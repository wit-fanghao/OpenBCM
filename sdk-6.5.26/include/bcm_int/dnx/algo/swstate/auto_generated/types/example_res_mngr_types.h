/** \file algo/swstate/auto_generated/types/example_res_mngr_types.h
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
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 */

#ifndef __EXAMPLE_RES_MNGR_TYPES_H__
#define __EXAMPLE_RES_MNGR_TYPES_H__

#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
/*
 * STRUCTs
 */

/**
 * Resource management unit test sw state.
 */
typedef struct {
    /**
     * resource_test
     */
    dnx_algo_res_t resource;
} example_res_mngr_sw_state_t;


#endif /* __EXAMPLE_RES_MNGR_TYPES_H__ */