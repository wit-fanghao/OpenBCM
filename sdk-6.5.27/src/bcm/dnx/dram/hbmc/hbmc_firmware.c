
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_DRAM

#include <soc/sand/shrextend/shrextend_debug.h>
#include <shared/util.h>
#include <shared/dbx/dbx_file.h>
#include <soc/util.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_dram.h>
#include <soc/dnx/swstate/auto_generated/access/dnx_dram_access.h>
#include <bcm_int/dnx/cmn/dnxcmn.h>
#include <bcm_int/dnx/dram/dram.h>
#include <bcm_int/dnx/dram/hbmc/hbmc.h>
#include <bcm_int/dnx/dram/hbmc/hbmc_firmware.h>
#include "hbmc_dbal_access.h"
#ifdef INCLUDE_AAPL
#include <libs/aapl/include/aapl.h>
#endif

#define DNX_HBMC_FIRMWARE_FILE_MAX_SIZE 384

#define DNX_HBMC_FIRMWARE_STATUS_OPERATION_DONE              (dnx_data_dram.firmware.operation_status_get(unit)->done)
#define DNX_HBMC_FIRMWARE_STATUS_OPERATION_ACTIVE            (dnx_data_dram.firmware.operation_status_get(unit)->active)
#define DNX_HBMC_FIRMWARE_STATUS_OPERATION_ERRORS_DETECTED   (dnx_data_dram.firmware.operation_status_get(unit)->errors_detected)

#define DNX_HBMC_FIRMWARE_INTERRUPT_SUCCESS (1)

#define DNX_HBMC_FIRMWARE_INTERRUPT_DATA_COMPOSE(operation, channel)   (operation | ((channel == DNX_HBMC_FIRMWARE_ALL_CHANNELS) ? 0 : (channel << 8)))

#define DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_CLK_DELAY_SHIFT (6)
#define DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_WR_DELAY_SHIFT  (3)
#define DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_RD_DELAY_SHIFT  (0)

#define DNX_HBMC_FIRMWARE_HBM2E_GET_QC_DELAY(clk_delay, wr_delay, rd_delay) \
    ((clk_delay) << DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_CLK_DELAY_SHIFT | \
     (wr_delay) << DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_WR_DELAY_SHIFT | \
     (rd_delay) << DNX_HBMC_FIRMWARE_HBM2E_QC_DELAY_RD_DELAY_SHIFT)

#define DNX_HBMC_FIRMWARE_JTAGID_ONE_HBM                 (0x1000057f)
#define DNX_HBMC_FIRMWARE_JTAGID_TWO_HBMS                (0x2000057f)
#define DNX_HBMC_FIRMWARE_JTAGID_THREE_HBM               (0x3000057f)

typedef enum
{

    DNX_HBMC_AAPL_CMD_RESET = 0,

    DNX_HBMC_AAPL_CMD_WRITE = 1,

    DNX_HBMC_AAPL_CMD_READ = 2
} dnx_hbmc_aapl_cmd_e;

typedef enum
{

    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_OPERATION_STATUS = 0x00,

    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_GLOBAL_ERROR_CODE = 0x01,

    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_0_ERROR_CODE = 0x02,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_1_ERROR_CODE = 0x03,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_2_ERROR_CODE = 0x04,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_3_ERROR_CODE = 0x05,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_4_ERROR_CODE = 0x06,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_5_ERROR_CODE = 0x07,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_6_ERROR_CODE = 0x08,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_7_ERROR_CODE = 0x09,

    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_0_LAST_OPERATION = 0x0a,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_1_LAST_OPERATION = 0x0b,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_2_LAST_OPERATION = 0x0c,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_3_LAST_OPERATION = 0x0d,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_4_LAST_OPERATION = 0x0e,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_5_LAST_OPERATION = 0x0f,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_6_LAST_OPERATION = 0x10,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_7_LAST_OPERATION = 0x11,

    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_0 = 0x12,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_1 = 0x13,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_2 = 0x14,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_3 = 0x15,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_4 = 0x16,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_5 = 0x17,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_6 = 0x18,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_7 = 0x19,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_8 = 0x1a,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_9 = 0x1b,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_10 = 0x1c,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_11 = 0x1d,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_12 = 0x1e,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_13 = 0x1f,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_14 = 0x20,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_15 = 0x21,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_16 = 0x22,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_17 = 0x23,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_18 = 0x24,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_19 = 0x25,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_20 = 0x26,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_21 = 0x27,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_22 = 0x28,
    DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_23 = 0x29
} dnx_hbmc_firmware_operation_result_type_e;

typedef struct dnx_hbmc_firmware_operation_result_error_code_s
{

    uint32 global_error_code;

    uint32 channel_error_code[DNX_DATA_MAX_DRAM_GENERAL_INFO_NOF_CHANNELS];

    uint32 channel_last_operation[DNX_DATA_MAX_DRAM_GENERAL_INFO_NOF_CHANNELS];
} dnx_hbmc_firmware_operation_result_error_code_t;

static shr_error_e dnx_hbmc_firmware_operation_result_error_code_get(
    int unit,
    int hbmc_index,
    int channel_begin,
    int channel_end,
    dnx_hbmc_firmware_operation_result_error_code_t * error_code);

static shr_error_e dnx_hbmc_firmware_operation_result_spare_internal_get(
    int unit,
    int hbmc_index,
    uint32 nof_hbm_spares,
    dnx_hbmc_firmware_operation_result_hbm_spare_t * hbm_spare);

static shr_error_e
dnx_hbmc_firmware_mutex_take(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_dram_db.sync_manager.firmware_mutex.take(unit, sal_mutex_FOREVER));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_mutex_give(
    int unit)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_CONT(dnx_dram_db.sync_manager.firmware_mutex.give(unit));

    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_interrupt_access(
    int unit,
    int hbmc_index,
    uint32 interrupt_code,
    uint32 interrupt_data,
    uint32 *interrupt_result)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_INTERRUPT_ACCESS, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_INTERRUPT_CODE, INST_SINGLE, interrupt_code);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_INTERRUPT_DATA, INST_SINGLE, interrupt_data);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_INTERRUPT_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_INTERRUPT_ASSERT, INST_SINGLE, 1);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_INTERRUPT_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_INTERRUPT_ASSERT, INST_SINGLE, 0);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_INTERRUPT_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    SHR_IF_ERR_EXIT(dnxcmn_polling
                    (unit, DNXCMN_TIMEOUT, DNXCMN_MIN_POLLS, entry_handle_id, DBAL_FIELD_INTERRUPT_BUSY, 0));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_INTERRUPT_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_INTERRUPT_RESULT, INST_SINGLE, interrupt_result);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_info_get(
    int unit,
    int hbmc_index,
    dnx_hbmc_firmware_info_t * firmware_info)
{
    int is_mutex_locked = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    is_mutex_locked = TRUE;

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_REVISION, 0, &firmware_info->revision));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_BUILD_ID, 0, &firmware_info->build_id));

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_launch_operation(
    int unit,
    int hbmc_index,
    int hbmc_channel,
    dnx_hbmc_firmware_operation_e operation)
{
    uint32 interrupt_result = 0;
    dnx_hbmc_firmware_interrupt_code_e interrupt_code;
    uint32 interrupt_data;
    uint32 operation_status;
    uint32 nof_channels = dnx_data_dram.general_info.nof_channels_get(unit);
    uint32 channel_begin;
    uint32 channel_end;
    soc_timeout_t to;
    int is_mutex_locked = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    is_mutex_locked = TRUE;

    if (hbmc_channel == DNX_HBMC_FIRMWARE_ALL_CHANNELS)
    {
        interrupt_code = DNX_HBMC_FIRMWARE_INTERRUPT_CODE_LAUNCH_OPERATION_ON_ALL_CHANNELS;
        channel_begin = 0;
        channel_end = nof_channels - 1;
    }
    else
    {
        interrupt_code = DNX_HBMC_FIRMWARE_INTERRUPT_CODE_LAUNCH_OPERATION_ON_A_SINGLE_CHANNEL;
        channel_begin = hbmc_channel;
        channel_end = hbmc_channel;
    }

    interrupt_data = DNX_HBMC_FIRMWARE_INTERRUPT_DATA_COMPOSE(operation, hbmc_channel);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, interrupt_code, interrupt_data, &interrupt_result));
