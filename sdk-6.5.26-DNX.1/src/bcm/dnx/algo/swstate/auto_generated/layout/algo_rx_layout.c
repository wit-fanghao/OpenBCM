/** \file algo/swstate/auto_generated/layout/algo_rx_layout.c
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

#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_rx_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/algo_rx_layout.h>

dnxc_sw_state_layout_t layout_array_algo_rx[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB_NOF_PARAMS)];

shr_error_e
algo_rx_init_layout_structure(int unit)
{

    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB);
    layout_array_algo_rx[idx].name = "algo_rx_db";
    layout_array_algo_rx[idx].type = "algo_rx_sw_state_t";
    layout_array_algo_rx[idx].doc = "RX traps related sw state";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(algo_rx_sw_state_t);
    layout_array_algo_rx[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__FIRST);
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__LAST)-1;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_INGRESS_PREDEFINED);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_ingress_predefined";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "res mngr for ingress traps - predefined traps";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_INGRESS_USER_DEFINED);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_ingress_user_defined";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "res mngr for ingress traps - user_define traps";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_ERPP);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_erpp";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "res mngr for ERPP traps";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_ETPP);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_etpp";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "res mngr for ETPP traps";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_ETPP_OAM);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_etpp_oam";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "res mngr for ETPP traps - OAM traps";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_PROTOCOL_ICMP_TYPE_MAP);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_protocol_icmp_type_map";
    layout_array_algo_rx[idx].type = "dnx_algo_res_t";
    layout_array_algo_rx[idx].doc = "TRAP_PROTOCOL_ICMP_TYPE_MAP";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_RECYCLE_CMD);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_recycle_cmd";
    layout_array_algo_rx[idx].type = "dnx_algo_template_t";
    layout_array_algo_rx[idx].doc = "TRAP_RECYCLE_CMD";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_LIF_INGRESS);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_lif_ingress";
    layout_array_algo_rx[idx].type = "dnx_algo_template_t";
    layout_array_algo_rx[idx].doc = "TRAP_LIF_INGRESS";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_LIF_ETPP);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_lif_etpp";
    layout_array_algo_rx[idx].type = "dnx_algo_template_t";
    layout_array_algo_rx[idx].doc = "TRAP_LIF_ETPP";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_ALGO_RX_DB__TRAP_MTU);
    layout_array_algo_rx[idx].name = "algo_rx_db__trap_mtu";
    layout_array_algo_rx[idx].type = "dnx_algo_template_t";
    layout_array_algo_rx[idx].doc = "TRAP_MTU";
    layout_array_algo_rx[idx].sum_of_allocation = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].size_of = sizeof(dnx_algo_template_t);
    layout_array_algo_rx[idx].parent  = 0;
    layout_array_algo_rx[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_algo_rx[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_ALGO_RX_DB, layout_array_algo_rx, sw_state_layout_array[unit][ALGO_RX_MODULE_ID], DNX_SW_STATE_ALGO_RX_DB_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#undef BSL_LOG_MODULE