 /*
 * Configuration example start:
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/field/cint_field_mirror.c
  cint;
  int unit = 0;
  bcm_field_context_t context_id = 0;
  int mirror_code = 0xab;
  int mirror_qualifier = 0x12;
  cint_field_mirror_main(unit, context_id, mirror_code, mirror_qualifier);
 * Test Scenario - end
 *
 * Configuration example end
 *
 * example of using inPort qualifier which is encoded as GPORT.
 */

bcm_field_group_t   cint_mirror_fg_id = 0;
bcm_gport_t mirror_gport;
bcm_field_entry_t cint_mirror_ent_id;


/**
* \brief
*  Configures the written above
* \param [in] unit        -  Device id
* \param [in] context_id  -  PMF context Id
* \param [in] mirror_code       -  mirror command (9 bits)
* \param [in] mirror_qualifier  -  mirror qualifier (8 bits)
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int cint_field_mirror_main(int unit, bcm_field_context_t context_id, int mirror_code, int mirror_qualifier)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_context_info_t context_info;
    bcm_field_entry_info_t ent_info;
    bcm_field_action_info_t action_info;


    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = bcmFieldStageIngressPMF1;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyTpid;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionMirrorIngress;

    printf("Creating first group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &cint_mirror_fg_id), "");



    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeLayerAbsolute;
    attach_info.key_info.qual_info[0].input_arg = 0;
    attach_info.key_info.qual_info[0].offset = 96;

    printf("Attaching field group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, cint_mirror_fg_id, context_id, &attach_info), "");

    bcm_field_entry_info_t_init(&ent_info);
    ent_info.priority = 1;
    BCM_GPORT_MIRROR_SET(mirror_gport, mirror_code);
    ent_info.nof_entry_quals = fg_info.nof_quals;
    ent_info.entry_qual[0].type = fg_info.qual_types[0];
    ent_info.entry_qual[0].value[0] = 0x8100;
    ent_info.entry_qual[0].mask[0] = 0xffff;

    ent_info.nof_entry_actions = fg_info.nof_actions;
    ent_info.entry_action[0].type = fg_info.action_types[0];
    ent_info.entry_action[0].value[0] = mirror_gport;
    ent_info.entry_action[0].value[1] = mirror_qualifier;

    printf("Adding Entry\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_mirror_fg_id, &ent_info, &cint_mirror_ent_id), "");
    
    return BCM_E_NONE;
}


int cint_field_mirror_by_inport(int unit, bcm_field_context_t context_id, bcm_field_stage_t stage, int mirror_code, int mirror_qualifier, int port)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_context_info_t context_info;
    bcm_field_entry_info_t ent_info;
    bcm_field_action_info_t action_info;
    bcm_gport_t port_gport;


    /*
     * Create and attach TCAM group in iPMF
     */
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = stage;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyInPort;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionMirrorIngress;
    if (stage == bcmFieldStageEgress)
    {
        fg_info.qual_types[0] = bcmFieldQualifySrcPort;
        fg_info.action_types[0] = bcmFieldActionMirrorEgress;
    }

    printf("Creating first group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &cint_mirror_fg_id), "");



    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[0].input_arg = 0;
    attach_info.key_info.qual_info[0].offset = 0;

    printf("Attaching field group\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, cint_mirror_fg_id, context_id, &attach_info), "");

    BCM_GPORT_LOCAL_SET(port_gport, port);
    if (stage == bcmFieldStageEgress)
    {
        BCM_GPORT_SYSTEM_PORT_ID_SET(port_gport, port);
    }

    bcm_field_entry_info_t_init(&ent_info);
    ent_info.priority = 1;
    BCM_GPORT_MIRROR_SET(mirror_gport, mirror_code);
    ent_info.nof_entry_quals = fg_info.nof_quals;
    ent_info.entry_qual[0].type = fg_info.qual_types[0];
    ent_info.entry_qual[0].value[0] = port_gport;
    ent_info.entry_qual[0].mask[0] = 0xffff;

    ent_info.nof_entry_actions = fg_info.nof_actions;
    ent_info.entry_action[0].type = fg_info.action_types[0];
    ent_info.entry_action[0].value[0] = mirror_gport;
    ent_info.entry_action[0].value[1] = mirror_qualifier;

    printf("Adding Entry\n");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, cint_mirror_fg_id, &ent_info, &cint_mirror_ent_id), "");
    
    return BCM_E_NONE;
}

/**
* \brief
*  Destroy all configuration done
* \param [in] unit        -  Device id
* \param [in] context_id  -  PMF context Id
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int cint_field_mirror_destroy(int unit, bcm_field_context_t context_id)
{

    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, cint_mirror_fg_id, NULL, cint_mirror_ent_id), "");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, cint_mirror_fg_id, context_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, cint_mirror_fg_id), "");

    return BCM_E_NONE;
}
