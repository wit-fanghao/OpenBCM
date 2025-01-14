
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_EVENTOR

#ifdef _SOC_DRV_H
#undef _SOC_DRV_H
#endif
#include <soc/sand/shrextend/shrextend_debug.h>
#include <soc/drv.h>
#include <soc/mem.h>

#if !defined(BCM_ESW_SUPPORT)

#ifdef _SOC_MEMREGS_H
#undef _SOC_MEMREGS_H
#endif

#endif
#include <soc/mcm/memregs.h>

#include <soc/sbusdma.h>
#include <soc/cm.h>
#include <bcm/instru.h>
#include <bcm_int/dnx/algo/port/algo_port_mgmt.h>
#include <bcm_int/dnx/algo/port/algo_port_utils.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/access/instru_access.h>
#include <bcm_int/dnx/instru/instru_eventor.h>

#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_port.h>
#include <soc/dnx/dnx_err_recovery_manager.h>
#include <soc/cmicx.h>

#include "instru_internal.h"

#if defined (ADAPTER_SERVER_MODE) && defined (BCM_ACCESS_SUPPORT)
#include <soc/access/auto_generated/common_enum.h>
#include <soc/access/access.h>
#endif


/* *INDENT-OFF* */


#define DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER 2

#define MAX_NOF_EVENTOR_SBUS_DMA_CHANNELS (2*8)


#define EVENTOR_SRAM_OFFSET_IN_BAR (7*1024*1024)

#define EVENTOR_SRAM_DIRECT_MEM_ACCESS(unit, offset_in_bytes) \
    ((EVENTOR_SRAM_OFFSET_IN_BAR + (offset_in_bytes)))


#define DDC(dnx_data_field) dnx_data_instru.eventor.dnx_data_field##_get(unit)

#define DNX_EVENTOR_NOF_CONTEXTS(unit) DDC(nof_contexts) 
#define DNX_EVENTOR_NOF_BUILDERS(unit) DDC(nof_builders) 
#define DNX_EVENTOR_NOF_SRAM_BANKS(unit) DDC(nof_sram_banks) 
#define DNX_EVENTOR_SRAM_BANK_BITS(unit) DDC(sram_bank_bits) 
#define DNX_EVENTOR_SRAM_BANK_MASK(unit) DDC(sram_bank_mask) 
#define DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) DDC(sram_banks_full_size) 
#define DNX_EVENTOR_SRAM_BANKS_NET_SIZE(unit) DDC(sram_banks_net_size) 
#define DNX_EVENTOR_SRAM_BANKS_FULL_SIZE_WORDS(unit) (DDC(sram_banks_full_size) / 4) 
#define DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit) (DDC(sram_banks_net_size) / 4) 
#define DNX_EVENTOR_BUILDER_MAX_BUFFER_SIZE_WORDS(unit) (DDC(builder_max_buffer_size) / 4) 
#define DNX_EVENTOR_RX_MAX_BUFFER_SIZE_WORDS(unit) (DDC(rx_max_buffer_size) / 4) 
#define DNX_EVENTOR_MAX_BUILDER_TIMEOUT_MS(unit) DDC(builder_max_timeout_ms) 
#define DNX_EVENTOR_AXI_SRAM_OFFSET(unit) DDC(axi_sram_offset) 
#define DNX_EVENTOR_AXI_SRAM_WORD_OFFSET(unit) (DDC(axi_sram_offset) / 4) 


#define DNX_EVENTOR_SBUS_DMA_BUFFERS_DEFAULT_THRESH 10 
#define DNX_EVENTOR_EVPCK_DEFAULT_HEADER_STACK_SIZE 12 
#define DNX_EVENTOR_BUILDER_DEFAULT_TRANSMIT_STACK_SIZE 20 

#define DNX_EVENTOR_BUILDER_QUEUE_MAX_SIZE_TH_GRANULARITY 4 


#define UNUSED_RX_CONTEXT_BUFFER_SIZE 4


#define UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE 8


#define ONE_MS_IN_NS 1000000

#define TOD_COUNTER_MASK COMPILER_64_LITERAL(0xffffffffffff)


#define DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE (1024/8)


#define DNX_EVENTOR_STATE_FLAGS_ENABLED 0x1 


int
dnx_instru_eventor_write_dma_descriptors(
        int unit,
        bcm_eventor_context_id_t context,
        const bcm_instru_eventor_context_conf_t *context_conf);
void
dnx_instru_eventor_generate_tx_event_eventor_header(
        int unit,
        uint32 flags,
        bcm_eventor_context_id_t context,
        bcm_instru_eventor_context_conf_t *context_conf,
        uint32 *eventor_header);


shr_error_e dnx_instru_eventor_init(
    int unit)
{
    uint32 core = 0;
    uint32 entry_handle_id;
    bcm_port_t port;
    int builder;
    int context_index;
    uint8 port_is_found = FALSE;
    const dnx_data_port_static_add_ucode_port_t *ucode_port;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_IPP_FIFO_CFG, &entry_handle_id)); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_ALMOST_FULL_TH, INST_SINGLE, 9); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CODE, INST_SINGLE, 0xfd); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_HANDLER_REQ_EN, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TX_HANDLER_REQ_EN, INST_SINGLE, 0xfc00); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 


    
    
    if (dnx_data_device.general.nof_cores_get(unit) > 1) {
        uint32 max_num_ports = dnx_data_port.general.fabric_port_base_get(unit);
        for (port = 0; port < max_num_ports; port++) {
            ucode_port = dnx_data_port.static_add.ucode_port_get(unit, port);
            if (ucode_port->interface == BCM_PORT_IF_EVENTOR) {
                
                if (port_is_found == FALSE) {
                    core = ucode_port->core;
                    port_is_found = TRUE;
                } else {
                    if (core != ucode_port->core) {
                        SHR_ERR_EXIT(_SHR_E_CONFIG, "All Eventor ports must use the same core\n");
                    }
                }
            }
        }
    }

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_PIPE_SELECTOR, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_PIPE_ID, INST_SINGLE, core); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_RX_EVPCK_HEADER_STACK_SIZE, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_TRANSMIT_HEADER_SIZE, INST_SINGLE,
                                 DDC(rx_evpck_header_size)); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 


    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_RX_SEQUENCE_CHECK, entry_handle_id));
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_SEQUENCE_CHECK_ENABLE, INST_SINGLE, 0); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_ENG_CFG, entry_handle_id));
    for (builder = 0; builder < DNX_EVENTOR_NOF_BUILDERS(unit); builder++) {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_TX_ENGINE_ID, builder); 
        
        
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_PADDING_ENABLE, INST_SINGLE, FALSE); 
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    }

    for (context_index=0; context_index < DNX_EVENTOR_NOF_CONTEXTS(unit); context_index++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.context_type.set(unit, context_index, bcmEventorContextTypeAny));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}



static inline int dnx_instru_eventor_do_buffers_collide(
    uint32 buf1_start, 
    uint32 buf1_end,   
    uint32 buf2_start, 
    uint32 buf2_end)   
{
    return buf1_end > buf2_start && buf2_end > buf1_start;
}


shr_error_e
bcm_dnx_instru_eventor_event_generate(
        int unit,
        uint32 flags,
        bcm_eventor_event_id_t event_id)
{
    uint32 done_indication = 0;
    uint32 entry_handle_id;
    uint8 done_count;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_EVENT_GENERATE, &entry_handle_id)); 
    
    SHR_IF_ERR_EXIT(dbal_entry_clear(unit, entry_handle_id, DBAL_COMMIT));

    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_ID, INST_SINGLE, event_id); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_REQ, INST_SINGLE, 1); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    done_count = 0;
    while (!done_indication && done_count < 5)
    {
        
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_EVENT_GENERATE, entry_handle_id)); 
        SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get(unit, entry_handle_id, DBAL_FIELD_EVENT_DONE, INST_SINGLE,
                                                        &done_indication));
        done_count++;
    }

    if (!done_indication)
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "Eventor generate Event %d failed\n", event_id);
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e bcm_dnx_instru_synced_trigger_time_of_day_get(
    int unit,
    uint32 flags,
    uint64 *time_of_day)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INST_TOD, &entry_handle_id));
    dbal_value_field64_request(unit, entry_handle_id, DBAL_FIELD_TIMESTAMP_NS, INST_SINGLE, time_of_day);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}



