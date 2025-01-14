/* 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
*/
/*
 * demonstrate add/delete/traverse operation on MACT
 * Test Scenario
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_vlan.c
  cint ../../../../src/examples/dnx/l2/cint_dnx_mact.c
  cint ../../../../src/examples/dnx/l2/cint_dnx_mact_traverse.c
  cint
  int unit = 0;
  int local_port = 13;
  int dest_ports[4] = {13,14,15,16};
  mact_group_traverse_example(unit,local_port);
  mact_multiple_rules_example(unit,local_port,dest_ports);
  mact_rule_mask_vlan_example(unit,local_port);
  mact_rule_mask_vlan_port_example(unit,local_port);
  exit;
 * Test Scenario - end
 *
 */

int verbose;
verbose = 2;

/*
 * Call back to print entry includeing the group
 */
int call_back_get_block(int unit, bcm_l2_addr_t *l2e, void* ud) {
    printf("| %02x:%02x:%02x:%02x:%02x:%02x |",
         l2e->mac[0],l2e->mac[1],l2e->mac[2],
         l2e->mac[3],l2e->mac[4],l2e->mac[5]);
    printf(" VLAN=0x%04x | PORT=0x%08x |", l2e->vid, l2e->port);
    printf("GROUP=0x%x|\n", l2e->group);

    return BCM_E_NONE;
}

/*
 * Add entry to mac table <vlan,mac>
 * flags argument is configurd as BCM_L2_STATIC if iteration over dynamic entries is not supported in device
 */
void
l2_addr_init(int unit, bcm_mac_t mac, uint16 vid, bcm_l2_addr_t *l2_addr) {
    int dynamic_entries_iteration_support = *dnxc_data_get(unit, "l2", "general", "dynamic_entries_iteration_support", NULL);


    bcm_l2_addr_t_init(l2_addr, mac, vid);
    /** Insert static entries in case device does not support iteration over dynamic entries*/
    if(!dynamic_entries_iteration_support){
        l2_addr->flags = BCM_L2_STATIC;
    }
}

/*
 * - Add entries to different groups
 * - Dump/traverse MACT table according to specific group
 * - Delete according to specific group
 *
 * - group: user define value set when adding static entries
 *        88650: 1-7 groups. group 0: not assigned to group (backward comp)
 */
int
 mact_group_traverse_example(int unit, int local_port) {
    int a=0;
    int flags=0;

    bcm_l2_addr_t l2_addr;
    bcm_gport_t dest_port;
    bcm_mac_t mac1;
    bcm_vlan_t vid;
    int grp1, grp2;
    bcm_l2_addr_t match_addr;

    /* init data */
    vid=10;
    mac1[5] = 0x32;
    grp1 = 3;
    grp2 = 4;
    l2_addr_init(unit,mac1,vid,&l2_addr);

    l2_addr.port = dest_port;
    BCM_GPORT_LOCAL_SET(dest_port,local_port);

    /* add L2 entries with group grp1*/
    l2_addr.group = grp1;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    l2_addr.vid++;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    l2_addr.vid++;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    /* add L2 entries with group 4*/
    l2_addr.group = grp2;

    l2_addr.vid++;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    l2_addr.vid++;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit,&l2_addr), "");

    if (verbose >= 2) {
        printf("dump all entries (showing group of each entry) \n");
    }

    /* traverse: show group of each entry */
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    /* traverse according to group grp1 */
    if (verbose >= 2) {
        printf("dump entries in group %d\n",grp1);
    }
    l2_addr_init(unit,mac1,vid,&match_addr);
    match_addr.group = grp1;
    flags = BCM_L2_TRAVERSE_MATCH_GROUP;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_matched_traverse(unit,flags, &match_addr, call_back_get_block, &a), "");

    /* traverse according to group grp2 */
    if (verbose >= 2) {
        printf("dump entries in group %d\n",grp2);
    }

    l2_addr_init(unit,mac1,vid,&match_addr);
    match_addr.group = grp2;

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_matched_traverse(unit,flags, &match_addr, call_back_get_block, &a), "");

    if (verbose >= 2) {
        printf("delete entries in group %d\n",grp1);
    }

    flags = BCM_L2_REPLACE_MATCH_STATIC | BCM_L2_REPLACE_DELETE | BCM_L2_REPLACE_NO_CALLBACKS
            | BCM_L2_REPLACE_IGNORE_DES_HIT | BCM_L2_REPLACE_MATCH_GROUP;

    l2_addr_init(unit,mac1,vid,&match_addr);
    match_addr.group = grp1;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_replace(unit, flags, match_addr, 0,0,0), "");

    if (verbose >= 2) {
        printf("dump entries (after remove group %d) \n",grp1);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    return BCM_E_NONE;
}

/*
 * - Add entries to MACT
 * - Set traverse mode to aggregate
 * - Call several delete-by APIs
 * - Commit all rules
 *
 * Parameters:
 * - dest_ports: port array of size = 4, used as destination of L2 entries
 *
 * MAX number of rules
 * - 88650: up to 8 rules.
 */
