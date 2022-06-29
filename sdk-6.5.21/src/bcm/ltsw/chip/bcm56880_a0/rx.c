/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include <bcm/types.h>
#include <bcm/rx.h>
#include <bcm_int/control.h>

#include <bcm_int/ltsw/mbcm/rx.h>
#include <bcm_int/ltsw/rx_int.h>
#include <bcm_int/ltsw/chip/bcm56880_a0/variant_dispatch.h>

#include <bcm_int/ltsw/cosq.h>
#include <bcm_int/ltsw/dev.h>
#include <bcm_int/ltsw/ha.h>
#include <bcm_int/ltsw/lt_intf.h>
#include <bcm_int/ltsw/port.h>
#include <bcm_int/ltsw/property.h>
#include <bcm_int/ltsw/switch.h>
#include <shr/shr_debug.h>
#include <shr/shr_bitop.h>
#include <sal/sal_libc.h>
#include <sal/sal_mutex.h>
#include <bcmlt/bcmlt.h>
#include <bcmltd/chip/bcmltd_str.h>

/******************************************************************************
 * Local definitions
 */

#define BSL_LOG_MODULE BSL_LS_BCM_RX

/******************************************************************************
 * Private functions
 */


/*
 * rx table control structure
 */
typedef struct rx_ctrl_s {

    /* rx map database pointer. */
    const bcmint_rx_map_db_t *rx_db;

    /* Is key1 use as opaque ctrl id in current NPL version. */
    bool key1_opaque_ctrl_id;

    /* Is key2 use as int pri in current NPL version. */
    bool key2_int_pri;

} rx_ctrl_t;

static rx_ctrl_t rx_ctrl[BCM_MAX_NUM_UNITS] = {{ 0 }};

/* RX map database. */
#define RX_MAP_DB(unit) \
            (rx_ctrl[unit].rx_db)

/* key1 use as opaque ctrl id. */
#define IFP_OPAQUE_CTRL_ID(unit) \
            (rx_ctrl[unit].key1_opaque_ctrl_id)

/* key2 use as int pri. */
#define INT_PRI(unit) \
            (rx_ctrl[unit].key2_int_pri)

/* RX map string database. */
#define RX_MAP_STR_DB(unit, hdl) \
            (&(RX_MAP_DB(unit)->str_db[hdl]))

/* RX map string info. */
#define RX_MAP_STR_INFO(unit, hdl) \
            (RX_MAP_STR_DB(unit, hdl)->info)

/* RX map string number. */
#define RX_MAP_STR_NUM(unit, hdl) \
            (RX_MAP_STR_DB(unit, hdl)->num)

/* RX event database. */
#define RX_EVENT_DB(unit, hdl) \
            (&(RX_MAP_DB(unit)->event_db[hdl]))

/* RX drop event info. */
#define RX_DROP_EVENT_INFO(unit, hdl) \
            (RX_EVENT_DB(unit, hdl)->drop_info)

/* RX drop event number. */
#define RX_DROP_EVENT_NUM(unit, hdl) \
            (RX_EVENT_DB(unit, hdl)->drop_num)

/* RX trace event info. */
#define RX_TRACE_EVENT_INFO(unit, hdl) \
            (RX_EVENT_DB(unit, hdl)->trace_info)

/* RX trace event number. */
#define RX_TRACE_EVENT_NUM(unit, hdl) \
            (RX_EVENT_DB(unit, hdl)->trace_num)

/*
 * Only CMC0 is used for BCM RX hence we can have
 * CMICX_N_DMA_CHAN number of maximum rx channels
 */
#define CMICX_N_DMA_CHAN 8
#define MAX_CMC 2

#define COS_MAP_ENTRY_PRIORITY_MAX_VALUE 0xffff

