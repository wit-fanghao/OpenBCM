
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifdef BSL_LOG_MODULE
#error "BSL_LOG_MODULE redefined"
#endif
#define BSL_LOG_MODULE BSL_LS_BCMDNX_RX

#include <soc/dnx/dnx_data/auto_generated/dnx_data_internal_trap.h>



#ifdef BCM_DNX2_SUPPORT

extern shr_error_e jr2_a0_data_trap_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e jr2_b0_data_trap_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2c_a0_data_trap_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e q2a_a0_data_trap_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2p_a0_data_trap_attach(
    int unit);

#endif 
#ifdef BCM_DNX2_SUPPORT

extern shr_error_e j2x_a0_data_trap_attach(
    int unit);

#endif 



static shr_error_e
dnx_data_trap_ingress_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "ingress";
    submodule_data->doc = "trap profiles data";
    
    submodule_data->nof_features = _dnx_data_trap_ingress_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap ingress features");

    submodule_data->features[dnx_data_trap_ingress_ndp_trap_en].name = "ndp_trap_en";
    submodule_data->features[dnx_data_trap_ingress_ndp_trap_en].doc = "Are NDP/myNDP traps supported";
    submodule_data->features[dnx_data_trap_ingress_ndp_trap_en].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_trap_in_lif_profile_mapping].name = "trap_in_lif_profile_mapping";
    submodule_data->features[dnx_data_trap_ingress_trap_in_lif_profile_mapping].doc = "If set, mapping for in_lif_prfile in the case of ingress protocol trap";
    submodule_data->features[dnx_data_trap_ingress_trap_in_lif_profile_mapping].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_svtag_trap_en].name = "svtag_trap_en";
    submodule_data->features[dnx_data_trap_ingress_svtag_trap_en].doc = "Does MACSec exist in the device, so it can be initialized";
    submodule_data->features[dnx_data_trap_ingress_svtag_trap_en].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_oam_offset_actions].name = "oam_offset_actions";
    submodule_data->features[dnx_data_trap_ingress_oam_offset_actions].doc = "Does the device support OAM Offset adjustment actions";
    submodule_data->features[dnx_data_trap_ingress_oam_offset_actions].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_snoop_code_clear_action].name = "snoop_code_clear_action";
    submodule_data->features[dnx_data_trap_ingress_snoop_code_clear_action].doc = "Enables the Snoop Code clear action from Q2A onward";
    submodule_data->features[dnx_data_trap_ingress_snoop_code_clear_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_mirror_code_clear_action].name = "mirror_code_clear_action";
    submodule_data->features[dnx_data_trap_ingress_mirror_code_clear_action].doc = "Enables the Mirror Code clear action from Q2A onward";
    submodule_data->features[dnx_data_trap_ingress_mirror_code_clear_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_stat_sampling_code_clear_action].name = "stat_sampling_code_clear_action";
    submodule_data->features[dnx_data_trap_ingress_stat_sampling_code_clear_action].doc = "Enables the Statistical Sampling Code clear action from Q2A onward";
    submodule_data->features[dnx_data_trap_ingress_stat_sampling_code_clear_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_bypass_filtering_action].name = "bypass_filtering_action";
    submodule_data->features[dnx_data_trap_ingress_bypass_filtering_action].doc = "Enables bypass filtering action";
    submodule_data->features[dnx_data_trap_ingress_bypass_filtering_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_ipv6_mapped_dest].name = "ipv6_mapped_dest";
    submodule_data->features[dnx_data_trap_ingress_ipv6_mapped_dest].doc = "Shows if IPv6 mapped destination trap is working";
    submodule_data->features[dnx_data_trap_ingress_ipv6_mapped_dest].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_mpls_termination_fail_over].name = "mpls_termination_fail_over";
    submodule_data->features[dnx_data_trap_ingress_mpls_termination_fail_over].doc = "Shows if MPLS termination labels need to be over the number of sent";
    submodule_data->features[dnx_data_trap_ingress_mpls_termination_fail_over].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_checksum_feature_fixed].name = "checksum_feature_fixed";
    submodule_data->features[dnx_data_trap_ingress_checksum_feature_fixed].doc = "";
    submodule_data->features[dnx_data_trap_ingress_checksum_feature_fixed].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_header_size_err_blocking].name = "header_size_err_blocking";
    submodule_data->features[dnx_data_trap_ingress_header_size_err_blocking].doc = "";
    submodule_data->features[dnx_data_trap_ingress_header_size_err_blocking].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_l4_trap_res_before_l3].name = "l4_trap_res_before_l3";
    submodule_data->features[dnx_data_trap_ingress_l4_trap_res_before_l3].doc = "";
    submodule_data->features[dnx_data_trap_ingress_l4_trap_res_before_l3].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_comp_mc_before_routing_traps].name = "comp_mc_before_routing_traps";
    submodule_data->features[dnx_data_trap_ingress_comp_mc_before_routing_traps].doc = "";
    submodule_data->features[dnx_data_trap_ingress_comp_mc_before_routing_traps].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_soft_mem_err_over_dest_err].name = "soft_mem_err_over_dest_err";
    submodule_data->features[dnx_data_trap_ingress_soft_mem_err_over_dest_err].doc = "Shows if soft mem error takes priority over destination error";
    submodule_data->features[dnx_data_trap_ingress_soft_mem_err_over_dest_err].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_eth_default_proc_fix].name = "eth_default_proc_fix";
    submodule_data->features[dnx_data_trap_ingress_eth_default_proc_fix].doc = "Shows if Ethernet default procedure fix was for the device.";
    submodule_data->features[dnx_data_trap_ingress_eth_default_proc_fix].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_fwd_domain_mode_trap].name = "fwd_domain_mode_trap";
    submodule_data->features[dnx_data_trap_ingress_fwd_domain_mode_trap].doc = "Shows if Fwd domain mode trap is enabled.";
    submodule_data->features[dnx_data_trap_ingress_fwd_domain_mode_trap].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_sa_equals_zero_trap].name = "sa_equals_zero_trap";
    submodule_data->features[dnx_data_trap_ingress_sa_equals_zero_trap].doc = "Shows if SA equals Zero trap is enabled.";
    submodule_data->features[dnx_data_trap_ingress_sa_equals_zero_trap].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_latency_measurement_bug].name = "latency_measurement_bug";
    submodule_data->features[dnx_data_trap_ingress_latency_measurement_bug].doc = "";
    submodule_data->features[dnx_data_trap_ingress_latency_measurement_bug].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_ser_hw_support].name = "ser_hw_support";
    submodule_data->features[dnx_data_trap_ingress_ser_hw_support].doc = "Indicate if software memory error is supported";
    submodule_data->features[dnx_data_trap_ingress_ser_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_compatible_mc_hw_support].name = "compatible_mc_hw_support";
    submodule_data->features[dnx_data_trap_ingress_compatible_mc_hw_support].doc = "Indicate if compatible multicast is supported";
    submodule_data->features[dnx_data_trap_ingress_compatible_mc_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_tcp_frag_offset_lt8_trap_support].name = "tcp_frag_offset_lt8_trap_support";
    submodule_data->features[dnx_data_trap_ingress_tcp_frag_offset_lt8_trap_support].doc = "Indicate if tcp fragment offset less than 8 trap is supported";
    submodule_data->features[dnx_data_trap_ingress_tcp_frag_offset_lt8_trap_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_eth_trap_vec_mapping_support].name = "eth_trap_vec_mapping_support";
    submodule_data->features[dnx_data_trap_ingress_eth_trap_vec_mapping_support].doc = "Indicate if ethernet trap vector needs to be mapped";
    submodule_data->features[dnx_data_trap_ingress_eth_trap_vec_mapping_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_support_fabric_header_set_action].name = "support_fabric_header_set_action";
    submodule_data->features[dnx_data_trap_ingress_support_fabric_header_set_action].doc = "Indicates if fabric header set action is supported";
    submodule_data->features[dnx_data_trap_ingress_support_fabric_header_set_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_support_update_exem_learn_action].name = "support_update_exem_learn_action";
    submodule_data->features[dnx_data_trap_ingress_support_update_exem_learn_action].doc = "Indicates if update exem learn action is supported";
    submodule_data->features[dnx_data_trap_ingress_support_update_exem_learn_action].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_ingress_support_update_trunk_members_action].name = "support_update_trunk_members_action";
    submodule_data->features[dnx_data_trap_ingress_support_update_trunk_members_action].doc = "Indicates if update trunk members local only action is supported";
    submodule_data->features[dnx_data_trap_ingress_support_update_trunk_members_action].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_trap_ingress_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap ingress defines");

    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_init_mode].name = "protocol_traps_init_mode";
    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_init_mode].doc = "initialize protocol traps configuration mode";
    
    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_init_mode].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_lif_profile_starting_offset].name = "protocol_traps_lif_profile_starting_offset";
    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_lif_profile_starting_offset].doc = "The offset at which LIF profile entries start in protocol profiling table";
    
    submodule_data->defines[dnx_data_trap_ingress_define_protocol_traps_lif_profile_starting_offset].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_predefeind_traps].name = "nof_predefeind_traps";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_predefeind_traps].doc = "Number of predefined traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_predefeind_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps].name = "nof_user_defined_traps";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps].doc = "Number of bcmRxTrapUserDefine traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps_in_jr1_mode].name = "nof_user_defined_traps_in_jr1_mode";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps_in_jr1_mode].doc = "Number of bcmRxTrapUserDefine traps in jr1 mode";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_user_defined_traps_in_jr1_mode].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_1588_traps].name = "nof_1588_traps";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_1588_traps].doc = "Number of bcmRxTrap1588 traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_1588_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_entries_action_table].name = "nof_entries_action_table";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_entries_action_table].doc = "Number of entries in action table of traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_entries_action_table].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_protocol_trap_profiles].name = "nof_protocol_trap_profiles";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_protocol_trap_profiles].doc = "Number of protocol trap profiles";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_protocol_trap_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_recycle_cmds].name = "nof_recycle_cmds";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_recycle_cmds].doc = "Number of forward recycle commands";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_recycle_cmds].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_programmable_traps].name = "nof_programmable_traps";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_programmable_traps].doc = "Number of programmable traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_programmable_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_lif_traps].name = "nof_lif_traps";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_lif_traps].doc = "Number of LIF traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_lif_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_icmp_compressed_types].name = "nof_icmp_compressed_types";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_icmp_compressed_types].doc = "Number of ICMP compressed types";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_icmp_compressed_types].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_stat_objs].name = "nof_stat_objs";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_stat_objs].doc = "Number of ingress statistical objects";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_stat_objs].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_max_nof_stat_objs_to_overwrite].name = "max_nof_stat_objs_to_overwrite";
    submodule_data->defines[dnx_data_trap_ingress_define_max_nof_stat_objs_to_overwrite].doc = "Max number of statistical objects to overwrite";
    
    submodule_data->defines[dnx_data_trap_ingress_define_max_nof_stat_objs_to_overwrite].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_code_profiles].name = "nof_error_code_profiles";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_code_profiles].doc = "Number of Error Code profiles for MACSEC traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_code_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_sci_profiles].name = "nof_sci_profiles";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_sci_profiles].doc = "Number of SCI profiles for MACSEC traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_sci_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_codes].name = "nof_error_codes";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_codes].doc = "Number of Error Codes for MACSEC traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_error_codes].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_ingress_define_nof_scis].name = "nof_scis";
    submodule_data->defines[dnx_data_trap_ingress_define_nof_scis].doc = "Number of SCIs for MACSEC traps";
    
    submodule_data->defines[dnx_data_trap_ingress_define_nof_scis].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_trap_ingress_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap ingress tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_ingress_feature_get(
    int unit,
    dnx_data_trap_ingress_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, feature);
}


