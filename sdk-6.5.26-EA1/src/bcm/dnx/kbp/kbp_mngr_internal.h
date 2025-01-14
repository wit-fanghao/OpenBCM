/*! \file src/bcm/dnx/kbp/kbp_mngr_internal.h
 *
 * Internal DNX KBP APIs
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */

#ifndef _KBP_MNGR_INTERNAL_H_INCLUDED__
/*
 * {
 */
#define _KBP_MNGR_INTERNAL_H_INCLUDED__

#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif

/*
 * Include files
 * {
 */
#include <shared/utilex/utilex_bitstream.h>
#include <soc/dnx/kbp/kbp_common.h>
#include <bcm_int/dnx/kbp/kbp_mngr.h>
#include <soc/dnx/dbal/dbal.h>
#include <soc/dnx/swstate/auto_generated/access/kbp_access.h>
#include "src/soc/dnx/dbal/dbal_internal.h"
/*
 * }
 */

/*
 * DEFINEs
 * {
 */

#define DNX_KBP_DUMMY_HOLE_DB_ID 0
#define DNX_KBP_KEY_SEGMENT_NOT_CONFIGURED "NOT_CONFIGURED"

/** Every master key must be a multiplier of 80 bits (10 bytes).*/
#define DNX_KBP_MASTER_KEY_BYTE_GRANULARITY   (10)
/** The minimum size result can have in bytes..*/
#define DNX_KBP_RESULT_SIZE_MIN_BYTES         (1)

#define DNX_KBP_ACL_CONTEXT_BASE              (DNX_KBP_FWD_CONTEXT_LAST)

#define DNX_KBP_DYNAMIC_OPCODE_BASE           (DNX_KBP_MAX_STATIC_OPCODES_NOF)

#define DNX_KBP_ENTRY_PARSE_FWD_ONLY          (1)

/*
 * }
 */

/*
 * TYPEDEFs
 * {
 */

/*
 * }
 */

/*
 * FUNCTIONs
 * {
 */

shr_error_e kbp_mngr_opcode_lookup_set(
    int unit,
    uint8 opcode_id,
    uint8 lookup_id,
    uint8 lookup_type,
    uint8 *lookup_db,
    uint8 result_id,
    uint8 nof_key_segments,
    uint8 key_segment_index[DNX_KBP_MAX_NOF_SEGMENTS_PER_LOOKUP]);

shr_error_e kbp_mngr_opcode_result_set(
    int unit,
    uint8 opcode_id,
    uint8 result_id,
    uint8 offset,
    uint8 size);

#if defined(BCM_DNX2_SUPPORT) && defined(INCLUDE_KBP)
/* { */
/**
 * \brief
 *   Sets the DB key segments info related to a DB
 *   \param [in] unit - Relevant unit.
 *   \param [in] db_id - KBP DB ID.
 *   \param [in] index - Segment index to get.
 *   \param [in] segment_type - Input segment type in KBP define; Set if not NULL.
 *   \param [in] segment_size - Input segment size in bytes; Set if not NULL.
 *   \param [in] segment_name - Input segment name; Set if not NULL.
 *  \return
 *    \retval errors if unexpected behavior. See \ref shr_error_e
 *  \remark
 *    None
 *  \see
 *    shr_error_e
 */
shr_error_e kbp_mngr_db_key_segment_set(
    int unit,
    uint32 db_id,
    int index,
    uint32 *segment_type,
    uint32 *segment_size,
    char segment_name[DNX_KBP_KEY_SEGMENT_NAME_SIZE_IN_BYTES]);
/**
 * \brief
 *   Gets the DB key segments info related to a DB
 *   \param [in] unit - Relevant unit.
 *   \param [in] db_id - KBP DB ID.
 *   \param [in] index - Segment index to get.
 *   \param [out] segment_type - Returned segment type in KBP define; Returned if not NULL.
 *   \param [out] segment_size - Returned segment size in bytes; Returned if not NULL.
 *   \param [out] segment_name - Returned segment name; Returned if not NULL.
 *  \return
 *    \retval errors if unexpected behavior. See \ref shr_error_e
 *  \remark
 *    None
 *  \see
 *    shr_error_e
 */
