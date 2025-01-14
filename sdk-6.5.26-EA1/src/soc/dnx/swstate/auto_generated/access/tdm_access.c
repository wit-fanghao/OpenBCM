
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/tdm_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/tdm_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/tdm_layout.h>





int
tdm_ftmh_info_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_TDM_FTMH_INFO,
        ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID]),
        "tdm_ftmh_info[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
tdm_ftmh_info_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        tdm_ftmh_headers_params,
        DNX_SW_STATE_TDM_FTMH_INFO_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "tdm_ftmh_info_init",
        DNX_SW_STATE_DIAG_ALLOC,
        tdm_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_TDM_FTMH_INFO,
        ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID]),
        "tdm_ftmh_info[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO,
        tdm_ftmh_info_info,
        TDM_FTMH_INFO_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
tdm_ftmh_info_tdm_header_is_ftmh_set(int unit, uint8 tdm_header_is_ftmh)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        sw_state_roots_array[unit][TDM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->tdm_header_is_ftmh,
        tdm_header_is_ftmh,
        uint8,
        0,
        "tdm_ftmh_info_tdm_header_is_ftmh_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        &tdm_header_is_ftmh,
        "tdm_ftmh_info[%d]->tdm_header_is_ftmh",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        tdm_ftmh_info_info,
        TDM_FTMH_INFO_TDM_HEADER_IS_FTMH_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
tdm_ftmh_info_tdm_header_is_ftmh_get(int unit, uint8 *tdm_header_is_ftmh)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        sw_state_roots_array[unit][TDM_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        tdm_header_is_ftmh);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        DNX_SW_STATE_DIAG_READ);

    *tdm_header_is_ftmh = ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->tdm_header_is_ftmh;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        &((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->tdm_header_is_ftmh,
        "tdm_ftmh_info[%d]->tdm_header_is_ftmh",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__TDM_HEADER_IS_FTMH,
        tdm_ftmh_info_info,
        TDM_FTMH_INFO_TDM_HEADER_IS_FTMH_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
tdm_ftmh_info_use_optimized_ftmh_set(int unit, uint8 use_optimized_ftmh)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        sw_state_roots_array[unit][TDM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->use_optimized_ftmh,
        use_optimized_ftmh,
        uint8,
        0,
        "tdm_ftmh_info_use_optimized_ftmh_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        &use_optimized_ftmh,
        "tdm_ftmh_info[%d]->use_optimized_ftmh",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        tdm_ftmh_info_info,
        TDM_FTMH_INFO_USE_OPTIMIZED_FTMH_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
tdm_ftmh_info_use_optimized_ftmh_get(int unit, uint8 *use_optimized_ftmh)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        sw_state_roots_array[unit][TDM_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        use_optimized_ftmh);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        DNX_SW_STATE_DIAG_READ);

    *use_optimized_ftmh = ((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->use_optimized_ftmh;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        &((tdm_ftmh_headers_params*)sw_state_roots_array[unit][TDM_MODULE_ID])->use_optimized_ftmh,
        "tdm_ftmh_info[%d]->use_optimized_ftmh",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_TDM_FTMH_INFO__USE_OPTIMIZED_FTMH,
        tdm_ftmh_info_info,
        TDM_FTMH_INFO_USE_OPTIMIZED_FTMH_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}





tdm_ftmh_info_cbs tdm_ftmh_info = 	{
	
	tdm_ftmh_info_is_init,
	tdm_ftmh_info_init,
		{
		
		tdm_ftmh_info_tdm_header_is_ftmh_set,
		tdm_ftmh_info_tdm_header_is_ftmh_get}
	,
		{
		
		tdm_ftmh_info_use_optimized_ftmh_set,
		tdm_ftmh_info_use_optimized_ftmh_get}
	}
;
#undef BSL_LOG_MODULE
