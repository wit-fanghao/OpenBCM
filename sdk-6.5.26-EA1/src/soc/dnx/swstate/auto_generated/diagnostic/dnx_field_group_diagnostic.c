
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SWSTATEDNX_GENERAL

#include <soc/dnx/swstate/auto_generated/diagnostic/dnx_field_group_diagnostic.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_field_group_access.h>
#include <soc/dnx/swstate/auto_generated/layout/dnx_field_group_layout.h>
#if defined(DNX_SW_STATE_DIAGNOSTIC)


extern dnx_field_group_sw_t * dnx_field_group_sw_data[SOC_MAX_NUM_DEVICES];



int
dnx_field_group_sw_dump(int  unit,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_dump(unit, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_dump(unit, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_field_stage_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_fg_type_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_name_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_dump(unit, fg_info_idx_0, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_length_type_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_action_length_type_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_actions_payload_info_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_dbal_table_id_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_flags_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_dump(unit, fg_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_field_stage_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_stage_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info field_stage") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info field_stage\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/field_stage.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].field_stage: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FIELD_STAGE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FIELD_STAGE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].field_stage: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FIELD_STAGE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].field_stage: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_stage_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].field_stage));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_fg_type_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_group_type_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info fg_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info fg_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/fg_type.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].fg_type: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FG_TYPE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FG_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].fg_type: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FG_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].fg_type: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_group_type_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].fg_type));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_name_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_name_value_dump(unit, fg_info_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_name_value_dump(int  unit,  int  fg_info_idx_0,  int  value_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = value_idx_0, I1 = value_idx_0 + 1, org_i1 = value_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "char") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info name value") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info name value\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/name/value.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].name.value[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__NAME__VALUE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__NAME__VALUE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].name.value[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__NAME__VALUE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DBAL_MAX_STRING_LENGTH;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].name.value
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].name.value), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DBAL_MAX_STRING_LENGTH)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].name.value[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DBAL_MAX_STRING_LENGTH == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].name.value[%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_char(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].name.value[i1]);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_key_id_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_qual_attach_info_dump(unit, fg_info_idx_0, context_info_idx_0, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_context_info_valid_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_nof_cascading_refs_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_payload_offset_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_payload_id_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_flags_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_key_id_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_key_id_id_dump(unit, fg_info_idx_0, context_info_idx_0, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_key_id_offset_on_first_key_dump(unit, fg_info_idx_0, context_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_key_id_nof_bits_dump(unit, fg_info_idx_0, context_info_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_key_id_id_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  id_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = id_idx_0, I2 = id_idx_0 + 1, org_i2 = id_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dbal_enum_value_field_field_key_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info key_id id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info key_id id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/key_id/id.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].key_id.id[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__ID,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.id[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.id[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.id
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.id), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.id[]: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                        unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.id[i2],
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].key_id.id[%s%d]: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_OPAQUE_FILE(
                        unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.id[i2],
                            "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_key_id_offset_on_first_key_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info key_id offset_on_first_key") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info key_id offset_on_first_key\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/key_id/offset_on_first_key.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].key_id.offset_on_first_key: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__OFFSET_ON_FIRST_KEY,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__OFFSET_ON_FIRST_KEY, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.offset_on_first_key: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__OFFSET_ON_FIRST_KEY, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.offset_on_first_key: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].key_id.offset_on_first_key: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.offset_on_first_key);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_key_id_nof_bits_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  nof_bits_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = nof_bits_idx_0, I2 = nof_bits_idx_0 + 1, org_i2 = nof_bits_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info key_id nof_bits") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info key_id nof_bits\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/key_id/nof_bits.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].key_id.nof_bits[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__NOF_BITS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__NOF_BITS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.nof_bits[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__KEY_ID__NOF_BITS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.nof_bits[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.nof_bits
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.nof_bits), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].key_id.nof_bits[]: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_KEYS_PER_FG_MAX == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_MONITOR(
                        unit,
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].key_id.nof_bits[%s%d]: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_FILE(
                        unit,
                        "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                    dnx_sw_state_print_uint8(
                        unit,
                        &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].key_id.nof_bits[i2]);

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_qual_attach_info_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  qual_attach_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_qual_attach_info_input_type_dump(unit, fg_info_idx_0, context_info_idx_0, qual_attach_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_qual_attach_info_input_arg_dump(unit, fg_info_idx_0, context_info_idx_0, qual_attach_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_qual_attach_info_offset_dump(unit, fg_info_idx_0, context_info_idx_0, qual_attach_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_context_info_qual_attach_info_base_qual_dump(unit, fg_info_idx_0, context_info_idx_0, qual_attach_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_qual_attach_info_input_type_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  qual_attach_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = qual_attach_info_idx_0, I2 = qual_attach_info_idx_0 + 1, org_i2 = qual_attach_info_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_input_type_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info qual_attach_info input_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info qual_attach_info input_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/qual_attach_info/input_type.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].qual_attach_info[].input_type: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_TYPE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_type: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_type: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_type: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_MONITOR(
                        unit,
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].qual_attach_info[%s%d].input_type: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_FILE(
                        unit,
                        "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_ENUM(
                        unit,
                        dnx_field_input_type_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info[i2].input_type));

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_qual_attach_info_input_arg_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  qual_attach_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = qual_attach_info_idx_0, I2 = qual_attach_info_idx_0 + 1, org_i2 = qual_attach_info_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info qual_attach_info input_arg") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info qual_attach_info input_arg\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/qual_attach_info/input_arg.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].qual_attach_info[].input_arg: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_ARG,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_ARG, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_arg: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__INPUT_ARG, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_arg: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].input_arg: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_MONITOR(
                        unit,
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].qual_attach_info[%s%d].input_arg: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_FILE(
                        unit,
                        "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                    dnx_sw_state_print_int(
                        unit,
                        &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info[i2].input_arg);

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_qual_attach_info_offset_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  qual_attach_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = qual_attach_info_idx_0, I2 = qual_attach_info_idx_0 + 1, org_i2 = qual_attach_info_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info qual_attach_info offset") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info qual_attach_info offset\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/qual_attach_info/offset.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].qual_attach_info[].offset: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__OFFSET,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__OFFSET, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].offset: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__OFFSET, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].offset: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].offset: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_MONITOR(
                        unit,
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].qual_attach_info[%s%d].offset: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_FILE(
                        unit,
                        "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                    dnx_sw_state_print_int(
                        unit,
                        &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info[i2].offset);

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_qual_attach_info_base_qual_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  int  qual_attach_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    int i2 = qual_attach_info_idx_0, I2 = qual_attach_info_idx_0 + 1, org_i2 = qual_attach_info_idx_0;
    char *s0 = "", *s1 = "", *s2 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_qual_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info qual_attach_info base_qual") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info qual_attach_info base_qual\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/qual_attach_info/base_qual.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].qual_attach_info[].base_qual: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__BASE_QUAL,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__BASE_QUAL, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].base_qual: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__QUAL_ATTACH_INFO__BASE_QUAL, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].base_qual: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                if (i2 == -1) {
                    I2 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                    i2 = dnx_sw_state_dump_check_all_the_same(unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info
                        , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info), I2, &s2) ? I2 - 1 : 0;
                }

                if(i2 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
                {
                    LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].qual_attach_info[].base_qual: ")));
                    LOG_CLI((BSL_META("Invalid index: %d \n"),i2));
                    SHR_EXIT();
                }

                if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
                {
                    SHR_EXIT();
                }

                for(; i2 < I2; i2++) {
                    dnx_sw_state_dump_update_current_idx(unit, i2);
                    DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                        unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info[i2].base_qual,
                        "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].qual_attach_info[%s%d].base_qual: ", s0, i0, s1, i1, s2, i2);

                    DNX_SW_STATE_PRINT_OPAQUE_FILE(
                        unit,
                        ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].qual_attach_info[i2].base_qual,
                            "[%s%d][%s%d][%s%d]: ", s0, i0, s1, i1, s2, i2);

                }
                i2 = org_i2;
                dnx_sw_state_dump_end_of_stride(unit);
            }
            i1 = org_i1;
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_context_info_valid_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info context_info_valid") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info context_info_valid\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/context_info_valid.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].context_info_valid: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__CONTEXT_INFO_VALID,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__CONTEXT_INFO_VALID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].context_info_valid: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__CONTEXT_INFO_VALID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].context_info_valid: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].context_info_valid: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].context_info_valid);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_nof_cascading_refs_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint16") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info nof_cascading_refs") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info nof_cascading_refs\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/nof_cascading_refs.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].nof_cascading_refs: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__NOF_CASCADING_REFS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__NOF_CASCADING_REFS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].nof_cascading_refs: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__NOF_CASCADING_REFS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].nof_cascading_refs: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].nof_cascading_refs: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint16(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].nof_cascading_refs);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_payload_offset_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info payload_offset") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info payload_offset\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/payload_offset.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].payload_offset: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_OFFSET,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_OFFSET, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].payload_offset: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_OFFSET, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].payload_offset: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].payload_offset: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint32(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].payload_offset);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_payload_id_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint32") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info payload_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info payload_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/payload_id.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].payload_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_ID,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].payload_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__PAYLOAD_ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].payload_id: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].payload_id: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint32(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].payload_id);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_context_info_flags_dump(int  unit,  int  fg_info_idx_0,  int  context_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = context_info_idx_0, I1 = context_info_idx_0 + 1, org_i1 = context_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_group_context_attach_flags_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info context_info flags") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info context_info flags\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/context_info/flags.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].context_info[].flags: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__FLAGS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].flags: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__CONTEXT_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].context_info[].flags: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_CONTEXTS == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].context_info[%s%d].flags: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_ENUM(
                    unit,
                    dnx_field_group_context_attach_flags_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].context_info[i1].flags));

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_key_qual_map_dump(unit, fg_info_idx_0, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_key_size_in_bits_dump(unit, fg_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_key_qual_map_dump(int  unit,  int  fg_info_idx_0,  int  key_qual_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_key_qual_map_qual_type_dump(unit, fg_info_idx_0, key_qual_map_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_key_qual_map_lsb_dump(unit, fg_info_idx_0, key_qual_map_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_key_template_key_qual_map_size_dump(unit, fg_info_idx_0, key_qual_map_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_key_qual_map_qual_type_dump(int  unit,  int  fg_info_idx_0,  int  key_qual_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = key_qual_map_idx_0, I1 = key_qual_map_idx_0 + 1, org_i1 = key_qual_map_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_qual_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info key_template key_qual_map qual_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info key_template key_qual_map qual_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/key_template/key_qual_map/qual_type.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].key_template.key_qual_map[].qual_type: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].qual_type: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__QUAL_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].qual_type: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map[i1].qual_type,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].key_template.key_qual_map[%s%d].qual_type: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_OPAQUE_FILE(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map[i1].qual_type,
                        "[%s%d][%s%d]: ", s0, i0, s1, i1);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_key_qual_map_lsb_dump(int  unit,  int  fg_info_idx_0,  int  key_qual_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = key_qual_map_idx_0, I1 = key_qual_map_idx_0 + 1, org_i1 = key_qual_map_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint16") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info key_template key_qual_map lsb") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info key_template key_qual_map lsb\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/key_template/key_qual_map/lsb.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].key_template.key_qual_map[].lsb: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].lsb: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].lsb: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].key_template.key_qual_map[%s%d].lsb: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint16(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map[i1].lsb);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_key_qual_map_size_dump(int  unit,  int  fg_info_idx_0,  int  key_qual_map_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = key_qual_map_idx_0, I1 = key_qual_map_idx_0 + 1, org_i1 = key_qual_map_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info key_template key_qual_map size") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info key_template key_qual_map size\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/key_template/key_qual_map/size.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].key_template.key_qual_map[].size: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].size: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_QUAL_MAP__SIZE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_qual_map[].size: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_GROUP_NOF_QUALS_PER_FG == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].key_template.key_qual_map[%s%d].size: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_qual_map[i1].size);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_template_key_size_in_bits_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint16") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info key_template key_size_in_bits") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info key_template key_size_in_bits\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/key_template/key_size_in_bits.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].key_template.key_size_in_bits: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_template.key_size_in_bits: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_TEMPLATE__KEY_SIZE_IN_BITS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].key_template.key_size_in_bits: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint16(
                unit,
                &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_template.key_size_in_bits);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_key_length_type_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_key_length_type_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info key_length_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info key_length_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/key_length_type.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].key_length_type: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_LENGTH_TYPE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_LENGTH_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].key_length_type: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__KEY_LENGTH_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].key_length_type: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_key_length_type_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].key_length_type));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_action_length_type_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_action_length_type_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info action_length_type") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info action_length_type\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/action_length_type.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].action_length_type: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTION_LENGTH_TYPE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTION_LENGTH_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].action_length_type: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTION_LENGTH_TYPE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].action_length_type: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_action_length_type_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].action_length_type));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_actions_payload_info_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dump(unit, fg_info_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dump(int  unit,  int  fg_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dnx_action_dump(unit, fg_info_idx_0, actions_on_payload_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dont_use_valid_bit_dump(unit, fg_info_idx_0, actions_on_payload_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_lsb_dump(unit, fg_info_idx_0, actions_on_payload_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dnx_action_dump(int  unit,  int  fg_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_action_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info actions_payload_info actions_on_payload_info dnx_action") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info actions_payload_info actions_on_payload_info dnx_action\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/actions_payload_info/actions_on_payload_info/dnx_action.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info[i1].dnx_action,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].dnx_action: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_OPAQUE_FILE(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info[i1].dnx_action,
                        "[%s%d][%s%d]: ", s0, i0, s1, i1);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_dont_use_valid_bit_dump(int  unit,  int  fg_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info actions_payload_info actions_on_payload_info dont_use_valid_bit") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info actions_payload_info actions_on_payload_info dont_use_valid_bit\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/actions_payload_info/actions_on_payload_info/dont_use_valid_bit.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].dont_use_valid_bit: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info[i1].dont_use_valid_bit);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_actions_payload_info_actions_on_payload_info_lsb_dump(int  unit,  int  fg_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info actions_payload_info actions_on_payload_info lsb") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info actions_payload_info actions_on_payload_info lsb\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/actions_payload_info/actions_on_payload_info/lsb.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].actions_payload_info.actions_on_payload_info[].lsb: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].lsb: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].actions_payload_info.actions_on_payload_info[].lsb: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_COMMON_MAX_VAL_NOF_ACTION_PER_GROUP == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].lsb: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].actions_payload_info.actions_on_payload_info[i1].lsb);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_dbal_table_id_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dbal_tables_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info dbal_table_id") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info dbal_table_id\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/dbal_table_id.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].dbal_table_id: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__DBAL_TABLE_ID,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__DBAL_TABLE_ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].dbal_table_id: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__DBAL_TABLE_ID, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].dbal_table_id,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].dbal_table_id: ", s0, i0);

            DNX_SW_STATE_PRINT_OPAQUE_FILE(
                unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].dbal_table_id,
                    "[%s%d]: ", s0, i0);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_flags_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_group_add_flags_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info flags") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info flags\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/flags.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].flags: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FLAGS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].flags: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].flags: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_group_add_flags_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].flags));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_auto_tcam_bank_select_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_nof_tcam_banks_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_tcam_bank_ids_dump(unit, fg_info_idx_0, -1, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_cache_mode_dump(unit, fg_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_fg_info_tcam_info_nof_valid_entries_dump(unit, fg_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_auto_tcam_bank_select_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info tcam_info auto_tcam_bank_select") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info tcam_info auto_tcam_bank_select\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/tcam_info/auto_tcam_bank_select.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].tcam_info.auto_tcam_bank_select: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__AUTO_TCAM_BANK_SELECT,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__AUTO_TCAM_BANK_SELECT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.auto_tcam_bank_select: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__AUTO_TCAM_BANK_SELECT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].tcam_info.auto_tcam_bank_select: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.auto_tcam_bank_select);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_nof_tcam_banks_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info tcam_info nof_tcam_banks") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info tcam_info nof_tcam_banks\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/tcam_info/nof_tcam_banks.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].tcam_info.nof_tcam_banks: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_TCAM_BANKS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_TCAM_BANKS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.nof_tcam_banks: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_TCAM_BANKS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].tcam_info.nof_tcam_banks: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.nof_tcam_banks);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_tcam_bank_ids_dump(int  unit,  int  fg_info_idx_0,  int  tcam_bank_ids_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    int i1 = tcam_bank_ids_idx_0, I1 = tcam_bank_ids_idx_0 + 1, org_i1 = tcam_bank_ids_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info tcam_info tcam_bank_ids") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info tcam_info tcam_bank_ids\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/tcam_info/tcam_bank_ids.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].tcam_info.tcam_bank_ids[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.tcam_bank_ids[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            
            
                DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids);

            if (i1 == -1) {
                I1 = dnx_sw_state_get_nof_elements(unit,
                    DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids);
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids))
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.tcam_bank_ids[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__TCAM_BANK_IDS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids) == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].tcam_info.tcam_bank_ids[%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_int(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.tcam_bank_ids[i1]);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_cache_mode_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_group_cache_mode_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info tcam_info cache_mode") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info tcam_info cache_mode\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/tcam_info/cache_mode.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].tcam_info.cache_mode: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__CACHE_MODE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__CACHE_MODE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.cache_mode: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__CACHE_MODE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].tcam_info.cache_mode: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_group_cache_mode_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.cache_mode));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_fg_info_tcam_info_nof_valid_entries_dump(int  unit,  int  fg_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = fg_info_idx_0, I0 = fg_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "int") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group fg_info tcam_info nof_valid_entries") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group fg_info tcam_info nof_valid_entries\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/fg_info/tcam_info/nof_valid_entries.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[].tcam_info.nof_valid_entries: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_VALID_ENTRIES,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_VALID_ENTRIES, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->fg_info[].tcam_info.nof_valid_entries: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__FG_INFO__TCAM_INFO__NOF_VALID_ENTRIES, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","fg_info[%s%d].tcam_info.nof_valid_entries: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_int(
                unit,
                &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->fg_info[i0].tcam_info.nof_valid_entries);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_dump(int  unit,  int  ace_format_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_actions_payload_info_dump(unit, ace_format_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_flags_dump(unit, ace_format_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_name_dump(unit, ace_format_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_use_ppmc_range_dump(unit, ace_format_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_actions_payload_info_dump(int  unit,  int  ace_format_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dump(unit, ace_format_info_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dump(int  unit,  int  ace_format_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dnx_action_dump(unit, ace_format_info_idx_0, actions_on_payload_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dont_use_valid_bit_dump(unit, ace_format_info_idx_0, actions_on_payload_info_idx_0, filters));
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_lsb_dump(unit, ace_format_info_idx_0, actions_on_payload_info_idx_0, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dnx_action_dump(int  unit,  int  ace_format_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_action_t") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info actions_payload_info actions_on_payload_info dnx_action") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info actions_payload_info actions_on_payload_info dnx_action\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/actions_payload_info/actions_on_payload_info/dnx_action.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DNX_ACTION, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].dnx_action: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_OPAQUE_MONITOR(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info[i1].dnx_action,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].dnx_action: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_OPAQUE_FILE(
                    unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info[i1].dnx_action,
                        "[%s%d][%s%d]: ", s0, i0, s1, i1);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_dont_use_valid_bit_dump(int  unit,  int  ace_format_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info actions_payload_info actions_on_payload_info dont_use_valid_bit") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info actions_payload_info actions_on_payload_info dont_use_valid_bit\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/actions_payload_info/actions_on_payload_info/dont_use_valid_bit.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__DONT_USE_VALID_BIT, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].dont_use_valid_bit: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].dont_use_valid_bit: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info[i1].dont_use_valid_bit);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_actions_payload_info_actions_on_payload_info_lsb_dump(int  unit,  int  ace_format_info_idx_0,  int  actions_on_payload_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    int i1 = actions_on_payload_info_idx_0, I1 = actions_on_payload_info_idx_0 + 1, org_i1 = actions_on_payload_info_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info actions_payload_info actions_on_payload_info lsb") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info actions_payload_info actions_on_payload_info lsb\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/actions_payload_info/actions_on_payload_info/lsb.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].actions_payload_info.actions_on_payload_info[].lsb: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].lsb: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__ACTIONS_PAYLOAD_INFO__ACTIONS_ON_PAYLOAD_INFO__LSB, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].actions_payload_info.actions_on_payload_info[].lsb: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DNX_DATA_MAX_FIELD_ACE_NOF_ACTION_PER_ACE_FORMAT == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].actions_payload_info.actions_on_payload_info[%s%d].lsb: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_uint8(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].actions_payload_info.actions_on_payload_info[i1].lsb);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_flags_dump(int  unit,  int  ace_format_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "dnx_field_ace_format_add_flags_e") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info flags") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info flags\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/flags.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].flags: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__FLAGS,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].flags: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__FLAGS, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].flags: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            DNX_SW_STATE_PRINT_ENUM(
                unit,
                dnx_field_ace_format_add_flags_e_get_name(((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].flags));

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_name_dump(int  unit,  int  ace_format_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    DNXC_SW_STATE_INIT_FUNC_DEFS;
    SHR_IF_ERR_EXIT(dnx_field_group_sw_ace_format_info_name_value_dump(unit, ace_format_info_idx_0, -1, filters));
    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_name_value_dump(int  unit,  int  ace_format_info_idx_0,  int  value_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    int i1 = value_idx_0, I1 = value_idx_0 + 1, org_i1 = value_idx_0;
    char *s0 = "", *s1 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "char") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info name value") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info name value\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/name/value.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].name.value[]: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__NAME__VALUE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__NAME__VALUE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].name.value[]: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__NAME__VALUE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            if (i1 == -1) {
                I1 = DBAL_MAX_STRING_LENGTH;
                i1 = dnx_sw_state_dump_check_all_the_same(unit,
                    ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].name.value
                    , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].name.value), I1, &s1) ? I1 - 1 : 0;
            }

            if(i1 >= DBAL_MAX_STRING_LENGTH)
            {
                LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].name.value[]: ")));
                LOG_CLI((BSL_META("Invalid index: %d \n"),i1));
                SHR_EXIT();
            }

            if(DBAL_MAX_STRING_LENGTH == 0)
            {
                SHR_EXIT();
            }

            for(; i1 < I1; i1++) {
                dnx_sw_state_dump_update_current_idx(unit, i1);
                DNX_SW_STATE_PRINT_MONITOR(
                    unit,
                    "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].name.value[%s%d]: ", s0, i0, s1, i1);

                DNX_SW_STATE_PRINT_FILE(
                    unit,
                    "[%s%d][%s%d]: ", s0, i0, s1, i1);

                dnx_sw_state_print_char(
                    unit,
                    &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].name.value[i1]);

            }
            i1 = org_i1;
            dnx_sw_state_dump_end_of_stride(unit);
        }
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}




