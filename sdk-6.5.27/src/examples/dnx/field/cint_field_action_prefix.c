 /*
 * Configuration example start:
 *
 * Test Scenario - start
 * cint;                                                                  
 * cint_reset();                                                          
 * exit; 
  cint ../../../../src/examples/dnx/field/cint_field_action_prefix.c
  cint;
  int unit = 0;
  bcm_field_context_t context_id_ipmf1 = BCM_FIELD_CONTEXT_ID_DEFAULT;
  field_action_prefix_main(unit, context_id_ipmf1);
 * Test Scenario - end
 *
 * Configuration example end
 *
 *   This cint creates actions with prefixes and the field groups to use them.
 *
 */


/* 
 * Variables to store object IDs for deletion.
 */
bcm_field_action_t action_prefix_stat_action;
bcm_field_action_t action_prefix_udh2_action;

bcm_field_qualify_t action_prefix_qual_lrn_data_dst_port;
bcm_field_group_t action_prefix_de_fg_id;


/**
* \brief
*  Create DE in iPMF2 so that Meter ID[19:0] = <0xA, learn_data_dst_port[4:0], TTL[7:0], TC[2:0]>, using action prefix
* \param [in] unit              - Device ID
* \param [in] context_id_ipmf1  - Context to attach FG to in iPMF2
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_action_prefix_main(
    int unit, 
    bcm_field_context_t context_id_ipmf1)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_info_t fg_info_get;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_group_attach_info_t attach_info_get;
    bcm_field_qualifier_info_create_t qual_info;
    bcm_field_action_info_t action_info;
    void *dest_char;
    int ii = 0;

    bcm_field_action_info_t_init(&action_info);
    action_info.action_type = bcmFieldActionStatId0;
    action_info.prefix_size = 4;
    action_info.prefix_value = 0xA;
    action_info.size = 16;
    action_info.stage = bcmFieldStageIngressPMF2;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_action_create(unit, 0, &action_info, &action_prefix_stat_action), "");

    bcm_field_action_info_t_init(&action_info);
    action_info.action_type = bcmFieldActionUDHData2;
    action_info.prefix_size = 31;
    action_info.prefix_value = 0x2;
    action_info.size = 1;
    action_info.stage = bcmFieldStageIngressPMF2;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_action_create(unit, 0, &action_info, &action_prefix_udh2_action), "");

    bcm_field_qualifier_info_create_t_init(&qual_info);
    qual_info.size = 6;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_create(unit, 0, &qual_info, &action_prefix_qual_lrn_data_dst_port), "");


    
    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeDirectExtraction;
    fg_info.nof_quals = 3;
    fg_info.stage = bcmFieldStageIngressPMF2;


    fg_info.qual_types[0] = bcmFieldQualifyIntPriority;
    fg_info.qual_types[1] = bcmFieldQualifyGeneratedTtl;
    fg_info.qual_types[2] = action_prefix_qual_lrn_data_dst_port;
    

    fg_info.nof_actions = 2;

    /** Order of actions should be the same as order of qualifiers*/
    fg_info.action_types[0] = action_prefix_stat_action;
    fg_info.action_with_valid_bit[0] = FALSE;
    fg_info.action_types[1] = action_prefix_udh2_action;
    fg_info.action_with_valid_bit[1] = FALSE;
    dest_char = &(fg_info.name[0]);
    sal_strncpy_s(dest_char, "basic_prefix", sizeof(fg_info.name));

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &action_prefix_de_fg_id), "");


    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    for(ii=0; ii< fg_info.nof_quals; ii++)
    {
        attach_info.key_info.qual_types[ii] = fg_info.qual_types[ii];
    }
    for(ii=0; ii<fg_info.nof_actions; ii++)
    {
        attach_info.payload_info.action_types[ii] = fg_info.action_types[ii];
    }

    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[1].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[2].input_type = bcmFieldInputTypeMetaData;
    attach_info.key_info.qual_info[2].input_arg = 0;
    attach_info.key_info.qual_info[2].offset = (2556 + 9);


    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, action_prefix_de_fg_id, context_id_ipmf1, &attach_info), "");
    
    printf("Action prefix DE FG_ID(%d) was attached to context (%d) \n", action_prefix_de_fg_id, context_id_ipmf1);

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_info_get(unit, action_prefix_de_fg_id, &fg_info_get), "");
    if (sal_memcmp(&fg_info, &fg_info_get, sizeof(fg_info_get)))
    {
        printf("bcm_field_group_info_get did not return expected value.\n");
        return BCM_E_FAIL;
    }

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_info_get(unit, action_prefix_de_fg_id, context_id_ipmf1, &attach_info_get), "");
    if (sal_memcmp(&attach_info, &attach_info_get, sizeof(attach_info_get)))
    {
        printf("bcm_field_group_context_info_get did not return expected value.\n");
        return BCM_E_INTERNAL;
    }

    return BCM_E_NONE;
    
}


/**
* \brief
*  Delete the field group and created actions
* \param [in] unit        - Device ID
* \param [in] context_id_ipmf1  - Context to detach FG from in iPMF2
* \return
*   int - Error Type
* \remark
*   * None
* \see
*   * None
*/
int field_action_prefix_destroy(
    int unit, 
    bcm_field_context_t context_id_ipmf1)
{

    /*
     * Delete iPMF2 DE configuration.
     */
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, action_prefix_de_fg_id, context_id_ipmf1), "");
    printf("Action prefix detach DE FG_ID(%d) from context (%d) \n", action_prefix_de_fg_id, context_id_ipmf1);
    
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, action_prefix_de_fg_id), "");
    printf("Action prefix delete DE FG_ID(%d) \n", action_prefix_de_fg_id);

    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_destroy(unit, action_prefix_qual_lrn_data_dst_port), "");
    
    BCM_IF_ERROR_RETURN_MSG(bcm_field_action_destroy(unit, action_prefix_stat_action), "");
    
    return BCM_E_NONE;
}
