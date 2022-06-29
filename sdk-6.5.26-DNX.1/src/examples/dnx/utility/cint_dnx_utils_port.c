/* 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * This file provides port basic functionality
 */

uint32 eth_type_header_size = -1;
bcm_cosq_ingress_port_drop_flex_key_base_t user_offset_base = bcmCosqIngressPortDropFlexKeyBaseEndOfEthHeader;

int
cint_nif_priority_config_mpls_special_label_config(int unit, int in_port, int scenario_index)
{
    int rv = BCM_E_NONE, index;
    uint32 flags = 0;
    bcm_cosq_ingress_port_drop_map_t cosq_map;
    bcm_port_prio_config_t priority_config;
    bcm_cosq_ingress_port_drop_mpls_special_label_config_t label_config;
    int exp, prio;
    uint32 key, tpid = 0x8100, fifo_size_01, fifo_size_23;
    uint32 special_label1[4] = {1, 13, 14, 1};
    uint32 special_label2[4] = {2, 6, 10, 15};

    set_clu_prd_port_profile(unit, in_port);

    /* Set port priority groups */
    priority_config.nof_priority_groups = 2;
    priority_config.priority_groups[0].sch_priority = bcmPortNifSchedulerLow;
    priority_config.priority_groups[0].source_priority = BCM_PORT_F_PRIORITY_0  | BCM_PORT_F_PRIORITY_1;
    priority_config.priority_groups[0].num_of_entries = -1;
    priority_config.priority_groups[1].sch_priority = bcmPortNifSchedulerHigh;
    priority_config.priority_groups[1].source_priority = BCM_PORT_F_PRIORITY_2  | BCM_PORT_F_PRIORITY_3;
    priority_config.priority_groups[1].num_of_entries = -1;
    rv = bcm_port_priority_config_set(unit, in_port, &priority_config);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_dnx_port_priority_config_set\n", rv);
        return rv;
    }

    /* Fill the hard stage priority maps */
    for(exp=0; exp < 8; exp++)
    {
        prio = exp % 4;
        key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(exp);
        rv = bcm_cosq_ingress_port_drop_map_set(unit, in_port, flags, bcmCosqIngressPortDropMplsExpToPriorityTable, key, prio);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
            return rv;
        }
    }

    if(scenario_index == 0)
    {
        /* Set MPLS Special labels for common usage */
        for(index = 0; index < 4; index++)
        {
            label_config.label_value = special_label1[index];
            label_config.priority = 2;
            label_config.is_tdm = 0;
            rv = bcm_cosq_ingress_port_drop_mpls_special_label_set(unit, in_port, flags, index, label_config);
            if (rv != BCM_E_NONE)
            {
                printf("Failed(%d) bcm_cosq_ingress_port_drop_mpls_special_label_set\n", rv);
                return rv;
            }
        }
    } else if(scenario_index == 1)
    {
        /* Set MPLS Special labels for special usage */
        for(index = 0; index < 4; index++)
        {
            label_config.label_value = special_label2[index];
            label_config.priority = special_label2[index]/4;
            label_config.is_tdm = 0;
            rv = bcm_cosq_ingress_port_drop_mpls_special_label_set(unit, in_port, flags, index, label_config);
            if (rv != BCM_E_NONE)
            {
                printf("Failed(%d) bcm_cosq_ingress_port_drop_mpls_special_label_set\n", rv);
                return rv;
            }
        }
    }

    /*Set TPID for the port*/
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,tpid);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Set threshold for every priority. For the example we will create an equally divided FIFO */
    rv = bcm_port_priority_config_get(unit, in_port, &priority_config);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_port_priority_config_get\n", rv);
        return rv;
    }

    fifo_size_01 = priority_config.priority_groups[0].num_of_entries;
    fifo_size_23 = priority_config.priority_groups[1].num_of_entries;
    rv = bcm_cosq_ingress_port_drop_threshold_set(unit, in_port, flags, 0, fifo_size_01/2);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    rv = bcm_cosq_ingress_port_drop_threshold_set(unit, in_port, flags, 1, fifo_size_01);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    rv = bcm_cosq_ingress_port_drop_threshold_set(unit, in_port, flags, 2, fifo_size_23/2);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    rv = bcm_cosq_ingress_port_drop_threshold_set(unit, in_port, flags, 3, fifo_size_23);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    /*Enable hard stage PRD!*/
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, 1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    printf("cint_nif_priority_config_mpls_common_usage: PASS\n\n");
    return BCM_E_NONE;
}

