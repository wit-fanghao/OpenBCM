
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_UTILS

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_consistent_hashing.h>



#ifdef BCM_DNX2_SUPPORT

extern shr_error_e jr2_a0_data_consistent_hashing_attach(
    int unit);

#endif 



static shr_error_e
dnx_data_consistent_hashing_calendar_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "calendar";
    submodule_data->doc = "consistent hashing calendar parameters";
    
    submodule_data->nof_features = _dnx_data_consistent_hashing_calendar_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data consistent_hashing calendar features");

    
    submodule_data->nof_defines = _dnx_data_consistent_hashing_calendar_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data consistent_hashing calendar defines");

    submodule_data->defines[dnx_data_consistent_hashing_calendar_define_max_nof_entries_in_calendar].name = "max_nof_entries_in_calendar";
    submodule_data->defines[dnx_data_consistent_hashing_calendar_define_max_nof_entries_in_calendar].doc = "the maximal number of entries in the consistent hashing calendar";
    
    submodule_data->defines[dnx_data_consistent_hashing_calendar_define_max_nof_entries_in_calendar].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_consistent_hashing_calendar_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data consistent_hashing calendar tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_consistent_hashing_calendar_feature_get(
    int unit,
    dnx_data_consistent_hashing_calendar_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_consistent_hashing, dnx_data_consistent_hashing_submodule_calendar, feature);
}


uint32
dnx_data_consistent_hashing_calendar_max_nof_entries_in_calendar_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_consistent_hashing, dnx_data_consistent_hashing_submodule_calendar, dnx_data_consistent_hashing_calendar_define_max_nof_entries_in_calendar);
}







shr_error_e
dnx_data_consistent_hashing_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "consistent_hashing";
    module_data->nof_submodules = _dnx_data_consistent_hashing_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data consistent_hashing submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_consistent_hashing_calendar_init(unit, &module_data->submodules[dnx_data_consistent_hashing_submodule_calendar]));
    
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_consistent_hashing_attach(unit));
    }
    else

#endif 
    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

