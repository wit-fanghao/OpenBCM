/** \file diag_dnx_pp_context.c
 *
 * Context PP Diagnostic Command - Present all context signal values for the last sent packet.
 */

/*************
 * INCLUDES  *
 *************/
#include "diag_dnx_pp.h"
#include "soc/dnx/dnx_data/auto_generated/dnx_data_internal_device.h"
#include "src/soc/dnx/dbal/dbal_internal.h"
#include <soc/dnx/dnx_data/auto_generated/dnx_data_adapter.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
/*************
 * DEFINES   *
 *************/

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_SOCDNX_DIAGPPDNX

/*************
 *  MACROS  *
 *************/

/*************
 * TYPEDEFS  *
 *************/

/*************
 * GLOBALS   *
 *************/
/*************
 * FUNCTIONS *
 *************/

/**
 * \brief
 *    A diagnostics function that extracts the values of the context signal and displays them in a table
 *    decoding the values according to the Nasid value and the context enum for the given stage.
 *    If a stage is selected, an additional table is printed for the context enablers for that stage.
 * \param [in] unit - unit ID
 * \param [in] args - arguments passed to the function according to the diag mechanism
 * \param [in] sand_control - passed according to the diag mechanism
 * \return
 *   \retval Zero if no error was detected
 *   \retval Negative if error was detected. See \ref shr_error_e
 */

