/*
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        cint_retimer.c
 *
 * Purpose:
 *
 * Notes:
 *              1) Relevant functions for user:
 *                  - cint_dnxf_fe2_to_pass_through_retimer_set
 *                  - cint_dnxf_pass_through_retimer_to_fe2_set
 *                  - cint_find_fe_to_fap_links
 *                  - cint_dnxf_fe2_to_loopback_retimer_set
 *                  - cint_dnxf_loopback_retimer_to_fe2_set
 *
 */

/*
 * Function:
 *      cint_dnxf_fe2_to_pass_through_retimer_set
 *
 * Purpose:
 *      To set DNXF device into pass-through retimer mode. This is done by setting all FE links into retimer mode
 *      and connecting lower half of the FE links to the high half.
 *
 * Parameters:
 *      unit                                 (IN) - unit #
 *
 * Returns:
 *      BCM_E_XXX
 *
 * Notes:
 *
 */
int
cint_dnxf_fe2_to_pass_through_retimer_set(
    int fe_unit)
{
    char error_msg[200]={0,};
    bcm_port_t link = 0;
    uint32 remote_link;
    uint32 nof_links = *(dnxc_data_get(fe_unit, "port", "general", "nof_links", NULL));
    bcm_info_t info;

    snprintf(error_msg, sizeof(error_msg), "failed for fe_unit %d .", fe_unit);
    BCM_IF_ERROR_RETURN_MSG(bcm_info_get (fe_unit, &info), error_msg);

    /* 
    * retimer links should be isolated
    */ 
    for (link = 0; link < nof_links; link++) {
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", link);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, link, bcmFabricLinkIsolate, 1), error_msg);
    }

    /*
     * Set first half of the links into retimer mode.
     * No need to use API on other half because when link is set into retimer mode
     * it actually also configures its relevant link on the other side
     * and also sets it in retimer mode creating complate bi-directional connection.
     */
    for (link = 0; link < nof_links / 2; link++) {
        remote_link = *(dnxc_data_1d_get (fe_unit, "port", "retimer", "links_connection", "connected_link", link));
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", link);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, link, bcmFabricLinkRetimerConnect, remote_link), error_msg);
    }

    printf("cint_dnxf_fe2_to_pass_through_retimer_set: PASS - fe_unit %d.\n", fe_unit);
    return BCM_E_NONE;
}

/*
 * Function:
 *      cint_dnxf_pass_through_retimer_to_fe2_set
 *
 * Purpose:
 *      To unset DNXF device from pass-through retimer mode.
 *
 * Parameters:
 *      unit                                 (IN) - unit # 
 *
 * Returns:
 *      BCM_E_XXX
 *
 * Notes:
 *
 */
int
cint_dnxf_pass_through_retimer_to_fe2_set(
    int fe_unit)
{
    char error_msg[200]={0,};
    bcm_port_t link = 0;
    uint32 nof_links = *(dnxc_data_get(fe_unit, "port", "general", "nof_links", NULL));
    bcm_info_t info;

    snprintf(error_msg, sizeof(error_msg), "failed for fe_unit %d .", fe_unit);
    BCM_IF_ERROR_RETURN_MSG(bcm_info_get (fe_unit, &info), error_msg);

    /* 
    * Unset retimer mode
    */ 
    for (link = 0; link < nof_links / 2; link++) {
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", link);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, link, bcmFabricLinkRetimerConnect, -1), error_msg);
    }

    /*
     * When setting links into retimer, they should be isolated.
     * When setting links back to FE2 - we remove the isolation, so that the link will operate as normal FE2 link.
     */
    for (link = 0; link < nof_links; link++) {
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", link);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, link, bcmFabricLinkIsolate, 0), error_msg);
    }

    printf("cint_dnxf_pass_through_retimer_to_fe2_set: PASS - fe_unit %d.\n", fe_unit);
    return BCM_E_NONE;
}
/*
 * Function:
 *      cint_find_fe_to_fap_links
 *
 * Purpose:
 *      To find all links connecting the FE to a given FAP
 *
 * Parameters:
 *      fe_unit                              (IN) - unit #
 *      fap_unit                             (IN) - fap_unit # Unit id of one of the FAPs connected to the FE in the MGMT system
 *      max_links                            (IN) - max_links # Max number of possible links connecting FE to FAP / size of fe_to_fap_links_array
 *      fe_to_fap_links_array                (OUT) - Array of all links connecting the FE to the given FAP
 *      fe_to_fap_nof_links                  (OUT) - The count of the links connecting the FE to the given FAP
 *
 * Returns:
 *      BCM_E_XXX
 *
 * Notes:
 *
 */
