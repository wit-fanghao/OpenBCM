/* 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 */

#include <sal/core/libc.h>
#include <shared/swstate/sw_state.h>
#include <shared/error.h>
#include <shared/swstate/sw_state_defs.h>
#include <shared/bsl.h>
#include <shared/swstate/sw_state_dump.h>
#include <shared/swstate/diagnostic/sw_state_diagnostic.h>
#include <shared/swstate/diagnostic/sw_state_dpp_bcm_policer_diagnostic.h>

#ifdef BCM_WARM_BOOT_SUPPORT
#ifdef _ERR_MSG_MODULE_NAME
    #error "_ERR_MSG_MODULE_NAME redefined"
#endif

#define _ERR_MSG_MODULE_NAME BSL_LS_SHARED_SWSTATE

extern shr_sw_state_t *sw_state[BCM_MAX_NUM_UNITS];

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_bcm_policer_dump(int unit){
    SW_STATE_INIT_FUNC_DEFS;
    {
        uint32 j0, J0;
        sw_state_get_nof_elements(unit, sw_state[unit]->dpp.bcm.policer, sizeof(*sw_state[unit]->dpp.bcm.policer), &j0 ,&J0);
        for (; j0 < J0; j0++) {
            shr_sw_state_dump_update_current_idx(unit, j0);
            sw_state_diagnostic[unit].dpp.bcm.policer.policer_group.dump(unit, j0);
        }
        shr_sw_state_dump_end_of_stride(unit);
    }
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_bcm_policer_policer_group_dump(int unit, int policer_idx_0){
    SW_STATE_INIT_FUNC_DEFS;
    {
        int i0;
        i0 = shr_sw_state_dump_check_all_the_same(unit, sw_state[unit]->dpp.bcm.policer[policer_idx_0].policer_group
            , sizeof(*sw_state[unit]->dpp.bcm.policer[policer_idx_0].policer_group), _DPP_POLICER_NOF_POLICERS) ? _DPP_POLICER_NOF_POLICERS - 1 : 0;
        for (; i0 < _DPP_POLICER_NOF_POLICERS; i0++) {
            shr_sw_state_dump_update_current_idx(unit, i0);
            sw_state_diagnostic[unit].dpp.bcm.policer.policer_group.mode.dump(unit, policer_idx_0, i0);
        }
        shr_sw_state_dump_end_of_stride(unit);
    }
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 

#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
/* AUTO-GENERATED - DO NOT MODIFY */
int sw_state_dpp_bcm_policer_policer_group_mode_dump(int unit, int policer_idx_0, int policer_group_idx_0){
    SW_STATE_INIT_FUNC_DEFS;
    SW_STATE_PRINT_OPAQUE(unit, sw_state[unit]->dpp.bcm.policer[policer_idx_0].policer_group[policer_group_idx_0].mode,
        "sw_state[%d]->dpp.bcm.policer[%d].policer_group[%d].mode: ", unit, policer_idx_0, policer_group_idx_0);
    SW_STATE_FUNC_RETURN;
}

#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 


int
sw_state_dpp_bcm_policer_diagnostic_cb_init(int unit){
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_diagnostic[unit].dpp.bcm.policer.dump = sw_state_dpp_bcm_policer_dump;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_diagnostic[unit].dpp.bcm.policer.policer_group.dump = sw_state_dpp_bcm_policer_policer_group_dump;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
#ifdef BCM_PETRA_SUPPORT
#if defined(BCM_PETRA_SUPPORT)
    sw_state_diagnostic[unit].dpp.bcm.policer.policer_group.mode.dump = sw_state_dpp_bcm_policer_policer_group_mode_dump;
#endif /* defined(BCM_PETRA_SUPPORT)*/ 
#endif /* BCM_PETRA_SUPPORT*/ 
    return _SHR_E_NONE;
}

#undef _ERR_MSG_MODULE_NAME
#endif /* BCM_WARM_BOOT_SUPPORT */