shr_error_e
dnx_instru_synced_trigger_enable(
        int unit,
        uint32 nof_sources,
        bcm_instru_synced_trigger_source_type_t *sources,
        uint32 *enable)
{
    uint32 entry_handle_id;
    uint8 source_index;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INST_SYNCED_TRIGGER_CTRL, &entry_handle_id)); 

    
    for (source_index=0; source_index<nof_sources; source_index++)
    {
        switch (sources[source_index]) {
            case bcmInstruSyncedTriggerTypeIcgm:
                dbal_entry_value_field8_set(unit, entry_handle_id, DBAL_FIELD_CGM_ENABLE, INST_SINGLE, enable[source_index]); 
                break;
            case bcmInstruSyncedTriggerTypeNif:
                dbal_entry_value_field8_set(unit, entry_handle_id, DBAL_FIELD_CDU_ENABLE, INST_SINGLE, enable[source_index]); 
                break;
            case bcmInstruSyncedTriggerTypeCrps:
                dbal_entry_value_field8_set(unit, entry_handle_id, DBAL_FIELD_CRPS_ENABLE, INST_SINGLE, enable[source_index]); 
                break;
            default:
                SHR_ERR_EXIT(_SHR_E_PARAM, "Trigger type does not exist %d.\n",sources[source_index]);
                break;
        }
    }

    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    for (source_index=0; source_index<nof_sources; source_index++)
    {
        SHR_IF_ERR_EXIT(instru.trigger_info.enable.set(unit,sources[source_index],enable[source_index]));
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
bcm_dnx_instru_synced_triggers_enable_set(
        int unit,
        uint32 flags,
        uint32 nof_sources,
        bcm_instru_synced_trigger_source_type_t *sources,
        uint32 *enable)
{
    bcm_instru_synced_trigger_config_t config;
    uint32 entry_handle_id;
    uint8 source_index;
    uint64 start_time, start_time_calc, start_time_wrapped;
    uint64 immediate_time;
    uint64 timestamp;
    uint64 nof_triggers;
    uint32 is_continuous;
    uint32 config_flags;
    int wait_till_wrap_around = 0;
    bcm_instru_synced_counters_source_type_t source_type;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    if (nof_sources >= bcmInstruSyncedTriggerTypeCount)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "nof sources %d exceed the number of available sources %d.\n",nof_sources, bcmInstruSyncedTriggerTypeCount);
    }

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INST_SYNCED_COUNTERS_CTRL, &entry_handle_id));

    for (source_index=0; source_index<nof_sources; source_index++)
    {
        if (enable[source_index])
        {
            SHR_IF_ERR_EXIT(instru.trigger_info.trigger_period.get(unit,sources[source_index], &config.trigger_period));
            SHR_IF_ERR_EXIT(instru.trigger_info.nof_triggers.get(unit,sources[source_index], &config.nof_triggers));
            SHR_IF_ERR_EXIT(instru.trigger_info.start_time.get(unit,sources[source_index], &config.start_time));

            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_INST_SYNCED_COUNTERS_CTRL, entry_handle_id));
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_TYPE, sources[source_index]);
            
            dbal_entry_value_field64_set(unit, entry_handle_id, DBAL_FIELD_START_TIME, INST_SINGLE, config.start_time);
            
            dbal_entry_value_field64_set(unit, entry_handle_id, DBAL_FIELD_INTERVAL_PERIOD, INST_SINGLE, config.trigger_period);
            
            nof_triggers = (config.nof_triggers ? config.nof_triggers-1 : 0);
            
            dbal_entry_value_field16_set(unit, entry_handle_id, DBAL_FIELD_NOF_INTERVALS, INST_SINGLE, nof_triggers);
            is_continuous = (config.nof_triggers ? 0 : 1);
            
            dbal_entry_value_field8_set(unit, entry_handle_id, DBAL_FIELD_IS_CONTINUOUS, INST_SINGLE, is_continuous);
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
        }
    }

    
    SHR_IF_ERR_EXIT(bcm_dnx_instru_synced_trigger_time_of_day_get(unit, 0,&timestamp));
    immediate_time = ((timestamp + ONE_MS_IN_NS) & TOD_COUNTER_MASK);

    
    for (source_index=0; source_index<nof_sources; source_index++)
    {
        if (enable[source_index])
        {
            SHR_IF_ERR_EXIT(instru.trigger_info.start_time.get(unit,sources[source_index], &start_time));
            SHR_IF_ERR_EXIT(instru.trigger_info.flags.get(unit,sources[source_index], &config_flags));

            
            if ((config_flags & BCM_INSTRU_SYNCED_TRIGGER_CONFIG_START_TIME_ABSOLUTE) == 0)
            { 
                start_time_calc = start_time + timestamp;
                start_time_wrapped = (start_time_calc & TOD_COUNTER_MASK);
                if (start_time_wrapped < immediate_time) { 
                    start_time_wrapped = immediate_time;
                }
                if (start_time_wrapped < timestamp) { 
                    wait_till_wrap_around = 1;
                }
                
                SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_INST_SYNCED_COUNTERS_CTRL, entry_handle_id));
                dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_TYPE, sources[source_index]);
                dbal_entry_value_field64_set(unit, entry_handle_id, DBAL_FIELD_START_TIME, INST_SINGLE, start_time_wrapped);
                SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));
            }
            else 
            {
                if (start_time < timestamp)
                {
                    SHR_ERR_EXIT(_SHR_E_PARAM, "absolute time cannot be older then current time.\n");
                }
            }
        }
    }
    if (wait_till_wrap_around)
    {
        
        while (1)
        {
            SHR_IF_ERR_EXIT(bcm_dnx_instru_synced_trigger_time_of_day_get(unit, 0,&timestamp));
            if (timestamp <= TOD_COUNTER_MASK/4)
            {
                break;
            }
            
            sal_usleep(1);
        };
    }

    
    SHR_IF_ERR_EXIT(dnx_instru_synced_trigger_enable(unit, nof_sources, sources, enable));

    
    for (source_index=0; source_index<nof_sources; source_index++)
    {
        if ((sources[source_index] == bcmInstruSyncedTriggerTypeIcgm) || (sources[source_index] == bcmInstruSyncedTriggerTypeNif))
        {
            
            source_type = (sources[source_index] == bcmInstruSyncedTriggerTypeIcgm) ? bcmInstruSyncedCountersTypeIcgm : bcmInstruSyncedCountersTypeNif;
            SHR_IF_ERR_EXIT(dnx_instru_synced_counters_sw_state_set(unit, source_type, enable[source_index]));
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


shr_error_e
bcm_dnx_instru_synced_triggers_enable_get(
        int unit,
        uint32 flags,
        uint32 nof_trigger_types,
        bcm_instru_synced_trigger_source_type_t *sources,
        uint8 *enable)
{
    uint32 entry_handle_id;
    uint8 source_index;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    if (nof_trigger_types >= bcmInstruSyncedTriggerTypeCount)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "number of trigger types %d exceed the number of available trigger types %d.\n",nof_trigger_types, bcmInstruSyncedTriggerTypeCount);
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INST_SYNCED_TRIGGER_CTRL, &entry_handle_id)); 

    
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

    for (source_index=0; source_index<nof_trigger_types; source_index++)
    {
        switch (sources[source_index]) {
            case bcmInstruSyncedTriggerTypeIcgm:
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_CGM_ENABLE, INST_SINGLE,
                                                                   &enable[source_index]));
                break;
            case bcmInstruSyncedTriggerTypeNif:
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_CDU_ENABLE, INST_SINGLE,
                                                                   &enable[source_index]));
                break;
            case bcmInstruSyncedTriggerTypeCrps:
                SHR_IF_ERR_EXIT(dbal_entry_handle_value_field8_get(unit, entry_handle_id, DBAL_FIELD_CRPS_ENABLE, INST_SINGLE,
                                                                   &enable[source_index]));
                break;
            default:
                SHR_ERR_EXIT(_SHR_E_PARAM, "Instrumentation source does not  exist %d.\n",sources[source_index]);
                break;
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_instru_synced_trigger_config_verify(
    int unit,
    uint32 flags,
    bcm_instru_synced_trigger_source_type_t source_type,
    uint8 is_set,
    bcm_instru_synced_trigger_config_t *config)
{
    int trigger_period_nof_bits_hw;
    int trigger_period_nof_bits_maximum_usable = dnx_data_instru.synced_counters.max_interval_period_size_get(unit);
    int max_trigger_period_nof_bits;

    SHR_FUNC_INIT_VARS(unit);

    
    if (flags & ~(BCM_INSTRU_SYNCED_TRIGGER_CONFIG_START_TIME_ABSOLUTE))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported flags for synchronized triggers configuration: 0x%x\n", flags);
    }

    
    if ((source_type != bcmInstruSyncedTriggerTypeIcgm) && (source_type != bcmInstruSyncedTriggerTypeNif))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported source type %d for synchronized triggers configuration!\n",
                     source_type);
    }

    if (is_set)
    {
        uint32 trigger_source_enable;
        
        SHR_IF_ERR_EXIT(instru.trigger_info.enable.get(unit,source_type,&trigger_source_enable));
        if (trigger_source_enable)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Trigger source need to be disabled before configuration.\n");
        }
        
        if (config->trigger_period == 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Period cannot be zero.\n");
        }
        SHR_IF_ERR_EXIT(dbal_tables_field_size_get
                        (unit, DBAL_TABLE_INST_SYNCED_COUNTERS_CTRL, DBAL_FIELD_INTERVAL_PERIOD, FALSE, 0, 0,
                         &trigger_period_nof_bits_hw));
        max_trigger_period_nof_bits = (trigger_period_nof_bits_hw < trigger_period_nof_bits_maximum_usable) ?
            (trigger_period_nof_bits_hw) : (trigger_period_nof_bits_maximum_usable);
        if ((config->trigger_period >> max_trigger_period_nof_bits) != 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Period (%u,%u)is out of range, cannot be more than %u bits.\n",
                         COMPILER_64_HI(config->trigger_period), COMPILER_64_LO(config->trigger_period),
                         max_trigger_period_nof_bits);
        }
    }

exit:
    SHR_FUNC_EXIT;
}


shr_error_e
bcm_dnx_instru_synced_trigger_config_set(
    int unit, 
    uint32 flags, 
    bcm_instru_synced_trigger_source_type_t source_type,
    bcm_instru_synced_trigger_config_t *config)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_IF_ERR_EXIT(dnx_instru_synced_trigger_config_verify(unit, flags, source_type, TRUE, config));

    SHR_IF_ERR_EXIT(instru.trigger_info.flags.set(unit,source_type,flags));
    SHR_IF_ERR_EXIT(instru.trigger_info.start_time.set(unit,source_type,config->start_time));
    SHR_IF_ERR_EXIT(instru.trigger_info.trigger_period.set(unit,source_type,config->trigger_period));
    SHR_IF_ERR_EXIT(instru.trigger_info.nof_triggers.set(unit,source_type,config->nof_triggers));

exit:
    SHR_FUNC_EXIT;
}


shr_error_e
bcm_dnx_instru_synced_trigger_config_get(
    int unit, 
    uint32 flags, 
    bcm_instru_synced_trigger_source_type_t source_type,
    bcm_instru_synced_trigger_config_t *config)
{
    uint32 entry_handle_id;
    uint8 is_continuous;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_IF_ERR_EXIT(dnx_instru_synced_trigger_config_verify(unit, flags, source_type, FALSE, config));

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_INST_SYNCED_COUNTERS_CTRL, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_TYPE, source_type);
    dbal_value_field64_request(unit, entry_handle_id, DBAL_FIELD_START_TIME, INST_SINGLE, &config->start_time);
    dbal_value_field64_request(unit, entry_handle_id, DBAL_FIELD_INTERVAL_PERIOD, INST_SINGLE, &config->trigger_period);
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_NOF_INTERVALS, INST_SINGLE, &config->nof_triggers);
    config->nof_triggers++;
    dbal_value_field8_request(unit, entry_handle_id, DBAL_FIELD_IS_CONTINUOUS, INST_SINGLE, &is_continuous);
    if (is_continuous)
    {
        config->trigger_period = 0;
    }
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


shr_error_e
bcm_dnx_instru_eventor_event_id_config_set(
         int unit,
         uint32 flags,
         bcm_eventor_event_id_t event_id,
         bcm_instru_eventor_event_id_config_t *config)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);
    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_EVENT_ID_TO_TX_CONTEXT_ID_MAP, &entry_handle_id)); 
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_ID,event_id);                    
    dbal_entry_value_field8_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, INST_SINGLE, config->context); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


shr_error_e
bcm_dnx_instru_eventor_event_id_config_get(
        int unit,
        uint32 flags,
        bcm_eventor_event_id_t event_id,
        bcm_instru_eventor_event_id_config_t *config)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_EVENT_ID_TO_TX_CONTEXT_ID_MAP, &entry_handle_id)); 
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_ID,event_id);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field16_get(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, INST_SINGLE,
                                                        &config->context));
exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}

