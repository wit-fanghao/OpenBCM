/** \file algo/swstate/auto_generated/types/lif_table_mngr_types.h
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

#ifndef __LIF_TABLE_MNGR_TYPES_H__
#define __LIF_TABLE_MNGR_TYPES_H__

#include <soc/dnxc/swstate/dnxc_sw_state_h_includes.h>
#include <soc/dnxc/swstate/callbacks/sw_state_htb_callbacks.h>
#include <soc/dnxc/swstate/types/sw_state_hash_table.h>
/*
 * MACROs
 */

/**
 * Max number of Result types, can't be less than dnx_data_lif.lif_table_manager.max_nof_result_types_get()
 */
#define MAX_NOF_RESULT_TYPES 32

/*
 * STRUCTs
 */

/**
 * LIF Table manager SW info per local LIF
 */
typedef struct {
    /**
     * 32 bits of the valid fields bitmap
     */
    int valid_fields;
} local_lif_info_t;

/**
 * Information per DBAL LIF table ID
 */
typedef struct {
    /**
     * A list of sorted result type indices
     */
    int8 result_type[MAX_NOF_RESULT_TYPES];
#ifdef BCM_DNX2_SUPPORT
    /**
     * First 32 bits of the forbidden fields bitmap
     */
    int forbidden_fields_lo;
#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    /**
     * Last 32 bits of the forbidden fields bitmap
     */
    int forbidden_fields_hi;
#endif /* BCM_DNX2_SUPPORT*/ 
} lif_table_mngr_table_info_t;

/**
 * sw state for the LIF table manager
 */
typedef struct {
    /**
     * Hash table for valid fields per egress local LIF.
     */
    sw_state_htbl_t valid_fields_per_egress_lif_htb;
#ifdef BCM_DNX2_SUPPORT
    /**
     * Valid fields per ingress local LIFs in physical table INLIF1.
     */
    local_lif_info_t* valid_fields_per_ingress_lif1;
#endif /* BCM_DNX2_SUPPORT*/ 
#ifdef BCM_DNX2_SUPPORT
    /**
     * Valid fields per ingress local LIFs in physical table INLIF2/3.
     */
    local_lif_info_t* valid_fields_per_ingress_lif2;
#endif /* BCM_DNX2_SUPPORT*/ 
    /**
     * LIF table mngr information per LIF DBAL table ID
     */
    sw_state_htbl_t lif_table_info_htb;
} lif_table_mngr_sw_state_t;


#endif /* __LIF_TABLE_MNGR_TYPES_H__ */