uint32
dnx_data_trap_ingress_protocol_traps_init_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_protocol_traps_init_mode);
}

uint32
dnx_data_trap_ingress_protocol_traps_lif_profile_starting_offset_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_protocol_traps_lif_profile_starting_offset);
}

uint32
dnx_data_trap_ingress_nof_predefeind_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_predefeind_traps);
}

uint32
dnx_data_trap_ingress_nof_user_defined_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_user_defined_traps);
}

uint32
dnx_data_trap_ingress_nof_user_defined_traps_in_jr1_mode_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_user_defined_traps_in_jr1_mode);
}

uint32
dnx_data_trap_ingress_nof_1588_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_1588_traps);
}

uint32
dnx_data_trap_ingress_nof_entries_action_table_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_entries_action_table);
}

uint32
dnx_data_trap_ingress_nof_protocol_trap_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_protocol_trap_profiles);
}

uint32
dnx_data_trap_ingress_nof_recycle_cmds_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_recycle_cmds);
}

uint32
dnx_data_trap_ingress_nof_programmable_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_programmable_traps);
}

uint32
dnx_data_trap_ingress_nof_lif_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_lif_traps);
}

uint32
dnx_data_trap_ingress_nof_icmp_compressed_types_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_icmp_compressed_types);
}

uint32
dnx_data_trap_ingress_nof_stat_objs_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_stat_objs);
}