int
cint_nif_priority_config_soft_stage_JR2(int unit, int in_port,int lp_pcp,int low_priority,int hp_pcp,int high_priority, uint32 header,
                                             uint32 match_key_size, uint32 *lp_match_key, uint32 *hp_match_key,
                                             uint32 offset_base, uint32 lp_key_index, uint32 hp_key_index)
{
    int rv = BCM_E_NONE;
    uint32 flags = 0;
    int index, lp_key, hp_key;
    bcm_cosq_ingress_port_drop_map_t cosq_map;
    bcm_info_t info;
    bcm_cosq_ingress_drop_flex_key_construct_id_t key_id;
    bcm_cosq_ingress_drop_flex_key_construct_t flex_key_config;
    bcm_cosq_ingress_drop_flex_key_t ether_code;
    bcm_cosq_ingress_drop_flex_key_entry_t lp_flex_key_info;
    bcm_cosq_ingress_drop_flex_key_entry_t hp_flex_key_info;
    bcm_cosq_ingress_drop_flex_key_t key_field_match;
    uint32 offset = 1;
    uint32 tpid = 0x8100;
    uint32 ether_type_val = 0xc0c0;

    if (header == 0)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropEthPcpDeiToPriorityTable;
    } else if (header == 1 || header == 2)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropTmTcDpPriorityTable;
    } else if (header == 3)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropIpDscpToPriorityTable;
    } else if (header == 4)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropMplsExpToPriorityTable;
    } else {
        printf("ERROR: Incorrect value for header type %d", header);
        return BCM_E_PARAM;
    }

    /* Map the created lp_key to low priority */
    rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,lp_key,low_priority);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* Map the created hp_key to high priority */
    rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,hp_key,high_priority);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* Set TPID for the port */
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,tpid);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Set 1 byte as a threshold level for the FIFO for packets mapped to low_priority */
    rv = bcm_cosq_ingress_port_drop_threshold_set(unit,in_port,flags,low_priority,1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

      /********************************/
     /*   Start Soft Stage override  */
    /********************************/
    /* Configure ConfigurableEthType1(code 2) for the given port with value 0xc0c0 */
    bcm_cosq_ingress_drop_flex_key_construct_t_init(&flex_key_config);

    if((offset_base == bcmCosqIngressPortDropFlexKeyBasePacketStart) || (offset_base == bcmCosqIngressPortDropFlexKeyBaseEndOfEthHeader))
    {
        flex_key_config.ether_type_header_size = -1;
    } else {
        flex_key_config.ether_type_header_size = 6;
    }

    rv = bcm_cosq_ingress_port_drop_custom_ether_type_set(unit, in_port, flags, 2, ether_type_val);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_custom_ether_type_set \n", rv);
        return rv;
    }

    /* Set the rules for constructing a key on this port */
    key_id.port = in_port;
    key_id.ether_type_code = 2;

    /* Construct the key of from the given offset value */
    flex_key_config.array_size = 4;
    flex_key_config.offset_base = offset_base;
    flex_key_config.offset_array[0] = offset;
    flex_key_config.offset_array[1] = offset+1;
    flex_key_config.offset_array[2] = offset+2;
    flex_key_config.offset_array[3] = offset+3;
    rv = bcm_cosq_ingress_port_drop_flex_key_construct_set(unit, key_id, flags, flex_key_config);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_construct_set \n", rv);
        return rv;
    }

    /* Override the priority of the two streams */
    ether_code.value = 2;
    ether_code.mask = 0xf;
    /* Check for match flex_key_config.offset_array[0] flex_key_config.offset_array[1] flex_key_config.offset_array[2] flex_key_config.offset_array[3].
     * The other offset bytes are around the one that is checked so this
     * reasuers us that if we have a match we checked the correct byte */

    /* Add low prio key to the TCAM */
    /* If match - set to priority 2 */
    bcm_cosq_ingress_drop_flex_key_entry_t_init(&lp_flex_key_info);
    lp_flex_key_info.ether_code = ether_code;
    lp_flex_key_info.num_key_fields = match_key_size;
    lp_flex_key_info.priority = high_priority;

    for (index = 0; index < match_key_size; index++)
    {
        key_field_match.value = lp_match_key[index];
        key_field_match.mask = 0xFF;
        lp_flex_key_info.key_fields[index] = key_field_match;
    }

    rv = bcm_cosq_ingress_port_drop_flex_key_entry_set(unit, in_port, flags, lp_key_index, lp_flex_key_info);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_entry_set\n", rv);
        return rv;
    }

    /* Add high prio key to the TCAM */
    /* If match - set to priority 0 */
    bcm_cosq_ingress_drop_flex_key_entry_t_init(&hp_flex_key_info);
    hp_flex_key_info.ether_code = ether_code;
    hp_flex_key_info.num_key_fields = match_key_size;
    hp_flex_key_info.priority = low_priority;

    for (index = 0; index < match_key_size; index++)
    {
        key_field_match.value = hp_match_key[index];
        key_field_match.mask = 0xFF;
        hp_flex_key_info.key_fields[index] = key_field_match;
    }

    rv = bcm_cosq_ingress_port_drop_flex_key_entry_set(unit, in_port, flags, hp_key_index, hp_flex_key_info);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_entry_set\n", rv);
        return rv;
    }

    /* Enable the NIF PRD soft stage feature for the given port! */
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, 2);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    printf("cint_nif_priority_config_soft_stage_JR2: PASS\n\n");
    return BCM_E_NONE;
}

