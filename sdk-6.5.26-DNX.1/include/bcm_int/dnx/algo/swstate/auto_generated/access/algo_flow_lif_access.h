/** \file algo/swstate/auto_generated/access/algo_flow_lif_access.h
 *
 * sw state functions declarations
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

#ifndef __ALGO_FLOW_LIF_ACCESS_H__
#define __ALGO_FLOW_LIF_ACCESS_H__

#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_flow_lif_types.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr.h>
#include <bcm_int/dnx/algo/res_mngr/res_mngr_internal.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/lif_mngr_types.h>
#include <bcm_int/dnx/algo/swstate/auto_generated/types/lif_table_mngr_types.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_tables.h>
#include <soc/dnxc/swstate/callbacks/sw_state_htb_callbacks.h>
#include <soc/dnxc/swstate/types/sw_state_hash_table.h>
/*
 * TYPEDEFs
 */

/**
 * implemented by: algo_flow_lif_is_init
 */
typedef int (*algo_flow_lif_is_init_cb)(
    int unit, uint8 *is_init);

/**
 * implemented by: algo_flow_lif_init
 */
typedef int (*algo_flow_lif_init_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_create
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_create_cb)(
    int unit, sw_state_htbl_init_info_t *init_info, int key_size, int value_size);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_find
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_find_cb)(
    int unit, const void *key, void *value, uint8 *found);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_insert
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_insert_cb)(
    int unit, const void *key, const void *value, uint8 *success);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_get_next
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_get_next_cb)(
    int unit, SW_STATE_HASH_TABLE_ITER *iter, const void *key, const void *value);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_clear
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_clear_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_delete
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_delete_cb)(
    int unit, const void *key);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_set
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_set_cb)(
    int unit, uint32 local_inlif_to_global_lif_map_idx_0, int local_inlif_to_global_lif_map);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_get
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_get_cb)(
    int unit, uint32 local_inlif_to_global_lif_map_idx_0, int *local_inlif_to_global_lif_map);

/**
 * implemented by: algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_alloc
 */
typedef int (*algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);

/**
 * implemented by: algo_flow_lif_inlif_nof_inlif_banks_set
 */
typedef int (*algo_flow_lif_inlif_nof_inlif_banks_set_cb)(
    int unit, uint32 nof_inlif_banks);

/**
 * implemented by: algo_flow_lif_inlif_nof_inlif_banks_get
 */
typedef int (*algo_flow_lif_inlif_nof_inlif_banks_get_cb)(
    int unit, uint32 *nof_inlif_banks);

/**
 * implemented by: algo_flow_lif_inlif_inlif_bank_manager_set
 */
typedef int (*algo_flow_lif_inlif_inlif_bank_manager_set_cb)(
    int unit, uint32 inlif_bank_manager_idx_0, algo_flow_lif_inlif_all_banks_type_e inlif_bank_manager);

/**
 * implemented by: algo_flow_lif_inlif_inlif_bank_manager_get
 */
typedef int (*algo_flow_lif_inlif_inlif_bank_manager_get_cb)(
    int unit, uint32 inlif_bank_manager_idx_0, algo_flow_lif_inlif_all_banks_type_e *inlif_bank_manager);

/**
 * implemented by: algo_flow_lif_inlif_inlif_bank_manager_alloc
 */
typedef int (*algo_flow_lif_inlif_inlif_bank_manager_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);

/**
 * implemented by: algo_flow_lif_inlif_inlif_per_core_bank_manager_alloc
 */
typedef int (*algo_flow_lif_inlif_inlif_per_core_bank_manager_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0, uint32 nof_instances_to_alloc_1);

/**
 * implemented by: algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_set
 */
typedef int (*algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_set_cb)(
    int unit, uint32 inlif_per_core_bank_manager_idx_0, uint32 inlif_per_core_bank_manager_idx_1, algo_flow_lif_inlif_bank_entry_sizes_e bank_entry_sizes);

/**
 * implemented by: algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_get
 */
typedef int (*algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_get_cb)(
    int unit, uint32 inlif_per_core_bank_manager_idx_0, uint32 inlif_per_core_bank_manager_idx_1, algo_flow_lif_inlif_bank_entry_sizes_e *bank_entry_sizes);

/**
 * implemented by: algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_set
 */
typedef int (*algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_set_cb)(
    int unit, uint32 inlif_per_core_bank_manager_idx_0, uint32 inlif_per_core_bank_manager_idx_1, uint32 nof_added_entries);