#ifndef PLISIM
    if (interrupt_result != DNX_HBMC_FIRMWARE_INTERRUPT_SUCCESS)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "HBMC%d firmware operation 0x%x failed to start: invalid return code 0x%x\n",
                     hbmc_index, operation, interrupt_result);
    }
#endif

    soc_timeout_init(&to, 10000000, 1000);
    do
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                        (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_OPERATION_RESULT,
                         DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_OPERATION_STATUS, &operation_status));

        if (soc_timeout_check(&to))
        {
            SHR_ERR_EXIT(_SHR_E_TIMEOUT, "TIMEOUT when polling for operation %d to complete\n", operation);
        }
    }
    while (operation_status == DNX_HBMC_FIRMWARE_STATUS_OPERATION_ACTIVE);

    if (operation_status == DNX_HBMC_FIRMWARE_STATUS_OPERATION_ERRORS_DETECTED)
    {
        dnx_hbmc_firmware_operation_result_error_code_t error_code;
        uint32 i_channel;
        dnx_hbmc_firmware_operation_result_hbm_spare_t hbm_spare;
        uint32 i_spare;
        uint32 nof_hbm_spares = dnx_data_dram.firmware.nof_hbm_spare_data_results_get(unit);

        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_operation_result_error_code_get
                        (unit, hbmc_index, channel_begin, channel_end, &error_code));
        if (error_code.global_error_code)
        {

            LOG_ERROR(BSL_LOG_MODULE,
                      (BSL_META_U(unit, "HBMC%d firmware operation result: global_error_code=0x%x:%s\n"), hbmc_index,
                       error_code.global_error_code, dnx_data_dram.firmware.operation_result_error_code_get(unit,
                                                                                                            error_code.global_error_code)->description));
        }

        for (i_channel = channel_begin; i_channel <= channel_end; ++i_channel)
        {
            if (error_code.channel_error_code[i_channel])
            {

                LOG_ERROR(BSL_LOG_MODULE,
                          (BSL_META_U
                           (unit,
                            "HBMC%d firmware operation result: channel=%u, error_code=0x%x:%s, operation=0x%x:%s\n"),
                           hbmc_index, i_channel, error_code.channel_error_code[i_channel],
                           dnx_data_dram.firmware.operation_result_error_code_get(unit,
                                                                                  error_code.channel_error_code
                                                                                  [i_channel])->description,
                           error_code.channel_last_operation[i_channel],
                           dnx_data_dram.firmware.operation_result_last_operation_get(unit,
                                                                                      error_code.channel_last_operation
                                                                                      [i_channel])->description));
            }
        }

        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_operation_result_spare_internal_get
                        (unit, hbmc_index, nof_hbm_spares, &hbm_spare));
        for (i_spare = 0; i_spare < nof_hbm_spares; ++i_spare)
        {
            if (hbm_spare.hbm_spare_data[i_spare])
            {

                LOG_ERROR(BSL_LOG_MODULE,
                          (BSL_META_U(unit, "HBMC%d firmware operation result: hbm_spare_%u=0x%x\n"), hbmc_index,
                           i_spare, hbm_spare.hbm_spare_data[i_spare]));
            }
        }

        SHR_ERR_EXIT(_SHR_E_FAIL, "HBMC%d firmware operation 0x%x resulted with error\n", hbmc_index, operation);
    }

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_operation_result_error_code_get(
    int unit,
    int hbmc_index,
    int channel_begin,
    int channel_end,
    dnx_hbmc_firmware_operation_result_error_code_t * error_code)
{
    uint32 i_channel;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_OPERATION_RESULT,
                     DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_GLOBAL_ERROR_CODE, &error_code->global_error_code));

    for (i_channel = channel_begin; i_channel <= channel_end; ++i_channel)
    {

        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                        (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_OPERATION_RESULT,
                         DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_0_ERROR_CODE + i_channel,
                         &error_code->channel_error_code[i_channel]));

        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                        (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_OPERATION_RESULT,
                         DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_CHANNEL_0_LAST_OPERATION + i_channel,
                         &error_code->channel_last_operation[i_channel]));
    }

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_operation_result_spare_internal_get(
    int unit,
    int hbmc_index,
    uint32 nof_hbm_spares,
    dnx_hbmc_firmware_operation_result_hbm_spare_t * hbm_spare)
{
    uint32 i_spare;
    SHR_FUNC_INIT_VARS(unit);

    SHR_MAX_VERIFY(nof_hbm_spares, dnx_data_dram.firmware.nof_hbm_spare_data_results_get(unit), _SHR_E_PARAM,
                   "Number of required HBM spare data results is too high (%d). Max is %d\n.", nof_hbm_spares,
                   dnx_data_dram.firmware.nof_hbm_spare_data_results_get(unit));

    for (i_spare = 0; i_spare < nof_hbm_spares; ++i_spare)
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                        (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_OPERATION_RESULT,
                         DNX_HBMC_FIRMWARE_OPERATION_RESULT_TYPE_HBM_SPARE_0 + i_spare,
                         &hbm_spare->hbm_spare_data[i_spare]));
    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_operation_result_spare_get(
    int unit,
    int hbmc_index,
    uint32 nof_hbm_spares,
    dnx_hbmc_firmware_operation_result_hbm_spare_t * hbm_spare)
{
    int is_mutex_locked = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    is_mutex_locked = TRUE;

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_operation_result_spare_internal_get(unit, hbmc_index, nof_hbm_spares, hbm_spare));

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_param_set(
    int unit,
    int hbmc_index,
    int param,
    uint32 value)
{
    uint32 interrupt_result;
    int is_mutex_locked = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    is_mutex_locked = TRUE;

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_SET_PARAMETER, param, &interrupt_result));
#ifndef PLISIM
    if (interrupt_result != DNX_HBMC_FIRMWARE_INTERRUPT_SUCCESS)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "HBM%d firmware param offset %x set failed\n", hbmc_index, param);
    }
