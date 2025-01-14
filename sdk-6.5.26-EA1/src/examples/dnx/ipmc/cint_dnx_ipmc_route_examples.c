/*
 * 
 This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 
 Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
int print_level = 2;
struct ip_mc_s {
    int      is_ingress_mc; /* indicate if we're running the test using ingress MC or egress MC */
};

ip_mc_s g_ip_mc =
{
/* is ingress mc */
0
};
int IP_ROUTE_NOF_REPLICATIONS = 4;

/*
 *  Creates an IP MC Group
 *  Here we create the actual MC group.
 *  We must run this function before creating the IP MC entry
 *  The creation of IPv4 and IPv6 MC Groups is identical
 *
 *  MC group can be ingress/egress/both, depending on the flags
 *  flags: BCM_MULTICAST_INGRESS_GROUP and/or BCM_MULTICAST_EGRESS_GROUP
 */
bcm_multicast_t
create_ip_mc_group(
    int unit,
    int flags,
    int ipmc_index,
    int dest_local_port_id,
    int nof_ports,
    int vlan_base,
    uint8 change_vlan)
{
    bcm_error_t rv = BCM_E_NONE;
    bcm_gport_t dest_gport;
    int port_indx;
    int nof_reps = 0;
    bcm_multicast_t mc_id = ipmc_index;
    bcm_multicast_replication_t replications[IP_ROUTE_NOF_REPLICATIONS];

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        rv = bcm_multicast_group_destroy(unit, flags, mc_id);
    } else { 
        rv = bcm_multicast_destroy(unit, mc_id);
    }
    if ((rv != BCM_E_NONE) && (rv != BCM_E_NOT_FOUND)) {
        printf("Error, in multicast_destroy, mc_id $mc_id\n");
        return rv;
    }

    flags |= BCM_MULTICAST_WITH_ID;
    rv = bcm_multicast_create(unit, flags, &mc_id);
    if (rv != BCM_E_NONE) {
        printf("Error, in multicast_create, mc_id $mc_id flags $flags\n");
        return rv;
    }

    BCM_GPORT_LOCAL_SET(dest_gport, dest_local_port_id);
    for(port_indx = 0; port_indx < nof_ports; ++port_indx) {
        bcm_multicast_replication_t_init(&replications[port_indx]);
        replications[port_indx].encap1 = vlan_base + ((change_vlan && port_indx >= 1) ? port_indx : 0);
        replications[port_indx].port = dest_gport + port_indx;
        nof_reps ++;
    }

    flags = (flags & ~BCM_MULTICAST_WITH_ID);
    if (nof_ports > 0) {
        rv = bcm_multicast_set(unit, mc_id, flags, nof_reps, replications);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_multicast_set\n");
            return rv;
        }
    }

    if(print_level >= 2) {
        printf("create MC group: 0x%08x\n", mc_id);
    }

    if (flags & BCM_MULTICAST_EGRESS_GROUP) {
        rv = multicast__open_fabric_mc_or_ingress_mc_for_egress_mc(unit, mc_id, mc_id);
        if (rv != BCM_E_NONE) {
           printf("Error, multicast__open_fabric_mc_or_ingress_mc_for_egress_mc \n");
           return rv;
        }
    }

    return mc_id;
}

int lpm_raw_data_enabled =0;         /* use raw data payload in KAPs LPM */
int lpm_payload = 0x1234;            /* raw payload in Kaps*/

/*
 * In this example, we send a packet with MC IP 224.224.224.1, dedicated mymac and vlan 2, through the iport.
 *
 * We then expect the packet to multicast and exit on four different rifs if packet TTL is larger than the out-RIF TTL threshold:
 *      - oport + outrif 2 - will fallback to bridge and be filtered because of same interface filter
 *      - (oport + 1) + outrif 3 (vlan 3)
 *      - (oport + 2) + ourtif 4 (vlan 4)
 *      - (oport + 3) + ourtif 5 (vlan 5)
 */
/*
 * Test Scenario
 *
 * ./bcm.user
 * cd ../../../../regress/bcm
 * cint ../../src/./examples/dnx/utility/cint_dnx_utils_global.c
 * cint ../../src/./examples/dnx/utility/cint_dnx_utils_l3.c
 * cint ../../src/./examples/dnx/l3/cint_dnx_ip_route_basic.c
 * cint ../../src/./examples/dnx/l3/cint_ip_route_scenarios.c
 * cint ../../src/./examples/dnx/ipmc/cint_dnx_ipmc_route_basic.c
 * cint ../../src/./examples/dnx/ipmc/cint_dnx_ipmc_route_examples.c
 * cint
 * run_with_ports_ipv4_mc_example_with_ttl(0,200,201,25);
 * exit;
 *
 * tx 1 psrc=200 data=0x01005e60e00100000000000181000002080045000035000000001a001e66c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * If packtet TTL=26 is larger than the out-RIF TTL threshold 25, then received packets on unit 0 should be:
 * Source port: 0, Destination port: 0
 *  Data: 0x01005e60e00100000000ab1d810000030800450000350000000019001f66c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *  Source port: 0, Destination port: 0
 *  Data: 0x01005e60e00100000000ab1d810000040800450000350000000019001f66c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *  Source port: 0, Destination port: 0
 *  Data: 0x01005e60e00100000000ab1d810000050800450000350000000019001f66c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * tx 1 psrc=200 data=0x01005e60e001000000000001810000020800450000350000000018002066c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * packets on unit 0 should be drop because packtet TTL=24 is lower than the out-RIF TTL threshold 25
 *
 * tx 1 psrc=200 data=0x01005e60e001000000000001810000020800450000350000000019001f66c0800101e0e0e001000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f20
 *
 * packets on unit 0 should be drop because packet TTL=25 is equal with the out-RIF TTL threshold 25
 *
 */