shr_error_e
sh_dnx_pp_context_cmd(
    int unit,
    args_t * args,
    sh_sand_control_t * sand_control)
{
    int core_index;
    int user_core_id = BCM_CORE_ALL;
    uint32 nof_values = 0;
    uint32 nof_stages = DNX_PP_STAGE_NOF;
    uint32 entry_handle_id;
    uint32 stage_start = 0;
    uint32 stage_id;
    uint32 field_value = 0;
    dnx_pp_block_e block_id;
    char *stage_name;
    uint32 nasid = 0;
    uint32 context_id = 0;
    uint32 context_val = 0;
    dbal_tables_e table_names[DNX_PP_STAGE_NOF] = { 0 };
    int rv = BCM_E_NONE;
    dbal_field_types_defs_e context_enums[DNX_PP_STAGE_NOF] = { 0 };
    CONST dbal_field_types_basic_info_t *context_field_type;
#ifdef ADAPTER_SERVER_MODE
    int core_group_idx;
#endif
    PRT_INIT_VARS;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    table_names[DNX_PP_STAGE_VTT1] = DBAL_TABLE_INGRESS_IRPP_VT1_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_VTT2] = DBAL_TABLE_INGRESS_IRPP_VT2_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_VTT3] = DBAL_TABLE_INGRESS_IRPP_VT3_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_VTT4] = DBAL_TABLE_INGRESS_IRPP_VT4_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_VTT5] = DBAL_TABLE_INGRESS_IRPP_VT5_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_IFWD1] = DBAL_TABLE_INGRESS_IRPP_FWD1_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_IFWD2] = DBAL_TABLE_INGRESS_IRPP_FWD2_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_TERM] = DBAL_TABLE_EGRESS_ETPP_TERM_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_EFWD] = DBAL_TABLE_EGRESS_ETPP_FWD_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_ENC1] = DBAL_TABLE_EGRESS_ETPP_ENCAP_1_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_ENC2] = DBAL_TABLE_EGRESS_ETPP_ENCAP_2_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_ENC3] = DBAL_TABLE_EGRESS_ETPP_ENCAP_3_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_ENC4] = DBAL_TABLE_EGRESS_ETPP_ENCAP_4_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_ENC5] = DBAL_TABLE_EGRESS_ETPP_ENCAP_5_CONTEXT_PROPERTIES;
    table_names[DNX_PP_STAGE_TRAP] = DBAL_TABLE_EGRESS_ETPP_TRAP_CONTEXT_PROPERTIES;

    context_enums[DNX_PP_STAGE_VTT1] = DBAL_FIELD_TYPE_DEF_VT1_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_VTT2] = DBAL_FIELD_TYPE_DEF_VT2_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_VTT3] = DBAL_FIELD_TYPE_DEF_VT3_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_VTT4] = DBAL_FIELD_TYPE_DEF_VT4_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_VTT5] = DBAL_FIELD_TYPE_DEF_VT5_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_IFWD1] = DBAL_FIELD_TYPE_DEF_FWD1_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_IFWD2] = DBAL_FIELD_TYPE_DEF_FWD2_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ETPRP2] = DBAL_FIELD_TYPE_DEF_PRP2_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_TERM] = DBAL_FIELD_TYPE_DEF_TERM_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_EFWD] = DBAL_FIELD_TYPE_DEF_FWD_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ENC1] = DBAL_FIELD_TYPE_DEF_ENCAP_1_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ENC2] = DBAL_FIELD_TYPE_DEF_ENCAP_2_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ENC3] = DBAL_FIELD_TYPE_DEF_ENCAP_3_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ENC4] = DBAL_FIELD_TYPE_DEF_ENCAP_4_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_ENC5] = DBAL_FIELD_TYPE_DEF_ENCAP_5_CONTEXT_ID;
    context_enums[DNX_PP_STAGE_TRAP] = DBAL_FIELD_TYPE_DEF_TRAP_CONTEXT_ID;

    SH_SAND_GET_STR("stage", stage_name);
    SH_SAND_GET_INT32("core", user_core_id);

    /** Determine if the user passed a correct stage value. Amend start and end variables for iteration */
    if (ISEMPTY(stage_name))
    {
        stage_start = 0;
    }
    else if (dnx_pp_stage_string_to_id_no_error(unit, stage_name, &stage_id) != _SHR_E_NONE ||
             dnx_pp_stage_is_kleap(unit, stage_id) == 0)
    {
        LOG_CLI((BSL_META
                 ("Illegal Stage. Valid stages are: \nVTT1-5, FWD1-2, IPMF1-3, FER, LBP, Term, FWD, ENC1-5, Trap.\n")));
        SHR_EXIT();
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_pp_stage_string_to_id(unit, stage_name, &stage_id));
        stage_start = stage_id;
        nof_stages = stage_id + 1;
    }

    if (user_core_id != BCM_CORE_ALL)
    {
        /** Determine if the user passed a correct core value.*/
#ifdef ADAPTER_SERVER_MODE
        for (core_group_idx = 0; core_group_idx < dnx_data_device.general.nof_core_groups_get(unit); core_group_idx++)
        {
            if (user_core_id == (dnx_data_adapter.reg_mem_access.swap_core_index_zero_with_core_index_get(unit) +
                                 core_group_idx * dnx_data_device.general.nof_cores_per_core_group_get(unit)))
            {
                break;
            }
        }
        if (core_group_idx == dnx_data_device.general.nof_core_groups_get(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal Core %d, Only legal core (per core_group) is: %d\n", user_core_id,
                         dnx_data_adapter.reg_mem_access.swap_core_index_zero_with_core_index_get(unit));
        }
#else
        if (user_core_id < 0 || user_core_id > dnx_data_device.general.nof_cores_get(unit) - 1)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Illegal Core %d, max core is: %d \n", user_core_id,
                         dnx_data_device.general.nof_cores_get(unit) - 1);
        }
