
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#if defined(INCLUDE_KBP)
#include <soc/dnx/swstate/auto_generated/access/kbp_fwd_tcam_access_mapper_access.h>
#include <soc/dnx/swstate/auto_generated/diagnostic/kbp_fwd_tcam_access_mapper_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/layout/kbp_fwd_tcam_access_mapper_layout.h>





int
kbp_fwd_tcam_access_mapper_is_init(int unit, uint8 *is_init)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        SW_STATE_FUNC_IS_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    *is_init = (NULL != ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]));
    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_IS_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_ISINIT,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]),
        "kbp_fwd_tcam_access_mapper[%d]",
        unit);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_init(int unit)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        SW_STATE_FUNC_INIT,
        DNXC_SW_STATE_NO_FLAGS);

    DNX_SW_STATE_MODULE_INIT(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        DNXC_SW_STATE_IMPLEMENTATION_WB,
        kbp_fwd_tcam_access_mapper_t,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER_NOF_PARAMS,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION,
        "kbp_fwd_tcam_access_mapper_init",
        DNX_SW_STATE_DIAG_ALLOC,
        kbp_fwd_tcam_access_mapper_init_layout_structure);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_INIT_LOGGING,
        BSL_LS_SWSTATEDNX_INIT,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]),
        "kbp_fwd_tcam_access_mapper[%d]",
        unit);

    DNX_SW_STATE_DIAG_INFO_POST(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_INFO,
        DNX_SW_STATE_DIAG_ALLOC,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]));

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_create(int unit, uint32 key_2_entry_id_hash_idx_0, sw_state_htbl_init_info_t *init_info)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_CREATE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB_CREATE);

    SW_STATE_HTB_CREATE(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        init_info,
        dnx_kbp_fwd_tcam_access_hash_key_t,
        uint32,
        FALSE,
        0,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION | DNXC_SW_STATE_DNX_DATA_ALLOC_EXCEPTION);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_CREATE_LOGGING,
        BSL_LS_SWSTATEDNX_HTBCREATE,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB_CREATE,
        NULL,
        DNXC_SW_STATE_AUTO_GENERATED_ALLOCATION | DNXC_SW_STATE_DNX_DATA_ALLOC_EXCEPTION);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_find(int unit, uint32 key_2_entry_id_hash_idx_0, const dnx_kbp_fwd_tcam_access_hash_key_t *key, uint32 *value, uint8 *found)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_FIND,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB);

    SW_STATE_HTB_FIND(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        key,
        value,
        found);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_FIND_LOGGING,
        BSL_LS_SWSTATEDNX_HTBFIND,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB,
        NULL,
        DNXC_SW_STATE_NO_FLAGS);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_insert(int unit, uint32 key_2_entry_id_hash_idx_0, const dnx_kbp_fwd_tcam_access_hash_key_t *key, const uint32 *value, uint8 *success)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_INSERT,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB);

    SW_STATE_HTB_INSERT(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        key,
        value,
        success);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_INSERT_LOGGING,
        BSL_LS_SWSTATEDNX_HTBINSERT,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB,
        NULL,
        DNXC_SW_STATE_NO_FLAGS);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_get_next(int unit, uint32 key_2_entry_id_hash_idx_0, SW_STATE_HASH_TABLE_ITER *iter, const dnx_kbp_fwd_tcam_access_hash_key_t *key, const uint32 *value)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_GET_NEXT,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB);

    SW_STATE_HTB_GET_NEXT(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        iter,
        key,
        value);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_GET_NEXT_LOGGING,
        BSL_LS_SWSTATEDNX_HTBGET_NEXT,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB,
        NULL,
        DNXC_SW_STATE_NO_FLAGS);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_clear(int unit, uint32 key_2_entry_id_hash_idx_0)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_CLEAR,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB);

    SW_STATE_HTB_CLEAR(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0]);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_CLEAR_LOGGING,
        BSL_LS_SWSTATEDNX_HTBCLEAR,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB,
        NULL,
        DNXC_SW_STATE_NO_FLAGS);

    DNXC_SW_STATE_FUNC_RETURN;
}




int
kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_delete(int unit, uint32 key_2_entry_id_hash_idx_0, const dnx_kbp_fwd_tcam_access_hash_key_t *key)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    VERIFY_FUNCTION_CALL_ALLOWED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        SW_STATE_FUNC_DELETE,
        DNXC_SW_STATE_NO_FLAGS);

    VERIFY_MODULE_IS_INITIALIZED(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID]);

    DNX_SW_STATE_OOB_STATIC_ARRAY_CHECK(
        key_2_entry_id_hash_idx_0,
        DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

    DNX_SW_STATE_DIAG_INFO_PRE(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        DNX_SW_STATE_DIAG_HTB);

    SW_STATE_HTB_DELETE(
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        ((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        key);

    DNX_SW_STATE_LOG(
        unit,
        DNX_SW_STATE_HTB_DELETE_LOGGING,
        BSL_LS_SWSTATEDNX_HTBDELETE,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        &((kbp_fwd_tcam_access_mapper_t*)sw_state_roots_array[unit][KBP_FWD_TCAM_ACCESS_MAPPER_MODULE_ID])->key_2_entry_id_hash[key_2_entry_id_hash_idx_0],
        "kbp_fwd_tcam_access_mapper[%d]->key_2_entry_id_hash[%d]",
        unit, key_2_entry_id_hash_idx_0);

    DNX_SW_STATE_DIAG_INFO_POST_WITH_FLAGS(
        unit,
        DNX_SW_STATE_KBP_FWD_TCAM_ACCESS_MAPPER__KEY_2_ENTRY_ID_HASH,
        kbp_fwd_tcam_access_mapper_info,
        KBP_FWD_TCAM_ACCESS_MAPPER_KEY_2_ENTRY_ID_HASH_INFO,
        DNX_SW_STATE_DIAG_HTB,
        NULL,
        DNXC_SW_STATE_NO_FLAGS);

    DNXC_SW_STATE_FUNC_RETURN;
}




const char *
dnx_kbp_fwd_tcam_hash_table_index_e_get_name(dnx_kbp_fwd_tcam_hash_table_index_e value)
{
#if defined(INCLUDE_KBP)
    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_KBP_TCAM_HASH_TABLE_INDEX_IPV4_MC", value, DNX_KBP_TCAM_HASH_TABLE_INDEX_IPV4_MC);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_KBP_TCAM_HASH_TABLE_INDEX_IPV6_MC", value, DNX_KBP_TCAM_HASH_TABLE_INDEX_IPV6_MC);

    DNX_SW_STATE_ENUM_COMPARE_AND_GET_NAME("DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES", value, DNX_KBP_MAX_NOF_TCAM_HASH_TABLE_INDICES);

#endif  
    return NULL;
}





kbp_fwd_tcam_access_mapper_cbs kbp_fwd_tcam_access_mapper = 	{
	
	kbp_fwd_tcam_access_mapper_is_init,
	kbp_fwd_tcam_access_mapper_init,
		{
		
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_create,
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_find,
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_insert,
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_get_next,
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_clear,
		kbp_fwd_tcam_access_mapper_key_2_entry_id_hash_delete}
	}
;
#endif  
#undef BSL_LOG_MODULE