int
run_with_ports_ipv4_mc_example_with_ttl(
    int unit,
    int iport,
    int oport,
    int ttl_threshold)
{
    uint32 rv = BCM_E_NONE;
    bcm_gport_t dst_gport;

    /* Set parameters: User can set different parameters. */
    bcm_ip_t mc_ip = 0xE0E0E001; /* 224.224.224.1 */
    bcm_ip_t src_ip = 0xC0800101; /* 192.128.1.1 */
    int vlan = 2;
    int vrf = 2;
    int ipmc_index = 6000;
    int dest_local_port_id = iport;
    int source_local_port_id = oport;
    int nof_dest_ports = 4, port_ndx;
    bcm_mac_t mac_l3_ingress = {0x00, 0x00, 0x00, 0x00, 0xab, 0x1d};
    l3_ingress_intf ingress_itf;
    dnx_utils_l3_eth_rif_s eth_rif;
    uint32 mc_flags = 0;

    if (g_ip_mc.is_ingress_mc == TRUE) {
        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            mc_flags = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC);
        } else {
            mc_flags = BCM_MULTICAST_INGRESS_GROUP;
        }
    } else {
        mc_flags = BCM_MULTICAST_EGRESS_GROUP;
    }

    bcm_multicast_t mc_id = create_ip_mc_group(unit, mc_flags, ipmc_index, dest_local_port_id, nof_dest_ports, vlan, TRUE);

    for(port_ndx = 0; port_ndx < nof_dest_ports; ++port_ndx) {
        rv = in_port_intf_set(unit, dest_local_port_id + port_ndx, vlan);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in_port_intf_set vlan\n");
            return rv;
        }
        rv = out_port_set(unit, (dest_local_port_id+port_ndx));
        if (rv != BCM_E_NONE && rv != BCM_E_EXISTS)
        {
            printf("Error, out_port_intf_set intf_out\n");
            return rv;
        }

        dnx_utils_l3_eth_rif_s_common_init(unit, 0, &eth_rif, (vlan + port_ndx), 0, BCM_L3_INGRESS_GLOBAL_ROUTE, mac_l3_ingress, (vrf + port_ndx));
        if (ttl_threshold != 0) {
            eth_rif.ttl_valid = 1;
            eth_rif.ttl  = ttl_threshold;
        }
        rv = dnx_utils_l3_eth_rif_create(unit, &eth_rif);
        if (rv != BCM_E_NONE && rv != BCM_E_EXISTS)
        {
            printf("Error, dnx_utils_l3_eth_rif_create intf_in = %d, err_id = %d\n", (vlan+port_ndx), rv);
            return rv;
        }

        if (lpm_raw_data_enabled) {
            rv = add_ipv4_ipmc_raw(unit, mc_ip, 0xFFFFFFFF, src_ip, 0xFFFFFFFF, (vlan+port_ndx), (vrf+port_ndx), 0, lpm_payload);
        } else {
            rv = add_ipv4_ipmc(unit, mc_ip, 0xFFFFFFFF, src_ip, 0xFFFFFFFF, (vrf+port_ndx),(vlan+port_ndx), mc_id, 0, 0);
        }
        if (rv != BCM_E_NONE){
            return rv;
        }
    }

    /* redirect the packet in the pmf acording to the raw payload received in the kaps*/
    if (lpm_raw_data_enabled) {
        BCM_GPORT_LOCAL_SET(dst_gport, oport);
        rv = dnx_kaps_raw_data_redirect(unit, lpm_payload, 0, 0, dst_gport);
        if (rv != BCM_E_NONE) {
            printf("Error, in function kaps_raw_data_redirect, \n");
            return rv;
        }
    }

    return rv;
}

int
run_with_ports_ipv4_mc_example(
    int unit,
    int iport,
    int oport)
{
    return run_with_ports_ipv4_mc_example_with_ttl(unit,iport,oport,0);
}

/*
 * Adding ports to ingress MC group with encapsulation
 *
 */
int
add_ingress_multicast_forwarding_with_encap (
    int unit,
    int ipmc_index,
    int *ports,
    int nof_ports,
    int vlan)
{
    int rv = BCM_E_NONE;
    int i;
    bcm_if_t encap_id;
    bcm_vlan_port_t vp;
    bcm_multicast_replication_t replications[8];
    int flags = 0;
    int action_id;
    bcm_vlan_action_set_t action;
    bcm_vlan_translate_action_class_t action_class;
    bcm_port_tag_format_class_t tag_format_stag = 2;

    for (i=0; i < nof_ports; i++)
    {
        bcm_vlan_port_t_init(&vp);
        vp.port = ports[i];
        vp.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
        vp.match_vlan = vlan;

        rv = bcm_vlan_port_find(unit, &vp);
        if (rv != BCM_E_NONE) {
            rv = bcm_vlan_port_create(unit, &vp);
            if (rv != BCM_E_NONE) {
                printf("Error, bcm_vlan_port_create\n");
                return rv;
            }
        }

        rv = bcm_multicast_vlan_encap_get(unit, ipmc_index, 0/*not in use in the function*/, vp.vlan_port_id, &encap_id);
        if (rv != BCM_E_NONE) {
            printf("Error, bcm_multicast_vlan_encap_get\n");
            return rv;
        }

        bcm_multicast_replication_t_init(&replications[i]);
        replications[i].encap1 = encap_id;
        BCM_GPORT_LOCAL_SET(replications[i].port, ports[i]);
    }

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    rv = bcm_multicast_set(unit, ipmc_index, flags, nof_ports, replications);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_multicast_set\n");
        return rv;
    }

    return rv;
}

/* Creates a L2 forwarding entry. The entry will be accessed by LEM<FID,DA> Lookup.
 * The entry determines information relevant for MC L2 forwarding given a destination MAC address.
 */
int
create_l2_forwarding_entry_da (
    int unit,
    bcm_mac_t mac,
    int l2mc_group,
    int vlan)
{

    int rv = BCM_E_NONE;
    bcm_l2_addr_t l2_addr;

    /* Configurations relevant for LEM<FID,DA> lookup*/
    bcm_l2_addr_t_init(&l2_addr,mac,vlan);

    l2_addr.flags = BCM_L2_MCAST;
    l2_addr.l2mc_group = l2mc_group;

    rv = bcm_l2_addr_add(unit,&l2_addr);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_l2_addr_add \n");
        return rv;
    }

    return rv;
}

