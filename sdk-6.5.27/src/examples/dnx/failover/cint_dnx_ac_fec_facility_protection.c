/* $Id: cint_dnx_ac_fec_facility_protection.c
 *
 * **************************************************************************************************************************************************
 *                                                                                                                                                  *
 * The CINT provides two protection examples:                                                                                                       *
 *                                                                                                                                                  *
 * Example 1:                                                                                                                                       *
 * ==========                                                                                                                                       *
 * Facility FEC (The Super-FEC Protection Pointer is -2)                                                                                            *
 *                                                                                                                                                  *
 * 1. Set the Destination-Status of the working port to 0 (Disable)                                                                                 *
 * 2. Expect to receive the packet in protecting port                                                                                               *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                  ________________________________                                                                *
 *                                                 |                   _____        |                                                               *
 *                           In-AC                 |                  |     | ----> | -----                                                         *
 *                               ----------------> | -   -   -   -  > | FEC |       |      |                                                        *
 *                                                 |                  |_____| ----> | ---  |                                                        *
 *                                                 |                                |    | |                                                        *
 *                                                 |                                |    | |                                                        *
 *                           Working Out-AC  /     |                                |    | |                                                        *
 *                               <----------/----- | < -- - -  -   -  -   -   -  -  | <--  |                                                        *
 *                                         /       |                                |      |                                                        *
 *                           Protecting Out-AC     |                                |      |                                                        *
 *                               <---------------- | < -- - -  -   -  -   -   -  -  | <----                                                         *
 *                                                 |                                |                                                               *
 *                                                 |________________________________|                                                               *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 * Example 2:                                                                                                                                       *
 * ==========                                                                                                                                       *
 * Facility FEC with simultaneous mode (Facility & The Super-FEC Protection Pointer has a vaild Path pointer)                                       *
 *                                                                                                                                                  *
 * Set following SOC properties:                                                                                                                    *
 * Configure the device to be in "bcm886xx_fec_accelerated_reroute_mode=1"                                                                          *
 *                                                                                                                                                  *
 * 1. Set protection_path to protecting port                                                                                                        *
 * 2. Set the Destination-Status of the protecting port to 0 (Disable)                                                                              *
 * 3. Expect to receive the packet in working port                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                  ________________________________                                                                *
 *                                                 |                   _____        |                                                               *
 *                           In-AC                 |                  |     | ----> | -----                                                         *
 *                               ----------------> | -   -   -   -  > | FEC |       |      |                                                        *
 *                                                 |                  |_____| ----> | ---  |                                                        *
 *                                                 |                                |    | |                                                        *
 *                                                 |                                |    | |                                                        *
 *                           Working Out-AC        |                                |    | |                                                        *
 *                               <---------------- | < -- - -  -   -  -   -   -  -  | <--  |                                                        *
 *                                                 |                                |      |                                                        *
 *                           Protecting Out-AC  /  |                                |      |                                                        *
 *                               <-------------/-- | < -- - -  -   -  -   -   -  -  | <----                                                         *
 *                                            /    |                                |                                                               *
 *                                                 |________________________________|                                                               *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 * Configuration:                                                                                                                                   *
 *                                                                                                                                                  *
 *                                                                                                                                                  *
 * run:                                                                                                                                             *
 *************************Facility FEC with simultaneous mode (Facility & The Super-FEC Protection Pointer has a vaild Path pointer)*****************
 * Test Scenario - start
  config add bcm886xx_fec_accelerated_reroute_mode.0=1                                                                                 
  0: tr 141 NoInit=1                                                                                                                   
  config add custom_feature_init_verify=1                                                                                              
  config delete custom_feature_multithread_en*                                                                                         
  config delete custom_feature_kbp_multithread_en*                                                                                     
  0: tr 141 NoDeinit=1                                                                                                                 
 *                                                                                                                                                  *
  cint ../../../../src/examples/dnx/l3/cint_dnx_ip_route_basic.c                                                                                       
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c                                                                                    
  cint ../../../../src/examples/dnx/failover/cint_dnx_ac_fec_facility_protection.c                                                                              
  cint                                                                                                                                             
  ac_fec_facility_protection_with_ports__start_run(0,201,202,203,247652);                                                                          
  exit;                                                                                                                                            
 *                                                                                                                                                  *
 * Stage 1: Send a packet with known DA. Expect to receive on the Working port.                                                                     *
  tx 1 psrc=201 data=0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * Stage 2: Disable Working port. Expect to receive on the Protecting port.                                                                         *
  tx 1 psrc=201 data=0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * Stage 3: Enable Working port. Expect to receive on the Working port.                                                                             *
  tx 1 psrc=201 data=0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000eba0f21281000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * stage 4: Disable both working and protecing ports. Expect to receive on the working port.                                                        *
  tx 1 psrc=201 data=0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * stage 5: Set protection path to protecting port. Enable working and protecting ports. Expect to receive on the Protecting port.                  *
  tx 1 psrc=201 data=0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * stage 6: Protection path is protecting port. Enable working port. Disable protecting port. Expect to receive on the Working port.                *
  tx 1 psrc=201 data=0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * stage 7: Protection path is protecting port. Disable both working and protecing ports. Expect to receive on the protecting port.                 *
  tx 1 psrc=201 data=0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e100000ad43e9f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
  config delete bcm886xx_fec_accelerated_reroute_mode.0                                                                                
  0: tr 141 NoInit=1                                                                                                                   
  config add custom_feature_init_verify=1                                                                                              
  config delete custom_feature_multithread_en*                                                                                         
  config delete custom_feature_kbp_multithread_en*                                                                                     
  0: tr 141 NoDeinit=1                                                                                                                 
 * Test Scenario - end
 *                                                                                                                                                  *
 *******************************************Facility FEC (The Super-FEC Protection Pointer is -2)****************************************************
 * Test Scenario - start
  cint ../../../../src/examples/dnx/l3/cint_dnx_ip_route_basic.c                                                                                       
  cint ../../../../src/examples/dnx/utility/cint_dnx_utils_global.c                                                                                    
  cint ../../../../src/examples/dnx/failover/cint_dnx_ac_fec_facility_protection.c                                                                              
  cint                                                                                                                                             
  ac_fec_facility_protection_with_ports__start_run(0,201,202,203,0);                                                                               
  exit;                                                                                                                                            
 *                                                                                                                                                  *
 * Stage 1: Send a packet with known DA. Expect to receive on the Working port.                                                                     *
  tx 1 psrc=201 data=0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * Stage 2: Disable Working port. Expect to receive on the Protecting port.                                                                         *
  tx 1 psrc=201 data=0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * Stage 3: Enable Working port. Expect to receive on the Working port.                                                                             *
  tx 1 psrc=201 data=0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000b982794181000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 *                                                                                                                                                  *
 * Stage 4: Disable both working and protecing ports. Expect to receive on the protecting port.                                                     *
  tx 1 psrc=201 data=0xa600000000e10000b56bd12f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20                      
 *                                                                                                                                                  *
 * Received packets on unit 0 should be:                                                                                                            *
 * Data: 0xa600000000e10000b56bd12f81000014ffff000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f200000000000000000000000             *
 * Test Scenario - end
 *                                                                                                                                                  *
 ************************************************************************************************************************************************** */

