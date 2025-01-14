/***********************************************************************************
 *                                                                                 *
 * Copyright: (c) 2021 Broadcom.                                                   *
 * Broadcom Proprietary and Confidential. All rights reserved.                     *
 *                                                                                 *
 ***********************************************************************************/

/***********************************************************************************
 ***********************************************************************************
 *  File Name     :  osprey7_v2l8p2_access.c                                           *
 *  Created On    :  03 Nov 2015                                                   *
 *  Created By    :  Brent Roberts                                                 *
 *  Description   :  APIs to implement Serdes uC access                            *
 *  Revision      :   *
 *                                                                                 *
 ***********************************************************************************
 ***********************************************************************************/

#include "osprey7_v2l8p2_access.h"
#include "osprey7_v2l8p2_common.h"
#include "osprey7_v2l8p2_functions.h"
#include "osprey7_v2l8p2_internal.h"
#include "osprey7_v2l8p2_internal_error.h"
#include "osprey7_v2l8p2_select_defns.h"
#include "osprey7_v2l8p2_config.h"


/** @file
 *
 */




/******************************************************/
/*  Commands through Serdes FW DSC Command Interface  */
/******************************************************/

err_code_t osprey7_v2l8p2_pmd_uc_cmd_return_immediate(srds_access_t *sa__, enum srds_pmd_uc_cmd_enum cmd, uint8_t supp_info) {
  INIT_SRDS_ERR_CODE
  err_code_t err_code;
  uint16_t   cmddata;

  err_code = osprey7_v2l8p2_INTERNAL_poll_uc_dsc_ready_for_cmd_equals_1(sa__, 1, cmd); /* Poll for uc_dsc_ready_for_cmd = 1 to indicate osprey7_v2l8p2 ready for command */
  if (err_code) {
    EFUN_PRINTF(("ERROR : DSC ready for command timed out (before cmd) cmd = %d, supp_info = x%02x err=%d !\n", cmd, supp_info, err_code));
    return (err_code);
  }
  /*EFUN(wr_uc_dsc_supp_info(supp_info)); */                   /* Supplement info field */
  /*EFUN(wr_uc_dsc_error_found(0x0)    ); */                   /* Clear error found field */
  /*EFUN(wr_uc_dsc_gp_uc_req(cmd)      ); */                   /* Set command code */
  /*EFUN(wr_uc_dsc_ready_for_cmd(0x0)  ); */                   /* Issue command, by clearing "ready for command" field */
  cmddata = (uint16_t)(((uint16_t)supp_info)<<8) | (uint16_t)cmd;        /* Combine writes to single write instead of 4 RMW */

  EFUN(reg_wr_DSC_A_DSC_UC_CTRL(cmddata));

  return(ERR_CODE_NONE);
}

err_code_t osprey7_v2l8p2_pmd_uc_cmd(srds_access_t *sa__, enum srds_pmd_uc_cmd_enum cmd, uint8_t supp_info, uint32_t timeout_ms) {
  INIT_SRDS_ERR_CODE
  EFUN(osprey7_v2l8p2_pmd_uc_cmd_return_immediate(sa__, cmd, supp_info));    /* Invoke osprey7_v2l8p2_uc_cmd and return control immediately */
  EFUN(osprey7_v2l8p2_INTERNAL_poll_uc_dsc_ready_for_cmd_equals_1(sa__, timeout_ms, cmd)); /* Poll for uc_dsc_ready_for_cmd = 1 to indicate osprey7_v2l8p2 ready for command */
  return(ERR_CODE_NONE);
}