/* Set VLAN domain */
int
port__vlan_domain__set(int unit, bcm_port_t port, int vlan_domain){

    return bcm_port_class_set(unit, port, bcmPortClassId, vlan_domain);
}

int
port__tpid__set(int unit, bcm_port_t port, uint16 outer_tpid, uint16 inner_tpid)
{
    int rv;
    bcm_switch_tpid_info_t tpid_info;
    int options = 0;

    tpid_info.tpid_value = outer_tpid;
    tpid_info.tpid_type = bcmTpidTypeOuter;
    rv = bcm_switch_tpid_add(unit, options, &tpid_info);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_switch_tpid_add\n");
        return rv;
    }

    if(inner_tpid != 0)
    {
        tpid_info.tpid_value = inner_tpid;
        tpid_info.tpid_type = bcmTpidTypeInner;
        /* Set inner TPID on port */
        rv = bcm_switch_tpid_add(unit, options, &tpid_info);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_switch_tpid_add\n");
            return rv;
        }
    }

    return rv;
}

int
port__basic_tpid_class__set(int unit, bcm_port_t port)
{
    bcm_port_tpid_class_t port_tpid_class;
    int rv;

    bcm_port_tpid_class_t_init(&port_tpid_class);
    sal_memset(&port_tpid_class, 0, sizeof (port_tpid_class));

    bcm_port_tpid_class_t_init(&port_tpid_class);
    sal_memset(&port_tpid_class, 0, sizeof (port_tpid_class));

    port_tpid_class.port  = port;
    port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_ANY;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tag_format_class_id = 8;  /* Set tag format to '8' for all TPID types with one TPID  */

    rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set, port=%d, \n", port);
        return rv;
    }

    bcm_port_tpid_class_t_init(&port_tpid_class);
    sal_memset(&port_tpid_class, 0, sizeof (port_tpid_class));

    port_tpid_class.port  = port;
    port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tag_format_class_id = 0;
    rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set, port=%d, \n", port);
        return rv;
    }

    return rv;
}

/* Classify a Ports combination of TPIDs to a specific tag format.
 * Applicable only in AVT mode.
 *
 * INPUT:
 *   port: Physical port or a PWE gport
 *   tag_format: Tag format.
 *   outer_tpid: Outer TPID value
 *   inner_tpid: Inner TPID value
 */
int
port__tag_classification__set(int unit,
                                  bcm_port_t port,
                                  bcm_port_tag_format_class_t tag_format,
                                  uint32 outer_tpid,
                                  uint32 inner_tpid)
{
    int rv;
    bcm_port_tpid_class_t tpid_class;

    bcm_port_tpid_class_t_init(&tpid_class);
    tpid_class.flags = 0;   /* Both for Ingress and Egress */
    tpid_class.port = port;
    tpid_class.tag_format_class_id = tag_format;
    tpid_class.tpid1 = outer_tpid;
    tpid_class.tpid2 = inner_tpid;
    rv = bcm_port_tpid_class_set(unit, &tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set, port - %d, rv - %d\n", port, rv);
        return rv;
    }

    return BCM_E_NONE;
}


