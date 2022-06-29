/** \file algo/swstate/auto_generated/access/algo_mdb_em_access.h
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

#ifndef __ALGO_MDB_EM_ACCESS_H__
#define __ALGO_MDB_EM_ACCESS_H__

#include <bcm_int/dnx/algo/swstate/auto_generated/types/algo_mdb_em_types.h>
#include <bcm_int/dnx/algo/algo_mdb_em.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr.h>
#include <bcm_int/dnx/algo/template_mngr/template_mngr_internal.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_fields.h>
#include <soc/dnx/dbal/auto_generated/dbal_defines_tables.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_device.h>
#include <soc/dnx/dnx_data/auto_generated/dnx_data_mdb.h>
#include <soc/dnx/mdb_global.h>
/*
 * TYPEDEFs
 */

/**
 * implemented by: mdb_em_format_template_manager_is_init
 */
typedef int (*mdb_em_format_template_manager_is_init_cb)(
    int unit, uint8 *is_init);

/**
 * implemented by: mdb_em_format_template_manager_init
 */
typedef int (*mdb_em_format_template_manager_init_cb)(
    int unit);

/**
 * implemented by: mdb_em_format_template_manager_template_manager_create
 */
typedef int (*mdb_em_format_template_manager_template_manager_create_cb)(
    int unit, uint32 template_manager_idx_0, dnx_algo_template_create_data_t * data, void *extra_arguments);

/**
 * implemented by: mdb_em_format_template_manager_template_manager_allocate_single
 */
typedef int (*mdb_em_format_template_manager_template_manager_allocate_single_cb)(
    int unit, uint32 template_manager_idx_0, uint32 flags, uint8 *profile_data, void *extra_arguments, int *profile, uint8 *first_reference);

/**
 * implemented by: mdb_em_format_template_manager_template_manager_free_single
 */
typedef int (*mdb_em_format_template_manager_template_manager_free_single_cb)(
    int unit, uint32 template_manager_idx_0, int profile, uint8 *last_reference);

/**
 * implemented by: mdb_em_format_template_manager_template_manager_profile_get
 */
typedef int (*mdb_em_format_template_manager_template_manager_profile_get_cb)(
    int unit, uint32 template_manager_idx_0, const uint8 *profile_data, int *profile);

/*
 * STRUCTs
 */

/**
 * This structure holds the access functions for the variable template_manager
 */
typedef struct {
    mdb_em_format_template_manager_template_manager_create_cb create;
    mdb_em_format_template_manager_template_manager_allocate_single_cb allocate_single;
    mdb_em_format_template_manager_template_manager_free_single_cb free_single;
    mdb_em_format_template_manager_template_manager_profile_get_cb profile_get;
} mdb_em_format_template_manager_template_manager_cbs;

/**
 * This structure holds the access functions for the variable mdb_em_format_t
 */
typedef struct {
    mdb_em_format_template_manager_is_init_cb is_init;
    mdb_em_format_template_manager_init_cb init;
    /**
     * Access struct for template_manager
     */
    mdb_em_format_template_manager_template_manager_cbs template_manager;
} mdb_em_format_template_manager_cbs;

/*
 * Global Variables
 */

/*
 * Global Variables
 */

extern mdb_em_format_template_manager_cbs mdb_em_format_template_manager;

#endif /* __ALGO_MDB_EM_ACCESS_H__ */