int
 mact_multiple_rules_example(int unit, int local_port, int *dest_ports) {
    int a=0;

    example_new_vlan_entries(unit,1,local_port,dest_ports[0],5);
    example_new_vlan_entries(unit,2,local_port,dest_ports[1],5);
    example_new_vlan_entries(unit,2,local_port,dest_ports[2],5);
    example_new_vlan_entries(unit,3,local_port,dest_ports[3],5);

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    bshell(unit, "g IHP_MACT_COUNTER_LIMIT_MACT_DB_ENTRIES_COUNT");

    /* set aggregate mode */
    if (verbose >= 2) {
        printf("set traverse to aggregate mode\n");
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchTraverseMode, bcmSwitchTableUpdateRuleAdd),
        "bcmSwitchTraverseMode:bcmSwitchTraverseMode");

    /* delete entries frwrd to port[0] */
    if (verbose >= 2) {
        printf("delete entries with dest = 0x%08x\n", dest_ports[0]);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_delete_by_port(unit,0,dest_ports[0],BCM_L2_DELETE_NO_CALLBACKS|BCM_L2_DELETE_STATIC), "");

    /* delete entries frwrd to port[1] */
    if (verbose >= 2) {
        printf("delete entries with dest = 0x%08x\n", dest_ports[1]);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_delete_by_port(unit,0,dest_ports[1],BCM_L2_DELETE_NO_CALLBACKS|BCM_L2_DELETE_STATIC), "");
    /* show no change yet */
    /* cannot dump table as dump us traverse */
    if (verbose >= 2) {
        printf("sleep 1 second\n");
    }

    sal_sleep(1);

    bshell(unit, "g IHP_MACT_COUNTER_LIMIT_MACT_DB_ENTRIES_COUNT");

    if (verbose >= 2) {
        printf("commit rules \n");
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchTraverseMode, bcmSwitchTableUpdateRuleCommit),
        "bcmSwitchTraverseMode:bcmbcmSwitchTableUpdateRuleCommit");

    if (verbose >= 2) {
        printf("sleep 1 second\n");
    }

    sal_sleep(1);
    bshell(unit, "g IHP_MACT_COUNTER_LIMIT_MACT_DB_ENTRIES_COUNT");

    /* restor normal behavoir of traverse */
    if (verbose >= 2) {
        printf("clear rules and back to normal mode\n");
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchTraverseMode, bcmSwitchTableUpdateRuleClear),
        "bcmSwitchTraverseMode:bcmSwitchTableUpdateRuleClear");

    BCM_IF_ERROR_RETURN_MSG(bcm_switch_control_set(unit, bcmSwitchTraverseMode, bcmSwitchTableUpdateNormal),
        "bcmSwitchTraverseMode:bcmSwitchTableUpdateNormal");

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    return BCM_E_NONE;
}

/*
 * - Add entries to MACT on different vlans
 * - Delete all entries by VLAN value and mask
 *
 * Parameters:
 * - local_port: to be use as destination of the L2 entries
 */
int
 mact_rule_mask_vlan_example(int unit, int local_port) {
    int a=0;
    int flags;
    bcm_mac_t mac_init = {0};
    bcm_l2_addr_t match_addr;
    bcm_l2_addr_t match_mask_addr;
    bcm_l2_addr_t replace_mask_addr;
    bcm_l2_addr_t replace_addr;
    bcm_vlan_t vlan =0;

    /* (int unit, int vlan, int in_port, int dest_port, int nof_entries);*/
    example_new_vlan_entries(unit,0xf0f,local_port,local_port,5);
    example_new_vlan_entries(unit,0x70f,local_port,local_port,5);
    example_new_vlan_entries(unit,0xf0e,local_port,local_port,5);
    example_new_vlan_entries(unit,0xf1f,local_port,local_port,5);
    example_new_vlan_entries(unit,0xfff,local_port,local_port,5);
    example_new_vlan_entries(unit,0xfaf,local_port,local_port,5);

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    flags = BCM_L2_REPLACE_MATCH_STATIC | BCM_L2_REPLACE_DELETE | BCM_L2_REPLACE_NO_CALLBACKS
            | BCM_L2_REPLACE_IGNORE_DISCARD_SRC | BCM_L2_REPLACE_IGNORE_DES_HIT;
    /*
    * JR2 does not support BCM_L2_REPLACE_IGNORE_DISCARD_SRC
    */
	flags &= ~BCM_L2_REPLACE_IGNORE_DISCARD_SRC;
    flags |= BCM_L2_REPLACE_MATCH_VLAN;

    bcm_l2_addr_t_init(&match_addr,mac_init,0);
    bcm_l2_addr_t_init(&match_mask_addr,mac_init,0);
    bcm_l2_addr_t_init(&replace_addr,mac_init,0);
    bcm_l2_addr_t_init(&replace_mask_addr,mac_init,0);

    /* delete according to vlan, all entries with vlan =  f?f, middle nibble is ignored */
    match_addr.vid = 0xf0f;
    match_mask_addr.vid = 0xf0f;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_replace_match(unit, flags, &match_addr, match_mask_addr,replace_addr,replace_mask_addr), "");

    /* sleep till replace done */
    if (verbose >= 2) {
        printf("sleep 1 second\n");
    }

    sal_sleep(1);

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    return BCM_E_NONE;
}



