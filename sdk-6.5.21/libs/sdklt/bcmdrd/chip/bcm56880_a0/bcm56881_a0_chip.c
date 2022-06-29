/*******************************************************************************
 *
 * DO NOT EDIT THIS FILE!
 * This file is auto-generated from the registers file.
 * Edits to this file will be lost when it is regenerated.
 * Tool: INTERNAL/regs/xgs/generate-chip.pl
 *
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2020 Broadcom Inc. All rights reserved.
 */

#include <bcmdrd/bcmdrd_types.h>
#include <bcmdrd/bcmdrd_chip.h>
#include <bcmdrd/bcmdrd_field.h>
#include <bcmdrd/chip/bcm56880_a0_defs.h>
#include <bcmdrd/chip/bcm56880_a0_sig.h>

/* Block types */
extern const char *bcm56880_a0_drd_blktype_names[];
extern const int bcm56880_a0_drd_blktype_start_idx[];

/* Block structures */
extern bcmdrd_block_t bcm56880_a0_drd_blocks[];

/* Symbol table */
#if BCMDRD_CONFIG_INCLUDE_CHIP_SYMBOLS == 1
extern bcmdrd_symbols_t bcm56880_a0_drd_symbols;
#endif

/* Declare function first to prevent compiler warnings */
extern uint32_t
bcm56880_a0_drd_blockport_addr(int block, int lane, uint32_t offset,
                               uint32_t idx);

/* Declare function first to prevent compiler warnings */
extern int
bcm56880_a0_drd_addr_decode(const bcmdrd_symbol_t *symbol,
                            int block, uint32_t addr,
                            uint32_t *idx, uint32_t *lane);

/* Declare function first to prevent compiler warnings */
extern bcmdrd_port_num_domain_t
bcm56880_a0_drd_port_num_domain(bcmdrd_sid_t sid, int blktype);

/* Declare function first to prevent compiler warnings */
extern int
bcm56880_a0_drd_blktype_from_porttype(bcmdrd_port_type_t ptype);

static bcmdrd_chip_param_t bcm56881_a0_chip_params[] = {
    { NULL }
};

static bcmdrd_chip_mod_t bcm56881_a0_chip_mods[] = {
    { .sid = L3_DEFIP_ALPM_LEVEL3_B0m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B0_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B0_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B1m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B1_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B1_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B2m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B2_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B2_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B3m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B3_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B3_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B4m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B4_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B4_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B5m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B5_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B5_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B6m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B6_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B6_SINGLEm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B7m, .index_max = { true, 8191 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B7_ECCm, .index_max = { true, 32767 } },
    { .sid = L3_DEFIP_ALPM_LEVEL3_B7_SINGLEm, .index_max = { true, 32767 } },
    { .sid = MEMDB_IFTA100_MEM10_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM10_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM11_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM2_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM3_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM6_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_0_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_0_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_0_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_0_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_1_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_1_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_1_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_1_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_2_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_2_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_2_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_2_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_3_DATA_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_3_DATA_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_3_ONLYm, .valid = { true, 0 } },
    { .sid = MEMDB_IFTA100_MEM7_3_ONLY_SER_CONTROLr, .valid = { true, 0 } },
    { .sid = IFTA90_E2T_00_B0_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_00_B0_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_00_B0_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_00_B0_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_00_B0_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_00_B1_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_00_B1_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_00_B1_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_00_B1_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_00_B1_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_01_B0_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_01_B0_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_01_B0_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_01_B0_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_01_B0_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_01_B1_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_01_B1_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_01_B1_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_01_B1_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_01_B1_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_02_B0_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_02_B0_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_02_B0_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_02_B0_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_02_B0_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_02_B1_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_02_B1_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_02_B1_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_02_B1_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_02_B1_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_03_B0_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_03_B0_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_03_B0_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_03_B0_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_03_B0_SINGLEm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_03_B1_DOUBLEm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_03_B1_ECCm, .index_max = { true, 32767 } },
    { .sid = IFTA90_E2T_03_B1_LPm, .index_max = { true, 16383 } },
    { .sid = IFTA90_E2T_03_B1_QUADm, .index_max = { true, 8191 } },
    { .sid = IFTA90_E2T_03_B1_SINGLEm, .index_max = { true, 32767 } },
    { .sid = BCMDRD_INVALID_ID }
};

static bcmdrd_chip_profile_t bcm56881_a0_chip_profile = {
    bcm56881_a0_chip_params,
    bcm56881_a0_chip_mods
};

/* Declare function first to prevent compiler warnings */
extern uint32_t
bcm56880_a0_drd_pipe_info(const bcmdrd_chip_info_t *cinfo,
                          bcmdrd_pipe_info_t *pi,
                          bcmdrd_pipe_info_type_t pi_type);

/* Variable register array info */
extern bcmdrd_numel_info_t bcm56880_a0_drd_numel_info;

/* Chip information structure */
bcmdrd_chip_info_t bcm56881_a0_drd_chip_info = {

    /* Register file digest. */
    BCM56880_A0_SIGNATURE,

    /* HMI protocol (typically S-bus address format version). */
    4,

    /* HMI block (typically CMIC block number). */
    CMIC_BLOCK,

    /* Other (non-HMI) block types */
    16,
    bcm56880_a0_drd_blktype_names,
    bcm56880_a0_drd_blktype_start_idx,

    /* Other (non-HMI) blocks */
    49,
    bcm56880_a0_drd_blocks,

    /* Valid ports for this chip */
    {
        /* Valid physical ports for this chip */
        {{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0x000001ff}},
        /* Valid logical ports for this chip */
        {{0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff}},
        /* Valid MMU ports for this chip */
        {{0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff, 0x000fffff}}
    },

    /* Chip flags */
    BCMDRD_CHIP_FLAG_VARIANT |
    CHIP_FLAG_X11E |
    0,

#if BCMDRD_CONFIG_INCLUDE_CHIP_SYMBOLS == 1
    /* Use the static per-chip symbol tables */
    &bcm56880_a0_drd_symbols,
#endif

    /* Variable register array info */
    &bcm56880_a0_drd_numel_info,

    /* Chip profile */
    &bcm56881_a0_chip_profile,

    /* Address calculation override */
    bcm56880_a0_drd_blockport_addr,

    /* Address decoder override */
    bcm56880_a0_drd_addr_decode,

    /* Port number domain */
    bcm56880_a0_drd_port_num_domain,

    /* Get device-specific block type from generic port type */
    bcm56880_a0_drd_blktype_from_porttype,

    /* Pipe info */
    bcm56880_a0_drd_pipe_info

};