int
dnx_field_group_sw_ace_format_info_use_ppmc_range_dump(int  unit,  int  ace_format_info_idx_0,  dnx_sw_state_dump_filters_t  filters)
{
    int i0 = ace_format_info_idx_0, I0 = ace_format_info_idx_0 + 1;
    char *s0 = "";
    DNXC_SW_STATE_INIT_FUNC_DEFS;

    if (dnx_sw_state_compare(filters.typefilter, "uint8") != TRUE)
    {
         SHR_EXIT();
    }

    if (dnx_sw_state_compare(filters.namefilter, "dnx_field_group ace_format_info use_ppmc_range") != TRUE)
    {
         SHR_EXIT();
    }

    if (filters.nocontent)
    {
         DNX_SW_STATE_PRINT(unit, "swstate dnx_field_group ace_format_info use_ppmc_range\n");
    }
    else
    {
        dnx_sw_state_dump_attach_file(
            unit,
            "dnx_field_group_sw/ace_format_info/use_ppmc_range.txt",
            "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[].use_ppmc_range: ");

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID]));

        DNX_SW_STATE_DUMP_PTR_NULL_CHECK(
            unit,
            ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);

        if (i0 == -1) {
            I0 = dnx_sw_state_get_nof_elements(unit,
                DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__USE_PPMC_RANGE,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info);
            i0 = dnx_sw_state_dump_check_all_the_same(unit,
                ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info
                , sizeof(*((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info), I0, &s0) ? I0 - 1 : 0;
        }

        if(i0 >= dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__USE_PPMC_RANGE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info))
        {
            LOG_CLI((BSL_META("dnx_field_group_sw[]->((dnx_field_group_sw_t*)sw_state_roots_array[][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[].use_ppmc_range: ")));
            LOG_CLI((BSL_META("Invalid index: %d \n"),i0));
            SHR_EXIT();
        }

        if(dnx_sw_state_get_nof_elements(unit, DNX_SW_STATE_DNX_FIELD_GROUP_SW__ACE_FORMAT_INFO__USE_PPMC_RANGE, ((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info) == 0)
        {
            SHR_EXIT();
        }

        for(; i0 < I0; i0++) {
            dnx_sw_state_dump_update_current_idx(unit, i0);
            DNX_SW_STATE_PRINT_MONITOR(
                unit,
                "dnx_field_group_sw[%d]->","((dnx_field_group_sw_t*)sw_state_roots_array[%d][DNX_FIELD_GROUP_MODULE_ID])->","ace_format_info[%s%d].use_ppmc_range: ", s0, i0);

            DNX_SW_STATE_PRINT_FILE(
                unit,
                "[%s%d]: ", s0, i0);

            dnx_sw_state_print_uint8(
                unit,
                &((dnx_field_group_sw_t*)sw_state_roots_array[unit][DNX_FIELD_GROUP_MODULE_ID])->ace_format_info[i0].use_ppmc_range);

        }
        dnx_sw_state_dump_end_of_stride(unit);
        dnx_sw_state_dump_detach_file(
            unit);

    }

    DNXC_SW_STATE_FUNC_RETURN;
}





dnx_sw_state_diagnostic_info_t dnx_field_group_sw_info[SOC_MAX_NUM_DEVICES][DNX_FIELD_GROUP_SW_INFO_NOF_ENTRIES];
const char* dnx_field_group_sw_layout_str[DNX_FIELD_GROUP_SW_INFO_NOF_ENTRIES] = {
    "DNX_FIELD_GROUP_SW~",
    "DNX_FIELD_GROUP_SW~FG_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~FIELD_STAGE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~FG_TYPE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~NAME~",
    "DNX_FIELD_GROUP_SW~FG_INFO~NAME~VALUE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~KEY_ID~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~KEY_ID~ID~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~KEY_ID~OFFSET_ON_FIRST_KEY~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~KEY_ID~NOF_BITS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~QUAL_ATTACH_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~QUAL_ATTACH_INFO~INPUT_TYPE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~QUAL_ATTACH_INFO~INPUT_ARG~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~QUAL_ATTACH_INFO~OFFSET~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~QUAL_ATTACH_INFO~BASE_QUAL~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~CONTEXT_INFO_VALID~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~NOF_CASCADING_REFS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~PAYLOAD_OFFSET~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~PAYLOAD_ID~",
    "DNX_FIELD_GROUP_SW~FG_INFO~CONTEXT_INFO~FLAGS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~KEY_QUAL_MAP~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~KEY_QUAL_MAP~QUAL_TYPE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~KEY_QUAL_MAP~LSB~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~KEY_QUAL_MAP~SIZE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_TEMPLATE~KEY_SIZE_IN_BITS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~KEY_LENGTH_TYPE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTION_LENGTH_TYPE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTIONS_PAYLOAD_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~DNX_ACTION~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~DONT_USE_VALID_BIT~",
    "DNX_FIELD_GROUP_SW~FG_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~LSB~",
    "DNX_FIELD_GROUP_SW~FG_INFO~DBAL_TABLE_ID~",
    "DNX_FIELD_GROUP_SW~FG_INFO~FLAGS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~AUTO_TCAM_BANK_SELECT~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~NOF_TCAM_BANKS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~TCAM_BANK_IDS~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~CACHE_MODE~",
    "DNX_FIELD_GROUP_SW~FG_INFO~TCAM_INFO~NOF_VALID_ENTRIES~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~ACTIONS_PAYLOAD_INFO~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~DNX_ACTION~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~DONT_USE_VALID_BIT~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~ACTIONS_PAYLOAD_INFO~ACTIONS_ON_PAYLOAD_INFO~LSB~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~FLAGS~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~NAME~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~NAME~VALUE~",
    "DNX_FIELD_GROUP_SW~ACE_FORMAT_INFO~USE_PPMC_RANGE~",
};
#endif 
#undef BSL_LOG_MODULE