struct ac_fec_facility_protection_s {
    bcm_vlan_t vlan;
    bcm_mac_t mac;
    int in_port;
    int out_port_working;
    int out_port_protecting;
    bcm_failover_t failover_id;
    int hierarchy_level;
};

/* Initialization of global struct*/
ac_fec_facility_protection_s g_ac_fec_facility_protection = {
            20,                                     /* VSI */
            {0xa6, 0x00, 0x00, 0x00, 0x00, 0xe1},   /* MAC Address Out */
            201,                                    /* IN-PORT */
            13,                                     /* OUT-PORT WORKING */
            14,                                     /* OUT-PORT PROTECTING */
            0,                                      /* FAILOVER-ID */
            2};                                     /* Hierarchical level */

int fec_standby=0x2000A563;
int fec_primary=0x2000A562;

/* **************************************************************************************************
  --------------          Global  Variables Definitions and Initialization  END       ---------------
 **************************************************************************************************** */

/* Initialization of the main struct
 * Function allows the re-write of default values
 *
 * INPUT:
 * params: new values for g_ac_fec_facility_protection
 */
int ac_fec_facility_protection_init(int unit, ac_fec_facility_protection_s *params) {
    int rv;
    int flags;
    int failover_flag_per_hierarchy[] = {0, BCM_FAILOVER_FEC_2ND_HIERARCHY, BCM_FAILOVER_FEC_3RD_HIERARCHY};

    if (params != NULL) {
       sal_memcpy(&g_ac_fec_facility_protection, params, sizeof(g_ac_fec_facility_protection));
    }

    if (g_ac_fec_facility_protection.failover_id) {
        /* This is the simultaneous mode case, where the received failover_id has a vaild Path pointer */
        flags = (BCM_FAILOVER_WITH_ID | BCM_FAILOVER_FEC | failover_flag_per_hierarchy[g_ac_fec_facility_protection.hierarchy_level]);

        /* Create failover object. This call can fail in case that the user allready created the failover object */
        rv = bcm_failover_create(unit, flags, &g_ac_fec_facility_protection.failover_id);
        if (rv == BCM_E_RESOURCE) {
            rv = BCM_E_NONE;
        }
        BCM_IF_ERROR_RETURN_MSG(rv, "");
    } else {
        /* This is the simple facility mode case. Here we assign the failover_id to -2 */

        /* This is to get the encoding of the FEC type */
        g_ac_fec_facility_protection.failover_id = 1;
        BCM_IF_ERROR_RETURN_MSG(bcm_failover_create(unit, (BCM_FAILOVER_WITH_ID | BCM_FAILOVER_FEC), &g_ac_fec_facility_protection.failover_id), "");
        g_ac_fec_facility_protection.failover_id = BCM_FAILOVER_ID_LOCAL;
    }

    printf("Failover_id: %d\n", g_ac_fec_facility_protection.failover_id);

    return BCM_E_NONE;
}