/**
 * implemented by: algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_get
 */
typedef int (*algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_get_cb)(
    int unit, uint32 inlif_per_core_bank_manager_idx_0, uint32 inlif_per_core_bank_manager_idx_1, uint32 *nof_added_entries);

/**
 * implemented by: algo_flow_lif_inlif_symmetric_info_set
 */
typedef int (*algo_flow_lif_inlif_symmetric_info_set_cb)(
    int unit, uint32 symmetric_info_idx_0, CONST inlif_info_t *symmetric_info);

/**
 * implemented by: algo_flow_lif_inlif_symmetric_info_get
 */
typedef int (*algo_flow_lif_inlif_symmetric_info_get_cb)(
    int unit, uint32 symmetric_info_idx_0, inlif_info_t *symmetric_info);

/**
 * implemented by: algo_flow_lif_inlif_symmetric_info_alloc
 */
typedef int (*algo_flow_lif_inlif_symmetric_info_alloc_cb)(
    int unit, uint32 nof_instances_to_alloc_0);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_create
 */
typedef int (*algo_flow_lif_inlif_per_core_info_create_cb)(
    int unit, sw_state_htbl_init_info_t *init_info);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_find
 */
typedef int (*algo_flow_lif_inlif_per_core_info_find_cb)(
    int unit, const int *key, inlif_info_t *value, uint8 *found);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_insert
 */
typedef int (*algo_flow_lif_inlif_per_core_info_insert_cb)(
    int unit, const int *key, const inlif_info_t *value, uint8 *success);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_get_next
 */
typedef int (*algo_flow_lif_inlif_per_core_info_get_next_cb)(
    int unit, SW_STATE_HASH_TABLE_ITER *iter, const int *key, const inlif_info_t *value);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_clear
 */
typedef int (*algo_flow_lif_inlif_per_core_info_clear_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_delete
 */
typedef int (*algo_flow_lif_inlif_per_core_info_delete_cb)(
    int unit, const int *key);

/**
 * implemented by: algo_flow_lif_inlif_per_core_info_delete_all
 */
typedef int (*algo_flow_lif_inlif_per_core_info_delete_all_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_set
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_set_cb)(
    int unit, uint32 per_core_alloc_idx_0, dnx_algo_res_t per_core_alloc);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_get
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_get_cb)(
    int unit, uint32 per_core_alloc_idx_0, dnx_algo_res_t *per_core_alloc);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_alloc
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_alloc_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_create
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_create_cb)(
    int unit, uint32 per_core_alloc_idx_0, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_allocate_single
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_allocate_single_cb)(
    int unit, uint32 per_core_alloc_idx_0, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_free_single
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_free_single_cb)(
    int unit, uint32 per_core_alloc_idx_0, int element, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_is_allocated
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_is_allocated_cb)(
    int unit, uint32 per_core_alloc_idx_0, int element, uint8 *is_allocated);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_clear
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_clear_cb)(
    int unit, uint32 per_core_alloc_idx_0);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_get_next
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_get_next_cb)(
    int unit, uint32 per_core_alloc_idx_0, int *element);

/**
 * implemented by: algo_flow_lif_inlif_per_core_alloc_nof_allocated_elements_in_range_get
 */
typedef int (*algo_flow_lif_inlif_per_core_alloc_nof_allocated_elements_in_range_get_cb)(
    int unit, uint32 per_core_alloc_idx_0, int range_start, int nof_elements_in_range, int *nof_allocated_elements);

/**
 * implemented by: algo_flow_lif_inlif_nof_per_core_lifs_set
 */
typedef int (*algo_flow_lif_inlif_nof_per_core_lifs_set_cb)(
    int unit, int nof_per_core_lifs);

/**
 * implemented by: algo_flow_lif_inlif_nof_per_core_lifs_get
 */
typedef int (*algo_flow_lif_inlif_nof_per_core_lifs_get_cb)(
    int unit, int *nof_per_core_lifs);

/**
 * implemented by: algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_set
 */
typedef int (*algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_set_cb)(
    int unit, int nof_per_core_lifs_size_in_bits);

/**
 * implemented by: algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_get
 */
