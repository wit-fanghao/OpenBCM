 /*
 * Configuration example start:
 *
 * Test Scenario - start
 * cint;
 * cint_reset();
 * exit;
  cint ../../../../src/examples/dnx/field/cint_field_cascading_320b.c
  cint
  int unit = 0;
  bcm_field_context_t context_id = BCM_FIELD_CONTEXT_ID_DEFAULT;
  cint_field_cascading_320b_main(unit, context_id);
 * Test Scenario - end
 *
 * Configuration example end
 *
 */

bcm_field_group_t   cint_field_cascading_320b_ipmf1_fg_id = BCM_FIELD_ID_INVALID;
bcm_field_group_t   cint_field_cascading_320b_ipmf2_fg_id = BCM_FIELD_ID_INVALID;
bcm_field_qualify_t cint_field_cascading_320b_cas_qual1 = BCM_FIELD_ID_INVALID;
bcm_field_qualify_t cint_field_cascading_320b_cas_qual2 = BCM_FIELD_ID_INVALID;
bcm_field_context_t cint_field_cascading_320b_context_id = BCM_FIELD_ID_INVALID;
bcm_field_entry_t   cint_field_cascading_320b_entry_id1 = BCM_FIELD_ID_INVALID;
bcm_field_entry_t   cint_field_cascading_320b_entry_id2 = BCM_FIELD_ID_INVALID;

int cint_field_cascading_320b_fg_create(int unit, bcm_field_group_t *fg_id)
{
    bcm_field_group_info_t fg_info;

    bcm_field_group_info_t_init(&fg_info);

    fg_info.stage = bcmFieldStageIngressPMF1;
    fg_info.fg_type  = bcmFieldGroupTypeTcam;

    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyIp4Ttl;

    fg_info.nof_actions = 3;
    fg_info.action_types[0] = bcmFieldActionDropPrecedence;
    fg_info.action_types[1] = bcmFieldActionUDHData0;
    fg_info.action_types[2] = bcmFieldActionUDHData1;

    return bcm_field_group_add(unit, 0, &fg_info, fg_id);
}

int cint_field_cascading_320b_fg_attach(int unit, bcm_field_group_t fg_id, bcm_field_context_t context_id)
{
    bcm_field_group_attach_info_t attach_info;

    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = 1;
    attach_info.key_info.qual_types[0] = bcmFieldQualifyIp4Ttl;
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeLayerFwd;
    attach_info.key_info.qual_info[0].input_arg = 1;
    attach_info.key_info.qual_info[0].offset = 0;

    attach_info.payload_info.nof_actions = 3;
    attach_info.payload_info.action_types[0] = bcmFieldActionDropPrecedence;
    attach_info.payload_info.action_types[1] = bcmFieldActionUDHData0;
    attach_info.payload_info.action_types[2] = bcmFieldActionUDHData1;

    return bcm_field_group_context_attach(unit, 0, fg_id, context_id, &attach_info);
}

int cint_field_cascading_320b_ipmf2_fg_create(int unit, bcm_field_group_t *fg_id)
{
    bcm_field_group_info_t fg_info;
    bcm_field_qualifier_info_create_t qual_info1;
    bcm_field_qualifier_info_create_t qual_info2;
    void *dst;

    bcm_field_group_info_t_init(&fg_info);
    fg_info.stage = bcmFieldStageIngressPMF2;
    fg_info.fg_type  = bcmFieldGroupTypeTcam;

    qual_info1.size = 32;
    dst = &(qual_info1.name[0]);
    sal_strncpy_s(dst, "cascad1", 8);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_create(unit, 0, &qual_info1, &cint_field_cascading_320b_cas_qual1), "");


    qual_info2.size = 2;
    dst = &(qual_info2.name[0]);
    sal_strncpy_s(dst, "cascad2", 8);
    BCM_IF_ERROR_RETURN_MSG(bcm_field_qualifier_create(unit, 0, &qual_info2, &cint_field_cascading_320b_cas_qual2), "");

    fg_info.nof_quals = 2;
    fg_info.qual_types[0] = cint_field_cascading_320b_cas_qual1;
    fg_info.qual_types[1] = cint_field_cascading_320b_cas_qual2;

    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionTtlSet;

    return bcm_field_group_add(unit, 0, &fg_info, fg_id);
}

