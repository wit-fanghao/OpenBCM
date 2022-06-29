/*******************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated by fltg from Logical Table mapping files.
 *
 * Tool: $SDK/INTERNAL/fltg/bin/fltg
 *
 * Edits to this file will be lost when it is regenerated.
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */
/* Logical Table Adaptor for component bcmltx */
/* Handler: bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler */
#include <bcmlrd/bcmlrd_types.h>
#include <bcmltd/chip/bcmltd_id.h>
#include <bcmltx/bcmltx_field_demux.h>
#include <bcmdrd/chip/bcm56780_a0_enum.h>
#include <bcmlrd/chip/bcm56780_a0/dna_2_5_13/bcm56780_a0_dna_2_5_13_lrd_xfrm_field_desc.h>


extern const bcmltd_field_desc_t
bcm56780_a0_dna_2_5_13_lrd_field_demux_r_egr_hg3_etype_reservedt_typef_0_src_field_desc_s0[];

static const bcmltd_field_desc_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_dst_field_desc[3] = {
    {
        .field_id  = BCMLTD_INTERNAL_FIELD_BASE + 245,
        .field_idx = 0,
        .minbit    = 48,
        .maxbit    = 49,
        .entry_idx = 0,
        .sym       = "EFSL20_DATA_CONSTANTm.DATAf[49:48]",
        .reserved  = 0
    },
    {
        .field_id  = BCMLTD_INTERNAL_FIELD_BASE + 246,
        .field_idx = 0,
        .minbit    = 56,
        .maxbit    = 61,
        .entry_idx = 0,
        .sym       = "EFSL20_DATA_CONSTANTm.DATAf[61:56]",
        .reserved  = 0
    },
    {
        .field_id  = BCMLTD_INTERNAL_FIELD_BASE + 247,
        .field_idx = 0,
        .minbit    = 64,
        .maxbit    = 65,
        .entry_idx = 0,
        .sym       = "EFSL20_DATA_CONSTANTm.DATAf[65:64]",
        .reserved  = 0
    },
};

static const
bcmltd_field_list_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_src_list_s0 = {
    .field_num = 3,
    .field_array = bcm56780_a0_dna_2_5_13_lrd_field_demux_r_egr_hg3_etype_reservedt_typef_0_src_field_desc_s0
};

static const bcmltd_field_list_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_dst_list_d0 = {
    .field_num = 3,
    .field_array = bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_dst_field_desc
};

static const uint32_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_src_s0[1] = {
    BCM56780_A0_DNA_2_5_13_R_EGR_HG3_ETYPE_RESERVEDt_TYPEf,
};

static const uint32_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_dst_d0[3] = {
    BCMLTD_INTERNAL_FIELD_BASE + 245,
    BCMLTD_INTERNAL_FIELD_BASE + 246,
    BCMLTD_INTERNAL_FIELD_BASE + 247,
};

static const bcmltd_generic_arg_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_comp_data = {
    .sid       = BCM56780_A0_DNA_2_5_13_R_EGR_HG3_ETYPE_RESERVEDt,
    .values    = 0,
    .value     = NULL,
    .user_data = NULL
};

static const bcmltd_transform_arg_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_fwd_arg_s0_d0 = {
    .values      = 0,
    .value       = NULL,
    .tables      = 0,
    .table       = NULL,
    .fields      = 1,
    .field       = bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_src_s0,
    .field_list  = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_src_list_s0,
    .rfields     = 3,
    .rfield      = bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_dst_d0,
    .rfield_list = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_dst_list_d0,
    .comp_data   = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_comp_data
};

static const bcmltd_transform_arg_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_rev_arg_s0_d0 = {
    .values      = 0,
    .value       = NULL,
    .tables      = 0,
    .table       = NULL,
    .fields      = 3,
    .field       = bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_dst_d0,
    .field_list  = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_dst_list_d0,
    .rfields     = 1,
    .rfield      = bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_transform_src_s0,
    .rfield_list = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_src_list_s0,
    .comp_data   = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_comp_data
};

const bcmltd_xfrm_handler_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_fwd_s0_d0 = {
    .transform     = bcmltx_field_demux_transform,
    .arg           = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_fwd_arg_s0_d0
};

const bcmltd_xfrm_handler_t
bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_rev_s0_d0 = {
    .transform     = bcmltx_field_mux_transform,
    .arg           = &bcm56780_a0_dna_2_5_13_lta_bcmltx_field_demux_r_egr_hg3_etype_reservedt_typef_0_xfrm_handler_rev_arg_s0_d0
};