typedef int (*algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_get_cb)(
    int unit, int *nof_per_core_lifs_size_in_bits);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_set
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_set_cb)(
    int unit, dnx_algo_res_t flow_ingress_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_get
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_get_cb)(
    int unit, dnx_algo_res_t *flow_ingress_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_create
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_allocate_single
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_free_single
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_ingress_virtual_gport_id_is_allocated
 */
typedef int (*algo_flow_lif_flow_ingress_virtual_gport_id_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_set
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_set_cb)(
    int unit, dnx_algo_res_t flow_egress_esem_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_get
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_get_cb)(
    int unit, dnx_algo_res_t *flow_egress_esem_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_create
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_allocate_single
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_free_single
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_egress_esem_virtual_gport_id_is_allocated
 */
typedef int (*algo_flow_lif_flow_egress_esem_virtual_gport_id_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_set
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_set_cb)(
    int unit, dnx_algo_res_t flow_egress_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_get
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_get_cb)(
    int unit, dnx_algo_res_t *flow_egress_virtual_gport_id);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_create
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_create_cb)(
    int unit, dnx_algo_res_create_data_t * data, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_allocate_single
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_allocate_single_cb)(
    int unit, uint32 flags, void *extra_arguments, int *element);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_free_single
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_free_single_cb)(
    int unit, int element, void *extra_arguments);

/**
 * implemented by: algo_flow_lif_flow_egress_virtual_gport_id_is_allocated
 */
typedef int (*algo_flow_lif_flow_egress_virtual_gport_id_is_allocated_cb)(
    int unit, int element, uint8 *is_allocated);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_create
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_create_cb)(
    int unit, sw_state_htbl_init_info_t *init_info);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_find
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_find_cb)(
    int unit, const int *key, local_lif_info_t *value, uint8 *found);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_insert
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_insert_cb)(
    int unit, const int *key, const local_lif_info_t *value, uint8 *success);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_get_next
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_get_next_cb)(
    int unit, SW_STATE_HASH_TABLE_ITER *iter, const int *key, const local_lif_info_t *value);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_clear
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_clear_cb)(
    int unit);

/**
 * implemented by: algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_delete
 */
typedef int (*algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_delete_cb)(
    int unit, const int *key);

/*
 * STRUCTs
 */

/**
 * This structure holds the access functions for the variable global_lif_to_local_inlif_htb
 */
typedef struct {
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_create_cb create;
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_find_cb find;
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_insert_cb insert;
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_get_next_cb get_next;
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_clear_cb clear;
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_delete_cb delete;
} algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_cbs;

/**
 * This structure holds the access functions for the variable local_inlif_to_global_lif_map
 */
typedef struct {
    algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_set_cb set;
    algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_get_cb get;
    algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_alloc_cb alloc;
} algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_cbs;

/**
 * This structure holds the access functions for the variable inlif_mapping_info_t
 */
typedef struct {
    /**
     * Access struct for global_lif_to_local_inlif_htb
     */
    algo_flow_lif_inlif_inlif_mapping_global_lif_to_local_inlif_htb_cbs global_lif_to_local_inlif_htb;
    /**
     * Access struct for local_inlif_to_global_lif_map
     */
    algo_flow_lif_inlif_inlif_mapping_local_inlif_to_global_lif_map_cbs local_inlif_to_global_lif_map;
} algo_flow_lif_inlif_inlif_mapping_cbs;

/**
 * This structure holds the access functions for the variable nof_inlif_banks
 */
typedef struct {
    algo_flow_lif_inlif_nof_inlif_banks_set_cb set;
    algo_flow_lif_inlif_nof_inlif_banks_get_cb get;
} algo_flow_lif_inlif_nof_inlif_banks_cbs;

/**
 * This structure holds the access functions for the variable inlif_bank_manager
 */
typedef struct {
    algo_flow_lif_inlif_inlif_bank_manager_set_cb set;
    algo_flow_lif_inlif_inlif_bank_manager_get_cb get;
    algo_flow_lif_inlif_inlif_bank_manager_alloc_cb alloc;
} algo_flow_lif_inlif_inlif_bank_manager_cbs;

/**
 * This structure holds the access functions for the variable bank_entry_sizes
 */
typedef struct {
    algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_set_cb set;
    algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_get_cb get;
} algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_cbs;

/**
 * This structure holds the access functions for the variable nof_added_entries
 */
typedef struct {
    algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_set_cb set;
    algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_get_cb get;
} algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_cbs;

/**
 * This structure holds the access functions for the variable inlif_bank_manager_info_t
 */
