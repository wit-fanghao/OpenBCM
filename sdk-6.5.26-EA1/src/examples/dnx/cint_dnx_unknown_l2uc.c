/* $Id: cint_dnx_unknown_l2uc.c,
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
*/
/* **************************************************************************************************************************************************
 *                                                                                                                                                  *
 *                                                                                                                                                  * 
 * This CINT demonstrates basic l2 bridging with IVE and EVE actions for canonical format untag                                                     * 
 *                                                                                                                                                  *
 * The cint creates a basic L2 switching scheme with following Logical Interfaces(LIF)                                                              *
 *                                                                                                                                                  *
 * - Ports used:                                                                                                                                    *
 *    Port_1 : To transmit/receive UnTAG packet                                                                                                     *
 *    Port_3 : To transmit/receive DTAG packet {(TPID=0x8100,SVID=100),(TPID=0x9100, CVID=333)}                                                     *
 *    Port_4 : To transmit/receive STAG packet {TPID=0x8100,SVID=100}                                                                               *
 *    Port_2 : To transmit/receive STAG packet  {TPID=0x9100, SVID=100}                                                                             *
 * - VLAN_DOMAINs and Ports are 1:1 mapped                                                                                                          *
 * - InLifs are created on Each Tx port as:                                                                                                         *
 *     inlif_Port_1_untag = Port_1.Default_Lif                                                                                                      *
 *     inlif_Port_3_dtag  = ISEM lookup on {Port_3,SVID=100,CVID=333}                                                                               *
 *     inlif_Port_4_stag  = ISEM lookup on {Port_4,SVID=100}                                                                                        *
 * - OutLif is created on Port_2 as:                                                                                                                *
 *     outlif_Port_2_stag = EEDB based i.e. using criteria MATCH_PORT_VLAN                                                                          *
 * - Canonical format is NOOP so following is IVE{outer_tag_action,inner_tag_action} command is applied on each InLif:                             *
 *     inlif_Port_1_untag.IVE = {bcmvlanactionNone,bcmvlanactionNone}                                                                               *
 *     inlif_Port_3_dtag.IVE = {bcmvlanactionNone,bcmvlanactionNone}                                                                              *
 *     inlif_Port_4_stag.IVE = {bcmvlanactionNone,bcmvlanactionNone}                                                                              *
 * - All Lifs are part of VSI=100                                                                                                                   *
 * - FWD lookup :                                                                                                                                   *
 *     The packets are forwarded to the egress using MACT (VSI=100 and MAC_DA) with destination as Port_2 with lif_Port_2_stag                      *
 *                                                                                                                                                  *
 * - EVE command :                                                                                                                                  *
 *      outlif_Port_2_stag.EVE={bcmvlanactionNone,bcmvlanactionNone}                                                                                *
 ************************************************************************************************************************************************** */

/* **************************************************************************************************
  --------------          Global Variables Definition and Initialization  START     -----------------
 **************************************************************************************************** */


int NUM_OF_PORTS = 4;
int NUM_OF_LIF_PER_PORT = 1;

/* vlan edit profiles */
enum vlan_edit_profiles {
    ing_vlan_edit_profile_untag = 1,
    ing_vlan_edit_profile_stag,
    ing_vlan_edit_profile_ctag,
    ing_vlan_edit_profile_dtag,
    egr_vlan_edit_profile_untag,
    egr_vlan_edit_profile_stag,
    egr_vlan_edit_profile_ctag,
    egr_vlan_edit_profile_dtag
};

struct global_tpids_s
{
    uint16 tpid0;               /* tpid0 */
    uint16 tpid1;               /* tpid1 */
    uint16 tpid2;               /* tpid2 */
    uint16 tpid3;               /* tpid3 */
    uint16 tpid4;               /* tpid4 */
    uint16 tpid5;               /* tpid5 */
    uint16 tpid6;               /* tpid6 */
};

/*  Main Struct  */
struct unknown_l2uc_s
{
    bcm_gport_t ports[NUM_OF_PORTS];
    int Port_1_untag;
    int Port_2_stag;
    int Port_3_dtag;
    int Port_4_stag;
    bcm_vlan_t vsi;
    bcm_mac_t d_mac;
    bcm_mac_t bpdu_mac;
    global_tpids_s tpids;
    bcm_gport_t inlif[NUM_OF_PORTS][NUM_OF_LIF_PER_PORT];
    bcm_gport_t outlif[NUM_OF_PORTS][NUM_OF_LIF_PER_PORT];
    bcm_vlan_t outer_vid;
    bcm_vlan_t inner_vid;
    bcm_multicast_t uuc_mcid;
    int unknown_da_profile_destination;
    int arp_trap_id;
    int my_arp_trap_id;
    int arp_fwd_strength;
    int my_arp_fwd_strength;
    int arp_trap_profile;
    int l2cp_trap_id;
    int l2cp_fwd_strength;
    int l2cp_trap_profile;
    /* vid for tag actions */
    int new_outer_vid;
    int egr_new_outer_vid;
    int new_inner_vid;
    int egr_new_inner_vid;
    /* tag formats */
    int tag_format_untag;
    int tag_format_stag;
    int tag_format_ctag;
    int tag_format_dtag;
};