/*
 * This cint is used to test the V4MC with IPMC enable case handling in per RIF configuration
 * and to make sure that the IPMC disable case is forward by L2 MC after deleting RIF.
 *
 * Section 1: Configure IPMC L3 forwarding
 * Section 2: Forward by L2 MC after deleting RIF
*/
int
ipmc_flows_ipmc_per_rif (
    int unit,
    int inP,
    int outP,
    int outP2,
    int outP3,
    int vlan)
{
    int rv = BCM_E_NONE;
    int ipmc_l2_mc_group = 6001;
    int forwarding_ports_2[3] = {outP,outP2,outP3};
    bcm_mac_t mac1 = {0x01, 0x00, 0x5E, 0x02, 0x02, 0x02};
    uint32 mc_flags = 0;

    /*Case 1 - Configure L3 IPMC forwarding */
    rv = basic_ipmc_example_inner(unit, vlan, inP, outP, outP2, 0, 0);
    if (rv != BCM_E_NONE)
    {
        printf("Error, basic_ipmc_example_inner \n");
        return rv;
    }

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        mc_flags = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_WITH_ID);
    } else {
        mc_flags = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_WITH_ID);
    }

    /* Case 2 - L2 MC Group */
    rv = bcm_multicast_create(unit, mc_flags, &ipmc_l2_mc_group);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_multicast_create() with l2mc_group \n");
        return rv;
    }

    /* Case 2 - Set information relevant to MC forwarding: ipmc_index will connect the MC group to LEM: <FID, DA> lookup */
    rv = add_ingress_multicast_forwarding_with_encap(unit, ipmc_l2_mc_group, forwarding_ports_2, 3, vlan);
    if (rv != BCM_E_NONE) {
        printf("Error, add_ingress_multicast_forwarding_with_encap \n");
        return rv;
    }

    /*Case 2 - Add IPMC entry LEM: <FID, DA> */
    rv = create_l2_forwarding_entry_da(unit, mac1, ipmc_l2_mc_group, vlan);
    if (rv != BCM_E_NONE) {
        printf("Error, create_l2_forwarding_entry_da()\n");
        return rv;
    }
    return rv;

}

/*
 * This function sets the RPF traps for the case of MC RPF.
 * These include:
 *    - bcmRxTrapMcUseSipRpfFail - trap for packets that are failing a SIP-based RPF check.
 *    - bcmRxTrapMcExplicitRpfFail - trap for packets that are failing an Explicit RPF check.
 */
int
l3_dnx_ip_mc_rpf_config_traps(
    int unit)
{
    int rv = BCM_E_NONE;
    bcm_rx_trap_config_t config;
    int rpf_mc_sip_trap = 0;
    int rpf_mc_explicit_trap = 0;
    /*
     * RPF types: bcmRxTrapMcUseSipRpfFail - Out-RIF is not equal to In-RIF when MC-RPF-Mode is 'Use-SIP-WITH-ECMP'.
     * bcmRxTrapMcExplicitRpfFail - RPF-Entry. Expected-InRIF is not equal to packet InRIF. Relevant when FEC-Entry.
     */

    /*
     * change dest port for trap
     */
    bcm_rx_trap_config_t_init(&config);
    config.flags |= (BCM_RX_TRAP_UPDATE_DEST);
    config.trap_strength = 7;
    config.dest_port = BCM_GPORT_BLACK_HOLE;

    /*
     * set mc sip-based and explicit RPF to drop packet
     */
    rv = bcm_rx_trap_type_get(unit, 0, bcmRxTrapMcUseSipRpfFail, &rpf_mc_sip_trap);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_rx_trap_type_get rpf_mc_sip_trap \n");
        return rv;
    }
    rv = bcm_rx_trap_set(unit, rpf_mc_sip_trap, &config);
    if (rv != BCM_E_NONE)
    {
        rv = bcm_rx_trap_type_create(unit, 0, bcmRxTrapMcUseSipRpfFail, &rpf_mc_sip_trap);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in trap create, trap bcmRxTrapMcUseSipRpfFail \n");
            return rv;
        }
        rv = bcm_rx_trap_set(unit, rpf_mc_sip_trap, &config);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in trap set rpf_mc_sip_trap\n");
            return rv;
        }
    }
    rv = bcm_rx_trap_type_get(unit, 0, bcmRxTrapMcExplicitRpfFail, &rpf_mc_explicit_trap);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_rx_trap_type_get rpf_mc_explicit_trap \n");
        return rv;
    }
    rv = bcm_rx_trap_set(unit, rpf_mc_explicit_trap, &config);
    if (rv != BCM_E_NONE)
    {
        rv = bcm_rx_trap_type_create(unit, 0, bcmRxTrapMcExplicitRpfFail, &rpf_mc_explicit_trap);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in trap create, trap bcmRxTrapMcExplicitRpfFail \n");
            return rv;
        }
        rv = bcm_rx_trap_set(unit, rpf_mc_explicit_trap, &config);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in trap set rpf_mc_explicit_trap\n");
            return rv;
        }
    }

    return rv;
}