#endif
    }
    PRT_TITLE_SET("Context diagnostics");
    PRT_COLUMN_ADD("Core");
    PRT_COLUMN_ADD("Stage");
    PRT_COLUMN_ADD("Block");
    PRT_COLUMN_ADD("Context");
    PRT_COLUMN_ADD("Nasid");

    SH_DNX_CORES_ITER(unit, user_core_id, core_index)
    {
        for (stage_id = stage_start; stage_id < nof_stages; stage_id++)
        {
            if (dnx_pp_stage_is_kleap(unit, stage_id) == 0)
            {
                continue;
            }

            SHR_IF_ERR_EXIT(dnx_pp_block_string_to_id(unit, dnx_pp_stage_block_name(unit, stage_id), &block_id));
            DNX_PP_BLOCK_IS_READY_CONT(core_index, block_id, FALSE);

            /** Receive the value of the context signal. Skip the current stage if the context signal is not found */
            rv = dpp_dsig_read(unit, core_index, dnx_pp_stage_block_name(unit, stage_id),
                               NULL, dnx_pp_stage_name(unit, stage_id), "context", &context_val, 1);
            if (rv != BCM_E_NONE)
            {
                continue;
            }
                    /** Receive the value of the nasid signal. Set it to 0 if it couldn't be received. */
            if (sal_strncmp
                (dnx_pp_stage_block_name(unit, stage_id), "IRPP", SHR_SAND_DEFAULT_MAX_STRING_OPERATION_LENGTH) == 0)
            {
                rv = dpp_dsig_read(unit, core_index, dnx_pp_stage_block_name(unit, stage_id), NULL,
                                   dnx_pp_stage_name(unit, stage_id), "nasid", &nasid, 1);
                if (rv != BCM_E_NONE)
                {
                    nasid = 0;
                }
            }
            else
            {
                nasid = 0;
            }

            /*
             * Determine the separator that needs to be placed in the table
             */
            if ((stage_id + 1 == nof_stages) && (core_index == 1 || user_core_id == 0))
            {
                PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            }
            else
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
            }

            /*
             * If the value of the nasid signal is different than 0 and it doesn't indicate a stage that has passed,
             * the value is taken in mind and indicates a different context enum.
             * Otherwise, the context enum is chosen based on the current stage.
             */
            if ((nasid != 0) && (nasid > stage_id))
            {
                context_id = nasid - 1;
            }
            else
            {
                context_id = stage_id;
            }

            /** If the context_id indicates a valid context_enum, extract the nof_values from it. */
            if (context_enums[context_id] != 0)
            {
                SHR_IF_ERR_EXIT(dbal_field_types_info_get(unit, context_enums[context_id], &context_field_type));
                nof_values = context_field_type->nof_enum_values;
            }
            else
            {
                nof_values = 0;
            }

            PRT_CELL_SET("%d", core_index);
            PRT_CELL_SET("%s", dnx_pp_stage_name(unit, stage_id));
            PRT_CELL_SET("%s", dnx_pp_stage_block_name(unit, stage_id));

            /*
             * If the context value that was received is out of range, only its value is written in the table.
             * Otherwise the meaning of the value is written.
             */
            if (nof_values != 0)
            {
                int idx = context_val;
                if (context_field_type->enum_val_info[context_val].value != context_val)
                {
                    for (idx = 0; idx < context_field_type->nof_enum_values; idx++)
                    {
                        if (context_field_type->enum_val_info[idx].value == context_val)
                        {
                            break;
                        }
                    }
                }
                if (idx > context_field_type->max_value)
                {
                    PRT_CELL_SET("0x%02x", context_val);
                }
                else
                {
                    PRT_CELL_SET("%s (0x%02x)", context_field_type->enum_val_info[idx].name, context_val);
                }
            }
            else
            {
                PRT_CELL_SET("0x%02x", context_val);
            }
            PRT_CELL_SET("%d", nasid);
        }/** loop of stages */
    }/** of ITERATOR for cores */
    PRT_COMMITX;

    /*
     * If the user provided a name of stage then an additional table will be printed with the context enablers.
     */
    if (!ISEMPTY(stage_name))
    {
        /** Determine if there is a valid context enablers table for the selected stage. */
        if (table_names[stage_start] != 0 && context_val < nof_values)
        {
            int iter = 0;
            dbal_fields_e next_field_id;
            dbal_field_print_type_e field_print_type;
            char field_enum[DBAL_MAX_PRINTABLE_BUFFER_SIZE];

            SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, table_names[stage_start], &entry_handle_id));

            PRT_TITLE_SET("Context enablers for stage %s", dnx_pp_stage_name(unit, stage_start));
            PRT_COLUMN_ADD("Context enabler name");
            PRT_COLUMN_ADD("Value");
            PRT_ROW_ADD(PRT_ROW_SEP_UNDERSCORE);
            /*
             * Iterate over the keys of the context enablers table for the given stage
             */

            SHR_IF_ERR_EXIT(dbal_tables_next_field_get
                            (unit, table_names[stage_start], DBAL_FIELD_EMPTY, 1, 0, &next_field_id));
            while (next_field_id != DBAL_FIELD_EMPTY)
            {
                iter++;
                SHR_IF_ERR_EXIT(dbal_fields_print_type_get(unit, next_field_id, &field_print_type));
                if (field_print_type == DBAL_FIELD_PRINT_TYPE_ENUM)
                {
                    SHR_IF_ERR_EXIT(dbal_fields_enum_value_get(unit, next_field_id, context_val, &field_value));
                }
                else
                {
                    field_value = context_val;
                }
                dbal_entry_key_field32_set(unit, entry_handle_id, next_field_id, field_value);
                PRT_CELL_SET("%s = %u", dbal_field_to_string(unit, next_field_id), field_value);

                SHR_IF_ERR_EXIT(dbal_tables_next_field_get
                                (unit, table_names[stage_start], next_field_id, 1, 0, &next_field_id));
            }

            /*
             * If the table has a single key field,
             * we need to add an empty cell in order to align the table to its two columns
             */
            if (iter < 2)
            {
                PRT_CELL_SKIP(1);
            }
            SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

            SHR_IF_ERR_EXIT(dbal_tables_next_field_get
                            (unit, table_names[stage_start], DBAL_FIELD_EMPTY, 0, 0, &next_field_id));
            while (next_field_id != DBAL_FIELD_EMPTY)
            {
                PRT_ROW_ADD(PRT_ROW_SEP_NONE);
                PRT_CELL_SET("%s", dbal_field_to_string(unit, next_field_id));

                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field_arr32_get
                                (unit, entry_handle_id, next_field_id, INST_SINGLE, &field_value));

                SHR_IF_ERR_EXIT(dbal_table_field32_printable_string_get
                                (unit, table_names[stage_start], next_field_id, 0, field_value, NULL, 0, FALSE,
                                 field_enum));
                PRT_CELL_SET("%s", field_enum);

                SHR_IF_ERR_EXIT(dbal_tables_next_field_get
                                (unit, table_names[stage_start], next_field_id, 0, 0, &next_field_id));
            }

            DBAL_HANDLE_CLEAR(unit, table_names[stage_start], entry_handle_id);
            DBAL_HANDLE_FREE(unit, entry_handle_id);
            PRT_COMMITX;
        }
    }

exit:
    PRT_FREE;
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

sh_sand_man_t dnx_pp_context_man = {
    .brief = "Print information about the values of the 'context' signal for all relevant stages.",
    .full =
        "Print information regarding the value of the context signal for all stages\n"
        "If a particular stage is provided, then only its value will be presented.\n"
        "In case there is a valid context enablers table for the given stage, its data will be also printed.\n"
        "Valid stages are: \n"
        "VTT1-5, FWD1-2, IPMF1-3, FER, LBP, Term, FWD, ENC1-5, Trap.\n"
        "If a core ID is provided, then only the data from that core will be presented. Valid values: 0 and 1",
    .synopsis = "[stage=<STAGE_NAME> core=<CORE_ID>]",
    .init_cb = diag_sand_packet_send_simple,
    .examples = "\n" "stage=VTT1\n" "core=0",
    .compatibility = DIAG_DNX_PP_BARE_METAL_NOT_AVAILABLE_COMMAND
};

sh_sand_option_t dnx_pp_context_options[] = {
    {"stage", SAL_FIELD_TYPE_STR, "Stage name", ""}
    ,
    {NULL}
};