/* Initialization of Main struct */
unknown_l2uc_s g_unknown_l2uc = {
    /*
     * ports:
     */
    {0, 0, 0, 0},
    /*
     * Port_1_untag
     */
    0,
    /*
     * Port_2_stag
     */
    1,
    /*
     * Port_3_dtag
     */
    2,
    /*
     * Port_4_stag
     */
    3,
    /*
     * vsi
     */
    100,
    /*
     * d_mac
     */
    {0x00, 0x00, 0x00, 0x00, 0x12, 0x34},
    /*
     * bpdu_mac
     */
    {0x01, 0x80, 0xc2, 0x00, 0x00, 0x00},
     /*TPIDS*/ {0x8100, 0x9100, 0x88a8, 0x88e7, 0xaaaa, 0xbbbb, 0x5555},
    /*
     * InLifs 
     */
    {
     {0, 0},
     {0, 0},
     {0, 0},
     {0, 0}
     },
    /*
     * OutLifs 
     */
    {
     {0, 0},
     {0, 0},
     {0, 0},
     {0, 0}
     },
    /*
     * outer_vid 
     */
    100,
    /*
     * inner_vid
     */
    333,
    /*
     * MCID for Unknown_UC 
     */
    100,
    /*
     * unknown_da_profile_destination
     */
    0,
    /*
     * arp_trap_id
     */
    0,
    /*
     * my_arp_trap_id
     */
    0,
    /*
     * arp_fwd_strength
     */
    7,
    /*
     * my_arp_fwd_strength
     */
    6,
    /*
     * arp_trap_profile
     */
    3,
    /*
     * l2cp_trap_id
     */
    259,
    /*
     * l2cp_fwd_strength 
     */
    7,
    /*
     * l2cp_trap_profile
     */
    3,
    /*
     * new_outer_vid
     */
    1024,
    /*
     * egr_new_outer_vid
     */
    100,
    /*
     * new_inner_vid
     */
    1500,
    /*
     * egr_new_inner_vid
     */
    1500,
    /*
     * tag_format_untag
     */
    0,
    /*
     * tag_format_stag
     */
    4,
    /*
     * tag_format_ctag
     */
    8,
    /*
     * tag_format_dtag
     */
    16
};

/* **************************************************************************************************
  --------------          Global  Variables Definitions and Initialization  END       ---------------
**************************************************************************************************** */

/* Initialization of main struct
 * Function allows to re-write default values
 *
 * INPUT:
 *   param: new values for g_vlan_translate_tpid_modify
 */
int
unknown_l2uc__l2_basic_bridge_modify_init(
    int unit,
    unknown_l2uc_s * param)
{
    int rv;

    if (param != NULL)
    {
        sal_memcpy(&g_unknown_l2uc, param, sizeof(g_unknown_l2uc));
    }

    return BCM_E_NONE;
}

/*
 * Return l2_basic_bridge information
 */
void
unknown_l2uc__l2_basic_bridge_modify_struct_get(
    int unit,
    unknown_l2uc_s * param)
{

    sal_memcpy(param, &g_unknown_l2uc.ports, sizeof(g_unknown_l2uc));

    return;
}

/* This function runs the main test configuration function with given ports
 *
 * INPUT: unit
 *        Port1
 *        Port2
 *        Port3
 *        Port4
 */
int
unknown_l2uc__main_config__start_run(
    int unit,
    int Port_1,
    int Port_2,
    int Port_3,
    int Port_4)
{

    unknown_l2uc_s param;

    unknown_l2uc__l2_basic_bridge_modify_struct_get(unit, &param);

    param.ports[0] = Port_1;
    param.ports[1] = Port_2;
    param.ports[2] = Port_3;
    param.ports[3] = Port_4;

    return unknown_l2uc__l2_basic_bridge_run(unit, &param);
}

/*
  */
