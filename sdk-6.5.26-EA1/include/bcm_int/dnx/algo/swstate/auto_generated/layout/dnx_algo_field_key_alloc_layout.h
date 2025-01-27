/** \file algo/swstate/auto_generated/layout/dnx_algo_field_key_alloc_layout.h
 *
 * sw state layout enum
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

#ifndef __DNX_ALGO_FIELD_KEY_ALLOC_LAYOUT_H__
#define __DNX_ALGO_FIELD_KEY_ALLOC_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_algo_field_key_alloc_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_ALGO_FIELD_KEY_ALLOC_MODULE_ID, 0),
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__KEYS_AVAILABILITY_GROUP_INFO,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__NOF_AVAILABLE_KEYS_ON_STAGE,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__FIRST_AVAILABLE_KEY_ON_STAGE,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__KEYS_AVAILABILITY_GROUP_INFO__STRUCTURE_IS_VALID,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__KEYS_AVAILABILITY_GROUP_INFO__NOF_AVAILABLE_KEYS,
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW__KEYS_AVAILABILITY__KEYS_AVAILABILITY_STAGE_INFO__KEYS_AVAILABILITY_GROUP_INFO__FIRST_AVAILABLE_KEY,
    /*
     * Use DNXC_SW_STATE_LAYOUT_GET_PARAM_IDX macro to get the number of parameters
     */
    DNX_SW_STATE_DNX_FIELD_KEYS_PER_STAGE_ALLOCATION_SW_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_algo_field_key_alloc_node_id_e;

#endif /* __DNX_ALGO_FIELD_KEY_ALLOC_LAYOUT_H__ */
