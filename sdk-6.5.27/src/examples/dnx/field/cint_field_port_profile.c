/*
 * Configuration example start:
 *  
 * Test Scenario - start
  cint ../../../../src/examples/dnx/field/cint_field_port_profile.c
  cint;
  int unit = 0;
  bcm_field_context_t context_id = 0;
  int in_port = 200;
  int pp_or_tm = 1;
  int bitmap_or_single = 1;
  uint32 profile_id = 7;
  field_port_profile_main(unit, context_id, in_port, pp_or_tm, bitmap_or_single, profile_id);
 * Test Scenario - end
 *
 * Configuration example end
 *
 *   This cint shows an example of using port profile by PP port and TM port.
 *   We provide two methods of interpreting the profile_id. In one,  we show an examples of using a bitmap of profiles, 
 *   while in the other we show an example of using a single profile per port.
 *   
 */


/** Values saved for delete.*/
bcm_field_group_t Port_profile_fg_id;
bcm_field_qualify_t Port_profile_bitmap_profile_qual = bcmFieldQualifyCount;
bcm_field_entry_t Port_profile_entry_handle;
bcm_field_entry_t Port_profile_entry_handle_default;
uint32 Port_profile_old_value;



/**
* \brief
*  Configure a port profile and a field group to qualify on it.
*  This function uses the port profile as bitmap, and so profile_id is the bit we set
* \param [in] unit            - Device ID.
* \param [in] stage           - The field stage.
* \param [in] context_id      - Context to attach the FG to.
* \param [in] gport           - The port whose profile we change.
* \param [in] port_class      - The profile type we want to change.
* \param [in] pp_or_tm        - If true configure PP port profiles, otherwise TM port profiles.
* \param [in] profile_id_bit  - The bit on the bitmap to change (the profile ID).
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_port_profile_bitmap_configure(
    int unit,
    bcm_field_stage_t stage,
    bcm_field_context_t context_id,
    bcm_port_t gport,
    bcm_port_class_t port_class,
    int pp_or_tm,
    uint32 profile_id_bit)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_qualifier_info_create_t qual_info;
    bcm_field_entry_info_t entry_info;
    bcm_field_qualifier_info_get_t qual_info_get;
    bcm_field_qualify_t predefined_qual;
    void * dest_char;
    uint32 profile_total_value;
    int qual_offset;


    /* Create a qualifier to read the specific bit we set.*/
    bcm_field_qualifier_info_create_t_init(&qual_info);
    qual_info.size = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_create(unit, 0, &qual_info, &Port_profile_bitmap_profile_qual), "");


    /* Find the qualifier's offset.*/
    bcm_field_qualifier_info_get_t_init(&qual_info_get);
    predefined_qual = (pp_or_tm)?(bcmFieldQualifyPortClassPacketProcessing):(bcmFieldQualifyPortClassTrafficManagement);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_info_get(unit, predefined_qual, stage, &qual_info_get), "");

    qual_offset = qual_info_get.offset;

    /* Set the port profile in the wanted bit.*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_get(unit, gport, port_class, &profile_total_value), "");

    profile_total_value |= (1 << profile_id_bit);
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, gport, port_class, profile_total_value), "");


    /* Configure the field group.*/
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.nof_quals = 1;
    fg_info.stage = stage;
    fg_info.qual_types[0] = Port_profile_bitmap_profile_qual;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionPrioIntNew;
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "port_profile", sizeof(fg_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &Port_profile_fg_id), "");


    bcm_field_group_attach_info_t_init(&attach_info);
    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[0].offset = qual_offset + profile_id_bit;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, Port_profile_fg_id, context_id, &attach_info), "");

    
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = 1;
    entry_info.entry_qual[0].mask[0] = 1;
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = 2;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, Port_profile_fg_id, &entry_info, &Port_profile_entry_handle), "");


    /* Create a default entry for the case of an error.*/
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = 0;
    entry_info.entry_qual[0].mask[0] = 0;
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, Port_profile_fg_id, &entry_info, &Port_profile_entry_handle_default), "");


    return BCM_E_NONE;
    
}

