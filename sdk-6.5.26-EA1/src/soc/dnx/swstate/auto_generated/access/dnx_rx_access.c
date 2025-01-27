
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/access/dnx_rx_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_rx_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_rx_layout.h>





int
dnx_rx_parser_info_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID]),
        "dnx_rx_parser_info[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        rx_paser_info_t,
        DNX_SW_STATE_DNX_RX_PARSER_INFO_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_rx_parser_info_init",
        DNX_SW_STATE_DIAG_ALLOC,
        dnx_rx_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID]),
        "dnx_rx_parser_info[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_lb_key_size_set(int unit, uint32 ftmh_lb_key_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_lb_key_size,
        ftmh_lb_key_size,
        uint32,
        0,
        "dnx_rx_parser_info_ftmh_lb_key_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        &ftmh_lb_key_size,
        "dnx_rx_parser_info[%d]->ftmh_lb_key_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_LB_KEY_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_lb_key_size_get(int unit, uint32 *ftmh_lb_key_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        ftmh_lb_key_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *ftmh_lb_key_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_lb_key_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_lb_key_size,
        "dnx_rx_parser_info[%d]->ftmh_lb_key_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_LB_KEY_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_LB_KEY_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_stacking_ext_size_set(int unit, uint32 ftmh_stacking_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_stacking_ext_size,
        ftmh_stacking_ext_size,
        uint32,
        0,
        "dnx_rx_parser_info_ftmh_stacking_ext_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        &ftmh_stacking_ext_size,
        "dnx_rx_parser_info[%d]->ftmh_stacking_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_STACKING_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_stacking_ext_size_get(int unit, uint32 *ftmh_stacking_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        ftmh_stacking_ext_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *ftmh_stacking_ext_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_stacking_ext_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_stacking_ext_size,
        "dnx_rx_parser_info[%d]->ftmh_stacking_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_STACKING_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_STACKING_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_user_header_enable_set(int unit, uint8 user_header_enable)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->user_header_enable,
        user_header_enable,
        uint8,
        0,
        "dnx_rx_parser_info_user_header_enable_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        &user_header_enable,
        "dnx_rx_parser_info[%d]->user_header_enable",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_USER_HEADER_ENABLE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_user_header_enable_get(int unit, uint8 *user_header_enable)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        user_header_enable);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        DNX_SW_STATE_DIAG_READ);

    *user_header_enable = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->user_header_enable;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->user_header_enable,
        "dnx_rx_parser_info[%d]->user_header_enable",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__USER_HEADER_ENABLE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_USER_HEADER_ENABLE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_pph_base_size_set(int unit, uint32 pph_base_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->pph_base_size,
        pph_base_size,
        uint32,
        0,
        "dnx_rx_parser_info_pph_base_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        &pph_base_size,
        "dnx_rx_parser_info[%d]->pph_base_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_PPH_BASE_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_pph_base_size_get(int unit, uint32 *pph_base_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        pph_base_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *pph_base_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->pph_base_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->pph_base_size,
        "dnx_rx_parser_info[%d]->pph_base_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__PPH_BASE_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_PPH_BASE_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_1_ext_size_set(int unit, uint32 out_lif_x_1_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_1_ext_size,
        out_lif_x_1_ext_size,
        uint32,
        0,
        "dnx_rx_parser_info_out_lif_x_1_ext_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        &out_lif_x_1_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_1_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_1_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_1_ext_size_get(int unit, uint32 *out_lif_x_1_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        out_lif_x_1_ext_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *out_lif_x_1_ext_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_1_ext_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_1_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_1_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_1_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_1_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_2_ext_size_set(int unit, uint32 out_lif_x_2_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_2_ext_size,
        out_lif_x_2_ext_size,
        uint32,
        0,
        "dnx_rx_parser_info_out_lif_x_2_ext_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        &out_lif_x_2_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_2_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_2_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_2_ext_size_get(int unit, uint32 *out_lif_x_2_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        out_lif_x_2_ext_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *out_lif_x_2_ext_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_2_ext_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_2_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_2_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_2_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_2_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_3_ext_size_set(int unit, uint32 out_lif_x_3_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_3_ext_size,
        out_lif_x_3_ext_size,
        uint32,
        0,
        "dnx_rx_parser_info_out_lif_x_3_ext_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        &out_lif_x_3_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_3_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_3_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_out_lif_x_3_ext_size_get(int unit, uint32 *out_lif_x_3_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        out_lif_x_3_ext_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *out_lif_x_3_ext_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_3_ext_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->out_lif_x_3_ext_size,
        "dnx_rx_parser_info[%d]->out_lif_x_3_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OUT_LIF_X_3_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OUT_LIF_X_3_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_in_lif_ext_size_set(int unit, uint32 in_lif_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->in_lif_ext_size,
        in_lif_ext_size,
        uint32,
        0,
        "dnx_rx_parser_info_in_lif_ext_size_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        &in_lif_ext_size,
        "dnx_rx_parser_info[%d]->in_lif_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_IN_LIF_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_in_lif_ext_size_get(int unit, uint32 *in_lif_ext_size)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        in_lif_ext_size);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        DNX_SW_STATE_DIAG_READ);

    *in_lif_ext_size = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->in_lif_ext_size;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->in_lif_ext_size,
        "dnx_rx_parser_info[%d]->in_lif_ext_size",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__IN_LIF_EXT_SIZE,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_IN_LIF_EXT_SIZE_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_oamp_system_port_0_set(int unit, uint32 oamp_system_port_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_0,
        oamp_system_port_0,
        uint32,
        0,
        "dnx_rx_parser_info_oamp_system_port_0_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        &oamp_system_port_0,
        "dnx_rx_parser_info[%d]->oamp_system_port_0",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OAMP_SYSTEM_PORT_0_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_oamp_system_port_0_get(int unit, uint32 *oamp_system_port_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        oamp_system_port_0);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        DNX_SW_STATE_DIAG_READ);

    *oamp_system_port_0 = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_0;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_0,
        "dnx_rx_parser_info[%d]->oamp_system_port_0",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_0,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OAMP_SYSTEM_PORT_0_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_oamp_system_port_1_set(int unit, uint32 oamp_system_port_1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_1,
        oamp_system_port_1,
        uint32,
        0,
        "dnx_rx_parser_info_oamp_system_port_1_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        &oamp_system_port_1,
        "dnx_rx_parser_info[%d]->oamp_system_port_1",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OAMP_SYSTEM_PORT_1_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_oamp_system_port_1_get(int unit, uint32 *oamp_system_port_1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        oamp_system_port_1);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        DNX_SW_STATE_DIAG_READ);

    *oamp_system_port_1 = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_1;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->oamp_system_port_1,
        "dnx_rx_parser_info[%d]->oamp_system_port_1",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__OAMP_SYSTEM_PORT_1,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_OAMP_SYSTEM_PORT_1_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_dma_channel_to_cpu_port_set(int unit, uint32 dma_channel_to_cpu_port_idx_0, int dma_channel_to_cpu_port)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port,
        dma_channel_to_cpu_port_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port[dma_channel_to_cpu_port_idx_0],
        dma_channel_to_cpu_port,
        int,
        0,
        "dnx_rx_parser_info_dma_channel_to_cpu_port_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        &dma_channel_to_cpu_port,
        "dnx_rx_parser_info[%d]->dma_channel_to_cpu_port[%d]",
        unit, dma_channel_to_cpu_port_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_DMA_CHANNEL_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_dma_channel_to_cpu_port_get(int unit, uint32 dma_channel_to_cpu_port_idx_0, int *dma_channel_to_cpu_port)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port,
        dma_channel_to_cpu_port_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        dma_channel_to_cpu_port);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_READ);

    *dma_channel_to_cpu_port = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port[dma_channel_to_cpu_port_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port[dma_channel_to_cpu_port_idx_0],
        "dnx_rx_parser_info[%d]->dma_channel_to_cpu_port[%d]",
        unit, dma_channel_to_cpu_port_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_DMA_CHANNEL_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_dma_channel_to_cpu_port_alloc(int unit, uint32 nof_instances_to_alloc_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port,
        int,
        nof_instances_to_alloc_0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_rx_parser_info_dma_channel_to_cpu_port_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port,
        "dnx_rx_parser_info[%d]->dma_channel_to_cpu_port",
        unit,
        nof_instances_to_alloc_0 * sizeof(int) / sizeof(*((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->dma_channel_to_cpu_port));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__DMA_CHANNEL_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_DMA_CHANNEL_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_cpu_port_to_dma_channel_set(int unit, uint32 cpu_port_to_dma_channel_idx_0, int cpu_port_to_dma_channel)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel,
        cpu_port_to_dma_channel_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel[cpu_port_to_dma_channel_idx_0],
        cpu_port_to_dma_channel,
        int,
        0,
        "dnx_rx_parser_info_cpu_port_to_dma_channel_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        &cpu_port_to_dma_channel,
        "dnx_rx_parser_info[%d]->cpu_port_to_dma_channel[%d]",
        unit, cpu_port_to_dma_channel_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_CPU_PORT_TO_DMA_CHANNEL_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_cpu_port_to_dma_channel_get(int unit, uint32 cpu_port_to_dma_channel_idx_0, int *cpu_port_to_dma_channel)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel,
        cpu_port_to_dma_channel_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        cpu_port_to_dma_channel);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        DNX_SW_STATE_DIAG_READ);

    *cpu_port_to_dma_channel = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel[cpu_port_to_dma_channel_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel[cpu_port_to_dma_channel_idx_0],
        "dnx_rx_parser_info[%d]->cpu_port_to_dma_channel[%d]",
        unit, cpu_port_to_dma_channel_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_CPU_PORT_TO_DMA_CHANNEL_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_cpu_port_to_dma_channel_alloc(int unit, uint32 nof_instances_to_alloc_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel,
        int,
        nof_instances_to_alloc_0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_rx_parser_info_cpu_port_to_dma_channel_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel,
        "dnx_rx_parser_info[%d]->cpu_port_to_dma_channel",
        unit,
        nof_instances_to_alloc_0 * sizeof(int) / sizeof(*((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->cpu_port_to_dma_channel));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__CPU_PORT_TO_DMA_CHANNEL,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_CPU_PORT_TO_DMA_CHANNEL_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_set(int unit, uint32 ftmh_pp_dsp_to_cpu_port_idx_0, int ftmh_pp_dsp_to_cpu_port)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port,
        ftmh_pp_dsp_to_cpu_port_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port[ftmh_pp_dsp_to_cpu_port_idx_0],
        ftmh_pp_dsp_to_cpu_port,
        int,
        0,
        "dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        &ftmh_pp_dsp_to_cpu_port,
        "dnx_rx_parser_info[%d]->ftmh_pp_dsp_to_cpu_port[%d]",
        unit, ftmh_pp_dsp_to_cpu_port_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_PP_DSP_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_get(int unit, uint32 ftmh_pp_dsp_to_cpu_port_idx_0, int *ftmh_pp_dsp_to_cpu_port)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_OOB_DYNAMIC_ARRAY_CHECK(
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port,
        ftmh_pp_dsp_to_cpu_port_idx_0);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ftmh_pp_dsp_to_cpu_port);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_READ);

    *ftmh_pp_dsp_to_cpu_port = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port[ftmh_pp_dsp_to_cpu_port_idx_0];
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port[ftmh_pp_dsp_to_cpu_port_idx_0],
        "dnx_rx_parser_info[%d]->ftmh_pp_dsp_to_cpu_port[%d]",
        unit, ftmh_pp_dsp_to_cpu_port_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_PP_DSP_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_alloc(int unit, uint32 nof_instances_to_alloc_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        SW_STATE_FUNC_ALLOC,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        DNX_SW_STATE_DIAG_ALLOC);

    DNX_SW_STATE_ALLOC(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port,
        int,
        nof_instances_to_alloc_0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_alloc");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_ALLOC_LOGGING,
        BSL_LS_SWSTATEDNX_ALLOC,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port,
        "dnx_rx_parser_info[%d]->ftmh_pp_dsp_to_cpu_port",
        unit,
        nof_instances_to_alloc_0 * sizeof(int) / sizeof(*((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->ftmh_pp_dsp_to_cpu_port));

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__FTMH_PP_DSP_TO_CPU_PORT,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_FTMH_PP_DSP_TO_CPU_PORT_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id1_set(int unit, uint32 etpp_oam_up_mep_dest_trap_id1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id1,
        etpp_oam_up_mep_dest_trap_id1,
        uint32,
        0,
        "dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id1_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        &etpp_oam_up_mep_dest_trap_id1,
        "dnx_rx_parser_info[%d]->etpp_oam_up_mep_dest_trap_id1",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_ETPP_OAM_UP_MEP_DEST_TRAP_ID1_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id1_get(int unit, uint32 *etpp_oam_up_mep_dest_trap_id1)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        etpp_oam_up_mep_dest_trap_id1);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        DNX_SW_STATE_DIAG_READ);

    *etpp_oam_up_mep_dest_trap_id1 = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id1;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id1,
        "dnx_rx_parser_info[%d]->etpp_oam_up_mep_dest_trap_id1",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID1,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_ETPP_OAM_UP_MEP_DEST_TRAP_ID1_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id2_set(int unit, uint32 etpp_oam_up_mep_dest_trap_id2)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        SW_STATE_FUNC_SET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        DNX_SW_STATE_DIAG_MODIFY);

    DNX_SW_STATE_SET(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id2,
        etpp_oam_up_mep_dest_trap_id2,
        uint32,
        0,
        "dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id2_set");

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_SET_LOGGING,
        BSL_LS_SWSTATEDNX_SET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        &etpp_oam_up_mep_dest_trap_id2,
        "dnx_rx_parser_info[%d]->etpp_oam_up_mep_dest_trap_id2",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_ETPP_OAM_UP_MEP_DEST_TRAP_ID2_INFO,
        DNX_SW_STATE_DIAG_MODIFY,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id2_get(int unit, uint32 *etpp_oam_up_mep_dest_trap_id2)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        SW_STATE_FUNC_GET,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        sw_state_roots_array[unit][DNX_RX_MODULE_ID]);

    DNX_SW_STATE_PTR_NULL_CHECK(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        etpp_oam_up_mep_dest_trap_id2);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        DNX_SW_STATE_DIAG_READ);

    *etpp_oam_up_mep_dest_trap_id2 = ((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id2;
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_GET_LOGGING,
        BSL_LS_SWSTATEDNX_GET,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        &((rx_paser_info_t*)sw_state_roots_array[unit][DNX_RX_MODULE_ID])->etpp_oam_up_mep_dest_trap_id2,
        "dnx_rx_parser_info[%d]->etpp_oam_up_mep_dest_trap_id2",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_DNX_RX_PARSER_INFO__ETPP_OAM_UP_MEP_DEST_TRAP_ID2,
        dnx_rx_parser_info_info,
        DNX_RX_PARSER_INFO_ETPP_OAM_UP_MEP_DEST_TRAP_ID2_INFO,
        DNX_SW_STATE_DIAG_READ,
        NULL);

    DNXC_SW_STATE_FUNC_RETURN;
}