#endif

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_SET_PARAMETER_VALUE, value, &interrupt_result));
#ifndef PLISIM
    if (interrupt_result != DNX_HBMC_FIRMWARE_INTERRUPT_SUCCESS)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "HBMC%d firmware param value %x set failed\n", hbmc_index, value);
    }
#endif

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_param_get(
    int unit,
    int hbmc_index,
    int param,
    uint32 *value)
{
    int is_mutex_locked = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    is_mutex_locked = TRUE;

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_interrupt_access
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_INTERRUPT_CODE_GET_PARAMETER_VALUE, param, value));

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_sbus_clock_divider_set(
    int unit,
    int hbmc_index,
    uint32 divider)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (!utilex_is_power_of_2(divider))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR HBMC%d: sbus clock divider must be power of 2, but got %d.\n", hbmc_index,
                     divider);
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SBUS_CONTROLLER_ACCESS, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CLOCK_DIVIDER, INST_SINGLE,
                                 utilex_log2_round_down(divider));
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_hbmc_firmware_sbus_dll_config_clock_set(
    int unit,
    uint32 hbmc_index,
    uint32 value)
{
    uint32 entry_handle_id;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SBUS_CONTROLLER_ACCESS, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DLL_CONFIG_CLK, INST_SINGLE, value);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static int
dnx_hbmc_read_firmware_line_from_rom(
    int unit,
    FILE * fp,
    uint32 *line)
{
    int ascii_hex_digit;

    while ((ascii_hex_digit = sal_fgetc(fp)) != EOF)
    {

        if (ascii_hex_digit == '\n')
        {
            break;
        }

        *line <<= 4;

        *line |= _shr_xdigit2i(ascii_hex_digit);
    }

    return (ascii_hex_digit == EOF) ? FALSE : TRUE;
}

static shr_error_e
dnx_hbmc_firmware_upload(
    int unit,
    int hbmc_index,
    int is_hbm2e)
{
    uint32 entry_handle_id;
    FILE *fp = NULL;
    char *rel_file_path;
    char file_path[DNX_HBMC_FIRMWARE_FILE_MAX_SIZE];
    int valid = 1;
    uint32 line_number = 0;
    dnx_hbmc_firmware_info_t firmware_info;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    rel_file_path = is_hbm2e ?
        dnx_data_dram.firmware.rom_get(unit, DNX_HBMC_HBM_GENERATION_HBM2E)->filename :
        dnx_data_dram.firmware.rom_get(unit, DNX_HBMC_HBM_GENERATION_HBM)->filename;

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): Uploading Sbus Master ROM via SBus\n"), FUNCTION_NAME(), hbmc_index));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, &entry_handle_id));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SINGLE_STEP_EN, INST_SINGLE, TRUE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SBUS_CNTL_GATE, INST_SINGLE, TRUE);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SNAP_RESET, INST_SINGLE, TRUE);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SNAP_ENABLE, INST_SINGLE, FALSE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SNAP_RESET, INST_SINGLE, FALSE);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_CNTL_EN, INST_SINGLE, TRUE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SINGLE_STEP_EN, INST_SINGLE, FALSE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_WRITE_EN, INST_SINGLE, TRUE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(dbx_file_get_file_path(unit, rel_file_path, CONF_OPEN_PER_DEVICE, file_path));
    if ((fp = sal_fopen(file_path, "r")) == NULL)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR: HBMC%d firmware file %s was not found.\n", hbmc_index, file_path);
    }

    while (valid)
    {
        int line_index = 0;
        uint32 buf_data1 = 0;
        uint32 buf_data2 = 0;
        uint32 buf_data3 = 0;

        for (line_index = 0; line_index <= 7; ++line_index)
        {
            uint32 rom_line = 0;

            valid = dnx_hbmc_read_firmware_line_from_rom(unit, fp, &rom_line);

            if (valid)
            {
                switch (line_index)
                {
                    case 0:
                    {
                        buf_data1 = rom_line;
                        break;
                    }
                    case 1:
                    {
                        buf_data1 |= (rom_line << 12);
                        break;
                    }
                    case 2:
                    {
                        buf_data1 |= ((rom_line & 0xff) << 24);
                        buf_data2 = (rom_line >> 8);
                        break;
                    }
                    case 3:
                    {
                        buf_data2 |= (rom_line << 4);
                        break;
                    }
                    case 4:
                    {
                        buf_data2 |= (rom_line << 16);
                        break;
                    }
                    case 5:
                    {
                        buf_data2 |= ((rom_line & 0xf) << 28);
                        buf_data3 = (rom_line >> 4);
                        break;
                    }
                    case 6:
                    {
                        buf_data3 |= (rom_line << 8);
                        break;
                    }
                    case 7:
                    {
                        buf_data3 |= (rom_line << 20);
                        break;
                    }
                }
            }
            else
            {
                break;
            }
        }

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_BURST_DATA, INST_SINGLE, buf_data1);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_BURST_DATA, INST_SINGLE, buf_data2);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_BURST_DATA, INST_SINGLE, buf_data3);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

        line_number += 8;
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_CNTL_EN, INST_SINGLE, FALSE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IMEM_ECC_ENABLE, INST_SINGLE, TRUE);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DMEM_ECC_ENABLE, INST_SINGLE, TRUE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SNAP_ENABLE, INST_SINGLE, TRUE);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): Waiting for Spico to initialize\n"), FUNCTION_NAME(), hbmc_index));
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_SNAP_ACCESS, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, hbmc_index);
    SHR_IF_ERR_EXIT(dnxcmn_polling
                    (unit, 1000000, 500, entry_handle_id, DBAL_FIELD_SNAP_STATE,
                     dnx_data_dram.firmware.snap_state_init_done_get(unit)));
    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "%s(hbmc%d): Spico initialized\n"), FUNCTION_NAME(), hbmc_index));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_info_get(unit, hbmc_index, &firmware_info));
    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): firmware revision 0x%x build id 0x%x\n"), FUNCTION_NAME(), hbmc_index,
                 firmware_info.revision, firmware_info.build_id));