/* Rx cosq CPU mapping. */
typedef struct rx_cosq_cpu_map_s {
    /* ifp opaque ctrl id */
    uint8_t key1;

    /* mask for ifp opaque ctrl id */
    uint8_t key1_mask;

    /* internal priority value */
    uint8_t key2;

    /* mask for internal priority value */
    uint8_t key2_mask;

    /* enable to switch the packets to CPU */
    bool sw_to_cpu;

    /* mask for enable to switch the packets to CPU */
    bool sw_to_cpu_mask;

    /* enable to mirror the packets to CPU */
    bool mir_to_cpu;

    /* mask for enable to mirror the packets to CPU */
    bool mir_to_cpu_mask;

    /* copy to CPU trace event reasons bitmap */
    uint64_t cpu_reasons;

    /* mask for copy to CPU trace event reasons bitmap */
    uint64_t cpu_reasons_mask;

    /* highest priority drop code */
    uint8_t drop_code;

    /* mask for highest priority drop code */
    uint8_t drop_code_mask;

    /* specifies the priority of the entry */
    uint16_t entry_priority;

    /* Enable to truncate CPU copy, disable to not truncate CPU copy */
    bool truncate;

    /* COS value. */
    uint16_t cos;
} rx_cosq_cpu_map_t;

/*
 * \brief Populate TM_COS_QUEUE_CPU_MAP entry.
 *
 * \param [in] unit Unit number
 * \param [in] eh LT entry handle.
 * \param [in] TM_COS_QUEUE_CPU_MAP structure.
 * \param [bool] key_only Only populate key.
 *
 * \return BCM_E_NONE on success, error code otherwise.
 */
static int
rx_cosq_mapping_entry_populate(int unit, bcmlt_entry_handle_t eh,
                               rx_cosq_cpu_map_t *mapping, bool key_only)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY0s, 0));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY0_MASKs, 0));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY1s, mapping->key1));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY1_MASKs, mapping->key1_mask));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY2s, mapping->key2));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, KEY2_MASKs, mapping->key2_mask));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, SWITCHs, mapping->sw_to_cpu));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, SWITCH_MASKs, mapping->sw_to_cpu_mask));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, MIRRORs, mapping->mir_to_cpu));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, MIRROR_MASKs, mapping->mir_to_cpu_mask));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, CPU_REASONs, mapping->cpu_reasons));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, CPU_REASON_MASKs, mapping->cpu_reasons_mask));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, HIGHEST_DROP_CODEs, mapping->drop_code));

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_add(eh, HIGHEST_DROP_CODE_MASKs, mapping->drop_code_mask));

    if (!key_only) {
        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_add(eh, ENTRY_PRIORITYs, mapping->entry_priority));

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_add(eh, TRUNCATE_CPU_COPYs, mapping->truncate));

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_add(eh, COSs, mapping->cos));
    }

exit:
    SHR_FUNC_EXIT();
}

/*
 * \brief Parse TM_COS_QUEUE_CPU_MAP entry.
 *
 * \param [in] unit Unit number
 * \param [in] eh LT entry handle.
 * \param [in] TM_COS_QUEUE_CPU_MAP structure.
 * \param [bool] key_only Only populate key.
 *
 * \return BCM_E_NONE on success, error code otherwise.
 */
static int
rx_cosq_mapping_entry_parse(int unit, bcmlt_entry_handle_t eh,
                            rx_cosq_cpu_map_t *mapping, bool no_key)
{
    uint64_t data = 0LL;

    SHR_FUNC_ENTER(unit);

    if (!no_key) {
        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, KEY1s, &data));
        mapping->key1 = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, KEY1_MASKs, &data));
        mapping->key1_mask = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, KEY2s, &data));
        mapping->key2 = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, KEY2_MASKs, &data));
        mapping->key2_mask = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, SWITCHs, &data));
        mapping->sw_to_cpu = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, SWITCH_MASKs, &data));
        mapping->sw_to_cpu_mask = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, MIRRORs, &data));
        mapping->mir_to_cpu = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, MIRROR_MASKs, &data));
        mapping->mir_to_cpu_mask = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, CPU_REASONs, &data));
        mapping->cpu_reasons = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, CPU_REASON_MASKs, &data));
        mapping->cpu_reasons_mask = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, HIGHEST_DROP_CODEs, &data));
        mapping->drop_code = data;

        SHR_IF_ERR_EXIT
            (bcmlt_entry_field_get(eh, HIGHEST_DROP_CODE_MASKs, &data));
        mapping->drop_code_mask = data;
    }

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_get(eh, ENTRY_PRIORITYs, &data));
    mapping->entry_priority = data;

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_get(eh, TRUNCATE_CPU_COPYs, &data));
    mapping->truncate = data;

    SHR_IF_ERR_EXIT
        (bcmlt_entry_field_get(eh, COSs, &data));
    mapping->cos = data;