typedef struct {
    algo_flow_lif_inlif_inlif_per_core_bank_manager_alloc_cb alloc;
    /**
     * Access struct for bank_entry_sizes
     */
    algo_flow_lif_inlif_inlif_per_core_bank_manager_bank_entry_sizes_cbs bank_entry_sizes;
    /**
     * Access struct for nof_added_entries
     */
    algo_flow_lif_inlif_inlif_per_core_bank_manager_nof_added_entries_cbs nof_added_entries;
} algo_flow_lif_inlif_inlif_per_core_bank_manager_cbs;

/**
 * This structure holds the access functions for the variable inlif_info_t
 */
typedef struct {
    algo_flow_lif_inlif_symmetric_info_set_cb set;
    algo_flow_lif_inlif_symmetric_info_get_cb get;
    algo_flow_lif_inlif_symmetric_info_alloc_cb alloc;
} algo_flow_lif_inlif_symmetric_info_cbs;

/**
 * This structure holds the access functions for the variable per_core_info
 */
typedef struct {
    algo_flow_lif_inlif_per_core_info_create_cb create;
    algo_flow_lif_inlif_per_core_info_find_cb find;
    algo_flow_lif_inlif_per_core_info_insert_cb insert;
    algo_flow_lif_inlif_per_core_info_get_next_cb get_next;
    algo_flow_lif_inlif_per_core_info_clear_cb clear;
    algo_flow_lif_inlif_per_core_info_delete_cb delete;
    algo_flow_lif_inlif_per_core_info_delete_all_cb delete_all;
} algo_flow_lif_inlif_per_core_info_cbs;

/**
 * This structure holds the access functions for the variable per_core_alloc
 */
typedef struct {
    algo_flow_lif_inlif_per_core_alloc_set_cb set;
    algo_flow_lif_inlif_per_core_alloc_get_cb get;
    algo_flow_lif_inlif_per_core_alloc_alloc_cb alloc;
    algo_flow_lif_inlif_per_core_alloc_create_cb create;
    algo_flow_lif_inlif_per_core_alloc_allocate_single_cb allocate_single;
    algo_flow_lif_inlif_per_core_alloc_free_single_cb free_single;
    algo_flow_lif_inlif_per_core_alloc_is_allocated_cb is_allocated;
    algo_flow_lif_inlif_per_core_alloc_clear_cb clear;
    algo_flow_lif_inlif_per_core_alloc_get_next_cb get_next;
    algo_flow_lif_inlif_per_core_alloc_nof_allocated_elements_in_range_get_cb nof_allocated_elements_in_range_get;
} algo_flow_lif_inlif_per_core_alloc_cbs;

/**
 * This structure holds the access functions for the variable nof_per_core_lifs
 */
typedef struct {
    algo_flow_lif_inlif_nof_per_core_lifs_set_cb set;
    algo_flow_lif_inlif_nof_per_core_lifs_get_cb get;
} algo_flow_lif_inlif_nof_per_core_lifs_cbs;

/**
 * This structure holds the access functions for the variable nof_per_core_lifs_size_in_bits
 */
typedef struct {
    algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_set_cb set;
    algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_get_cb get;
} algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_cbs;

/**
 * This structure holds the access functions for the variable algo_flow_inlif_t
 */
typedef struct {
    /**
     * Access struct for inlif_mapping
     */
    algo_flow_lif_inlif_inlif_mapping_cbs inlif_mapping;
    /**
     * Access struct for nof_inlif_banks
     */
    algo_flow_lif_inlif_nof_inlif_banks_cbs nof_inlif_banks;
    /**
     * Access struct for inlif_bank_manager
     */
    algo_flow_lif_inlif_inlif_bank_manager_cbs inlif_bank_manager;
    /**
     * Access struct for inlif_per_core_bank_manager
     */
    algo_flow_lif_inlif_inlif_per_core_bank_manager_cbs inlif_per_core_bank_manager;
    /**
     * Access struct for symmetric_info
     */
    algo_flow_lif_inlif_symmetric_info_cbs symmetric_info;
    /**
     * Access struct for per_core_info
     */
    algo_flow_lif_inlif_per_core_info_cbs per_core_info;
    /**
     * Access struct for per_core_alloc
     */
    algo_flow_lif_inlif_per_core_alloc_cbs per_core_alloc;
    /**
     * Access struct for nof_per_core_lifs
     */
    algo_flow_lif_inlif_nof_per_core_lifs_cbs nof_per_core_lifs;
    /**
     * Access struct for nof_per_core_lifs_size_in_bits
     */
    algo_flow_lif_inlif_nof_per_core_lifs_size_in_bits_cbs nof_per_core_lifs_size_in_bits;
} algo_flow_lif_inlif_cbs;

