
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_L2

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_l2.h>







static shr_error_e
jr2_a0_dnx_data_l2_general_learning_use_insert_cmd_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_learning_use_insert_cmd;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_flush_machine_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_flush_machine_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_dynamic_entries_iteration_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_dynamic_entries_iteration_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_counters_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_counters_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_aging_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_aging_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_transplant_over_stronger_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_transplant_over_stronger_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_dma_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_dma_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_separate_fwd_learn_mact_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_separate_fwd_learn_mact;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_SLLB_v1_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_SLLB_v1_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_enhanced_learn_key_generation_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_enhanced_learn_key_generation;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_learn_payload_res_optimize_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int feature_index = dnx_data_l2_general_learn_payload_res_optimize;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_l2_general_vsi_offset_shift_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_vsi_offset_shift;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 70;

    
    define->data = 70;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_lif_offset_shift_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_lif_offset_shift;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = -74;

    
    define->data = -74;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_lem_nof_dbs_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_lem_nof_dbs;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_learn_limit_mode_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_learn_limit_mode;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_L2_LEARN_LIMIT_MODE;
    define->property.doc = 
        "MACT learn limit mode\n"
    ;
    define->property.method = dnxc_data_property_method_direct_map;
    define->property.method_str = "direct_map";
    define->property.nof_mapping = 3;
    DNXC_DATA_ALLOC(define->property.mapping, dnxc_data_property_map_t, define->property.nof_mapping, "dnxc_data property mapping");

    define->property.mapping[0].name = "VLAN";
    define->property.mapping[0].val = 0;
    define->property.mapping[0].is_default = 1 ;
    define->property.mapping[1].name = "VLAN_PORT";
    define->property.mapping[1].val = 1;
    define->property.mapping[2].name = "TUNNEL";
    define->property.mapping[2].val = 2;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_jr_mode_nof_fec_bits_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_jr_mode_nof_fec_bits;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 17;

    
    define->data = 17;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_arad_plus_mode_nof_fec_bits_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_arad_plus_mode_nof_fec_bits;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 15;

    
    define->data = 15;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_egress_max_extention_size_bytes_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_egress_max_extention_size_bytes;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 60;

    
    define->data = 60;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_egress_max_additional_termination_size_bytes_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_egress_max_additional_termination_size_bytes;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 192;

    
    define->data = 192;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_mact_mngmnt_fid_exceed_limit_int_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_mact_mngmnt_fid_exceed_limit_int;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1653;

    
    define->data = 1653;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_mact_lela_fid_exceed_limit_int_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_mact_lela_fid_exceed_limit_int;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1653;

    
    define->data = 1653;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_api_supported_flags2_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_api_supported_flags2;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = (BCM_L2_FLAGS2_AGE_GET | BCM_L2_FLAGS2_HIT_GET | BCM_L2_FLAGS2_NO_MOVE);

    
    define->data = (BCM_L2_FLAGS2_AGE_GET | BCM_L2_FLAGS2_HIT_GET | BCM_L2_FLAGS2_NO_MOVE);

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_traverse_api_supported_flags_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_traverse_api_supported_flags;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = (BCM_L2_TRAVERSE_MATCH_STATIC | BCM_L2_TRAVERSE_MATCH_MAC |              BCM_L2_TRAVERSE_MATCH_VLAN | BCM_L2_TRAVERSE_MATCH_DEST | BCM_L2_TRAVERSE_IGNORE_DES_HIT | BCM_L2_TRAVERSE_MATCH_GROUP |               BCM_L2_TRAVERSE_MATCH_IVL | BCM_L2_TRAVERSE_IGNORE_PENDING);

    
    define->data = (BCM_L2_TRAVERSE_MATCH_STATIC | BCM_L2_TRAVERSE_MATCH_MAC |              BCM_L2_TRAVERSE_MATCH_VLAN | BCM_L2_TRAVERSE_MATCH_DEST | BCM_L2_TRAVERSE_IGNORE_DES_HIT | BCM_L2_TRAVERSE_MATCH_GROUP |               BCM_L2_TRAVERSE_MATCH_IVL | BCM_L2_TRAVERSE_IGNORE_PENDING);

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_l2_delete_api_supported_flags_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int define_index = dnx_data_l2_general_define_l2_delete_api_supported_flags;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = (BCM_L2_DELETE_NO_CALLBACKS | BCM_L2_DELETE_STATIC | BCM_L2_DELETE_IVL);

    
    define->data = (BCM_L2_DELETE_NO_CALLBACKS | BCM_L2_DELETE_STATIC | BCM_L2_DELETE_IVL);

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_l2_general_mact_result_type_map_set(
    int unit)
{
    int forward_learning_db_index;
    int vlan_learning_mode_index;
    dnx_data_l2_general_mact_result_type_map_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int table_index = dnx_data_l2_general_table_mact_result_type_map;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 2;
    table->info_get.key_size[0] = 2;
    table->keys[1].size = 2;
    table->info_get.key_size[1] = 2;

    
    table->values[0].default_val = "0";
    table->values[1].default_val = "0";
    table->values[2].default_val = "0";
    table->values[3].default_val = "0";
    table->values[4].default_val = "0";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }
    if (table->keys[1].size == 0 || table->info_get.key_size[1] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_general_mact_result_type_map_t, (1 * (table->keys[0].size) * (table->keys[1].size) + 1  ), "data of dnx_data_l2_general_table_mact_result_type_map");

    
    default_data = (dnx_data_l2_general_mact_result_type_map_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->dest_lif_stat = 0;
    default_data->dest_stat = 0;
    default_data->eei = 0;
    default_data->no_outlif = 0;
    default_data->single_outlif = 0;
    
    for (forward_learning_db_index = 0; forward_learning_db_index < table->keys[0].size; forward_learning_db_index++)
    {
        for (vlan_learning_mode_index = 0; vlan_learning_mode_index < table->keys[1].size; vlan_learning_mode_index++)
        {
            data = (dnx_data_l2_general_mact_result_type_map_t *) dnxc_data_mgmt_table_data_get(unit, table, forward_learning_db_index, vlan_learning_mode_index);
            sal_memcpy(data, default_data, table->size_of_values);
        }
    }
    
    if ((uint8)l2ActionTypeFwdAndNA < table->keys[0].size && (uint8)l2AddrMactSvl < table->keys[1].size)
    {
        data = (dnx_data_l2_general_mact_result_type_map_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeFwdAndNA, (uint8)l2AddrMactSvl);
        data->dest_lif_stat = DBAL_RESULT_TYPE_FWD_MACT_FWD_MACT_RESULT_DEST_LIF_STAT;
        data->dest_stat = DBAL_RESULT_TYPE_FWD_MACT_FWD_MACT_RESULT_DEST_STAT;
        data->eei = DBAL_RESULT_TYPE_FWD_MACT_FWD_MACT_RESULT_EEI_FEC;
        data->no_outlif = DBAL_RESULT_TYPE_FWD_MACT_FWD_MACT_RESULT_NO_OUTLIF;
        data->single_outlif = DBAL_RESULT_TYPE_FWD_MACT_FWD_MACT_RESULT_SINGLE_OUTLIF;
    }
    if ((uint8)l2ActionTypeFwdAndNA < table->keys[0].size && (uint8)l2AddrMactIvl < table->keys[1].size)
    {
        data = (dnx_data_l2_general_mact_result_type_map_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeFwdAndNA, (uint8)l2AddrMactIvl);
        data->dest_lif_stat = DBAL_RESULT_TYPE_FWD_MACT_IVL_FWD_MACT_RESULT_DEST_LIF_STAT;
        data->dest_stat = DBAL_RESULT_TYPE_FWD_MACT_IVL_FWD_MACT_RESULT_DEST_STAT;
        data->eei = DBAL_RESULT_TYPE_FWD_MACT_IVL_FWD_MACT_RESULT_EEI_FEC;
        data->no_outlif = DBAL_RESULT_TYPE_FWD_MACT_IVL_FWD_MACT_RESULT_NO_OUTLIF;
        data->single_outlif = DBAL_RESULT_TYPE_FWD_MACT_IVL_FWD_MACT_RESULT_SINGLE_OUTLIF;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_scan_data_bases_info_set(
    int unit)
{
    int data_base_index;
    dnx_data_l2_general_scan_data_bases_info_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int table_index = dnx_data_l2_general_table_scan_data_bases_info;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 1;
    table->info_get.key_size[0] = 1;

    
    table->values[0].default_val = "DBAL_TABLE_EMPTY";
    table->values[1].default_val = "DBAL_TABLE_EMPTY";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_general_scan_data_bases_info_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_l2_general_table_scan_data_bases_info");

    
    default_data = (dnx_data_l2_general_scan_data_bases_info_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->age_scan = DBAL_TABLE_EMPTY;
    default_data->scan_cycles = DBAL_TABLE_EMPTY;
    
    for (data_base_index = 0; data_base_index < table->keys[0].size; data_base_index++)
    {
        data = (dnx_data_l2_general_scan_data_bases_info_t *) dnxc_data_mgmt_table_data_get(unit, table, data_base_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if (0 < table->keys[0].size)
    {
        data = (dnx_data_l2_general_scan_data_bases_info_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
        data->age_scan = DBAL_TABLE_MDB_33_LEM;
        data->scan_cycles = DBAL_TABLE_MDB_22_LEM;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_fwd_mact_info_set(
    int unit)
{
    int l2_action_type_index;
    int is_ivl_index;
    dnx_data_l2_general_fwd_mact_info_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int table_index = dnx_data_l2_general_table_fwd_mact_info;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 2;
    table->info_get.key_size[0] = 2;
    table->keys[1].size = 2;
    table->info_get.key_size[1] = 2;

    
    table->values[0].default_val = "DBAL_TABLE_EMPTY";
    table->values[1].default_val = "DBAL_PHYSICAL_TABLE_NONE";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }
    if (table->keys[1].size == 0 || table->info_get.key_size[1] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_general_fwd_mact_info_t, (1 * (table->keys[0].size) * (table->keys[1].size) + 1  ), "data of dnx_data_l2_general_table_fwd_mact_info");

    
    default_data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->logical_data_base = DBAL_TABLE_EMPTY;
    default_data->physical_data_base = DBAL_PHYSICAL_TABLE_NONE;
    
    for (l2_action_type_index = 0; l2_action_type_index < table->keys[0].size; l2_action_type_index++)
    {
        for (is_ivl_index = 0; is_ivl_index < table->keys[1].size; is_ivl_index++)
        {
            data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, l2_action_type_index, is_ivl_index);
            sal_memcpy(data, default_data, table->size_of_values);
        }
    }
    
    if ((uint8)l2ActionTypeFwdAndNA < table->keys[0].size && 0 < table->keys[1].size)
    {
        data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeFwdAndNA, 0);
        data->logical_data_base = DBAL_TABLE_FWD_MACT;
        data->physical_data_base = DBAL_PHYSICAL_TABLE_LEM;
    }
    if ((uint8)l2ActionTypeLearn < table->keys[0].size && 0 < table->keys[1].size)
    {
        data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeLearn, 0);
        data->logical_data_base = DBAL_TABLE_FWD_MACT;
        data->physical_data_base = DBAL_PHYSICAL_TABLE_LEM;
    }
    if ((uint8)l2ActionTypeFwdAndNA < table->keys[0].size && 1 < table->keys[1].size)
    {
        data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeFwdAndNA, 1);
        data->logical_data_base = DBAL_TABLE_FWD_MACT_IVL;
        data->physical_data_base = DBAL_PHYSICAL_TABLE_LEM;
    }
    if ((uint8)l2ActionTypeLearn < table->keys[0].size && 1 < table->keys[1].size)
    {
        data = (dnx_data_l2_general_fwd_mact_info_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeLearn, 1);
        data->logical_data_base = DBAL_TABLE_FWD_MACT_IVL;
        data->physical_data_base = DBAL_PHYSICAL_TABLE_LEM;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_general_lem_table_map_l2_action_set(
    int unit)
{
    int logical_data_base_index;
    dnx_data_l2_general_lem_table_map_l2_action_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_general;
    int table_index = dnx_data_l2_general_table_lem_table_map_l2_action;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = DBAL_NOF_TABLES;
    table->info_get.key_size[0] = DBAL_NOF_TABLES;

    
    table->values[0].default_val = "0";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_general_lem_table_map_l2_action_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_l2_general_table_lem_table_map_l2_action");

    
    default_data = (dnx_data_l2_general_lem_table_map_l2_action_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->l2_action_type = 0;
    
    for (logical_data_base_index = 0; logical_data_base_index < table->keys[0].size; logical_data_base_index++)
    {
        data = (dnx_data_l2_general_lem_table_map_l2_action_t *) dnxc_data_mgmt_table_data_get(unit, table, logical_data_base_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if (DBAL_TABLE_FWD_MACT < table->keys[0].size)
    {
        data = (dnx_data_l2_general_lem_table_map_l2_action_t *) dnxc_data_mgmt_table_data_get(unit, table, DBAL_TABLE_FWD_MACT, 0);
        data->l2_action_type = l2ActionTypeFwdAndNA;
    }
    if (DBAL_TABLE_FWD_MACT_IVL < table->keys[0].size)
    {
        data = (dnx_data_l2_general_lem_table_map_l2_action_t *) dnxc_data_mgmt_table_data_get(unit, table, DBAL_TABLE_FWD_MACT_IVL, 0);
        data->l2_action_type = l2ActionTypeFwdAndNA;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}





static shr_error_e
jr2_a0_dnx_data_l2_feature_age_out_and_refresh_profile_selection_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_out_and_refresh_profile_selection;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_age_machine_pause_after_flush_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_machine_pause_after_flush;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_age_state_not_updated_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_state_not_updated;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_appdb_id_for_olp_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_appdb_id_for_olp;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_eth_qual_is_mc_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_eth_qual_is_mc;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_bc_same_as_unknown_mc_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_bc_same_as_unknown_mc;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_fid_mgmt_ecc_error_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_fid_mgmt_ecc_error;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_wrong_limit_interrupt_handling_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_wrong_limit_interrupt_handling;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_transplant_instead_of_refresh_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_transplant_instead_of_refresh;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_static_mac_age_out_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_static_mac_age_out;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_vmv_for_limit_in_wrong_location_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_vmv_for_limit_in_wrong_location;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_learn_limit_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_limit;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_limit_per_lif_counters_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_limit_per_lif_counters;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;
    
    feature->property.name = spn_L2_LEARN_LIMIT_MODE;
    feature->property.doc = NULL;
    feature->property.method = dnxc_data_property_method_direct_map;
    feature->property.method_str = "direct_map";
    feature->property.nof_mapping = 3;
    DNXC_DATA_ALLOC(feature->property.mapping , dnxc_data_property_map_t, feature->property.nof_mapping, "limit_per_lif_counters property mapping");

    feature->property.mapping[0].name = "VLAN";
    feature->property.mapping[0].val = 0;
    feature->property.mapping[0].is_default = 1 ;
    feature->property.mapping[1].name = "VLAN_PORT";
    feature->property.mapping[1].val = 1;
    feature->property.mapping[2].name = "TUNNEL";
    feature->property.mapping[2].val = 0;
    feature->property.mapping[2].is_default = 1 ;
    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &feature->property, -1, &feature->data));
    
    feature->flags |= (DNXC_DATA_F_PROPERTY);


    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_learn_events_wrong_command_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_events_wrong_command;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_opportunistic_learning_always_transplant_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_opportunistic_learning_always_transplant;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_exceed_limit_interrupt_by_insert_cmd_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_exceed_limit_interrupt_by_insert_cmd;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_refresh_events_wrong_key_msbs_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_refresh_events_wrong_key_msbs;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_ignore_limit_check_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_ignore_limit_check;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_no_trap_for_unknown_destination_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_no_trap_for_unknown_destination;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_mact_access_by_opportunistic_learning_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_mact_access_by_opportunistic_learning;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_opportunistic_rejected_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_opportunistic_rejected;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_flush_drop_stuck_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_flush_drop_stuck;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_lif_flood_profile_always_update_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_lif_flood_profile_always_update;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_olp_always_enters_source_cpu_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_olp_always_enters_source_cpu;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_learn_payload_compatible_jr1_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_payload_compatible_jr1;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_ingress_opportunistic_learning_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_ingress_opportunistic_learning_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_age_refresh_mode_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_age_refresh_mode_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_feature_learn_payload_native_update_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_feature;
    int feature_index = dnx_data_l2_feature_learn_payload_native_update_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 0;

    
    feature->data = 0;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}








static shr_error_e
jr2_a0_dnx_data_l2_vsi_nof_vsi_aging_profiles_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vsi;
    int define_index = dnx_data_l2_vsi_define_nof_vsi_aging_profiles;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 32;

    
    define->data = 32;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_vsi_nof_event_forwarding_profiles_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vsi;
    int define_index = dnx_data_l2_vsi_define_nof_event_forwarding_profiles;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_vsi_nof_vsi_learning_profiles_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vsi;
    int define_index = dnx_data_l2_vsi_define_nof_vsi_learning_profiles;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 32;

    
    define->data = 32;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_vsi_vsi_table_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vsi;
    int define_index = dnx_data_l2_vsi_define_vsi_table;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = DBAL_TABLE_ING_VSI_INFO_DB;

    
    define->data = DBAL_TABLE_ING_VSI_INFO_DB;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}







static shr_error_e
jr2_a0_dnx_data_l2_vlan_domain_nof_vlan_domains_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vlan_domain;
    int define_index = dnx_data_l2_vlan_domain_define_nof_vlan_domains;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 512;

    
    define->data = 512;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_vlan_domain_nof_bits_next_layer_network_domain_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_vlan_domain;
    int define_index = dnx_data_l2_vlan_domain_define_nof_bits_next_layer_network_domain;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 9;

    
    define->data = 9;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}







static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_nof_dma_entries_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_nof_dma_entries;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 128;

    
    define->data = 128;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_db_nof_dma_rules_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_db_nof_dma_rules;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 16;

    
    define->data = 16;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_db_nof_dma_rules_per_table_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_db_nof_dma_rules_per_table;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 8;

    
    define->data = 8;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_db_rule_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_db_rule_size;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 67;

    
    define->data = 67;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_db_data_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_db_data_size;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 25;

    
    define->data = 25;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_flush_group_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_flush_group_size;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_learning_fifo_dma_buffer_size_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_learning_fifo_dma_buffer_size;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 200000;

    
    define->data = 200000;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_LEARNING_FIFO_DMA_BUFFER_SIZE;
    define->property.doc = 
        "\n"
        "Configure the size of the host memory in bytes.\n"
        "The valid range of memory size is 20-327680 bytes.\n"
        "learning_fifo_dma_buffer_size=20-327680\n"
        "Default: 200000\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = 20;
    define->property.range_max = 327680;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_learning_fifo_dma_timeout_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_learning_fifo_dma_timeout;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 32767;

    
    define->data = 32767;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_LEARNING_FIFO_DMA_TIMEOUT;
    define->property.doc = 
        "\n"
        "Configures the learning fifo dma timeout in microseconds.\n"
        "The valid range is 0-65535.\n"
        "learning_fifo_dma_timeout=0-65535\n"
        "Default: 32767\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = 0;
    define->property.range_max = 65535;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_learning_fifo_dma_threshold_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_learning_fifo_dma_threshold;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 4;

    
    define->data = 4;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_LEARNING_FIFO_DMA_THRESHOLD;
    define->property.doc = 
        "\n"
        "Configures the learning fifo dma threshold.\n"
        "The valid range is 1-16384.\n"
        "learning_fifo_dma_threshold=1-16384\n"
        "Default: 4\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = 1;
    define->property.range_max = 16384;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_dma_l2_dma_cpu_learn_thread_priority_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_dma;
    int define_index = dnx_data_l2_dma_define_l2_dma_cpu_learn_thread_priority;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 50;

    
    define->data = 50;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_L2_DMA_CPU_LEARN_THREAD_PRIORITY;
    define->property.doc = 
        "\n"
        "Configures the cpu learning dedicated thread's priority.\n"
        "The valid range is 0-0xFFFF.\n"
        "l2_dma_cpu_learn_thread_priority=0-0xFFFF\n"
        "Default: 50\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = 0;
    define->property.range_max = 0xFFFF;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}






static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_flush_init_enable_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int feature_index = dnx_data_l2_age_and_flush_machine_flush_init_enable;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_max_age_states_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int define_index = dnx_data_l2_age_and_flush_machine_define_max_age_states;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 8;

    
    define->data = 8;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_flush_buffer_nof_entries_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int define_index = dnx_data_l2_age_and_flush_machine_define_flush_buffer_nof_entries;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = -1;

    
    define->data = -1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_L2_FLUSH_BUFFER_NOF_ENTRIES;
    define->property.doc = 
        "Size of flush buffer in number of entries.\n"
        "If value > 127, it will be used to indicate the size of the buffer (in nof entries).\n"
        "If value = -1, max nof MACT entries according to MDB profile.\n"
        "value = 0-127, invalid.\n"
        "\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = dnx_data_l2.dma.flush_nof_dma_entries_get(unit);
    define->property.range_max = 0xFFFFFFFF;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_traverse_thread_priority_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int define_index = dnx_data_l2_age_and_flush_machine_define_traverse_thread_priority;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 50;

    
    define->data = 50;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;
    
    define->property.name = spn_L2_FLUSH_TRAVERSE_THREAD_PRIORITY;
    define->property.doc = 
        "L2 flush match traverse non-blocking thread priority\n"
    ;
    define->property.method = dnxc_data_property_method_range;
    define->property.method_str = "range";
    define->property.range_min = 0;
    define->property.range_max = 0xFFFF;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));

    SHR_IF_ERR_EXIT(dnxc_data_mgmt_property_read(unit, &define->property, -1, &define->data));
    
    define->flags |= (DNXC_DATA_F_PROPERTY);

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_flush_pulse_set(
    int unit)
{
    int l2_action_type_index;
    dnx_data_l2_age_and_flush_machine_flush_pulse_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int table_index = dnx_data_l2_age_and_flush_machine_table_flush_pulse;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->keys[0].size = 1;
    table->info_get.key_size[0] = 1;

    
    table->values[0].default_val = "INVALIDr";
    
    if (table->keys[0].size == 0 || table->info_get.key_size[0] == 0)
    {
        SHR_EXIT();
    }

    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_age_and_flush_machine_flush_pulse_t, (1 * (table->keys[0].size) + 1  ), "data of dnx_data_l2_age_and_flush_machine_table_flush_pulse");

    
    default_data = (dnx_data_l2_age_and_flush_machine_flush_pulse_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->flush_pulse_reg = INVALIDr;
    
    for (l2_action_type_index = 0; l2_action_type_index < table->keys[0].size; l2_action_type_index++)
    {
        data = (dnx_data_l2_age_and_flush_machine_flush_pulse_t *) dnxc_data_mgmt_table_data_get(unit, table, l2_action_type_index, 0);
        sal_memcpy(data, default_data, table->size_of_values);
    }
    
    if ((uint8)l2ActionTypeFwdAndNA < table->keys[0].size)
    {
        data = (dnx_data_l2_age_and_flush_machine_flush_pulse_t *) dnxc_data_mgmt_table_data_get(unit, table, (uint8)l2ActionTypeFwdAndNA, 0);
        data->flush_pulse_reg = MDB_REG_3021r;
    }

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_age_and_flush_machine_age_set(
    int unit)
{
    dnx_data_l2_age_and_flush_machine_age_t *data, *default_data;
    dnxc_data_table_t *table;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    int table_index = dnx_data_l2_age_and_flush_machine_table_age;
    SHR_FUNC_INIT_VARS(unit);

    table = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].tables[table_index];
    
    table->flags |= DNXC_DATA_F_SUPPORTED;

    
    table->values[0].default_val = "MDB_REG_181r";
    table->values[1].default_val = "ITEM_360_367f";
    table->values[2].default_val = "MDB_REG_3020r";
    
    DNXC_DATA_ALLOC(table->data, dnx_data_l2_age_and_flush_machine_age_t, (1 + 1  ), "data of dnx_data_l2_age_and_flush_machine_table_age");

    
    default_data = (dnx_data_l2_age_and_flush_machine_age_t *) dnxc_data_mgmt_table_data_get(unit, table, -1, -1);
    default_data->age_config = MDB_REG_181r;
    default_data->disable_aging = ITEM_360_367f;
    default_data->scan_pulse = MDB_REG_3020r;
    
    data = (dnx_data_l2_age_and_flush_machine_age_t *) dnxc_data_mgmt_table_data_get(unit, table, 0, 0);
    sal_memcpy(data, default_data, table->size_of_values);

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_table_value_set(unit, table));


exit:
    SHR_FUNC_EXIT;
}