shr_error_e
dnx_instru_eventor_generate_periodic_verify(
    int unit,
    uint32 flags,
    bcm_instru_eventor_periodic_source_t *source,
    bcm_instru_eventor_periodic_config_t *config)
{
    SHR_FUNC_INIT_VARS(unit);

    
    SHR_VAL_VERIFY(flags, 0, _SHR_E_PARAM, "Unsupported flags for synchronized triggers configuration!\n");

    
    if ((source->source != bcmInstruSyncedTriggerTypeIcgm) && (source->source != bcmInstruSyncedTriggerTypeNif))
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported source type %d for Eventor generate periodic configuration!\n",
                source->source);
    }
    if (source->source_index > 1)
    {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Unsupported source index %d for Eventor generate periodic configuration!\n",
                source->source_index);
    }

exit:
    SHR_FUNC_EXIT;
}


int
bcm_dnx_instru_eventor_generate_periodic_set(
    int unit,
    uint32 flags,
    bcm_instru_eventor_periodic_source_t * source,
    bcm_instru_eventor_periodic_config_t * config)
{
    uint32 entry_handle_id;
    uint32 source_index;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_IF_ERR_EXIT(dnx_instru_eventor_generate_periodic_verify(unit,flags, source, config));

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_EVENT_SOURCE_MAPPING, &entry_handle_id)); 

    source_index = ((source->source * 2) + source->source_index);
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_INDEX, source_index); 
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_ID, INST_SINGLE, config->event_id); 
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENT_SRC, INST_SINGLE, 0); 
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE, INST_SINGLE, config->enable); 
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


int
bcm_dnx_instru_eventor_generate_periodic_get(
    int unit,
    uint32 flags,
    bcm_instru_eventor_periodic_source_t * source,
    bcm_instru_eventor_periodic_config_t * config)
{
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_IF_ERR_EXIT(dnx_instru_eventor_generate_periodic_verify(unit,flags, source, config));

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_EVENT_SOURCE_MAPPING, &entry_handle_id)); 
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_SOURCE_INDEX,source->source_index);
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));

    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field16_get(unit, entry_handle_id, DBAL_FIELD_EVENT_ID, INST_SINGLE, &config->event_id));
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get(unit, entry_handle_id, DBAL_FIELD_ENABLE, INST_SINGLE, (uint32 *)&config->enable));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_context_set_verify(
    int unit,
    uint32 flags,
    bcm_eventor_context_id_t context,
    bcm_eventor_context_type_t context_type,
    bcm_instru_eventor_context_conf_t *conf)
{
    uint32 buffer1_end, buffer2_end, buf_i1_start, buf_i1_end, buf_i2_start, buf_i2_end, buf_i1_bank, buf_i2_bank;
    uint8 bank_1_is_used_in_tx, bank_2_is_used_in_tx, bank_1_is_used_in_rx, bank_2_is_used_in_rx;
    uint32 sw_state_flags, buffer_size_i;
    unsigned context_i;
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(conf, _SHR_E_PARAM, "conf");
    buffer1_end = conf->buffer1_start + conf->buffer_size;
    buffer2_end = conf->buffer2_start + conf->buffer_size;

    
    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    } else if (flags) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "unsupported flags were specified.\n");
    } else if (context >= DNX_EVENTOR_NOF_CONTEXTS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "context ID %u is out of range, should be under %u.\n", context, DNX_EVENTOR_NOF_CONTEXTS(unit));
    } else if (conf->buffer_size > DNX_EVENTOR_RX_MAX_BUFFER_SIZE_WORDS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "RX buffer size in 4 byte words %u is bigger than the allowed %u.\n",
        conf->buffer_size, DNX_EVENTOR_RX_MAX_BUFFER_SIZE_WORDS(unit));
    } else if (conf->bank1 >= DNX_EVENTOR_NOF_SRAM_BANKS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "SRAM bank %u is out of range, should be under %u.\n", conf->bank1, DNX_EVENTOR_NOF_SRAM_BANKS(unit));
    } else if (conf->bank2 >= DNX_EVENTOR_NOF_SRAM_BANKS(unit)) {
        SHR_ERR_EXIT(_SHR_E_PARAM, "SRAM bank %u is out of range, should be under %u.\n", conf->bank2, DNX_EVENTOR_NOF_SRAM_BANKS(unit));
    } else if (buffer1_end > DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit)) {
        SHR_ERR_EXIT(_SHR_E_PARAM, "1st buffer offset + size in words is out of range, should be <= %u.\n", DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit));
    } else if (buffer2_end > DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit)) {
        SHR_ERR_EXIT(_SHR_E_PARAM, "2nd buffer offset + size in words is out of range, should be <= %u.\n", DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit));
    } else if ((conf->flags & ~(BCM_INSTRU_EVENTOR_CONTEXT_CONF_NO_AGGREGATION | BCM_INSTRU_EVENTOR_CONTEXT_CONF_MAX_AGGREGATION_2 | BCM_INSTRU_EVENTOR_CONTEXT_CONF_WORD_LITTLE_ENDIAN | BCM_INSTRU_EVENTOR_CONTEXT_CONF_DONT_GENERATE_EVENTOR_HEADER)) != 0) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "unsupported flag/s in context configuration flags %u\n", conf->flags);
    }

    
    SHR_IF_ERR_EXIT(instru.eventor_info.flags.get(unit, &sw_state_flags));

    
    if (sw_state_flags & DNX_EVENTOR_STATE_FLAGS_ENABLED) {
        SHR_ERR_EXIT(_SHR_E_BUSY, "Cannot change configuration after the Eventor is started.\n");
    }

    switch (context_type) {
        case bcmEventorContextTypeRx: 
        case bcmEventorContextTypeRxDma:
            
            for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
            {
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
                if ((buffer_size_i > 0) && (context != context_i))
                {
                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.get(unit, context_i, &buf_i1_start));
                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.get(unit, context_i, &buf_i2_start));

                    buf_i1_bank = buf_i1_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);
                    buf_i2_bank = buf_i2_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);

                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_sram_banks_bitmap.bit_get(unit, buf_i1_bank, &bank_1_is_used_in_tx));
                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_sram_banks_bitmap.bit_get(unit, buf_i2_bank, &bank_2_is_used_in_tx));
                    if (bank_1_is_used_in_tx || bank_2_is_used_in_tx)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "May not use same SRAM bank for RX and TX contexts: bank1: %u used by tx: %u bank2: %u used by tx: %u.\n",
                                buf_i1_bank, bank_1_is_used_in_tx, buf_i1_bank, bank_2_is_used_in_tx);
                    }
                    buf_i1_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);
                    buf_i2_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);

                    buf_i1_end = buf_i1_start + buffer_size_i;
                    buf_i2_end = buf_i2_start + buffer_size_i;

                    if (conf->bank1 == buf_i1_bank && dnx_instru_eventor_do_buffers_collide(
                        conf->buffer1_start, buffer1_end, buf_i1_start, buf_i1_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 1st buffer bank %u word offset %u collides with specified 1st buffer.\n",
                          context_i, buf_i1_bank, buf_i1_start);
                    } else if (conf->bank2 == buf_i1_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer2_start, buffer2_end, buf_i1_start, buf_i1_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 1st buffer bank %u word offset %u collides with specified 2nd buffer.\n",
                          context_i, buf_i1_bank, buf_i1_start);
                    } else if (conf->bank1 == buf_i2_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer1_start, buffer1_end, buf_i2_start, buf_i2_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 2nd buffer bank %u word offset %u collides with specified 1st buffer.\n",
                          context_i, buf_i2_bank, buf_i2_start);
                    } else if (conf->bank2 == buf_i2_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer2_start, buffer2_end, buf_i2_start, buf_i2_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 2nd buffer bank %u word offset %u collides with specified 2nd buffer.\n",
                          context_i, buf_i2_bank, buf_i2_start);
                    }
                }
            }
            break;
        case bcmEventorContextTypeTx: 
            
            for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
            {
                SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
                if ((buffer_size_i > 0) && (context != context_i))
                {
                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer0_offset.get(unit, context_i, &buf_i1_start));
                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer1_offset.get(unit, context_i, &buf_i2_start));

                    buf_i1_bank = buf_i1_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);
                    buf_i2_bank = buf_i2_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);

                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_get(unit, buf_i1_bank, &bank_1_is_used_in_rx));
                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_get(unit, buf_i2_bank, &bank_2_is_used_in_rx));
                    if (bank_1_is_used_in_rx || bank_2_is_used_in_rx)
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "May not use same SRAM bank for RX and TX contexts: bank1: %u used by rx: %u bank2: %u used by rx: %u.\n",
                                buf_i1_bank, bank_1_is_used_in_rx, buf_i1_bank, bank_2_is_used_in_rx);
                        SHR_ERR_EXIT(_SHR_E_PARAM, "SRAM bank is not TX: bank1 %u is_rx_bank %u bank2 %u is_rx_bank %u.\n",
                                buf_i1_bank, bank_1_is_used_in_rx, buf_i1_bank, bank_2_is_used_in_rx);
                    }

                    buf_i1_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);
                    buf_i2_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);

                    buf_i1_end = buf_i1_start + buffer_size_i;
                    buf_i2_end = buf_i2_start + buffer_size_i;

                    if (conf->bank1 == buf_i1_bank && dnx_instru_eventor_do_buffers_collide(
                        conf->buffer1_start, buffer1_end, buf_i1_start, buf_i1_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 1st buffer bank %u word offset %u collides with specified 1st buffer.\n",
                          context_i, buf_i1_bank, buf_i1_start);
                    } else if (conf->bank2 == buf_i1_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer2_start, buffer2_end, buf_i1_start, buf_i1_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 1st buffer bank %u word offset %u collides with specified 2nd buffer.\n",
                          context_i, buf_i1_bank, buf_i1_start);
                    } else if (conf->bank1 == buf_i2_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer1_start, buffer1_end, buf_i2_start, buf_i2_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 2nd buffer bank %u word offset %u collides with specified 1st buffer.\n",
                          context_i, buf_i2_bank, buf_i2_start);
                    } else if (conf->bank2 == buf_i2_bank && dnx_instru_eventor_do_buffers_collide(
                               conf->buffer2_start, buffer2_end, buf_i2_start, buf_i2_end))
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "context %u 2nd buffer bank %u word offset %u collides with specified 2nd buffer.\n",
                          context_i, buf_i2_bank, buf_i2_start);
                    }
                }
            }
            break;

        default:
            SHR_EXIT_WITH_LOG(_SHR_E_PARAM, "unsupported context type flag %d%s%s.\n", context_type, EMPTY, EMPTY);
    }

exit:
    SHR_FUNC_EXIT;
}