shr_error_e kbp_mngr_db_key_segment_get(
    int unit,
    uint32 db_id,
    int index,
    uint32 *segment_type,
    uint32 *segment_size,
    char segment_name[DNX_KBP_KEY_SEGMENT_NAME_SIZE_IN_BYTES]);

/**
 * \brief
 *   Sets the master key segments info related to an opcode
 *   \param [in] unit - Relevant unit.
 *   \param [in] opcode_id - KBP opcode ID.
 *   \param [in] index - Segment index to get.
 *   \param [in] segment_type - Input segment type in KBP define; Set if not NULL.
 *   \param [in] segment_size - Input segment size in bytes; Set if not NULL.
 *   \param [in] segment_name - Input segment name; Set if not NULL.
 *   \param [in] overlay_offset - Input segment overlay offset in bytes; Set if not NULL.
 *  \return
 *    \retval errors if unexpected behavior. See \ref shr_error_e
 *  \remark
 *    None
 *  \see
 *    shr_error_e
 */
shr_error_e kbp_mngr_master_key_segment_set(
    int unit,
    uint32 opcode_id,
    int index,
    uint32 *segment_type,
    uint32 *segment_size,
    char segment_name[DNX_KBP_KEY_SEGMENT_NAME_SIZE_IN_BYTES],
    uint32 *overlay_offset);
/* } */
#endif

/**
 * \brief
 *   Gets the master key segments info related to an opcode
 *   \param [in] unit - Relevant unit.
 *   \param [in] opcode_id - KBP opcode ID.
 *   \param [in] index - Segment index to get.
 *   \param [out] segment_type - Returned segment type in KBP define; Returned if not NULL.
 *   \param [out] segment_size - Returned segment size in bytes; Returned if not NULL.
 *   \param [out] segment_name - Returned segment name; Returned if not NULL.
 *   \param [out] overlay_offset - Returned segment overlay offset in bytes; Returned if not NULL.
 *  \return
 *    \retval errors if unexpected behavior. See \ref shr_error_e
 *  \remark
 *    None
 *  \see
 *    shr_error_e
 */
shr_error_e kbp_mngr_master_key_segment_get(
    int unit,
    uint32 opcode_id,
    int index,
    uint32 *segment_type,
    uint32 *segment_size,
    char segment_name[DNX_KBP_KEY_SEGMENT_NAME_SIZE_IN_BYTES],
    uint32 *overlay_offset);

#if defined(BCM_DNX2_SUPPORT) && defined(INCLUDE_KBP)
/* { */
/**
* \brief
*   Maps FWD and ACL contexts to KBP opcode ID.
*   \param [in] unit - Relevant unit.
*   \param [in] fwd_context - Forwarding context (only from IFWD2 stage and only HW value).
*   \param [in] acl_context - ACL context.
*   \param [in] opcode_id - The KBP opcode ID used by the contexts.
*  \return
*    \retval errors if unexpected behavior. See \ref shr_error_e
*  \remark
*    None
*  \see
*    shr_error_e
*/
shr_error_e kbp_mngr_context_to_opcode_set(
    int unit,
    uint8 fwd_context,
    uint8 acl_context,
    uint8 opcode_id);

/**
 * See kbp_mngr_db_create() in kbp_mngr.h
 */
shr_error_e kbp_mngr_db_create_internal(
    int unit,
    dbal_tables_e table_id,
    uint8 clone_id,
    uint8 acl_db_as_lpm,
    uint8 counters_enable,
    uint32 initial_capacity,
    int algo_mode,
    uint8 *db_id);
/* } */
#endif
/**
 * See kbp_mngr_db_capacity_get() in kbp_mngr.h
 */
shr_error_e kbp_mngr_db_capacity_get_internal(
    int unit,
    uint8 db_id,
    uint32 *nof_entries,
    uint32 *estimated_capacity);

/**
 * \brief - Open a file to facilitate KBPSDK warmboot.
 * \param [in] unit - Relevant unit
 * \param [in] filename - Warmboot file name
 * \param [in] device_type - KBP device type
 * \return
 *    \retval errors if unexpected behavior. See \ref shr_error_e
 * \remark
 *   * None
 * \see
 *   * None
 */