int
unknown_l2uc__l2_basic_bridge_run(
    int unit,
    unknown_l2uc_s * param)
{
    int rv;
    int i;

    rv = unknown_l2uc__l2_basic_bridge_modify_init(unit, param);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in unknown_l2uc__l2_basic_bridge_modify_init\n");
        return rv;
    }

    /*
     * Set vlan domain:
     */
    for (i = 0; i < NUM_OF_PORTS; i++)
    {
        rv = bcm_port_class_set(unit, g_unknown_l2uc.ports[i], bcmPortClassId, g_unknown_l2uc.ports[i]);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_class_set(port = %d)\n", g_unknown_l2uc.ports[i]);
            return rv;
        }
    }

    /*
     * Make Port_1, Port_2, Port_3 and Port_4 as VLAN Members
     */
    for (i = 0; i < NUM_OF_PORTS; i++)
    {
        rv = bcm_port_class_set(unit, g_unknown_l2uc.ports[i], bcmPortClassVlanMember, g_unknown_l2uc.ports[i]);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_class_set(port = %d)\n", g_unknown_l2uc.ports[i]);
            return rv;
        }
    }

    /*
     * Set TPIDs
     */
    rv = unknown_l2uc__tpids_assign(unit);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in unknown_l2uc__tpids_assign\n");
        return rv;
    }

    /*
     * Create VSI:
     */
    printf("bcm_vlan_create :");
    rv = bcm_vlan_create(unit, g_unknown_l2uc.vsi);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_create(vis=%d)\n", g_unknown_l2uc.vsi);
        return rv;
    }

    /*
     * Set Group_id for UUC, MC and BC packets
     */

    bcm_port_control_t flood_type;
    bcm_vlan_control_vlan_t control;
    bcm_vlan_control_vlan_t_init(&control);

    bcm_port_flood_group_t flood_groups;
    bcm_gport_t flood_destination;
    bcm_port_flood_group_t_init(&flood_groups);
    BCM_GPORT_MCAST_SET(flood_destination, g_unknown_l2uc.unknown_da_profile_destination);
    flood_groups.unknown_unicast_group = flood_destination;
    rv = bcm_port_flood_group_set(unit, g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag], 0, &flood_groups);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_control_set/bcm_port_flood_group_set");
        return rv;
    }

    control.unknown_unicast_group = g_unknown_l2uc.uuc_mcid;
    control.broadcast_group = g_unknown_l2uc.uuc_mcid;
    control.unknown_multicast_group = g_unknown_l2uc.uuc_mcid;
    control.forwarding_vlan = g_unknown_l2uc.vsi;

    rv = bcm_vlan_control_vlan_set(unit, g_unknown_l2uc.vsi, control);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_control_vlan_set(vis=%d)\n", g_unknown_l2uc.vsi);
        return rv;
    }

    g_unknown_l2uc.uuc_mcid = g_unknown_l2uc.unknown_da_profile_destination + g_unknown_l2uc.uuc_mcid;

    /*
     * Set VLAN port membership
     */
    bcm_pbmp_t pbmp, untag_pbmp;

    BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_CLEAR(untag_pbmp);

    for (i = 0; i < NUM_OF_PORTS; i++)
    {
        BCM_PBMP_PORT_ADD(pbmp, g_unknown_l2uc.ports[i]);
    }
    BCM_PBMP_PORT_ADD(untag_pbmp, g_unknown_l2uc.ports[0]);  /* Port_1 is part of both untag_pbm and pbm. Putting it 
                                                                 * in pbm will configure
                                                                 * IPPF_VLAN_MEMBERSHIP_TABLE.VLAN_PORT_MEMBER_LINE */

    rv = bcm_vlan_port_add(unit, g_unknown_l2uc.vsi, pbmp, untag_pbmp);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_add\n");
        return rv;
    }

    /*
     * Add vid=100 as Default_Vid on all Ports 
     */
    for (i = 0; i < NUM_OF_PORTS; i++)
    {
        rv = bcm_port_untagged_vlan_set(unit, g_unknown_l2uc.ports[i], g_unknown_l2uc.outer_vid);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_untagged_vlan_set\n");
            return rv;
        }
    }

    /*
     * Creates default In-Lif
     */
    bcm_vlan_port_t vlan_port;
    bcm_vlan_port_t_init(&vlan_port);
    bcm_gport_t inlif0;
    rv = bcm_vlan_gport_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.ports[0], 0);
    rv = bcm_vlan_gport_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.ports[1], 0);
    rv = bcm_vlan_gport_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.ports[2], 0);
    rv = bcm_vlan_gport_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.ports[3], 0);

    /* Default Port based InLif creation on Port_1 */
    if (*dnxc_data_get(unit, "flow", "general", "is_flow_enabled_for_legacy_applications", NULL))
    {
       BCM_GPORT_SUB_TYPE_VIRTUAL_INGRESS_NON_NATIVE_SET(inlif0,5000);
    } else {
        BCM_GPORT_SUB_TYPE_LIF_SET(inlif0, BCM_GPORT_SUB_TYPE_LIF_EXC_INGRESS_ONLY, 5000);
    }
    BCM_GPORT_VLAN_PORT_ID_SET(inlif0, inlif0);

    vlan_port.flags = (BCM_VLAN_PORT_CREATE_INGRESS_ONLY | BCM_VLAN_PORT_WITH_ID);
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT;
    vlan_port.vsi = g_unknown_l2uc.vsi;
    vlan_port.vlan_port_id = inlif0;
    vlan_port.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }

    g_unknown_l2uc.inlif[g_unknown_l2uc.Port_1_untag][0] = vlan_port.vlan_port_id;
    g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0] = vlan_port.vlan_port_id;

    printf("InLif create: port=%d, vlan_port_id=0x%08x,\n", vlan_port.port, vlan_port.vlan_port_id);

    /*
     * S_C_VLAN_Db based InLif creation on Port_2
     */
    /*
     * GPORT_TYPE <<26, GPORT_SUB_TYPE <<22;lif vlaue
     */
    inlif0 = (17 << 26 | 2 << 22 | 50000);

    vlan_port.flags = BCM_VLAN_PORT_WITH_ID;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN; /* As per Test plan, for DTAG packet as well InLif derivation
                                                         * is based on SVLAN */
    vlan_port.vsi = 0;
    vlan_port.vlan_port_id = inlif0;
    vlan_port.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_2_stag];
    vlan_port.match_vlan = g_unknown_l2uc.outer_vid;

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }

    g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0] = vlan_port.vlan_port_id;
    g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0] = vlan_port.vlan_port_id;

    printf("InLif create: port=%d, vlan_port_id=0x%08x,\n", vlan_port.port, vlan_port.vlan_port_id);