err_code_t osprey7_v2l8p2_pmd_uc_cmd_with_data_return_immediate(srds_access_t *sa__, enum srds_pmd_uc_cmd_enum cmd, uint8_t supp_info, uint16_t data) {
  INIT_SRDS_ERR_CODE
  err_code_t err_code;
  uint16_t   cmddata;

  err_code = osprey7_v2l8p2_INTERNAL_poll_uc_dsc_ready_for_cmd_equals_1(sa__, 1, cmd); /* Poll for uc_dsc_ready_for_cmd = 1 to indicate osprey7_v2l8p2 ready for command */
  if (err_code) {
     EFUN_PRINTF(("ERROR : DSC ready for command timed out (before cmd) cmd = %d, supp_info = x%02x, data = x%04x err=%d !\n", cmd, supp_info, data,err_code));
    return (err_code);
  }

  EFUN(wr_uc_dsc_data(data));                                  /* Write value written to uc_dsc_data field */
  /*EFUN(wr_uc_dsc_supp_info(supp_info)); */                   /* Supplement info field */
  /*EFUN(wr_uc_dsc_error_found(0x0));     */                   /* Clear error found field */
  /*EFUN(wr_uc_dsc_gp_uc_req(cmd));       */                   /* Set command code */
  /*EFUN(wr_uc_dsc_ready_for_cmd(0x0));   */                   /* Issue command, by clearing "ready for command" field */
  cmddata = (uint16_t)(((uint16_t)supp_info)<<8) | (uint16_t)cmd;        /* Combine writes to single write instead of 4 RMW */

  EFUN(reg_wr_DSC_A_DSC_UC_CTRL(cmddata));

  return(ERR_CODE_NONE);
}


err_code_t osprey7_v2l8p2_pmd_uc_cmd_with_data(srds_access_t *sa__, enum srds_pmd_uc_cmd_enum cmd, uint8_t supp_info, uint16_t data, uint32_t timeout_ms) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_pmd_uc_cmd_with_data_return_immediate(sa__, cmd, supp_info, data)); /* Invoke osprey7_v2l8p2_uc_cmd and return control immediately */

    EFUN(osprey7_v2l8p2_INTERNAL_poll_uc_dsc_ready_for_cmd_equals_1(sa__, timeout_ms, cmd)); /* Poll for uc_dsc_ready_for_cmd = 1 to indicate osprey7_v2l8p2 ready for command */
    return(ERR_CODE_NONE);
}

err_code_t osprey7_v2l8p2_pmd_uc_control_return_immediate(srds_access_t *sa__, enum srds_pmd_uc_ctrl_cmd_enum control) {
  return(osprey7_v2l8p2_pmd_uc_cmd_return_immediate(sa__, CMD_UC_CTRL, (uint8_t) control));
}

err_code_t osprey7_v2l8p2_pmd_uc_control(srds_access_t *sa__, enum srds_pmd_uc_ctrl_cmd_enum control, uint32_t timeout_ms) {
  return(osprey7_v2l8p2_pmd_uc_cmd(sa__, CMD_UC_CTRL, (uint8_t) control, timeout_ms));
}

err_code_t osprey7_v2l8p2_pmd_uc_diag_cmd(srds_access_t *sa__, enum srds_pmd_uc_diag_cmd_enum control, uint32_t timeout_ms) {
  return(osprey7_v2l8p2_pmd_uc_cmd(sa__, CMD_DIAG_EN, (uint8_t) control, timeout_ms));
}

/* Micro RAM Lane Byte Read */
uint8_t osprey7_v2l8p2_rdbl_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
    INIT_SRDS_ERR_CODE
    uint8_t rddata;
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if(!err_code_p) {
        return(0);
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);


        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_lane(sa__, addr,lane);

        EPSTM(rddata = osprey7_v2l8p2_rdb_uc_ram(sa__, err_code_p, lane_addr_offset)); /* Use Micro register interface for reading RAM */
        return (rddata);

    }
}

/* Micro RAM Lane Byte Signed Read */
int8_t osprey7_v2l8p2_rdbls_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int8_t) osprey7_v2l8p2_rdbl_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Lane Word Read */
uint16_t osprey7_v2l8p2_rdwl_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
    INIT_SRDS_ERR_CODE
    uint16_t rddata;
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if(!err_code_p) {
        return(0);
    }
    if (addr%2 != 0) {                                                                /* Validate even address */
        *err_code_p = ERR_CODE_INVALID_RAM_ADDR;
        return (0);
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);


        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_lane(sa__,addr,lane);
        EPSTM(rddata = osprey7_v2l8p2_rdw_uc_ram(sa__, err_code_p, lane_addr_offset)); /* Use Micro register interface for reading RAM */

        return (rddata);
    }
}