uint32
dnx_data_trap_ingress_max_nof_stat_objs_to_overwrite_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_max_nof_stat_objs_to_overwrite);
}

uint32
dnx_data_trap_ingress_nof_error_code_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_error_code_profiles);
}

uint32
dnx_data_trap_ingress_nof_sci_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_sci_profiles);
}

uint32
dnx_data_trap_ingress_nof_error_codes_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_error_codes);
}

uint32
dnx_data_trap_ingress_nof_scis_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_ingress, dnx_data_trap_ingress_define_nof_scis);
}










static shr_error_e
dnx_data_trap_erpp_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "erpp";
    submodule_data->doc = "erpp traps";
    
    submodule_data->nof_features = _dnx_data_trap_erpp_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap erpp features");

    submodule_data->features[dnx_data_trap_erpp_unknown_da_trap_en].name = "unknown_da_trap_en";
    submodule_data->features[dnx_data_trap_erpp_unknown_da_trap_en].doc = "Is UnknownDA trap supported";
    submodule_data->features[dnx_data_trap_erpp_unknown_da_trap_en].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_erpp_glem_not_found_trap].name = "glem_not_found_trap";
    submodule_data->features[dnx_data_trap_erpp_glem_not_found_trap].doc = "Is glem not found trap supported";
    submodule_data->features[dnx_data_trap_erpp_glem_not_found_trap].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_trap_erpp_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap erpp defines");

    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_app_traps].name = "nof_erpp_app_traps";
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_app_traps].doc = "Number of ERPP application traps";
    
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_app_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_forward_profiles].name = "nof_erpp_forward_profiles";
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_forward_profiles].doc = "Number of ERPP forward profiles";
    
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_forward_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_user_configurable_profiles].name = "nof_erpp_user_configurable_profiles";
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_user_configurable_profiles].doc = "Number of user configurable profiles";
    
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_user_configurable_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_snif_profiles].name = "nof_erpp_snif_profiles";
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_snif_profiles].doc = "Number of ERPP snif profiles";
    
    submodule_data->defines[dnx_data_trap_erpp_define_nof_erpp_snif_profiles].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_trap_erpp_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap erpp tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_erpp_feature_get(
    int unit,
    dnx_data_trap_erpp_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_erpp, feature);
}


