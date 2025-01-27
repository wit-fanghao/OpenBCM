/*
 * File: cint_rx_trap_l2cp_exhaustive.c
 * PORTED FROM: cint_l2cp_traps_config.c
 *
 * Purpose: Random L2CP traps allocation together with basic L2 forwarding,
 *          for the packets that don't match on the L2CP traps.
 *
 * Helper functions:
 * cint_rx_trap_l2cp_exhaustive_l2_config(unit,vsi,in_port,out_port);
 *
 * cint ../../../../src/examples/dnx/traps/cint_rx_trap_l2cp_exhaustive.c
 *
 * Main Function:
 *      cint_rx_trap_l2cp_exhaustive_main(unit,inP,outP,l2cp_trap_profile,step,vlan);
 * Destroy Function:
 *      cint_rx_trap_l2cp_exhaustive_destroy(unit,l2cp_trap_profile,step,vlan);
 *
 * Example Config:
 * Test Scenario - start
  cint ../../../../src/examples/dnx/traps/cint_utils_rx.c
  cint ../../../../src/examples/dnx/traps/cint_rx_trap_l2cp_exhaustive.c
  cint
  cint_rx_trap_l2cp_exhaustive_main(0,200,202,1,3,100);
 * Test Scenario - end
 */

int cint_rx_trap_l2cp_exhaustive_trap_id;

/**
* \brief
* Creates an L2 config to forward packets, which do not match the traps created.
*
* \par DIRECT INPUT:
*   \param [in] unit      - unit Id
*   \param [in] vsi       - VLAN/VSI
*   \param [in] in_port   - In Port
*   \param [in] out_port  - Out Port
* \par INDIRECT INPUT:
*   * None
* \par DIRECT OUTPUT:
*   int - Error type
* \par INDIRECT OUTPUT:
*   * None
* \remark
*   * None
* \see
*   * None
*/
int cint_rx_trap_l2cp_exhaustive_l2_config(
    int unit,
    int vsi,
    int in_port,
    int out_port)
{
    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_create(unit, vsi), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit, vsi, in_port, BCM_VLAN_GPORT_ADD_INGRESS_ONLY), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_gport_add(unit, vsi, out_port, BCM_VLAN_GPORT_ADD_EGRESS_ONLY), "");

    return BCM_E_NONE;
}

/**
* \brief
* Creates a UserDefined Ingress trap and sets a multiple L2CP Protocol traps
* with action drop.
*
* \par DIRECT INPUT:
*   \param [in] unit                - unit Id
*   \param [in] inP                 - In Port
*   \param [in] l2cp_trap_profile   - L2CP Trap profile
*   \param [in] step                - Step incrementation for L2CP args
* \par INDIRECT INPUT:
*   * None
* \par DIRECT OUTPUT:
*   int - Error type
* \par INDIRECT OUTPUT:
*   * None
* \remark
*   * None
* \see
*   * None
*/
int cint_rx_trap_l2cp_exhaustive_l2cp_trap(
   int unit,
   int inP,
   int l2cp_trap_profile,
   int step)
{
    int fwd_strength = 7, snp_strength = 0;
    int i;
    int nof = 0;
    bcm_gport_t trap_gport;
    bcm_rx_trap_protocol_key_t key ;
    bcm_rx_trap_protocol_profiles_t protocol_profiles = { 0 };

    if (step == 0 || step > 63)
    {   printf("ERROR: step =%d\n",step);
        return ERR_E_PARAM;
    }

    BCM_IF_ERROR_RETURN_MSG(cint_utils_rx_trap_ingress_create_and_set_to_drop(unit, 0, bcmRxTrapUserDefine,0, &cint_rx_trap_l2cp_exhaustive_trap_id), "");

    protocol_profiles.l2cp_trap_profile = l2cp_trap_profile;

    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_protocol_profiles_set(unit, inP, &protocol_profiles), "");

    BCM_GPORT_TRAP_SET(trap_gport, cint_rx_trap_l2cp_exhaustive_trap_id, fwd_strength, snp_strength);

    key.protocol_type = bcmRxTrapL2cpPeer;
    key.protocol_trap_profile = l2cp_trap_profile;

    for (i = 0; i < BCM_RX_TRAP_L2CP_NOF_ENTRIES; i += step)
    {
        key.trap_args = i;
        nof++;

        BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_protocol_set(unit, &key, trap_gport), "");
    }

    return BCM_E_NONE;
}

/**
* \brief
* Main function of the cint which calls the L2 set-up and then the L2CP trap creation,
* according to the 'step' param..
* \par DIRECT INPUT:
*   \param [in] unit            - unit Id
*   \param [in] inP             - In Port
*   \param [in] outP            - Out Port
*   \param [in] l2cp_profile    - L2CP Trap profile
*   \param [in] step            - L2CP trap args stepping
*   \param [in] vlan            - VLAN
* \par INDIRECT INPUT:
*   * None
* \par DIRECT OUTPUT:
*   int - Error type
* \par INDIRECT OUTPUT:
*   * None
* \remark
*   * None
* \see
*   * None
*/
int cint_rx_trap_l2cp_exhaustive_main(
    int unit,
    int inP,
    int outP,
    int l2cp_profile,
    int step,
    int vlan)
{
    BCM_IF_ERROR_RETURN_MSG(cint_rx_trap_l2cp_exhaustive_l2_config(unit, vlan, inP, outP), "");

    BCM_IF_ERROR_RETURN_MSG(cint_rx_trap_l2cp_exhaustive_l2cp_trap(unit, inP, l2cp_profile, step), "");

    return BCM_E_NONE;
}

/**
* \brief
* Destroy function of the cint which clears the L2CP traps created by the supplied 'step'.
* \par DIRECT INPUT:
*   \param [in] unit            - unit Id
*   \param [in] l2cp_profile    - L2CP Trap profile
*   \param [in] step            - L2CP trap args stepping
*   \param [in] vlan            - VLAN to be deleted
* \par INDIRECT INPUT:
*   * None
* \par DIRECT OUTPUT:
*   int - Error type
* \par INDIRECT OUTPUT:
*   * None
* \remark
*   * None
* \see
*   * None
*/
int cint_rx_trap_l2cp_exhaustive_destroy(
    int unit,
    int l2cp_profile,
    int step,
    int vlan)
{
    int i;
    bcm_rx_trap_protocol_key_t key;

    BCM_IF_ERROR_RETURN_MSG(bcm_vlan_destroy(unit, vlan), "");

    if (*dnxc_data_get(unit, "multicast", "params", "mcdb_formats_v2", NULL)) {
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_group_destroy(unit, (BCM_MULTICAST_INGRESS_GROUP | BCM_MULTICAST_ELEMENT_STATIC), vlan), "");
    } else {
        BCM_IF_ERROR_RETURN_MSG(bcm_multicast_destroy(unit, vlan), "");
    }

    key.protocol_type = bcmRxTrapL2cpPeer;
    key.protocol_trap_profile = l2cp_profile;

    for (i = 0; i < BCM_RX_TRAP_L2CP_NOF_ENTRIES; i += step)
    {
        key.trap_args = i;
        BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_protocol_clear(unit,&key), "");
    }
    BCM_IF_ERROR_RETURN_MSG(bcm_rx_trap_type_destroy(unit, cint_rx_trap_l2cp_exhaustive_trap_id), "");

    return BCM_E_NONE;
}