static shr_error_e
jr2_a0_dnx_data_l2_olp_refresh_events_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int feature_index = dnx_data_l2_olp_refresh_events_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_olp_learn_payload_initial_value_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int feature_index = dnx_data_l2_olp_olp_learn_payload_initial_value_supported;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_dsp_messages_support_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int feature_index = dnx_data_l2_olp_dsp_messages_support;
    SHR_FUNC_INIT_VARS(unit);

    feature = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].features[feature_index];
    
    feature->default_data = 1;

    
    feature->data = 1;

    
    feature->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_feature_value_set(unit, feature));

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e
jr2_a0_dnx_data_l2_olp_lpkgv_shift_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_lpkgv_shift;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 26;

    
    define->data = 26;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_lpkgv_mask_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_lpkgv_mask;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0x3f;

    
    define->data = 0x3f;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_lpkgv_with_outlif_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_lpkgv_with_outlif;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0x20;

    
    define->data = 0x20;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_lpkgv_wo_outlif_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_lpkgv_wo_outlif;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0x30;

    
    define->data = 0x30;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_destination_offset_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_destination_offset;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 37;

    
    define->data = 37;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_outlif_offset_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_outlif_offset;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 8;

    
    define->data = 8;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_eei_offset_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_eei_offset;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 6;

    
    define->data = 6;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_fec_offset_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_fec_offset;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 37;

    
    define->data = 37;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_l2_olp_jr_mode_enhanced_performance_enable_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_l2;
    int submodule_index = dnx_data_l2_submodule_olp;
    int define_index = dnx_data_l2_olp_define_jr_mode_enhanced_performance_enable;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 1;

    
    define->data = 1;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}