/* SVLAN_Db based InLif creation on Port_4 */
    /*
     * GPORT_TYPE <<26, GPORT_SUB_TYPE <<22;lif vlaue
     */
    inlif0 = (17 << 26 | 2 << 22 | 6000);

    vlan_port.flags = BCM_VLAN_PORT_WITH_ID;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vlan_port.vsi = 0;
    vlan_port.vlan_port_id = inlif0;
    vlan_port.match_vlan = g_unknown_l2uc.outer_vid;
    vlan_port.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_4_stag];

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }

    g_unknown_l2uc.inlif[g_unknown_l2uc.Port_4_stag][0] = vlan_port.vlan_port_id;
    g_unknown_l2uc.outlif[g_unknown_l2uc.Port_4_stag][0] = vlan_port.vlan_port_id;

    printf("InLif create: port=%d, vlan_port_id=0x%08x,\n", vlan_port.port, vlan_port.vlan_port_id);

/* S_C_VLAN_Db based InLif creation on Port_3*/
    /*
     * GPORT_TYPE <<26, GPORT_SUB_TYPE <<22;lif vlaue
     */
    inlif0 = (17 << 26 | 2 << 22 | 7000);

    vlan_port.flags = BCM_VLAN_PORT_WITH_ID;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN; /* As per Test plan, for DTAG packet as well InLif derivation
                                                         * is based on SVLAN */
    vlan_port.vsi = 0;
    vlan_port.vlan_port_id = inlif0;
    vlan_port.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_3_dtag];
    vlan_port.match_vlan = g_unknown_l2uc.outer_vid;
    vlan_port.match_inner_vlan = g_unknown_l2uc.inner_vid;

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }

    g_unknown_l2uc.inlif[g_unknown_l2uc.Port_3_dtag][0] = vlan_port.vlan_port_id;
    g_unknown_l2uc.outlif[g_unknown_l2uc.Port_3_dtag][0] = vlan_port.vlan_port_id;

    printf("InLif create: port=%d, vlan_port_id=0x%08x,\n", vlan_port.port, vlan_port.vlan_port_id);

    /*
     * Add All symmetric Lifs created to VSI
     */
    rv = bcm_vswitch_port_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0]);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vswitch_port_add(port = %d)\n", g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0]);
        return rv;
    }
    rv = bcm_vswitch_port_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_3_dtag][0]);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vswitch_port_add(port = %d)\n", g_unknown_l2uc.inlif[g_unknown_l2uc.Port_3_dtag][0]);
        return rv;
    }
    rv = bcm_vswitch_port_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_4_stag][0]);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vswitch_port_add(port = %d)\n", g_unknown_l2uc.inlif[g_unknown_l2uc.Port_4_stag][0]);
        return rv;
    }

    /*
     * Ingress LLVP configs
     * Incoming STAG
     */
    bcm_port_tpid_class_t port_tpid_class;
    bcm_port_tpid_class_t_init(&port_tpid_class);

    port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    port_tpid_class.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];
    port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_untag;

    rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set(Port_1)\n");
        return rv;
    }

    port_tpid_class.tpid1 = g_unknown_l2uc.tpids.tpid1;
    port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    port_tpid_class.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_4_stag];
    port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_stag;

    rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set(Port_4)\n");
        return rv;
    }

    port_tpid_class.tpid1 = g_unknown_l2uc.tpids.tpid1;
    port_tpid_class.tpid2 = g_unknown_l2uc.tpids.tpid0;
    port_tpid_class.flags = BCM_PORT_TPID_CLASS_INGRESS_ONLY;
    port_tpid_class.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_3_dtag];
    port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_dtag;

    rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_port_tpid_class_set(Port_3)\n");
        return rv;
    }

    /*
     * Incoming is Un-TAG
     * Canonical Format is UnTAG
     * Hence IVE ={None,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_1_untag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid0,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid1,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.new_outer_vid,  /* new_outer_vid */
                                                g_unknown_l2uc.new_inner_vid,  /* new_inner_vid */
                                                ing_vlan_edit_profile_untag,    /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_untag,       /* tag_format */
                                                TRUE    /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set(setting IVE to {None,None}\n");
        return rv;
    }

    /*
     * Incoming is DTAG Canonical Format is UnTAG Hence IVE ={None,None} 
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_3_dtag][0],  /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.new_outer_vid,  /* new_outer_vid */
                                                g_unknown_l2uc.new_inner_vid,  /* new_inner_vid */
                                                ing_vlan_edit_profile_dtag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_dtag,        /* tag_format */
                                                TRUE    /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set(setting IVE to {None,None}\n");
        return rv;
    }

    /*
     * Incoming is STAG
     * Canonical Format is UnTAG
     * Hence IVE ={None,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_4_stag][0],  /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.new_outer_vid,  /* new_outer_vid */
                                                g_unknown_l2uc.new_inner_vid,  /* new_inner_vid */
                                                ing_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_stag,        /* tag_format */
                                                TRUE    /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set(setting IVE to {None,None}\n");
        return rv;
    }

    /*
     * Create Outlif in EEDB for Port_2 
     */
    bcm_gport_t outlif;

    /*
     * DA-Not-Found Configurations for flooding
     */
    int flags;
    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        flags = BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC;
    } else {
        flags = BCM_MULTICAST_INGRESS_GROUP;
    }
    rv = bcm_multicast_create(unit, (BCM_MULTICAST_WITH_ID | flags), &g_unknown_l2uc.uuc_mcid);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_multicast_create\n");
        return rv;
    }

    bcm_multicast_replication_t rep_array;
    bcm_multicast_replication_t_init(&rep_array);

    rep_array.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];
    rep_array.encap1 = (g_unknown_l2uc.inlif[g_unknown_l2uc.Port_1_untag][0] & 0xffff);

    rv = bcm_multicast_add(unit, g_unknown_l2uc.uuc_mcid, flags, 1, &rep_array);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_multicast_add in Port=Port_1\n");
        return rv;
    }

    rep_array.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_2_stag];
    rep_array.encap1 = (g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0] & 0x3fffff);
    rv = bcm_multicast_add(unit, g_unknown_l2uc.uuc_mcid, flags, 1, &rep_array);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_multicast_add in Port= Port_2\n");
        return rv;
    }

    rep_array.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_3_dtag];
    rep_array.encap1 = (g_unknown_l2uc.outlif[g_unknown_l2uc.Port_3_dtag][0] & 0x3fffff);

    rv = bcm_multicast_add(unit, g_unknown_l2uc.uuc_mcid, flags, 1, &rep_array);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_multicast_add in Port= Port_3\n");
        return rv;
    }

    rep_array.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_4_stag];
    rep_array.encap1 = (g_unknown_l2uc.outlif[g_unknown_l2uc.Port_4_stag][0] & 0x3fffff);

    rv = bcm_multicast_add(unit, g_unknown_l2uc.uuc_mcid, flags, 1, &rep_array);

    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_multicast_add in Port= Port_4\n");
        return rv;
    }

    outlif = (17 << 26 | 2 << 22 | 10003);

    vlan_port.flags = BCM_VLAN_PORT_WITH_ID;
    vlan_port.criteria = BCM_VLAN_PORT_MATCH_PORT_VLAN;
    vlan_port.vsi = 0;
    vlan_port.vlan_port_id = outlif;
    vlan_port.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];

    rv = bcm_vlan_port_create(unit, &vlan_port);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vlan_port_create(port = %d)\n", vlan_port.port);
        return rv;
    }

    g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0] = vlan_port.vlan_port_id;
    printf("OutLif create: port=%d, vlan_port_id=0x%08x,\n", vlan_port.port, vlan_port.vlan_port_id);
    rv = bcm_vswitch_port_add(unit, g_unknown_l2uc.vsi, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0]);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in bcm_vswitch_port_add(port = %d)\n", g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0]);
        return rv;
    }
    
    /*
     * Egress LLVP configs
     * As Canonical Format is NOOP
     * Hence packet after IVE, in egress will be based on ingress Port
     */

    /*
     * TPID Profiles for different TAGs on all Ports 
     */
    bcm_port_tpid_class_t_init(&port_tpid_class);

    for (i = 0; i < NUM_OF_PORTS; i++)
    {
        port_tpid_class.tpid1 = BCM_PORT_TPID_CLASS_TPID_INVALID;
        port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
        port_tpid_class.flags = BCM_PORT_TPID_CLASS_EGRESS_ONLY;
        port_tpid_class.port = g_unknown_l2uc.ports[i];
        port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_untag;

        rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_tpid_class_set( Port=%d )\n", g_unknown_l2uc.ports[i]);
            return rv;
        }

        port_tpid_class.tpid1 = g_unknown_l2uc.tpids.tpid1;
        port_tpid_class.tpid2 = BCM_PORT_TPID_CLASS_TPID_INVALID;
        port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_stag;

        rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_tpid_class_set( Port=%d )\n", g_unknown_l2uc.ports[i]);
            return rv;
        }

        port_tpid_class.tpid1 = g_unknown_l2uc.tpids.tpid1;
        port_tpid_class.tpid2 = g_unknown_l2uc.tpids.tpid0;
        port_tpid_class.tag_format_class_id = g_unknown_l2uc.tag_format_dtag;

        rv = bcm_port_tpid_class_set(unit, &port_tpid_class);
        if (rv != BCM_E_NONE)
        {
            printf("Error, in bcm_port_tpid_class_set( Port=%d )\n", g_unknown_l2uc.ports[i]);
            return rv;
        }
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = Untag
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionAdd,       /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_untag,       /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_2)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = STAG
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_stag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_2)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = DTAG
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */
    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionDelete,    /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_dtag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_2 )\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = Untag
     * Out Pkt = UnTAG
     * Hence EVE ={None,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0],        /* lif - need
                                                                                                                     * the gport,
                                                                                                                     * thus use
                                                                                                                     * inLifList
                                                                                                                     * instead of
                                                                                                                     * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionMappedAdd, /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_untag,    /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_untag,       /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_1)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = STAG
     * Out Pkt = UnTAG
     * EVE ={Delete,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0],        /* lif - need
                                                                                                                     * the gport,
                                                                                                                     * thus use
                                                                                                                     * inLifList
                                                                                                                     * instead of
                                                                                                                     * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionDelete,    /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_untag,    /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_stag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_1)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = DTAG
     * Out Pkt = UnTAG
     * EVE ={Delete,Delete}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0],        /* lif - need
                                                                                                                     * the gport,
                                                                                                                     * thus use
                                                                                                                     * inLifList
                                                                                                                     * instead of
                                                                                                                     * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionDelete,    /* outer_action */
                                                bcmVlanActionDelete,    /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_untag,    /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_dtag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_1)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = Untag
     * Out Pkt = DTAG
     * Hence EVE ={Add,Add}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_3_dtag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionAdd,       /* outer_action */
                                                bcmVlanActionAdd,       /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_dtag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_untag,       /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_1)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = STAG
     * Out Pkt = DTAG
     * EVE ={None,Add}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_3_dtag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionAdd,       /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_dtag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_stag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_3 )\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = DTAG
     * Out Pkt = DTAG
     * EVE ={None,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_3_dtag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_dtag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_dtag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_3)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = Untag
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_4_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionAdd,       /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_untag,       /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_4)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = STAG
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */

    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_4_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionNone,      /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_stag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_2)\n");
        return rv;
    }

    /*
     * Egress Vlan Edit
     * Tag After IVE = DTAG
     * Out Pkt = STAG
     * Hence EVE ={Add,None}
     */
    rv = vlan_translate_ive_eve_translation_set(unit, g_unknown_l2uc.outlif[g_unknown_l2uc.Port_4_stag][0], /* lif - need the
                                                                                                             * gport, thus use
                                                                                                             * inLifList instead of
                                                                                                             * * * * outLifList */
                                                g_unknown_l2uc.tpids.tpid1,  /* outer_tpid */
                                                g_unknown_l2uc.tpids.tpid0,  /* inner_tpid */
                                                bcmVlanActionNone,      /* outer_action */
                                                bcmVlanActionDelete,    /* inner_action */
                                                g_unknown_l2uc.egr_new_outer_vid,      /* new_outer_vid */
                                                g_unknown_l2uc.egr_new_inner_vid,      /* new_inner_vid */
                                                egr_vlan_edit_profile_stag,     /* vlan_edit_profile */
                                                g_unknown_l2uc.tag_format_dtag,        /* tag_format */
                                                FALSE   /* is_ive */
        );

    if (rv != BCM_E_NONE)
    {
        printf("Error, in vlan_translate_ive_eve_translation_set( Port_4)\n");
        return rv;
    }

    /*
     * arp profile set
     */
    bcm_rx_trap_protocol_profiles_t protocol_profiles = { 0 };
    protocol_profiles.arp_trap_profile = g_unknown_l2uc.arp_trap_profile;
    protocol_profiles.l2cp_trap_profile = g_unknown_l2uc.l2cp_trap_profile;
    rv = bcm_rx_trap_protocol_profiles_set(unit, g_unknown_l2uc.inlif[g_unknown_l2uc.Port_1_untag][0], &protocol_profiles);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_profiles_set : arp and l2cp profiles set per lif\n");
        return rv;
    }

    rv = bcm_rx_trap_protocol_profiles_set(unit,g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0], &protocol_profiles);
    if (rv != BCM_E_NONE) {
         printf("Error, bcm_rx_trap_protocol_profiles_set : arp and l2cp profiles set per lif\n");
       return rv;
    }

    rv = bcm_rx_trap_protocol_profiles_set(unit,g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0], &protocol_profiles);
    if (rv != BCM_E_NONE) {
         printf("Error, bcm_rx_trap_protocol_profiles_set : arp and l2cp profiles set per lif\n");
       return rv;
    }

    rv = bcm_rx_trap_protocol_profiles_set(unit,g_unknown_l2uc.inlif[g_unknown_l2uc.Port_2_stag][0], &protocol_profiles);
    if (rv != BCM_E_NONE) {
         printf("Error, bcm_rx_trap_protocol_profiles_set : arp and l2cp profiles set per lif\n");
       return rv;
    }
    
    /* On init time hair pin filter is with default trap strength  - 4, in the cint lower trap strength is required*/
    bcm_gport_t hairpin_gport;
    int hairpin_trap_id;
    rv = bcm_rx_trap_action_profile_get(unit, bcmRxTrapEgHairPinFilter, &hairpin_gport);
    if (rv != BCM_E_NONE) {
        printf("Error, bcm_rx_trap_action_profile_get: Couldn't retrieve gprot for bcmRxTrapEgHairPinFilter\n");
        return rv;
    }
    hairpin_trap_id = BCM_GPORT_TRAP_GET_ID(hairpin_gport);
    BCM_GPORT_TRAP_SET(hairpin_gport, hairpin_trap_id, 2, 0);

    rv = bcm_rx_trap_action_profile_set(unit, 0, bcmRxTrapEgHairPinFilter, hairpin_gport);
    if (rv != BCM_E_NONE) {
    printf("Error, bcm_rx_trap_action_profile_set: Couldn't update gprot for bcmRxTrapEgHairPinFilter\n");
    return rv;
    }
    /* TRAP call for ARP*/
    rv = unknown_l2uc__l2_basic_bridge_arp_trap_create(unit);
    if (rv != BCM_E_NONE)
    {
        printf("Error, unknown_l2uc__l2_basic_bridge_arp_trap_create for ARP\n");
        return rv;
    }

    /*
     * TRAP call for My ARP
     */
    rv = unknown_l2uc__l2_basic_bridge_my_arp_trap_create(unit);
    if (rv != BCM_E_NONE)
    {
        printf("Error, unknown_l2uc__l2_basic_bridge_arp_trap_create for ARP\n");
        return rv;
    }

    /*
     * TRAP call for L2CP
     */
    rv = unknown_l2uc__l2_basic_bridge_l2cp_trap_create(unit);
    if (rv != BCM_E_NONE)
    {
        printf("Error, unknown_l2uc__l2_basic_bridge_l2cp_trap_create for ARP\n");
        return rv;
    }

    /*
     * Add l2 address -
     * adding oPort and outLif to MACT
     */
    bcm_l2_addr_t l2_addr;

    bcm_l2_addr_t_init(&l2_addr, g_unknown_l2uc.d_mac, g_unknown_l2uc.vsi);

    l2_addr.flags = BCM_L2_STATIC;
    l2_addr.port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_2_stag];
    bcm_gport_t forward_encap_id;
    BCM_FORWARD_ENCAP_ID_VAL_SET(forward_encap_id, BCM_FORWARD_ENCAP_ID_TYPE_OUTLIF,
                                 BCM_FORWARD_ENCAP_ID_OUTLIF_USAGE_VLAN_PORT, 10000);
    l2_addr.encap_id = forward_encap_id;

    rv = bcm_l2_addr_add(unit, &l2_addr);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_l2_addr_add\n");
        return rv;
    }

    return rv;
}