static int dnx_instru_eventor_context_set_internal(
    int unit,
    uint32 flags,
    bcm_eventor_context_id_t context,
    bcm_eventor_context_type_t context_type,
    bcm_instru_eventor_context_conf_t *conf,
    int mark_context_as_rx)
{
    uint32 eventor_buffer_address[DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER];
    uint32 eventor_header = 0;

    SHR_FUNC_INIT_VARS(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_context_set_verify(unit, flags, context, context_type, conf));

    
    switch (context_type) {
        case bcmEventorContextTypeRx: 
        case bcmEventorContextTypeRxDma:
            
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.set(unit, context, conf->bank1 |
                                                                     (conf->buffer1_start << DNX_EVENTOR_SRAM_BANK_BITS(unit))));
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.set(unit, context, conf->bank2 |
                                                                     (conf->buffer2_start << DNX_EVENTOR_SRAM_BANK_BITS(unit))));
            
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_set(unit, conf->bank1));
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_set(unit, conf->bank2));
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.set(unit, context, conf->buffer_size)); 
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.program0_offset.set(unit, context, conf->program1_start));
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.program1_offset.set(unit, context, conf->program2_start));
            if (mark_context_as_rx)
            {
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_set(unit, context)); 
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.context_type.set(unit, context, context_type));
            }
            
            if (!mark_context_as_rx || (context_type == bcmEventorContextTypeRxDma))
            {
                
                SHR_IF_ERR_EXIT(dnx_instru_eventor_write_dma_descriptors(unit, context, conf));
            }
            break;

        case bcmEventorContextTypeTx:
            
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.set(unit, context, conf->buffer_size));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer0_offset.set(unit, context, conf->bank1 |
                                                                     (conf->buffer1_start << DNX_EVENTOR_SRAM_BANK_BITS(unit))));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer1_offset.set(unit, context, conf->bank2 |

                    (conf->buffer2_start << DNX_EVENTOR_SRAM_BANK_BITS(unit))));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_sram_banks_bitmap.bit_set(unit, conf->bank1));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_sram_banks_bitmap.bit_set(unit, conf->bank2));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program0_offset.set(unit, context, conf->program1_start));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program1_offset.set(unit, context, conf->program2_start));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.nof_operations.set(unit, context, conf->nof_operations));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.builders.set(unit, context, conf->builders));

            

            eventor_buffer_address[0] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * conf->bank1 + conf->buffer1_start * 4;
            eventor_buffer_address[1] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * conf->bank2 + conf->buffer2_start * 4;
            

            SHR_IF_ERR_EXIT(dnx_instru_eventor_write_dma_descriptors(unit, context, conf));

            
            dnx_instru_eventor_generate_tx_event_eventor_header(unit, conf->flags, context, conf, &eventor_header);
            soc_pci_write(unit, EVENTOR_SRAM_DIRECT_MEM_ACCESS(unit,eventor_buffer_address[0] & 0xfffff), eventor_header);
            if ((conf->flags & BCM_INSTRU_EVENTOR_CONTEXT_CONF_MAX_AGGREGATION_2) != 0)
            {
                dnx_instru_eventor_generate_tx_event_eventor_header(unit, BCM_INSTRU_EVENTOR_CONTEXT_CONF_NO_AGGREGATION, context, conf, &eventor_header);
            }
            
            if (!(conf->flags &  BCM_INSTRU_EVENTOR_CONTEXT_CONF_DONT_GENERATE_EVENTOR_HEADER))
            {
                soc_pci_write(unit, EVENTOR_SRAM_DIRECT_MEM_ACCESS(unit,eventor_buffer_address[1] & 0xfffff), eventor_header);
            }

            
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_bitmap.bit_set(unit, context));

            break;
        default:
            SHR_EXIT_WITH_LOG(_SHR_E_PARAM, "unsupported context type flag %d%s%s.\n", context_type, EMPTY, EMPTY);
    }

exit:
    SHR_FUNC_EXIT;
}


int bcm_dnx_instru_eventor_context_set(
    int unit,
    uint32 flags,
    bcm_eventor_context_id_t context,
    bcm_eventor_context_type_t context_type,
    bcm_instru_eventor_context_conf_t *conf)
{
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_IF_ERR_EXIT(dnx_instru_eventor_context_set_internal(unit, flags, context, context_type,conf, TRUE));

exit:
    SHR_FUNC_EXIT;
}

static shr_error_e
dnx_instru_eventor_context_get_verify(
    int unit,
    uint32 flags,
    bcm_eventor_context_id_t context,
    bcm_eventor_context_type_t context_type,
    bcm_instru_eventor_context_conf_t *out_conf)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(out_conf, _SHR_E_PARAM, "out_conf");

    
    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    } else if (flags) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "unsupported flags were specified.\n");
    } else if (context >= DNX_EVENTOR_NOF_CONTEXTS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "context ID %u is out of range, should be under %u.\n", context, DNX_EVENTOR_NOF_CONTEXTS(unit));
    }

exit:
    SHR_FUNC_EXIT;
}



int bcm_dnx_instru_eventor_context_get(
    int unit,
    uint32 flags,
    bcm_eventor_context_id_t context,
    bcm_eventor_context_type_t context_type,
    bcm_instru_eventor_context_conf_t *out_conf)
{
    uint8 is_rx_context, is_tx_context;
    uint32 sram_words_offset;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_context_get_verify(unit, flags, context, context_type, out_conf));

    SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context, &is_rx_context));
    SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_bitmap.bit_get(unit, context, &is_tx_context));

    
    if (is_rx_context && (context_type == bcmEventorContextTypeRx || context_type == bcmEventorContextTypeAny))
    {
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.get(unit, context, &sram_words_offset));
            out_conf->bank1 = sram_words_offset & DNX_EVENTOR_SRAM_BANK_MASK(unit);
            out_conf->buffer1_start = sram_words_offset >> DNX_EVENTOR_SRAM_BANK_BITS(unit);

            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.get(unit, context, &sram_words_offset));
            out_conf->bank2 = sram_words_offset & DNX_EVENTOR_SRAM_BANK_MASK(unit);
            out_conf->buffer2_start = sram_words_offset >> DNX_EVENTOR_SRAM_BANK_BITS(unit);

            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context, &out_conf->buffer_size));
    }
    else if (is_tx_context && (context_type == bcmEventorContextTypeTx || context_type == bcmEventorContextTypeAny))
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer0_offset.get(unit, context, &sram_words_offset));
        out_conf->bank1 = sram_words_offset & DNX_EVENTOR_SRAM_BANK_MASK(unit);
        out_conf->buffer1_start = sram_words_offset >> DNX_EVENTOR_SRAM_BANK_BITS(unit);

        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer1_offset.get(unit, context, &sram_words_offset));
        out_conf->bank2 = sram_words_offset & DNX_EVENTOR_SRAM_BANK_MASK(unit);
        out_conf->buffer2_start = sram_words_offset >> DNX_EVENTOR_SRAM_BANK_BITS(unit);

        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.get(unit, context, &out_conf->buffer_size));
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program0_offset.get(unit, context, &out_conf->program1_start));
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program1_offset.get(unit, context, &out_conf->program2_start));
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.nof_operations.get(unit, context, &out_conf->nof_operations));
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.nof_const_values.get(unit, context, &out_conf->nof_const_values));
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Context %u of the requested type was not found.\n", context);
    }

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_builder_set_verify(
    int unit,
    uint32 flags,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *conf)
{
    uint32 sw_state_flags, buffer_size, tx_max_header_size;
    uint8 is_rx_context, is_tx_context;
    uint8 context_found = FALSE;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(conf, _SHR_E_PARAM, "conf");

    
    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    } else if (builder >= DNX_EVENTOR_NOF_BUILDERS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "builder ID %u is out of range, should be under %u.\n", builder, DNX_EVENTOR_NOF_BUILDERS(unit));
    } else if (conf->header_length & 0x3) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error! header_length = %u, must be multiple of 4 bytes!\n", conf->header_length);
    }

    
    if ((flags & ~(BCM_INSTRU_EVENTOR_BUILDER_RECONFIG_WITH_NO_TRAFFIC)) != 0) {
            SHR_ERR_EXIT(_SHR_E_PARAM, "unsupported flags were specified.\n");
    }

    
    tx_max_header_size = DDC(tx_builder_max_header_size);
    if (conf->header_length > tx_max_header_size) {
        SHR_ERR_EXIT(_SHR_E_PARAM, "Error! header_length = %d, can't be larger then %d!\n", conf->header_length, tx_max_header_size);
    } else if (conf->header_length != 0) { 
        
        SHR_NULL_CHECK(conf->header_data, _SHR_E_PARAM, "conf->header_data");
    }

    SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, builder, &is_rx_context));
    SHR_IF_ERR_EXIT(instru.eventor_info.flags.get(unit, &sw_state_flags));

    
    if ((sw_state_flags & DNX_EVENTOR_STATE_FLAGS_ENABLED) && !(is_rx_context && (flags & BCM_INSTRU_EVENTOR_BUILDER_RECONFIG_WITH_NO_TRAFFIC) != 0))
    {
        SHR_ERR_EXIT(_SHR_E_BUSY, "May not change configuration after the Eventor is started. sw_state_flags = 0x%08X, is_rx_context = %d, flags = 0x%08X\n",
            sw_state_flags, is_rx_context, flags);
    }

    if (is_rx_context)
    {
        context_found = TRUE;
        
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, builder, &buffer_size));
        if (conf->thresh_size <= 0 || (conf->thresh_size % buffer_size))  
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "thresh_size given %u is not a positive multiple of the buffer size %u.\n",
              conf->thresh_size, buffer_size);
        } else if (conf->thresh_size > DNX_EVENTOR_BUILDER_MAX_BUFFER_SIZE_WORDS(unit)) {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Builder size threshold in words %u is greater that the max %u.\n",
              conf->thresh_size, DNX_EVENTOR_BUILDER_MAX_BUFFER_SIZE_WORDS(unit));
        }
    }
    else
    {
        uint32 context_i ,builders = 0;

        for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++) {
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_bitmap.bit_get(unit, context_i, &is_tx_context));
            if (is_tx_context)
            {
                SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.builders.get(unit, context_i, &builders));
                if (builders & (0x1 << builder))
                {
                    context_found = TRUE;
                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.get(unit, context_i, &buffer_size));
                    if (conf->thresh_size <= 0) 
                    {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "thresh_size given %u is not a positive number %u.\n",
                          conf->thresh_size, buffer_size);
                    } else if (conf->thresh_size > DNX_EVENTOR_BUILDER_MAX_BUFFER_SIZE_WORDS(unit)) {
                        SHR_ERR_EXIT(_SHR_E_PARAM, "Builder threshold size in words %u is greater that the max %u.\n",
                          conf->thresh_size, DNX_EVENTOR_BUILDER_MAX_BUFFER_SIZE_WORDS(unit));
                    }
                }
            }
        }
    }

    if (!context_found)
    {
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Builder ID %u was not configured to any context.\n", builder);
    }