/* Micro RAM Lane Word Signed Read */
int16_t osprey7_v2l8p2_rdwls_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int16_t) osprey7_v2l8p2_rdwl_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Lane Byte Write */
err_code_t osprey7_v2l8p2_wrbl_uc_var(srds_access_t *sa__, uint16_t addr, uint8_t wr_val)
{
    uint32_t lane_addr_offset = 0;
    uint8_t lane;



    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_lane(sa__,addr,lane);


        return (osprey7_v2l8p2_wrb_uc_ram(sa__, lane_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
    }
}

/* Micro RAM Lane Byte Signed Write */
err_code_t osprey7_v2l8p2_wrbls_uc_var(srds_access_t *sa__, uint16_t addr, int8_t wr_val) {
  return (osprey7_v2l8p2_wrbl_uc_var(sa__, addr, (uint8_t)wr_val));
}

/* Micro RAM Lane Word Write */
err_code_t osprey7_v2l8p2_wrwl_uc_var(srds_access_t *sa__, uint16_t addr, uint16_t wr_val)
{
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if (addr%2 != 0) {                                                                /* Validate even address */
        return (osprey7_v2l8p2_error(sa__, ERR_CODE_INVALID_RAM_ADDR));
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_lane(sa__,addr,lane);

        return (osprey7_v2l8p2_wrw_uc_ram(sa__, lane_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
    }
}

/* Micro RAM Lane Word Signed Write */
err_code_t osprey7_v2l8p2_wrwls_uc_var(srds_access_t *sa__, uint16_t addr, int16_t wr_val) {
  return (osprey7_v2l8p2_wrwl_uc_var(sa__, addr, (uint16_t)wr_val));
}

/* Micro RAM Lane Double Word Write */
err_code_t osprey7_v2l8p2_wrdwl_uc_var(srds_access_t *sa__, uint16_t addr, uint32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrwl_uc_var(sa__,addr,(uint16_t)(wr_val&0xFFFF)));
    EFUN(osprey7_v2l8p2_wrwl_uc_var(sa__,(uint16_t)(addr + 0x2),(uint16_t)((wr_val>>16)&0xFFFF)));
    return ERR_CODE_NONE;
}

/* Micro RAM Lane Double Word Signed Write */
err_code_t osprey7_v2l8p2_wrdwls_uc_var(srds_access_t *sa__, uint16_t addr, int32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrdwl_uc_var(sa__, addr, (uint32_t)wr_val));
    return ERR_CODE_NONE;
}

/* Micro RAM Lane Static/Persistent Byte Read */
uint8_t osprey7_v2l8p2_rdblp_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
    INIT_SRDS_ERR_CODE
    uint8_t rddata;
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if(!err_code_p) {
        return(0);
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);


        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_static_addr_from_lane(sa__, addr,lane);
        EPSTM(rddata = osprey7_v2l8p2_rdb_uc_ram(sa__, err_code_p, lane_addr_offset)); /* Use Micro register interface for reading RAM */

        return (rddata);
    }
}
/* Micro RAM Lane Static/Persistent Byte Signed Read */
int8_t osprey7_v2l8p2_rdblps_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int8_t) osprey7_v2l8p2_rdblp_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Lane Static/Persistent Word Read */
uint16_t osprey7_v2l8p2_rdwlp_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
    INIT_SRDS_ERR_CODE
    uint16_t rddata;
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if(!err_code_p) {
        return(0);
    }
    if (addr%2 != 0) {                                                                /* Validate even address */
        *err_code_p = ERR_CODE_INVALID_RAM_ADDR;
        return (0);
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);


        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_static_addr_from_lane(sa__,addr,lane);
        EPSTM(rddata = osprey7_v2l8p2_rdw_uc_ram(sa__, err_code_p, lane_addr_offset)); /* Use Micro register interface for reading RAM */
        return (rddata);
    }
}
/* Micro RAM Lane Static/Persistent Word Signed Read */
int16_t osprey7_v2l8p2_rdwlps_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int16_t) osprey7_v2l8p2_rdwlp_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Lane Static/Persistent Byte Write */
err_code_t osprey7_v2l8p2_wrblp_uc_var(srds_access_t *sa__, uint16_t addr, uint8_t wr_val)
{
    uint32_t lane_addr_offset = 0;
    uint8_t lane;


    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_static_addr_from_lane(sa__,addr,lane);

        return (osprey7_v2l8p2_wrb_uc_ram(sa__, lane_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
    }
}
/* Micro RAM Lane Static/Persistent Byte Signed Write */
err_code_t osprey7_v2l8p2_wrblps_uc_var(srds_access_t *sa__, uint16_t addr, int8_t wr_val) {
  return (osprey7_v2l8p2_wrblp_uc_var(sa__, addr, (uint8_t)wr_val));
}

/* Micro RAM Lane Static/Persistent Word Write */
err_code_t osprey7_v2l8p2_wrwlp_uc_var(srds_access_t *sa__, uint16_t addr, uint16_t wr_val)
{
    uint32_t lane_addr_offset = 0;
    uint8_t lane;

    if (addr%2 != 0) {                                                                /* Validate even address */
        return (osprey7_v2l8p2_error(sa__, ERR_CODE_INVALID_RAM_ADDR));
    }

    {
        lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
        lane_addr_offset = _osprey7_v2l8p2_INTERNAL_get_static_addr_from_lane(sa__,addr,lane);

        return (osprey7_v2l8p2_wrw_uc_ram(sa__, lane_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
    }
}
/* Micro RAM Lane Static/Persistent Word Signed Write */
err_code_t osprey7_v2l8p2_wrwlps_uc_var(srds_access_t *sa__, uint16_t addr, int16_t wr_val) {
  return (osprey7_v2l8p2_wrwlp_uc_var(sa__, addr, (uint16_t)wr_val));
}


/* Micro RAM Lane Static/Persistent Double Word Write */
err_code_t osprey7_v2l8p2_wrdwlp_uc_var(srds_access_t *sa__, uint16_t addr, uint32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrwlp_uc_var(sa__,addr,(uint16_t)(wr_val&0xFFFF)));
    EFUN(osprey7_v2l8p2_wrwlp_uc_var(sa__,(uint16_t)(addr + 0x2),(uint16_t)((wr_val>>16)&0xFFFF)));
    return ERR_CODE_NONE;
}

/* Micro RAM Lane Static/Persistent Double Word Signed Write */
err_code_t osprey7_v2l8p2_wrdwlps_uc_var(srds_access_t *sa__, uint16_t addr, int32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrdwlp_uc_var(sa__, addr, (uint32_t)wr_val));
    return ERR_CODE_NONE;
}



/* Micro RAM UC Byte Read */
uint8_t osprey7_v2l8p2_rdbuc_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  INIT_SRDS_ERR_CODE
  uint8_t  rddata;
  uint32_t uc_addr_offset = 0;
  uint8_t  lane;

  if(!err_code_p) {
      return(0);
  }

  lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);

  uc_addr_offset = _osprey7_v2l8p2_INTERNAL_get_uc_addr_from_lane(sa__, addr,lane);
  EPSTM(rddata = osprey7_v2l8p2_rdb_uc_ram(sa__, err_code_p, uc_addr_offset)); /* Use Micro register interface for reading RAM */
  return (rddata);
}