int
unknown_l2uc__l2_basic_bridge_arp_trap_create(
    int unit)
{
    int rv;
    bcm_rx_trap_config_t config;
    bcm_gport_t trap_gport;
    bcm_rx_trap_protocol_profiles_t protocol_profiles = { 0 };
    bcm_rx_trap_protocol_key_t key = { 0 };
    /*
     * ARP trap ID
     */
    rv = bcm_rx_trap_type_create(unit, 0, bcmRxTrapUserDefine, &g_unknown_l2uc.arp_trap_id);
    printf("trap id generated is ARP %d\n", g_unknown_l2uc.arp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_create for ARP\n");
        return rv;
    }

    config.flags = (BCM_RX_TRAP_UPDATE_ENCAP_ID | BCM_RX_TRAP_UPDATE_DEST);
    config.dest_port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];
    config.encap_id = g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0];
    rv = bcm_rx_trap_set(unit, g_unknown_l2uc.arp_trap_id, &config);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_set for ARP\n");
        return rv;
    }


    key.protocol_type = bcmRxTrapArp;
    key.protocol_trap_profile = g_unknown_l2uc.arp_trap_profile;
    BCM_GPORT_TRAP_SET(trap_gport, g_unknown_l2uc.arp_trap_id, g_unknown_l2uc.arp_fwd_strength, 0);
    rv = bcm_rx_trap_protocol_set(unit, &key, trap_gport);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for ARP\n");
        return rv;
    }

    return rv;
}