int
cint_nif_priority_config(int unit, int in_port,
                             int lp_pcp, int low_priority,
                             int hp_pcp, int high_priority, uint32 tpid, uint32 header)
{
    int rv = BCM_E_NONE;
    uint32 flags = 0;
    int lp_key, hp_key;
    bcm_cosq_ingress_port_drop_map_t cosq_map;
    bcm_port_interface_info_t itf_info;
    bcm_port_mapping_info_t map_info;
    uint32 port_flags;
    bcm_port_prio_config_t priority_config;
    int flexe_gen;

    /* Get port info */
    rv = bcm_port_get(unit, in_port, &port_flags, &itf_info, &map_info);
    if (rv != BCM_E_NONE)
    {
        printf("Error(%d), bcm_port_get\n", rv);
        return rv;
    }

    /* Configure the NIF ports priority drop */
    /* Header type legend
     * 0 - VLAN
     * 1 - ITMH
     * 2 - HIGIG
     * 3 - IP
     * 4 - MPLS
     */

    /* Depending on the header we chose also and the map type
     * bcmCosqIngressPortDropTmTcDpPriorityTable = 0,
     * bcmCosqIngressPortDropIpDscpToPriorityTable = 1,
     * bcmCosqIngressPortDropEthPcpDeiToPriorityTable = 2,
     * bcmCosqIngressPortDropMplsExpToPriorityTable = 3
     */

    /* Choose the right key constructor macro for the specified header type and the right COSQ table */
    if (header == 0)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropEthPcpDeiToPriorityTable;
    } else if (header == 1 || header == 2)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropTmTcDpPriorityTable;
    } else if (header == 3)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropIpDscpToPriorityTable;
    } else if (header == 4)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropMplsExpToPriorityTable;
    } else
    {
        printf("ERROR: Incorrect value for header type %d", header);
        return BCM_E_PARAM;
    }

    set_clu_prd_port_profile(unit, in_port);

    if (!((low_priority == BCM_COSQ_INGRESS_PORT_DROP_PRIORITY_TDM) && (itf_info.interface == BCM_PORT_IF_ILKN)))
    {
        /* Map the created lp_key to low priority */
        rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,lp_key,low_priority);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
            return rv;
        }
    }

    if (!((high_priority == BCM_COSQ_INGRESS_PORT_DROP_PRIORITY_TDM) && (itf_info.interface == BCM_PORT_IF_ILKN)))
    {
        /* Map the created hp_key to high priority */
        rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,hp_key,high_priority);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
            return rv;
        }
    }

    /* Change the TPID value for the MPLS and IP tests */
    if (header == 3 || header == 4)
    {
        tpid=0x9100;
    }

    /* Set TPID for the port */
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,tpid);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Return traffic back to the IXIA to get stream statistics */
    if((port_flags & BCM_PORT_ADD_FLEXE_MAC) == 0)
    {
        /* Exclude force forward setting on FlexE MAC client */
        rv = bcm_port_force_forward_set(unit,in_port,in_port,1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_port_force_forward_set\n", rv);
            return rv;
        }
    }

    /* Enable the NIF PRD feature for the given port! */
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, 1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    priority_config.nof_priority_groups = 2;
    if (itf_info.interface != BCM_PORT_IF_ILKN)
    {
        if (high_priority == BCM_COSQ_INGRESS_PORT_DROP_PRIORITY_TDM)
        {
            priority_config.priority_groups[0].sch_priority = bcmPortNifSchedulerLow;
            priority_config.priority_groups[0].source_priority = BCM_PORT_F_PRIORITY_0  | BCM_PORT_F_PRIORITY_1 | BCM_PORT_F_PRIORITY_2  | BCM_PORT_F_PRIORITY_3;
            priority_config.priority_groups[1].sch_priority = bcmPortNifSchedulerTDM;
            priority_config.priority_groups[1].source_priority = BCM_PORT_F_PRIORITY_TDM;
        } else
        {
            priority_config.priority_groups[0].sch_priority = bcmPortNifSchedulerLow;
            priority_config.priority_groups[0].source_priority = BCM_PORT_F_PRIORITY_0  | BCM_PORT_F_PRIORITY_1;
            priority_config.priority_groups[1].sch_priority = bcmPortNifSchedulerHigh;
            priority_config.priority_groups[1].source_priority = BCM_PORT_F_PRIORITY_2  | BCM_PORT_F_PRIORITY_3;
        }
        priority_config.priority_groups[0].num_of_entries = 4;
        priority_config.priority_groups[1].num_of_entries = -1;
        if(port_flags & BCM_PORT_ADD_FLEXE_MAC)
        {
            flexe_gen = *(dnxc_data_get(unit, "nif", "framer", "gen", NULL));
            if (flexe_gen != 2) {
                /* FlexE MAC client doesn't allow FIFO size setting */
                priority_config.priority_groups[0].num_of_entries = 0;
                priority_config.priority_groups[1].num_of_entries = 0;
            }
        }
        rv = bcm_port_priority_config_set(unit, in_port, &priority_config);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_port_priority_config_set\n", rv);
            return rv;
        }
    }

    /* Set 1 byte as a threshold level for the FIFO for packets mapped to low_priority */
    rv = bcm_cosq_ingress_port_drop_threshold_set(unit,in_port,flags,low_priority,1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    printf("cint_nif_priority_config: PASS\n\n");
    return BCM_E_NONE;

}