/* The following cint is used to test an explicit MC RPF (pass and fail) and a SIP based MC RPF (pass and fail).*/
int NOF_BASIC_MC_GROUP = 4;
int bcm_l3_ip6_mc_rpf(int unit, int port0, int port1, int port2, int port3) {
    bcm_if_t frwdl3egid;
    bcm_mac_t mac_l3_ingress_add = {0x00, 0x00, 0x00, 0x00, 0x55, 0x00};
    bcm_mac_t mac_l3_engress_add = {0x66, 0x00, 0x00, 0x00, 0x66, 0x00};
    int  vlan_bais_in    = 0x100;
    int  vlan_offset_in  = 0x100;
    int ipmc_index_offset;
    int ipmc_index_upper_bound;
    int explicit_count = 2;
    int sip_count = 2;
    int i, j, found, l3egid, rc, rv, flags, vlan;
    uint8 mac_last_byte[NOF_BASIC_MC_GROUP];
    int exPorts[4] = {port0 , port1, port2 , port3};
    int ipmc_group[NOF_BASIC_MC_GROUP];
    int out_ports[NOF_BASIC_MC_GROUP] = {3, 3, 2, 2};
    bcm_multicast_replication_t replications[NOF_BASIC_MC_GROUP];
    bcm_l3_egress_t l3_eg;
    bcm_if_t l3egid_null;
    l3_ingress_intf ingr_itf;
    int fec[5];
    char *kbp_dev_type = soc_property_get_str(unit, spn_EXT_TCAM_DEV_TYPE);
    int is_kbp = kbp_dev_type ? (!(sal_strcmp("NONE", kbp_dev_type)) ? 0 : 1) : 0;

    ipmc_index_offset = 0;
    ipmc_index_upper_bound = *(dnxc_data_get(unit,  "multicast", "params", "max_ing_mc_groups", NULL));

    /*Different last byte of the MAC address for the interfaces*/
    mac_last_byte[0] = 0x10;
    for (i = 1; i < NOF_BASIC_MC_GROUP; i++) {
        mac_last_byte[i] = mac_last_byte[i - 1] + 0x20;
    }

    /*Create traps to catch the explicit MC RPF and SIP MC RPF fails*/
    rc = l3_dnx_ip_mc_rpf_config_traps(unit);
    if (rc != BCM_E_NONE)
    {
        printf("Error, l3_dnx_ip_mc_rpf_config_traps\n");
        return rc;
    }

    /*create different IPMC groups */
    sal_srand(sal_time());
    for (i = 0; i < NOF_BASIC_MC_GROUP; i++) {  /* picking random values for the mc groups */
        found = 1;
        while (found){ /* verifying that we don't get a previous value */
            found = 0;
            ipmc_group[i] = (sal_rand() % ipmc_index_upper_bound) + ipmc_index_offset;
            for(j = 0 ; j < i - 1 ;j++) {
                if(ipmc_group[i] == ipmc_group[j]) {found = 1;}
            }
        }
    }

    for (i = 0; i < NOF_BASIC_MC_GROUP; i++) {
        vlan = vlan_bais_in + (i * vlan_offset_in);
        mac_l3_ingress_add[5] = mac_last_byte[i];

        rv = bcm_vlan_gport_add(unit, vlan, port0, 0);
        if (rv != BCM_E_NONE) {
            printf("Error, bcm_vlan_gport_add - port(0x%08x) to vlan(%d)\n", port0, vlan);
            return rv;
        }

        rv = intf_eth_rif_create(unit, vlan, mac_l3_ingress_add);
        if (rv != BCM_E_NONE)
        {
             printf("Error, intf_eth_rif_create intf_in\n");
             return rv;
        }

        ingr_itf.intf_id = ingr_itf.vrf = vlan;
        rv = intf_ingress_rif_set(unit, &ingr_itf);
        if (rv != BCM_E_NONE)
        {
             printf("Error, intf_eth_rif_create intf_out\n");
             return rv;
        }

        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_WITH_ID;
        } else {
            flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_WITH_ID;
        }

        /*Create MC groups*/
        rc = bcm_multicast_create(unit, flags, &(ipmc_group[i]));
        if (rc != BCM_E_NONE) {
            printf("Error, bcm_multicast_create \n");
            return rc;
        }

        /*Add ports to each MC group*/
        for (j = 0; j < out_ports[i]; j++) {
            bcm_multicast_replication_t_init(&replications[j]);
            replications[j].port = exPorts[(j + 1) % 4];
            replications[j].encap1 = vlan;
        }

        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
        } else {
            flags = BCM_MULTICAST_INGRESS_GROUP;
        }

        rc = bcm_multicast_set(unit, ipmc_group[i], flags, out_ports[i], replications);
        if (rc != BCM_E_NONE)
        {
            printf("Error, bcm_multicast_set\n");
            return rc;
        }
    }

    bcm_ipmc_addr_t data;

    bcm_ip6_t route = {0xFF,0xFF,0x16,0,0x35,0,0x70,0,0,0,0xdb,0x7,0,0,0,0};
    bcm_ip6_t supported_sip  = {0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16,0x16};
    bcm_ip6_t kbp_fwd_sip  = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x23};
    bcm_ip6_t full_mask  = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

    /*
     * Create two explicit MC RPF FEC - one with an incorrect IN-RIF and one with a correct one.
     * Create two SIP MC RPF FEC
     */

    for(i = 0; i < explicit_count + sip_count; i++) {
        vlan = vlan_bais_in + (i * vlan_offset_in);
        mac_l3_engress_add[5] = mac_last_byte[i];
        bcm_l3_egress_t_init(&l3_eg);
        sal_memcpy(l3_eg.mac_addr, mac_l3_engress_add, 6);
        rc = bcm_l3_egress_create(unit, BCM_L3_EGRESS_ONLY, &l3_eg, &l3egid_null);
        if (rc != BCM_E_NONE)
        {
            printf("Error, create egress object, \n");
            return rc;
        }

        if (i < explicit_count) {
            /*Set the first entry with an incorrect in-rif */
            l3_eg.intf = vlan + (1 - i) * 5;
            l3_eg.flags = BCM_L3_MC_RPF_EXPLICIT;
        } else {
            l3_eg.flags = BCM_L3_MC_RPF_SIP_BASE;
        }

        BCM_GPORT_MCAST_SET(l3_eg.port, ipmc_group[i]);
        l3_eg.encap_id = 0;
        rc = bcm_l3_egress_create(unit, BCM_L3_INGRESS_ONLY, &l3_eg, &fec[i]);
        if (rc != BCM_E_NONE)
        {
            printf("Error, create egress object, unit=%d, \n", unit);
            return rc;
        }

        frwdl3egid = fec[i];

        bcm_ipmc_addr_t_init(&data);
        sal_memcpy(data.mc_ip6_addr, route, 16);
        sal_memcpy(data.mc_ip6_mask, full_mask, 16);
        if (i == explicit_count + sip_count -1) {
            sal_memcpy(data.s_ip6_addr, supported_sip, 16);
        } else {
            sal_memcpy(data.s_ip6_addr, kbp_fwd_sip, 16);
        }
        data.flags = BCM_IPMC_IP6;
        data.vid = data.vrf = vlan;
        data.group = 0;
        data.l3a_intf = frwdl3egid;
        if (is_kbp)
        {
            /* External lookup enabled on JR2 */
            data.flags |= BCM_IPMC_TCAM;
        }

        printf("frwdl3egid 0x%x \n",frwdl3egid);
        rc = bcm_ipmc_add(unit,&data);

        if (rc != BCM_E_NONE) {
             printf("Error, create_forwarding_entry_dip_sip \n");
             return rc;
        }
        route[15] += 0x10;
    }

    mac_l3_engress_add[5] = 11;
    bcm_l3_egress_t_init(&l3_eg);
    sal_memcpy(l3_eg.mac_addr, mac_l3_engress_add, 6);
    rc = bcm_l3_egress_create(unit, BCM_L3_EGRESS_ONLY, &l3_eg, &l3egid_null);
    if (rc != BCM_E_NONE)
    {
        printf("Error, create egress object, \n");
        return rc;
    }

    /*Creating a FEC to have a payload for the SIP check (won't be used for actual forwarding)*/
    l3_eg.flags = BCM_L3_MC_RPF_SIP_BASE;
    l3_eg.intf = vlan_bais_in + (3 * vlan_offset_in);
    l3_eg.encap_id = 0;
    l3_eg.port = port1;
    rc = bcm_l3_egress_create(unit, BCM_L3_INGRESS_ONLY, &l3_eg, &fec[4]);
    if (rc != BCM_E_NONE)
    {
        printf("Error, create egress object, unit=%d, \n", unit);
        return rc;
    }

    frwdl3egid = fec[4];

    bcm_l3_route_t l3route;
    bcm_l3_route_t_init(&l3route);
    l3route.l3a_flags =  BCM_L3_IP6;
    sal_memcpy(l3route.l3a_ip6_net, supported_sip, 16);
    sal_memcpy(l3route.l3a_ip6_mask, full_mask, 16);
    l3route.l3a_vrf = vlan_bais_in + (3 * vlan_offset_in);
    if (is_jericho2_kbp_ipv6_split_rpf_enabled(unit))
    {
        /* External lookup enabled on JR2 */
        l3route.l3a_flags2 |= BCM_L3_FLAGS2_RPF_ONLY;
    }
    /* dest is FEC + OutLif */
    l3route.l3a_intf = frwdl3egid;
    rc = bcm_l3_route_add(unit, &l3route);
    if (rc != BCM_E_NONE) {
        printf ("bcm_l3_host_add failed: %d \n", rc);
        return rc;
    }

    return rc;
}


