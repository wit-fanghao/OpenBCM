
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SOCDNX_DBALDNX

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_dbal.h>




extern shr_error_e jr2_a0_data_dbal_attach(
    int unit);


extern shr_error_e jr2_b0_data_dbal_attach(
    int unit);


extern shr_error_e j2c_a0_data_dbal_attach(
    int unit);


extern shr_error_e q2a_a0_data_dbal_attach(
    int unit);


extern shr_error_e j2p_a0_data_dbal_attach(
    int unit);


extern shr_error_e j2x_a0_data_dbal_attach(
    int unit);




static shr_error_e
dnx_data_dbal_diag_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "diag";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dbal_diag_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dbal diag features");

    
    submodule_data->nof_defines = _dnx_data_dbal_diag_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dbal diag defines");

    
    submodule_data->nof_tables = _dnx_data_dbal_diag_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dbal diag tables");

    
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].name = "loggerInfo";
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].size_of_values = sizeof(dnx_data_dbal_diag_loggerInfo_t);
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].entry_get = dnx_data_dbal_diag_loggerInfo_entry_str_get;

    
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].nof_keys = 0;

    
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].nof_values, "_dnx_data_dbal_diag_table_loggerInfo table values");
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].values[0].name = "file_name";
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].values[0].type = "char *";
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].values[0].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_loggerInfo].values[0].offset = UTILEX_OFFSETOF(dnx_data_dbal_diag_loggerInfo_t, file_name);

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].name = "example_1_key";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].size_of_values = sizeof(dnx_data_dbal_diag_example_1_key_t);
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].entry_get = dnx_data_dbal_diag_example_1_key_entry_str_get;

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].nof_keys = 1;
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].keys[0].name = "key1";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].keys[0].doc = "";

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].nof_values, "_dnx_data_dbal_diag_table_example_1_key table values");
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].values[0].name = "value1";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].values[0].type = "int";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].values[0].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_example_1_key].values[0].offset = UTILEX_OFFSETOF(dnx_data_dbal_diag_example_1_key_t, value1);

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].name = "example_2_keys";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].flags |= DNXC_DATA_F_TABLE;
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].size_of_values = sizeof(dnx_data_dbal_diag_example_2_keys_t);
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].entry_get = dnx_data_dbal_diag_example_2_keys_entry_str_get;

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].nof_keys = 2;
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].keys[0].name = "key1";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].keys[0].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].keys[1].name = "key2";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].keys[1].doc = "";

    
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].nof_values = 1;
    DNXC_DATA_ALLOC(submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].values, dnxc_data_value_t, submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].nof_values, "_dnx_data_dbal_diag_table_example_2_keys table values");
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].values[0].name = "value1";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].values[0].type = "int";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].values[0].doc = "";
    submodule_data->tables[dnx_data_dbal_diag_table_example_2_keys].values[0].offset = UTILEX_OFFSETOF(dnx_data_dbal_diag_example_2_keys_t, value1);


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dbal_diag_feature_get(
    int unit,
    dnx_data_dbal_diag_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, feature);
}




const dnx_data_dbal_diag_loggerInfo_t *
dnx_data_dbal_diag_loggerInfo_get(
    int unit)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_loggerInfo);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    return (const dnx_data_dbal_diag_loggerInfo_t *) data;

}

const dnx_data_dbal_diag_example_1_key_t *
dnx_data_dbal_diag_example_1_key_get(
    int unit,
    int key1)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_1_key);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, key1, 0);
    return (const dnx_data_dbal_diag_example_1_key_t *) data;

}

const dnx_data_dbal_diag_example_2_keys_t *
dnx_data_dbal_diag_example_2_keys_get(
    int unit,
    int key1,
    int key2)
{
    char *data;
    dnxc_data_table_t *table;

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_2_keys);
    
    data = dnxc_data_mgmt_table_data_get(unit, table, key1, key2);
    return (const dnx_data_dbal_diag_example_2_keys_t *) data;

}


