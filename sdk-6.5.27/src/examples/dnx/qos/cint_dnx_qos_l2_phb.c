/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * Cint QOS PHB example code
 * Test Scenario - start
  cint ../../../../src/examples/sand/utility/cint_sand_utils_global.c
  cint ../../../../src/examples/sand/cint_vswitch_metro_mp_vlan_port.c
  cint ../../../../src/examples/sand/cint_qos_l2_phb.c
  cint
  qos_map_l2_example(0,1,2,10,7);
  exit;
 * Test Scenario - end
 */

/* Map ingress follows
 *   Ingress      INTERNAL     INGRESS
 *   PKT_PRI/CFI  TC/DP        NWK-QOS
 *
 *       0/0    0/GREEN         2
 *       0/1    0/RED           2
 *       1/0    1/GREEN         3
 *       1/1    1/YELLOW        4
 *       2/0    1/YELLOW        5
 *       2/1    2/YELLOW        6
 *       3/0    3/GREEN         7
 *       3/1    3/RED           7
 *       4/0    4/GREEN         5
 *       4/1    4/RED           3
 *       5/0    5/GREEN         2
 *       5/1    5/RED           3
 *       6/0    6/GREEN         4
 *       6/1    6/RED           5
 *       7/0    7/GREEN         6
 *       7/1    7/YELLOW        7
 */
 
/* Map egress follows
 *  EGRESS         Egress
 * NWK-QOS/DP      PKT_PRI/CFI
 *
 *  0/GREEN          1/0
 *  0/RED            1/1
 *  1/GREEN          2/0
 *  1/YELLOW         2/1
 *  2/YELLOW         3/0
 *  2/RED            3/1
 *  3/GREEN          4/0
 *  3/RED            4/1
 *  4/GREEN          5/0
 *  4/YELLOW         5/1
 *  5/GREEN          6/0
 *  5/RED            6/1
 *  6/GREEN          7/0
 *  6/RED            7/1
 *  7/GREEN          7/0
 *  7/YELLOW         7/1
 *  nwk_qos/dp      qos_map_l2_egress_pcp[nwk_qos%16]/qos_map_l2_egress_cfi[nwk_qos%16]; 
 */

/* inheritance egress follows
 *
 * NWK-QOS         new NWK_QOS
 *
 *  0/GREEN          1
 *  0/RED            4
 *  1/GREEN          5
 *  1/YELLOW         6
 *  2/YELLOW         7
 *  2/RED            7
 *  3/GREEN          6
 *  3/RED            5
 *  4/GREEN          7
 *  4/YELLOW         2
 *  5/GREEN          3
 *  5/RED            1
 *  6/GREEN          7
 *  6/RED            6
 *  7/GREEN          5
 *  7/YELLOW         5
 *  others           0
 */
     
int QOS_MAPPING_TABLE_SIZE = 16;    
int qos_map_l2_internal_pri[QOS_MAPPING_TABLE_SIZE] = {0, 0, 1, 1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7};
bcm_color_t qos_map_l2_internal_color[QOS_MAPPING_TABLE_SIZE] = {bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorYellow,
					     bcmColorYellow,
					     bcmColorYellow,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorYellow};
bcm_color_t qos_map_l2_internal_color_egr[QOS_MAPPING_TABLE_SIZE] = {bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorYellow,
					     bcmColorYellow,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorYellow,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorRed,
					     bcmColorGreen,
					     bcmColorYellow};
int ing_nwk_qos_map_remark_intpri[QOS_MAPPING_TABLE_SIZE] = {2, 2, 3, 4, 5, 6, 7, 7, 5, 3, 2, 3, 4, 5, 6, 7};
int qos_map_l2_egress_pcp[QOS_MAPPING_TABLE_SIZE] = {1, 1, 2, 2, 2, 3, 4, 4, 5, 5, 6, 6, 7, 7, 0, 0};
int qos_map_l2_egress_cfi[QOS_MAPPING_TABLE_SIZE] = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
int egr_nwk_qos_map_remark_intpri[QOS_MAPPING_TABLE_SIZE] = {1, 4, 5, 6, 7, 7, 6, 5, 7, 2, 3, 1, 7, 6, 5, 5};
int illegal_qos_id = 0xFFFF;