uint32
dnx_data_trap_erpp_nof_erpp_app_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_erpp, dnx_data_trap_erpp_define_nof_erpp_app_traps);
}

uint32
dnx_data_trap_erpp_nof_erpp_forward_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_erpp, dnx_data_trap_erpp_define_nof_erpp_forward_profiles);
}

uint32
dnx_data_trap_erpp_nof_erpp_user_configurable_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_erpp, dnx_data_trap_erpp_define_nof_erpp_user_configurable_profiles);
}

uint32
dnx_data_trap_erpp_nof_erpp_snif_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_erpp, dnx_data_trap_erpp_define_nof_erpp_snif_profiles);
}










static shr_error_e
dnx_data_trap_etpp_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "etpp";
    submodule_data->doc = "etpp traps";
    
    submodule_data->nof_features = _dnx_data_trap_etpp_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap etpp features");

    submodule_data->features[dnx_data_trap_etpp_glem_hw_support].name = "glem_hw_support";
    submodule_data->features[dnx_data_trap_etpp_glem_hw_support].doc = "Indicate if glem hw is supported";
    submodule_data->features[dnx_data_trap_etpp_glem_hw_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_etpp_visibility_trap_support].name = "visibility_trap_support";
    submodule_data->features[dnx_data_trap_etpp_visibility_trap_support].doc = "Indicate if visibility trap is supported";
    submodule_data->features[dnx_data_trap_etpp_visibility_trap_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_etpp_oam_traps_predefined_support].name = "oam_traps_predefined_support";
    submodule_data->features[dnx_data_trap_etpp_oam_traps_predefined_support].doc = "Indicate if OAM traps are supported as predefined traps";
    submodule_data->features[dnx_data_trap_etpp_oam_traps_predefined_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_etpp_mtu_trap_action_profile_indirection].name = "mtu_trap_action_profile_indirection";
    submodule_data->features[dnx_data_trap_etpp_mtu_trap_action_profile_indirection].doc = "Indicate if mtu trap action profile is indirected to a separate table";
    submodule_data->features[dnx_data_trap_etpp_mtu_trap_action_profile_indirection].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_etpp_mtu_layer_to_compressed_layer_mapping_support].name = "mtu_layer_to_compressed_layer_mapping_support";
    submodule_data->features[dnx_data_trap_etpp_mtu_layer_to_compressed_layer_mapping_support].doc = "Indicate if mtu mapping from layer type to compressed layer type is supported";
    submodule_data->features[dnx_data_trap_etpp_mtu_layer_to_compressed_layer_mapping_support].flags |= DNXC_DATA_F_FEATURE;

    submodule_data->features[dnx_data_trap_etpp_latency_trap_mirror_config_support].name = "latency_trap_mirror_config_support";
    submodule_data->features[dnx_data_trap_etpp_latency_trap_mirror_config_support].doc = "Indicate if latency trap mirror configuration is supported";
    submodule_data->features[dnx_data_trap_etpp_latency_trap_mirror_config_support].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_trap_etpp_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap etpp defines");

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_app_traps].name = "nof_etpp_app_traps";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_app_traps].doc = "Number of ETPP application traps";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_app_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_user_configurable_profiles].name = "nof_etpp_user_configurable_profiles";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_user_configurable_profiles].doc = "Number of user configurable profiles";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_user_configurable_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_first_etpp_user_configurable_profile].name = "first_etpp_user_configurable_profile";
    submodule_data->defines[dnx_data_trap_etpp_define_first_etpp_user_configurable_profile].doc = "First user configurable profile number";
    
    submodule_data->defines[dnx_data_trap_etpp_define_first_etpp_user_configurable_profile].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_trap_profiles].name = "nof_etpp_trap_profiles";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_trap_profiles].doc = "Number of ETPP trap profiles";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_trap_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_oam_traps].name = "nof_etpp_oam_traps";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_oam_traps].doc = "Number of ETPP OAM traps";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_oam_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_snif_profiles].name = "nof_etpp_snif_profiles";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_snif_profiles].doc = "Number of ETPP snif profiles";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_snif_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_lif_traps].name = "nof_etpp_lif_traps";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_lif_traps].doc = "Number of ETPP LIF traps";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_etpp_lif_traps].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_trap_context_port_profile_4b].name = "trap_context_port_profile_4b";
    submodule_data->defines[dnx_data_trap_etpp_define_trap_context_port_profile_4b].doc = "The context port profile 4b.";
    
    submodule_data->defines[dnx_data_trap_etpp_define_trap_context_port_profile_4b].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_profiles].name = "nof_mtu_profiles";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_profiles].doc = "Number of MTU profiles";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_max_mtu_value].name = "max_mtu_value";
    submodule_data->defines[dnx_data_trap_etpp_define_max_mtu_value].doc = "The maximum MTU value allowed.";
    
    submodule_data->defines[dnx_data_trap_etpp_define_max_mtu_value].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_trap_action_profiles].name = "nof_mtu_trap_action_profiles";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_trap_action_profiles].doc = "Number of MTU trap action profiles";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_trap_action_profiles].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_map_table_entries].name = "nof_mtu_map_table_entries";
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_map_table_entries].doc = "Number of MTU map table entries";
    
    submodule_data->defines[dnx_data_trap_etpp_define_nof_mtu_map_table_entries].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_trap_etpp_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap etpp tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_etpp_feature_get(
    int unit,
    dnx_data_trap_etpp_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, feature);
}