int
cint_nif_priority_control_frame_config(int unit, int in_port,
                             int lp_pcp, int low_priority, uint32 tpid, uint32 header, uint32 control_frame_index, uint32 ether_type_code, uint32 ether_type_code_mask, uint32 ether_type_val)
{
    int rv = BCM_E_NONE;
    uint32 flags = 0;
    int lp_key, hp_key;
    bcm_cosq_ingress_port_drop_map_t cosq_map;
    bcm_cosq_ingress_drop_control_frame_config_t control_frame_config;
    uint64 mac_da_val,mac_da_mask;

    set_clu_prd_port_profile(unit, in_port);

    /* Configure the NIF ports priority drop*/
    /* Header type legend
     * 0 - VLAN
     * 1 - ITMH
     * 2 - HIGIG
     * 3 - IP
     * 4 - MPLS
     */

    /* Depending on the header we chose also and the map type
     * bcmCosqIngressPortDropTmTcDpPriorityTable = 0,
     * bcmCosqIngressPortDropIpDscpToPriorityTable = 1,
     * bcmCosqIngressPortDropEthPcpDeiToPriorityTable = 2,
     * bcmCosqIngressPortDropMplsExpToPriorityTable = 3
     */

    /* Choose the right key constructor macro for the specified header type and the right COSQ table */
    if (header == 0)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(lp_pcp,0);
        cosq_map = bcmCosqIngressPortDropEthPcpDeiToPriorityTable;
    } else if (header == 1 || header == 2)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(lp_pcp,0);
        cosq_map = bcmCosqIngressPortDropTmTcDpPriorityTable;
    } else if (header == 3)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(lp_pcp);
        cosq_map = bcmCosqIngressPortDropIpDscpToPriorityTable;
    } else if (header == 4)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(lp_pcp);
        cosq_map = bcmCosqIngressPortDropMplsExpToPriorityTable;
    } else
    {
        printf("ERROR: Incorrect value for header type %d", header);
        return BCM_E_PARAM;
    }

    /* Map the created lp_key to low priority */
    rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,lp_key,low_priority);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* set ether type value oxc0c0 for protocol code 2 (part of key for control frame) */
    rv = bcm_cosq_ingress_port_drop_custom_ether_type_set (unit, in_port, flags,  ether_type_code, ether_type_val);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_custom_ether_type_set \n", rv);
        return rv;
    }

    /* The pkt will be treated as control frame when dmac is 0x112233445566 and protocol code is 2 (the corresponding ether type value is 0xc0c0) */
    COMPILER_64_SET(control_frame_config.mac_da_val,0x1122,0x33445566);
    COMPILER_64_SET(control_frame_config.mac_da_mask,0xffff,0xffffffff);
    control_frame_config.ether_type_code=ether_type_code;
    control_frame_config.ether_type_code_mask=ether_type_code_mask;
    rv = bcm_cosq_ingress_port_drop_control_frame_set(unit,in_port,flags,control_frame_index,&control_frame_config);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_control_frame_set\n", rv);
        return rv;
    }

    /* Change the TPID value for the MPLS and IP tests */
    if (header == 3 || header == 4)
    {
        tpid=0x9100;
    }

    /* Set TPID for the port */
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,tpid);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Set 1 byte as a threshold level for the FIFO for packets mapped to low_priority */
    rv = bcm_cosq_ingress_port_drop_threshold_set(unit,in_port,flags,low_priority,1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    /* Return traffic back to the IXIA to get stream statistics */
    rv = bcm_port_force_forward_set(unit,in_port,in_port,1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_port_force_forward_set\n", rv);
        return rv;
    }

    /* Enable the NIF PRD feature for the given port! */
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, 1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    printf("cint_nif_priority_control_frame_config: PASS\n\n");
    return BCM_E_NONE;

}