/*
 * modify the cint example mapping table.
 * modify single entry of tc and dp for a given PKT_PRI/CFI
 */
int
qos_l2_default_mapping_modify(int unit, int pkt_pri, int cfi, int tc, bcm_color_t dp)
{
    int index = (pkt_pri*2+cfi);

    if (index >= QOS_MAPPING_TABLE_SIZE)
    {
        printf("qos_l2_default_mapping_modify failed. index=%d. \n", index);
        return BCM_E_FAIL;
    }
    
    qos_map_l2_internal_pri[index] = tc;
    qos_map_l2_internal_color[index] = dp;
    return BCM_E_NONE;            
}

/*
 * Set QOS ID map for tag_type , current validated only with BCM_QOS_MAP_L2_UNTAGGED
 */
int
qos_map_ingress_profile_map(int unit,int qos_map_id, int opcode, int tag_type)
{
    bcm_qos_map_t l2_in_map;
    int flags = 0;
    int idx = 0;

    /* Clear structure */
	bcm_qos_map_t_init(&l2_in_map);

    l2_in_map.opcode = opcode;
    flags = BCM_QOS_MAP_L2 | tag_type | BCM_QOS_MAP_OPCODE;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_in_map, qos_map_id), "OPCODE");

    /* Map L2 table Out-tag */
    for (idx=0; idx<QOS_MAPPING_TABLE_SIZE; idx++) {
        bcm_qos_map_t_init(&l2_in_map);
    	flags = BCM_QOS_MAP_L2 | tag_type;

    	/* Set ingress pkt_pri/cfi Priority */
    	l2_in_map.pkt_pri = idx>>1;
    	l2_in_map.pkt_cfi = idx&1;

    	/* Set internal priority for this ingress pri */
    	l2_in_map.int_pri = qos_map_l2_internal_pri[idx];

    	/* Set color for this ingress Priority  */
    	l2_in_map.color = qos_map_l2_internal_color[idx];

        /* NWK-Qos mapping  */
    	l2_in_map.remark_int_pri = ing_nwk_qos_map_remark_intpri[idx];

        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_in_map, opcode), "in PHB ingress");

    }
    return BCM_E_NONE;
}

/*
 * Set QOS ID map for tag_type , current validated only with BCM_QOS_MAP_L2_OUTER_TAG
 */
