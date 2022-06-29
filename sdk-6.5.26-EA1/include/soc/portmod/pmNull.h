/*
 *         
 * 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *     
 * DO NOT EDIT THIS FILE!
 *
 */

#ifndef _PMNULL_H__H_
#define _PMNULL_H__H_

#include <phymod/phymod.h>
#include <phymod/phymod_diagnostics.h>
#include <phymod/phymod_reg.h>
#include <soc/cprimod/cprimod.h>
#include <soc/portmod/portmod_defs.h>
#include <sal/core/sync.h>
/**/
int pmNull_port_speed_ability_local_get(int unit, int port, pm_info_t pm_info, int max_num_abilities, portmod_port_speed_ability_t* abilities, int* num_abilities);

/*Get whether the inerface type is supported by PM */
int pmNull_pm_interface_type_is_supported(int unit, soc_port_if_t interface, int* is_supported);

/*Add new pm.*/
int pmNull_pm_init(int unit, const portmod_pm_create_info_internal_t* pm_add_info, int wb_buffer_index, pm_info_t pm_info);

/*Release PM resources*/
int pmNull_pm_destroy(int unit, pm_info_t pm_info);

/*Add new port*/
int pmNull_port_attach(int unit, int port, pm_info_t pm_info, const portmod_port_add_info_t* add_info);

/*get port cores' phymod access*/
int pmNull_pm_core_info_get(int unit, pm_info_t pm_info, int phyn, portmod_pm_core_info_t* core_info);

/*Port remove in PM level*/
int pmNull_port_detach(int unit, int port, pm_info_t pm_info);

/*Port enable*/
int pmNull_port_enable_set(int unit, int port, pm_info_t pm_info, int flags, int enable);
int pmNull_port_enable_get(int unit, int port, pm_info_t pm_info, int flags, int* enable);

/* set/get the interface, speed and encapsulation for the specified port.
            For the First port within core this function initialize the PM, MAC and PHY before configure the port.*/
int pmNull_port_interface_config_set(int unit, int port, pm_info_t pm_info, const portmod_port_interface_config_t* config, int phy_init_flags);
int pmNull_port_interface_config_get(int unit, int port, pm_info_t pm_info, portmod_port_interface_config_t* config, int phy_init_flags);

/* get the default line-side (outmost) interface type of a port based on its speed, encap, number of lanes, etc, when there is or there is not an ext PHY*/
int pmNull_port_default_interface_get(int unit, int port, pm_info_t pm_info, const portmod_port_interface_config_t* config, soc_port_if_t* interface);

/*Port speed set\get*/
int pmNull_port_loopback_set(int unit, int port, pm_info_t pm_info, portmod_loopback_mode_t loopback_type, int enable);
int pmNull_port_loopback_get(int unit, int port, pm_info_t pm_info, portmod_loopback_mode_t loopback_type, int* enable);

/*Port RX MAC ENABLE set\get*/
int pmNull_port_rx_mac_enable_set(int unit, int port, pm_info_t pm_info, int enable);
int pmNull_port_rx_mac_enable_get(int unit, int port, pm_info_t pm_info, int* enable);

/*get port auto negotiation local ability*/
int pmNull_port_ability_local_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);

/*Set\Get autoneg*/
int pmNull_port_autoneg_set(int unit, int port, pm_info_t pm_info, uint32 phy_flags, const phymod_autoneg_control_t* an);
int pmNull_port_autoneg_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, phymod_autoneg_control_t* an);

/*Get autoneg status*/
int pmNull_port_autoneg_status_get(int unit, int port, pm_info_t pm_info, phymod_autoneg_status_t* an_status);

/*get link status*/
int pmNull_port_link_get(int unit, int port, pm_info_t pm_info, int flags, int* link);

/* link up event */
int pmNull_port_phy_link_up_event(int unit, int port, pm_info_t pm_info);

/* link down event */
int pmNull_port_phy_link_down_event(int unit, int port, pm_info_t pm_info);

/*Filter packets bigger than the specified value*/
int pmNull_port_max_packet_size_set(int unit, int port, pm_info_t pm_info, int value);
int pmNull_port_max_packet_size_get(int unit, int port, pm_info_t pm_info, int* value);

