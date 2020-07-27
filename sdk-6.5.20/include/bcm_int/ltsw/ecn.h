/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#ifndef BCMI_LTSW_ECN_H
#define BCMI_LTSW_ECN_H

#include <bcm/switch.h>
#include <bcm/types.h>

#include <sal/sal_types.h>

/*! Encoding ID for ING_MPLS_EXP_TO_ECN type. */
#define BCMI_LTSW_ECN_MPLS_ECN_MAP_TYPE_EXP2ECN (0x4000)

/*! Encoding ID for ECN_IP_TO_MPLS_EXP type. */
#define BCMI_LTSW_ECN_MPLS_ECN_MAP_TYPE_ECN2EXP (0x8000)

/*! Encoding ID for ECN_CNG_TO_MPLS_EXP type. */
#define BCMI_LTSW_ECN_MPLS_ECN_MAP_TYPE_INTCN2EXP (0xC000)

/*! Encoding ID for ECN_TNL_DECAP_IP_PAYLOAD type. */
#define BCMI_LTSW_ECN_TUNNEL_ECN_MAP_TYPE_TERM (0x10000)

/*! Encoding ID for ECN_TNL_ENCAP_IP_PAYLOAD type. */
#define BCMI_LTSW_ECN_TUNNEL_ECN_MAP_TYPE_INIT_IP_PAYLOAD (0x20000)

/*! Encoding ID for ECN_TNL_ENCAP_NON_IP_PAYLOAD type. */
#define BCMI_LTSW_ECN_TUNNEL_ECN_MAP_TYPE_INIT_NON_IP_PAYLOAD (0x40000)

/*! Encoding ID for ECN_LATENCY_PROFILE type. */
#define BCMI_LTSW_ECN_LATENCY_ECN_MAP_TYPE (0x80000)

/*!
 * \brief Resolve ECN map ID.
 *
 * \param [in] unit Unit Number.
 * \param [in] ecn_map_id ECN map ID.
 * \param [out] ecn_map_type ECN map type.
 * \param [out] prof_id ECN map profile ID.
 */
extern int
bcmi_ltsw_ecn_map_id_resolve(
    int unit,
    int ecn_map_id,
    int *ecn_map_type,
    uint32_t *prof_id);

/*!
 * \brief Construct ECN map ID.
 *
 * \param [in] unit Unit Number.
 * \param [in] ecn_map_type ECN map type.
 * \param [in] prof_id ECN map profile ID.
 * \param [out] ecn_map_id ECN map ID.
 */
extern int
bcmi_ltsw_ecn_map_id_construct(
    int unit,
    int ecn_map_type,
    uint32_t prof_id,
    int *ecn_map_id);

/*!
 * \brief Deinit ECN module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_deinit(int unit);

/*!
 * \brief Init ECN module.
 *
 * \param [in] unit Unit Number.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_init(int unit);

/*!
 * \brief Set latency-based ECN mode.
 *
 * \param [in] unit Unit Number.
 * \param [in] mode mode.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_latency_based_mode_set(
    int unit,
    bcm_switch_latency_ecn_mark_mode_t mode);

/*!
 * \brief Get latency-based ECN mode.
 *
 * \param [in] unit Unit Number.
 * \param [out] mode mode.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_latency_based_mode_get(
    int unit,
    bcm_switch_latency_ecn_mark_mode_t *mode);

/*!
 * \brief Set latency-based ECN threshold.
 *
 * \param [in] unit Unit Number.
 * \param [in] gport Port number or GPORT identifier.
 * \param [in] cosq COS queue number.
 * \param [in] mode mode.
 * \param [in] threshold threshold.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_latency_based_threshold_set(
    int unit,
    bcm_gport_t gport,
    bcm_cos_queue_t cosq,
    bcm_switch_latency_ecn_mark_mode_t mode,
    uint32_t threshold);

/*!
 * \brief Get latency-based ECN threshold.
 *
 * \param [in] unit Unit Number.
 * \param [in] gport Port number or GPORT identifier.
 * \param [in] cosq COS queue number.
 * \param [in] mode mode.
 * \param [out] threshold threshold.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_latency_based_threshold_get(
    int unit,
    bcm_gport_t gport,
    bcm_cos_queue_t cosq,
    bcm_switch_latency_ecn_mark_mode_t mode,
    uint32_t *threshold);

/*!
 * \brief To set the default responsive value for Non-TCP packets.
 *
 * \param [in] unit Unit Number.
 * \param [in] value Default responsive value.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_responsive_default_set(
    int unit,
    int value);

/*!
 * \brief To get the default responsive value for Non-TCP packets.
 *
 * \param [in] unit Unit Number.
 * \param [out] value Returned default responsive value.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_responsive_default_get(
    int unit,
    int *value);

/*!
 * \brief Enable or disable one field ECN control table.
 *
 * \param [in] unit Unit Number.
 * \param [in] lt_name ecn_ctrl_name LT name.
 * \param [in] lt_fld_name ecn_ctrl_fld LT field name.
 * \param [in] val value set in the field.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_ctrl_set(
    int unit,
    const char *lt_name,
    const char *lt_fld_name,
    int val);

/*!
 * \brief Get status ECN control table.
 *
 * \param [in] unit Unit Number.
 * \param [in] lt_name ecn_ctrl_name LT name.
 * \param [in] lt_fld_name ecn_ctrl_fld LT field name.
 * \param [in] val value get in the field.
 *
 * \retval SHR_E_NONE No errors.
 * \retval !SHR_E_NONE Failure.
 */
extern int
bcmi_ltsw_ecn_ctrl_get(
    int unit,
    const char *lt_name,
    const char *lt_fld_name,
    int *val);

#endif /* BCMI_LTSW_ECN_H */