int
qos_map_egress_profile_map(int unit, int qos_map_id, int opcode, int tag_type)
{
    bcm_qos_map_t l2_eg_map;
    int flags = 0;
    int idx;
    int nwk_qos;
    int dp;
    char error_msg[200]={0,};

    /*
     * Currently BCM API doesn't have internal map priority,
     * for now we use queue_offset field to get this value.
     */

    /* Clear structure */
    bcm_qos_map_t_init(&l2_eg_map);

    l2_eg_map.opcode = opcode;
    flags = BCM_QOS_MAP_L2 | tag_type | BCM_QOS_MAP_OPCODE;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, qos_map_id), "OPCODE");

    /*current mark mapping*/
    for (idx = 0; idx < QOS_MAPPING_TABLE_SIZE; idx++)
    {
        flags = BCM_QOS_MAP_L2 | tag_type;

        bcm_qos_map_t_init(&l2_eg_map);
        /* Set internal priority  */
        l2_eg_map.int_pri = qos_map_l2_internal_pri[idx];
        l2_eg_map.color = qos_map_l2_internal_color_egr[idx];

    	/* Set egress pri */
        l2_eg_map.pkt_pri = qos_map_l2_egress_pcp[idx];
        l2_eg_map.pkt_cfi = qos_map_l2_egress_cfi[idx];


        snprintf(error_msg, sizeof(error_msg), "in L2 egress, profile(0x%08x)", opcode);
	    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, opcode), error_msg);
    }
    /*relevant current mark mapping*/
    for (nwk_qos = 8; nwk_qos < 256; nwk_qos++)
    {
        flags = BCM_QOS_MAP_L2 | tag_type;
        for (dp = 0; dp < 4; dp++)
        {
            bcm_qos_map_t_init(&l2_eg_map);
            /* Set internal priority  */
            l2_eg_map.int_pri = nwk_qos;
            l2_eg_map.color = dp;
        	/* Set egress pri */
            idx = nwk_qos % 16;
            l2_eg_map.pkt_pri = qos_map_l2_egress_pcp[idx];
            l2_eg_map.pkt_cfi = qos_map_l2_egress_cfi[idx];
            snprintf(error_msg, sizeof(error_msg), "in L2 egress, profile(0x%08x)", opcode);
    	    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, opcode), error_msg);
        }
    }

    /*inheritance to next layer mapping*/
    for (idx = 0; idx < QOS_MAPPING_TABLE_SIZE; idx++)
    {
        flags = BCM_QOS_MAP_L2 | tag_type;

        bcm_qos_map_t_init(&l2_eg_map);
        /* Set internal priority  */
        l2_eg_map.int_pri = qos_map_l2_internal_pri[idx];
        l2_eg_map.color = qos_map_l2_internal_color_egr[idx];
        l2_eg_map.remark_color = qos_map_l2_internal_color_egr[idx];

        /* NWK-QoS-Var*/
        l2_eg_map.remark_int_pri = egr_nwk_qos_map_remark_intpri[idx];

        snprintf(error_msg, sizeof(error_msg), "in L2 egress, profile(0x%08x)", qos_map_id);
	    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &l2_eg_map, qos_map_id), error_msg);
    }

    return BCM_E_NONE;
}

/*
 * Main function for QOS settings
 * Create QOS ingress profile and set its mapping ETH VLAN fields to TC, DP (PHB QOS)
 * Create QOS egress profile and set its mapping TC,DP to ETH VLAN fields
 */
int
qos_map_l2_example(int unit, int ingress_qos_id, int egress_qos_id, int ingress_opcode_id, int egress_opcode_id)
{
    int qos_egress     = egress_qos_id;
    int qos_ingress    = ingress_qos_id;
    int opcode_ingress = ingress_opcode_id;
    int opcode_egress  = egress_opcode_id;
    uint32 flags = 0;

    if (ingress_qos_id != illegal_qos_id)
    {
        flags = (BCM_QOS_MAP_INGRESS | BCM_QOS_MAP_PHB | BCM_QOS_MAP_REMARK);
        if (qos_ingress != -1)
        {
            flags |= BCM_QOS_MAP_WITH_ID;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &qos_ingress), "in L3 ingress");


        flags = BCM_QOS_MAP_INGRESS | BCM_QOS_MAP_PHB | BCM_QOS_MAP_OPCODE ;
        if (opcode_ingress != -1)
        {
            flags |= BCM_QOS_MAP_WITH_ID;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &opcode_ingress), "in ingress l3 opcode");

        BCM_IF_ERROR_RETURN_MSG(qos_map_ingress_profile_map(unit, qos_ingress, opcode_ingress, BCM_QOS_MAP_PHB | BCM_QOS_MAP_L2_OUTER_TAG), "setting up");
        /* To configure nwk-qos
         * */

        flags = BCM_QOS_MAP_INGRESS | BCM_QOS_MAP_REMARK | BCM_QOS_MAP_OPCODE ;
        opcode_ingress = ingress_opcode_id;
        if (opcode_ingress != -1)
        {
            flags |= BCM_QOS_MAP_WITH_ID;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &opcode_ingress), "in ingress l3 opcode");
        BCM_IF_ERROR_RETURN_MSG(qos_map_ingress_profile_map(unit, qos_ingress, opcode_ingress, BCM_QOS_MAP_REMARK | BCM_QOS_MAP_L2_OUTER_TAG), "setting up");
    }

    if (egress_qos_id != illegal_qos_id)
    {
        flags = BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK;
        if (qos_egress != -1)
        {
            flags |= BCM_QOS_MAP_WITH_ID;
        }
        if(qos_egress !=0)
        {
            BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &qos_egress), "in L3 egress");
        }
        else
        {
            qos_egress = ((0x2000 | 0x2) << 16) | qos_egress;
        }

        flags = BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK | BCM_QOS_MAP_OPCODE ;
        if (opcode_egress != -1)
        {
            flags |= BCM_QOS_MAP_WITH_ID;
        }
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &opcode_egress), "in egress l3 opcode");

        BCM_IF_ERROR_RETURN_MSG(qos_map_egress_profile_map(unit, qos_egress, opcode_egress, BCM_QOS_MAP_REMARK | BCM_QOS_MAP_L2_OUTER_TAG), "setting up");
    }
    return BCM_E_NONE;
}