/* Micro RAM UC Byte Signed Read */
int8_t osprey7_v2l8p2_rdbucs_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int8_t) osprey7_v2l8p2_rdbuc_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM UC Word Read */
uint16_t osprey7_v2l8p2_rdwuc_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  INIT_SRDS_ERR_CODE
  uint16_t rddata;
  uint32_t uc_addr_offset = 0;
  uint8_t  lane;

  if(!err_code_p) {
      return(0);
  }
  if (addr%2 != 0) {                                                                /* Validate even address */
      *err_code_p = ERR_CODE_INVALID_RAM_ADDR;
      return (0);
  }

  lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);


  uc_addr_offset = _osprey7_v2l8p2_INTERNAL_get_uc_addr_from_lane(sa__, addr,lane);
  EPSTM(rddata = osprey7_v2l8p2_rdw_uc_ram(sa__, err_code_p, uc_addr_offset)); /* Use Micro register interface for reading RAM */

  return (rddata);
}


/* Micro RAM UC Word Signed Read */
int16_t osprey7_v2l8p2_rdwucs_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint16_t addr) {
  return ((int16_t) osprey7_v2l8p2_rdwuc_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM UC Byte Write */
err_code_t osprey7_v2l8p2_wrbuc_uc_var(srds_access_t *sa__, uint16_t addr, uint8_t wr_val) {

  uint32_t uc_addr_offset = 0;
  uint8_t  lane;

  lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
  uc_addr_offset = _osprey7_v2l8p2_INTERNAL_get_uc_addr_from_lane(sa__, addr,lane);

  return (osprey7_v2l8p2_wrb_uc_ram(sa__, uc_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
}

/* Micro RAM UC Byte Signed Write */
err_code_t osprey7_v2l8p2_wrbucs_uc_var(srds_access_t *sa__, uint16_t addr, int8_t wr_val) {
  return (osprey7_v2l8p2_wrbuc_uc_var(sa__, addr, (uint8_t)wr_val));
}

/* Micro RAM UC Word Write */
err_code_t osprey7_v2l8p2_wrwuc_uc_var(srds_access_t *sa__, uint16_t addr, uint16_t wr_val) {
  uint32_t uc_addr_offset = 0;
  uint8_t  lane;

  if (addr%2 != 0) {                                                                /* Validate even address */
      return (osprey7_v2l8p2_error(sa__, ERR_CODE_INVALID_RAM_ADDR));
  }
  lane = osprey7_v2l8p2_acc_get_physical_lane(sa__);
  uc_addr_offset = _osprey7_v2l8p2_INTERNAL_get_uc_addr_from_lane(sa__, addr,lane);

  return (osprey7_v2l8p2_wrw_uc_ram(sa__, uc_addr_offset, wr_val));    /* Use Micro register interface for writing RAM */
}

/* Micro RAM UC Word Signed Write */
err_code_t osprey7_v2l8p2_wrwucs_uc_var(srds_access_t *sa__, uint16_t addr, int16_t wr_val) {
  return (osprey7_v2l8p2_wrwuc_uc_var(sa__, addr, (uint16_t)wr_val));
}

/* Micro RAM UC Double Word Write */
err_code_t osprey7_v2l8p2_wrdwuc_uc_var(srds_access_t *sa__, uint16_t addr, uint32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrwuc_uc_var(sa__,addr,(uint16_t)(wr_val&0xFFFF)));
    EFUN(osprey7_v2l8p2_wrwuc_uc_var(sa__,(uint16_t)(addr + 0x2),(uint16_t)((wr_val>>16)&0xFFFF)));
    return ERR_CODE_NONE;
}

/* Micro RAM UC Double Word Signed Write */
err_code_t osprey7_v2l8p2_wrdwucs_uc_var(srds_access_t *sa__, uint16_t addr, int32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrdwuc_uc_var(sa__, addr, (uint32_t)wr_val));
    return ERR_CODE_NONE;
}


/* Micro RAM Core Byte Read */
uint8_t osprey7_v2l8p2_rdbc_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint8_t addr) {
    INIT_SRDS_ERR_CODE
    uint8_t  rddata;
    uint32_t core_addr_offset;
    if(!err_code_p) {
        return(0);
    }

    {


        core_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_core(sa__, addr);
        EPSTM(rddata = osprey7_v2l8p2_rdb_uc_ram(sa__, err_code_p, core_addr_offset));    /* Use Micro register interface for reading RAM */

        return (rddata);
    }
}

/* Micro RAM Core Byte Signed Read */
int8_t osprey7_v2l8p2_rdbcs_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint8_t addr) {
  return ((int8_t) osprey7_v2l8p2_rdbc_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Core Word Read */
uint16_t osprey7_v2l8p2_rdwc_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint8_t addr) {
    INIT_SRDS_ERR_CODE
    uint16_t rddata;
    uint32_t core_addr_offset;

    if(!err_code_p) {
        return(0);
    }
    if (addr%2 != 0) {                                                                /* Validate even address */
        *err_code_p = ERR_CODE_INVALID_RAM_ADDR;
        return (0);
    }

    {


        core_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_core(sa__, addr);
        EPSTM(rddata = osprey7_v2l8p2_rdw_uc_ram(sa__, err_code_p, core_addr_offset));    /* Use Micro register interface for reading RAM */
        return (rddata);
    }
}

/* Micro RAM Core Word Signed Read */
int16_t osprey7_v2l8p2_rdwcs_uc_var(srds_access_t *sa__, err_code_t *err_code_p, uint8_t addr) {
  return ((int16_t) osprey7_v2l8p2_rdwc_uc_var(sa__, err_code_p, addr));
}

/* Micro RAM Core Byte Write  */
err_code_t osprey7_v2l8p2_wrbc_uc_var(srds_access_t *sa__, uint8_t addr, uint8_t wr_val) {
    uint32_t core_addr_offset;

    {
        core_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_core(sa__, addr);

        return (osprey7_v2l8p2_wrb_uc_ram(sa__, core_addr_offset, wr_val));               /* Use Micro register interface for writing RAM */
    }
}


/* Micro RAM Core Byte Signed Write */
err_code_t osprey7_v2l8p2_wrbcs_uc_var(srds_access_t *sa__, uint8_t addr, int8_t wr_val) {
  return (osprey7_v2l8p2_wrbc_uc_var(sa__, addr, (uint8_t)wr_val));
}

/* Micro RAM Core Word Write  */
err_code_t osprey7_v2l8p2_wrwc_uc_var(srds_access_t *sa__, uint8_t addr, uint16_t wr_val) {
    uint32_t core_addr_offset;

    {
        if (addr%2 != 0) {                                                              /* Validate even address */
            return (osprey7_v2l8p2_error(sa__, ERR_CODE_INVALID_RAM_ADDR));
        }

        core_addr_offset = _osprey7_v2l8p2_INTERNAL_get_addr_from_core(sa__, addr);
        return (osprey7_v2l8p2_wrw_uc_ram(sa__, core_addr_offset, wr_val));             /* Use Micro register interface for writing RAM */
    }
}

/* Micro RAM Core Word Signed Write */
err_code_t osprey7_v2l8p2_wrwcs_uc_var(srds_access_t *sa__, uint8_t addr, int16_t wr_val) {
  return(osprey7_v2l8p2_wrwc_uc_var(sa__, addr, (uint16_t)wr_val));
}

/* Micro RAM Core Double Word Write */
err_code_t osprey7_v2l8p2_wrdwc_uc_var(srds_access_t *sa__, uint8_t addr, uint32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrwc_uc_var(sa__,addr,(uint16_t)(wr_val&0xFFFF)));
    EFUN(osprey7_v2l8p2_wrwc_uc_var(sa__,(uint8_t)(addr + 0x2),(uint16_t)((wr_val>>16)&0xFFFF)));
    return ERR_CODE_NONE;
}