int
ipv4_mc_to_trap_example(
    int unit,
    int in_port,
    int out_port)
{
    bcm_error_t rv = BCM_E_NONE;
    int ingress_intf;

    bcm_ip_t mc_ip = 0xE0E0E001; /* 224.224.224.1 */
    /* compatible MAC 01:00:5E:60:e0:01 */
    bcm_ip_t src_ip = 0x0; /* masked */
    int ipmc_index = 6000;
    int dest_local_port_id = 13;
    int source_local_port_id = 13;
    bcm_mac_t mac_l3_ingress = {0x00, 0x00, 0x00, 0x00, 0xab, 0x1d};

    int egr_flags = 0;
    bcm_multicast_t mc_id;
    bcm_gport_t mc_gport_drop; /*This mc id traps to BCM_GPORT_BLACK_HOLE*/
    int nof_entries = 6;
    int idx;

    bcm_l3_egress_t l3eg;
    int fec[10] = {0x0};
    int eg_itf_index = 0;

    int encap_id[10]={0x0};
    int vrf = 0;
    int vlan;

    int vlan_l = 10;
    bcm_mac_t mac_address_l  = {0x00, 0x00, 0x00, 0x02, 0x00, 0x01};  /* my-MAC */
    int ing_intf_l;
    bcm_gport_t mc_gport_2_cpu; /*This mc id traps to BCM_GPORT_LOCAL_CPU*/

    int vlan_r = 20;
    bcm_mac_t mac_address_r  = {0x00, 0x00, 0x00, 0x02, 0x00, 0x02};  /* my-MAC */
    int ing_intf_r;

    int trap_id_handle_drop, trap_id_handle_cpu;
    bcm_rx_trap_config_t config_trap_drop, config_trap_cpu;
    int trap_strength;

    l3_ingress_intf ingr_itf;
    l3_ingress_intf_init(&ingr_itf);


    vrf = vlan_l;

    /* 1. configure two traps: dest port of one trap is drop, dest of another trap is cpu */
    bcm_rx_trap_type_create(unit,0/*flags*/,bcmRxTrapUserDefine,&trap_id_handle_drop);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_create - bcmRxTrapUserDefine\n");
        return rv;
    }
    bcm_rx_trap_type_create(unit,0/*flags*/,bcmRxTrapUserDefine,&trap_id_handle_cpu);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_create - bcmRxTrapUserDefine\n");
        return rv;
    }

    bcm_rx_trap_config_t_init(&config_trap_drop);
    config_trap_drop.flags |= (BCM_RX_TRAP_UPDATE_DEST);
    config_trap_drop.trap_strength = 0; /*FOR USER DEFINE set as part of destination */
    config_trap_drop.dest_port = BCM_GPORT_BLACK_HOLE;
    rv = bcm_rx_trap_set(unit,trap_id_handle_drop,&config_trap_drop);
    if (rv != BCM_E_NONE) {
        printf("Error, in bcm_rx_trap_set\n");
    }

    bcm_rx_trap_config_t_init(&config_trap_cpu);
    config_trap_cpu.flags |= (BCM_RX_TRAP_UPDATE_DEST);
    config_trap_cpu.trap_strength = 0; /*FOR USER DEFINE set as part of destination */
    BCM_GPORT_LOCAL_SET(config_trap_cpu.dest_port, 0);
    rv = bcm_rx_trap_set(unit,trap_id_handle_cpu,&config_trap_cpu);
    if (rv != BCM_E_NONE) {
        printf("Error, in bcm_rx_trap_set\n");

    }

    /* Associate the traps with the gports */
    trap_strength = 15;
    BCM_GPORT_TRAP_SET(mc_gport_drop, trap_id_handle_drop, trap_strength, 0);
    BCM_GPORT_TRAP_SET(mc_gport_2_cpu, trap_id_handle_cpu, trap_strength, 0);


    /* 2. Set In-Port to Eth-RIF */
    rv = in_port_intf_set(unit, in_port, vlan_l);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in_port_intf_set intf_in\n");
        return rv;
    }

    /* 3. Set Out-Port default properties */
    rv = out_port_set(unit, out_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, out_port_intf_set\n");
        return rv;
    }

    /* 4. Create IN-RIF and set its properties */
    rv = intf_eth_rif_create(unit, vlan_l, mac_address_l);
    ing_intf_l = vlan_l;
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_eth_rif_create intf_in\n");
        return rv;
    }

    rv = intf_eth_rif_create(unit, vlan_r, mac_address_r);
    ing_intf_r = vlan_r;
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_eth_rif_create intf_in\n");
        return rv;
    }

    /* 5. Set ingress interface */
    ingr_itf.intf_id = ing_intf_l;
    ingr_itf.vrf = vrf;
    rv = intf_ingress_rif_set(unit, &ingr_itf);
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_eth_rif_create intf_out\n");
        return rv;
    }

    eg_itf_index = 2;

    /* 6. Create the IP MC entry */
    vlan = vlan_l;
    for(idx = 0; idx < eg_itf_index; ++idx) {
        rv = add_ipv4_ipmc_to_port(unit, mc_ip, 0xffffffff, src_ip, 0x0, vlan, vrf, ((idx==0)?mc_gport_drop:mc_gport_2_cpu));
        if (rv != BCM_E_NONE)
        {
            return rv;
        }
        mc_ip++;

    }

    return rv;
}




