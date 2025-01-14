
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_field_tcam_manager_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_tcam_manager_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_field_tcam_manager_layout.h>





int
dnx_field_tcam_manager_sw_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]),
        "dnx_field_tcam_manager_sw[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        dnx_field_tcam_manager_sw_t,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_manager_sw_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_field_tcam_manager_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]),
        "dnx_field_tcam_manager_sw[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_set(int unit, uint32 tcam_handlers_idx_0, CONST dnx_field_tcam_handler_t *tcam_handlers)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_MEMCPY(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0],
        tcam_handlers,
        dnx_field_tcam_handler_t,
        0,
        "dnx_field_tcam_manager_sw_tcam_handlers_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        tcam_handlers,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d]",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_get(int unit, uint32 tcam_handlers_idx_0, dnx_field_tcam_handler_t *tcam_handlers)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        tcam_handlers);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        DNX_SW_STATE_DIAG_READ);

    *tcam_handlers = ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        &((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0],
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d]",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_alloc(int unit)
{
    DNX_SW_STATE_DEFAULT_VALUE_DEFS;
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        dnx_field_tcam_handler_t,
        dnx_data_field.tcam.nof_tcam_handlers_get(unit),
        DNXC_SW_STATE_DNX_DATA_ALLOC | DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_field_tcam_manager_sw_tcam_handlers_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers",
        unit,
        dnx_data_field.tcam.nof_tcam_handlers_get(unit) * sizeof(dnx_field_tcam_handler_t) / sizeof(*((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNX_SW_STATE_DEFAULT_VALUE_LOOP(def_val_idx[0], dnx_data_field.tcam.nof_tcam_handlers_get(unit))

    DNX_SW_STATE_DEFAULT_VALUE_ASSIGN(
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[def_val_idx[0]].mode,
        DNX_FIELD_TCAM_HANDLER_MODE_INVALID);

    DNX_SW_STATE_DEFAULT_VALUE_LOOP(def_val_idx[0], dnx_data_field.tcam.nof_tcam_handlers_get(unit))

    DNX_SW_STATE_DEFAULT_VALUE_ASSIGN(
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[def_val_idx[0]].state,
        DNX_FIELD_TCAM_HANDLER_STATE_CLOSE);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_mode_set(int unit, uint32 tcam_handlers_idx_0, dnx_field_tcam_handler_mode_e mode)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].mode,
        mode,
        dnx_field_tcam_handler_mode_e,
        0,
        "dnx_field_tcam_manager_sw_tcam_handlers_mode_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        &mode,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d].mode",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_MODE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_mode_get(int unit, uint32 tcam_handlers_idx_0, dnx_field_tcam_handler_mode_e *mode)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        mode);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        DNX_SW_STATE_DIAG_READ);

    *mode = ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].mode;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        &((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].mode,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d].mode",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__MODE,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_MODE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_state_set(int unit, uint32 tcam_handlers_idx_0, dnx_field_tcam_handler_state_e state)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].state,
        state,
        dnx_field_tcam_handler_state_e,
        0,
        "dnx_field_tcam_manager_sw_tcam_handlers_state_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        &state,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d].state",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_STATE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_tcam_manager_sw_tcam_handlers_state_get(int unit, uint32 tcam_handlers_idx_0, dnx_field_tcam_handler_state_e *state)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers,
        tcam_handlers_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        state);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        DNX_SW_STATE_DIAG_READ);

    *state = ((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].state;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        &((dnx_field_tcam_manager_sw_t*)sw_state_roots_array[unit][DNX_FIELD_TCAM_MANAGER_MODULE_ID])->tcam_handlers[tcam_handlers_idx_0].state,
        "dnx_field_tcam_manager_sw[%d]->tcam_handlers[%d].state",
        unit, tcam_handlers_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_FIELD_TCAM_MANAGER_SW__TCAM_HANDLERS__STATE,
        dnx_field_tcam_manager_sw_info,
        DNX_FIELD_TCAM_MANAGER_SW_TCAM_HANDLERS_STATE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




const char *
dnx_field_tcam_handler_mode_e_get_name(dnx_field_tcam_handler_mode_e value)
{
    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_MODE_INVALID", value, DNX_FIELD_TCAM_HANDLER_MODE_INVALID);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_MODE_DEFAULT", value, DNX_FIELD_TCAM_HANDLER_MODE_DEFAULT);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_MODE_NOF_MODES", value, DNX_FIELD_TCAM_HANDLER_MODE_NOF_MODES);

    return NULL;
}




const char *
dnx_field_tcam_handler_state_e_get_name(dnx_field_tcam_handler_state_e value)
{
    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_STATE_INVALID", value, DNX_FIELD_TCAM_HANDLER_STATE_INVALID);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_STATE_CLOSE", value, DNX_FIELD_TCAM_HANDLER_STATE_CLOSE);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_STATE_OPEN", value, DNX_FIELD_TCAM_HANDLER_STATE_OPEN);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_FIELD_TCAM_HANDLER_STATE_NOF_STATES", value, DNX_FIELD_TCAM_HANDLER_STATE_NOF_STATES);

    return NULL;
}





dnx_field_tcam_manager_sw_cbs dnx_field_tcam_manager_sw = 	{
	
	dnx_field_tcam_manager_sw_is_init,
	dnx_field_tcam_manager_sw_init,
		{
		
		dnx_field_tcam_manager_sw_tcam_handlers_set,
		dnx_field_tcam_manager_sw_tcam_handlers_get,
		dnx_field_tcam_manager_sw_tcam_handlers_alloc,
			{
			
			dnx_field_tcam_manager_sw_tcam_handlers_mode_set,
			dnx_field_tcam_manager_sw_tcam_handlers_mode_get}
		,
			{
			
			dnx_field_tcam_manager_sw_tcam_handlers_state_set,
			dnx_field_tcam_manager_sw_tcam_handlers_state_get}
		}
	}
;
#undef BSL_LOG_MODULE