int
cint_find_fe_to_fap_links(
    int fe_unit,
    int fap_unit,
    int max_links,
    bcm_port_t *fe_to_fap_links_array,
    int *fe_to_fap_nof_links)
{
    int link_idx = 0;
    uint32 nof_fe_links = *(dnxc_data_get(fe_unit, "port", "general", "nof_links", NULL));
    bcm_fabric_link_connectivity_t fe_connectivity_array[nof_fe_links];
    int nof_fe_connectivity_links;
    bcm_port_config_t config;
    bcm_port_t port;

    int fap_base_modid;
    BCM_IF_ERROR_RETURN_MSG(bcm_stk_my_modid_get(fap_unit, &fap_base_modid), "");

    /*
     * Get all FE active links connectivity status
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_connectivity_status_get(fe_unit, nof_fe_links, fe_connectivity_array , &nof_fe_connectivity_links), "");

    /*
     * Get all links from FE to the FAP
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_port_config_get(fe_unit, &config), "");

    link_idx = 0;
    *fe_to_fap_nof_links = 0;
    BCM_PBMP_ITER(config.sfi, port)
    {
        if (*fe_to_fap_nof_links > max_links)
        {
            printf("fe_to_fap_links_array is too small .\n");
            return BCM_E_PARAM;
        }

        if ((fe_connectivity_array[link_idx].link_id != BCM_FABRIC_LINK_NO_CONNECTIVITY) && (fe_connectivity_array[link_idx].module_id == fap_base_modid))
        {
            fe_to_fap_links_array[*fe_to_fap_nof_links] = port;
            ++(*fe_to_fap_nof_links);
        }
        ++link_idx;
    }

    printf("cint_find_fe_to_fap_links: PASS - fe_unit %d and fap_unit %d.\n", fe_unit, fap_unit);
    return BCM_E_NONE;
}


/*
 * Function:
 *      cint_dnxf_fe2_to_loopback_retimer_set
 *
 * Purpose:
 *      To set DNXF device into loopback retimer mode.
 *      This is done by connecting FAP0 sfi links to FAP1 sfi links
 *      using the FE to make the connetions
 *
 * Parameters:
 *      fe_unit                                 (IN) - unit #
 *      fe_to_fap0_links_array                  (IN) - fe_to_fap0_links_array # The links from the FE to FAP0
 *                                                      which after the cint execution will be in retimer mode.
 *      fe_to_fap1_links_array                  (IN) - fe_to_fap1_links_array # The links from the FE to FAP1
 *                                                      which after the cint execution will be in retimer mode.
 *      fe_to_fap_nof_links                     (IN) - fe_to_fap_nof_links # nof links from FE to each FAP / size of fe_to_fap0_links_array, fe_to_fap1_links_array.
 *                                                      nof links FE-FAP0 configured as retimer == nof links FE-FAP1 configured as retimer
 *                                                      since each FE-FAP0 link is connected to FE-FAP1 link as retimer.
 * Returns:
 *      BCM_E_XXX
 *
 * Notes:
 *
 */
int
cint_dnxf_fe2_to_loopback_retimer_set(
    int fe_unit,
    int fe_to_fap_nof_links,
    bcm_port_t *fe_to_fap0_links_array,
    bcm_port_t *fe_to_fap1_links_array)
{
    char error_msg[200]={0,};
    int link_idx = 0;
    int i;

    /*
     * retimer links should be isolated
     */
    for (link_idx = 0; link_idx < fe_to_fap_nof_links; link_idx++) {
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", fe_to_fap0_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap0_links_array[link_idx], bcmFabricLinkIsolate, 1), error_msg);

        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", fe_to_fap1_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap1_links_array[link_idx], bcmFabricLinkIsolate, 1), error_msg);
    }

    /*
     * Enable retimer FEC
     */
    for (link_idx = 0; link_idx < fe_to_fap_nof_links; link_idx++) {
        snprintf(error_msg, sizeof(error_msg), "bcmFabricLinkRetimerFecEnable failed for link %d.", fe_to_fap0_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap0_links_array[link_idx], bcmFabricLinkRetimerFecEnable, 1), error_msg);

        snprintf(error_msg, sizeof(error_msg), "bcmFabricLinkRetimerFecEnable failed for link %d.", fe_to_fap1_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap1_links_array[link_idx], bcmFabricLinkRetimerFecEnable, 1), error_msg);
    }

    /* 
    * Connect in couples all FE-FAP0 links to their associative FE-FAP1 link 
    */ 
    if (*(dnxc_data_get(fe_unit, "device", "general", "serdes_support", NULL))) 
    {
        for (link_idx = 0; link_idx < fe_to_fap_nof_links; link_idx++) {
            printf("Connecting link %d to link %d \n", fe_to_fap0_links_array[link_idx], fe_to_fap1_links_array[link_idx]);

            snprintf(error_msg, sizeof(error_msg), "failed for link_a %d and link_b %d.",
                fe_to_fap0_links_array[link_idx], fe_to_fap1_links_array[link_idx]);
            BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap0_links_array[link_idx], bcmFabricLinkRetimerConnect, fe_to_fap1_links_array[link_idx]), error_msg);
        }
    }

    printf("cint_dnxf_fe2_to_loopback_retimer_set: PASS - fe_unit %d, .\n", fe_unit);
    return BCM_E_NONE;
}

