/** \file vlan_port_flow.h
 * vlan port functionality for DNX using flow lif
*/

#ifndef _VLAN_PORT_FLOW_INCLUDED__
/*
 * {
 */
#define _VLAN_PORT_FLOW_INCLUDED__

#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX family only!"
#endif /* BCM_DNX_SUPPORT */

#include <bcm/flow.h>
#include <bcm_int/dnx/flow/flow.h>

typedef struct
{
    void *user_data;
    bcm_vlan_port_traverse_cb user_cb;
} dnx_vlan_port_flow_egress_user_data_t;

shr_error_e dnx_vlan_port_flow_terminator_l2_learn_info_set(
    int unit,
    bcm_flow_handle_info_t * flow_handle_info,
    bcm_flow_terminator_info_t * vlan_port_flow_term,
    bcm_vlan_port_t * vlan_port);

shr_error_e dnx_vlan_port_terminator_flow_get(
    int unit,
    bcm_vlan_port_t * vlan_port,
    bcm_flow_handle_info_t * flow_handle_info);
/**
 * Set/get/delete match fields for vlan port terminator according criteria
 */
shr_error_e dnx_vlan_port_terminator_flow_match_action(
    int unit,
    bcm_flow_handle_info_t * flow_handle_info,
    bcm_vlan_port_t * vlan_port,
    dnx_flow_match_action_e action);

/**
  * \brief
 * vlan port create using flow lif
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in,out] vlan_port - vlan port
 */
shr_error_e dnx_vlan_port_flow_create(
    int unit,
    bcm_vlan_port_t * vlan_port);

/**
  * \brief
 * vlan port  get using flow lif
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in,out] vlan_port - vlan port
 */
shr_error_e dnx_vlan_port_flow_get(
    int unit,
    bcm_vlan_port_t * vlan_port);

/**
  * \brief
 * vlan port clear using flow lif
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in] gport - VLAN PORT ID (Gport encoded with at least a type and subtype)
 */
shr_error_e dnx_vlan_port_flow_delete(
    int unit,
    bcm_gport_t gport);

/**
 * \brief
 * Sets INGRESS VLAN Transation parameters for flow lif
 * \param [in] unit -
 *     The unit number.
 * \param [in] vlan_port_translation - structure containing VLAN Translation parameters
 */
shr_error_e dnx_vlan_port_flow_translation_set_ingress(
    int unit,
    bcm_vlan_port_translation_t * vlan_port_translation);

/**
 * \brief
 * Gets INGRESS VLAN Transation parameters of flow lif
 * \param [in] unit -
 *     The unit number.
 * \param [in] vlan_port_translation - structure containing VLAN Translation parameters
 */
shr_error_e dnx_vlan_port_flow_translation_get_ingress(
    int unit,
    bcm_vlan_port_translation_t * vlan_port_translation);

/**
 * \brief
 * Sets EGRESS VLAN Transation parameters for flow lif
 * \param [in] unit -
 *     The unit number.
 * \param [in] vlan_port_translation - structure containing VLAN Translation parameters
 */
shr_error_e dnx_vlan_port_flow_translation_set_egress(
    int unit,
    bcm_vlan_port_translation_t * vlan_port_translation);

/**
 * \brief
 * Gets EGRESS VLAN Transation parameters of flow lif
 * \param [in] unit -
 *     The unit number.
 * \param [in] vlan_port_translation - structure containing VLAN Translation parameters
 */
shr_error_e dnx_vlan_port_flow_translation_get_egress(
    int unit,
    bcm_vlan_port_translation_t * vlan_port_translation);

/**
  * \brief
 * vlan port traverse using flow lif
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in] additional_info - Additional info which can translate to traverse rules
 * \param [in] trav_fn - The function to call with every object that is returned
 * \param [in] user_data - additional data to pass to the trav_fn, along with the returned object
 */
shr_error_e dnx_vlan_port_flow_traverse(
    int unit,
    bcm_vlan_port_traverse_info_t * additional_info,
    bcm_vlan_port_traverse_cb trav_fn,
    void *user_data);

/**
  * \brief
 * vlan port traverse using flow application
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in] app_name - flow application name
 * \param [in] cb - callback function to run
 * \param [in] trav_fn - The function to call with every object that is returned
 * \param [in] user_data - additional data to pass to the trav_fn, along with the returned object
 */

shr_error_e dnx_vlan_port_flow_traverse_egress_app(
    int unit,
    char *app_name,
    bcm_flow_initiator_info_traverse_cb cb,
    bcm_vlan_port_traverse_cb trav_fn,
    void *user_data);

/**
  * \brief
 * This API associated a gport with a VSI by updating the vsi
 * attribute of an In-LIF using flow module
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in] vsi - vsi value
 * \param [in] learn_enable - learning enable/disable
 * \param [in] port - LIF gport
 */
shr_error_e dnx_vswitch_port_flow_add(
    int unit,
    bcm_vlan_t vsi,
    int learn_enable,
    bcm_gport_t port);

/**
  * \brief
 * This API gets the VSI which is associated to gport (the vsi attribute of an In-LIF)
 * using flow module.
 * header profile
 * \param [in] unit -
 *     The unit number.
 * \param [in] port - VLAN-Port gport
 * \param [out] vsi - the vsi value
 */
shr_error_e dnx_vswitch_port_flow_get(
    int unit,
    bcm_gport_t port,
    bcm_vlan_t * vsi);

/**
 * \brief
 * This API disassociates all gports that are associated with the VSI, using flow module.
 * It is done by traversing all In-LIF range and setting the vsi
 * attribute of an associated In-LIF to DNX_VSI_DEFAULT value.
 *
 *   \param [in] unit -
 *     Relevant unit.
 *   \param [in] vsi -
 *     The VSI that the In-LIFs are associated with
 */
shr_error_e dnx_vswitch_port_flow_delete_all(
    int unit,
    bcm_vlan_t vsi);

#endif  /*_VLAN_PORT_FLOW_INCLUDED__ */
