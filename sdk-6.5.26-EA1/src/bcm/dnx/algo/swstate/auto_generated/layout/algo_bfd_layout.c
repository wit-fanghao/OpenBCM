/** \file algo/swstate/auto_generated/layout/algo_bfd_layout.c
 *
 * sw state layout structure
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_bfd_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/algo_bfd_layout.h>

dnxc_sw_state_layout_t layout_array_algo_bfd[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB_NOF_PARAMS)];

shr_error_e
algo_bfd_init_layout_structure(int unit)
{

    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB);
    layout_array_algo_bfd[idx].name = "algo_bfd_db";
    layout_array_algo_bfd[idx].type = "algo_bfd_sw_state_t";
    layout_array_algo_bfd[idx].doc = "BFD related sw state";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(algo_bfd_sw_state_t);
    layout_array_algo_bfd[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].first_child_index = 1;
    layout_array_algo_bfd[idx].last_child_index = 17;
    layout_array_algo_bfd[idx].next_node_index = 1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMA_ACTION);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oama_action";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD MEP OAMA Action";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 2;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMB_ACTION);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamb_action";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD MEP OAMB Action";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 3;

#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_TOS_TTL);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_tos_ttl";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP TOS-TTL";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 4;

#endif /* BCM_DNX2_SUPPORT*/ 
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_YOUR_DISCR_RANGE);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_your_discr_range";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD Your-Discr Range";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 5;

#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_TX_RATE);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_tx_rate";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP TX Rate";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 6;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_REQ_INTERVAL);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_req_interval";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP Required Interval";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 7;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_MY_DISCR_RANGE_START);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_my_discr_range_start";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP My-Discr Range Start";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 8;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_IPV4_SRC_ADDR);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_ipv4_src_addr";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP IPv4 Source Addr";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 9;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_UDP_SPORT);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_udp_sport";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP UDP SPORT";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 10;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_MPLS_SPORT);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_mpls_sport";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP MPLS SPORT";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 11;

#endif /* BCM_DNX2_SUPPORT*/ 
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_LOCAL_MIN_ECHO);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_local_min_echo";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP local min echo";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 12;

#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_TX_PERIOD_CLUSTER);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_tx_period_cluster";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD Tx Period Cluster";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 13;

#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_OAMP_V1_SINGLE_HOP_TOS);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_oamp_v1_single_hop_tos";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD OAMP single-hop TOS";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 14;

#endif /* BCM_DNX2_SUPPORT*/ 
    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_SEAMLESS_UDP_SPORT);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_seamless_udp_sport";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "SEAMLESS BFD UDP SPORT";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 15;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_SERVER_TRAP_CODES);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_server_trap_codes";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD SERVER trap codes";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 16;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_DIP);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_dip";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD DIP";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = 17;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_BFD_DB__BFD_SERVER_DEVICE_INDEX);
    layout_array_algo_bfd[idx].name = "algo_bfd_db__bfd_server_device_index";
    layout_array_algo_bfd[idx].type = "dnx_algo_template_t";
    layout_array_algo_bfd[idx].doc = "BFD_SERVER_DEVICE_INDEX";
    layout_array_algo_bfd[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_bfd[idx].parent  = 0;
    layout_array_algo_bfd[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_bfd[idx].next_node_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_ALGO_BFD_DB, layout_array_algo_bfd, sw_state_layout_array[unit][ALGO_BFD_MODULE_ID], DNX_SW_STATE_ALGO_BFD_DB_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#undef BSL_LOG_MODULE