exit:
    if (fp)
    {
        sal_fclose(fp);
    }
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_setup_dll_and_qc(
    int unit,
    uint32 hbmc_index,
    uint32 hbm_freq_x2_mhz)
{
    int is_range_found = FALSE;
    int nof_freq_ranges = dnx_data_dram.hbm.dll_and_qc_conf_vals_per_freq_range_info_get(unit)->key_size[0];
    const dnx_data_dram_hbm_dll_and_qc_conf_vals_per_freq_range_t *entry;
    uint32 dll_clk;
    uint32 qc_delay;
    SHR_FUNC_INIT_VARS(unit);

    for (int i = 0; i < nof_freq_ranges; i++)
    {
        entry = dnx_data_dram.hbm.dll_and_qc_conf_vals_per_freq_range_get(unit, i);

        if (hbm_freq_x2_mhz <= entry->freq_x2_range_upper_limit)
        {
            is_range_found = TRUE;
            dll_clk = entry->dll_config_val;
            qc_delay = DNX_HBMC_FIRMWARE_HBM2E_GET_QC_DELAY(entry->qc_ck_delay_config_val,
                                                            entry->qc_wr_delay_config_val,
                                                            entry->qc_rd_delay_config_val);
            break;
        }
    }

    if (!is_range_found)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error: DRAM frequency out of range");
    }

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): configuring DLL = %x\n"), FUNCTION_NAME(), hbmc_index, dll_clk));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_sbus_dll_config_clock_set(unit, hbmc_index, dll_clk));

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): configuring QC delay = %x\n"), FUNCTION_NAME(), hbmc_index, qc_delay));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_QC_DELAY,
                     qc_delay));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_phy_params_init(
    int unit,
    int hbmc_index)
{
    dnx_hbmc_mode_registers_t mrs;
    uint32 dq_write_parity = dnx_data_dram.general_info.dq_write_parity_get(unit);
    uint32 dq_read_parity = dnx_data_dram.general_info.dq_read_parity_get(unit);
    uint32 parity_latency = dnx_data_dram.general_info.parity_latency_get(unit);
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set(unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_DIV_MODE, 0));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_FREQ,
                     (dnx_data_dram.general_info.frequency_get(unit) * 2)));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_T_RDLAT_OFFSET,
                     dnx_data_dram.hbm.t_rdlat_offset_get(unit)));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MAX_TIMEOUT,
                     dnx_data_dram.firmware.max_timeout_get(unit)));

    if (dq_read_parity == 0 && dq_write_parity == 0)
    {
        parity_latency = 0;
    }
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_PARITY_LATENCY, parity_latency));

    dnx_hbmc_mode_registers_default_values_get(unit, FALSE, &mrs);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER0, mrs.mr_val[0]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER1, mrs.mr_val[1]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER2, mrs.mr_val[2]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER3, mrs.mr_val[3]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER4, mrs.mr_val[4]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER5, mrs.mr_val[5]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER6, mrs.mr_val[6]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER7, mrs.mr_val[7]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER8, mrs.mr_val[8]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_PARAM_HBM_MODE_REGISTER15, mrs.mr_val[15]));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_phy_with_hbm2e_support_params_init(
    int unit,
    int is_hbm2e,
    int hbmc_index)
{

    dnx_hbmc_mode_registers_t mrs;
    uint32 dq_write_parity = dnx_data_dram.general_info.dq_write_parity_get(unit);
    uint32 dq_read_parity = dnx_data_dram.general_info.dq_read_parity_get(unit);
    uint32 parity_latency = dnx_data_dram.general_info.parity_latency_get(unit);
    uint32 hbm_freq_x2_mhz = dnx_data_dram.general_info.frequency_get(unit) * 2;
    const int DNX_HBMC_FIRMWARE_READ_ONLY_MAX_TEMP = 0;
    SHR_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_CLQ_F1_FREQ,
                     hbm_freq_x2_mhz));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_CLK_1500_DIVIDER,
                     0));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_T_RDLAT_OFFSET,
                     dnx_data_dram.hbm.t_rdlat_offset_get(unit)));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index,
                     (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_READ_ALL_TEMP_SENSORS,
                     DNX_HBMC_FIRMWARE_READ_ONLY_MAX_TEMP));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MAX_TIMEOUT,
                     dnx_data_dram.firmware.max_timeout_get(unit)));

    if (dq_read_parity == 0 && dq_write_parity == 0)
    {
        parity_latency = 0;
    }

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_PAR_ENABLE,
                     (! !dq_write_parity << 1) | ! !dq_read_parity));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_PAR_LATENCY,
                     parity_latency));

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_setup_dll_and_qc(unit, hbmc_index, hbm_freq_x2_mhz));

    dnx_hbmc_mode_registers_default_values_get(unit, is_hbm2e, &mrs);
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR0,
                     mrs.mr_val[0]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR1,
                     mrs.mr_val[1]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR2,
                     mrs.mr_val[2]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR3,
                     mrs.mr_val[3]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR4,
                     mrs.mr_val[4]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR5,
                     mrs.mr_val[5]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR6,
                     mrs.mr_val[6]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR7,
                     mrs.mr_val[7]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR8,
                     mrs.mr_val[8]));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_param_set
                    (unit, hbmc_index, (dnx_hbmc_firmware_param_e) DNX_HBMC_HBM2E_FIRMWARE_PARAM_HBM_MR15,
                     mrs.mr_val[15]));

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_phy_init(
    int unit,
    int hbmc_index)
{
    const int is_phy_with_hbm2e_support = dnx_data_dram.hbm.feature_get(unit, dnx_data_dram_hbm_hbm2e_support);

    const int is_hbm2e = FALSE;
    SHR_FUNC_INIT_VARS(unit);

    if (dnx_data_dram.hbm.feature_get(unit, dnx_data_dram_hbm_sbus_execute_delay))
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_dbal_access_sbus_master_execute_delay_set(unit,
                                                                           hbmc_index,
                                                                           dnx_data_dram.
                                                                           hbm.sbus_execute_delay_default_get(unit)));
    }

    if (is_phy_with_hbm2e_support)
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_dbal_access_phy_reset_set(unit, hbmc_index, 0));
    }

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_sbus_clock_divider_set
                    (unit, hbmc_index, dnx_data_dram.firmware.sbus_clock_divider_get(unit)));

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): take phy control out of reset\n"), FUNCTION_NAME(), hbmc_index));
    SHR_IF_ERR_EXIT(dnx_hbmc_dbal_access_phy_control_out_of_reset_config(unit, hbmc_index));

    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "%s(hbmc%d): upload firmware\n"), FUNCTION_NAME(), hbmc_index));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_upload(unit, hbmc_index, is_hbm2e));

    LOG_VERBOSE(BSL_LOG_MODULE, (BSL_META_U(unit, "%s(hbmc%d): set firmware params\n"), FUNCTION_NAME(), hbmc_index));
    if (is_phy_with_hbm2e_support)
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_phy_with_hbm2e_support_params_init(unit, is_hbm2e, hbmc_index));
    }
    else
    {
        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_phy_params_init(unit, hbmc_index));
    }

    LOG_VERBOSE(BSL_LOG_MODULE,
                (BSL_META_U(unit, "%s(hbmc%d): Launch firmware operation RESET_PHY_AND_HBM\n"),
                 FUNCTION_NAME(), hbmc_index));
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_launch_operation
                    (unit, hbmc_index, DNX_HBMC_FIRMWARE_ALL_CHANNELS, DNX_HBMC_FIRMWARE_OPERATION_RESET_PHY_AND_HBM));
exit:
    SHR_FUNC_EXIT;
}

#ifdef INCLUDE_AAPL