exit:
    SHR_FUNC_EXIT();
}

/*
 * \brief handle a cos mapping.
 *
 * \param [in] unit Unit number
 * \param [in] mapping structure.
 *
 * \return BCM_E_NONE on success, error code otherwise.
 */
static int
rx_cosq_mapping_handle(int unit, bcmlt_opcode_t opcode, rx_cosq_cpu_map_t *mapping)
{
    bcmlt_entry_handle_t eh = BCMLT_INVALID_HDL;
    const char * tbl_name;
    bool key_only;
    int dunit;

    SHR_FUNC_ENTER(unit);

    dunit = bcmi_ltsw_dev_dunit(unit);

    tbl_name = TM_COS_Q_CPU_MAPs;

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmlt_entry_allocate(dunit, tbl_name, &eh));

    switch (opcode) {
        case BCMLT_OPCODE_INSERT:
        case BCMLT_OPCODE_UPDATE:
            key_only = false;
            break;
        case BCMLT_OPCODE_LOOKUP:
        case BCMLT_OPCODE_DELETE:
            key_only = true;
            break;
        default:
            SHR_IF_ERR_EXIT(SHR_E_UNAVAIL);
    }

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_entry_populate(unit, eh, mapping, key_only));

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmi_lt_entry_commit(unit, eh, opcode, BCMLT_PRIORITY_NORMAL));

    if (opcode == BCMLT_OPCODE_LOOKUP) {
        SHR_IF_ERR_VERBOSE_EXIT
            (rx_cosq_mapping_entry_parse(unit, eh, mapping, true));
    }

exit:
    if (eh != BCMLT_INVALID_HDL) {
        bcmlt_entry_free(eh);
    }
    SHR_FUNC_EXIT();
}

