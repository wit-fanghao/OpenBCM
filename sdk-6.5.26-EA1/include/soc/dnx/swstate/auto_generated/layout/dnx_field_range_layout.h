
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_FIELD_RANGE_LAYOUT_H__
#define __DNX_FIELD_RANGE_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_field_range_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_FIELD_RANGE_MODULE_ID, 0),
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_RANGE_TYPES,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__DNX_QUAL,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__QUAL_INFO,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__QUAL_INFO__INPUT_TYPE,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__QUAL_INFO__INPUT_ARG,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__QUAL_INFO__OFFSET,
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB__EXT_L4_OPS_FFC_QUALS__QUAL_INFO__BASE_QUAL,
    
    DNX_SW_STATE_DNX_FIELD_RANGE_SW_DB_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_field_range_node_id_e;

#endif 