shr_error_e
dnx_data_dbal_diag_loggerInfo_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dbal_diag_loggerInfo_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_loggerInfo);
    data = (const dnx_data_dbal_diag_loggerInfo_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, 0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%s", data->file_name == NULL ? "" : data->file_name);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dbal_diag_example_1_key_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dbal_diag_example_1_key_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_1_key);
    data = (const dnx_data_dbal_diag_example_1_key_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, 0);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->value1);
            break;
    }

    SHR_FUNC_EXIT;
}

shr_error_e
dnx_data_dbal_diag_example_2_keys_entry_str_get(
    int unit,
    char *buffer,
    int key0,
    int key1,
    int value_index)
{
    dnxc_data_table_t *table;
    const dnx_data_dbal_diag_example_2_keys_t *data;
    SHR_FUNC_INIT_VARS(unit);

    
    table = dnxc_data_mgmt_table_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_2_keys);
    data = (const dnx_data_dbal_diag_example_2_keys_t *) dnxc_data_mgmt_table_data_diag_get(unit, table, key0, key1);
    switch (value_index)
    {
        case 0:
            sal_snprintf(buffer, DNXC_DATA_MGMT_MAX_TABLE_VALUE_LENGTH, "%d", data->value1);
            break;
    }

    SHR_FUNC_EXIT;
}


const dnxc_data_table_info_t *
dnx_data_dbal_diag_loggerInfo_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_loggerInfo);

}

const dnxc_data_table_info_t *
dnx_data_dbal_diag_example_1_key_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_1_key);

}

const dnxc_data_table_info_t *
dnx_data_dbal_diag_example_2_keys_info_get(
    int unit)
{

    
    return dnxc_data_mgmt_table_info_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_diag, dnx_data_dbal_diag_table_example_2_keys);

}






static shr_error_e
dnx_data_dbal_db_init_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "db_init";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dbal_db_init_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dbal db_init features");

    submodule_data->features[dnx_data_dbal_db_init_invalid_feature_example].name = "invalid_feature_example";
    submodule_data->features[dnx_data_dbal_db_init_invalid_feature_example].doc = "";
    submodule_data->features[dnx_data_dbal_db_init_invalid_feature_example].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_dbal_db_init_zero_size_payload_support].name = "zero_size_payload_support";
    submodule_data->features[dnx_data_dbal_db_init_zero_size_payload_support].doc = "";
    submodule_data->features[dnx_data_dbal_db_init_zero_size_payload_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_dbal_db_init_support_encoding_for_hl_tcam].name = "support_encoding_for_hl_tcam";
    submodule_data->features[dnx_data_dbal_db_init_support_encoding_for_hl_tcam].doc = "";
    submodule_data->features[dnx_data_dbal_db_init_support_encoding_for_hl_tcam].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_dbal_db_init_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dbal db_init defines");

    submodule_data->defines[dnx_data_dbal_db_init_define_dbal_device_state].name = "dbal_device_state";
    submodule_data->defines[dnx_data_dbal_db_init_define_dbal_device_state].doc = "";
    
    submodule_data->defines[dnx_data_dbal_db_init_define_dbal_device_state].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_dbal_db_init_define_run_ltt_after_wm_test].name = "run_ltt_after_wm_test";
    submodule_data->defines[dnx_data_dbal_db_init_define_run_ltt_after_wm_test].doc = "";
    
    submodule_data->defines[dnx_data_dbal_db_init_define_run_ltt_after_wm_test].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_dbal_db_init_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dbal db_init tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dbal_db_init_feature_get(
    int unit,
    dnx_data_dbal_db_init_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_db_init, feature);
}


uint32
dnx_data_dbal_db_init_dbal_device_state_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_db_init, dnx_data_dbal_db_init_define_dbal_device_state);
}

uint32
dnx_data_dbal_db_init_run_ltt_after_wm_test_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_db_init, dnx_data_dbal_db_init_define_run_ltt_after_wm_test);
}