/*
 * Function:
 *      cint_dnxf_loopback_retimer_to_fe2_set
 *
 * Purpose:
 *      To unset DNXF device from loopback retimer mode.
 *      Cint assume that either cint_dnxf_fe2_to_loopback_retimer_set is used to set FE in loopback retimer mode
 *      or that all FE links are in loopback retimer mode
 *
 * Parameters:
 *      fe_unit                              (IN) - unit #
 *      fe_to_fap0_retimer_links_array       (IN) - fe_to_fap0_retimer_links_array # Array of links from FE to FAP0 to unset from retimer mode
 *      fe_to_fap1_retimer_links_array       (IN) - fe_to_fap1_retimer_links_array # Array of links from FE to FAP1 to unset from retimer mode
 *      fe_to_fap_nof_links                  (IN) - fe_to_fap_nof_links # Count of links from FE to FAP to unset from retimer mode.
 *                                                  nof links FE-FAP0 configured as retimer == nof links FE-FAP1 configured as retimer
 *                                                  since each FE-FAP0 link is connected to FE-FAP1 link as retimer.
 * Returns:
 *      BCM_E_XXX
 *
 * Notes:
 *
 */
int
cint_dnxf_loopback_retimer_to_fe2_set(
    int fe_unit,
    bcm_port_t *fe_to_fap0_retimer_links_array,
    bcm_port_t *fe_to_fap1_retimer_links_array,
    int fe_to_fap_nof_links)
{
    char error_msg[200]={0,};
    bcm_port_t link_idx = 0;

    /* 
    * Unset loopback retimer mode. 
    * Disabling retimer mode only on the links connecting FAP0 to the FE is enough to unset loopback retimer.
    * This is because when un-setting retimer link it unset both related links.                                                                           .
    */
    if(*(dnxc_data_get(fe_unit, "device", "general", "serdes_support", NULL)))
    {
        for (link_idx = 0; link_idx < fe_to_fap_nof_links; link_idx++) {
            snprintf(error_msg, sizeof(error_msg), "failed for link %d .", fe_to_fap0_retimer_links_array[link_idx]);
            BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap0_retimer_links_array[link_idx], bcmFabricLinkRetimerConnect, -1), error_msg);
        }
    }

    /*
     * When setting links into retimer, they should be isolated.
     * When setting links back to FE2 - we remove the isolation, so that the link will operate as normal FE2 link.
     */
    for (link_idx = 0; link_idx < fe_to_fap_nof_links; link_idx++) {
        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", fe_to_fap0_retimer_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap0_retimer_links_array[link_idx], bcmFabricLinkIsolate, 0), error_msg);

        snprintf(error_msg, sizeof(error_msg), "failed for link %d .", fe_to_fap1_retimer_links_array[link_idx]);
        BCM_IF_ERROR_RETURN_MSG(bcm_fabric_link_control_set(fe_unit, fe_to_fap1_retimer_links_array[link_idx], bcmFabricLinkIsolate, 0), error_msg);
    }

    printf("cint_dnxf_loopback_retimer_to_fe2_set: PASS - fe_unit %d .\n", fe_unit);
    return BCM_E_NONE;
}