int ac_fec_facility_protection_deinit(int unit) {
    int rv;

    printf("ac_fec_facility_protection_deinit: g_ac_fec_facility_protection.failover_id = %d\n", g_ac_fec_facility_protection.failover_id);

    rv = bcm_failover_destroy(unit, g_ac_fec_facility_protection.failover_id);
    if (rv == BCM_E_RESOURCE) {
        rv = BCM_E_NONE;
    }
    BCM_IF_ERROR_RETURN_MSG(rv, "");

    return BCM_E_NONE;
}


/* Retrieve the initial confgiuration for the example.
 *
 * INPUT:
 *   protection_ac_s: Configuration info for a single In-AC.
 */
void ac_fec_facility_protection__struct_get(ac_fec_facility_protection_s *param){
    sal_memcpy(param, &g_ac_fec_facility_protection, sizeof(*param));
    return;
}


/* Main function that performs all the configuarations for the example.
 * Performs init configuration before configuring the ACs and adding a static MAC
 * entry for the UC packets.
 * INPUT:
 *   protection_ac_s: Configuration info for running the example.
 */
int ac_fec_facility_protection__start_run(int unit, ac_fec_facility_protection_s *params) {
    int fec_flag_per_hierarchy[] = {0, BCM_L3_2ND_HIERARCHY, BCM_L3_3RD_HIERARCHY};
    bcm_l3_egress_t fec;

    BCM_IF_ERROR_RETURN_MSG(ac_fec_facility_protection_init(unit, *params), "");

    /* Create the protecting FEC entry */
    bcm_vlan_port_t vport_t_protection;
    bcm_vlan_port_t_init(&vport_t_protection);
    vport_t_protection.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vport_t_protection.match_vlan = g_ac_fec_facility_protection.vlan;
    vport_t_protection.port = g_ac_fec_facility_protection.out_port_protecting;
    BCM_IF_ERROR_RETURN_MSG(get_first_fec_in_range_which_not_in_ecmp_range(unit, g_ac_fec_facility_protection.hierarchy_level, 0, &fec_primary), "");

    fec_primary |= 0x20000000 + g_ac_fec_facility_protection.hierarchy_level * 2;
    fec_standby = fec_primary + 1;
    vport_t_protection.failover_id = 0;
    BCM_L3_ITF_FEC_TO_GPORT_FORWARD_GROUP(vport_t_protection.failover_port_id, fec_standby);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vport_t_protection), "");
    printf("Created vlan_port: port-%d vlan-%d\n", g_ac_fec_facility_protection.out_port_protecting, g_ac_fec_facility_protection.vlan);

    bcm_vlan_port_t vport_t_protection_get;
    bcm_vlan_port_t_init(&vport_t_protection_get);
    vport_t_protection_get.vlan_port_id = vport_t_protection.vlan_port_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_find(unit, &vport_t_protection_get), "");

    if(sal_memcmp(&vport_t_protection_get, &vport_t_protection, sizeof(vport_t_protection)) != 0) {
        printf("Error, vport_t_protection_get isn't same with vport_t_protection\n");
        print vport_t_protection_get;
        print vport_t_protection;
        return BCM_E_FAIL;
    }

    /* Create the working FEC entry */
    bcm_vlan_port_t vport_working;
    bcm_vlan_port_t_init(&vport_working);
    vport_working.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vport_working.flags = BCM_VLAN_PORT_WITH_ID;
    vport_working.vlan_port_id = vport_t_protection.vlan_port_id + 1;
    vport_working.match_vlan = g_ac_fec_facility_protection.vlan;
    vport_working.port = g_ac_fec_facility_protection.out_port_working;
    vport_working.failover_id = 0;
    BCM_L3_ITF_FEC_TO_GPORT_FORWARD_GROUP(vport_working.failover_port_id, fec_primary);
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &vport_working), "");
    printf("Created vlan_port: port-%d vlan-%d\n", g_ac_fec_facility_protection.out_port_working, g_ac_fec_facility_protection.vlan);

    bcm_vlan_port_t vport_working_get;
    bcm_vlan_port_t_init(&vport_working_get);
    vport_working_get.vlan_port_id = vport_working.vlan_port_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_find(unit, &vport_working_get), "");

    vport_working_get.flags |= BCM_VLAN_PORT_WITH_ID;
    if (sal_memcmp(&vport_working_get, &vport_working, sizeof(vport_working)) != 0) {
        printf("Error, vport_working_get isn't same with vport_working\n");
        print vport_working_get;
        print vport_working;
        return BCM_E_FAIL;
    }

    /*
     * Creates backup FEC:
     */
    bcm_l3_egress_t_init(&fec);
    fec.flags=fec_flag_per_hierarchy[g_ac_fec_facility_protection.hierarchy_level];
    fec.intf=vport_t_protection.vlan_port_id;
    fec.vlan=g_ac_fec_facility_protection.vlan;
    fec.port=g_ac_fec_facility_protection.out_port_protecting;
    fec.failover_id=g_ac_fec_facility_protection.failover_id;
    fec.failover_if_id = 0;
    if (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec.flags2 = BCM_L3_FLAGS2_FWD_ONLY;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_create(unit, BCM_L3_INGRESS_ONLY | BCM_L3_WITH_ID, fec, &fec_standby), "");

    /*
     * Creates primary FEC:
     */
    bcm_l3_egress_t_init(&fec);
    fec.flags=fec_flag_per_hierarchy[g_ac_fec_facility_protection.hierarchy_level];
    fec.intf=vport_working.vlan_port_id;
    fec.vlan=g_ac_fec_facility_protection.vlan;
    fec.port=g_ac_fec_facility_protection.out_port_working;
    fec.failover_id=g_ac_fec_facility_protection.failover_id;
    fec.failover_if_id = fec_standby;
    if (*dnxc_data_get(unit, "l3", "feature", "separate_fwd_rpf_dbs", NULL))
    {
        fec.flags2 = BCM_L3_FLAGS2_FWD_ONLY;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_l3_egress_create(unit, BCM_L3_INGRESS_ONLY | BCM_L3_WITH_ID, fec, &fec_primary), "");

    /* Create the in-ac */
    bcm_vlan_port_t in_ac;
    bcm_vlan_port_t_init(&in_ac);
    in_ac.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    in_ac.port = g_ac_fec_facility_protection.in_port;
    in_ac.match_vlan = g_ac_fec_facility_protection.vlan;
    in_ac.vsi = 0;
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_port_create(unit, &in_ac), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_create_with_id(unit,g_ac_fec_facility_protection.vlan), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_vswitch_port_add(unit, g_ac_fec_facility_protection.vlan, in_ac.vlan_port_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit, g_ac_fec_facility_protection.vlan, g_ac_fec_facility_protection.in_port, 0), "");

    /* Add a MACT entry */
    bcm_l2_addr_t l2_addr;
    l2_addr.mac = g_ac_fec_facility_protection.mac;
    l2_addr.vid = g_ac_fec_facility_protection.vlan;
    l2_addr.port = vport_t_protection.vlan_port_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_l2_addr_add(unit, &l2_addr), "");

    return BCM_E_NONE;
}

/* This function runs the main test function with specified ports
 *
 * INPUT: in_port  - ingress port .
 *        out_port_working - egress port.
 *        out_port_protecting - egress port.
 *        failover_id - If simultaneous_mode- failover_id. Otherwise, 0.
 */
int ac_fec_facility_protection_with_ports__start_run(int unit, int in_port, int out_port_working, int out_port_protecting, bcm_failover_t failover_id, int hierarchy_level) {
    ac_fec_facility_protection_s param;
    ac_fec_facility_protection__struct_get(&param);

    param.in_port = in_port;
    param.out_port_working = out_port_working;
    param.out_port_protecting = out_port_protecting;
    param.failover_id = (failover_id == 0) ? 0 : (failover_id + hierarchy_level);
    param.hierarchy_level = hierarchy_level;
    param.vlan = 20 + hierarchy_level;

    return ac_fec_facility_protection__start_run(unit, &param);
}