exit:
    SHR_FUNC_EXIT;
}


static shr_error_e  SDK_170437_Buffer_flip(
    int unit,
    uint8 *buffer,
    uint32 length)
{
    int i;
    uint8 *startP, *endP;
    uint8 tmp;

    SHR_FUNC_INIT_VARS(unit);

    startP = buffer;
    endP = &buffer[length -1];

    for (i=0; i< (length/2); i++)
    {
        tmp = *startP;
        *startP = *endP;
        *endP = tmp;

        startP++;
        endP--;
    }

    SHR_EXIT();

exit:
    SHR_FUNC_EXIT;

}


static shr_error_e dnx_instru_eventor_builder_tx_header_set(
    int unit,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *conf)
{
    uint8 header_data_high[(DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)];
    uint8 header_data_low[(DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)];
    uint32 nof_samples;
    uint32 buffer_size = 0;
    uint8 is_rx_context;
    uint32 entry_handle_id;


    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_BUILDER_TRANSMIT_HEADER_STACK, &entry_handle_id));
    
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_BUILDER_ID, builder);


    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_SIZE, INST_SINGLE,
                                 conf->header_length);

    
    if (conf->header_length == 0)
    {
        sal_memset(header_data_high, 0, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2));
        sal_memset(header_data_low, 0, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2));
    }
    else
    {
        uint8 *destPtr, *srcPtr;
        uint32 length;

        if (conf->header_length < (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2))
        {
            
            destPtr = header_data_high;
            srcPtr = conf->header_data;
            length = conf->header_length;
            sal_memcpy(destPtr, srcPtr,length);

            
            destPtr += length;
            length = (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2) - length;
            sal_memset(destPtr, 0, length);

            
            sal_memset(header_data_low, 0, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2));

            
            SHR_IF_ERR_EXIT(SDK_170437_Buffer_flip(unit, header_data_high, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)));

        }
        else
        {
            
            destPtr = header_data_high;
            srcPtr = conf->header_data;
            sal_memcpy(destPtr, srcPtr, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2));


            
            SHR_IF_ERR_EXIT(SDK_170437_Buffer_flip(unit, header_data_high, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)));


            
            destPtr = header_data_low;
            srcPtr += (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2);
            length = conf->header_length - (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2);
            sal_memcpy(destPtr, srcPtr, length);

            
            destPtr += length;
            length = (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2) - length;
            sal_memset(destPtr, 0, length);


            
            SHR_IF_ERR_EXIT(SDK_170437_Buffer_flip(unit, header_data_low, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)));
        }

    }

    dbal_entry_value_field_arr8_set(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_DATA_HIGH, INST_SINGLE, header_data_high);
    dbal_entry_value_field_arr8_set(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_DATA_LOW, INST_SINGLE, header_data_low);

    
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));


    
    SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, builder, &is_rx_context));
    if (is_rx_context)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, builder, &buffer_size));
    }
    else
    {
       uint32 context_i, builders = 0;
        uint8 is_tx_context;

        for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++) {
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_bitmap.bit_get(unit, context_i, &is_tx_context));
            if (is_tx_context)
            {
                SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.builders.get(unit, context_i, &builders));
                if (builders & (0x1 << builder))
                {
                    SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.get(unit, context_i, &buffer_size));
                    break;
                }
            }
        }
        if (context_i == DNX_EVENTOR_NOF_CONTEXTS(unit))
        {
            SHR_ERR_EXIT(_SHR_E_PARAM, "context with builder %d not found.\n",builder);
        }
    }

    if (buffer_size != 0)
    {
        nof_samples = conf->thresh_size / buffer_size;
    }
    else
    {
        SHR_ERR_EXIT(_SHR_E_INTERNAL, "valid buffer size not found for builder %d.\n",builder);
    }

    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_CONTEXT_EVPCK_HEADER_STACK, entry_handle_id));
    
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, builder);

    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVPCK_HEADER_STACK_SIZE, INST_SINGLE, DNX_EVENTOR_EVPCK_DEFAULT_HEADER_STACK_SIZE);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVPCK_HEADER_STACK_EN, INST_SINGLE, 0);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_EVPCK_HEADER_STACK_NOF_SAMPLES, INST_SINGLE, nof_samples);

    
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


int bcm_dnx_instru_eventor_builder_set(
    int unit,
    uint32 flags,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *conf)
{
    uint32 u32;
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);
    DBAL_FUNC_INIT_VARS(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_builder_set_verify(unit, flags, builder, conf));

    
    switch (conf->thresh_time) {
      case BCM_INSTRU_EVENTOR_TIMEOUT_NONE:
        u32 = 0;
        break;
      case BCM_INSTRU_EVENTOR_TIMEOUT_MINIMAL:
        u32 = 1;
        break;
      default:
        if ( conf->thresh_time > DNX_EVENTOR_MAX_BUILDER_TIMEOUT_MS(unit)) {
            SHR_ERR_EXIT(_SHR_E_PARAM, "Value bigger than max timeout threshold %ums.\n",
              DNX_EVENTOR_MAX_BUILDER_TIMEOUT_MS(unit));
        }
        u32 = conf->thresh_time * dnx_data_device.general.core_clock_khz_get(unit);
    }

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_TX_ENG_CFG, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_TX_ENGINE_ID, builder); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTEXT_QUEUE_TIMEOUT, INST_SINGLE, u32); 
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CONTEXT_QUEUE_MAX_SIZE, INST_SINGLE,
                                 conf->thresh_size * DNX_EVENTOR_BUILDER_QUEUE_MAX_SIZE_TH_GRANULARITY);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    SHR_IF_ERR_EXIT(dnx_instru_eventor_builder_tx_header_set(unit, builder, conf));

    
    SHR_IF_ERR_EXIT(instru.eventor_info.builder_configured_bitmap.bit_set(unit, builder));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_builder_get_verify(
    int unit,
    uint32 flags,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *out_conf)
{
    uint8 is_builder_configured;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(out_conf, _SHR_E_PARAM, "out_conf");

    
    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    } else if (flags) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "unsupported flags were specified.\n");
    } else if (builder >= DNX_EVENTOR_NOF_BUILDERS(unit)) { 
        SHR_ERR_EXIT(_SHR_E_PARAM, "builder ID %u is out of range, should be under %u.\n", builder, DNX_EVENTOR_NOF_BUILDERS(unit));
    }

    SHR_IF_ERR_EXIT(instru.eventor_info.builder_configured_bitmap.bit_get(unit, builder, &is_builder_configured));
    if (is_builder_configured == FALSE) { 
        SHR_ERR_EXIT(_SHR_E_NOT_FOUND, "Builder ID %u was not configured as RX.\n", builder);
    }

exit:
    SHR_FUNC_EXIT;
}



static shr_error_e dnx_instru_eventor_builder_tx_header_get(
    int unit,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *conf)
{
    uint8 header_data_high[(DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)];
    uint8 header_data_low[(DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)];
    uint32 entry_handle_id;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_BUILDER_TRANSMIT_HEADER_STACK, &entry_handle_id));
    
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_BUILDER_ID, builder);

    
    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_GET_ALL_FIELDS));


    
    SHR_IF_ERR_EXIT(dbal_entry_handle_value_field32_get(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_SIZE, INST_SINGLE,
                                                        &conf->header_length));

    if (conf->header_length > 0)
    {
        uint8 *destPtr;
        int length;

        
        SHR_NULL_CHECK(conf->header_data, _SHR_E_PARAM, "conf->header_data");


        
        SHR_IF_ERR_EXIT(dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_DATA_HIGH, INST_SINGLE, header_data_high));


        
        SHR_IF_ERR_EXIT(SDK_170437_Buffer_flip(unit, header_data_high, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)));

        
        length = (conf->header_length > (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2))? (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2):conf->header_length;
        destPtr = &conf->header_data[0];
        sal_memcpy(destPtr, header_data_high, length);

        length = conf->header_length - (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2);

        if (length > 0)
        {
            
            SHR_IF_ERR_EXIT(dbal_entry_handle_value_field_arr8_get(unit, entry_handle_id, DBAL_FIELD_TRANSMIT_HEADER_STACK_DATA_LOW, INST_SINGLE, header_data_low));

            
            SHR_IF_ERR_EXIT(SDK_170437_Buffer_flip(unit, header_data_low, (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2)));

            
            destPtr += (DNX_EVENTOR_TRANSMIT_HEADER_MAX_SIZE/2);
            sal_memcpy(destPtr, header_data_low, length);
        }
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}