static shr_error_e
dnx_data_dbal_table_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "table";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dbal_table_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dbal table features");

    submodule_data->features[dnx_data_dbal_table_support_mdb_general_phys_db].name = "support_mdb_general_phys_db";
    submodule_data->features[dnx_data_dbal_table_support_mdb_general_phys_db].doc = "";
    submodule_data->features[dnx_data_dbal_table_support_mdb_general_phys_db].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_dbal_table_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dbal table defines");

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables].name = "nof_dynamic_tables";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_xml_tables].name = "nof_dynamic_xml_tables";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_xml_tables].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_xml_tables].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_labels].name = "nof_dynamic_tables_labels";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_labels].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_labels].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_key_fields].name = "nof_dynamic_tables_key_fields";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_key_fields].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_key_fields].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_result_fields].name = "nof_dynamic_tables_result_fields";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_result_fields].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_result_fields].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_multi_result_types].name = "nof_dynamic_tables_multi_result_types";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_multi_result_types].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_multi_result_types].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_ppmc_multi_result_types].name = "nof_dynamic_tables_ppmc_multi_result_types";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_ppmc_multi_result_types].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_tables_ppmc_multi_result_types].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_and_static_tables].name = "nof_dynamic_and_static_tables";
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_and_static_tables].doc = "";
    
    submodule_data->defines[dnx_data_dbal_table_define_nof_dynamic_and_static_tables].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_dbal_table_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dbal table tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dbal_table_feature_get(
    int unit,
    dnx_data_dbal_table_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, feature);
}


uint32
dnx_data_dbal_table_nof_dynamic_tables_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables);
}

uint32
dnx_data_dbal_table_nof_dynamic_xml_tables_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_xml_tables);
}

uint32
dnx_data_dbal_table_nof_dynamic_tables_labels_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables_labels);
}

uint32
dnx_data_dbal_table_nof_dynamic_tables_key_fields_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables_key_fields);
}

uint32
dnx_data_dbal_table_nof_dynamic_tables_result_fields_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables_result_fields);
}

uint32
dnx_data_dbal_table_nof_dynamic_tables_multi_result_types_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables_multi_result_types);
}

uint32
dnx_data_dbal_table_nof_dynamic_tables_ppmc_multi_result_types_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_tables_ppmc_multi_result_types);
}

uint32
dnx_data_dbal_table_nof_dynamic_and_static_tables_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_table, dnx_data_dbal_table_define_nof_dynamic_and_static_tables);
}










static shr_error_e
dnx_data_dbal_hw_ent_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "hw_ent";
    submodule_data->doc = "";
    
    submodule_data->nof_features = _dnx_data_dbal_hw_ent_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data dbal hw_ent features");

    
    submodule_data->nof_defines = _dnx_data_dbal_hw_ent_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data dbal hw_ent defines");

    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_direct_maps].name = "nof_direct_maps";
    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_direct_maps].doc = "";
    
    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_direct_maps].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_groups_maps].name = "nof_groups_maps";
    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_groups_maps].doc = "";
    
    submodule_data->defines[dnx_data_dbal_hw_ent_define_nof_groups_maps].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_dbal_hw_ent_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data dbal hw_ent tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_dbal_hw_ent_feature_get(
    int unit,
    dnx_data_dbal_hw_ent_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_hw_ent, feature);
}


uint32
dnx_data_dbal_hw_ent_nof_direct_maps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_hw_ent, dnx_data_dbal_hw_ent_define_nof_direct_maps);
}

uint32
dnx_data_dbal_hw_ent_nof_groups_maps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_dbal, dnx_data_dbal_submodule_hw_ent, dnx_data_dbal_hw_ent_define_nof_groups_maps);
}







shr_error_e
dnx_data_dbal_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "dbal";
    module_data->nof_submodules = _dnx_data_dbal_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data dbal submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_dbal_diag_init(unit, &module_data->submodules[dnx_data_dbal_submodule_diag]));
    SHR_IF_ERR_EXIT(dnx_data_dbal_db_init_init(unit, &module_data->submodules[dnx_data_dbal_submodule_db_init]));
    SHR_IF_ERR_EXIT(dnx_data_dbal_table_init(unit, &module_data->submodules[dnx_data_dbal_submodule_table]));
    SHR_IF_ERR_EXIT(dnx_data_dbal_hw_ent_init(unit, &module_data->submodules[dnx_data_dbal_submodule_hw_ent]));
    

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_dbal_attach(unit));
    }
    else


    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_dbal_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_dbal_attach(unit));
    }
    else

    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