/*
 * Connect GPORT (VLAN-Port) to its QOS-profile
 */
int
qos_map_gport(int unit, bcm_gport_t gport, int ingress_qos_id, int egress_qos_id)
{
    char error_msg[200]={0,};

    snprintf(error_msg, sizeof(error_msg), "setting up gport(0x%08x) to map", gport);
	BCM_IF_ERROR_RETURN_MSG(bcm_qos_port_map_set(unit, gport, ingress_qos_id, egress_qos_id), error_msg);

    return BCM_E_NONE;
}

/*
 * test profile creation functionality,
 * Connect GPORT (VLAN-Port) to its QOS-profile
 * go thoroug all valid profile values
 * test configure a profile with id functionality
 * use unsupported flags for negative tests
 * try to configure a unvalid profile id
 */
int
qos_profile_creation_test(int unit)
{
    const int NUM_OF_PHB_PROFILES = 1024;
    int qos_map_id;
    int ingress_qos_map_id = 4;
    int ingress_qos_map_ids_received[NUM_OF_PHB_PROFILES];
    int i;


    /** configuring one profile with ID   */
  	BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_INGRESS|BCM_QOS_MAP_WITH_ID, &ingress_qos_map_id),
        "failed allocate ingress static profile");

    ingress_qos_map_ids_received[0] = ingress_qos_map_id;

    /** trying to configure all other ingress available profiles */
    for (i = 1; i < NUM_OF_PHB_PROFILES; i++)
    {
        qos_map_id = 0;
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_INGRESS, &qos_map_id), "failed allocate profile");

        if (ingress_qos_map_id == qos_map_id)
        {
            printf("error allocated the same value for static profile and dynamic profile\n");
            return -1;
        }

        ingress_qos_map_ids_received[i] = qos_map_id;
    }

    /** trying to configure profiles exceed to number of legal
     *  profiles */
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_INGRESS|BCM_QOS_MAP_WITH_ID, &ingress_qos_map_id),
        "allocate one profile more than legal value");

    printf("finish creating profiles\n");

    for (i = 0; i < NUM_OF_PHB_PROFILES; i++)
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_destroy(unit, ingress_qos_map_ids_received[i]), "failed allocate profile");
    }

    printf("finish deleting profiles\n");

    printf("Test PASSED\n");

    return BCM_E_NONE;
}

/*
 * test profile creation functionality,
 * Connect GPORT (VLAN-Port) to its QOS-profile
 * go thoroug all valid profile values
 * test configure a profile with id functionality
 * use unsupported flags for negative tests
 * try to configure a unvalid profile id
 */