int bcm_dnx_instru_eventor_builder_get(
    int unit,
    uint32 flags,
    bcm_eventor_builder_id_t builder,
    bcm_instru_eventor_builder_conf_t *out_conf)
{
    uint32 entry_handle_id, thresh_size, thresh_timeout;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);
    DBAL_FUNC_INIT_VARS(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_builder_get_verify(unit, flags, builder, out_conf));

    out_conf->flags = 0;

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_TX_ENG_CFG, &entry_handle_id));
    
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_TX_ENGINE_ID, builder);

    
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CONTEXT_QUEUE_TIMEOUT, INST_SINGLE, &thresh_timeout);

    
    dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CONTEXT_QUEUE_MAX_SIZE, INST_SINGLE, &thresh_size);

    SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT)); 

    out_conf->thresh_size = thresh_size / DNX_EVENTOR_BUILDER_QUEUE_MAX_SIZE_TH_GRANULARITY;
    out_conf->thresh_time = thresh_timeout ? (thresh_timeout == 1 ? BCM_INSTRU_EVENTOR_TIMEOUT_MINIMAL :
      thresh_timeout / dnx_data_device.general.core_clock_khz_get(unit)) :
      BCM_INSTRU_EVENTOR_TIMEOUT_NONE;

    
    SHR_IF_ERR_EXIT(dnx_instru_eventor_builder_tx_header_get(unit, builder, out_conf));

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_active_set_verify(
    int unit,
    uint32 flags,
    int active)
{
    int error = 0;
    uint32 thresh_size, context_i, buffer_size_i, buf0_offset, buf1_offset, entry_handle_id;
    uint8 is_builder_configured;
    uint8 is_rx_context;
    uint32 rx_context_type;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) { 
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    } else if (active == 0) { 
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "Stopping the Eventor is not supported.\n");
    }

    
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++) {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context_i, &is_rx_context));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.context_type.get(unit, context_i, &rx_context_type));
        if (is_rx_context && buffer_size_i && (rx_context_type == bcmEventorContextTypeRx)) {
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.get(unit, context_i, &buf0_offset));
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.get(unit, context_i, &buf1_offset));

            SHR_IF_ERR_EXIT(instru.eventor_info.builder_configured_bitmap.bit_get(unit, context_i, &is_builder_configured));

            if (is_builder_configured == 0) {
                LOG_ERROR(BSL_LOG_MODULE, ("Context %u configured as RX, and the same builder was not configured.\n", context_i));
                error = 1;
            } else {
                
                
                SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_TX_ENG_CFG, &entry_handle_id));
                dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_TX_ENGINE_ID, context_i); 
                dbal_value_field32_request(unit, entry_handle_id, DBAL_FIELD_CONTEXT_QUEUE_MAX_SIZE, INST_SINGLE, &thresh_size); 
                SHR_IF_ERR_EXIT(dbal_entry_get(unit, entry_handle_id, DBAL_COMMIT)); 

                if (thresh_size == 0 || (thresh_size % buffer_size_i)) {
                    LOG_ERROR(BSL_LOG_MODULE, ("RX context %u has a builder thresh_size %u which is not a positive multiple of the rx buffer size %u.\n",
                      context_i, thresh_size, buffer_size_i));
                    error = 1;
                }
            }
        }
    }
    

    if (error) {
        SHR_ERR_EXIT(_SHR_E_FAIL, "Wrong Eventor configuration detailed above.\n");
    }

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_active_context_set(
        int unit,
        uint32 context,
        uint32 buffer_size,
        uint32 buff0_start_address,
        uint32 buff1_start_address,
        uint32 program0_offset,
        uint32 program1_offset,
        uint8 is_tx_context)
{
    uint32 entry_handle_id;
    uint32 bank1,bank2;
    uint32 cmic_buff0_start, cmic_buff1_start;

    SHR_FUNC_INIT_VARS(unit);
    DBAL_FUNC_INIT_VARS(unit);

    
    bank1 = buff0_start_address & DNX_EVENTOR_SRAM_BANK_MASK(unit);
    bank2 = buff1_start_address & DNX_EVENTOR_SRAM_BANK_MASK(unit);

    buff0_start_address = bank1 * DNX_EVENTOR_SRAM_BANKS_FULL_SIZE_WORDS(unit) +
      (buff0_start_address >> DNX_EVENTOR_SRAM_BANK_BITS(unit));

    
    buff1_start_address = bank2 * DNX_EVENTOR_SRAM_BANKS_FULL_SIZE_WORDS(unit) +
      (buff1_start_address >> DNX_EVENTOR_SRAM_BANK_BITS(unit));

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_SPACE_REGIONS, &entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_TX_CONTEXT, is_tx_context); 
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, context); 
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BUFFER_START_ADDR, 0, buff0_start_address);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BUFFER_END_ADDR, 0, buff0_start_address + buffer_size-1);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BUFFER_START_ADDR, 1, buff1_start_address);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_BUFFER_END_ADDR, 1, buff1_start_address + buffer_size-1);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    cmic_buff0_start = DNX_EVENTOR_AXI_SRAM_WORD_OFFSET(unit) +
            (DNX_EVENTOR_SRAM_BANKS_FULL_SIZE_WORDS(unit) * bank1) + program0_offset;
    cmic_buff1_start = DNX_EVENTOR_AXI_SRAM_WORD_OFFSET(unit) +
            (DNX_EVENTOR_SRAM_BANKS_FULL_SIZE_WORDS(unit) * bank2) + program1_offset;

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_CONTEXT_PROPERITES, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_TX_CONTEXT, is_tx_context); 
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, context); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_BUFFER_START_ADDR, 0, cmic_buff0_start);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_BUFFER_START_ADDR, 1, cmic_buff1_start);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_configure_unused_rx_contexts(int unit, uint32 nof_rx_context)
{

    uint32 nof_rx_banks = 0;
    uint32 bank_index;
    uint32 context_i, buffer_size_i;
    uint8 is_rx_bank, is_tx_bank, is_rx_context;
    uint8 context_index, unused_context_i;
    int unused_rx_context_bank_1 = -1;
    int unused_rx_context_bank_2 = -1;
    uint32 buffer_1_start=0, program_1_start=0;
    uint32 buffer_2_start=0, program_2_start = 0;
    uint32 nof_unused_rx_contexts = DNX_EVENTOR_NOF_CONTEXTS(unit) - nof_rx_context;
    uint32 buf_i1_start, buf_i1_end, buf_i2_start, buf_i2_end, buf_i1_bank, buf_i2_bank;
    bcm_instru_eventor_operation_t operation = {0};
    bcm_instru_eventor_context_conf_t conf;
    uint32 free_words_needed_in_bank = nof_unused_rx_contexts * (UNUSED_RX_CONTEXT_BUFFER_SIZE + UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE);
    uint32 needed_free_area_start_for_one_alloc = DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit) - free_words_needed_in_bank;
    uint32 needed_free_area_start_for_two_allocs = DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit) - DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER*free_words_needed_in_bank;
    uint32 *bank_first_free_address  = NULL;

    SHR_FUNC_INIT_VARS(unit);

    SHR_ALLOC_SET_ZERO( bank_first_free_address, sizeof(uint32) * DNX_EVENTOR_NOF_SRAM_BANKS(unit),
                       "sram bank highest used address", "%s%s%s", EMPTY, EMPTY, EMPTY);

    if (nof_unused_rx_contexts == 0) {
        SHR_EXIT(); 
    }

    
    
    for (bank_index = 0; bank_index < DNX_EVENTOR_NOF_SRAM_BANKS(unit); bank_index++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_get(unit, bank_index, &is_rx_bank));
        if (is_rx_bank)
        {
            nof_rx_banks++;
        }
        else
        {
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_sram_banks_bitmap.bit_get(unit, bank_index, &is_tx_bank));
            if (!is_tx_bank)
            {
                
                if (unused_rx_context_bank_1 == -1) {
                    unused_rx_context_bank_1 = bank_index;
                    unused_rx_context_bank_2 = bank_index;
                    
                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_set(unit, bank_index));
                }
                else
                {
                    
                    unused_rx_context_bank_2 = bank_index;
                    
                    SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_set(unit, bank_index));
                    break;
                }
            }
        }
    }

    
    if (unused_rx_context_bank_1 == -1)
    {
        
        if (nof_rx_banks == 0)
        {
            SHR_ERR_EXIT(_SHR_E_PARAM,"at least one free SRAM bank or an RX bank\n");
        }

        
        for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
        {
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context_i, &is_rx_context));
            if (is_rx_context)
            {
                
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.get(unit, context_i, &buf_i1_start));
                SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.get(unit, context_i, &buf_i2_start));

                buf_i1_bank = buf_i1_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);
                buf_i2_bank = buf_i2_start & DNX_EVENTOR_SRAM_BANK_MASK(unit);

                buf_i1_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);
                buf_i2_start >>= DNX_EVENTOR_SRAM_BANK_BITS(unit);

                buf_i1_end = buf_i1_start + buffer_size_i;
                buf_i2_end = buf_i2_start + buffer_size_i;

                if ( bank_first_free_address[buf_i1_bank] < buf_i1_end)
                {
                    bank_first_free_address[buf_i1_bank] = buf_i1_end;
                }
                if (bank_first_free_address[buf_i2_bank] < buf_i2_end)
                {
                    bank_first_free_address[buf_i2_bank] = buf_i2_end;
                }
            }
        }

        
        for (bank_index = 0; bank_index < DNX_EVENTOR_NOF_SRAM_BANKS(unit); bank_index++)
        {
            SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_get(unit, bank_index, &is_rx_bank));
            if (is_rx_bank && bank_first_free_address[bank_index] <= needed_free_area_start_for_one_alloc)
            {
                if (unused_rx_context_bank_1 == -1) {
                    unused_rx_context_bank_1 = bank_index;
                    
                    if (bank_first_free_address[bank_index] <= needed_free_area_start_for_two_allocs)
                    {
                        unused_rx_context_bank_2 = bank_index;
                    }
                }
                else
                {
                    unused_rx_context_bank_2 = bank_index;
                    
                    break;
                }
            }

        }
    }

    if (unused_rx_context_bank_2 == -1) {
        SHR_ERR_EXIT(_SHR_E_PARAM,"There is no free bank and no RX banks with enough free space at their end.\n");
    }

    
    buffer_1_start = DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit) - (nof_unused_rx_contexts * UNUSED_RX_CONTEXT_BUFFER_SIZE);
    program_1_start = buffer_1_start - (nof_unused_rx_contexts * UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE);

    
    buffer_2_start = program_1_start;
    if (unused_rx_context_bank_1 != unused_rx_context_bank_2)
    {
        buffer_2_start = DNX_EVENTOR_SRAM_BANKS_NET_SIZE_WORDS(unit);
    }
    buffer_2_start -= (nof_unused_rx_contexts * UNUSED_RX_CONTEXT_BUFFER_SIZE);
    program_2_start = buffer_2_start - (nof_unused_rx_contexts * UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE);

    SHR_IF_ERR_EXIT(bcm_instru_get_register_access_info(unit, BCM_INSTRU_ACCESS_FLAG_IS_WRITE, ECI_VERSION_REGISTERr, 0, 0, &operation.access_info));

    
    for (unused_context_i = 0, context_index = 0; context_index < DNX_EVENTOR_NOF_CONTEXTS(unit); context_index++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context_index, &is_rx_context));
        if (!is_rx_context) { 
            if (unused_context_i >= nof_unused_rx_contexts) {
                SHR_ERR_EXIT(_SHR_E_INTERNAL,"found too many unused contexts\n");
            }
            
            conf.flags = 0;
            conf.bank1  = unused_rx_context_bank_1;
            conf.bank2  = unused_rx_context_bank_2;

            
            conf.buffer1_start = buffer_1_start + unused_context_i * UNUSED_RX_CONTEXT_BUFFER_SIZE;
            conf.buffer2_start = buffer_2_start + unused_context_i * UNUSED_RX_CONTEXT_BUFFER_SIZE;
            conf.buffer_size = UNUSED_RX_CONTEXT_BUFFER_SIZE;
            conf.program1_start = program_1_start + unused_context_i * UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE;
            conf.program2_start = program_2_start + unused_context_i * UNUSED_RX_CONTEXT_DESCRIPTOR_CHAIN_SIZE;
            conf.nof_operations = 1;
            conf.operations = &operation;
            
            SHR_IF_ERR_EXIT(dnx_instru_eventor_context_set_internal(unit, 0, context_index, bcmEventorContextTypeRx, &conf, 0));

            unused_context_i++;
        }
    }