/*
 * \brief Populate rx cosq mapping key value.
 *
 * \param [in] unit            Unit Number.
 * \param [in] rx_cosq_mapping bcm_rx_cosq_mapping_t.
 * \param [out] mapping        rx_cosq_cpu_map_t.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
static int
rx_cosq_mapping_key_populate(int unit, bcm_rx_cosq_mapping_t *rx_cosq_mapping,
                             rx_cosq_cpu_map_t *mapping)
{
    const bcmint_rx_trace_event_convert_t *rx_trace_event = NULL;
    const bcmint_rx_drop_event_convert_t *rx_drop_event = NULL;
    int event_table_length;
    bcm_pkt_trace_event_t  reason_enum;
    bcm_rx_pkt_trace_reasons_t reasons_remain;
    uint32_t opaque_ctrl_id = 0;
    uint32_t opaque_ctrl_id_mask = 0;
    uint32_t final_int_prio = 0;
    uint32_t final_int_prio_mask = 0;
    uint8_t final_drop_code = 0;
    uint8_t final_drop_code_mask = 0;
    uint64_t cpu_reasons = 0;
    uint64_t cpu_reasons_mask = 0;
    int i, entries;
    bool drop_code_found = false;

    SHR_FUNC_ENTER(unit);

    /* Handle ifp opaque ctrl id when flex_key1_mask != 0 */
    if (rx_cosq_mapping->flex_key1_mask) {
        if (IFP_OPAQUE_CTRL_ID(unit)) {
            opaque_ctrl_id = rx_cosq_mapping->flex_key1;
            opaque_ctrl_id_mask = rx_cosq_mapping->flex_key1_mask;
            if (opaque_ctrl_id > 15) {
                SHR_ERR_EXIT(SHR_E_PARAM);
            }
            opaque_ctrl_id &= opaque_ctrl_id_mask;
            mapping->key1 = opaque_ctrl_id;
            mapping->key1_mask = opaque_ctrl_id_mask;
        } else {
            SHR_ERR_EXIT(SHR_E_UNAVAIL);
        }
    }

    /* Handle priority when flex_key2_mask != 0 */
    if (rx_cosq_mapping->flex_key2_mask) {
        if (INT_PRI(unit)) {
            final_int_prio = rx_cosq_mapping->flex_key2;
            final_int_prio_mask = rx_cosq_mapping->flex_key2_mask;
            if (final_int_prio > 15) {
                SHR_ERR_EXIT(SHR_E_PARAM);
            }
            final_int_prio &= final_int_prio_mask;
            mapping->key2 = final_int_prio;
            mapping->key2_mask = final_int_prio_mask;
        } else {
            SHR_ERR_EXIT(SHR_E_UNAVAIL);
        }
    }

    /* Program the packet type */
    if (rx_cosq_mapping->packet_type_mask & BCM_RX_COSQ_PACKET_TYPE_NON_UNICAST) {
        if (rx_cosq_mapping->packet_type & BCM_RX_COSQ_PACKET_TYPE_NON_UNICAST) {
            SHR_ERR_EXIT(SHR_E_UNAVAIL);
        }
    }

    if (rx_cosq_mapping->packet_type_mask & BCM_RX_COSQ_PACKET_TYPE_SWITCHED) {
        if (!(rx_cosq_mapping->packet_type & BCM_RX_COSQ_PACKET_TYPE_SWITCHED)) {
            SHR_ERR_EXIT(SHR_E_PARAM);
        }

        mapping->sw_to_cpu = true;
        mapping->sw_to_cpu_mask = true;
    }

    if (rx_cosq_mapping->packet_type_mask & BCM_RX_COSQ_PACKET_TYPE_MIRROR) {
        if (!(rx_cosq_mapping->packet_type & BCM_RX_COSQ_PACKET_TYPE_MIRROR)) {
            SHR_ERR_EXIT(SHR_E_PARAM);
        }

        mapping->mir_to_cpu = true;
        mapping->mir_to_cpu_mask = true;
    }

    /* Program the cpu reason and mask when reasons_mask is not NULL */
    reasons_remain = rx_cosq_mapping->trace_reasons_mask;
    mapping->cpu_reasons = 0;
    mapping->cpu_reasons_mask = 0;

    rx_trace_event = RX_TRACE_EVENT_INFO(unit, BCMINT_RX_EVENT_INFO_ID);
    if (rx_trace_event == NULL) {
        SHR_ERR_EXIT(SHR_E_INIT);
    }

    event_table_length = RX_TRACE_EVENT_NUM(unit, BCMINT_RX_EVENT_INFO_ID);

    for (i = 0; i < event_table_length; i++) {
        reason_enum = rx_trace_event[i].trace_event;

        if (reason_enum == -1) {
            continue;
        }

        LOG_VERBOSE(BSL_LOG_MODULE,
                    (BSL_META_U(unit,
                                "RX trace reason: event=%d value=%d mask=%d code=%d\n"),
                     rx_trace_event[i].trace_event,
                     BCM_RX_PKT_TRACE_REASON_GET(rx_cosq_mapping->trace_reasons,
                                       reason_enum) ? 1 : 0,
                     BCM_RX_PKT_TRACE_REASON_GET(rx_cosq_mapping->trace_reasons_mask,
                                       reason_enum) ? 1 : 0,
                     rx_trace_event[i].trace_code));

        /* Find reason being set */
        if (!BCM_RX_PKT_TRACE_REASON_GET(rx_cosq_mapping->trace_reasons_mask, reason_enum)) {
            continue;
        }
        BCM_RX_PKT_TRACE_REASON_CLEAR(reasons_remain, reason_enum);

        cpu_reasons_mask |= 1 << rx_trace_event[i].trace_code;
        if (BCM_RX_PKT_TRACE_REASON_GET(rx_cosq_mapping->trace_reasons, reason_enum)) {
            cpu_reasons |= 1 << rx_trace_event[i].trace_code;
        }
    }

    /* check whether there are reasons unsupported */
    if (!BCM_RX_PKT_TRACE_REASON_IS_NULL(reasons_remain)) {
        SHR_ERR_EXIT(SHR_E_PARAM);
    }

    if (!BCM_RX_PKT_TRACE_REASON_IS_NULL(rx_cosq_mapping->trace_reasons_mask)) {
        mapping->cpu_reasons = cpu_reasons;
        mapping->cpu_reasons_mask = cpu_reasons_mask;
    }

    rx_drop_event = RX_DROP_EVENT_INFO(unit, BCMINT_RX_EVENT_INFO_ID);
    if (rx_drop_event == NULL) {
        SHR_ERR_EXIT(SHR_E_INIT);
    }

    event_table_length = RX_DROP_EVENT_NUM(unit, BCMINT_RX_EVENT_INFO_ID);

    if (rx_cosq_mapping->drop_event_mask) {
        final_drop_code = rx_cosq_mapping->drop_event;
        final_drop_code_mask = rx_cosq_mapping->drop_event_mask;

        entries = event_table_length;

        final_drop_code &= final_drop_code_mask;

        for (i = 0; i < entries; i++) {
            LOG_VERBOSE(BSL_LOG_MODULE,
                      (BSL_META_U(unit,
                                  "RX drop reason: event=%d value=%d code=%d\n"),
                       final_drop_code,
                       rx_drop_event[i].drop_event,
                       rx_drop_event[i].drop_code));

            if (final_drop_code == rx_drop_event[i].drop_event) {
                mapping->drop_code = rx_drop_event[i].drop_code;
                mapping->drop_code_mask = 0xff;
                drop_code_found = true;
                break;
            }
        }

        if (!drop_code_found) {
            SHR_ERR_EXIT(SHR_E_PARAM);
        }
    }

