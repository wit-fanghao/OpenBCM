/*
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * File:        dnx_field_dispatch.h
 * Purpose:     dnx field driver BCM API dispatch table
 * Generator:   modules_dispatch.py
 */

#ifndef _BCM_INT_DNX_FIELD_DISPATCH_H
#define _BCM_INT_DNX_FIELD_DISPATCH_H

#include <bcm/types.h>
#include <bcm_int/dispatch.h>

#ifdef BCM_DNX_SUPPORT

extern int bcm_dnx_field_fem_action_delete(int,bcm_field_group_t,bcm_field_action_priority_t);
extern int bcm_dnx_field_entry_state_table_add(int,uint32,bcm_field_entry_state_table_info_t *);
extern int bcm_dnx_field_flush_entry_add(int,uint32,bcm_field_group_t,int,bcm_field_flush_entry_info_t *);
extern int bcm_dnx_field_qualifier_value_map(int,bcm_field_stage_t,bcm_field_qualify_t,uint32 [BCM_FIELD_QUAL_WIDTH_IN_WORDS],uint32 [BCM_FIELD_QUAL_WIDTH_IN_WORDS]);
extern int bcm_dnx_field_context_hash_info_get(int,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_hash_info_t *);
extern int bcm_dnx_field_tcam_bank_evacuate(int,uint32,bcm_field_tcam_bank_info_t *);
extern int bcm_dnx_field_ace_entry_delete(int,uint32);
extern int bcm_dnx_field_range_type_config_set(int,uint32,bcm_field_stage_t,bcm_field_context_t,uint32,bcm_field_range_qual_info_t *);
extern int bcm_dnx_field_flush_entry_delete(int,uint32,bcm_field_group_t,int);
extern int bcm_dnx_field_entry_add(int,uint32,bcm_field_group_t,bcm_field_entry_info_t *,bcm_field_entry_t *);
extern int bcm_dnx_field_flush_profile_attach(int,uint32,bcm_field_group_t,uint32);
extern int bcm_dnx_field_ace_entry_info_get(int,uint32,bcm_field_ace_entry_info_t *);
extern int bcm_dnx_field_ace_format_add(int,uint32,bcm_field_ace_format_info_t *,bcm_field_ace_format_t *);
extern int bcm_dnx_field_data_qualifier_create(int,bcm_field_data_qualifier_t *);
extern int bcm_dnx_field_group_cache(int,uint32,bcm_field_group_t,bcm_field_group_cache_mode_t);
extern int bcm_dnx_field_compare_operand_offset_get(int,int,bcm_field_compare_operand_t,int *);
extern int bcm_dnx_field_group_info_get(int,bcm_field_group_t,bcm_field_group_info_t *);
extern int bcm_dnx_field_presel_get(int,uint32,bcm_field_presel_entry_id_t *,bcm_field_presel_entry_data_t *);
extern int bcm_dnx_field_efes_action_delete(int,bcm_field_group_t,bcm_field_context_t,bcm_field_action_priority_t);
extern int bcm_dnx_field_context_compare_info_get(int,bcm_field_stage_t,bcm_field_context_t,uint32,bcm_field_context_compare_info_t *);
extern int bcm_dnx_field_tcam_bank_add(int,uint32,bcm_field_tcam_bank_info_t *);
extern int bcm_dnx_field_context_state_table_destroy(int,uint32,bcm_field_stage_t,bcm_field_context_t);
extern int bcm_dnx_field_group_context_info_get(int,bcm_field_group_t,bcm_field_context_t,bcm_field_group_attach_info_t *);
extern int bcm_dnx_field_group_add(int,uint32,bcm_field_group_info_t *,bcm_field_group_t *);
extern int bcm_dnx_field_group_action_offset_get(int,uint32,bcm_field_group_t,bcm_field_action_t,int *);
extern int bcm_dnx_field_range_type_config_get(int,uint32,bcm_field_stage_t,bcm_field_context_t,uint32,bcm_field_range_qual_info_t *);
extern int bcm_dnx_field_flush_profile_get(int,uint32,uint32,bcm_field_flush_profile_info_t *);
extern int bcm_dnx_field_group_delete(int,bcm_field_group_t);
extern int bcm_dnx_field_group_qualifier_offset_get(int,uint32,bcm_field_group_t,bcm_field_qualify_t,int *);
extern int bcm_dnx_field_qualifier_destroy(int,bcm_field_qualify_t);
extern int bcm_dnx_field_context_create(int,uint32,bcm_field_stage_t,bcm_field_context_info_t *,bcm_field_context_t *);
extern int bcm_dnx_field_name_to_id(int,uint32,bcm_field_name_to_id_info_t *,int *,uint32 *);
extern int bcm_dnx_field_context_param_set(int,uint32,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_param_info_t *);
extern int bcm_dnx_field_context_hash_create(int,uint32,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_hash_info_t *);
extern int bcm_dnx_field_qualifier_create(int,uint32,bcm_field_qualifier_info_create_t *,bcm_field_qualify_t *);
extern int bcm_dnx_field_action_info_get(int,bcm_field_action_t,bcm_field_stage_t,bcm_field_action_info_t *);
extern int bcm_dnx_field_entry_state_table_delete(int,uint32,bcm_field_entry_state_table_info_t *);
extern int bcm_dnx_field_context_hash_destroy(int,bcm_field_stage_t,bcm_field_context_t);
extern int bcm_dnx_field_presel_set(int,uint32,bcm_field_presel_entry_id_t *,bcm_field_presel_entry_data_t *);
extern int bcm_dnx_field_qualifier_info_get(int,bcm_field_qualify_t,bcm_field_stage_t,bcm_field_qualifier_info_get_t *);
extern int bcm_dnx_field_data_qualifier_destroy(int,int);
extern int bcm_dnx_field_range_set(int,uint32,bcm_field_stage_t,bcm_field_range_t,bcm_field_range_info_t *);
extern int bcm_dnx_field_entry_hit_flush(int,uint32,bcm_field_entry_t);
extern int bcm_dnx_field_ace_format_delete(int,bcm_field_ace_format_t);
extern int bcm_dnx_field_efes_action_info_get(int,bcm_field_group_t,bcm_field_context_t,bcm_field_action_priority_t,bcm_field_efes_action_info_t *);
extern int bcm_dnx_field_group_context_attach(int,uint32,bcm_field_group_t,bcm_field_context_t,bcm_field_group_attach_info_t *);
extern int bcm_dnx_field_action_create(int,uint32,bcm_field_action_info_t *,bcm_field_action_t *);
extern int bcm_dnx_field_efes_action_add(int,uint32,bcm_field_group_t,bcm_field_context_t,bcm_field_action_priority_t *,bcm_field_efes_action_info_t *);
extern int bcm_dnx_field_tcam_bank_status_get(int,bcm_core_t,uint32,bcm_field_tcam_bank_status_info_t *);
extern int bcm_dnx_field_range_info_get(int,bcm_field_stage_t,bcm_field_range_t *,bcm_field_range_info_t *);
extern int bcm_dnx_field_ace_format_info_get(int,bcm_field_ace_format_t,bcm_field_ace_format_info_t *);
extern int bcm_dnx_field_entry_delete(int,bcm_field_group_t,bcm_field_entry_qual_t [BCM_FIELD_NUMBER_OF_QUALS_PER_GROUP],bcm_field_entry_t);
extern int bcm_dnx_field_fem_action_add(int,uint32,bcm_field_group_t,bcm_field_action_priority_t,bcm_field_fem_action_info_t *);
extern int bcm_dnx_field_flush_entry_get(int,uint32,bcm_field_group_t,int,bcm_field_flush_entry_info_t *);
extern int bcm_dnx_field_ace_entry_add(int,uint32,bcm_field_ace_format_t,bcm_field_ace_entry_info_t *,uint32 *);
extern int bcm_dnx_field_flush_profile_destroy(int,uint32,uint32);
extern int bcm_dnx_field_fem_action_info_get(int,bcm_field_group_t,bcm_field_action_priority_t,bcm_field_fem_action_info_t *);
extern int bcm_dnx_field_context_info_get(int,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_info_t *);
extern int bcm_dnx_field_context_state_table_create(int,uint32,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_state_table_info_t *);
extern int bcm_dnx_field_context_state_table_info_get(int,uint32,bcm_field_stage_t,bcm_field_context_t,bcm_field_context_state_table_info_t *);
extern int bcm_dnx_field_group_context_detach(int,bcm_field_group_t,bcm_field_context_t);
extern int bcm_dnx_field_flush_profile_create(int,uint32,bcm_field_flush_profile_info_t *,uint32 *);
extern int bcm_dnx_field_action_value_map(int,bcm_field_stage_t,bcm_field_action_t,uint32 [BCM_FIELD_ACTION_WIDTH_IN_WORDS],uint32 [BCM_FIELD_ACTION_WIDTH_IN_WORDS]);
extern int bcm_dnx_field_context_compare_create(int,uint32,bcm_field_stage_t,bcm_field_context_t,uint32,bcm_field_context_compare_info_t *);
extern int bcm_dnx_field_data_qualifier_get(int,int,bcm_field_data_qualifier_t *);
extern int bcm_dnx_field_entry_info_get(int,bcm_field_group_t,bcm_field_entry_t,bcm_field_entry_info_t *);
extern int bcm_dnx_field_entry_state_table_info_get(int,uint32,bcm_field_entry_state_table_info_t *);
extern int bcm_dnx_field_context_destroy(int,bcm_field_stage_t,bcm_field_context_t);
extern int bcm_dnx_field_action_destroy(int,bcm_field_action_t);
extern int bcm_dnx_field_context_compare_destroy(int,bcm_field_stage_t,bcm_field_context_t,uint32);
extern int bcm_dnx_field_entry_hit_get(int,uint32,bcm_field_entry_t,uint8 *);

#endif /* BCM_DNX_SUPPORT */
#endif /* !_BCM_INT_DNX_FIELD_DISPATCH_H */