/* Micro RAM Core Double Word Signed Write */
err_code_t osprey7_v2l8p2_wrdwcs_uc_var(srds_access_t *sa__, uint8_t addr, int32_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrdwc_uc_var(sa__, addr, (uint32_t)wr_val));
    return ERR_CODE_NONE;
}

/*********************************************************/
/*  Program RAM access through Micro Register Interface  */
/*********************************************************/

/* Micro Program Ram Long Read */
uint32_t osprey7_v2l8p2_rd_long_uc_prog_ram(srds_access_t *sa__, err_code_t *err_code_p, uint32_t addr) {
   INIT_SRDS_ERR_CODE
   uint32_t rddata;
   if(!err_code_p) {
        return(0);
   }
   *err_code_p = ERR_CODE_NONE;
   EPFUN(wrc_micro_autoinc_rdaddr_en(1));
   EPFUN(wrc_micro_ra_rddatasize(0x1));                          /* Select 16bit read datasize */
   EPFUN(wrc_micro_ra_rdaddr_msw((uint16_t)((addr >> 16) & 0xFFFF)));      /* Upper 16bits of ROM address to be read */
   EPFUN(wrc_micro_ra_rdaddr_lsw(addr & 0xFFFF));                /* Lower 16bits of ROM address to be read */
   EPSTM(rddata = rdc_micro_ra_rddata_lsw());                    /* 16bit read data */
   EPSTM(rddata |= (uint32_t)(rdc_micro_ra_rddata_lsw() << 16)); /* 16bit read data */
   return (rddata);
}