/*set/get the MAC source address that will be sent in case of Pause/LLFC*/
int pmNull_port_tx_mac_sa_set(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);
int pmNull_port_tx_mac_sa_get(int unit, int port, pm_info_t pm_info, sal_mac_addr_t mac_sa);

/*set/get Average inter-packet gap*/
int pmNull_port_tx_average_ipg_set(int unit, int port, pm_info_t pm_info, int value);
int pmNull_port_tx_average_ipg_get(int unit, int port, pm_info_t pm_info, int* value);

/*local fault set/get*/
int pmNull_port_local_fault_control_set(int unit, int port, pm_info_t pm_info, const portmod_local_fault_control_t* control);
int pmNull_port_local_fault_control_get(int unit, int port, pm_info_t pm_info, portmod_local_fault_control_t* control);

/*remote fault set/get*/
int pmNull_port_remote_fault_control_set(int unit, int port, pm_info_t pm_info, const portmod_remote_fault_control_t* control);
int pmNull_port_remote_fault_control_get(int unit, int port, pm_info_t pm_info, portmod_remote_fault_control_t* control);

/*local fault status get*/
int pmNull_port_local_fault_status_get(int unit, int port, pm_info_t pm_info, int* value);

/*remote fault status get*/
int pmNull_port_remote_fault_status_get(int unit, int port, pm_info_t pm_info, int* value);

/*set/get Pause FC configuration*/
int pmNull_port_pause_control_set(int unit, int port, pm_info_t pm_info, const portmod_pause_control_t* control);
int pmNull_port_pause_control_get(int unit, int port, pm_info_t pm_info, portmod_pause_control_t* control);

/*Routine for MAC\PHY sync.*/
int pmNull_port_update(int unit, int port, pm_info_t pm_info, const portmod_port_update_control_t* update_control);

/*get port cores' phymod access*/
int pmNull_port_core_access_get(int unit, int port, pm_info_t pm_info, int phyn, int max_cores, phymod_core_access_t* core_access_arr, int* nof_cores, int* is_most_ext);

/*Get lane phymod access structure. can be used for per lane operations*/
int pmNull_port_phy_lane_access_get(int unit, int port, pm_info_t pm_info, const portmod_access_get_params_t* params, int max_phys, phymod_phy_access_t* access, int* nof_phys, int* is_most_ext);

/*Port duplex set\get*/
int pmNull_port_duplex_set(int unit, int port, pm_info_t pm_info, int enable);
int pmNull_port_duplex_get(int unit, int port, pm_info_t pm_info, int* enable);

/*get port auto negotiation local ability*/
int pmNull_port_ability_advert_set(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);
int pmNull_port_ability_advert_get(int unit, int port, pm_info_t pm_info, uint32 phy_flags, portmod_port_ability_t* ability);

/*set EEE Config.*/
int pmNull_port_eee_set(int unit, int port, pm_info_t pm_info, const portmod_eee_t* eee);
int pmNull_port_eee_get(int unit, int port, pm_info_t pm_info, portmod_eee_t* eee);

/*set Vlan Inner/Outer tag.*/
int pmNull_port_vlan_tag_set(int unit, int port, pm_info_t pm_info, const portmod_vlan_tag_t* vlan_tag);
int pmNull_port_vlan_tag_get(int unit, int port, pm_info_t pm_info, portmod_vlan_tag_t* vlan_tag);

/*set modid field.*/
int pmNull_port_modid_set(int unit, int port, pm_info_t pm_info, int value);

/*Toggle Lag Failover Status.*/
int pmNull_port_lag_failover_status_toggle(int unit, int port, pm_info_t pm_info);

/*set port mode.*/
int pmNull_port_mode_set(int unit, int port, pm_info_t pm_info, const portmod_port_mode_info_t* mode);
int pmNull_port_mode_get(int unit, int port, pm_info_t pm_info, portmod_port_mode_info_t* mode);

/*set port encap.*/
int pmNull_port_encap_set(int unit, int port, pm_info_t pm_info, int flags, portmod_encap_t encap);
int pmNull_port_encap_get(int unit, int port, pm_info_t pm_info, int* flags, portmod_encap_t* encap);

/*set port register higig field.*/
int pmNull_port_higig_mode_set(int unit, int port, pm_info_t pm_info, int mode);
int pmNull_port_higig_mode_get(int unit, int port, pm_info_t pm_info, int* mode);

