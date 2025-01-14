
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __DNX_OFP_RATE_LAYOUT_H__
#define __DNX_OFP_RATE_LAYOUT_H__

#include <include/soc/dnxc/swstate/types/dnxc_sw_state_layout.h>
#include <include/soc/dnxc/swstate/auto_generated/types/dnxc_module_ids_types.h>


int dnx_ofp_rate_init_layout_structure(int unit);

typedef enum
{
    DNX_SW_STATE_DNX_OFP_RATE_DB = DNXC_SW_STATE_LAYOUT_NODE_ID_GET(DNX_OFP_RATE_MODULE_ID, 0),
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM,
    DNX_SW_STATE_DNX_OFP_RATE_DB__QPAIR,
    DNX_SW_STATE_DNX_OFP_RATE_DB__TCG,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM_CAL,
    DNX_SW_STATE_DNX_OFP_RATE_DB__CALCAL_IS_MODIFIED,
    DNX_SW_STATE_DNX_OFP_RATE_DB__CALCAL_LEN,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM__CAL_INSTANCE,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM__SHAPING,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM__SHAPING__RATE,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM__SHAPING__BURST,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM__SHAPING__VALID,
    DNX_SW_STATE_DNX_OFP_RATE_DB__QPAIR__RATE,
    DNX_SW_STATE_DNX_OFP_RATE_DB__QPAIR__VALID,
    DNX_SW_STATE_DNX_OFP_RATE_DB__TCG__RATE,
    DNX_SW_STATE_DNX_OFP_RATE_DB__TCG__VALID,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM_CAL__RATE,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM_CAL__MODIFIED,
    DNX_SW_STATE_DNX_OFP_RATE_DB__OTM_CAL__NOF_CALCAL_INSTANCES,
    
    DNX_SW_STATE_DNX_OFP_RATE_DB_NOF_PARAMS,
} dnxc_sw_state_layout_dnx_ofp_rate_node_id_e;

#endif 
