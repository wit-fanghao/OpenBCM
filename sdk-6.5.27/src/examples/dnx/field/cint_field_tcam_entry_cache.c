/*
 * Configuration example start:
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/field/cint_field_tcam_entry_cache.c
  cint;
  int unit = 0;
  bcm_field_context_t ctx_id = 0;
  cint_field_tcam_entry_cache_main(unit, ctx_id);
 * Test Scenario - end
 *
 * Configuration example end
 *
 *   This CINT shows how to add entries to TCAM field group using cache.
 *
 */

 /**
  * Global variables
  */
int nof_entries = 6;
bcm_field_context_t cint_field_tcam_entry_cache_ctx_id;
bcm_field_group_t cint_field_tcam_entry_cache_fg_id;
bcm_field_entry_t cint_field_tcam_entry_cache_entry_ids[nof_entries];

int cint_field_tcam_entry_cache_ttl_hit = 7;
int cint_field_tcam_entry_cache_tc_hit = 5;

/**
* \brief
*  This function creates TCAM field group in IPMF1, attaches it, and adds 5 entries to cache.
* \param [in] unit              - Device ID.
* \param [in] ctx_id            - Context ID.
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int cint_field_tcam_entry_cache_main(
       int unit,
       int ctx_id)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_entry_info_t entry_info;
    void *dest_char;
    int ii;

    cint_field_tcam_entry_cache_ctx_id = ctx_id;
    bcm_field_group_info_t_init(&fg_info);
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "TCAM_CACHE_FG", sizeof(fg_info.name));
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = bcmFieldStageIngressPMF1;

    fg_info.nof_quals = 1;
    /* Set quals */
    fg_info.qual_types[0] = bcmFieldQualifyIp4Ttl;
    fg_info.nof_actions = 1;
    /* Set actions */
    fg_info.action_types[0] = bcmFieldActionPrioIntNew;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &cint_field_tcam_entry_cache_fg_id), "");

    printf("Field Group %d was created. \n", cint_field_tcam_entry_cache_fg_id);

    bcm_field_group_attach_info_t_init(&attach_info);
    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeLayerAbsolute;
    attach_info.key_info.qual_info[0].input_arg = 1;
    attach_info.key_info.qual_info[0].offset = 0;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, cint_field_tcam_entry_cache_fg_id, cint_field_tcam_entry_cache_ctx_id, &attach_info), "");

    printf("Field Group %d was attached to context %d. \n", cint_field_tcam_entry_cache_fg_id, cint_field_tcam_entry_cache_ctx_id);

    /**
     * Set TCAM field group cache mode to Start
     * From now on all the entries that will be added to the field group will be saved on cache,
     * and will have no effect on traffic
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeStart), "");

    printf("Set TCAM field group %d mode to Start\n", cint_field_tcam_entry_cache_fg_id);

    /**
     * Add 5 entries to TCAM field group cache.
     */
    for (ii = 0; ii < nof_entries; ii++)
    {
        bcm_field_entry_info_t_init(&entry_info);
        entry_info.nof_entry_quals = fg_info.nof_quals;
        entry_info.nof_entry_actions = fg_info.nof_actions;

        entry_info.entry_qual[0].type = fg_info.qual_types[0];
        entry_info.entry_qual[0].value[0] = ii;
        entry_info.entry_qual[0].mask[0] = 0xff;

        entry_info.entry_action[0].type = fg_info.action_types[0];
        entry_info.entry_action[0].value[0] = ii;

        BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_field_tcam_entry_cache_fg_id, &entry_info, &cint_field_tcam_entry_cache_entry_ids[ii]), "");

        printf("Entry 0x%X (%d) was added to field group %d cache. \n", cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_fg_id);
    }

    /**
     * Set TCAM field group cache mode to Clear.
     * All pending entries will be deleted from memory.
     * No need to call bcm_field_entry_delete() for each entry,
     * Clear sets the cache mode to OFF.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeClear), "");

    printf("Set TCAM field group %d mode to Clear\n", cint_field_tcam_entry_cache_fg_id);

    /**
     * Set TCAM field group cache mode again to Start.
     * After setting cache mode to Clear, Start need to be invoked again.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeStart), "");

    printf("Set TCAM field group %d mode to Start\n", cint_field_tcam_entry_cache_fg_id);

    /**
     * Add 5 entries to TCAM field group cache.
     */
    for (ii = 0; ii < nof_entries - 1; ii++)
    {
        bcm_field_entry_info_t_init(&entry_info);
        entry_info.nof_entry_quals = fg_info.nof_quals;
        entry_info.nof_entry_actions = fg_info.nof_actions;

        entry_info.entry_qual[0].type = fg_info.qual_types[0];
        entry_info.entry_qual[0].value[0] = ii + 2;
        entry_info.entry_qual[0].mask[0] = 0xff;

        entry_info.entry_action[0].type = fg_info.action_types[0];
        entry_info.entry_action[0].value[0] = ii;

        BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_field_tcam_entry_cache_fg_id, &entry_info, &cint_field_tcam_entry_cache_entry_ids[ii]), "");

        printf("Entry 0x%X (%d) was added to field group %d cache. \n", cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_fg_id);
    }

    /**
     * Set TCAM field group cache mode to Install.
     * All TCAM entries that were saved in cache are now committed to HW.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeInstall), "");

    printf("Set TCAM field group %d mode to Install\n", cint_field_tcam_entry_cache_fg_id);

    /**
     * Set TCAM field group cache mode to Start.
     * After setting cache mode to Install, Start need to be invoked again.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeStart), "");

    printf("Set TCAM field group %d mode to Start\n", cint_field_tcam_entry_cache_fg_id);

    /**
     * Add 1 entry to TCAM field group cache.
     */
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.nof_entry_actions = fg_info.nof_actions;

    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = cint_field_tcam_entry_cache_ttl_hit;
    entry_info.entry_qual[0].mask[0] = 0xff;

    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = cint_field_tcam_entry_cache_tc_hit;

    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_field_tcam_entry_cache_fg_id, &entry_info, &cint_field_tcam_entry_cache_entry_ids[ii]), "");

    printf("Entry 0x%X (%d) was added to field group %d cache. \n", cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_fg_id);

    /**
     * Set TCAM field group cache mode to Install again.
     * All TCAM entries that were saved in cache are now committed to HW.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_cache(unit, 0, cint_field_tcam_entry_cache_fg_id, bcmFieldGroupCacheModeInstall), "");

    printf("Set TCAM field group %d mode to Install\n", cint_field_tcam_entry_cache_fg_id);

    return BCM_E_NONE;
}

/**
 * \brief
 *  This function destroys all allocated data by the configuration
 *
 * \param [in] unit            - Device id
 * \param [in] ctx_id          - Context ID
 * \return
 *   shr_error_e - Type of Error
 * \remark
 *   * None
 * \see
 *   * None
 */
int cint_field_tcam_entry_cache_destroy(
        int unit,
        int ctx_id)
{
    int ii;
    for (ii = 0; ii < nof_entries; ii++)
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, cint_field_tcam_entry_cache_fg_id, NULL, cint_field_tcam_entry_cache_entry_ids[ii]), "");
        printf("Entry 0x%X (%d) was deleted. \n", cint_field_tcam_entry_cache_entry_ids[ii], cint_field_tcam_entry_cache_entry_ids[ii]);
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, cint_field_tcam_entry_cache_fg_id, ctx_id), "");

    printf("Field Group %d was detach from context %d. \n", cint_field_tcam_entry_cache_fg_id, ctx_id);

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, cint_field_tcam_entry_cache_fg_id), "");

    printf("Field Group %d was deleted. \n", cint_field_tcam_entry_cache_fg_id);

    return BCM_E_NONE;
}