exit:
    SHR_FREE(bank_first_free_address);
    SHR_FUNC_EXIT;
}



int bcm_dnx_instru_eventor_active_set(
    int unit,
    uint32 flags,
    int active)
{
    int sbus_dma_channel_values[MAX_NOF_EVENTOR_SBUS_DMA_CHANNELS];  
    int nof_sbus_dma_channel_values, cmc, channel;
    uint8 cmic_engine_index;
    uint32 context_i, bank_i, buff0_start_address, buff1_start_address, sw_state_flags, buffer_size_i, program0_offset, program1_offset, builders;
    uint32 index;
    uint32 tx_context_type_bitmap = 0;
    uint32 addr;
    uint32 nof_rx_context = 0;

    uint8 is_rx_bank;
    uint32 entry_handle_id;
    uint8 is_rx_context;
    uint8 is_tx_context;
    uint32 context_type;

    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);
    DBAL_FUNC_INIT_VARS(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_active_set_verify(unit, flags, active));

    SHR_IF_ERR_EXIT(instru.eventor_info.flags.get(unit, &sw_state_flags));

    
    if ((sw_state_flags & DNX_EVENTOR_STATE_FLAGS_ENABLED) != 0) {
        SHR_EXIT();
    }

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_ALLOC(unit, DBAL_TABLE_EVENTOR_RX_CONTEXT_TO_TX_MAP, &entry_handle_id));

    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++) {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context_i, &is_rx_context));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.context_type.get(unit, context_i, &context_type));
        if (is_rx_context) { 
            if (context_type == bcmEventorContextTypeRx)
            {
                
                dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE_MAP, context_i, TRUE);
                
                nof_rx_context++;
            }
            else if (context_type == bcmEventorContextTypeRxDma)
            {
                
                dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE_MAP, context_i, FALSE);
                nof_rx_context++;
            }
        }
        else
        {
            
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_ENABLE_MAP, context_i, FALSE);
        }
    }

    SHR_IF_ERR_EXIT(dnx_instru_eventor_configure_unused_rx_contexts(unit, nof_rx_context));

    
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT));

    
    if (nof_rx_context > 0 && dnx_data_instru.eventor.is_rx_en_get(unit))
    {
        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_RX_INTERFACE_EN, entry_handle_id));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RXI_EN, INST_SINGLE, 1);
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    }

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_BANK_TYPE, entry_handle_id));
    for (bank_i = 0; bank_i < DNX_EVENTOR_NOF_SRAM_BANKS(unit); bank_i++) {
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_SRAM_BANK_ID, bank_i); 
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_sram_banks_bitmap.bit_get(unit, bank_i, &is_rx_bank));
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_TX_BANK, INST_SINGLE, !is_rx_bank); 
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    }


    

    
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_CONTEXT_IS_FIFO_DMA, entry_handle_id));
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_FIFO_DMA, context_i, FALSE); 
    }
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_CONTEXT_MAIN_BUFFER_TH, entry_handle_id));
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TX_BUFFER_TH, context_i,
                                     DNX_EVENTOR_SBUS_DMA_BUFFERS_DEFAULT_THRESH);
    }
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_RX_CONTEXT_MAIN_BUFFER_TH, entry_handle_id));
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
        
        if (buffer_size_i)
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RX_BUFFER_TH, context_i, buffer_size_i);
        }
        else
        {
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_RX_BUFFER_TH, context_i, 1);
        }
    }
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_bitmap.bit_get(unit, context_i, &is_rx_context));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer0_offset.get(unit, context_i, &buff0_start_address));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.buffer1_offset.get(unit, context_i, &buff1_start_address));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.program0_offset.get(unit, context_i, &program0_offset));
        SHR_IF_ERR_EXIT(instru.eventor_info.rx_contexts_info.program1_offset.get(unit, context_i, &program1_offset));

        if (buffer_size_i) {
            
            SHR_IF_ERR_EXIT(dnx_instru_eventor_active_context_set(
                    unit, context_i, buffer_size_i, buff0_start_address, buff1_start_address, program0_offset, program1_offset, FALSE));
        }
    }

    
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_bitmap.bit_get(unit, context_i, &is_tx_context));
        if (is_tx_context)
        {
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer_size.get(unit, context_i, &buffer_size_i));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer0_offset.get(unit, context_i, &buff0_start_address));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.buffer1_offset.get(unit, context_i, &buff1_start_address));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program0_offset.get(unit, context_i, &program0_offset));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.program1_offset.get(unit, context_i, &program1_offset));
            SHR_IF_ERR_EXIT(instru.eventor_info.tx_contexts_info.builders.get(unit, context_i, &builders));

            if (buffer_size_i) {
                SHR_IF_ERR_EXIT(dnx_instru_eventor_active_context_set(
                        unit, context_i, buffer_size_i, buff0_start_address,buff1_start_address, program0_offset, program1_offset, TRUE));

                
                SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_CONTEXT_MAIN_BUFFER_TH, entry_handle_id));
                
                dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_TX_BUFFER_TH, context_i, 7);
                SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
            }

            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_CONTEXT_TO_BUILDER_MAPPING, entry_handle_id));
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, context_i); 
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_MAPPING_DATA, INST_SINGLE, builders);
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

            
            tx_context_type_bitmap |= builders;

            tx_context_type_bitmap |= (0x1 << context_i);
        }
    }

    
    nof_sbus_dma_channel_values = soc_property_get_csv(unit, spn_EVENTOR_SBUS_DMA_CHANNELS, MAX_NOF_EVENTOR_SBUS_DMA_CHANNELS, sbus_dma_channel_values);
    if (nof_sbus_dma_channel_values > 0) {
        if ((nof_sbus_dma_channel_values & 1)) {
            SHR_ERR_EXIT(_SHR_E_PARAM,"soc property %s must have an even number of comma separated values\n", spn_EVENTOR_SBUS_DMA_CHANNELS);
        } else if (nof_sbus_dma_channel_values > MAX_NOF_EVENTOR_SBUS_DMA_CHANNELS) {
            SHR_ERR_EXIT(_SHR_E_PARAM,"soc property %s can not have more than %u channels\n", spn_EVENTOR_SBUS_DMA_CHANNELS, MAX_NOF_EVENTOR_SBUS_DMA_CHANNELS);
        }
        cmic_engine_index = 0;
        for (index = 0; index < nof_sbus_dma_channel_values; index++) {
            cmc = sbus_dma_channel_values[index++];
            channel = sbus_dma_channel_values[index];
            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_CMIC_ENGINE_PROPERTIES, entry_handle_id));
            dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_ENGINE_ID, cmic_engine_index); 
            addr = AXI_CMIC_OFFSET + CMIC_CMCx_SBUSDMA_CHy_DESCADDR_LO(cmc,channel);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_DSA_ADDR, INST_SINGLE, addr);

            addr = AXI_CMIC_OFFSET + CMIC_CMCx_SBUSDMA_CHy_CONTROL(cmc,channel);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_CTRL_ADDR, INST_SINGLE, addr);
            addr = AXI_CMIC_OFFSET + CMIC_CMCx_SBUSDMA_CHy_STATUS(cmc,channel);
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_STATUS_ADDR, INST_SINGLE, addr);
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

            addr = CMIC_CMCx_SBUSDMA_CHy_DESCADDR_HI(cmc,channel);
            soc_pci_write(unit, EVENTOR_SRAM_DIRECT_MEM_ACCESS(unit,addr), 0);
            
            SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_SHARED_CMIC_ENG_POOL, entry_handle_id));
            dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_ENGINE_NUM, 0, cmic_engine_index);
            SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

            cmic_engine_index++;
        }
    }
#ifndef ADAPTER_SERVER_MODE
    else
    {
        SHR_ERR_EXIT(_SHR_E_FAIL, "Eventor SBUS DMA # of channels cannot be 0\n");
    }
#endif

    
    for (context_i = 0; context_i < DNX_EVENTOR_NOF_CONTEXTS(unit); context_i++)
    {
        uint32 queue_type;
        queue_type = tx_context_type_bitmap & (0x1 <<context_i);

        SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_TX_CONTEXT_QUEUE_TYPE, entry_handle_id));
        dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_EVENTOR_CONTEXT_ID, context_i); 
        dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_STANDARD_QUEUE_TYPE, INST_SINGLE, (queue_type ? 1 : 0));
        SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    }

    
    
#ifndef ADAPTER_SERVER_MODE
    SHR_IF_ERR_EXIT(soc_reg_field32_modify(unit, CMIC_CMC1_SHARED_SBUS_DMA_READ_AXI_MAP_CTRLr, REG_PORT_ANY,
                    SLICE0_DATA_READ_AXIIDf, 0x6));
    SHR_IF_ERR_EXIT(soc_reg_field32_modify(unit, CMIC_CMC1_SHARED_SBUS_DMA_READ_AXI_MAP_CTRLr, REG_PORT_ANY,
                    SLICE1_DATA_READ_AXIIDf, 0x6));
    SHR_IF_ERR_EXIT(soc_reg_field32_modify(unit, CMIC_CMC1_SHARED_SBUS_DMA_READ_AXI_MAP_CTRLr, REG_PORT_ANY,
                    SLICE2_DATA_READ_AXIIDf, 0x6));
    SHR_IF_ERR_EXIT(soc_reg_field32_modify(unit, CMIC_CMC1_SHARED_SBUS_DMA_READ_AXI_MAP_CTRLr, REG_PORT_ANY,
                    SLICE3_DATA_READ_AXIIDf, 0x6));
#endif
    
    SHR_IF_ERR_EXIT(DBAL_HANDLE_CLEAR(unit, DBAL_TABLE_EVENTOR_CMIC_FLEX_CMD, entry_handle_id));
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_TX_CMIC_FLEX, 1); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_DESC_DMA_CONTROL, INST_SINGLE, 0x5);
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_FIFO_DMA_CFG, INST_SINGLE, 0x3e8093);
    
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_FIFO_DMA_CFG_WR_STROBE, INST_SINGLE, 0xffffffff);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 
    
    dbal_entry_key_field32_set(unit, entry_handle_id, DBAL_FIELD_IS_TX_CMIC_FLEX, 0); 
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_DESC_DMA_CONTROL, INST_SINGLE, 0x5);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_FIFO_DMA_CFG, INST_SINGLE, 0x3e8093);
    dbal_entry_value_field32_set(unit, entry_handle_id, DBAL_FIELD_CMIC_FIFO_DMA_CFG_WR_STROBE, INST_SINGLE, 0xffffffff);
    SHR_IF_ERR_EXIT(dbal_entry_commit(unit, entry_handle_id, DBAL_COMMIT)); 

    
    SHR_IF_ERR_EXIT(instru.eventor_info.flags.get(unit, &flags));
    SHR_IF_ERR_EXIT(instru.eventor_info.flags.set(unit, flags | DNX_EVENTOR_STATE_FLAGS_ENABLED));