int
cint_nif_priority_config_soft_stage(int unit, int in_port,
                             int lp_pcp, int low_priority,
                             int hp_pcp, int high_priority, uint32 tpid,
                             uint32 header, uint32 ether_type_val,
                             uint32 lp_match_key, uint32 hp_match_key, uint32 offset)
{
    int rv = BCM_E_NONE;
    uint32 port_flags, flags = 0;
    int lp_key, hp_key;
    bcm_cosq_ingress_port_drop_map_t cosq_map;
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    bcm_cosq_ingress_drop_flex_key_construct_id_t key_id;
    bcm_cosq_ingress_drop_flex_key_construct_t flex_key_config;
    bcm_cosq_ingress_drop_flex_key_t ether_code;
    bcm_cosq_ingress_drop_flex_key_entry_t lp_flex_key_info;
    bcm_cosq_ingress_drop_flex_key_t lp_key_field_match;
    uint32 lp_key_index = 10;
    bcm_cosq_ingress_drop_flex_key_entry_t hp_flex_key_info;
    bcm_cosq_ingress_drop_flex_key_t hp_key_field_match;
    uint32 hp_key_index = 20;
    int num_key_fields = 1;
    bcm_port_prio_config_t priority_config;
    int flexe_gen;

    rv = bcm_port_get(unit, in_port, &port_flags, &interface_info, &mapping_info);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_port_get\n", rv);
        return rv;
    }

    set_clu_prd_port_profile(unit, in_port);

    /* Configure the NIF ports priority drop */
    /* Header type legend
     * 0 - VLAN
     * 1 - ITMH
     * 2 - HIGIG
     * 3 - IP
     * 4 - MPLS
     */

    /* Depending on the header we chose also and the map type
     * bcmCosqIngressPortDropTmTcDpPriorityTable = 0,
     * bcmCosqIngressPortDropIpDscpToPriorityTable = 1,
     * bcmCosqIngressPortDropEthPcpDeiToPriorityTable = 2,
     * bcmCosqIngressPortDropMplsExpToPriorityTable = 3
     */

    /* Choose the right key constructor macro for the specified header type and the right COSQ table */
    if (header == 0)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropEthPcpDeiToPriorityTable;
    } else if (header == 1 || header == 2)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(lp_pcp,0);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_TM_MAP_KEY(hp_pcp,0);
        cosq_map = bcmCosqIngressPortDropTmTcDpPriorityTable;
    } else if (header == 3)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_IP_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropIpDscpToPriorityTable;
    } else if (header == 4)
    {
        lp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(lp_pcp);
        hp_key = BCM_COSQ_INGRESS_PORT_DROP_MPLS_MAP_KEY(hp_pcp);
        cosq_map = bcmCosqIngressPortDropMplsExpToPriorityTable;
    } else
    {
        printf("ERROR: Incorrect value for header type %d", header);
        return BCM_E_PARAM;
    }

    /* Map the created lp_key to low priority */
    rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,lp_key,low_priority);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* Map the created hp_key to high priority */
    rv = bcm_cosq_ingress_port_drop_map_set(unit,in_port,flags,cosq_map,hp_key,high_priority);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* Set TPID for the port */
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,tpid);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Set 1 byte as a threshold level for the FIFO for packets mapped to low_priority */
    rv = bcm_cosq_ingress_port_drop_threshold_set(unit,in_port,flags,low_priority,1);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_threshold_set\n", rv);
        return rv;
    }

    /* Start Soft Stage override */
    /* Configure ConfigurableEthType1(code 2) for the given port with value 0x1234 */
    rv = bcm_cosq_ingress_port_drop_custom_ether_type_set ( unit, in_port, flags,  2, ether_type_val);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_custom_ether_type_set \n", rv);
        return rv;
    }

    /* Set the rules for constructing a key on this port */
    key_id.port = in_port;
    key_id.ether_type_code = 2;

    /* Construct the key of from the given offset value */
    flex_key_config.offset_base = user_offset_base;
    flex_key_config.ether_type_header_size = eth_type_header_size;
    flex_key_config.array_size = 4;
    flex_key_config.offset_array[0] = offset;
    flex_key_config.offset_array[1] = offset+1;
    flex_key_config.offset_array[2] = offset+2;
    flex_key_config.offset_array[3] = offset+3;
    rv = bcm_cosq_ingress_port_drop_flex_key_construct_set ( unit, key_id, flags, flex_key_config);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_construct_set \n", rv);
        return rv;
    }

    /* Override the priority of the two streams */
    ether_code.value = 2;
    ether_code.mask = 0xF;
    /* Check for match only the first part of the key - flex_key_config.offset_array[0].
     * The other offset bytes are around the one that is checked so this
     * reasuers us that if we have a match we checked the correct byte */

    /* Add low prio key to the TCAM */
    /* If match - set to priority 2 */
    lp_key_field_match.value = lp_match_key;
    lp_key_field_match.mask = 0xFF;
    lp_flex_key_info.ether_code = ether_code;
    lp_flex_key_info.num_key_fields = num_key_fields;
    lp_flex_key_info.priority = high_priority;
    lp_flex_key_info.key_fields[0] = lp_key_field_match;
    rv = bcm_cosq_ingress_port_drop_flex_key_entry_set( unit, in_port, flags, lp_key_index, lp_flex_key_info);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_entry_set\n", rv);
        return rv;
    }

    /* Add high prio key to the TCAM */
    /* If match - set to priority 0 */
    hp_key_field_match.value = hp_match_key;
    hp_key_field_match.mask = 0xFF;
    hp_flex_key_info.ether_code = ether_code;
    hp_flex_key_info.num_key_fields = num_key_fields;
    hp_flex_key_info.priority = low_priority;
    hp_flex_key_info.key_fields[0] = hp_key_field_match;
    rv = bcm_cosq_ingress_port_drop_flex_key_entry_set( unit, in_port, flags, hp_key_index, hp_flex_key_info);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_flex_key_entry_set\n", rv);
        return rv;
    }

    /* Return traffic back to the IXIA to get stream statistics */
    if((port_flags & BCM_PORT_ADD_FLEXE_MAC) == 0)
    {
        rv = bcm_port_force_forward_set(unit,in_port,in_port,1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_port_force_forward_set\n", rv);
            return rv;
        }
    }

    /* Enable the NIF PRD soft stage feature for the given port! */
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, 2);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    priority_config.nof_priority_groups = 2;
    if (interface_info.interface != BCM_PORT_IF_ILKN)
    {
        priority_config.priority_groups[0].sch_priority = bcmPortNifSchedulerLow;
        priority_config.priority_groups[0].source_priority = BCM_PORT_F_PRIORITY_0  | BCM_PORT_F_PRIORITY_1;
        priority_config.priority_groups[0].num_of_entries = 4;
        priority_config.priority_groups[1].sch_priority = bcmPortNifSchedulerHigh;
        priority_config.priority_groups[1].source_priority = BCM_PORT_F_PRIORITY_2  | BCM_PORT_F_PRIORITY_3;
        priority_config.priority_groups[1].num_of_entries = -1;
        if(port_flags & BCM_PORT_ADD_FLEXE_MAC)
        {
            flexe_gen = *(dnxc_data_get(unit, "nif", "framer", "gen", NULL));
            if (flexe_gen != 2) {
                /* FlexE MAC client doesn't allow FIFO size setting */
                priority_config.priority_groups[0].num_of_entries = 0;
                priority_config.priority_groups[1].num_of_entries = 0;
            }
        }
        rv = bcm_port_priority_config_set(unit, in_port, &priority_config);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_port_priority_config_set\n", rv);
            return rv;
        }
    }
    printf("cint_nif_priority_config_soft_stage: PASS\n\n");
    return BCM_E_NONE;

}