int cint_field_cascading_320b_ipmf2_failing_attach(int unit, bcm_field_group_t fg_id, bcm_field_context_t context_id)
{
    int rv = BCM_E_NONE;
    bcm_field_group_attach_info_t attach_info;
    int action_offset;

    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = 2;
    attach_info.key_info.qual_types[0] = cint_field_cascading_320b_cas_qual1;
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeCascaded;
    attach_info.key_info.qual_info[0].input_arg = cint_field_cascading_320b_ipmf1_fg_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_action_offset_get(unit, 0, cint_field_cascading_320b_ipmf1_fg_id, bcmFieldActionUDHData0, &action_offset), "");

    attach_info.key_info.qual_info[0].offset = action_offset;

    attach_info.key_info.qual_types[1] = cint_field_cascading_320b_cas_qual2;
    attach_info.key_info.qual_info[1].input_type = bcmFieldInputTypeCascaded;
    attach_info.key_info.qual_info[1].input_arg = cint_field_cascading_320b_ipmf1_fg_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_action_offset_get(unit, 0, cint_field_cascading_320b_ipmf1_fg_id, bcmFieldActionDropPrecedence, &action_offset), "");

    attach_info.key_info.qual_info[1].offset = action_offset;

    attach_info.payload_info.nof_actions = 1;
    attach_info.payload_info.action_types[0] = bcmFieldActionTtlSet;

    /* This should fail, UDH0Data action is split between the two keys payload */
    bshell(unit, "debug bcmdnx fldprocdnx off");
    rv =bcm_field_group_context_attach(unit, 0, fg_id, context_id, &attach_info);
    bshell(unit, "debug bcmdnx fldprocdnx warn");
    if (rv != BCM_E_PARAM)
    {
        printf("iPMF2 cascading FG from iPMF1 double-key sized FG should fail when trying\n
               to attach it while cascading from an action that is split between the two keys payload\n
               Expected E_PARAM, received: %d\n", rv);
        return BCM_E_FAIL;
    }

    return BCM_E_NONE;
}

int cint_field_cascading_320b_ipmf2_attach(int unit, bcm_field_group_t fg_id, bcm_field_context_t context_id)
{
    bcm_field_group_attach_info_t attach_info;
    int action_offset;

    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = 2;
    attach_info.key_info.qual_types[0] = cint_field_cascading_320b_cas_qual1;
    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeCascaded;
    attach_info.key_info.qual_info[0].input_arg = cint_field_cascading_320b_ipmf1_fg_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_action_offset_get(unit, 0, cint_field_cascading_320b_ipmf1_fg_id, bcmFieldActionUDHData1, &action_offset), "");

    attach_info.key_info.qual_info[0].offset = action_offset;

    attach_info.key_info.qual_types[1] = cint_field_cascading_320b_cas_qual2;
    attach_info.key_info.qual_info[1].input_type = bcmFieldInputTypeCascaded;
    attach_info.key_info.qual_info[1].input_arg = cint_field_cascading_320b_ipmf1_fg_id;
    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_action_offset_get(unit, 0, cint_field_cascading_320b_ipmf1_fg_id, bcmFieldActionDropPrecedence, &action_offset), "");

    attach_info.key_info.qual_info[1].offset = action_offset;

    attach_info.payload_info.nof_actions = 1;
    attach_info.payload_info.action_types[0] = bcmFieldActionTtlSet;

    /* This should succeed, DP/UDH1Data are not split (each is on different key payload */
    return bcm_field_group_context_attach(unit, 0, fg_id, context_id, &attach_info);
}