dnx_rx_parser_info_cbs dnx_rx_parser_info = 	{
	
	dnx_rx_parser_info_is_init,
	dnx_rx_parser_info_init,
		{
		
		dnx_rx_parser_info_ftmh_lb_key_size_set,
		dnx_rx_parser_info_ftmh_lb_key_size_get}
	,
		{
		
		dnx_rx_parser_info_ftmh_stacking_ext_size_set,
		dnx_rx_parser_info_ftmh_stacking_ext_size_get}
	,
		{
		
		dnx_rx_parser_info_user_header_enable_set,
		dnx_rx_parser_info_user_header_enable_get}
	,
		{
		
		dnx_rx_parser_info_pph_base_size_set,
		dnx_rx_parser_info_pph_base_size_get}
	,
		{
		
		dnx_rx_parser_info_out_lif_x_1_ext_size_set,
		dnx_rx_parser_info_out_lif_x_1_ext_size_get}
	,
		{
		
		dnx_rx_parser_info_out_lif_x_2_ext_size_set,
		dnx_rx_parser_info_out_lif_x_2_ext_size_get}
	,
		{
		
		dnx_rx_parser_info_out_lif_x_3_ext_size_set,
		dnx_rx_parser_info_out_lif_x_3_ext_size_get}
	,
		{
		
		dnx_rx_parser_info_in_lif_ext_size_set,
		dnx_rx_parser_info_in_lif_ext_size_get}
	,
		{
		
		dnx_rx_parser_info_oamp_system_port_0_set,
		dnx_rx_parser_info_oamp_system_port_0_get}
	,
		{
		
		dnx_rx_parser_info_oamp_system_port_1_set,
		dnx_rx_parser_info_oamp_system_port_1_get}
	,
		{
		
		dnx_rx_parser_info_dma_channel_to_cpu_port_set,
		dnx_rx_parser_info_dma_channel_to_cpu_port_get,
		dnx_rx_parser_info_dma_channel_to_cpu_port_alloc}
	,
		{
		
		dnx_rx_parser_info_cpu_port_to_dma_channel_set,
		dnx_rx_parser_info_cpu_port_to_dma_channel_get,
		dnx_rx_parser_info_cpu_port_to_dma_channel_alloc}
	,
		{
		
		dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_set,
		dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_get,
		dnx_rx_parser_info_ftmh_pp_dsp_to_cpu_port_alloc}
	,
		{
		
		dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id1_set,
		dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id1_get}
	,
		{
		
		dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id2_set,
		dnx_rx_parser_info_etpp_oam_up_mep_dest_trap_id2_get}
	}
;
#undef BSL_LOG_MODULE
