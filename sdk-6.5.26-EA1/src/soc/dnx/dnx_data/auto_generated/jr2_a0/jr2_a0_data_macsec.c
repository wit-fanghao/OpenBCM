
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_MACSEC

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_macsec.h>







static shr_error_e
jr2_a0_dnx_data_macsec_general_macsec_block_exists_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_macsec_block_exists;
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
jr2_a0_dnx_data_macsec_general_is_hw_reset_init_done_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_is_hw_reset_init_done_supported;
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
jr2_a0_dnx_data_macsec_general_an_full_range_supported_set(
    int unit)
{
    dnxc_data_feature_t *feature;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int feature_index = dnx_data_macsec_general_an_full_range_supported;
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
jr2_a0_dnx_data_macsec_general_macsec_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_macsec_general_macsec_in_core_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_macsec_in_core_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_macsec_general_ports_in_macsec_nof_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_ports_in_macsec_nof;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
jr2_a0_dnx_data_macsec_general_is_macsec_enabled_set(
    int unit)
{
    dnxc_data_define_t *define;
    int module_index = dnx_data_module_macsec;
    int submodule_index = dnx_data_macsec_submodule_general;
    int define_index = dnx_data_macsec_general_define_is_macsec_enabled;
    SHR_FUNC_INIT_VARS(unit);

    define = &_dnxc_data[unit].modules[module_index].submodules[submodule_index].defines[define_index];
    
    define->default_data = 0;

    
    define->data = 0;

    
    define->flags |= DNXC_DATA_F_SUPPORTED;

    
    SHR_IF_ERR_EXIT(dnxc_data_dyn_loader_define_value_set(unit, define));


exit:
    SHR_FUNC_EXIT;
}




shr_error_e
jr2_a0_data_macsec_attach(
    int unit)
{
    dnxc_data_module_t *module = NULL;
    dnxc_data_submodule_t *submodule = NULL;
    dnxc_data_define_t *define = NULL;
    dnxc_data_feature_t *feature = NULL;
    dnxc_data_table_t *table = NULL;
    int module_index = dnx_data_module_macsec;
    int submodule_index = -1, data_index = -1;
    SHR_FUNC_INIT_VARS(unit);

    COMPILER_REFERENCE(define);
    COMPILER_REFERENCE(feature);
    COMPILER_REFERENCE(table);
    COMPILER_REFERENCE(submodule);
    COMPILER_REFERENCE(data_index);
    COMPILER_REFERENCE(submodule_index);
    module = &_dnxc_data[unit].modules[module_index];
    
    submodule_index = dnx_data_macsec_submodule_general;
    submodule = &module->submodules[submodule_index];

    
    data_index = dnx_data_macsec_general_define_macsec_nof;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_macsec_general_macsec_nof_set;
    data_index = dnx_data_macsec_general_define_macsec_in_core_nof;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_macsec_general_macsec_in_core_nof_set;
    data_index = dnx_data_macsec_general_define_ports_in_macsec_nof;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_macsec_general_ports_in_macsec_nof_set;
    data_index = dnx_data_macsec_general_define_is_macsec_enabled;
    define = &submodule->defines[data_index];
    define->set = jr2_a0_dnx_data_macsec_general_is_macsec_enabled_set;

    
    data_index = dnx_data_macsec_general_macsec_block_exists;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_macsec_general_macsec_block_exists_set;
    data_index = dnx_data_macsec_general_is_hw_reset_init_done_supported;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_macsec_general_is_hw_reset_init_done_supported_set;
    data_index = dnx_data_macsec_general_an_full_range_supported;
    feature = &submodule->features[data_index];
    feature->set = jr2_a0_dnx_data_macsec_general_an_full_range_supported_set;

    

    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

