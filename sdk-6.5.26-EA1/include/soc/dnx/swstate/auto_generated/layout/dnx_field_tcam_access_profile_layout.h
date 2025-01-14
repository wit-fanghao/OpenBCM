
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_FIELD_TCAM_ACCESS_PROFILE_LAYOUT_H__
#define __DNX_FIELD_TCAM_ACCESS_PROFILE_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_field_tcam_access_profile_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_FIELD_TCAM_ACCESS_PROFILE_MODULE_ID, 0),
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__OCCUPIED,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__KEY_SIZE,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__ACTION_SIZE,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__BANK_IDS_BMP,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__IS_DIRECT,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__PREFIX,
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW__ACCESS_PROFILES__HANDLER_ID,
    
    DNX_SW_STATE_DNX_FIELD_TCAM_ACCESS_PROFILE_SW_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_field_tcam_access_profile_node_id_e;

#endif 