exit:
    SHR_FUNC_EXIT();
}

/*
 * \brief NPL usage mode for CPU COS queue
 *        assignement info init.
 *
 * \param [in]  unit          Unit number.
 *
 * \retval SHR_E_NONE         No errors.
 * \retval !SHR_E_NONE        Failure.
 */
static int
tm_cos_q_cpu_map_info_init(int unit)
{
    bcmint_tm_cos_q_cpu_map_info_t info = {0};
    int i, size;
    const bcmint_rx_str_map_t *info_id_map = NULL;

    SHR_FUNC_ENTER(unit);

    IFP_OPAQUE_CTRL_ID(unit) = FALSE;
    INT_PRI(unit) = FALSE;

    info_id_map = RX_MAP_STR_INFO(unit, BCMINT_TM_COS_Q_CPU_MAP_INFO_ID);
    if (info_id_map == NULL) {
        SHR_ERR_EXIT(SHR_E_INIT);
    }

    size = RX_MAP_STR_NUM(unit, BCMINT_TM_COS_Q_CPU_MAP_INFO_ID);

    for (i = 0; i < size; i++) {
        SHR_IF_ERR_EXIT
            (mbcm_ltsw_rx_tm_cos_q_cpu_map_info_get(
                unit, info_id_map[i].str, &info));
        if (sal_strcasecmp(info_id_map[i].ifp_opaque_ctrl_id, info.key1) == 0) {
            IFP_OPAQUE_CTRL_ID(unit) = TRUE;
        }

        if (sal_strcasecmp(info_id_map[i].int_pri, info.key2) == 0) {
            INT_PRI(unit) = TRUE;
        }
    }

exit:
    SHR_FUNC_EXIT();
}