/**
* \brief
*  Configure a port profile and a field group to qualify on it.
*  This function uses the port profile as a numerical value, where only one such value can be assigned to a port.
* \param [in] unit            - Device ID.
* \param [in] stage           - The field stage.
* \param [in] context_id      - Context to attach the FG to.
* \param [in] gport           - The port whose profile we change.
* \param [in] port_class      - The profile type we want to change.
* \param [in] pp_or_tm        - If true configure PP port profiles, otherwise TM port profiles.
* \param [in] profile_id_num  - The number (profile ID) to assign to port.
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_port_profile_single_configure(
    int unit,
    bcm_field_stage_t stage,
    bcm_field_context_t context_id,
    bcm_port_t gport,
    bcm_port_class_t port_class,
    int pp_or_tm,
    uint32 profile_id_num)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_qualifier_info_create_t qual_info;
    bcm_field_entry_info_t entry_info;
    void * dest_char;

    /* Set the port profile.*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, gport, port_class, profile_id_num), "");


    /* Configure the field group.*/
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.nof_quals = 1;
    fg_info.stage = stage;
    fg_info.qual_types[0] = (pp_or_tm)?(bcmFieldQualifyPortClassPacketProcessing):(bcmFieldQualifyPortClassTrafficManagement);
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionPrioIntNew;
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "port_profile", sizeof(fg_info.name));
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &Port_profile_fg_id), "");


    bcm_field_group_attach_info_t_init(&attach_info);
    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, Port_profile_fg_id, context_id, &attach_info), "");

    
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = profile_id_num;
    entry_info.entry_qual[0].mask[0] = 0xffffff;
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = 2;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, Port_profile_fg_id, &entry_info, &Port_profile_entry_handle), "");


    /* Create a default entry for the case of an error.*/
    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = 0;
    entry_info.entry_qual[0].mask[0] = 0;
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = 1;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, Port_profile_fg_id, &entry_info, &Port_profile_entry_handle_default), "");


    return BCM_E_NONE;
    
}

/**
* \brief
*  Configures and uses a port profile
* \param [in] unit             - Device ID
* \param [in] context_id       - Context to attach the FG to.
* \param [in] in_port          - The port whose profile we change.
* \param [in] pp_or_tm         - If true configure PP port profiles, otherwise TM port profiles.
* \param [in] bitmap_or_single - If true configures profile id as bitmap, otherwise as one profile per port.
* \param [in] profile_id       - The profile ID to set.
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_port_profile_main(
    int unit,
    bcm_field_context_t context_id, 
    int in_port,
    int pp_or_tm,
    int bitmap_or_single,
    uint32 profile_id)
{
    bcm_gport_t gport_in;
    bcm_port_class_t port_class;


    /* Make a Gport out of the in_port.*/
    BCM_GPORT_LOCAL_SET(gport_in, in_port);
    
    port_class = (pp_or_tm) ? (bcmPortClassFieldIngressPMF1PacketProcessingPort) : (bcmPortClassFieldIngressPMF1TrafficManagementPort);

    /* Get the old port_profile value to be resumed after delete.*/
    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_get(unit, gport_in, port_class, &Port_profile_old_value), "");


    /* Perform configurations.*/
    if (bitmap_or_single)
    {
        BCM_IF_ERROR_RETURN_MSG(field_port_profile_bitmap_configure(unit, bcmFieldStageIngressPMF1, context_id, gport_in, port_class, pp_or_tm, profile_id), "");

    }
    else
    {
        BCM_IF_ERROR_RETURN_MSG(field_port_profile_single_configure(unit, bcmFieldStageIngressPMF1, context_id, gport_in, port_class, pp_or_tm, profile_id), "");

    }
    
    return BCM_E_NONE;
    
}

/**
* \brief
*  Delete the configurations.
* \param [in] unit        - Device ID
* \param [in] context_id  - Context to detach the field group from.
* \param [in] in_port     - The port whose profile we changed.
* \param [in] pp_or_tm    - If true configure PP port profiles, otherwise TM port profiles.
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_port_profile_destroy(
    int unit,
    bcm_field_context_t context_id,
    int in_port,
    int pp_or_tm)
{
    bcm_gport_t gport_in;
    bcm_port_class_t port_class;
    bcm_field_entry_qual_t entry_qual_info[BCM_FIELD_NUMBER_OF_QUALS_PER_GROUP];


    /* Make a Gport out of the in_port.*/
    BCM_GPORT_LOCAL_SET(gport_in, in_port);
    
    port_class = (pp_or_tm) ? (bcmPortClassFieldIngressPMF1PacketProcessingPort) : (bcmPortClassFieldIngressPMF1TrafficManagementPort);

    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, Port_profile_fg_id, &entry_qual_info, Port_profile_entry_handle), "");


    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, Port_profile_fg_id, &entry_qual_info, Port_profile_entry_handle_default), "");


    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, Port_profile_fg_id, context_id), "");


    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, Port_profile_fg_id), "");


    if (Port_profile_bitmap_profile_qual != bcmFieldQualifyCount)
    {
        BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_destroy(unit, Port_profile_bitmap_profile_qual), "");

        Port_profile_bitmap_profile_qual = bcmFieldQualifyCount;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_port_class_set(unit, gport_in, port_class, Port_profile_old_value), "");


    return BCM_E_NONE;
}