/*set port register higig field.*/
int pmNull_port_higig2_mode_set(int unit, int port, pm_info_t pm_info, int mode);
int pmNull_port_higig2_mode_get(int unit, int port, pm_info_t pm_info, int* mode);

/*Get the reference clock value 156 or 125.*/
int pmNull_port_ref_clk_get(int unit, int port, pm_info_t pm_info, int* ref_clk);

/*Disable lag failover.*/
int pmNull_port_cntmaxsize_set(int unit, int port, pm_info_t pm_info, int val);
int pmNull_port_cntmaxsize_get(int unit, int port, pm_info_t pm_info, int* val);

/*Get Info needed to restore after drain cells.*/
int pmNull_port_drain_cell_get(int unit, int port, pm_info_t pm_info, portmod_drain_cells_t* drain_cells);

/*Restore informaation after drain cells.*/
int pmNull_port_drain_cell_stop(int unit, int port, pm_info_t pm_info, const portmod_drain_cells_t* drain_cells);

/*Restore informaation after drain cells.*/
int pmNull_port_drain_cell_start(int unit, int port, pm_info_t pm_info);

/**/
int pmNull_port_drain_cells_rx_enable(int unit, int port, pm_info_t pm_info, int rx_en);

/**/
int pmNull_port_egress_queue_drain_rx_en(int unit, int port, pm_info_t pm_info, int rx_en);

/**/
int pmNull_port_mac_ctrl_set(int unit, int port, pm_info_t pm_info, uint64 ctrl);

/**/
int pmNull_port_txfifo_cell_cnt_get(int unit, int port, pm_info_t pm_info, uint32* cnt);

/**/
int pmNull_port_egress_queue_drain_get(int unit, int port, pm_info_t pm_info, uint64* ctrl, int* rxen);

/*Set/get port mac reset */
int pmNull_port_mac_reset_set(int unit, int port, pm_info_t pm_info, int val);
int pmNull_port_mac_reset_get(int unit, int port, pm_info_t pm_info, int* val);

/**/
int pmNull_port_soft_reset_toggle(int unit, int port, pm_info_t pm_info, int idx);

/*Check if MAC needs to be reset.*/
int pmNull_port_mac_reset_check(int unit, int port, pm_info_t pm_info, int enable, int* reset);

/*get the speed for the specified port*/
int pmNull_port_speed_get(int unit, int port, pm_info_t pm_info, int* speed);

/* portmod check if external phy is legacy*/
int pmNull_port_check_legacy_phy(int unit, int port, pm_info_t pm_info, int* legacy_phy);

/* portmod phy failover mode*/
int pmNull_port_failover_mode_set(int unit, int port, pm_info_t pm_info, phymod_failover_mode_t failover);
int pmNull_port_failover_mode_get(int unit, int port, pm_info_t pm_info, phymod_failover_mode_t* failover);

/* portmod restore information after warmboot*/
int pmNull_port_warmboot_db_restore(int unit, int port, pm_info_t pm_info, const portmod_port_interface_config_t* intf_config, const portmod_port_init_config_t* init_config, phymod_operation_mode_t phy_op_mode);

/* portmod port flow control config*/
int pmNull_port_flow_control_set(int unit, int port, pm_info_t pm_info, int merge_mode_en, int parallel_fc_en);

/*set/get port medium type config. */
int pmNull_port_medium_config_set(int unit, int port, pm_info_t pm_info, soc_port_medium_t medium, soc_phy_config_t* config);
int pmNull_port_medium_config_get(int unit, int port, pm_info_t pm_info, soc_port_medium_t medium, soc_phy_config_t* config);

/*get port medium type. */
int pmNull_port_medium_get(int unit, int port, pm_info_t pm_info, soc_port_medium_t* medium);

/* set/get the speed config for the specified port.*/
int pmNull_port_speed_config_set(int unit, int port, pm_info_t pm_info, const portmod_speed_config_t* speed_config);
int pmNull_port_speed_config_get(int unit, int port, pm_info_t pm_info, portmod_speed_config_t* speed_config);

/*Local and Remote faults status get*/
int pmNull_port_faults_status_get(int unit, int port, pm_info_t pm_info, portmod_port_fault_status_t* faults);

#endif /*_PMNULL_H_*/