int
cint_nif_prd_port_set_all_to_default_priority(int unit,int port,uint32 def_prio,
                                                   uint32 ignore_headers, uint32 tpid_mismatch, uint32 tpid_value)
{
    int rv = BCM_E_NONE;
    uint32 flags = 0;

    set_clu_prd_port_profile(unit, port);

    /* Set default priority */
    rv = bcm_cosq_ingress_port_drop_default_priority_set (unit, port, flags, def_prio);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_default_priority_set\n", rv);
        return rv;
    }

    /* If we use the cint for the TPID mismatch test */
    /* We change the expected TPID value for the second port */
    if (tpid_mismatch)
    {
        rv = bcm_cosq_control_set(unit,port,-1,bcmCosqControlIngressPortDropTpid1,tpid_value);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_control_set\n", rv);
            return rv;
        }
    }

    if (ignore_headers)
    {
        /* Ignore all header information */
        /* in order to receive  default */
        /* priority in second_port */
        rv = bcm_cosq_control_set(unit, port, -1, bcmCosqControlIngressPortDropIgnoreIpDscp, 1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_control_set\n", rv);
            return rv;
        }

        rv = bcm_cosq_control_set(unit, port, -1, bcmCosqControlIngressPortDropIgnoreMplsExp, 1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_control_set\n", rv);
            return rv;
        }

        rv = bcm_cosq_control_set(unit, port, -1, bcmCosqControlIngressPortDropIgnoreInnerTag, 1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_control_set\n", rv);
            return rv;
        }

        rv = bcm_cosq_control_set(unit, port, -1, bcmCosqControlIngressPortDropIgonreOuterTag, 1);
        if (rv != BCM_E_NONE)
        {
            printf("Failed(%d) bcm_cosq_control_set\n", rv);
            return rv;
        }
    }

    printf("cint_nif_prd_port_set_all_to_default_priority: PASS\n\n");
    return BCM_E_NONE;
}

