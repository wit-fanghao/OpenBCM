/** \file algo/swstate/auto_generated/layout/cosq_aqm_layout.c
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

#include <bcm_int/dnx/algo/swstate/auto_generated/types/cosq_aqm_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/cosq_aqm_layout.h>

dnxc_sw_state_layout_t layout_array_cosq_aqm[DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB_NOF_PARAMS)];

shr_error_e
cosq_aqm_init_layout_structure(int unit)
{

    int idx;

    DNXC_SW_STATE_INIT_FUNC_DEFS;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB);
    layout_array_cosq_aqm[idx].name = "dnx_cosq_aqm_db";
    layout_array_cosq_aqm[idx].type = "dnx_cosq_aqm_db_t";
    layout_array_cosq_aqm[idx].doc = "cosq aqm database per unit";
    layout_array_cosq_aqm[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].size_of = sizeof(dnx_cosq_aqm_db_t);
    layout_array_cosq_aqm[idx].parent  = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].first_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB__FIRST);
    layout_array_cosq_aqm[idx].last_child_index = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB__LAST);

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB__AQM_PROFILE_RES);
    layout_array_cosq_aqm[idx].name = "dnx_cosq_aqm_db__aqm_profile_res";
    layout_array_cosq_aqm[idx].type = "dnx_algo_res_t";
    layout_array_cosq_aqm[idx].doc = "holds AQM profiles allocation manager";
    layout_array_cosq_aqm[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_cosq_aqm[idx].parent  = 0;
    layout_array_cosq_aqm[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;

    idx = DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX(DNX_SW_STATE_DNX_COSQ_AQM_DB__AQM_FLOW_ID_RES);
    layout_array_cosq_aqm[idx].name = "dnx_cosq_aqm_db__aqm_flow_id_res";
    layout_array_cosq_aqm[idx].type = "dnx_algo_res_t";
    layout_array_cosq_aqm[idx].doc = "holds AQM flow id allocation manager";
    layout_array_cosq_aqm[idx].total_size = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].size_of = sizeof(dnx_algo_res_t);
    layout_array_cosq_aqm[idx].parent  = 0;
    layout_array_cosq_aqm[idx].first_child_index = DNXC_SW_STATE_LAYOUT_INVALID;
    layout_array_cosq_aqm[idx].last_child_index = DNXC_SW_STATE_LAYOUT_INVALID;


    dnxc_sw_state_layout_init_structure(unit, DNX_SW_STATE_DNX_COSQ_AQM_DB, layout_array_cosq_aqm, sw_state_layout_array[unit][COSQ_AQM_MODULE_ID], DNX_SW_STATE_DNX_COSQ_AQM_DB_NOF_PARAMS);

    DNXC_SW_STATE_FUNC_RETURN;
}

#undef BSL_LOG_MODULE