int
qos_egress_profile_creation_test(int unit)
{
    const int NUM_OF_EGRESS_PROFILES = 32;
    int qos_map_id;
    int egress_qos_map_id  = 7;
    int egress_qos_map_ids_received[NUM_OF_EGRESS_PROFILES];
    int i;


    /** configuring one profile with ID   */
  	BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_EGRESS|BCM_QOS_MAP_WITH_ID, &egress_qos_map_id),
        "failed allocate ingress static profile");

    egress_qos_map_ids_received[0]  = egress_qos_map_id;

    /** trying to configure all other egress available profiles */
    for (i = 1; i < NUM_OF_EGRESS_PROFILES; i++)
    {
        qos_map_id = 0;
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_EGRESS, &qos_map_id), "failed allocate egress profile");

        if (egress_qos_map_id == qos_map_id)
        {
            printf("error allocated the same value for static profile and dynamic profile\n");
            return -1;
        }

        egress_qos_map_ids_received[i] = qos_map_id;
    }

    /** trying to configure profiles exceed to number of legal
     *  profiles */
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, BCM_QOS_MAP_EGRESS|BCM_QOS_MAP_WITH_ID, &egress_qos_map_id),
        "allocate one profile more than legal value");

    printf("finish creating profiles\n");

    for (i = 0; i < NUM_OF_EGRESS_PROFILES; i++)
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_destroy(unit, egress_qos_map_ids_received[i]), "failed allocate profile");
    }

    printf("finish deleting profiles\n");

    printf("Test PASSED\n");

    return BCM_E_NONE;
}

/*
 * Configuration for Forwarding plus one header(mpls) remarking. 
 * The maps for remarking Qos is : remarking_qos = nwk_qos + 1.
 */
int qos_map_l2_fwd_plus_one_mpls_remark(int unit, int remark_profile, int opcode)
{
    int fwd_plus_1_opcode;
    int qos_value, dp_value;
    uint32 flags;
    bcm_qos_map_t eg_qos_map;

    /** Check if the given profile is valid*/
    if (remark_profile == -1)
    {
        printf("error (%d) in qos_map_l2_fwd_plus_one_remark. Given profile (%d) is invalid!\n", BCM_E_PARAM, remark_profile);
        return BCM_E_PARAM;
    }

    /** Create an opcode for fwd plus one remark.*/
    flags = BCM_QOS_MAP_EGRESS | BCM_QOS_MAP_REMARK | BCM_QOS_MAP_OPCODE ;
    if (opcode != -1)
    {
        flags |= BCM_QOS_MAP_WITH_ID;
        fwd_plus_1_opcode = opcode;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_create(unit, flags, &fwd_plus_1_opcode), "for fwd plus one opcode");
    printf("Create an opcode 0x%08X for fwd plus one header mpls remarking.\n", fwd_plus_1_opcode);

    /** Map given profile to the opcode */
    bcm_qos_map_t_init(&eg_qos_map);

    eg_qos_map.opcode = fwd_plus_1_opcode;
    flags = BCM_QOS_MAP_MPLS;
    flags |= BCM_QOS_MAP_L3_L2 | BCM_QOS_MAP_OPCODE | BCM_QOS_MAP_REMARK;
    BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &eg_qos_map, remark_profile),
        "for mapping profile to fwd plus one opcode");

    /** Add QoS map for the protocol: QoS = nwk_qos + 1*/
    for (qos_value = 0; qos_value < 8; qos_value++)
    {
        for (dp_value = 0; dp_value < 3; dp_value++)
        {
            bcm_qos_map_t_init(&eg_qos_map);

            flags = BCM_QOS_MAP_MPLS | BCM_QOS_MAP_REMARK;
            eg_qos_map.color = dp_value;
            eg_qos_map.int_pri = qos_value;
            eg_qos_map.exp = (qos_value + 1) & 0x7;
            BCM_IF_ERROR_RETURN_MSG(bcm_qos_map_add(unit, flags, &eg_qos_map, fwd_plus_1_opcode),
                "for mapping qos value with fwd plus one opcode");
        }
    }
    return BCM_E_NONE;
}