/*
 * MC routing functionality with bridge fallback configuration is verified.
 * If there is not a successful IPMC lookup and VSI indicates bridge fallback is enabled, packet will be flooded.
 *
 * Test Scenario
 *
 * ./bcm.user
 * config add tm_port_header_type_in_50=INJECTED
 * config add tm_port_header_type_out_50=ETH
 * config add ucode_port_50=RCY.10:core_0.50
 *
 * #if device has two cores, include the following properties as well:
 * config add tm_port_header_type_in_51=INJECTED
 * config add tm_port_header_type_out_51=ETH
 * config add ucode_port_51=RCY.11:core_1.51
 *
 * tr 141
 * cd ../../../../regress/bcm
 * cint ../../src/examples/dnx/utility/cint_dnx_utils_global.c
 * cint ../../src/examples/dnx/utility/cint_dnx_util_rch.c
 * cint ../../src/examples/dnx/field/cint_field_bridge_fallback.c
 * cint ../../src/examples/dnx/utility/cint_dnx_utils_vlan.c
 * cint ../../src/examples/dnx/cint_dnx_ip_route_basic.c
 * cint ../../src/examples/dnx/cint_dnx_ipmc_route_basic.c
 * cint ../../src/examples/dnx/cint_dnx_ipmc_route_examples.c
 * cint
 * l3_ipmc_bridge_fallback_example(0,11,12,200,201,202,203,50,51);
 * exit;
 *
 * # The following packet will hit VSI with bridge fallback configuration. Packet will be flooded.
 * tx 1 psrc=200 data=0x01005e0202020000070001009100000b080045000035000000006400b343c0800101e0020202000102030405060708090a0b0c0d0e0f
 *
 * Expected out packets:
 * on port 201: 0x01005E0202020000070001009100000B080045000035000000006400B343C0800101E0020202000102030405060708090A0B
 * on port 202: 0x01005E0202020000070001009100000B080045000035000000006400B343C0800101E0020202000102030405060708090A0B
 * on port 203: 0x01005E0202020000070001009100000B080045000035000000006400B343C0800101E0020202000102030405060708090A0B
 */