static int
dnx_hbmc_firmware_aapl_sbus_access_internal(
    Aapl_t * aapl,
    uint addr,
    unsigned char reg_addr,
    unsigned char command,
    uint * sbus_data)
{
    uint32 entry_handle_id;
    int unit = 0;
    Avago_addr_t addr_struct;
    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    avago_addr_to_struct(addr, &addr_struct);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_HBMC_PHY_FIRMWARE_GENERAL_ACCESS, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_HBMC_INDEX, addr_struct.ring);
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_ADDRESS, addr_struct.sbus);
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_REG_ADDRESS, reg_addr);

    if (command == DNX_HBMC_AAPL_CMD_READ)
    {
        dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_DATA, INST_SINGLE, sbus_data);
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));
    }
    else
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_DATA, INST_SINGLE, *sbus_data);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

static uint
dnx_hbmc_firmware_aapl_sbus_access(
    Aapl_t * aapl,
    uint addr,
    unsigned char reg_addr,
    unsigned char command,
    uint * sbus_data)
{
    return (_SHR_E_FAILURE
            (dnx_hbmc_firmware_aapl_sbus_access_internal(aapl, addr, reg_addr, command, sbus_data))) ? FALSE : TRUE;
}

static uint
dnx_hbmc_firmware_aapl_jtagid_get_internal(
    int unit)
{

    int nof_drams = dnx_data_dram.general_info.max_nof_drams_get(unit);
    uint jtagid = 0;

    switch (nof_drams)
    {
        case 1:
            jtagid = DNX_HBMC_FIRMWARE_JTAGID_ONE_HBM;
            break;

        case 2:
            jtagid = DNX_HBMC_FIRMWARE_JTAGID_TWO_HBMS;
            break;

        case 3:
            jtagid = DNX_HBMC_FIRMWARE_JTAGID_THREE_HBM;
            break;
    }

    return jtagid;
}

static uint
dnx_hbmc_firmware_aapl_jtagid_get(
    Aapl_t * aapl,
    uint unit)
{
    return dnx_hbmc_firmware_aapl_jtagid_get_internal(unit);
}

#define AAPL_IF_ERR_EXIT(_expr)      \
do                      \
{                       \
  int _rv = _expr;      \
  if (SHR_FAILURE(_rv)) \
  {                     \
    _func_rv = _SHR_E_FAIL ;  \
    LOG_ERROR_EX(BSL_LOG_MODULE,                       \
      " Error '%s' indicated ; %s%s%s\r\n" ,           \
      shrextend_errmsg_get(_func_rv) ,EMPTY,EMPTY,EMPTY) ;  \
    SHR_EXIT() ;        \
  }                     \
} while (0)