static int
bcm56880_a0_ltsw_rx_cosq_mapping_extended_add(
    int unit,
    uint32 options,
    bcm_rx_cosq_mapping_t *rx_cosq_mapping)
{
    rx_cosq_cpu_map_t mapping;
    bcmlt_opcode_t op;
    int port;
    int cpu_cos_number;

    SHR_FUNC_ENTER(unit);

    /* Now zero mapping */
    sal_memset (&mapping, 0, sizeof(rx_cosq_cpu_map_t));

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_key_populate(unit, rx_cosq_mapping, &mapping));

    port = bcmi_ltsw_port_cpu(unit);
    cpu_cos_number = bcmi_ltsw_cosq_port_num_cos(unit, port);

    /* Verify COSQ */
    if (rx_cosq_mapping->cosq >= cpu_cos_number) {
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    }

    /* Verify the priority */
    if (rx_cosq_mapping->priority < 0 ||
        rx_cosq_mapping->priority > COS_MAP_ENTRY_PRIORITY_MAX_VALUE) {
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    }

    mapping.entry_priority = rx_cosq_mapping->priority;
    mapping.cos = rx_cosq_mapping->cosq;
    mapping.truncate = (rx_cosq_mapping->flags & BCM_RX_COPYTOCPU_TRUNCATE) ? 1 : 0;

    op = (options & BCM_RX_COSQ_MAPPING_OPTIONS_REPLACE) ? BCMLT_OPCODE_UPDATE :
                                                           BCMLT_OPCODE_INSERT;

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_handle(unit, op, &mapping));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_cosq_mapping_extended_delete(
    int unit,
    bcm_rx_cosq_mapping_t *rx_cosq_mapping)
{
    rx_cosq_cpu_map_t mapping;

    SHR_FUNC_ENTER(unit);

    /* Now zero mapping */
    sal_memset (&mapping, 0, sizeof(rx_cosq_cpu_map_t));

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_key_populate(unit, rx_cosq_mapping, &mapping));

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_handle(unit, BCMLT_OPCODE_DELETE, &mapping));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_cosq_mapping_extended_delete_all(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmi_lt_clear(unit, TM_COS_Q_CPU_MAPs));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_cosq_mapping_extended_get(
    int unit,
    bcm_rx_cosq_mapping_t *rx_cosq_mapping)
{
    rx_cosq_cpu_map_t mapping;

    SHR_FUNC_ENTER(unit);

    /* Now zero mapping */
    sal_memset(&mapping, 0, sizeof(rx_cosq_cpu_map_t));

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_key_populate(unit, rx_cosq_mapping, &mapping));

    SHR_IF_ERR_VERBOSE_EXIT
        (rx_cosq_mapping_handle(unit, BCMLT_OPCODE_LOOKUP, &mapping));

    rx_cosq_mapping->priority = mapping.entry_priority;
    rx_cosq_mapping->cosq = mapping.cos;
    rx_cosq_mapping->flags = (mapping.truncate == 1) ? BCM_RX_COPYTOCPU_TRUNCATE : 0;

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_queue_channel_get(
    int unit,
    bcm_cos_queue_t queue_id,
    bcm_rx_chan_t *chan_id)
{
    int channel_id;
    bool enable = false;
    int rv = SHR_E_NONE;
    bcmi_ltsw_cosq_device_info_t device_info = {0};

    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmi_ltsw_cosq_device_info_get(unit, &device_info));

    if (queue_id < 0 || queue_id >= device_info.num_cpu_queue) {
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    }

    *chan_id = -1;

    for (channel_id = 0; channel_id < (MAX_CMC *CMICX_N_DMA_CHAN); channel_id++) {
        SHR_IF_ERR_EXIT_EXCEPT_IF
            (bcmi_ltsw_rx_queue_channel_get(unit, queue_id, channel_id, &enable),
             SHR_E_NOT_FOUND);

        if (enable) {
            if (*chan_id == -1) {
                *chan_id = channel_id;
            } else {
                LOG_WARN(BSL_LOG_MODULE,
                    (BSL_META_U(unit,
                                "rx_queue_channel_get: Warning: "
                                "Multiple channels assigned to the "
                                "COS 0x%x for unit %d\n"),
                                queue_id, unit));
                SHR_IF_ERR_VERBOSE_EXIT(SHR_E_INTERNAL);
            }
        }
    }

    rv = ((*chan_id == -1)? SHR_E_NOT_FOUND : SHR_E_NONE);
    SHR_IF_ERR_VERBOSE_EXIT(rv);

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_queue_channel_set(
    int unit,
    bcm_cos_queue_t queue_id,
    bcm_rx_chan_t chan_id)
{
    bcmi_ltsw_cosq_device_info_t device_info = {0};
    int num_queue_pci, num_queue_uc0, start_q, end_q, idx;

    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmi_ltsw_cosq_device_info_get(unit, &device_info));

    if (-1 == chan_id) {
        /* May not disable all queues */
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    } else if ((chan_id < 0) || (chan_id >= (MAX_CMC * CMICX_N_DMA_CHAN))) {
        /* Verify the chan id */
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    } else if (queue_id >= device_info.num_cpu_queue) {
        SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
    }

    if (chan_id < CMICX_N_DMA_CHAN) {
        /*
         * This function does two things:
         * 1. Tests whether the corresponding COS_BMP bit is set or not.
         * 2. Tests whether the queue corresponding to given cos is
         *     mapped to correct L0 or not.
         *
         * L0.0 is associated with CMC0 CH1(Rx) (pci)
         * L0.1 is associated with CMC0 CH2(Rx) (pci)
         * L0.2 is associated with CMC0 CH3(Rx) (pci)
         * L0.3 is associated with CMC0 CH4(Rx) (pci)
         * L0.4 is associated with CMC0 CH5(Rx) (pci)
         * L0.5 is associated with CMC0 CH6(Rx) (pci)
         * L0.6 is associated with CMC0 CH7(Rx) (pci)
         * L0.7 is associated with CMC1 CH1(Rx) (uc0)
         * L0.11 is reserved
         */
        SHR_IF_ERR_VERBOSE_EXIT
            (bcmi_ltsw_rx_queue_channel_set_test(unit, queue_id, chan_id));
    } else {
        if (queue_id > device_info.num_cpu_queue) {
            SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
        }
        num_queue_pci = bcmi_ltsw_property_get(unit, BCMI_CPN_NUM_QUEUES_PCI,
                                               device_info.num_cpu_queue);
        num_queue_uc0 = bcmi_ltsw_property_get(unit, BCMI_CPN_NUM_QUEUES_UC0,
                                               0);

        start_q = num_queue_pci;
        end_q = num_queue_pci + num_queue_uc0;

        if (queue_id == -1) {
            for (idx = start_q; idx < end_q; idx++) {
                SHR_IF_ERR_VERBOSE_EXIT
                    (bcmi_ltsw_rx_queue_channel_set(unit, idx, chan_id, TRUE));
            }
        } else {
            if (queue_id < start_q || queue_id >= end_q) {
                SHR_IF_ERR_VERBOSE_EXIT(SHR_E_PARAM);
            }

            SHR_IF_ERR_VERBOSE_EXIT
                (bcmi_ltsw_rx_queue_channel_set(unit, queue_id, chan_id, TRUE));
        }
    }

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_cosq_mapping_size_get(
    int unit,
    int *size)
{
    uint32_t entry_num = 0;

    SHR_FUNC_ENTER(unit);

    *size = 0;

    SHR_IF_ERR_VERBOSE_EXIT
        (bcmi_lt_capacity_get(unit, TM_COS_Q_CPU_MAPs, &entry_num));

    *size = entry_num + 1;

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_init(int unit)
{
    rx_ctrl_t *rxc = &rx_ctrl[unit];

    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_EXIT
        (mbcm_ltsw_rx_map_db_init(unit, &rxc->rx_db));

    SHR_IF_ERR_EXIT
        (tm_cos_q_cpu_map_info_init(unit));

exit:
    SHR_FUNC_EXIT();
}

static int
bcm56880_a0_ltsw_rx_detach(int unit)
{
    int warm = bcmi_warmboot_get(unit);

    if (!warm) {
        (void)bcmi_lt_clear(unit, TM_COS_Q_CPU_MAPs);
    }

    return SHR_E_NONE;
}

/*!
 * \brief Rx driver function variable for bcm56880_a0 device.
 */
static mbcm_ltsw_rx_drv_t bcm56880_a0_ltsw_rx_drv = {
    .rx_cosq_mapping_extended_add = bcm56880_a0_ltsw_rx_cosq_mapping_extended_add,
    .rx_cosq_mapping_extended_delete = bcm56880_a0_ltsw_rx_cosq_mapping_extended_delete,
    .rx_cosq_mapping_extended_delete_all = bcm56880_a0_ltsw_rx_cosq_mapping_extended_delete_all,
    .rx_cosq_mapping_extended_get = bcm56880_a0_ltsw_rx_cosq_mapping_extended_get,
    .rx_queue_channel_get = bcm56880_a0_ltsw_rx_queue_channel_get,
    .rx_queue_channel_set = bcm56880_a0_ltsw_rx_queue_channel_set,
    .rx_cosq_mapping_size_get = bcm56880_a0_ltsw_rx_cosq_mapping_size_get,
    .rx_init = bcm56880_a0_ltsw_rx_init,
    .rx_detach = bcm56880_a0_ltsw_rx_detach,
};

/******************************************************************************
 * Public functions
 */

int
bcm56880_a0_ltsw_rx_drv_attach(int unit)
{
    SHR_FUNC_ENTER(unit);

    SHR_IF_ERR_VERBOSE_EXIT
        (mbcm_ltsw_rx_drv_set(unit, &bcm56880_a0_ltsw_rx_drv));

    SHR_IF_ERR_VERBOSE_EXIT
        (bcm56880_a0_ltsw_variant_drv_attach(unit, BCM56880_A0_LTSW_VARIANT_RX));

exit:
    SHR_FUNC_EXIT();
}