/* Micro Program RAM Block Read */
err_code_t osprey7_v2l8p2_rdblk_uc_prog_ram(srds_access_t *sa__, uint8_t *mem, uint32_t addr, uint32_t cnt) {
    osprey7_v2l8p2_INTERNAL_rdblk_callback_arg_t arg;

    if(!mem) {
        return(osprey7_v2l8p2_error(sa__, ERR_CODE_BAD_PTR_OR_INVALID_INPUT));
    }

    arg.mem_ptr = mem;
    return osprey7_v2l8p2_INTERNAL_rdblk_uc_generic_ram(sa__, addr, cnt, 0, cnt, &arg, osprey7_v2l8p2_INTERNAL_rdblk_callback);
}

/*************************************************/
/*  RAM access through Micro Register Interface  */
/*************************************************/

/* Micro RAM Long Write */
err_code_t osprey7_v2l8p2_wr_long_uc_ram(srds_access_t *sa__, uint32_t addr, uint32_t value) {
    INIT_SRDS_ERR_CODE
    EFUN(osprey7_v2l8p2_wrw_uc_ram(sa__, addr+2, (uint16_t)(value >> 16)));
    EFUN(osprey7_v2l8p2_wrw_uc_ram(sa__, addr, value & 0xFFFF));
    return (ERR_CODE_NONE);
}

