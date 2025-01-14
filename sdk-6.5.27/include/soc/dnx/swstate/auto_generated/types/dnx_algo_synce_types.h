
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_ALGO_SYNCE_TYPES_H__
#define __DNX_ALGO_SYNCE_TYPES_H__

#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/auto_generated/types/dnxc_types.h>


typedef struct {
    soc_dnxc_synce_status_t fabric_synce_status;
    soc_dnxc_synce_status_t nif_synce_status;
    uint32* synce_type_core_group_id;
} dnx_algo_synce_db_t;


#endif 