int
unknown_l2uc__l2_basic_bridge_my_arp_trap_create(
    int unit)
{
    int rv;
    bcm_rx_trap_config_t config;
    bcm_gport_t trap_gport;
    bcm_rx_trap_protocol_profiles_t protocol_profiles = { 0 };
    bcm_rx_trap_protocol_key_t key = { 0 };

    /*
     * ARP trap ID
     */
    rv = bcm_rx_trap_type_create(unit, 0, bcmRxTrapUserDefine, &g_unknown_l2uc.my_arp_trap_id);
    printf("trap id generated is MY_ARP%d\n", g_unknown_l2uc.my_arp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_create for ARP\n");
        return rv;
    }

    config.flags = (BCM_RX_TRAP_UPDATE_ENCAP_ID | BCM_RX_TRAP_UPDATE_DEST);
    config.dest_port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_2_stag];
    config.encap_id = g_unknown_l2uc.outlif[g_unknown_l2uc.Port_2_stag][0];
    rv = bcm_rx_trap_set(unit, g_unknown_l2uc.my_arp_trap_id, &config);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_set for ARP\n");
        return rv;
    }

    key.protocol_type = bcmRxTrapArpMyIp;
    key.protocol_trap_profile = g_unknown_l2uc.arp_trap_profile;
    BCM_GPORT_TRAP_SET(trap_gport, g_unknown_l2uc.my_arp_trap_id, g_unknown_l2uc.my_arp_fwd_strength, 0);
    rv = bcm_rx_trap_protocol_set(unit, &key, trap_gport);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for ARP\n");
        return rv;
    }

    return rv;
}