uint32
dnx_data_trap_etpp_nof_etpp_app_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_app_traps);
}

uint32
dnx_data_trap_etpp_nof_etpp_user_configurable_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_user_configurable_profiles);
}

uint32
dnx_data_trap_etpp_first_etpp_user_configurable_profile_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_first_etpp_user_configurable_profile);
}

uint32
dnx_data_trap_etpp_nof_etpp_trap_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_trap_profiles);
}

uint32
dnx_data_trap_etpp_nof_etpp_oam_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_oam_traps);
}

uint32
dnx_data_trap_etpp_nof_etpp_snif_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_snif_profiles);
}

uint32
dnx_data_trap_etpp_nof_etpp_lif_traps_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_etpp_lif_traps);
}

uint32
dnx_data_trap_etpp_trap_context_port_profile_4b_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_trap_context_port_profile_4b);
}

uint32
dnx_data_trap_etpp_nof_mtu_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_mtu_profiles);
}

uint32
dnx_data_trap_etpp_max_mtu_value_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_max_mtu_value);
}

uint32
dnx_data_trap_etpp_nof_mtu_trap_action_profiles_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_mtu_trap_action_profiles);
}

uint32
dnx_data_trap_etpp_nof_mtu_map_table_entries_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_etpp, dnx_data_trap_etpp_define_nof_mtu_map_table_entries);
}