int
l3_ipmc_bridge_fallback_example(
    int unit,
    int vid_in_drop,
    int vid_in_flood,
    int in_port,
    int out_port1,
    int out_port2,
    int out_port3,
    int recycle_port_core_0,
    int recycle_port_core_1)
{
    int rv = BCM_E_NONE;
    int nof_cores = *(dnxc_data_get(unit, "device", "general", "nof_cores", NULL));
    bcm_port_flood_group_t flood_groups;
    cint_ipmc_info.vrf = 5;
    l3_ingress_intf ingr_itf;
    int idx;

    cint_ipmc_info.in_port = in_port;
    int out_ports[4];
    out_ports[0] = out_port1;
    out_ports[1] = out_port2;
    out_ports[2] = out_port3;
    out_ports[3] = in_port;


    rv = bcm_vlan_create(unit, vid_in_drop);
    if (rv != BCM_E_NONE)
    {
        printf("Error, create VLAN %d\n", vid_in_drop);
        return rv;
    }
    rv = bcm_vlan_create(unit, vid_in_flood);
    if (rv != BCM_E_NONE)
    {
        printf("Error, create VLAN %d\n", vid_in_flood);
        return rv;
    }

    bcm_vlan_port_t vlan_port;
    { /** VSI configuration to drop packet */
        bcm_vlan_port_t_init(&vlan_port);
        vlan_port.port = cint_ipmc_info.in_port;
        vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
        vlan_port.vsi = vid_in_drop;
        vlan_port.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
        vlan_port.match_vlan = vid_in_drop;
        rv = bcm_vlan_port_create(unit, vlan_port);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_vlan_port_create\n");
            return rv;
        }
        printf("port = %d, in_lif = 0x%08X\n", vlan_port.port, vlan_port.vlan_port_id);
        rv = bcm_vlan_gport_add(unit, vid_in_drop, cint_ipmc_info.in_port, 0);
        if (rv != BCM_E_NONE)
        {
            printf("Error in bcm_vlan_gport_add \n");
            return rv;
        }
    }
    { /** VSI configuration to flood packet */
        bcm_vlan_port_t_init(&vlan_port);
        vlan_port.port = cint_ipmc_info.in_port;
        vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
        vlan_port.vsi = vid_in_flood;
        vlan_port.flags = BCM_VLAN_PORT_CREATE_INGRESS_ONLY;
        vlan_port.match_vlan = vid_in_flood;
        vlan_port.ingress_network_group_id = 0;
        rv = bcm_vlan_port_create(unit, vlan_port);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_vlan_port_create\n");
            return rv;
        }
        printf("port = %d, in_lif = 0x%08X\n", vlan_port.port, vlan_port.vlan_port_id);
        rv = bcm_vlan_gport_add(unit, vid_in_flood, cint_ipmc_info.in_port, 0);
        if (rv != BCM_E_NONE)
        {
            printf("Error in bcm_vlan_gport_add \n");
            return rv;
        }
    }

    for (idx = 0; idx < 4; idx ++)
    {
        if (idx == 2)
        {
            continue;
        }
        rv = out_port_set(unit, out_ports[idx]);
        if (rv != BCM_E_NONE)
        {
            printf("Error, out_port_set vm_port \n");
            return rv;
        }
    }

    bcm_gport_t outlif;
    bcm_vlan_port_t_init(&vlan_port);
    /* EEDB */
    vlan_port.vsi = 0;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vlan_port.match_vlan = 100;
    vlan_port.port = out_ports[2];
    vlan_port.ingress_network_group_id = 0;
    vlan_port.egress_network_group_id = 3;

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE) {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }
    outlif=vlan_port.vlan_port_id;
    /*
     * 2. Create ETH-RIF and set its properties
     */
    rv = intf_eth_rif_create(unit, vid_in_drop, cint_ipmc_info.intf_in_mac_address);
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_eth_rif_create intf_in\n");
        return rv;
    }
    cint_ipmc_info.intf_in_mac_address[5]++;
    rv = intf_eth_rif_create(unit, vid_in_flood, cint_ipmc_info.intf_in_mac_address);
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_eth_rif_create intf_in\n");
        return rv;
    }

    /*
     * 3. Set Incoming ETH-RIF properties
     */
    l3_ingress_intf_init(&ingr_itf);
    ingr_itf.intf_id = vid_in_drop;
    ingr_itf.vrf = cint_ipmc_info.vrf;
    rv = intf_ingress_rif_set(unit, &ingr_itf);
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_ingress_rif_set vid_in_drop\n");
        return rv;
    }
    l3_ingress_intf_init(&ingr_itf);
    ingr_itf.intf_id = vid_in_flood;
    ingr_itf.vrf = cint_ipmc_info.vrf + 1;
    ingr_itf.flags |= BCM_L3_INGRESS_IPMC_BRIDGE_FALLBACK;
    rv = intf_ingress_rif_set(unit, &ingr_itf);
    if (rv != BCM_E_NONE)
    {
        printf("Error, intf_ingress_rif_set vid_in_flood\n");
        return rv;
    }

    /*
     * 5. Create a multicast group
     */
    int flags;
    cint_ipmc_info.mc_group = vid_in_flood;
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_WITH_ID;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_WITH_ID;
    }
    rv = bcm_multicast_create(unit, flags, &cint_ipmc_info.mc_group);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_multicast_create \n");
        return rv;
    }

    bcm_multicast_replication_t replications[4];
    set_multicast_replication(&replications[0], out_ports[0], -1);
    set_multicast_replication(&replications[1], out_ports[1], -1);
    set_multicast_replication(&replications[2], out_ports[2], (outlif & 0x3fffff));
    /** Add encap_id which is equal to the in_lif so that in_lif can equal out_lif */
    set_multicast_replication(&replications[3], out_ports[3], 0);
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    rv = bcm_multicast_add(unit, cint_ipmc_info.mc_group, flags, 4, replications);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_multicast_ingress_add\n");
        return rv;
    }

    int system_headers_mode = (*dnxc_data_get(unit, "headers", "system_headers", "system_headers_mode", NULL));
    if ((system_headers_mode == 0) && (*dnxc_data_get(unit, "fabric", "general", "blocks_exist", NULL)))
    {
        int nof_cores = *dnxc_data_get(unit, "device", "general", "nof_cores", NULL);
        bcm_module_t mreps[2];
        mreps[0] = 0;
        mreps[1] = 1; /* Ignore it in single core devices*/
        rv = bcm_fabric_multicast_set(unit, cint_ipmc_info.mc_group, 0, nof_cores, mreps);
        if (rv != BCM_E_NONE) {
            printf("Error, bcm_fabric_multicast_set \n");
            return rv;
        }
    }


    if (*dnxc_data_get(unit, "l3", "feature", "mc_bridge_fallback", NULL)) {
           /*
           use field processor to perform bridge fallback:
           for ipvx routing packets with no hit in forwarding, and for vsi profile:
           fwd to recycle port and build recycle header, update vsi and pop lif
           */
        rv = bcm_port_control_set(unit, recycle_port_core_0, bcmPortControlRecycleApp, bcmPortControlRecycleAppBridgeFallback);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_port_control_set with type bcmPortControlRecycleApp\n");
            return rv;
        }
        /** Set port class in order for PMF to crop RCH ad IRPP */
        rv = bcm_port_class_set(unit,recycle_port_core_0,bcmPortClassFieldIngressPMF3TrafficManagementPortCs,4);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_port_class_set \n");
            return rv;
        }
        if (nof_cores > 1)
        {
            rv = bcm_port_control_set(unit, recycle_port_core_1, bcmPortControlRecycleApp, bcmPortControlRecycleAppBridgeFallback);
            if (rv != BCM_E_NONE)
            {
                printf("Error, bcm_port_control_set with type bcmPortControlRecycleApp\n");
                return rv;
            }
            /** Set port class in order for PMF to crop RCH ad IRPP */
            rv = bcm_port_class_set(unit,recycle_port_core_1,bcmPortClassFieldIngressPMF3TrafficManagementPortCs,4);
            if (rv != BCM_E_NONE)
            {
                printf("Error, bcm_port_class_set \n");
                return rv;
            }
        }

        rv = bcm_port_control_set(unit, in_port, bcmPortControlSystemPortInjectedMap, 1);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_port_control_set with type bcmPortControlSystemPortInjectedMap\n");
            return rv;
        }


        /* configure vsi profile for vsis */
        int vsi_profile = 1;
        rv = vlan__control_vlan_vsi_profile_set(unit, vid_in_flood, vsi_profile);
        if (rv != BCM_E_NONE)
        {
            printf("Error, vlan__control_vlan_vsi_profile_set\n");
            return rv;
        }
        rv = vlan__control_vlan_vsi_profile_set(unit, vid_in_drop, vsi_profile);
        if (rv != BCM_E_NONE)
        {
            printf("Error, vlan__control_vlan_vsi_profile_set\n");
            return rv;
        }

        rv = cint_field_bridge_fallback_main(unit);
        if (rv != BCM_E_NONE)
        {
            printf("Error, cint_field_bridge_fallback_main\n");
            return rv;
        }

        rv = cint_field_bridge_fallback_entry_add(unit,
            nof_cores, recycle_port_core_0, recycle_port_core_1, vsi_profile);
        if (rv != BCM_E_NONE)
        {
            printf("Error, cint_field_bridge_fallback_entry_add\n");
            return rv;
        }
    }

    return rv;
}

/** A destroy function for the field configuration used for bridge fallback. */
int
l3_ipmc_bridge_fallback_field_destroy(
    int unit,
    int nof_cores)
{
    int vsi_profile = 1;
    int rv = BCM_E_NONE;
    if (*dnxc_data_get(unit, "l3", "feature", "mc_bridge_fallback", NULL)) {
        rv = cint_field_bridge_fallback_entry_destroy(unit, nof_cores, vsi_profile);
        if (rv != BCM_E_NONE)
        {
            printf("Error, cint_field_bridge_fallback_entry_add\n");
            return rv;
        }
        rv = cint_field_bridge_fallback_main_destroy(unit);
        if (rv != BCM_E_NONE)
        {
            printf("Error, cint_field_bridge_fallback_main\n");
            return rv;
        }
    }
    return rv;
}

/**
 * A routing example that presents the way in which in the case of a compatible multicast packet and no created RIF,
 * the packet can be forwarded based on an entry in the BRIDGE IPMC SVL tables.
 *
 * The functionality of the bcmSwitchL3McastL2 and bcmSwitchL3IP6McastL2 switch control is used to force updating the L2 Mc fwd type to IPV4MC bridge.
 */