shr_error_e
jr2_a0_data_l2_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_l2;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_l2_submodule_general;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_general_define_vsi_offset_shift;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_vsi_offset_shift_set;
    data_index = dnx_data_l2_general_define_lif_offset_shift;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_lif_offset_shift_set;
    data_index = dnx_data_l2_general_define_lem_nof_dbs;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_lem_nof_dbs_set;
    data_index = dnx_data_l2_general_define_l2_learn_limit_mode;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_learn_limit_mode_set;
    data_index = dnx_data_l2_general_define_jr_mode_nof_fec_bits;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_jr_mode_nof_fec_bits_set;
    data_index = dnx_data_l2_general_define_arad_plus_mode_nof_fec_bits;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_arad_plus_mode_nof_fec_bits_set;
    data_index = dnx_data_l2_general_define_l2_egress_max_extention_size_bytes;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_egress_max_extention_size_bytes_set;
    data_index = dnx_data_l2_general_define_l2_egress_max_additional_termination_size_bytes;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_egress_max_additional_termination_size_bytes_set;
    data_index = dnx_data_l2_general_define_mact_mngmnt_fid_exceed_limit_int;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_mact_mngmnt_fid_exceed_limit_int_set;
    data_index = dnx_data_l2_general_define_mact_lela_fid_exceed_limit_int;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_mact_lela_fid_exceed_limit_int_set;
    data_index = dnx_data_l2_general_define_l2_api_supported_flags2;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_api_supported_flags2_set;
    data_index = dnx_data_l2_general_define_l2_traverse_api_supported_flags;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_traverse_api_supported_flags_set;
    data_index = dnx_data_l2_general_define_l2_delete_api_supported_flags;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_general_l2_delete_api_supported_flags_set;

    
    data_index = dnx_data_l2_general_learning_use_insert_cmd;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_learning_use_insert_cmd_set;
    data_index = dnx_data_l2_general_flush_machine_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_flush_machine_support_set;
    data_index = dnx_data_l2_general_dynamic_entries_iteration_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_dynamic_entries_iteration_support_set;
    data_index = dnx_data_l2_general_counters_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_counters_support_set;
    data_index = dnx_data_l2_general_aging_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_aging_support_set;
    data_index = dnx_data_l2_general_transplant_over_stronger_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_transplant_over_stronger_support_set;
    data_index = dnx_data_l2_general_dma_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_dma_support_set;
    data_index = dnx_data_l2_general_separate_fwd_learn_mact;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_separate_fwd_learn_mact_set;
    data_index = dnx_data_l2_general_SLLB_v1_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_SLLB_v1_support_set;
    data_index = dnx_data_l2_general_enhanced_learn_key_generation;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_enhanced_learn_key_generation_set;
    data_index = dnx_data_l2_general_learn_payload_res_optimize;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_general_learn_payload_res_optimize_set;

    
    data_index = dnx_data_l2_general_table_mact_result_type_map;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_general_mact_result_type_map_set;
    data_index = dnx_data_l2_general_table_scan_data_bases_info;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_general_scan_data_bases_info_set;
    data_index = dnx_data_l2_general_table_fwd_mact_info;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_general_fwd_mact_info_set;
    data_index = dnx_data_l2_general_table_lem_table_map_l2_action;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_general_lem_table_map_l2_action_set;
    
    submodule_index = dnx_data_l2_submodule_feature;
    submodule = &module->submodules[submodule_index];

    

    
    data_index = dnx_data_l2_feature_age_out_and_refresh_profile_selection;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_age_out_and_refresh_profile_selection_set;
    data_index = dnx_data_l2_feature_age_machine_pause_after_flush;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_age_machine_pause_after_flush_set;
    data_index = dnx_data_l2_feature_age_state_not_updated;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_age_state_not_updated_set;
    data_index = dnx_data_l2_feature_appdb_id_for_olp;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_appdb_id_for_olp_set;
    data_index = dnx_data_l2_feature_eth_qual_is_mc;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_eth_qual_is_mc_set;
    data_index = dnx_data_l2_feature_bc_same_as_unknown_mc;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_bc_same_as_unknown_mc_set;
    data_index = dnx_data_l2_feature_fid_mgmt_ecc_error;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_fid_mgmt_ecc_error_set;
    data_index = dnx_data_l2_feature_wrong_limit_interrupt_handling;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_wrong_limit_interrupt_handling_set;
    data_index = dnx_data_l2_feature_transplant_instead_of_refresh;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_transplant_instead_of_refresh_set;
    data_index = dnx_data_l2_feature_static_mac_age_out;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_static_mac_age_out_set;
    data_index = dnx_data_l2_feature_vmv_for_limit_in_wrong_location;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_vmv_for_limit_in_wrong_location_set;
    data_index = dnx_data_l2_feature_learn_limit;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_learn_limit_set;
    data_index = dnx_data_l2_feature_limit_per_lif_counters;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_limit_per_lif_counters_set;
    data_index = dnx_data_l2_feature_learn_events_wrong_command;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_learn_events_wrong_command_set;
    data_index = dnx_data_l2_feature_opportunistic_learning_always_transplant;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_opportunistic_learning_always_transplant_set;
    data_index = dnx_data_l2_feature_exceed_limit_interrupt_by_insert_cmd;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_exceed_limit_interrupt_by_insert_cmd_set;
    data_index = dnx_data_l2_feature_refresh_events_wrong_key_msbs;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_refresh_events_wrong_key_msbs_set;
    data_index = dnx_data_l2_feature_ignore_limit_check;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_ignore_limit_check_set;
    data_index = dnx_data_l2_feature_no_trap_for_unknown_destination;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_no_trap_for_unknown_destination_set;
    data_index = dnx_data_l2_feature_mact_access_by_opportunistic_learning;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_mact_access_by_opportunistic_learning_set;
    data_index = dnx_data_l2_feature_opportunistic_rejected;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_opportunistic_rejected_set;
    data_index = dnx_data_l2_feature_flush_drop_stuck;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_flush_drop_stuck_set;
    data_index = dnx_data_l2_feature_lif_flood_profile_always_update;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_lif_flood_profile_always_update_set;
    data_index = dnx_data_l2_feature_olp_always_enters_source_cpu;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_olp_always_enters_source_cpu_set;
    data_index = dnx_data_l2_feature_learn_payload_compatible_jr1;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_learn_payload_compatible_jr1_set;
    data_index = dnx_data_l2_feature_ingress_opportunistic_learning_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_ingress_opportunistic_learning_support_set;
    data_index = dnx_data_l2_feature_age_refresh_mode_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_age_refresh_mode_support_set;
    data_index = dnx_data_l2_feature_learn_payload_native_update_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_feature_learn_payload_native_update_enable_set;

    
    
    submodule_index = dnx_data_l2_submodule_vsi;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_vsi_define_nof_vsi_aging_profiles;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vsi_nof_vsi_aging_profiles_set;
    data_index = dnx_data_l2_vsi_define_nof_event_forwarding_profiles;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vsi_nof_event_forwarding_profiles_set;
    data_index = dnx_data_l2_vsi_define_nof_vsi_learning_profiles;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vsi_nof_vsi_learning_profiles_set;
    data_index = dnx_data_l2_vsi_define_vsi_table;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vsi_vsi_table_set;

    

    
    
    submodule_index = dnx_data_l2_submodule_vlan_domain;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_vlan_domain_define_nof_vlan_domains;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vlan_domain_nof_vlan_domains_set;
    data_index = dnx_data_l2_vlan_domain_define_nof_bits_next_layer_network_domain;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_vlan_domain_nof_bits_next_layer_network_domain_set;

    

    
    
    submodule_index = dnx_data_l2_submodule_dma;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_dma_define_flush_nof_dma_entries;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_nof_dma_entries_set;
    data_index = dnx_data_l2_dma_define_flush_db_nof_dma_rules;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_db_nof_dma_rules_set;
    data_index = dnx_data_l2_dma_define_flush_db_nof_dma_rules_per_table;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_db_nof_dma_rules_per_table_set;
    data_index = dnx_data_l2_dma_define_flush_db_rule_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_db_rule_size_set;
    data_index = dnx_data_l2_dma_define_flush_db_data_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_db_data_size_set;
    data_index = dnx_data_l2_dma_define_flush_group_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_flush_group_size_set;
    data_index = dnx_data_l2_dma_define_learning_fifo_dma_buffer_size;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_learning_fifo_dma_buffer_size_set;
    data_index = dnx_data_l2_dma_define_learning_fifo_dma_timeout;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_learning_fifo_dma_timeout_set;
    data_index = dnx_data_l2_dma_define_learning_fifo_dma_threshold;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_learning_fifo_dma_threshold_set;
    data_index = dnx_data_l2_dma_define_l2_dma_cpu_learn_thread_priority;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_dma_l2_dma_cpu_learn_thread_priority_set;

    

    
    
    submodule_index = dnx_data_l2_submodule_age_and_flush_machine;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_age_and_flush_machine_define_max_age_states;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_age_and_flush_machine_max_age_states_set;
    data_index = dnx_data_l2_age_and_flush_machine_define_flush_buffer_nof_entries;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_age_and_flush_machine_flush_buffer_nof_entries_set;
    data_index = dnx_data_l2_age_and_flush_machine_define_traverse_thread_priority;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_age_and_flush_machine_traverse_thread_priority_set;

    
    data_index = dnx_data_l2_age_and_flush_machine_flush_init_enable;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_age_and_flush_machine_flush_init_enable_set;

    
    data_index = dnx_data_l2_age_and_flush_machine_table_flush_pulse;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_age_and_flush_machine_flush_pulse_set;
    data_index = dnx_data_l2_age_and_flush_machine_table_age;
    table = &submodule->tables[data_index];
    table->set = jr2_a0_dnx_data_l2_age_and_flush_machine_age_set;
    
    submodule_index = dnx_data_l2_submodule_olp;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_l2_olp_define_lpkgv_shift;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_lpkgv_shift_set;
    data_index = dnx_data_l2_olp_define_lpkgv_mask;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_lpkgv_mask_set;
    data_index = dnx_data_l2_olp_define_lpkgv_with_outlif;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_lpkgv_with_outlif_set;
    data_index = dnx_data_l2_olp_define_lpkgv_wo_outlif;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_lpkgv_wo_outlif_set;
    data_index = dnx_data_l2_olp_define_destination_offset;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_destination_offset_set;
    data_index = dnx_data_l2_olp_define_outlif_offset;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_outlif_offset_set;
    data_index = dnx_data_l2_olp_define_eei_offset;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_eei_offset_set;
    data_index = dnx_data_l2_olp_define_fec_offset;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_fec_offset_set;
    data_index = dnx_data_l2_olp_define_jr_mode_enhanced_performance_enable;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_l2_olp_jr_mode_enhanced_performance_enable_set;

    
    data_index = dnx_data_l2_olp_refresh_events_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_olp_refresh_events_support_set;
    data_index = dnx_data_l2_olp_olp_learn_payload_initial_value_supported;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_olp_olp_learn_payload_initial_value_supported_set;
    data_index = dnx_data_l2_olp_dsp_messages_support;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_l2_olp_dsp_messages_support_set;

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

