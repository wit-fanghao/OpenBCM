
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 * 
 */

shr_error_e
field_pmf_cpu_trap_code_profile_cpu_trap_code_profile_dataoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__ingress_trap_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_INGRESS_TRAP_ID, key_value__ingress_trap_id);
    *offset = key_value__ingress_trap_id;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_state_table_state_table_data_hw_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__state_table_address_hw;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_STATE_TABLE_ADDRESS_HW, key_value__state_table_address_hw);
    *offset = key_value__state_table_address_hw;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_ipmf1_l4_ops_ranges_min_src_l4_port_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__field_pmf_range_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_FIELD_PMF_RANGE_ID, key_value__field_pmf_range_id);
    *offset = key_value__field_pmf_range_id;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_ipmf1_l4_ops_ranges_cfg_field_select_l4_ops_field_type_select_dataoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__l4_ops_range_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_L4_OPS_RANGE_ID, key_value__l4_ops_range_id);
    *offset = key_value__l4_ops_range_id*3;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_ipmf1_l4_ops_encode_cfg_l4_ops_encode_map_dataoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__l4_ops_encode_idx;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_L4_OPS_ENCODE_IDX, key_value__l4_ops_encode_idx);
    *offset = key_value__l4_ops_encode_idx*4;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_pmf_pp_port_info_ifwd_pp_port_cs_profile_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__pp_port;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_PP_PORT, key_value__pp_port);
    *offset = key_value__pp_port;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_pmf_ptc_info_ifwd_ptc_cs_profile_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__ptc;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_PTC, key_value__ptc);
    *offset = key_value__ptc;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_pmf_out_tm_port_info_epmf_out_tm_port_pmf_data_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__out_tm_port;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_OUT_TM_PORT, key_value__out_tm_port);
    *offset = key_value__out_tm_port;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_ipmf1_cs_inlif_profile_map_inlif_0_profile_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__cs_inlif_profile_entry;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_CS_INLIF_PROFILE_ENTRY, key_value__cs_inlif_profile_entry);
    *offset = key_value__cs_inlif_profile_entry;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_epmf_cs_outlif_profile_map_outlif_profile_dataoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 key_value__cs_outlif_profile_entry;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_KEY_VALUE(unit, eh, DBAL_FIELD_CS_OUTLIF_PROFILE_ENTRY, key_value__cs_outlif_profile_entry);
    *offset = key_value__cs_outlif_profile_entry*4;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_pmf_small_exem_learning_info_map_format_value_entryoffset_0_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 full_key_value;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_FULL_KEY_VALUE(unit, eh, full_key_value);
    *offset = full_key_value;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
shr_error_e
field_pmf_small_exem_learning_info_map_format_value_entryoffset_1_cb(
int unit,
void * entry_handle,
dbal_fields_e current_mapped_field_id,
uint32 * offset)
{
    dbal_entry_handle_t *  eh = (dbal_entry_handle_t *) entry_handle;
    uint32 full_key_value;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FORMULA_CB_GET_FULL_KEY_VALUE(unit, eh, full_key_value);
    *offset = full_key_value+8;
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}
