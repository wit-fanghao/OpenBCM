
/* *INDENT-OFF* */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */
#ifndef _DNX_DATA_LATENCY_H_

#define _DNX_DATA_LATENCY_H_

#include <sal/limits.h>
#include <soc/property.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <shared/utilex/utilex_framework.h>
#include <soc/dnxc/dnxc_data/dnxc_data_utils.h>
#include <soc/dnxc/dnxc_data/dnxc_data_mgmt.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_max_latency.h>



#ifndef BCM_DNX_SUPPORT
#error "This file is for use by DNX (JR2) family only!"
#endif



shr_error_e dnx_data_if_latency_init(
    int unit);







typedef enum
{
    
    dnx_data_latency_features_valid_flow_profile_flag,
    
    dnx_data_latency_features_valid_end_to_end_aqm_profile,
    
    dnx_data_latency_features_probabilistic_legacy_mechanism_support,
    
    dnx_data_latency_features_egress_ecn_probabilistic_mechanism_support,
    
    dnx_data_latency_features_ingress_ecn_probabilistic_mechanism_support,
    
    dnx_data_latency_features_drop_probabilistic_mechanism_support,
    
    dnx_data_latency_features_coupled_mode_support,
    
    dnx_data_latency_features_latency_measurement_support,
    
    dnx_data_latency_features_valid_track_expansion,
    
    dnx_data_latency_features_egress_latency_track_support,
    
    dnx_data_latency_features_ingress_based_admission,

    
    _dnx_data_latency_features_feature_nof
} dnx_data_latency_features_feature_e;



typedef int(
    *dnx_data_latency_features_feature_get_f) (
    int unit,
    dnx_data_latency_features_feature_e feature);


typedef uint32(
    *dnx_data_latency_features_latency_bins_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_latency_features_feature_get_f feature_get;
    
    dnx_data_latency_features_latency_bins_get_f latency_bins_get;
} dnx_data_if_latency_features_t;







typedef enum
{

    
    _dnx_data_latency_profile_feature_nof
} dnx_data_latency_profile_feature_e;



typedef int(
    *dnx_data_latency_profile_feature_get_f) (
    int unit,
    dnx_data_latency_profile_feature_e feature);


typedef uint32(
    *dnx_data_latency_profile_egress_nof_get_f) (
    int unit);


typedef uint32(
    *dnx_data_latency_profile_ingress_nof_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_latency_profile_feature_get_f feature_get;
    
    dnx_data_latency_profile_egress_nof_get_f egress_nof_get;
    
    dnx_data_latency_profile_ingress_nof_get_f ingress_nof_get;
} dnx_data_if_latency_profile_t;







typedef enum
{
    
    dnx_data_latency_based_admission_cgm_extended_profiles_enable,

    
    _dnx_data_latency_based_admission_feature_nof
} dnx_data_latency_based_admission_feature_e;



typedef int(
    *dnx_data_latency_based_admission_feature_get_f) (
    int unit,
    dnx_data_latency_based_admission_feature_e feature);


typedef uint32(
    *dnx_data_latency_based_admission_reject_flow_profile_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_latency_based_admission_cgm_extended_profiles_enable_value_get_f) (
    int unit);


typedef uint32(
    *dnx_data_latency_based_admission_max_supported_profile_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_latency_based_admission_feature_get_f feature_get;
    
    dnx_data_latency_based_admission_reject_flow_profile_value_get_f reject_flow_profile_value_get;
    
    dnx_data_latency_based_admission_cgm_extended_profiles_enable_value_get_f cgm_extended_profiles_enable_value_get;
    
    dnx_data_latency_based_admission_max_supported_profile_get_f max_supported_profile_get;
} dnx_data_if_latency_based_admission_t;







typedef enum
{

    
    _dnx_data_latency_ingress_feature_nof
} dnx_data_latency_ingress_feature_e;



typedef int(
    *dnx_data_latency_ingress_feature_get_f) (
    int unit,
    dnx_data_latency_ingress_feature_e feature);


typedef uint32(
    *dnx_data_latency_ingress_jr_mode_latency_timestamp_left_shift_get_f) (
    int unit);



typedef struct
{
    
    dnx_data_latency_ingress_feature_get_f feature_get;
    
    dnx_data_latency_ingress_jr_mode_latency_timestamp_left_shift_get_f jr_mode_latency_timestamp_left_shift_get;
} dnx_data_if_latency_ingress_t;





typedef struct
{
    
    dnx_data_if_latency_features_t features;
    
    dnx_data_if_latency_profile_t profile;
    
    dnx_data_if_latency_based_admission_t based_admission;
    
    dnx_data_if_latency_ingress_t ingress;
} dnx_data_if_latency_t;




extern dnx_data_if_latency_t dnx_data_latency;


#endif 

