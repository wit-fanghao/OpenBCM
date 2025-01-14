
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __STIF_LAYOUT_H__
#define __STIF_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int stif_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_STIF_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(STIF_MODULE_ID, 0),
    DNX_SW_STATE_DNX_STIF_DB__INSTANCE,
    DNX_SW_STATE_DNX_STIF_DB__SOURCE_MAPPING,
    DNX_SW_STATE_DNX_STIF_DB__INSTANCE__LOGICAL_PORT,
    DNX_SW_STATE_DNX_STIF_DB__SOURCE_MAPPING__FIRST_PORT,
    DNX_SW_STATE_DNX_STIF_DB__SOURCE_MAPPING__SECOND_PORT,
    
    DNX_SW_STATE_DNX_STIF_DB_NOF_PARAMS,
} dnxc_sw_state_layout_stif_node_id_e;

#endif 