int
unknown_l2uc__l2_basic_bridge_arp_traps_destroy(
    int unit)
{
    int rv;
    bcm_rx_trap_protocol_key_t key = { 0 };
    rv = bcm_rx_trap_type_destroy(unit, g_unknown_l2uc.arp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_destroy for arp_trap_id\n");
        return rv;
    }

    rv = bcm_rx_trap_type_destroy(unit, g_unknown_l2uc.my_arp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_destroy for my_arp_trap_id\n");
        return rv;
    }

    key.protocol_type = bcmRxTrapArpMyIp;
    key.protocol_trap_profile = g_unknown_l2uc.arp_trap_profile;
    rv = bcm_rx_trap_protocol_clear(unit, &key);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for myARP\n");
        return rv;
    }

    key.protocol_type = bcmRxTrapArp;
    rv = bcm_rx_trap_protocol_clear(unit, &key);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for ARP\n");
        return rv;
    }

    return rv;
}

int
unknown_l2uc__l2_basic_bridge_l2cp_trap_create(
    int unit)
{
    int rv;
    bcm_rx_trap_config_t config;
    bcm_gport_t trap_gport;
    bcm_rx_trap_protocol_profiles_t protocol_profiles = { 0 };
    bcm_rx_trap_protocol_key_t key = { 0 };
    /*
     * L2CP trap ID
     */
    rv = bcm_rx_trap_type_create(unit, 0, bcmRxTrapUserDefine, &g_unknown_l2uc.l2cp_trap_id);
    printf("trap id generated is L2CP %d\n", g_unknown_l2uc.l2cp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_create for L2CP\n");
        return rv;
    }

    config.flags = (BCM_RX_TRAP_UPDATE_ENCAP_ID | BCM_RX_TRAP_UPDATE_DEST);
    config.dest_port = g_unknown_l2uc.ports[g_unknown_l2uc.Port_1_untag];
    config.encap_id = g_unknown_l2uc.outlif[g_unknown_l2uc.Port_1_untag][0];
    rv = bcm_rx_trap_set(unit, g_unknown_l2uc.l2cp_trap_id, &config);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_set for L2CP\n");
        return rv;
    }

    key.protocol_type = bcmRxTrapL2cpPeer;
    key.protocol_trap_profile = g_unknown_l2uc.l2cp_trap_profile;
    BCM_GPORT_TRAP_SET(trap_gport, g_unknown_l2uc.l2cp_trap_id, g_unknown_l2uc.l2cp_fwd_strength, 0);
    rv = bcm_rx_trap_protocol_set(unit, &key, trap_gport);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for L2CP\n");
        return rv;
    }

    return rv;
}