static shr_error_e
dnx_data_trap_egress_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "egress";
    submodule_data->doc = "egress traps";
    
    submodule_data->nof_features = _dnx_data_trap_egress_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap egress features");

    submodule_data->features[dnx_data_trap_egress_egress_divided_to_erpp_and_etpp].name = "egress_divided_to_erpp_and_etpp";
    submodule_data->features[dnx_data_trap_egress_egress_divided_to_erpp_and_etpp].doc = "Is Egress divided to ERPP and ETPP stages";
    submodule_data->features[dnx_data_trap_egress_egress_divided_to_erpp_and_etpp].flags |= DNXC_DATA_F_FEATURE;

    
    submodule_data->nof_defines = _dnx_data_trap_egress_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap egress defines");

    
    submodule_data->nof_tables = _dnx_data_trap_egress_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap egress tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_egress_feature_get(
    int unit,
    dnx_data_trap_egress_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_egress, feature);
}











static shr_error_e
dnx_data_trap_strength_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "strength";
    submodule_data->doc = "trap profiles data";
    
    submodule_data->nof_features = _dnx_data_trap_strength_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap strength features");

    
    submodule_data->nof_defines = _dnx_data_trap_strength_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap strength defines");

    submodule_data->defines[dnx_data_trap_strength_define_max_strength].name = "max_strength";
    submodule_data->defines[dnx_data_trap_strength_define_max_strength].doc = "Max value of strength (4b)";
    
    submodule_data->defines[dnx_data_trap_strength_define_max_strength].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_strength_define_max_snp_strength].name = "max_snp_strength";
    submodule_data->defines[dnx_data_trap_strength_define_max_snp_strength].doc = "Max value of snoop strength (3b)";
    
    submodule_data->defines[dnx_data_trap_strength_define_max_snp_strength].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_strength_define_max_ingress_to_egress_compressed_strength].name = "max_ingress_to_egress_compressed_strength";
    submodule_data->defines[dnx_data_trap_strength_define_max_ingress_to_egress_compressed_strength].doc = "Max value of ingress compressed strength (3b) mapped to egress strength (4b)";
    
    submodule_data->defines[dnx_data_trap_strength_define_max_ingress_to_egress_compressed_strength].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_strength_define_default_trap_strength].name = "default_trap_strength";
    submodule_data->defines[dnx_data_trap_strength_define_default_trap_strength].doc = "Default trap strength used when drop / trap packets to CPU";
    
    submodule_data->defines[dnx_data_trap_strength_define_default_trap_strength].flags |= DNXC_DATA_F_NUMERIC;

    submodule_data->defines[dnx_data_trap_strength_define_default_snoop_strength].name = "default_snoop_strength";
    submodule_data->defines[dnx_data_trap_strength_define_default_snoop_strength].doc = "Default snoop strength used when drop / trap packets to CPU";
    
    submodule_data->defines[dnx_data_trap_strength_define_default_snoop_strength].flags |= DNXC_DATA_F_NUMERIC;

    
    submodule_data->nof_tables = _dnx_data_trap_strength_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap strength tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_strength_feature_get(
    int unit,
    dnx_data_trap_strength_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, feature);
}


