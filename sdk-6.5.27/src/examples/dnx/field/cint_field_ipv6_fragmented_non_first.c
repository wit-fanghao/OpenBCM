/*
 * This cint shows how to qualify on IPv6 fragmented non first in IPv6 LR Qualifier.
 *
 * Configuration example start:
 *
 * Test Scenario - start
  cint ../../../../src/examples/dnx/field/cint_field_ipv6_fragmented_non_first.c
  cint;
  int unit = 0;
  bcm_field_context_t context_id = 0;
  bcm_field_stage_t field_stage = bcmFieldStageIngressPMF1;
  int input_arg = 1;
  uint32 non_first_fragmented = 1;
  cint_field_ipv6_fragmented_non_first_main(unit, field_stage, context_id, input_arg, non_first_fragmented);
 * Test Scenario - end
 *
 * Configuration example end
 *
 */

int Cint_field_ipv6_fragmented_non_first_tc_action_val = 4;

bcm_field_group_t Cint_field_ipv6_fragmented_non_first_fg_id = 0;
bcm_field_entry_t Cint_field_ipv6_fragmented_non_first_entry_handle;

/**
 * \brief
 *  This function creates a TCAM field group,
 *  attaching it to a context and adding an entry.
 *
 * \param [in] unit   - Device id
 * \param [in] field_stage  - Field stage
 * \param [in] context_id  -Context of the field stage
 * \param [in] input_arg  - Attach info input argument, indicates
 *  where the IPv6 header resides in the packet.
 * \param [in] non_first_fragmented  - 0 or 1, depends on the test scenario.
 *  Indicates the qualifier value.
 *      - 0 indicates that an IPv6 Layer were the IPv6 Header is EITHER:
 *          - NOT Fragmented (i.e. there is no fragment extension)
 *          - Fragmented and this IS the 1st Fragment
 *      - 1 indicates that an IPv6 Layer were the IPv6 Header is
 *        fragmented and this IS NOT 1st Fragment.
 *
 * \return
 *   int - Error Type
 * \remark
 *   * None
 * \see
 *   * None
 */
int
cint_field_ipv6_fragmented_non_first_main(
    int unit,
    bcm_field_stage_t field_stage,
    bcm_field_context_t context_id,
    int input_arg,
    uint32 non_first_fragmented)
{
    bcm_field_group_info_t fg_info;
    bcm_field_group_attach_info_t attach_info;
    bcm_field_entry_info_t entry_info;

    bcm_field_group_info_t_init(&fg_info);
    fg_info.fg_type = bcmFieldGroupTypeTcam;
    fg_info.stage = field_stage;
    fg_info.nof_quals = 1;
    fg_info.qual_types[0] = bcmFieldQualifyIPv6FragmentedNonFirst;
    fg_info.nof_actions = 1;
    fg_info.action_types[0] = bcmFieldActionPrioIntNew;

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_add(unit, 0, &fg_info, &Cint_field_ipv6_fragmented_non_first_fg_id), "");
    printf("Field Group ID %d was created. \n", Cint_field_ipv6_fragmented_non_first_fg_id);

    bcm_field_group_attach_info_t_init(&attach_info);

    attach_info.key_info.nof_quals = fg_info.nof_quals;
    attach_info.payload_info.nof_actions = fg_info.nof_actions;
    attach_info.key_info.qual_types[0] = fg_info.qual_types[0];
    attach_info.payload_info.action_types[0] = fg_info.action_types[0];

    attach_info.key_info.qual_info[0].input_type = bcmFieldInputTypeLayerRecordsAbsolute;
    attach_info.key_info.qual_info[0].input_arg = input_arg;
    attach_info.key_info.qual_info[0].offset = 0;

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_attach(unit, 0, Cint_field_ipv6_fragmented_non_first_fg_id, context_id, &attach_info), "");
    printf("Field Group ID %d was attached to Context ID %d. \n", Cint_field_ipv6_fragmented_non_first_fg_id, context_id);

    bcm_field_entry_info_t_init(&entry_info);
    entry_info.nof_entry_quals = fg_info.nof_quals;
    entry_info.entry_qual[0].type = fg_info.qual_types[0];
    entry_info.entry_qual[0].value[0] = non_first_fragmented;
    entry_info.entry_qual[0].mask[0] = 0x1;
    entry_info.nof_entry_actions = fg_info.nof_actions;
    entry_info.entry_action[0].type = fg_info.action_types[0];
    entry_info.entry_action[0].value[0] = Cint_field_ipv6_fragmented_non_first_tc_action_val;

    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_add(unit, 0, Cint_field_ipv6_fragmented_non_first_fg_id, &entry_info, &Cint_field_ipv6_fragmented_non_first_entry_handle), "");
    printf("Entry ID 0x%X (%d) was added to Field Group ID %d. \n", Cint_field_ipv6_fragmented_non_first_entry_handle,
            Cint_field_ipv6_fragmented_non_first_entry_handle, Cint_field_ipv6_fragmented_non_first_fg_id);

    return BCM_E_NONE;
}

/**
 * \brief
 *  Destroys all allocated data by the configuration.
 *
 * \param [in] unit         - Device id
 * \param [in] context_id   - Context
 *
 * \return
 *   int - Error Type
 * \remark
 *   * None
 * \see
 *   * None
 */
int
cint_field_ipv6_fragmented_non_first_destroy(
    int unit,
    bcm_field_context_t context_id)
{
    BCM_IF_ERROR_RETURN_MSG(bcm_field_entry_delete(unit, Cint_field_ipv6_fragmented_non_first_fg_id, NULL, Cint_field_ipv6_fragmented_non_first_entry_handle), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_context_detach(unit, Cint_field_ipv6_fragmented_non_first_fg_id, context_id), "");

    BCM_IF_ERROR_RETURN_MSG(bcm_field_group_delete(unit, Cint_field_ipv6_fragmented_non_first_fg_id), "");

    return BCM_E_NONE;
}