int cint_field_cascading_320b_ipmf1_entry_add(int unit, bcm_field_group_t fg_id, bcm_field_entry_t *entry_id)
{
    bcm_field_entry_info_t entry_info;

    bcm_field_entry_info_t_init(&entry_info);

    entry_info.nof_entry_quals = 1;
    entry_info.entry_qual[0].type = bcmFieldQualifyIp4Ttl;
    entry_info.entry_qual[0].value[0] = 0x5;
    entry_info.entry_qual[0].mask[0] = 0xff;

    entry_info.nof_entry_actions = 2;
    entry_info.entry_action[0].type = bcmFieldActionDropPrecedence;
    entry_info.entry_action[0].value[0] = 0x2;

    entry_info.entry_action[1].type = bcmFieldActionUDHData1;
    entry_info.entry_action[1].value[0] = 0x1234;

    return bcm_field_entry_add(unit, 0, fg_id, &entry_info ,entry_id);
}

int cint_field_cascading_320b_ipmf2_entry_add(int unit, bcm_field_group_t fg_id, bcm_field_entry_t *entry_id)
{
    bcm_field_entry_info_t entry_info;

    bcm_field_entry_info_t_init(&entry_info);

    entry_info.nof_entry_quals = 2;
    entry_info.entry_qual[0].type = cint_field_cascading_320b_cas_qual1;
    entry_info.entry_qual[0].value[0] = 0x1234;
    entry_info.entry_qual[0].mask[0] = 0xffff;

    entry_info.entry_qual[1].type = cint_field_cascading_320b_cas_qual2;
    entry_info.entry_qual[1].value[0] = 0x1;
    entry_info.entry_qual[1].mask[0] = 0x3;

    entry_info.nof_entry_actions = 1;
    entry_info.entry_action[0].type = bcmFieldActionTtlSet;
    entry_info.entry_action[0].value[0] = 0x10;

    return bcm_field_entry_add(unit, 0, fg_id, &entry_info ,entry_id);
}

int cint_field_cascading_320b_main(int unit, bcm_field_context_t context_id)
{

    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_fg_create(unit, &cint_field_cascading_320b_ipmf1_fg_id), "");

    /* It's a better practice to add entries, first then attach the FG */
    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_ipmf1_entry_add(unit, cint_field_cascading_320b_ipmf1_fg_id, &cint_field_cascading_320b_entry_id1), "");

    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_fg_attach(unit, cint_field_cascading_320b_ipmf1_fg_id, context_id), "");

    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_ipmf2_fg_create(unit, &cint_field_cascading_320b_ipmf2_fg_id), "");
    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_ipmf2_entry_add(unit, cint_field_cascading_320b_ipmf2_fg_id, &cint_field_cascading_320b_entry_id2), "");


    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_ipmf2_failing_attach(unit, cint_field_cascading_320b_ipmf2_fg_id, context_id), "");

    BCM_IF_ERROR_RETURN_MSG(cint_field_cascading_320b_ipmf2_attach(unit, cint_field_cascading_320b_ipmf2_fg_id, context_id), "");


    return BCM_E_NONE;
}

int cint_field_cascading_320b_destroy(int unit, bcm_field_context_t context_id)
{
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, cint_field_cascading_320b_ipmf1_fg_id, NULL, cint_field_cascading_320b_entry_id1), "");
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, cint_field_cascading_320b_ipmf2_fg_id, NULL, cint_field_cascading_320b_entry_id2), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, cint_field_cascading_320b_ipmf2_fg_id, context_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, cint_field_cascading_320b_ipmf1_fg_id, context_id), "");


    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, cint_field_cascading_320b_ipmf2_fg_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, cint_field_cascading_320b_ipmf1_fg_id), "");


    return BCM_E_NONE;
}