uint32
dnx_data_trap_strength_max_strength_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, dnx_data_trap_strength_define_max_strength);
}

uint32
dnx_data_trap_strength_max_snp_strength_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, dnx_data_trap_strength_define_max_snp_strength);
}

uint32
dnx_data_trap_strength_max_ingress_to_egress_compressed_strength_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, dnx_data_trap_strength_define_max_ingress_to_egress_compressed_strength);
}

uint32
dnx_data_trap_strength_default_trap_strength_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, dnx_data_trap_strength_define_default_trap_strength);
}

uint32
dnx_data_trap_strength_default_snoop_strength_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_strength, dnx_data_trap_strength_define_default_snoop_strength);
}










static shr_error_e
dnx_data_trap_register_name_changes_init(
    int unit,
    dnxc_data_submodule_t *submodule_data)
{
    SHR_FUNC_INIT_VARS(unit);

    submodule_data->name = "register_name_changes";
    submodule_data->doc = "Registers with changed names throughout devices.";
    
    submodule_data->nof_features = _dnx_data_trap_register_name_changes_feature_nof;
    DNXC_DATA_ALLOC(submodule_data->features, dnxc_data_feature_t,  submodule_data->nof_features, "_dnxc_data trap register_name_changes features");

    
    submodule_data->nof_defines = _dnx_data_trap_register_name_changes_define_nof;
    DNXC_DATA_ALLOC(submodule_data->defines, dnxc_data_define_t, submodule_data->nof_defines, "_dnxc_data trap register_name_changes defines");

    submodule_data->defines[dnx_data_trap_register_name_changes_define_out_lif_mcdb_ptr_signal].name = "out_lif_mcdb_ptr_signal";
    submodule_data->defines[dnx_data_trap_register_name_changes_define_out_lif_mcdb_ptr_signal].doc = "Out_LIF_or_MCDB_Ptr_ACE signal is shifted by bits";
    
    submodule_data->defines[dnx_data_trap_register_name_changes_define_out_lif_mcdb_ptr_signal].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_register_name_changes_define_added_n].name = "added_n";
    submodule_data->defines[dnx_data_trap_register_name_changes_define_added_n].doc = "Register name changed to have an _N at the end.";
    
    submodule_data->defines[dnx_data_trap_register_name_changes_define_added_n].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_register_name_changes_define_per_pp_port_change].name = "per_pp_port_change";
    submodule_data->defines[dnx_data_trap_register_name_changes_define_per_pp_port_change].doc = "Register names changed to be per PP port.";
    
    submodule_data->defines[dnx_data_trap_register_name_changes_define_per_pp_port_change].flags |= DNXC_DATA_F_DEFINE;

    submodule_data->defines[dnx_data_trap_register_name_changes_define_visibility_signal_0].name = "visibility_signal_0";
    submodule_data->defines[dnx_data_trap_register_name_changes_define_visibility_signal_0].doc = "Visibility signal validation enabled";
    
    submodule_data->defines[dnx_data_trap_register_name_changes_define_visibility_signal_0].flags |= DNXC_DATA_F_DEFINE;

    
    submodule_data->nof_tables = _dnx_data_trap_register_name_changes_table_nof;
    DNXC_DATA_ALLOC(submodule_data->tables, dnxc_data_table_t, submodule_data->nof_tables, "_dnxc_data trap register_name_changes tables");