/*
 * - Add entries to MACT on different vlan ports
 * - Delete all entries by VLAN port value and mask
 *
 * Parameters:
 * - local_port: to be use as destination of the L2 entries
 */
int
 mact_rule_mask_vlan_port_example(int unit, int local_port) {
    int a=0;
    int flags;
    bcm_mac_t mac_init = {0};
    bcm_l2_addr_t match_addr;
    bcm_l2_addr_t match_mask_addr;
    bcm_l2_addr_t replace_mask_addr;
    bcm_l2_addr_t replace_addr;
    bcm_vlan_t vlan =0;
    int nof_gports = 20;
    int gports[20] = {0};

    /* fill mact:*/
    BCM_IF_ERROR_RETURN_MSG(mact_add_l2_entry_to_vlan_port(unit,local_port,nof_gports,gports), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    flags = BCM_L2_REPLACE_MATCH_STATIC | BCM_L2_REPLACE_DELETE | BCM_L2_REPLACE_NO_CALLBACKS
            | BCM_L2_REPLACE_IGNORE_DISCARD_SRC | BCM_L2_REPLACE_IGNORE_DES_HIT;
    /*
    * JR2 does not support BCM_L2_REPLACE_IGNORE_DISCARD_SRC
    */
	flags &= ~BCM_L2_REPLACE_IGNORE_DISCARD_SRC;
    flags |= BCM_L2_REPLACE_MATCH_DEST;

    bcm_l2_addr_t_init(&match_addr,mac_init,0);
    bcm_l2_addr_t_init(&match_mask_addr,mac_init,0);
    bcm_l2_addr_t_init(&replace_addr,mac_init,0);
    bcm_l2_addr_t_init(&replace_mask_addr,mac_init,0);
    match_addr.port = gports[0];
    match_mask_addr.port = 0x5; /* consider only bit[0] and and bit[2] */

    /*
    * encap_id needs to be set when used as mask in JR2
    */
	match_mask_addr.port = BCM_GPORT_BLACK_HOLE;
	BCM_FORWARD_ENCAP_ID_VAL_SET(match_mask_addr.encap_id, BCM_FORWARD_ENCAP_ID_TYPE_OUTLIF, BCM_FORWARD_ENCAP_ID_OUTLIF_USAGE_GENERAL, 5);

    /* delete according to vlan-port (outlif),
       all entries with outlif: xxx1x0
     */
    if (verbose >= 2) {
        printf("delete gport match [0x%08x/0x%08x],\n",match_addr.port,match_mask_addr.port);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_replace_match(unit, flags, &match_addr, match_mask_addr,replace_addr,replace_mask_addr), "");

    if (verbose >= 2) {
        printf("sleep 1 second\n");
    }

    sal_sleep(1);

    BCM_IF_ERROR_RETURN_MSG(bcm_l2_traverse(unit,call_back_get_block, &a), "");

    return BCM_E_NONE;
}


/*
 * utility functions:
 *     create vlan-port
 */
int
mact_vlan_port_create(int unit, int port, int vlan,  bcm_gport_t *port_id){
    bcm_vlan_port_t vp1;

    bcm_vlan_port_t_init(&vp1);

    vp1.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vp1.port = port;
    vp1.match_vlan = vlan;
    vp1.egress_vlan = 0;
    vp1.flags = 0;
    vp1.vlan_port_id = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit,&vp1), "");


    if(verbose >= 3){
        printf("Add vlan-port-id:0x%08x in-port:0x%08x match_vlan:0x%08x match_inner_vlan:0x%08x in unit %d\n",
                vp1.vlan_port_id, vp1.port, vp1.match_vlan, vp1.match_inner_vlan, unit);
    }

    *port_id = vp1.vlan_port_id;
    return BCM_E_NONE;
}

/*
 * utility functions:
 *     create nof_gports gports on local_port and add MACT entry to each of the gports
 */
uint32 mact_add_l2_entry_to_vlan_port(int unit, int local_port, int nof_gports, int *gports){
    uint32 in_vlan = 0xabc;
    int in_port = local_port;
    uint32 index;

    for (index = 0; index < nof_gports; index++, in_vlan++) {
        BCM_IF_ERROR_RETURN_MSG(mact_vlan_port_create(unit,in_port,in_vlan,&gports[index]), "");
        example_new_vlan_entries(unit,in_vlan,in_port,gports[index],2);
    }

    if(verbose >= 1)
        print gports;

    return BCM_E_NONE;
}

