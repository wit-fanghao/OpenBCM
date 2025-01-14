/** \file algo/swstate/auto_generated/access/esem_access.c
 *
 * sw state functions definitions
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

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <bcm_int/dnx/algo/swstate/auto_generated/access/esem_access.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/diagnostic/esem_diagnostic.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/layout/esem_layout.h>
/*
 * Global Variables
 */

/*
 * FUNCTIONs
 */

/*
 *
 * is_init function for the variable esem_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_ESEM_DB,
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID]),
        "esem_db[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * init function for the variable esem_db
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_ESEM_DB,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        esem_sw_state_t,
        DNX_SW_STATE_ESEM_DB_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "esem_db_init",
        DNX_SW_STATE_DIAG_ALLOC,
        esem_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_ESEM_DB,
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID]),
        "esem_db[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_ESEM_DB,
        esem_db_info,
        ESEM_DB_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID]),
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * create function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_create(int unit, sw_state_htb_create_info_t *init_info)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_CREATE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH_CREATE);

    SW_STATE_HTB_RH_CREATE(
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        init_info,
        sizeof(esem_key_t),
        sizeof(int8),
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION | DNXC_SW_STATE_DNX_DATA_ALLOC_EXCEPTION);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_CREATE_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHCREATE,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH_CREATE,
        NULL,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION | DNXC_SW_STATE_DNX_DATA_ALLOC_EXCEPTION,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * find function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_find(int unit, const esem_key_t *key, int8 *value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_FIND,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_FIND(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        key,
        value);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_FIND_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHFIND,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * get_next function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_get_next(int unit, uint32 *iter, esem_key_t *key, int8 *value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_GET_NEXT,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_GET_NEXT(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        iter,
        key,
        value);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_GET_NEXT_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHGET_NEXT,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * insert function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_insert(int unit, const esem_key_t *key, const int8 *value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_INSERT,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_INSERT(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        key,
        value);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_INSERT_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHINSERT,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * replace function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_replace(int unit, const esem_key_t *key, const int8 *value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_REPLACE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_REPLACE(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        key,
        value);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_REPLACE_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHREPLACE,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * delete function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_delete(int unit, const esem_key_t *key)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_DELETE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_DELETE(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        key);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_DELETE_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHDELETE,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * delete_all function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_delete_all(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_DELETE_ALL,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_DELETE_ALL(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_DELETE_ALL_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHDELETE_ALL,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * print function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_print(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_PRINT,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_PRINT(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_PRINT_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHPRINT,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 *
 * traverse function for the variable esem_key_to_sw_info_htb
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
int
esem_db_esem_key_to_sw_info_htb_traverse(int unit, sw_state_htb_traverse_cb traverse_func, void *user_data)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        SW_STATE_FUNC_TRAVERSE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        sw_state_roots_array[unit][ESEM_MODULE_ID]);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        DNX_SW_STATE_DIAG_HTB_RH);

    SW_STATE_HTB_RH_TRAVERSE(
        ((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        traverse_func,
        user_data);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_RH_TRAVERSE_LOGGING,
        BSL_LS_SWSTATEDNX_HTB_RHTRAVERSE,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        &((esem_sw_state_t*)sw_state_roots_array[unit][ESEM_MODULE_ID])->esem_key_to_sw_info_htb,
        "esem_db[%d]->esem_key_to_sw_info_htb",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_ESEM_DB__ESEM_KEY_TO_SW_INFO_HTB,
        esem_db_info,
        ESEM_DB_ESEM_KEY_TO_SW_INFO_HTB_INFO,
        DNX_SW_STATE_DIAG_HTB_RH,
        NULL,
        DNXC_SW_STATE_NO_FLAGS,
        sw_state_layout_array[unit][ESEM_MODULE_ID]);

    DNXC_SW_STATE_FUNC_RETURN;
}


/*
 * Global Variables
 */

esem_db_cbs esem_db = 	{
	
	esem_db_is_init,
	esem_db_init,
		{
		
		esem_db_esem_key_to_sw_info_htb_create,
		esem_db_esem_key_to_sw_info_htb_find,
		esem_db_esem_key_to_sw_info_htb_get_next,
		esem_db_esem_key_to_sw_info_htb_insert,
		esem_db_esem_key_to_sw_info_htb_replace,
		esem_db_esem_key_to_sw_info_htb_delete,
		esem_db_esem_key_to_sw_info_htb_delete_all,
		esem_db_esem_key_to_sw_info_htb_print,
		esem_db_esem_key_to_sw_info_htb_traverse}
	}
;
#undef BSL_LOG_MODULE