exit:
    SHR_FUNC_EXIT;
}


int
dnx_data_trap_register_name_changes_feature_get(
    int unit,
    dnx_data_trap_register_name_changes_feature_e feature)
{
    return dnxc_data_mgmt_feature_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_register_name_changes, feature);
}


uint32
dnx_data_trap_register_name_changes_out_lif_mcdb_ptr_signal_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_register_name_changes, dnx_data_trap_register_name_changes_define_out_lif_mcdb_ptr_signal);
}

uint32
dnx_data_trap_register_name_changes_added_n_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_register_name_changes, dnx_data_trap_register_name_changes_define_added_n);
}

uint32
dnx_data_trap_register_name_changes_per_pp_port_change_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_register_name_changes, dnx_data_trap_register_name_changes_define_per_pp_port_change);
}

uint32
dnx_data_trap_register_name_changes_visibility_signal_0_get(
    int unit)
{
    return dnxc_data_mgmt_define_data_get(unit, dnx_data_module_trap, dnx_data_trap_submodule_register_name_changes, dnx_data_trap_register_name_changes_define_visibility_signal_0);
}







shr_error_e
dnx_data_trap_init(
    int unit,
    dnxc_data_module_t *module_data)
{
    SHR_FUNC_INIT_VARS(unit);

    
    module_data->name = "trap";
    module_data->nof_submodules = _dnx_data_trap_submodule_nof;
    DNXC_DATA_ALLOC(module_data->submodules, dnxc_data_submodule_t, module_data->nof_submodules, "_dnxc_data trap submodules");

    
    SHR_IF_ERR_EXIT(dnx_data_trap_ingress_init(unit, &module_data->submodules[dnx_data_trap_submodule_ingress]));
    SHR_IF_ERR_EXIT(dnx_data_trap_erpp_init(unit, &module_data->submodules[dnx_data_trap_submodule_erpp]));
    SHR_IF_ERR_EXIT(dnx_data_trap_etpp_init(unit, &module_data->submodules[dnx_data_trap_submodule_etpp]));
    SHR_IF_ERR_EXIT(dnx_data_trap_egress_init(unit, &module_data->submodules[dnx_data_trap_submodule_egress]));
    SHR_IF_ERR_EXIT(dnx_data_trap_strength_init(unit, &module_data->submodules[dnx_data_trap_submodule_strength]));
    SHR_IF_ERR_EXIT(dnx_data_trap_register_name_changes_init(unit, &module_data->submodules[dnx_data_trap_submodule_register_name_changes]));
    
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_jr2_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(jr2_b0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2c_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2c_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_q2a_b1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(q2a_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a1(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2p_a2(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2p_a0_data_trap_attach(unit));
    }
    else

#endif 
#ifdef BCM_DNX2_SUPPORT

    if (dnxc_data_mgmt_is_j2x_a0(unit))
    {
        SHR_IF_ERR_EXIT(jr2_a0_data_trap_attach(unit));
        SHR_IF_ERR_EXIT(j2x_a0_data_trap_attach(unit));
    }
    else

#endif 
    {
        SHR_EXIT();
    }

exit:
    SHR_FUNC_EXIT;
}
#undef BSL_LOG_MODULE