#if defined (ADAPTER_SERVER_MODE) && defined (BCM_ACCESS_SUPPORT)

    
    {
        uint32 value = 0x1;

        SHR_IF_ERR_EXIT(access_regmem
                        (unit, FLAG_ACCESS_IS_WRITE, rEVNT_RESERVED_SPARE_0, ACCESS_ALL_BLOCK_INSTANCES, 0, 0, &value));
    }
#endif

exit:
    DBAL_FUNC_FREE_VARS;
    SHR_FUNC_EXIT;
}


static shr_error_e
dnx_instru_eventor_active_get_verify(
    int unit,
    uint32 flags,
    int *out_active)
{
    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(out_active, _SHR_E_PARAM, "out_active");

    
    if (dnx_data_instru.eventor.feature_get(unit, dnx_data_instru_eventor_is_supported) == FALSE) {
        SHR_ERR_EXIT(_SHR_E_UNAVAIL, "There is no Eventor support for this device.\n");
    }

exit:
    SHR_FUNC_EXIT;
}


int
bcm_dnx_instru_eventor_active_get(
    int unit,
    uint32 flags,
    int *out_active)
{
    uint32 sw_state_flags;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    
    SHR_INVOKE_VERIFY_DNXC(dnx_instru_eventor_active_get_verify(unit, flags, out_active));

    
    SHR_IF_ERR_EXIT(instru.eventor_info.flags.get(unit, &sw_state_flags));
    *out_active = (sw_state_flags & DNX_EVENTOR_STATE_FLAGS_ENABLED) ? 1 : 0;

exit:
    SHR_FUNC_EXIT;
}


int
bcm_dnx_instru_get_register_access_info(
  int unit,
  uint32 flags,
  soc_reg_t reg,
  uint32 instance,
  uint32 array_index,
  bcm_instru_access_info_t* access_info)
{
    soc_reg_access_info_t reg_access_info;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_NULL_CHECK(access_info, _SHR_E_PARAM, "access_info");
    if (!SOC_REG_IS_VALID(unit, reg)) {
        return SOC_E_PARAM;
    }

    
    if (soc_reg_xaddr_get(unit, reg, instance, array_index,
           (flags & BCM_INSTRU_ACCESS_FLAG_IS_WRITE) != 0 ?
             SOC_REG_ADDR_OPTION_WRITE : SOC_REG_ADDR_OPTION_NONE,
           &reg_access_info) != SOC_E_NONE ||
        reg_access_info.num_blks != 1) {
        SHR_EXIT_WITH_LOG(SOC_E_PARAM, "could not get the address for register %s%s%s.\n",  SOC_REG_NAME(unit, reg), EMPTY, EMPTY);
    }

    
    access_info->flags = flags; 
    access_info->address = reg_access_info.offset; 
    access_info->phys_block = reg_access_info.blk_list[0]; 
    access_info->nof_entries = 1; 
    access_info->entry_size = 
      SOC_REG_IS_ABOVE_64(unit, reg) ? SOC_REG_ABOVE_64_INFO(unit, reg).size :
        (SOC_REG_IS_64(unit, reg) ? 2 : 1);

exit:
    SHR_FUNC_EXIT;
}


int
bcm_dnx_instru_get_memory_access_info(
   int unit,
   uint32 flags,
   soc_mem_t mem,
   int instance_number,
   uint32 index,
   uint32 array_index,
   bcm_instru_access_info_t *access_info)
{
    int copyno;
    uint8 access_type;
    int sbus_blk, copyno_override;
    SHR_FUNC_INIT_VARS(unit);
    DNX_ERR_RECOVERY_NOT_NEEDED(unit);

    SHR_NULL_CHECK(access_info, _SHR_E_PARAM, "access_info");
    if (!soc_mem_is_valid(unit, mem)) {
        return SOC_E_MEMORY;
    }
    SOC_MEM_ALIAS_TO_ORIG(unit, mem); 

    copyno = SOC_MEM_BLOCK_MIN(unit,mem) + instance_number;
    
    if ((flags & BCM_INSTRU_ACCESS_FLAG_IS_WRITE) != 0 ) {
        soc_mem_write_copyno_update(unit, mem, &copyno, &copyno_override);
        if (copyno_override) {
            copyno = copyno_override;
        }
    }
    
    if (copyno == SOC_CORE_ALL || copyno == COPYNO_ALL) {
        copyno = SOC_MEM_BLOCK_ANY(unit, mem);
    }

    
    access_info->flags = flags | BCM_INSTRU_ACCESS_FLAG_IS_MEM; 
    access_info->address = soc_mem_addr_get(unit, mem, array_index, copyno, index, &access_type); 

    
    soc_mem_dst_blk_update(unit, copyno, access_info->address, &sbus_blk);
    access_info->phys_block = sbus_blk;

    access_info->nof_entries = 1; 
    access_info->entry_size = soc_mem_entry_words(unit, mem); 

exit:
    SHR_FUNC_EXIT;
}


void
dnx_instru_eventor_generate_tx_event_eventor_header(
        int unit,
        uint32 flags,
        bcm_eventor_context_id_t context,
        bcm_instru_eventor_context_conf_t *context_conf,
        uint32 *eventor_header)
{
    bcm_instru_eventor_operation_t *operation_ptr;
    uint8 push = 0;

    uint8 operation_index;
    uint32 access_length = 0;

    for (operation_index=0; operation_index<context_conf->nof_operations; operation_index++)
    {
        operation_ptr = &context_conf->operations[operation_index];

        access_length += operation_ptr->access_info.entry_size * operation_ptr->access_info.nof_entries;
        if (dnx_data_instru.eventor.is_extra_words_copy_get(unit))
        {
            
            access_length += (0x1000 -(operation_ptr->buf_offset + operation_ptr->access_info.entry_size)) & 0x3;
        }
    }

    if (flags & BCM_INSTRU_EVENTOR_CONTEXT_CONF_NO_AGGREGATION)
    {
        push = 0x1;
    }

    
    *eventor_header = (context << 24) | (push << 23) | (1<<21) | (access_length * 4);
    context_conf->out_event_size = access_length;
}

int
dnx_instru_eventor_write_dma_descriptors(
        int unit,
        bcm_eventor_context_id_t context,
        const bcm_instru_eventor_context_conf_t *context_conf)
{
#ifndef ADAPTER_SERVER_MODE
    soc_sbusdma_desc_ctrl_t desc_ctrl = {0};
    soc_sbusdma_desc_cfg_t  *desc_cfg = NULL;
    uint8 desc_index;
    uint8 buffer_index;
    uint32 eventor_chain_address[DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER];
    uint32 eventor_buffer_address[DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER];
    uint32 buff_addr;
    void *desc_ptr;

    SHR_FUNC_INIT_VARS(unit);

    SHR_NULL_CHECK(context_conf, _SHR_E_PARAM, "context_conf");

    eventor_chain_address[0] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * context_conf->bank1 + context_conf->program1_start * 4;
    eventor_chain_address[1] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * context_conf->bank2 + context_conf->program2_start * 4;
    eventor_buffer_address[0] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * context_conf->bank1 + context_conf->buffer1_start * 4;
    eventor_buffer_address[1] = DNX_EVENTOR_AXI_SRAM_OFFSET(unit) + DNX_EVENTOR_SRAM_BANKS_FULL_SIZE(unit) * context_conf->bank2 + context_conf->buffer2_start * 4;

    desc_ctrl.flags = SOC_SBUSDMA_CFG_USE_FLAGS;
    if (context_conf->flags & BCM_INSTRU_EVENTOR_CONTEXT_CONF_WORD_LITTLE_ENDIAN)
    {
        desc_ctrl.flags |= SOC_SBUSDMA_CFG_DATA_BIGENDIAN;
    }
    desc_ctrl.name[0] = '\0';
    desc_ctrl.cfg_count = context_conf->nof_operations;             
    desc_ctrl.hw_desc = NULL;                                       
    
    desc_ctrl.buff = NULL;                                          
    desc_ctrl.cb = NULL;                                            
    desc_ctrl.data = NULL;                                          

    SHR_ALLOC_SET_ZERO(desc_cfg, sizeof(soc_sbusdma_desc_cfg_t) * context_conf->nof_operations,
                           "wanted_members_array_p", "%s%s%s", EMPTY, EMPTY, EMPTY);
    for (buffer_index=0; buffer_index<DNX_EVENTOR_NOF_BUFFERS_IN_DOUBLE_BUFFER; buffer_index++)
    {
        for (desc_index=0; desc_index<context_conf->nof_operations; desc_index++)
        {
            soc_sbusdma_desc_cfg_t * desc_cfg_ptr = &desc_cfg[desc_index];
            bcm_instru_eventor_operation_t *operation_ptr = &context_conf->operations[desc_index];

            desc_cfg_ptr->blk = operation_ptr->access_info.phys_block;              
            desc_cfg_ptr->addr = operation_ptr->access_info.address;                
            desc_cfg_ptr->width = operation_ptr->access_info.entry_size;            
            desc_cfg_ptr->count = operation_ptr->access_info.nof_entries;           
            desc_cfg_ptr->addr_shift = 0;
            buff_addr = (eventor_buffer_address[buffer_index] + operation_ptr->buf_offset * 4); 
            desc_cfg_ptr->buff = INT_TO_PTR(buff_addr);
            desc_cfg_ptr->flags = (operation_ptr->access_info.flags & BCM_INSTRU_ACCESS_FLAG_IS_WRITE) ? SOC_SBUSDMA_WRITE_CMD_MSG : 0;
            if ((operation_ptr->access_info.flags & BCM_INSTRU_ACCESS_FLAG_IS_MEM)) {
                desc_cfg_ptr->flags |= SOC_SBUSDMA_MEMORY_CMD_MSG;
            }
        }
        desc_ptr = (void *)(sal_vaddr_t)EVENTOR_SRAM_DIRECT_MEM_ACCESS(unit, (eventor_chain_address[buffer_index] & 0xfffff));
        SHR_IF_ERR_EXIT(soc_sbusdma_desc_create(unit, &desc_ctrl, desc_cfg, FALSE, desc_ptr));
    }
#else
    soc_sbusdma_desc_cfg_t  *desc_cfg = NULL;
    SHR_FUNC_INIT_VARS(unit);
    SHR_EXIT();
#endif

exit:
    SHR_FREE(desc_cfg);
    SHR_FUNC_EXIT;
}