/* Micro RAM Word Write */
err_code_t osprey7_v2l8p2_wrw_uc_ram(srds_access_t *sa__, uint32_t addr, uint16_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(wrc_micro_dr_raif_prtsel(osprey7_v2l8p2_INTERNAL_grp_idx_from_lane(osprey7_v2l8p2_acc_get_physical_lane(sa__))&1));
    EFUN(wrc_micro_autoinc_wraddr_en(0));
    EFUN(wrc_micro_ra_wrdatasize(0x1));                                 /* Select 16bit write datasize */
    EFUN(wrc_micro_ra_wraddr_msw((uint16_t)((addr >> 16) & 0xFFFF)));   /* Upper 16bits of RAM address to be written to */
    EFUN(wrc_micro_ra_wraddr_lsw(addr & 0xFFFF));                       /* Lower 16bits of RAM address to be written to */
    EFUN(wrc_micro_ra_wrdata_lsw(wr_val));                              /* uC RAM lower 16bits write data */
    return (ERR_CODE_NONE);
}

/* Micro RAM Byte Write */
err_code_t osprey7_v2l8p2_wrb_uc_ram(srds_access_t *sa__, uint32_t addr, uint8_t wr_val) {
    INIT_SRDS_ERR_CODE
    EFUN(wrc_micro_dr_raif_prtsel(osprey7_v2l8p2_INTERNAL_grp_idx_from_lane(osprey7_v2l8p2_acc_get_physical_lane(sa__))&1));
    EFUN(wrc_micro_autoinc_wraddr_en(0));
    EFUN(wrc_micro_ra_wrdatasize(0x0));                                 /* Select 8bit write datasize */
    EFUN(wrc_micro_ra_wraddr_msw((uint16_t)((addr >> 16) & 0xFFFF)));   /* Upper 16bits of RAM address to be written to */
    EFUN(wrc_micro_ra_wraddr_lsw(addr & 0xFFFF));                       /* Lower 16bits of RAM address to be written to */
    EFUN(wrc_micro_ra_wrdata_lsw(wr_val));                              /* uC RAM lower 16bits write data */
    return (ERR_CODE_NONE);
}