/**
 * This structure holds the access functions for the variable flow_ingress_virtual_gport_id
 */
typedef struct {
    algo_flow_lif_flow_ingress_virtual_gport_id_set_cb set;
    algo_flow_lif_flow_ingress_virtual_gport_id_get_cb get;
    algo_flow_lif_flow_ingress_virtual_gport_id_create_cb create;
    algo_flow_lif_flow_ingress_virtual_gport_id_allocate_single_cb allocate_single;
    algo_flow_lif_flow_ingress_virtual_gport_id_free_single_cb free_single;
    algo_flow_lif_flow_ingress_virtual_gport_id_is_allocated_cb is_allocated;
} algo_flow_lif_flow_ingress_virtual_gport_id_cbs;

/**
 * This structure holds the access functions for the variable flow_egress_esem_virtual_gport_id
 */
typedef struct {
    algo_flow_lif_flow_egress_esem_virtual_gport_id_set_cb set;
    algo_flow_lif_flow_egress_esem_virtual_gport_id_get_cb get;
    algo_flow_lif_flow_egress_esem_virtual_gport_id_create_cb create;
    algo_flow_lif_flow_egress_esem_virtual_gport_id_allocate_single_cb allocate_single;
    algo_flow_lif_flow_egress_esem_virtual_gport_id_free_single_cb free_single;
    algo_flow_lif_flow_egress_esem_virtual_gport_id_is_allocated_cb is_allocated;
} algo_flow_lif_flow_egress_esem_virtual_gport_id_cbs;

/**
 * This structure holds the access functions for the variable flow_egress_virtual_gport_id
 */
typedef struct {
    algo_flow_lif_flow_egress_virtual_gport_id_set_cb set;
    algo_flow_lif_flow_egress_virtual_gport_id_get_cb get;
    algo_flow_lif_flow_egress_virtual_gport_id_create_cb create;
    algo_flow_lif_flow_egress_virtual_gport_id_allocate_single_cb allocate_single;
    algo_flow_lif_flow_egress_virtual_gport_id_free_single_cb free_single;
    algo_flow_lif_flow_egress_virtual_gport_id_is_allocated_cb is_allocated;
} algo_flow_lif_flow_egress_virtual_gport_id_cbs;

/**
 * This structure holds the access functions for the variable valid_fields_per_no_local_lif_egress_htb
 */
typedef struct {
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_create_cb create;
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_find_cb find;
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_insert_cb insert;
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_get_next_cb get_next;
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_clear_cb clear;
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_delete_cb delete;
} algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_cbs;

/**
 * This structure holds the access functions for the variable algo_flow_lif_t
 */
typedef struct {
    algo_flow_lif_is_init_cb is_init;
    algo_flow_lif_init_cb init;
    /**
     * Access struct for inlif
     */
    algo_flow_lif_inlif_cbs inlif;
    /**
     * Access struct for flow_ingress_virtual_gport_id
     */
    algo_flow_lif_flow_ingress_virtual_gport_id_cbs flow_ingress_virtual_gport_id;
    /**
     * Access struct for flow_egress_esem_virtual_gport_id
     */
    algo_flow_lif_flow_egress_esem_virtual_gport_id_cbs flow_egress_esem_virtual_gport_id;
    /**
     * Access struct for flow_egress_virtual_gport_id
     */
    algo_flow_lif_flow_egress_virtual_gport_id_cbs flow_egress_virtual_gport_id;
    /**
     * Access struct for valid_fields_per_no_local_lif_egress_htb
     */
    algo_flow_lif_valid_fields_per_no_local_lif_egress_htb_cbs valid_fields_per_no_local_lif_egress_htb;
} algo_flow_lif_cbs;

/*
 * Global Variables
 */

/*
 * FUNCTIONs
 */

/*
 *
 * get_name function for enum type algo_flow_lif_inlif_all_banks_type_e
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
const char *
algo_flow_lif_inlif_all_banks_type_e_get_name(algo_flow_lif_inlif_all_banks_type_e value);
/*
 *
 * get_name function for enum type algo_flow_lif_inlif_bank_entry_sizes_e
 * AUTO-GENERATED - DO NOT MODIFY
 *
 */
const char *
algo_flow_lif_inlif_bank_entry_sizes_e_get_name(algo_flow_lif_inlif_bank_entry_sizes_e value);
/*
 * Global Variables
 */

extern algo_flow_lif_cbs algo_flow_lif;

#endif /* __ALGO_FLOW_LIF_ACCESS_H__ */