int
l3_ipmc_bridge_default_fwd_type_example(
    int unit,
    int eth_rif,
    int in_port,
    int out_port1,
    int out_port2,
    int out_port3)
{
    int rv = BCM_E_NONE;
    int mc_id;
    int idx;
    int ipmc_group[2] = {1000, 1001};
    int intf_out = 150;
    int fwd_id = eth_rif;
    int nof_mc_groups = 2;
    uint32 sip_addr = 0xC0800101;
    uint32 sip_mask = 0xFFFF0000;
    uint32 dip_addr = 0xE0020202;
    uint32 dip_mask = 0xFFFFFFFF;
    bcm_mac_t dmac = {0x01, 0x00, 0x5E, 0x02, 0x02, 0x04};
    bcm_mac_t dmac2 = {0x33, 0x33, 0x00, 0x00, 0x11, 0x13};
    bcm_ip6_t dip_v6_addr = {0xFF, 0xFF, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x11, 0x11};
    bcm_ip6_t dip_v6_mask = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    bcm_ip6_t sip_v6_addr = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11};
    bcm_ip6_t sip_v6_mask = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0, 0};
    bcm_l2_addr_t l2_addr;
    int compressed_val = 0x552;
    int ports[2][2] = {{out_port1, out_port2}, {out_port1, out_port3}};
    uint32 flags, flags_add;
    bcm_multicast_replication_t replications[cint_ipmc_info.nof_replications];
    l3_ingress_intf ingr_itf;

    l3_ingress_intf_init(&ingr_itf);

    rv = bcm_switch_control_set(unit, bcmSwitchL3McastL2, 1);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_switch_control_set \n");
        return rv;
    }
    rv = bcm_switch_control_set(unit, bcmSwitchL3IP6McastL2, 1);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_switch_control_set \n");
        return rv;
    }
    /* 1. Set In-Port to Eth-RIF */
    rv = in_port_intf_set(unit, in_port, eth_rif);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in_port_intf_set intf_in\n");
        return rv;
    }

    /* 2. Set Out-Port default properties */
    rv = out_port_set(unit, out_port1);
    if (rv != BCM_E_NONE)
    {
        printf("Error, out_port_intf_set\n");
        return rv;
    }
    rv = out_port_set(unit, out_port2);
    if (rv != BCM_E_NONE)
    {
        printf("Error, out_port_intf_set\n");
        return rv;
    }
    rv = out_port_set(unit, out_port3);
    if (rv != BCM_E_NONE)
    {
        printf("Error, out_port_intf_set\n");
        return rv;
    }

    rv = bcm_vlan_create(unit, eth_rif);
    if (rv != BCM_E_NONE)
    {
        printf("Error, create VLAN %d\n", eth_rif);
        return rv;
    }

    for (mc_id = 0; mc_id < nof_mc_groups; mc_id++)
    {

        for (idx = 0; idx < cint_ipmc_info.nof_replications; idx++)
        {
            /*
             * 4.2 Set the replication.
             */
            set_multicast_replication(&replications[idx], ports[mc_id][idx], -1);

            /*
             * 4.3 Set some changes for the next replication.
             */
            intf_out++;
            cint_ipmc_info.intf_out_mac_address[5]++;
        }
        /*
         * 5. Create a multicast group
         */
        if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
            flags = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC | BCM_MULTICAST_WITH_ID);
            flags_add = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC);
        } else {
            flags = (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_WITH_ID);
            flags_add = BCM_MULTICAST_INGRESS_GROUP;
        }
        rv = bcm_multicast_create(unit, flags, &ipmc_group[mc_id]);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_multicast_create %d\n",idx);
            return rv;
        }
        rv = bcm_multicast_add(unit, ipmc_group[mc_id], flags_add, cint_ipmc_info.nof_replications, replications);
        if (rv != BCM_E_NONE)
        {
            printf("Error, bcm_multicast_ingress_add\n");
            return rv;
        }
        rv = add_ipv4_ipmc_bridge(unit, dip_addr, dip_mask, sip_addr, sip_mask, fwd_id, 0, ipmc_group[mc_id], 0, 0);
        if (rv != BCM_E_NONE)
        {
            printf("Error, add_ipv4_ipmc_bridge\n");
            return rv;
        }
        rv = add_ipv6_ipmc_bridge(unit, dip_v6_addr, dip_v6_mask, sip_v6_addr, sip_v6_mask, 0, fwd_id, compressed_val, ipmc_group[mc_id], 0, 0);
        if (rv != BCM_E_NONE)
        {
            printf("Error, add_ipv6_ipmc_bridge\n");
            return rv;
        }
        dip_addr ++;
        dip_v6_addr[15]++;
        if (!(*(dnxc_data_get(unit, "l3", "fwd", "ipmc_config_cmprs_vrf_group", NULL))))
        {
            compressed_val = 0;
        }
        else
        {
            compressed_val ++;
        }
        sip_v6_mask[15] = 0;
        sip_mask = 0;
    }
    rv = bcm_switch_control_set(unit, bcmSwitchL3McastL2, 0);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_switch_control_set \n");
        return rv;
    }
    rv = bcm_switch_control_set(unit, bcmSwitchL3IP6McastL2, 0);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_switch_control_set \n");
        return rv;
    }
    eth_rif ++;
    /* Set In-Port to Eth-RIF */
    rv = in_port_intf_set(unit, out_port3, eth_rif);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in_port_intf_set intf_in\n");
        return rv;
    }
    rv = bcm_vlan_create(unit, eth_rif);
    if (rv != BCM_E_NONE)
    {
        printf("Error, create VLAN %d\n", eth_rif);
        return rv;
    }
    bcm_l2_addr_t_init(&l2_addr, dmac, eth_rif);
    l2_addr.l2mc_group = ipmc_group[0];
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    rv = bcm_l2_addr_add(unit, &l2_addr);
    if (rv != BCM_E_NONE) {
        printf("bcm_l2_addr_add failed \n");
        return rv;
    }
    bcm_l2_addr_t_init(&l2_addr, dmac2, eth_rif);
    l2_addr.l2mc_group = ipmc_group[0];
    l2_addr.flags = BCM_L2_STATIC | BCM_L2_MCAST;
    rv = bcm_l2_addr_add(unit, &l2_addr);
    if (rv != BCM_E_NONE) {
        printf("bcm_l2_addr_add failed \n");
        return rv;
    }

    return rv;
}