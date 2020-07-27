/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef BCMINT_LTSW_XGS_FLOWTRACKER_H
#define BCMINT_LTSW_XGS_FLOWTRACKER_H

#include <bcm/types.h>
#include <bcm/flowtracker.h>

#include <sal/sal_types.h>

/*!
 * \brief Deinitialize Flowtracker module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_detach(int unit);

/*!
 * \brief Init Flowtracker module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_init(int unit);

/*!
 * \brief Set the match criteria for an elephant action.
 *
 * \param [in] unit Unit Number.
 * \param [in] action Match action.
 * \param [in] match_types Match types.
 * \param [in] match_data Match data.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_action_match_set(
    int unit,
    bcm_flowtracker_elephant_match_action_t action,
    uint32_t match_types,
    bcm_flowtracker_elephant_match_data_t *match_data);

/*!
 * \brief Get the match criteria for an elephant action.
 *
 * \param [in] unit Unit Number.
 * \param [in] action Match action.
 * \param [out] match_types Match types.
 * \param [out] match_data Match data.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_action_match_get(
    int unit,
    bcm_flowtracker_elephant_match_action_t action,
    uint32_t *match_types,
    bcm_flowtracker_elephant_match_data_t *match_data);

/*!
 * \brief Set the internal priority remap for elephant flows.
 *
 * \param [in] unit Unit Number.
 * \param [in] int_pri Internal priority.
 * \param [in] new_int_pri New internal priority.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_int_pri_remap_set(
    int unit,
    bcm_cos_t int_pri,
    bcm_cos_t new_int_pri);

/*!
 * \brief Get the internal priority remap from elephant flows.
 *
 * \param [in] unit Unit Number.
 * \param [in] int_pri Internal priority.
 * \param [out] new_int_pri New internal priority.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_int_pri_remap_get(
    int unit,
    bcm_cos_t int_pri,
    bcm_cos_t *new_int_pri);

/*!
 * \brief Set the hashing configuration.
 *
 * \param [in] unit Unit Number.
 * \param [in] hash_table Hash table.
 * \param [in] instance_num Hash table instance number.
 * \param [in] bank_num Hash table bank number.
 * \param [in] hash_type Hash type.
 * \param [in] right_rotate_bits Number of bits the hash result should be rotated.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_hash_config_set(
    int unit,
    bcm_flowtracker_elephant_hash_table_t hash_table,
    int instance_num,
    int bank_num,
    bcm_flowtracker_elephant_hash_type_t hash_type,
    int right_rotate_bits);

/*!
 * \brief Get the hashing configuration.
 *
 * \param [in] unit Unit Number.
 * \param [in] hash_table Hash table.
 * \param [in] instance_num Hash table instance number.
 * \param [in] bank_num Hash table bank number.
 * \param [out] hash_type Hash type.
 * \param [out] right_rotate_bits Number of bits the hash result should be rotated.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_hash_config_get(
    int unit,
    bcm_flowtracker_elephant_hash_table_t hash_table,
    int instance_num,
    int bank_num,
    bcm_flowtracker_elephant_hash_type_t *hash_type,
    int *right_rotate_bits);

/*!
 * \brief Set the control configuration.
 *
 * \param [in] unit Unit Number.
 * \param [in] type Control type.
 * \param [in] arg Control value.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_control_set(
    int unit,
    bcm_flowtracker_elephant_control_t type,
    int arg);

/*!
 * \brief Get the control configuration.
 *
 * \param [in] unit Unit Number.
 * \param [in] type Control type.
 * \param [out] arg Control value.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_control_get(
    int unit,
    bcm_flowtracker_elephant_control_t type,
    int *arg);

/*!
 * \brief Get the elephant counters.
 *
 * \param [in] unit Unit Number.
 * \param [out] stats Elephant statistics.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_stats_get(
    int unit,
    bcm_flowtracker_elephant_stats_t *stats);

/*!
 * \brief Get the elephant counters.
 *
 * \param [in] unit Unit Number.
 * \param [out] stats Elephant statistics.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
xgs_ltsw_flowtracker_elephant_stats_sync_get(
    int unit,
    bcm_flowtracker_elephant_stats_t *stats);

#endif /* BCMINT_LTSW_XGS_FLOWTRACKER_H */