shr_error_e kbp_mngr_wb_file_open(
    int unit,
    char *filename,
    int device_type);

shr_error_e kbp_mngr_opcode_printable_entry_result_parsing(
    int unit,
    uint32 flags,
    uint8 opcode_id,
    uint32 *res_sig_value,
    int res_sig_size,
    uint8 *kbp_entry_print_num,
    kbp_printable_entry_t * kbp_entry_print_info);

shr_error_e kbp_mngr_opcode_printable_entry_key_parsing(
    int unit,
    uint8 opcode_id,
    uint32 *key_sig_value,
    int key_sig_size,
    uint8 *nof_print_info,
    kbp_printable_entry_t * kbp_entry_print_info);

/**
 * See kbp_mngr_opcode_total_result_size_get() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_total_result_size_get_internal(
    int unit,
    uint8 opcode_id,
    uint32 *result_size);

/**
 * See kbp_mngr_opcode_lookup_add() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_lookup_add_internal(
    int unit,
    uint8 opcode_id,
    kbp_opcode_lookup_info_t * lookup_info);

/**
 * See kbp_mngr_opcode_lookup_get() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_lookup_get_internal(
    int unit,
    uint8 opcode_id,
    kbp_opcode_lookup_info_t * lookup_info);

/**
 * See kbp_mngr_opcode_result_clear() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_result_clear_internal(
    int unit,
    uint8 opcode_id,
    uint8 result_id);

/**
 * See kbp_mngr_opcode_master_key_set() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_master_key_set_internal(
    int unit,
    uint8 opcode_id,
    uint32 nof_segments,
    kbp_mngr_key_segment_t * key_segments);

/**
 * See kbp_mngr_opcode_master_key_get() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_master_key_get_internal(
    int unit,
    uint32 opcode_id,
    uint32 *nof_key_segments,
    kbp_mngr_key_segment_t * key_segments);

/**
 * See kbp_mngr_opcode_master_key_segments_add() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_master_key_segments_add_internal(
    int unit,
    uint32 opcode_id,
    uint32 new_segments_index,
    uint32 nof_new_segments,
    kbp_mngr_key_segment_t * key_segments);

/**
 * See kbp_mngr_opcode_master_key_segments_add() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_master_key_segment_remove_internal(
    int unit,
    uint32 opcode_id,
    uint32 segment_index);

/**
 * See kbp_mngr_opcode_create() in kbp_mngr.h
 */
shr_error_e kbp_mngr_opcode_create_internal(
    int unit,
    uint8 source_opcode_id,
    char *opcode_name,
    uint8 *acl_ctx,
    uint8 *new_opcode_id);

/**
 * See kbp_mngr_cache_commit() in kbp_mngr.h
 */
shr_error_e kbp_mngr_cache_commit_internal(
    int unit,
    int is_acl);

/**
 * See kbp_mngr_init() in kbp_mngr.h
 */
shr_error_e kbp_mngr_init_internal(
    int unit);

/**
 * See kbp_mngr_deinit() in kbp_mngr.h
 */
shr_error_e kbp_mngr_deinit_internal(
    int unit);

#if defined(BCM_DNX2_SUPPORT) && defined(INCLUDE_KBP)
/* { */
/**
 * See kbp_mngr_sync() in kbp_mngr.h
 */
shr_error_e kbp_mngr_sync_internal(
    int unit);
/**
 * See kbp_mngr_wb_init() in kbp_mngr.h
 */
shr_error_e kbp_mngr_wb_init_internal(
    int unit);
/* } */
#endif

/**
* \brief
* This function disables the KBP lookups in case the soc properties of the KBP are
* disabled or kbp is not present.
* It is done be zeroing the aligner of the KBP key and the FFCs of the KBP KBRs.
* \param [in]  unit - The Unit number.
* \param [in]  context_index - The context to disable.
* \return
*    \retval errors if unexpected behavior. See \ref shr_error_e
* \remark
*   None
* \see
*   shr_error_e
*/
shr_error_e kbp_mngr_lookups_disable(
    int unit,
    uint32 context_index);

/*
 *
 * }
 */

#endif /* _KBP_MNGR_INTERNAL_H_INCLUDED__ */