uint64
cint_port_dropped_packets_get (int unit, int port) {
    int rv = BCM_E_NONE;
    uint64 dropped_cnt;

    rv = bcm_stat_get(unit,port,snmpEtherStatsDropEvents,&dropped_cnt);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_stat_get \n", rv);
        return rv;
    }

    return dropped_cnt;
}

int
set_clu_prd_port_profile(int unit, int in_port) {
    bcm_port_interface_info_t interface_info;
    bcm_port_mapping_info_t mapping_info;
    int rv;
    uint32 flags;
    portmod_dispatch_type_t port_type;

    rv = bcm_port_get(unit, in_port, &flags, &interface_info, &mapping_info);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_port_get\n");
        return rv;
    }

    cint_port_phy_type_get(unit, in_port, &port_type);
    if(interface_info.interface == BCM_PORT_IF_NIF_ETH && port_type == portmodDispatchTypePm4x25)
    {
        rv = bcm_cosq_control_set(unit, in_port, -1, bcmCosqControlIngressPortDropPortProfileMap, in_port % 4);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_cosq_control_set for bcmCosqControlIngressPortDropPortProfileMap\n");
            return rv;
        }
    }

    if(flags & BCM_PORT_ADD_FLEXE_MAC)
    {
        rv = bcm_cosq_control_set(unit, in_port, -1, bcmCosqControlIngressPortDropPortProfileMap, in_port % 8);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_cosq_control_set for bcmCosqControlIngressPortDropPortProfileMap\n");
            return rv;
        }
    }

    return BCM_E_NONE;
}

/*
 * brief - set tdm indication using prd for a given port and L2 tc, dei
 */
int
cint_nif_priority_l2_tdm_set(int unit, int in_port, int pcp, int dei)
{
    int rv = BCM_E_NONE;
    uint32 flags = 0;

    /* map pcp and dei to tdm */
    rv = bcm_cosq_ingress_port_drop_map_set(unit, in_port, flags, bcmCosqIngressPortDropEthPcpDeiToPriorityTable, BCM_COSQ_INGRESS_PORT_DROP_ETH_MAP_KEY(pcp, dei), BCM_COSQ_INGRESS_PORT_DROP_PRIORITY_TDM);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_map_set\n", rv);
        return rv;
    }

    /* Set TPID for the port */
    rv = bcm_cosq_control_set(unit,in_port,-1,bcmCosqControlIngressPortDropTpid1,0x8100);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_control_set\n", rv);
        return rv;
    }

    /* Enable hard stage PRD! */
    rv = bcm_cosq_ingress_port_drop_enable_set(unit, in_port, flags, bcmCosqIngressPortDropEnableHardStage);
    if (rv != BCM_E_NONE)
    {
        printf("Failed(%d) bcm_cosq_ingress_port_drop_enable_set\n", rv);
        return rv;
    }

    printf("cint_nif_priority_l2_tdm_set: PASS\n\n");
    return BCM_E_NONE;
}