/* Micro RAM Long Read */
uint32_t osprey7_v2l8p2_rd_long_uc_ram(srds_access_t *sa__, err_code_t *err, uint32_t addr) {
    INIT_SRDS_ERR_CODE
    uint32_t result;
    ESTM(result = (uint32_t)(osprey7_v2l8p2_rdw_uc_ram(sa__, err, addr+2) << 16));
    ESTM(result |= osprey7_v2l8p2_rdw_uc_ram(sa__, err, addr) & 0xFFFF);
    return result;
}
/* Micro RAM Word Read */
uint16_t osprey7_v2l8p2_rdw_uc_ram(srds_access_t *sa__, err_code_t *err_code_p, uint32_t addr) {
   INIT_SRDS_ERR_CODE
   uint16_t rddata;
   if(!err_code_p) {
        return(0);
   }
   *err_code_p = ERR_CODE_NONE;
   EPFUN(wrc_micro_autoinc_rdaddr_en(0));
   EPFUN(wrc_micro_ra_rddatasize(0x1));                                 /* Select 16bit read datasize */
   EPFUN(wrc_micro_ra_rdaddr_msw((uint16_t)((addr >> 16) & 0xFFFF)));   /* Upper 16bits of RAM address to be read */
   EPFUN(wrc_micro_ra_rdaddr_lsw(addr & 0xFFFF));                       /* Lower 16bits of RAM address to be read */
   EPSTM(rddata = rdc_micro_ra_rddata_lsw());                           /* 16bit read data */
   return (rddata);
}

/* Micro RAM Byte Read */
uint8_t osprey7_v2l8p2_rdb_uc_ram(srds_access_t *sa__, err_code_t *err_code_p, uint32_t addr) {
    INIT_SRDS_ERR_CODE
    uint8_t rddata;
    if(!err_code_p) {
        return(0);
    }
    *err_code_p = ERR_CODE_NONE;
    EPFUN(wrc_micro_autoinc_rdaddr_en(0));
    EPFUN(wrc_micro_ra_rddatasize(0x0));                                 /* Select 8bit read datasize */
    EPFUN(wrc_micro_ra_rdaddr_msw((uint16_t)((addr >> 16) & 0xFFFF)));   /* Upper 16bits of RAM address to be read */
    EPFUN(wrc_micro_ra_rdaddr_lsw(addr & 0xFFFF));                       /* Lower 16bits of RAM address to be read */
    EPSTM(rddata = (uint8_t) rdc_micro_ra_rddata_lsw());                 /* 16bit read data */
    return (rddata);
}

/* Micro RAM Word Signed Write */
err_code_t osprey7_v2l8p2_wrws_uc_ram(srds_access_t *sa__, uint32_t addr, int16_t wr_val) {
    return (osprey7_v2l8p2_wrw_uc_ram(sa__, addr, (uint16_t)wr_val));
}

/* Micro RAM Byte Signed Write */
err_code_t osprey7_v2l8p2_wrbs_uc_ram(srds_access_t *sa__, uint32_t addr, int8_t wr_val) {
    return (osprey7_v2l8p2_wrb_uc_ram(sa__, addr, (uint8_t)wr_val));
}

/* Micro RAM Word Signed Read */
int16_t osprey7_v2l8p2_rdws_uc_ram(srds_access_t *sa__, err_code_t *err_code_p, uint32_t addr) {
    return ((int16_t)osprey7_v2l8p2_rdw_uc_ram(sa__, err_code_p, addr));
}

/* Micro RAM Byte Signed Read */
int8_t osprey7_v2l8p2_rdbs_uc_ram(srds_access_t *sa__, err_code_t *err_code_p, uint32_t addr) {
    return ((int8_t)osprey7_v2l8p2_rdb_uc_ram(sa__, err_code_p, addr));
}

/* Micro RAM Block Read */
err_code_t osprey7_v2l8p2_rdblk_uc_ram(srds_access_t *sa__, uint8_t *mem, uint32_t addr, uint32_t cnt) {
    osprey7_v2l8p2_INTERNAL_rdblk_callback_arg_t arg;

    if(!mem) {
        return(osprey7_v2l8p2_error(sa__, ERR_CODE_BAD_PTR_OR_INVALID_INPUT));
    }

    arg.mem_ptr = mem;
    return osprey7_v2l8p2_INTERNAL_rdblk_uc_generic_ram(sa__, addr | DATA_RAM_BASE, cnt, 0, cnt, &arg, osprey7_v2l8p2_INTERNAL_rdblk_callback);
}