/* l2cp trap destroy*/
int
unknown_l2uc__l2_basic_bridge_l2cp_traps_destroy(
    int unit)
{
    int rv;
    bcm_rx_trap_protocol_key_t key = { 0 };
    rv = bcm_rx_trap_type_destroy(unit, g_unknown_l2uc.l2cp_trap_id);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_type_destroy for l2cp_trap_id\n");
        return rv;
    }

    key.protocol_type = bcmRxTrapL2cpPeer;
    key.protocol_trap_profile = g_unknown_l2uc.l2cp_trap_profile;
    rv = bcm_rx_trap_protocol_clear(unit, &key);
    if (rv != BCM_E_NONE)
    {
        printf("Error, bcm_rx_trap_protocol_set for L2CP\n");
        return rv;
    }

    return rv;
}

/* Configure global tpids of switch*/
int
unknown_l2uc__tpids_assign(
    int unit)
{
    int rv;

    rv = tpid__tpids_clear_all(unit);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpids_clear_all, rv = %d\n", rv);
        return rv;
    }

    /*
     * Set all 7 valid TPIDs
     */
    /*
     * TPID0 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid0);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid0, rv);
        return rv;
    }

    /*
     * TPID1 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid1);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid1, rv);
        return rv;
    }

    /*
     * TPID2 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid2);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid2, rv);
        return rv;
    }

    /*
     * TPID3 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid3);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid3, rv);
        return rv;
    }

    /*
     * TPID4 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid4);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid4, rv);
        return rv;
    }

    /*
     * TPID5 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid5);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid5, rv);
        return rv;
    }

    /*
     * TPID6 
     */
    rv = tpid__tpid_add(unit, g_unknown_l2uc.tpids.tpid6);
    if (rv != BCM_E_NONE)
    {
        printf("Error, in tpid__tpid_add(tpid_value=0x%04x), rv = %d\n", g_unknown_l2uc.tpids.tpid6, rv);
        return rv;
    }

    return rv;

}