shr_error_e
dnx_hbmc_firmware_aapl_cmd_run(
    int unit,
    uint32 dram_index,
    dnx_hbmc_firmware_aapl_cmd_e aapl_cmd,
    dnx_hbmc_firmware_aapl_params_t * aapl_params,
    int *cmd_return_code)
{
    int is_mutex_locked = FALSE;
    Aapl_t *aapl = aapl_construct();
    Avago_addr_t addr_struct;
    uint32 sbus_addr = 0;
    int hbm2e = FALSE;
    SHR_FUNC_INIT_VARS(unit);
    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_mutex_take(unit));
    *cmd_return_code = 0;
    is_mutex_locked = TRUE;

    if (aapl_params->debug)
    {
        aapl->debug = AVAGO_INFO;
    }

    aapl_register_jtag_idcode_fn(aapl, dnx_hbmc_firmware_aapl_jtagid_get);
    AAPL_IF_ERR_EXIT(aapl->return_code);

    aapl_register_sbus_fn(aapl, dnx_hbmc_firmware_aapl_sbus_access, NULL, NULL);
    AAPL_IF_ERR_EXIT(aapl->return_code);

    aapl_connect(aapl, 0, 0);
    aapl_get_ip_info(aapl, 0);

    avago_addr_init(&addr_struct);
    addr_struct.sbus = 0xfd;
    addr_struct.ring = dram_index;
    sbus_addr = avago_struct_to_addr(&addr_struct);

    hbm2e = avago_hbm2e_check(aapl, sbus_addr);

    if (aapl_params->freq != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        if (hbm2e)
        {
            LOG_CLI((BSL_META("Setting hbm_clk_f1_freq parameter to %d at Sbus addr %s\n"),
                     aapl_params->freq, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_set_parameter(aapl, sbus_addr, AVAGO_HBM2E_CLK_F1_FREQ, aapl_params->freq));
        }
        else
        {
            LOG_CLI((BSL_META("Setting hbm_freq parameter to %d at Sbus addr %s\n"),
                     aapl_params->freq, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_set_parameter(aapl, sbus_addr, AVAGO_HBM_FREQ, aapl_params->freq));
        }
    }

    if (aapl_params->spico_freq != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_spico_freq parameter to %d at Sbus addr %s\n"),
                 aapl_params->spico_freq, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_SPICO_FREQ : AVAGO_HBM_SPICO_FREQ,
                          aapl_params->spico_freq));
    }

    if (aapl_params->save_soft_lane_repairs != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_save_soft_lane_repairs parameter to %d at Sbus addr %s\n"),
                 aapl_params->save_soft_lane_repairs, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_SAVE_SOFT_LANE_REPAIRS : AVAGO_HBM_SAVE_SOFT_LANE_REPAIRS,
                          aapl_params->save_soft_lane_repairs));
    }

    if (aapl_params->div_mode != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        if (hbm2e)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "ERROR: div_mode not supported for hbm2e\n");
        }
        else
        {
            LOG_CLI((BSL_META("Setting hbm_div_mode parameter to %d at Sbus addr %s\n"),
                     aapl_params->div_mode, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_set_parameter(aapl, sbus_addr, AVAGO_HBM_DIV_MODE, aapl_params->div_mode));
        }
    }

    if (aapl_params->pl != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_parity_latency parameter to %d at Sbus addr %s\n"),
                 aapl_params->pl, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_PHY_CONFIG_PAR_LATENCY : AVAGO_HBM_PARITY_LATENCY, aapl_params->pl));
    }

    if (aapl_params->t_rdlat_offset != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_t_rdlat_offset parameter to %d at Sbus addr %s\n"),
                 aapl_params->t_rdlat_offset, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_PHY_CONFIG_T_RDLAT_OFFSET : AVAGO_HBM_T_RDLAT_OFFSET,
                          aapl_params->t_rdlat_offset));
    }

    if (aapl_params->hbm_drvstr != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_drvstr to %d at Sbus addr %s\n"), aapl_params->hbm_drvstr,
                 aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_hbm_drv_str(aapl, sbus_addr, aapl_params->hbm_drvstr));
    }

    if (aapl_params->phy_drvstr != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting phy_drvstr to %d at Sbus addr %s\n"), aapl_params->phy_drvstr,
                 aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_phy_drv_str(aapl, sbus_addr, aapl_params->phy_drvstr));
    }

    if (aapl_params->dll != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting dll delay_config to %d at Sbus addr %s\n"), aapl_params->dll,
                 aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_QC_DLL_CONFIG : AVAGO_HBM_DELAY_CONFIG_DLL,
                          (aapl_params->dll & 0x3) | ((aapl_params->dll & 0x3) << 2)));
    }

    if (aapl_params->qc_rd != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT
        || aapl_params->qc_wr != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT
        || aapl_params->qc_ck != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        if (aapl_params->qc_rd == DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT
            || aapl_params->qc_wr == DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT
            || aapl_params->qc_ck == DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Must set rd, wr, and ck qc values.\n");
        }
        LOG_CLI((BSL_META("Setting phy quarter-cycle to rd:%d wr:%d ck:%d at Sbus addr %s\n"),
                 aapl_params->qc_rd, aapl_params->qc_wr, aapl_params->qc_ck, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_phy_quarter_cycle
                         (aapl, sbus_addr, aapl_params->qc_rd, aapl_params->qc_wr, aapl_params->qc_ck));
    }

    if (aapl_params->qc != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting phy quarter-cycle to rd:%d wr:%d ck:%d at Sbus addr %s\n"),
                 aapl_params->qc, aapl_params->qc, aapl_params->qc, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_phy_quarter_cycle
                         (aapl, sbus_addr, aapl_params->qc, aapl_params->qc, aapl_params->qc));
    }

    if (aapl_params->mmt_rl != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_rl_override parameter to %d at Sbus addr %s\n"),
                 aapl_params->mmt_rl, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_MMT_RL : AVAGO_HBM_RL_OVERRIDE, aapl_params->mmt_rl));
    }

    if (aapl_params->mmt_dbi != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_mmt_dbi parameter to %d at Sbus addr %s\n"),
                 aapl_params->mmt_dbi, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_MMT_DBI_ENABLE : AVAGO_HBM_DBI, aapl_params->mmt_dbi));
    }

    if (aapl_params->mmt_read_repeat != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_mmt_read_repeat parameter to %d at Sbus addr %s\n"),
                 aapl_params->mmt_read_repeat, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_MMT_READ_REPEAT : AVAGO_HBM_MMT_READ_REPEAT,
                          aapl_params->mmt_read_repeat));
    }

    if (aapl_params->mmt_t_rdlat_offset != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_mmt_t_rdlat_offset parameter to %d at Sbus addr %s\n"),
                 aapl_params->mmt_t_rdlat_offset, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr,
                          hbm2e ? AVAGO_HBM2E_MMT_T_RDLAT_OFFSET : AVAGO_MMT_T_RDLAT_OFFSET,
                          aapl_params->mmt_t_rdlat_offset));
    }

    if (aapl_params->mmt_rddata_en != DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT)
    {
        LOG_CLI((BSL_META("Setting hbm_mmt_rddata_en parameter to %d at Sbus addr %s\n"),
                 aapl_params->mmt_rddata_en, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                         (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_MMT_RDDATA_EN : AVAGO_HBM_MMT_RDDATA_EN,
                          aapl_params->mmt_rddata_en));
    }

    if (aapl_params->reset == TRUE)
    {
        Avago_hbm_operation_results_t results;
        LOG_CLI((BSL_META("Sending reset to PHY/HBM%u at Sbus addr %s\n"), dram_index, aapl_addr_to_str(sbus_addr)));
        AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                         (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_OP_RESET : AVAGO_HBM_OP_RESET, &results,
                          aapl_params->operation_timeout));
        AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
    }

    switch (aapl_cmd)
    {
        case DNX_HBMC_FIRMWARE_AAPL_CMD_HBM_DIAG:
        {
            LOG_CLI((BSL_META("Begin HBM diagnostics for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_diagnostics(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_OPERATION:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Begin HBM%u operation 0x%02x for all channels at Sbus addr %s\n"),
                     dram_index, aapl_params->operation, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr, aapl_params->operation, &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_OPERATION_START:
        {
            LOG_CLI((BSL_META("Begin HBM%u operation 0x%02x for all channels at Sbus addr %s\n"),
                     dram_index, aapl_params->operation, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation_nowait
                             (aapl, sbus_addr, aapl_params->operation, aapl_params->operation_timeout));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_OPERATION_RESULTS:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Waiting for HBM%u operation 0x%02x for all channels at Sbus addr %s\n"),
                     dram_index, aapl_params->operation, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_check_operation
                             (aapl, sbus_addr, aapl_params->operation, &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DEVICE_ID:
        {
            Avago_hbm_device_id_t device_id;
            LOG_CLI((BSL_META("Reading device ID for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_read_device_id(aapl, sbus_addr, &device_id));
            AAPL_IF_ERR_EXIT(avago_hbm_print_device_id(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_TEMP:
        {
            int temp;
            LOG_CLI((BSL_META("Reading temperature for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            temp = avago_hbm_read_device_temp(aapl, sbus_addr);
            LOG_CLI((BSL_META("HBM%u Temp: %d\n"), dram_index, temp));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_TEMP_DIAG:
        {
            LOG_CLI((BSL_META("Begin temperature diagnostics for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_temp_diagnostics(aapl, sbus_addr, aapl_params->count));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_INIT_NWL:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Initializing NWL memory controllers at Sbus addr %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr, AVAGO_HBM_OP_INITIALIZE_NWL_MCS, &results,
                              aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CTC_INIT:
        {
            LOG_CLI((BSL_META("Begin CTC continuous mode (pattern %d) for HBM%u at Sbus addr %s\n"),
                     aapl_params->pattern, dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_ctc_start(aapl, sbus_addr, aapl_params->pattern, 1));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CTC_START:
        {
            LOG_CLI((BSL_META("Begin CTC continuous mode (pattern %d) for HBM%u at Sbus addr %s\n"),
                     aapl_params->pattern, dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_ctc_start(aapl, sbus_addr, aapl_params->pattern, 0));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CTC_STOP:
        {
            LOG_CLI((BSL_META("Stopping CTC for HBM%u at Sbus addr %s\n"), dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_ctc_stop(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CTC_STATUS:
        {
            uint32 apc_addr;
            LOG_CLI((BSL_META("Begin CTC status for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_get_apc_addr(aapl, sbus_addr, &apc_addr));
            AAPL_IF_ERR_EXIT(avago_hbm_print_ctc_results(aapl, apc_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CTC_DIAG:
        {
            LOG_CLI((BSL_META("Begin HBM CTC diagnostics for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_ctc_diagnostics(aapl, sbus_addr, 1, 1));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_RUN:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            uint32 pattern = avago_hbm_get_parameter(aapl, sbus_addr,
                                                     hbm2e ? AVAGO_HBM2E_MMT_CONFIGURATION :
                                                     AVAGO_HBM_MMT_CONFIGURATION);
            LOG_CLI((BSL_META("Begin MMT continuous mode (pattern %u) for HBM%u at Sbus addr %s\n"),
                     pattern, dram_index, aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_OP_MMT : AVAGO_HBM_OP_RUN_MMT,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                AAPL_IF_ERR_EXIT(avago_hbm_print_mmt_results(aapl, sbus_addr, 0));
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_START:
        {
            uint32 pattern = aapl_params->pattern;
            if (pattern == -1)
            {
                pattern =
                    avago_hbm_get_parameter(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_MMT_CONFIGURATION : AVAGO_HBM_MMT_CONFIGURATION);
            }
            LOG_CLI((BSL_META("Begin MMT continuous mode (pattern %u) for HBM%u at Sbus addr %s\n"),
                     pattern, dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_mmt_start(aapl, sbus_addr, pattern));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_STOP:
        {
            int rc;
            LOG_CLI((BSL_META("Stopping MMT for HBM%u at Sbus addr %s\n"), dram_index, aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_mmt_stop(aapl, sbus_addr);
            if (rc != 0)
            {
                AAPL_IF_ERR_EXIT(avago_hbm_print_mmt_results(aapl, sbus_addr, 0));
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_STATUS:
        {
            LOG_CLI((BSL_META("Begin MMT status for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_print_mmt_results(aapl, sbus_addr, aapl_params->state));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_LOOP:
        {
            uint32 pattern = aapl_params->pattern;
            if (pattern == -1)
            {
                pattern =
                    avago_hbm_get_parameter(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_MMT_CONFIGURATION : AVAGO_HBM_MMT_CONFIGURATION);
            }
            LOG_CLI((BSL_META("Looping on MMT (pattern %u) for HBM%u at Sbus addr %s\n"), pattern,
                     dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_mmt_loop(aapl, sbus_addr, aapl_params->count, pattern));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_MARGIN:
        {
            if (hbm2e)
            {
                LOG_CLI((BSL_META("Eye margin test not currently implmented for hbm2e\n")));
            }
            else
            {
                Avago_hbm_eye_t hbm_eye;
                LOG_CLI((BSL_META("Begin MMT margin test for HBM%u at Sbus addr %s\n"), dram_index,
                         aapl_addr_to_str(sbus_addr)));
                AAPL_IF_ERR_EXIT(avago_hbm_mmt_margin(aapl, sbus_addr, &hbm_eye));
                AAPL_IF_ERR_EXIT(avago_hbm_print_mmt_eye(aapl, &hbm_eye));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MMT_DIAG:
        {
            LOG_CLI((BSL_META("Begin HBM MMT diagnostics for HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_mmt_diagnostics(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MRS:
        {
            LOG_CLI((BSL_META("Reading MRS for HBM%u at Sbus addr %s\n"), dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_print_mrs(aapl, sbus_addr, aapl_params->channel));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_TMRS:
        {
            LOG_CLI((BSL_META("Sending TMRS to HBM%u at Sbus addr %s\n"), dram_index, aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_tmrs
                             (aapl, sbus_addr, aapl_params->tmrs_code, aapl_params->channel, aapl_params->safety));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_RESET:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Sending reset to PHY/HBM%u at Sbus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_OP_RESET : AVAGO_HBM_OP_RESET, &results,
                              aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_PARAM:
        {
            if (aapl_params->param_value == -1)
            {
                uint32 param_value = 0;
                LOG_CLI((BSL_META("Reading HBM%u firmware param %u at SBus addr %s\n"), dram_index,
                         aapl_params->param, aapl_addr_to_str(sbus_addr)));
                param_value = avago_hbm_get_parameter(aapl, sbus_addr, aapl_params->param);
                LOG_CLI((BSL_META("%u\n"), param_value));
            }
            else
            {
                uint32 param_value = 0;
                LOG_CLI((BSL_META("Writing HBM%u firmware param %u to %d at SBus addr %s\n"), dram_index,
                         aapl_params->param, aapl_params->param_value, aapl_addr_to_str(sbus_addr)));
                AAPL_IF_ERR_EXIT(avago_hbm_set_parameter
                                 (aapl, sbus_addr, aapl_params->param, aapl_params->param_value));
                param_value = avago_hbm_get_parameter(aapl, sbus_addr, aapl_params->param);
                LOG_CLI((BSL_META("%u\n"), param_value));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_READ_SPARES:
        {
            LOG_CLI((BSL_META("Reading HBM%u firmware spare registers at SBus addr %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_READ_LANE_REPAIRS:
        {
            LOG_CLI((BSL_META("Reading HBM%u lane repairs at Sbus address %s\n"), dram_index,
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_print_lane_repairs(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AERR:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aerr operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AERR : AVAGO_HBM_OP_AERR_TEST, &results,
                                            aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "AERR_0"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 1, "AERR_1"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AERR_ILB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aerr ilb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AERR_ILB : AVAGO_HBM_OP_AERR_ILB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "AERR_0"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 1, "AERR_1"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AERR_SLB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aerr slb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AERR_SLB : AVAGO_HBM_OP_AERR_SLB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "AERR_0"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 1, "AERR_1"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DERR:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running derr operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_DERR : AVAGO_HBM_OP_DERR_TEST, &results,
                                            aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "PHY"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DERR_ILB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running derr ilb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_DERR_ILB : AVAGO_HBM_OP_DERR_ILB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "PHY"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DERR_SLB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running derr slb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_DERR_SLB : AVAGO_HBM_OP_DERR_SLB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "PHY"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AWORD:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aword operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AWORD : AVAGO_HBM_OP_AWORD_TEST,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 1, 0, "HBM"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AWORD_ILB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aword ilb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AWORD_ILB : AVAGO_HBM_OP_AWORD_ILB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 1, 0, "HBM"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_AWORD_SLB:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running aword slb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_AWORD_SLB : AVAGO_HBM_OP_AWORD_SLB,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 1, 0, "HBM"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DWORD:
        {
            if (hbm2e)
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword read operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_READ, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }

                LOG_CLI((BSL_META("Running dword write operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_WRITE, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            else
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM_OP_DWORD_TEST, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "PHY"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 1, 1, "HBM"));
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DWORD_ILB:
        {
            if (hbm2e)
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword upper ilb operation at Sbus address %s\n"),
                         aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_UPPER_ILB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }

                LOG_CLI((BSL_META("Running dword lower ilb operation at Sbus address %s\n"),
                         aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_LOWER_ILB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            else
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword ilb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM_OP_DWORD_ILB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "DWORD_LOWER"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 1, "DWORD_UPPER"));
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DWORD_SLB:
        {
            if (hbm2e)
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword upper slb operation at Sbus address %s\n"),
                         aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_UPPER_SLB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }

                LOG_CLI((BSL_META("Running dword lower slb operation at Sbus address %s\n"),
                         aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM2E_OP_BIST_DWORD_LOWER_SLB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            else
            {
                int rc;
                Avago_hbm_operation_results_t results;
                LOG_CLI((BSL_META("Running dword slb operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
                rc = avago_hbm_launch_operation(aapl, sbus_addr, AVAGO_HBM_OP_DWORD_SLB, &results,
                                                aapl_params->operation_timeout);
                AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
                if (rc != 0)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "DWORD_LOWER"));
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 1, "DWORD_UPPER"));
                    AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
                }
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DWORD_READ:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running dword read operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_DWORD_READ : AVAGO_HBM_OP_DWORD_READ,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 0, 0, "PHY"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_DWORD_WRITE:
        {
            int rc;
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running dword write operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            rc = avago_hbm_launch_operation(aapl, sbus_addr,
                                            hbm2e ? AVAGO_HBM2E_OP_BIST_DWORD_WRITE : AVAGO_HBM_OP_DWORD_WRITE,
                                            &results, aapl_params->operation_timeout);
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            if (rc != 0)
            {
                if (!hbm2e)
                {
                    AAPL_IF_ERR_EXIT(avago_hbm_read_lfsr_compare_sticky(aapl, sbus_addr, 1, 1, "HBM"));
                }
                AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            }
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_LANE_REPAIR:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running lane_repair operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr,
                              hbm2e ? AVAGO_HBM2E_OP_LANE_REPAIR : AVAGO_HBM_OP_LANE_REPAIR, &results,
                              aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            AAPL_IF_ERR_EXIT(avago_hbm_print_spare_results(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_BURN_LANE_REPAIRS:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running burn lane repairs operation at Sbus address %s\n"),
                     aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr,
                              hbm2e ? AVAGO_HBM2E_OP_BURN_LANE_REPAIRS : AVAGO_HBM_OP_BURN_HARD_REPAIRS,
                              &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CATTRIP:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running cattrip operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr, hbm2e ? AVAGO_HBM2E_OP_TEST_CATTRIP : AVAGO_HBM_OP_CATTRIP,
                              &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_RESET_MRS:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running reset_mrs operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr,
                              hbm2e ? AVAGO_HBM2E_OP_PROGRAM_MRS : AVAGO_HBM_OP_RESET_MODE_REGISTERS,
                              &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_RESET_PHY_CONFIG:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running reset_phy_config operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr,
                              hbm2e ? AVAGO_HBM2E_OP_PROGRAM_PHY_CONFIG_AND_QC :
                              AVAGO_HBM_OP_RESET_PHY_CONFIG, &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_SAMSUNG_CHIPPING:
        {
            Avago_hbm_operation_results_t results;
            LOG_CLI((BSL_META("Running chipping operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_launch_operation
                             (aapl, sbus_addr,
                              hbm2e ? AVAGO_HBM2E_OP_TEST_CHIPPING : AVAGO_HBM_OP_SAMSUNG_CHIPPING_TEST,
                              &results, aapl_params->operation_timeout));
            AAPL_IF_ERR_EXIT(avago_hbm_print_operation_results(aapl, &results));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_CELL_REPAIR:
        {
            LOG_CLI((BSL_META("Running cell repair operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_cell_repair
                             (aapl, sbus_addr, aapl_params->channel, aapl_params->pc, aapl_params->sid,
                              aapl_params->bank, aapl_params->row, aapl_params->hard_repair));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_FUSE_SCAN:
        {
            uint result;
            LOG_CLI((BSL_META("Running cell fuse_scan operation at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_fuse_scan
                             (aapl, sbus_addr, aapl_params->channel, aapl_params->pc, aapl_params->sid,
                              aapl_params->bank, &result));
            LOG_CLI((BSL_META("Burned Fuses: 0b%d%d%d%d\n"), ((result >> 3) & 1), ((result >> 2) & 1),
                     ((result >> 1) & 1), ((result >> 0) & 1)));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_SOFT_LANE_REPAIR:
        {
            LOG_CLI((BSL_META("Running soft lane repair at Sbus address %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_soft_lane_repair
                             (aapl, sbus_addr, aapl_params->channel, aapl_params->repair_codes[0],
                              aapl_params->repair_codes[1], aapl_params->repair_codes[2]));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_PARAM_DIAG:
        {
            LOG_CLI((BSL_META("Begin Parameter diagnostics for HBM at Sbus addr %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_parameter_diagnostics(aapl, sbus_addr));
            break;
        }
        case DNX_HBMC_FIRMWARE_AAPL_CMD_MBIST_DIAG:
        {
            LOG_CLI((BSL_META("Begin HBM MBIST diagnostics for HBM at Sbus addr %s\n"), aapl_addr_to_str(sbus_addr)));
            AAPL_IF_ERR_EXIT(avago_hbm_run_mbist_diagnostics(aapl, sbus_addr));
            break;
        }
        default:
        {
            SHR_ERR_EXIT(_SHR_E_INTERNAL, "Unknown aapl command %d\n", aapl_cmd);
        }
    }

exit:
    if (is_mutex_locked)
    {
        SHR_IF_ERR_CONT(dnx_hbmc_firmware_mutex_give(unit));
    }
    if (aapl != NULL)
    {
        *cmd_return_code = aapl->return_code;
        aapl_destruct(aapl);
    }
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_full_aapl_diagnostics_run(
    int unit,
    uint32 dram_start,
    uint32 dram_end,
    dnx_hbmc_firmware_aapl_params_t * aapl_params,
    int *cmd_return_code_array)
{
    uint32 dram_index;
    SHR_FUNC_INIT_VARS(unit);

    for (dram_index = dram_start; dram_index <= dram_end; ++dram_index)
    {
        int is_valid = 0;

        SHR_IF_ERR_EXIT(dnx_dram_index_is_valid(unit, dram_index, &is_valid));
        if (!is_valid)
        {
            LOG_CLI((BSL_META("Dram index %d is not valid - and is skipped\n"), dram_index));
            continue;
        }

        SHR_IF_ERR_EXIT(dnx_hbmc_firmware_aapl_cmd_run
                        (unit, dram_index, DNX_HBMC_FIRMWARE_AAPL_CMD_HBM_DIAG, aapl_params,
                         &cmd_return_code_array[dram_index]));
        if (cmd_return_code_array[dram_index] == 0)
        {
            LOG_CLI((BSL_META("PASS: all AAPL Diagnostics for DRAM %d passed\n"), dram_index));
        }
        else
        {
            LOG_CLI((BSL_META("FAIL: AAPL Diagnostics for DRAM %d returned code %d\n"), dram_index,
                     cmd_return_code_array[dram_index]));
        }

    }

exit:
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_hbmc_firmware_default_full_aapl_diagnostics_run(
    int unit,
    int *cmd_return_code_array)
{
    dnx_hbmc_firmware_aapl_params_t aapl_params;
    uint32 dram_start = 0;
    uint32 dram_end = dnx_data_dram.general_info.max_nof_drams_get(unit) - 1;
    SHR_FUNC_INIT_VARS(unit);

    sal_memset(&aapl_params, 0, sizeof(dnx_hbmc_firmware_aapl_params_t));
    aapl_params.freq = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.spico_freq = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.save_soft_lane_repairs = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.div_mode = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.pl = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.t_rdlat_offset = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.hbm_drvstr = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.phy_drvstr = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.dll = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.qc_rd = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.qc_wr = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.qc_ck = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.qc = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.mmt_rl = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.mmt_dbi = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.mmt_read_repeat = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.mmt_t_rdlat_offset = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;
    aapl_params.mmt_rddata_en = DNX_HBMC_FIRMWARE_AAPL_CMD_DEFAULT;

    SHR_IF_ERR_EXIT(dnx_hbmc_firmware_full_aapl_diagnostics_run(unit, dram_start, dram_end, &aapl_params,
                                                                cmd_return_code_array));
exit:
    SHR_FUNC_EXIT;

}

#endif
