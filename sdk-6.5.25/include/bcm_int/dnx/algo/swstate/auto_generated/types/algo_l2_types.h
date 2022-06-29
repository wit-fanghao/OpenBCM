/** \file algo/swstate/auto_generated/types/algo_l2_types.h
 *
 * sw state types (structs/enums/typedefs)
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated.
 * Edits to this file will be lost when it is regenerated.
 *
 */
/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2021 Broadcom Inc. All rights reserved.
 */

#ifndef __ALGO_L2_TYPES_H__
#define __ALGO_L2_TYPES_H__

#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <bcm_int/dnx/algo/l2/algo_l2.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
/*
 * STRUCTs
 */

/**
 * L2 related sw state
 */
typedef struct {
    /**
     * VSI forwarding profile template
     */
    dnx_algo_template_t event_forwarding_profile;
    /**
     * VSI learning profile template
     */
    dnx_algo_template_t vsi_learning_profile;
    /**
     * VSI aging profile template
     */
    dnx_algo_template_t vsi_aging_profile;
} algo_l2_sw_state_t;


#endif /* __ALGO_L2_TYPES_H__ */