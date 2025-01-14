/*
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 * This File is Auto-generated - DO NOT TOUCH IT!!!!
 */



#include <shared/utilex/utilex_str.h>
#include <soc/sand/shrextend/shrextend_debug.h>
#include <sal/core/libc.h>
#include <soc/sand/auto_generated/common_dbx_pre_compiled.h>

#define _INTERNAL_AUTO_GENERATED_ARRAYS_MARKER
#define _INTERNAL_AUTO_GENERATED_FILE_SEARCH

/* *INDENT-OFF* */
_INTERNAL_AUTO_GENERATED_ARRAYS_MARKER

const char *DNX_Devices_0="<?xml version=\"1.0\"?>\n\
\n\
<!-- This document represent all supported DNX devices March 23 2016 -->\n\
<!-- Chip names are taken from drv.c mapping PCID to name in soc_dpp_chip_type_set -->\n\
\n\
<top>\n\
    <devices>\n\
\n\
        <device chip=\"arad\"         db_name=\"arad\"/>\n\
        <device chip=\"arad_plus\"    db_name=\"aradplus\"/>\n\
        <device chip=\"jericho\"      db_name=\"jericho\"/>\n\
        <device chip=\"qmx\"          db_name=\"jericho\"/>\n\
        <device chip=\"qax\"          db_name=\"qax\"/>\n\
        <device chip=\"BCM88470_B0\"  db_name=\"qax_b0\"/>\n\
        <device chip=\"kalia\"        db_name=\"qax\"/>\n\
        <device chip=\"qux\"          db_name=\"qux\"/>\n\
        <device chip=\"jericho_plus\" db_name=\"jerichoplus\"/>\n\
        <device chip=\"BCM88690_A0\"  device_name=\"jericho2_a0\" short_name=\"jr2_a0\" db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88690_B0\"  device_name=\"jericho2_b0\" short_name=\"jr2_b0\" db_name=\"jericho2_b0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88800_A0\"  device_name=\"jericho2c_a0\" short_name=\"j2c_a0\" db_name=\"jericho2c_a0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88480_A0\"  device_name=\"qumran2a_a0\" short_name=\"q2a_a0\" db_name=\"qumran2a_a0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88480_B0\"  device_name=\"qumran2a_b0\" short_name=\"q2a_b0\" db_name=\"qumran2a_b0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88850_A0\"  device_name=\"jericho2p_a0\" short_name=\"j2p_a0\" db_name=\"jericho2p_a0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"BCM88830_A0\"  device_name=\"jericho2x_a0\" short_name=\"j2x_a0\" db_name=\"jericho2x_a0\" base_db_name=\"jericho2_a0\"/>\n\
        <device chip=\"ramon\"        db_name=\"ramon\" pp=\"no\"/>\n\
    </devices>\n\
    <parsing-objects>\n\
        <include file=\"NetworkHeadersObjects.xml\" />\n\
        <include file=\"SystemHeadersObjects.xml\" device_specific=\"1\" />\n\
        <include file=\"LocalSystemHeadersObjects.xml\" device_specific=\"1\" />\n\
        <include file=\"NetworkStructures.xml\" type=\"structs\"/>\n\
        <include file=\"auto_generated/GeneralDataStructures.xml\" type=\"structs\" device_specific=\"1\"/>\n\
        <include file=\"LayerRecordsTypesStructures.xml\" type=\"structs\" device_specific=\"1\"/>\n\
        <include file=\"SignalStructures.xml\" type=\"structs\" device_specific=\"1\"/>\n\
        <include file=\"LocalSignalStructures.xml\" type=\"structs\" device_specific=\"1\"/>\n\
        <include file=\"SystemHeadersObjectsJ1.xml\" device_specific=\"1\" />\n\
        <include file=\"SignalStructuresJ1.xml\" type=\"structs\" device_specific=\"1\"/>\n\
        <include file=\"LocalSignalStructuresJ1.xml\" type=\"structs\" device_specific=\"1\"/>\n\
    </parsing-objects>\n\
    <case-objects>\n\
        <include file=\"TestCases.xml\" type=\"tests\"/>\n\
        <include file=\"FilterCases.xml\" type=\"filters\"/>\n\
    </case-objects>\n\
</top>\n\
";

const char *NetworkHeadersObjects_0="<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<top>\n\
    <parsing-objects>\n\
        <!-- ~~~~~~~~~ Dynamicly parsed ETH header ~~~~~~~~~ -->\n\
        <!-- This object has no structure, one of ETH0/1/2 will be used -->\n\
        <object name=\"ETH\" size=\"176\" plugin=\"eth_parser\">\n\
            <description>Ethernet Header for packet parsing (Use ETH0/1/2/3 for packet compose)</description>\n\
        </object>\n\
        <!-- ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ -->\n\
        <object name=\"ETH0\" size=\"112\">\n\
            <description>Untagged Ethernet Header</description>\n\
            <next-header field=\"ETH0.Type\" options=\"ETH_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"ETH1\" size=\"144\">\n\
            <description>Ethernet Header with a single VLAN</description>\n\
            <next-header field=\"ETH1.Type\" options=\"ETH_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"ETH2\" size=\"176\">\n\
            <description>Ethernet Header with 2 VLANs (use Inner_VLAN/Outer_VLAN for packet compose)</description>\n\
            <next-header field=\"ETH2.Type\" options=\"ETH_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"ETH3\" size=\"208\">\n\
            <description>Ethernet Header with 3 VLANs (use Inner_VLAN/Middle_VLAN/Outer_VLAN for packet compose)</description>\n\
            <next-header field=\"ETH3.Type\" options=\"ETH_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"ARP\" size=\"224\">\n\
            <description>ARP Header</description>\n\
        </object>\n\
        <object name=\"MPLS\" size=\"32\">\n\
            <description>MPLS/PWE header</description>\n\
            <extension name=\"MPLS\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0\" />\n\
                    <field path=\"MPLS.BOS\" />\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"MPLS_Post\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"MPLS.BOS\" />\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"MPLS_Post\" size=\"0\">\n\
            <description>The protocol after MPLS termination can be CW, GACH, IPV4, IPV6, ETH, etc.</description>\n\
            <extension name=\"Control_Word\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"Control_Word\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GACH\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"GACH\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"ETH\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"ETH\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"IPv4\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"IPv4\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"IPv6\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"IPv6\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"BIER\">\n\
                <condition type=\"plugin\" mode=\"enable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"BIER\"/>\n\
                </condition>\n\
            </extension>\n\
      ";

const char *NetworkHeadersObjects_1="      <extension name=\"MPLS_Next_Proto\">\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"BIER\"/>\n\
                </condition>\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"IPv6\"/>\n\
                </condition>\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"IPv4\"/>\n\
                </condition>\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"ETH\"/>\n\
                </condition>\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"GACH\"/>\n\
                </condition>\n\
                <condition type=\"plugin\" mode=\"disable\" callback=\"packet_post_mpls\">\n\
                    <plugin-arg Name=\"proto\" Value=\"Control_Word\"/>\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
\n\
        <object name=\"MPLS_Next_Proto\" size=\"320\" plugin=\"2nd_parser\" structure=\"Invalid\"/>\n\
        <object name=\"GACH\" size=\"32\">\n\
            <description>G-ACH Control word</description>\n\
            <next-header field=\"GACH.Channel\" options=\"GACH_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"Control_Word\" size=\"32\">\n\
            <description>PWE Control word</description>\n\
            <extension name=\"ETH\"/>\n\
        </object>\n\
        <object name=\"BIER\" size=\"320\">\n\
            <description>Bier(MPLS) header</description>\n\
            <next-header field=\"BIER.Proto\" options=\"BIER_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"IPv4\" size=\"480\" plugin=\"ipv4_parser\">\n\
            <description>IPv4 Header (Use IPv4_base for packet compose)</description>\n\
            <next-header field=\"IPv4.Protocol\" options=\"IPV4_Next_Protocol\"/>\n\
            <post-compose plugin=\"ipv4_post_processing\"/>\n\
        </object>\n\
        <object name=\"IPv6\" size=\"320\">\n\
            <description>IPv6 Header</description>\n\
            <next-header field=\"IPv6.Next_Header\" options=\"IPV6_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"IPv6_EXT\" size=\"1024\" plugin=\"ipv6_ext_parser\">\n\
            <description>IPv6-Extension header - Hop-By-Hop, Auth, Destination Options, Mobility Header, HIP, Shim6, 253, 254</description>\n\
            <next-header field=\"IPv6_EXT.Next_Header\" options=\"IPV6_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"IPv6_AH_EXT\" size=\"1024\" plugin=\"ipv6_ext_ah_parser\">\n\
            <description>IPv6-Extension header AH (Authentication Header)</description>\n\
            <next-header field=\"IPv6_AH_EXT.Next_Header\" options=\"IPV6_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"IPv6_Fragment\" size=\"64\">\n\
            <description>IPv6-Fragment header</description>\n\
            <extension name=\"TCP\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"6\" />\n\
                    <field path=\"IPv6_Fragment.Next_Header\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0\" />\n\
                    <field path=\"IPv6_Fragment.Fragment_Offset\" />\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"UDP\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"17\" />\n\
                    <field path=\"IPv6_Fragment.Next_Header\"/>\n\
                </condition>\n\
                <conditi";

const char *NetworkHeadersObjects_2="on type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0\" />\n\
                    <field path=\"IPv6_Fragment.Fragment_Offset\" />\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"ESP_Post\" size=\"480\" structure=\"IPvX_Demux\">\n\
            <description>Inner IPv4/6 after ESP</description>\n\
        </object>\n\
        <object name=\"ESP_Header\" size=\"64\" structure=\"ESP_Header\">\n\
            <description>ESP (Encapsulating Security Payload) header, first 8 bytes only</description>\n\
        </object>\n\
        <object name=\"ESP\" size=\"0\">\n\
            <description>Inner IPv4/6 after ESP</description>\n\
             <extension name=\"ESP_Post\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"SVTAG.IPSEC\" />\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"ESP_Header\">\n\
                <condition type=\"field\" mode=\"disable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"SVTAG.IPSEC\" />\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"TCP\" size=\"160\" structure=\"TCP\">\n\
            <description>TCP Header</description>\n\
        </object>\n\
        <object name=\"SCTP\" size=\"96\" structure=\"SCTP\">\n\
            <description>SCTP Header</description>\n\
        </object>        \n\
        <object name=\"UDP\" size=\"64\" structure=\"UDP\">\n\
            <description>UDP Header</description>\n\
            <next-header field=\"UDP.Dst_Port\" options=\"UDP_Applications\"/>\n\
        </object>\n\
        <object name=\"L2TP\" size=\"128\" structure=\"L2TP\">\n\
            <description>L2TP Header</description>\n\
            <extension name=\"PPP_CONST\">\n\
            </extension>\n\
        </object>\n\
        <object name=\"PPP_CONST\" size=\"16\" structure=\"PPP_CONST\">\n\
            <description>Constant part of PPP Header</description>\n\
            <extension name=\"PPP_NEXT_PROTOCOL\">\n\
            </extension>\n\
        </object>\n\
        <object name=\"PPP_NEXT_PROTOCOL\" size=\"16\" structure=\"PPP_NEXT_PROTOCOL\">\n\
            <description>NEXT_PROTOCOL part of PPP Header</description>\n\
            <next-header field=\"PPP_NEXT_PROTOCOL.Next_Protocol\" options=\"PPP_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"GRE\" size=\"32\" structure=\"GRE\">\n\
            <description>GRE header</description>\n\
            <next-header field=\"GRE.Protocol\" options=\"ETH_Next_Protocol\"/>\n\
            <extension name=\"GRE_Checksum\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.C\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Offset\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.C\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.R\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Offset\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.C\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"disable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.R\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Offset\">\n\
                <condition type=\"field\" mode=\"disable\">\n\
                ";

const char *NetworkHeadersObjects_3="    <enable val=\"1\" />\n\
                    <field path=\"GRE.C\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.R\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Key\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.K\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Sequence_Number\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.S(Seq)\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"GRE_Routing\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GRE.R\"/>\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"GRE_Checksum\" size=\"16\" structure=\"GRE_Checksum\">\n\
            <description>GRE Checksum</description>\n\
        </object>\n\
        <object name=\"GRE_Offset\" size=\"16\" structure=\"GRE_Offset\">\n\
            <description>GRE Offset</description>\n\
        </object>\n\
        <object name=\"GRE_Key\" size=\"32\" structure=\"GRE_Key\">\n\
            <description>GRE Key</description>\n\
        </object>\n\
        <object name=\"GRE_Sequence_Number\" size=\"32\" structure=\"GRE_Sequence_Number\">\n\
            <description>GRE Sequence Number</description>\n\
        </object>\n\
        <object name=\"GRE_Routing\" size=\"32\" structure=\"GRE_Routing\">\n\
            <description>GRE Routing</description>\n\
        </object>\n\
        \n\
        <object name=\"GTP_V1_base\" size=\"64\" structure=\"GTP_V1_base\">\n\
            <description>GTP V1 Header. The next protocol may be IPv4/v6.</description>\n\
            <extension name=\"GTP_V1_additional\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GTP_V1_base.E\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"IPvX_Demux\">\n\
                <condition type=\"field\" mode=\"disable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GTP_V1_base.E\"/>\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
\n\
        <object name=\"GTP_V1_additional\" size=\"32\">\n\
            <description>GTP V1 additional Header. The next protocol may be IPv4/v6.</description>\n\
            <extension name=\"IPvX_Demux\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"GTP_V1_base.E\"/>\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"IPvX_Demux\" size=\"480\" structure=\"IPvX_Demux\">\n\
            <description>Inner IPv4/6</description>\n\
        </object>\n\
        <object name=\"SRv6\" size=\"1472\" plugin=\"srv6_parser\" structure=\"Invalid\">\n\
            <description>SRv6 Header</description>\n\
           <next-header field=\"SRv6.Next_Header\" options=\"IPV6_Next_Protocol\"/>\n\
        </object>\n\
        <object name=\"BFD\" size=\"192\" structure=\"BFD\">\n\
            <description>BFD PDU</description>\n\
        </object>\n\
        <object name=\"BFD_SIG_HOP\" size=\"192\" structure=\"BFD\">\n\
            <description>Single Hop BFD PDU</description>\n\
        </object>\n\
        <object name=\"BFD_MUL_HOP\" size=\"192\" structure=\"BFD\">\n\
            <description>Multi Hop BFD PDU</description>\n\
        </object>\n\
        <object name=\"BFD_SEAMLE";

const char *NetworkHeadersObjects_4="SS\" size=\"192\" structure=\"BFD\">\n\
            <description>Seamless BFD PDU</description>\n\
        </object>\n\
        <object name=\"BFD_MICRO\" size=\"192\" structure=\"BFD\">\n\
            <description>Micro BFD PDU</description>\n\
        </object>\n\
        <object name=\"VXLAN\" size=\"64\" structure=\"VXLAN\">\n\
            <description>VXLAN Header</description>\n\
            <extension name=\"ETH\"/>\n\
        </object>\n\
        <object name=\"VXLAN_GPE\" size=\"64\" structure=\"VXLAN_GPE\">\n\
            <description>VXLAN Header</description>\n\
            <extension name=\"ETH\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Flags.P\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"IPv4\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Flags.P\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0x1\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Next_Protocol\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"IPv6\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Flags.P\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0x2\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Next_Protocol\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"ETH\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Flags.P\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0x3\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Next_Protocol\"/>\n\
                </condition>\n\
            </extension>\n\
            <extension name=\"MPLS\">\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"1\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Flags.P\"/>\n\
                </condition>\n\
                <condition type=\"field\" mode=\"enable\">\n\
                    <enable val=\"0x5\" />\n\
                    <field path=\"VXLAN_GPE.GPE_Next_Protocol\"/>\n\
                </condition>\n\
            </extension>\n\
        </object>\n\
        <object name=\"ETH_OAM\" size=\"600\" structure=\"ETH_OAM\">\n\
            <description>Y.1731 over ETH PDU</description>\n\
        </object>\n\
        <object name=\"IEEE_1588\" size=\"272\">\n\
            <description>PTP over ETH Header (IEEE 1588)</description>\n\
        </object>\n\
    </parsing-objects>\n\
    <next-headers>\n\
        <next-header-options name=\"ETH_Next_Protocol\">\n\
            <option object=\"ARP\"       val=\"0x0806\"/>\n\
            <option object=\"MPLS\"      val=\"0x8847\"/>\n\
            <option object=\"MPLS\"      val=\"0x8848\"/>\n\
            <option object=\"IPv4\"      val=\"0x0800\"/>\n\
            <option object=\"IPv6\"      val=\"0x86dd\"/>\n\
            <option object=\"ETH_OAM\"   val=\"0x8902\"/>\n\
            <option object=\"IEEE_1588\" val=\"0x88f7\"/>\n\
            <option object=\"ETH\"       val=\"0x1234\"/>\n\
        </next-header-options>\n\
        <next-header-options name=\"IPV4_Next_Protocol\">\n\
            <option object=\"SCTP\"             val=\"0x84\"/>\n\
            <option object=\"UDP\"              val=\"0x11\"/>\n\
            <option object=\"GRE\"              val=\"0x2f\"/>\n\
            <option obj";

const char *NetworkHeadersObjects_5="ect=\"TCP\"              val=\"0x06\"/>\n\
            <option object=\"IPv4\"             val=\"0x04\"/>\n\
            <option object=\"IPv6\"             val=\"0x29\"/>\n\
            <option object=\"SRv6\"             val=\"0x2B\"/>\n\
            <option object=\"ESP\"              val=\"0x32\"/>\n\
        </next-header-options>        \n\
        <next-header-options name=\"IPV6_Next_Protocol\">\n\
            <option object=\"SCTP\"             val=\"0x84\"/>\n\
            <option object=\"UDP\"              val=\"0x11\"/>\n\
            <option object=\"GRE\"              val=\"0x2f\"/>\n\
            <option object=\"TCP\"              val=\"0x06\"/>\n\
            <option object=\"IPv4\"             val=\"0x04\"/>\n\
            <option object=\"IPv6\"             val=\"0x29\"/>\n\
            <option object=\"SRv6\"             val=\"0x2B\"/>\n\
            <option object=\"IPv6_EXT\"         val=\"0x00\"/>\n\
            <option object=\"IPv6_Fragment\"    val=\"0x2C\"/>\n\
            <option object=\"ESP\"              val=\"0x32\"/>\n\
            <option object=\"IPv6_AH_EXT\"      val=\"0x33\"/>\n\
            <option object=\"IPv6_EXT\"         val=\"0x3C\"/>\n\
            <option object=\"IPv6_EXT\"         val=\"0x87\"/>\n\
            <option object=\"MPLS\"             val=\"0x89\"/>\n\
            <option object=\"IPv6_EXT\"         val=\"0x8B\"/>\n\
            <option object=\"IPv6_EXT\"         val=\"0x8C\"/>\n\
            <option object=\"ETH\"              val=\"0x8F\"/>\n\
<!--\n\
Currently not supporting the parsing of the experimentation and testing tags: 253,254\n\
                    object=\"IPv6_EXT\"         val=\"0xFD\"\n\
                    object=\"IPv6_EXT\"         val=\"0xFE\"\n\
-->\n\
        </next-header-options>\n\
        <next-header-options name=\"UDP_Applications\">\n\
            <option object=\"BFD_SIG_HOP\"       val=\"3784\"/>\n\
            <option object=\"BFD_MUL_HOP\"       val=\"4784\"/>\n\
            <option object=\"BFD_MICRO\"         val=\"6784\"/>\n\
            <option object=\"BFD_SEAMLESS\"      val=\"7784\"/>\n\
            <option object=\"MPLS\"      val=\"6635\"/>\n\
            <option object=\"VXLAN\"     val=\"4789\"/>\n\
            <option object=\"VXLAN\"     val=\"0x5555\"/>\n\
            <option object=\"VXLAN_GPE\" val=\"4790\"/>\n\
            <option object=\"GTP_V1_base\" val=\"2152\"/>\n\
            <option object=\"IPv4\"      val=\"26117\"/>\n\
            <option object=\"IPv6\"      val=\"26133\"/>\n\
            <option object=\"L2TP\"      val=\"1701\"/>\n\
        </next-header-options>\n\
        <next-header-options name=\"BIER_Next_Protocol\">\n\
            <option object=\"MPLS\" val=\"1\"/>\n\
            <option object=\"MPLS\" val=\"2\"/>\n\
            <option object=\"ETH\"  val=\"3\"/>\n\
            <option object=\"IPv4\" val=\"4\"/>\n\
            <option object=\"OAM\"  val=\"5\"/>\n\
            <option object=\"IPv6\" val=\"6\"/>\n\
        </next-header-options>\n\
        <next-header-options name=\"GACH_Next_Protocol\">\n\
            <option object=\"ETH_OAM\" val=\"0x8902\"/>\n\
            <option object=\"BFD\"     val=\"0x0007\"/>\n\
        </next-header-options>\n\
        <next-header-options name=\"PPP_Next_Protocol\">\n\
            <option object=\"LCP\"     val=\"0xC021\"/>\n\
            <option object=\"NCP\"     val=\"0x8021\"/>\n\
            <option object=\"IPv4\"    val=\"0x21\"/>\n\
            <option object=\"IPv6\"    val=\"0x57\"/>\n\
        </next-header-options>\n\
    </next-headers>\n\
</top>\n\
";

const char *NetworkStructures_0="<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<top>\n\
    <signal-structures>\n\
        <structure name=\"ETH0\" size=\"112\" order=\"msb\">\n\
            <field name=\"DA\" bits=\"0:47\" type=\"mac\" default=\"00:01:02:03:04:05\"/>\n\
            <field name=\"SA\" bits=\"48:95\" type=\"mac\" default=\"00:06:07:08:09:0A\" />\n\
            <field name=\"Type\" bits=\"96:111\" default=\"0x899\" resolution=\"ETH_Type\"/>\n\
        </structure>\n\
        <structure name=\"ETH1\" size=\"144\" order=\"msb\">\n\
            <field name=\"DA\" bits=\"0:47\" type=\"mac\" default=\"00:01:02:03:04:05\"/>\n\
            <field name=\"SA\" bits=\"48:95\" type=\"mac\" default=\"00:06:07:08:09:0A\" />\n\
            <field name=\"VLAN\" bits=\"96:127\" default=\"0x81000001\"/>\n\
            <field name=\"Type\" bits=\"128:143\" default=\"0x899\" resolution=\"ETH_Type\"/>\n\
        </structure>\n\
        <structure name=\"ETH2\" size=\"176\" order=\"msb\">\n\
            <field name=\"DA\" bits=\"0:47\" type=\"mac\" default=\"00:01:02:03:04:05\"/>\n\
            <field name=\"SA\" bits=\"48:95\" type=\"mac\" default=\"00:06:07:08:09:0A\" />\n\
            <field name=\"Outer_VLAN\" bits=\"96:127\" expansion=\"VLAN\" default=\"0x91000001\"/>\n\
            <field name=\"Inner_VLAN\" bits=\"128:159\" expansion=\"VLAN\" default=\"0x81000001\"/>\n\
            <field name=\"Type\" bits=\"160:175\" default=\"0x899\" resolution=\"ETH_Type\"/>\n\
        </structure>\n\
        <structure name=\"ETH3\" size=\"208\" order=\"msb\">\n\
            <field name=\"DA\" bits=\"0:47\" type=\"mac\" default=\"00:01:02:03:04:05\"/>\n\
            <field name=\"SA\" bits=\"48:95\" type=\"mac\" default=\"00:06:07:08:09:0A\" />\n\
            <field name=\"Outer_VLAN\" bits=\"96:127\" expansion=\"VLAN\" default=\"0x81000001\"/>\n\
            <field name=\"Middle_VLAN\" bits=\"128:159\" expansion=\"VLAN\"/>\n\
            <field name=\"Inner_VLAN\" bits=\"160:191\" expansion=\"VLAN\"/>\n\
            <field name=\"Type\" bits=\"192:207\" default=\"0x899\" resolution=\"ETH_Type\"/>\n\
        </structure>\n\
        <structure name=\"VLAN\" size=\"32\" order=\"msb\">\n\
            <field name=\"TPID\" bits=\"0:15\" default=\"0x8100\"/>\n\
            <field name=\"PCP\" bits=\"16:18\" default=\"2\"/>\n\
            <field name=\"DEI\" bits=\"19\"/>\n\
            <field name=\"VID\" bits=\"20:31\" default=\"0x1\"/>\n\
        </structure>\n\
        <structure name=\"MPLS\" size=\"32\" order=\"msb\">\n\
            <field name=\"Label\" bits=\"0:19\"/>\n\
            <field name=\"EXP\" bits=\"20:22\"/>\n\
            <field name=\"BOS\" bits=\"23:23\" default=\"1\"/>\n\
            <field name=\"TTL\" bits=\"24:31\"/>\n\
        </structure>\n\
        <structure name=\"GACH\" size=\"32\" order=\"msb\">\n\
            <field name=\"Nibble\" bits=\"0:3\" default=\"1\"/>\n\
            <field name=\"Version\" bits=\"4:7\" default=\"0\"/>\n\
            <field name=\"Channel\" bits=\"16:31\"/>\n\
        </structure>\n\
        <structure name=\"Control_Word\" size=\"32\" order=\"msb\">\n\
            <field name=\"Nibble\" bits=\"0:3\" default=\"0\"/>\n\
            <field name=\"Flags\" bits=\"4:7\" />\n\
            <field name=\"Frag\" bits=\"8:9\" />\n\
            <field name=\"Length\" bits=\"10:15\" />\n\
            <field name=\"Sequence_Number\" bits=\"16:31\" />\n\
        </structure>\n\
        <structure name=\"BIER\" size=\"320\" order=\"msb\">\n\
            <field name=\"Nibble\" bits=\"0:3\" default=\"5\"/>\n\
            <field name=\"Ver\" bits=\"4:7\"/>\n\
            <field name=\"BSL\" bits=\"8:11\" default=\"3\"/>\n\
            <field name=\"Entropy\" bits=\"12:31\"/>\n\
            <field name=\"OAM_Bits\" bits=\"32:33\"/>\n\
            <field name=\"Rsv\" bits=\"34:35\"/>\n\
            <field name=\"DSCP\" bits=\"36:41\"/>\n\
            <field name=\"Proto\" bits=\"42:47\" resolution=\"BIER_Next_Protocol\"/>\n\
            <";

const char *NetworkStructures_1="field name=\"BFIR_ID\" bits=\"48:63\"/>\n\
            <field name=\"BitString\" bits=\"64:319\"/>\n\
        </structure>\n\
        <structure name=\"TOS\" size=\"8\" order=\"msb\">\n\
            <field name=\"DSCP\" bits=\"0:5\" />\n\
            <field name=\"ECN\" bits=\"6:7\" />\n\
        </structure>\n\
        <structure name=\"IPv4\" size=\"160\" order=\"msb\">\n\
            <field name=\"Version\" bits=\"0:3\" default=\"4\"/>\n\
            <field name=\"IHL\" bits=\"4:7\" default=\"5\"/>\n\
            <field name=\"TOS\" bits=\"8:15\"/>\n\
            <field name=\"Total_Length\" bits=\"16:31\"/>\n\
            <field name=\"Identification\" bits=\"32:47\" />\n\
            <field name=\"Flags\" bits=\"48:50\" />\n\
            <field name=\"Fragment_Offset\" bits=\"51:63\" />\n\
            <field name=\"TTL\" bits=\"64:71\" default=\"64\" />\n\
            <field name=\"Protocol\" bits=\"72:79\" />\n\
            <field name=\"Checksum\" bits=\"80:95\" />\n\
            <field name=\"SIP\" bits=\"96:127\" type=\"ip4\" default=\"10.11.12.1\"/>\n\
            <field name=\"DIP\" bits=\"128:159\" type=\"ip4\" default=\"10.11.12.2\"/>\n\
        </structure>\n\
        <structure name=\"IPv6_Address\" size=\"128\" order=\"msb\">\n\
            <field name=\"High\" bits=\"0:63\"/>\n\
            <field name=\"Low\" bits=\"64:127\"/>\n\
        </structure>\n\
        <structure name=\"IPv6\" size=\"320\" order=\"msb\">\n\
            <field name=\"Version\" bits=\"0:3\" default=\"6\"/>\n\
            <field name=\"Traffic_Class\" bits=\"4:11\" />\n\
            <field name=\"Flow_Label\" bits=\"12:31\" />\n\
            <field name=\"Length\" bits=\"32:47\" />\n\
            <field name=\"Next_Header\" bits=\"48:55\" default=\"0x11\"/>\n\
            <field name=\"Hop_Limit\" bits=\"56:63\" />\n\
            <field name=\"SIP\" bits=\"64:191\" type=\"ip6\" default=\"1101:2202:3303:4404:5505:6606:7707:8808\" expansion=\"IPv6_Address\"/>\n\
            <field name=\"DIP\" bits=\"192:319\" type=\"ip6\" default=\"2001:0:0:0:ff0e:0:0:1234\" expansion=\"IPv6_Address\"/>\n\
        </structure>\n\
        <structure name=\"IPv6_EXT\" size=\"64\" order=\"msb\">\n\
            <field name=\"Next_Header\" bits=\"0:7\" />\n\
            <field name=\"Header_Ext_Len\" bits=\"8:15\" />\n\
            <field name=\"Header_Specific_Data\" bits=\"16:63\" />\n\
        </structure>\n\
        <structure name=\"IPv6_AH_EXT\" size=\"96\" order=\"msb\">\n\
            <field name=\"Next_Header\" bits=\"0:7\" />\n\
            <field name=\"Header_Ext_Len\" bits=\"8:15\" />\n\
            <field name=\"Reserved\" bits=\"16:31\" />\n\
            <field name=\"Security_Param_Idx\" bits=\"32:63\" />\n\
            <field name=\"Sequence_Number\" bits=\"64:95\" />\n\
        </structure>\n\
        <structure name=\"IPv6_With_Ext\" size=\"384\" order=\"msb\">\n\
            <field name=\"IPv6\" bits=\"0:319\"/>\n\
            <field naem=\"Ext\" bits=\"320:383\" expansion=\"IPv6_EXT\"/>\n\
        </structure>        \n\
        <structure name=\"IPv6_Fragment\" size=\"64\" order=\"msb\">\n\
            <field name=\"Next_Header\" bits=\"0:7\" />\n\
            <field name=\"Fragment_Offset\" bits=\"16:28\" />\n\
            <field name=\"More_Fragments\" bits=\"31:31\" />\n\
            <field name=\"Identification\" bits=\"32:63\" />\n\
        </structure>\n\
        <structure name=\"ESP_Header\" size=\"64\" order=\"msb\">\n\
            <field name=\"Security_Para_Idx\" bits=\"0:31\" />\n\
            <field name=\"Sequence_Number\" bits=\"32:63\" />\n\
        </structure>\n\
        <structure name=\"IPvX_Demux\" size=\"480\" expansion=\"Dynamic\" order=\"msb\">\n\
            <option expansion=\"IPv4\" Version=\"4\" trim=\"MS\" />\n\
            <option expansion=\"IPv6\" Version=\"6\" trim=\"MS\" />\n\
            <field name=\"Version\" bits=\"0:3\" />\n\
        </structure>\n\
        <structure name=\"UDP\" size=\"64\" order=";

const char *NetworkStructures_2="\"msb\">\n\
            <field name=\"Src_Port\" bits=\"0:15\" default=\"0x1314\"/>\n\
            <field name=\"Dst_Port\" bits=\"16:31\"  default=\"0x1315\"/>\n\
            <field name=\"Length\" bits=\"32:47\" />\n\
            <field name=\"Checksum\" bits=\"48:63\" />\n\
        </structure>\n\
       <structure name=\"GTP_V1_base\" size=\"64\" order=\"msb\">\n\
            <field name=\"version\" bits=\"0:2\"/>\n\
            <field name=\"PT\" bits=\"3:3\"/>\n\
            <field name=\"Reserved\" bits=\"4:4\"/>\n\
            <field name=\"E\" bits=\"5:5\"/>\n\
            <field name=\"S\" bits=\"6:6\"/>\n\
            <field name=\"N\" bits=\"7:7\"/>\n\
            <field name=\"Message_Type\" bits=\"8:15\"/>\n\
            <field name=\"Message_Length\" bits=\"16:31\"/>\n\
            <field name=\"TEID\" bits=\"32:63\"/>\n\
        </structure>\n\
       <structure name=\"GTP_V1_additional\" size=\"32\" order=\"msb\">\n\
            <field name=\"SN\" bits=\"0:15\"/>\n\
            <field name=\"NPDU_number\" bits=\"16:23\"/>\n\
            <field name=\"Next_extension_header_type\" bits=\"24:31\"/>\n\
        </structure>\n\
        <structure name=\"TCP_Flags\" size=\"9\" order=\"msb\">\n\
             <field name=\"NS\" bits=\"0:0\"/>\n\
             <field name=\"CWR\" bits=\"1:1\"/>\n\
             <field name=\"ECE\" bits=\"2:2\"/>\n\
             <field name=\"Base\" bits=\"3:8\"/>\n\
         </structure>\n\
        <structure name=\"TCP\" size=\"160\" order=\"msb\">\n\
            <field name=\"Src_Port\" bits=\"0:15\" />\n\
            <field name=\"Dst_Port\" bits=\"16:31\" />\n\
            <field name=\"SEQ\" bits=\"32:63\" />\n\
            <field name=\"ACK\" bits=\"64:95\" />\n\
            <field name=\"Data_Offset\" bits=\"96:99\" />\n\
            <field name=\"Reserved\" bits=\"100:102\" />\n\
            <field name=\"Control\" bits=\"103:111\" expansion=\"TCP_Flags\"/>\n\
            <field name=\"Win\" bits=\"112:127\" />\n\
            <field name=\"Checksum\" bits=\"128:143\" />\n\
            <field name=\"Urgent\" bits=\"144:159\" />\n\
        </structure>\n\
        <structure name=\"SCTP\" size=\"96\" order=\"msb\">\n\
            <field name=\"Src_Port\" bits=\"0:15\" />\n\
            <field name=\"Dst_Port\" bits=\"16:31\" />\n\
            <field name=\"Verification_Tag\" bits=\"32:63\" />\n\
            <field name=\"Checksum\" bits=\"64:95\" />            \n\
        </structure>\n\
        <structure name=\"ARP\" size=\"224\" order=\"msb\">\n\
            <field name=\"Hw_Type\" bits=\"0:15\"/>\n\
            <field name=\"Proto_Type\" bits=\"16:31\"/>\n\
            <field name=\"Hw_Size\" bits=\"32:39\"/>\n\
            <field name=\"Proto_Size\" bits=\"40:47\"/>\n\
            <field name=\"Opcode\" bits=\"48:63\"/>\n\
            <field name=\"SRC_MAC\" bits=\"64:111\" type=\"mac\" default=\"00:11:22:33:44:55\"/>\n\
            <field name=\"Sender_IP\" bits=\"112:143\" type=\"ip4\" default=\"192.1.1.10\"/>\n\
            <field name=\"DST_MAC\" bits=\"144:191\" type=\"mac\" default=\"00:66:77:88:99:AA\"/>\n\
            <field name=\"Target_IP\" bits=\"192:223\" type=\"ip4\" default=\"195.1.1.15\"/>\n\
        </structure>\n\
        <structure name=\"ETH_OAM\" size=\"600\" expansion=\"Dynamic\" order=\"msb\">\n\
            <option expansion=\"ETH_OAM_CCM\" OAM_Opcode=\"CCM\" />\n\
            <option expansion=\"ETH_OAM_LB\" OAM_Opcode=\"LBM\" trim=\"MS\" />\n\
            <option expansion=\"ETH_OAM_LB\" OAM_Opcode=\"LBR\" trim=\"MS\" />\n\
            <option expansion=\"ETH_OAM_LMM\" OAM_Opcode=\"LMM\" trim=\"MS\" />\n\
            <option expansion=\"ETH_OAM_LMR\" OAM_Opcode=\"LMR\" trim=\"MS\" />\n\
            <option expansion=\"ETH_OAM_DMM\" OAM_Opcode=\"DMM\" trim=\"MS\" />\n\
            <option expansion=\"ETH_OAM_DMR\" OAM_Opcode=\"DMR\" trim=\"MS\" />\n\
            <!-- Add more opcodes -->\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
     ";

const char *NetworkStructures_3="   </structure>\n\
        <structure name=\"ETH_OAM_CCM\" size=\"600\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"OAM_CCM_Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"Sequence_Number\" bits=\"32:63\" />\n\
            <field name=\"MEP_ID\" bits=\"64:79\" />\n\
            <field name=\"MEG_ID\" bits=\"80:463\" />\n\
            <field name=\"TxFCf\" bits=\"464:495\" />\n\
            <field name=\"RxFCb\" bits=\"496:527\" />\n\
            <field name=\"TxFCb\" bits=\"528:559\" />\n\
            <field name=\"Reserved\" bits=\"560:591\" />\n\
            <field name=\"EndTLV\" bits=\"592:599\" />\n\
        </structure>\n\
        <structure name=\"OAM_CCM_Flags\" size=\"8\">\n\
            <field name=\"OAM_CCM_Period\" bits=\"2:0\" />\n\
            <field name=\"RDI\" bits=\"7:7\" />\n\
        </structure>\n\
        <structure name=\"ETH_OAM_LMM\" size=\"136\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"TxFCf\" bits=\"32:63\" />\n\
            <field name=\"Reserved\" bits=\"64:127\" />\n\
            <field name=\"EndTLV\" bits=\"128:135\" />\n\
        </structure>\n\
        <structure name=\"ETH_OAM_LMR\" size=\"136\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"TxFCf\" bits=\"32:63\" />\n\
            <field name=\"RxFCf\" bits=\"64:95\" />\n\
            <field name=\"TxFCb\" bits=\"96:127\" />\n\
            <field name=\"EndTLV\" bits=\"128:135\" />\n\
        </structure>\n\
        <structure name=\"ETH_OAM_DMM\" size=\"296\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"TxTimeStampf\" bits=\"32:95\" />\n\
            <field name=\"Reserved\" bits=\"96:287\" />\n\
            <field name=\"EndTLV\" bits=\"288:295\" />\n\
        </structure>\n\
        <structure name=\"ETH_OAM_DMR\" size=\"296\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"TxTimeStampf\" bits=\"32:95\" />\n\
            <field name=\"RxTimeStampf\" bits=\"96:159\" />\n\
            <field name=\"TxTimeStampb\" bits=\"160:223\" />\n\
            <field name=\"Reserved\" bits=\"224:287\" />\n\
            <field name=\"EndTLV\" bits=\"288:295\" />\n\
        </structure>\n\
        <structure name=\"ETH_OAM_LB\" size=\"72\" order=\"msb\">\n\
            <field name=\"MEL\" bits=\"0:2\" />\n\
            <field name=\"Version\" bits=\"3:7\" />\n\
            <field name=\"OAM_Opcode\" bits=\"8:15\" />\n\
            <field name=\"Flags\" bits=\"16:23\" />\n\
            <field name=\"TLV_Offset\" bits=\"24:31\" />\n\
            <field name=\"Sequence_Number\" bits=\"32:63\" />\n\
            <field name=\"End_TLV\" bits=\"64:71\" />\n\
        </structure>\n\
        <structure name=\"BFD\" size=\"192\" order=\"msb\">";

const char *NetworkStructures_4="\n\
            <field name=\"Version\" bits=\"0:2\" />\n\
            <field name=\"Diag\" bits=\"3:7\" />\n\
            <field name=\"Sta\" bits=\"8:9\" />\n\
            <field name=\"P\" bits=\"10:10\" />\n\
            <field name=\"F\" bits=\"11:11\" />\n\
            <field name=\"C\" bits=\"12:12\" />\n\
            <field name=\"A\" bits=\"13:13\" />\n\
            <field name=\"D\" bits=\"14:14\" />\n\
            <field name=\"M\" bits=\"15:15\" />\n\
            <field name=\"Detect_Multiplier\" bits=\"16:23\" />\n\
            <field name=\"Length\" bits=\"24:31\" />\n\
            <field name=\"My_Disc\" bits=\"32:63\" />\n\
            <field name=\"Your_Disc\" bits=\"64:95\" />\n\
            <field name=\"Min_Tx\" bits=\"96:127\" />\n\
            <field name=\"Min_RX\" bits=\"128:159\" />\n\
            <field name=\"Min_Echo_RX\" bits=\"160:191\" />\n\
        </structure>\n\
        <structure name=\"VXLAN\" size=\"64\" order=\"msb\">\n\
            <field name=\"VXLAN_Flags\" bits=\"0:7\"/>\n\
            <field name=\"VNI\" bits=\"32:55\"/>\n\
        </structure>\n\
        <structure name=\"VXLAN_Flags\" size=\"8\" order=\"msb\">\n\
            <field name=\"I\" bits=\"4:4\"/>\n\
        </structure>\n\
        <structure name=\"VXLAN_GPE\" size=\"64\" order=\"msb\">\n\
            <field name=\"GPE_Flags\" bits=\"0:7\"/>\n\
            <field name=\"GPE_Next_Protocol\" bits=\"24:31\"/>\n\
            <field name=\"VNI\" bits=\"32:55\"/>\n\
        </structure>\n\
        <structure name=\"GPE_Flags\" size=\"8\" order=\"msb\">\n\
            <field name=\"Ver\" bits=\"2:3\"/>\n\
            <field name=\"I\" bits=\"4:4\"/>\n\
            <field name=\"P\" bits=\"5:5\"/>\n\
            <field name=\"B\" bits=\"6:6\"/>\n\
            <field name=\"O\" bits=\"7:7\"/>\n\
        </structure>\n\
        <structure name=\"Segment_ID\" size=\"128\" order=\"msb\">\n\
            <field name=\"Address\" bits=\"0:127\" type=\"ip6\"/>\n\
        </structure>\n\
        <structure name=\"SRv6\" size=\"64\" order=\"msb\">\n\
            <field name=\"Next_Header\" bits=\"0:7\"/>\n\
            <field name=\"Header_Length\" bits=\"8:15\"/>\n\
            <field name=\"Routing_Type\" bits=\"16:23\"/>\n\
            <field name=\"Segments_Left\" bits=\"24:31\"/>\n\
            <field name=\"Last_Entry\" bits=\"32:39\"/>\n\
            <field name=\"U_Flag\" bits=\"40\"/>\n\
            <field name=\"P_Flag\" bits=\"41\"/>\n\
            <field name=\"O_Flag\" bits=\"42\"/>\n\
            <field name=\"A_Flag\" bits=\"43\"/>\n\
            <field name=\"H_Flag\" bits=\"44\"/>\n\
            <field name=\"U_Flags\" bits=\"45:47\"/>\n\
            <field name=\"Tag\" bits=\"48:63\"/>\n\
            <!-- Parsed dynamically\n\
            <field name=\"SegmentIDs\" bits=\"64:1471\"/>\n\
            -->\n\
        </structure>\n\
        <structure name=\"GRE\" size=\"32\" order=\"msb\">\n\
            <field name=\"C\" bits=\"0:0\"/>\n\
            <field name=\"R\" bits=\"1:1\"/>\n\
            <field name=\"K\" bits=\"2:2\"/>\n\
            <field name=\"S(Seq)\" bits=\"3:3\"/>\n\
            <field name=\"s(Strict)\" bits=\"4:4\"/>\n\
            <field name=\"Recur\" bits=\"5:7\"/>\n\
            <field name=\"Flags\" bits=\"8:12\"/>\n\
            <field name=\"Ver\" bits=\"13:15\"/>\n\
            <field name=\"Protocol\" bits=\"16:31\" resolution=\"ETH_Type\"/>\n\
        </structure>\n\
        <structure name=\"GRE_Checksum\" size=\"16\" order=\"msb\">\n\
            <field name=\"Checksum\" bits=\"0:15\"/>\n\
        </structure>\n\
        <structure name=\"GRE_Offset\" size=\"16\" order=\"msb\">\n\
            <field name=\"Offset\" bits=\"0:15\"/>\n\
        </structure>\n\
        <structure name=\"GRE_Key\" size=\"32\" order=\"msb\">\n\
            <field name=\"Key\" bits=\"0:31\"/>\n\
        </structure>\n\
        <structure name=\"GRE_Sequence_Number\" size=\"32\" order=\"msb\">\n\
            <field nam";

const char *NetworkStructures_5="e=\"Rx\" bits=\"0:15\"/>\n\
            <field name=\"Tx\" bits=\"16:31\"/>\n\
        </structure>\n\
        <structure name=\"GRE_Routing\" size=\"32\" order=\"msb\">\n\
            <field name=\"Routing\" bits=\"0:31\"/>\n\
        </structure>\n\
        \n\
        <structure name=\"IEEE_1588\" size=\"272\" order=\"msb\">\n\
            <field name=\"Transport_Specific\" bits=\"0:3\"/>\n\
            <field name=\"Message_Type\" bits=\"4:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Version_PTP\" bits=\"12:15\"/>\n\
            <field name=\"Message_Length\" bits=\"16:31\"/>\n\
            <field name=\"Domain_Number\" bits=\"32:39\"/>\n\
            <field name=\"Reserved\" bits=\"40:47\"/>\n\
            <field name=\"Flag_Field\" bits=\"48:63\"/>\n\
            <field name=\"Correction_Field\" bits=\"64:127\"/>\n\
            <field name=\"Reserved\" bits=\"128:159\"/>\n\
            <field name=\"Source_Port_Identity\" bits=\"160:239\"/>\n\
            <field name=\"Sequence_Id\" bits=\"240:255\"/>\n\
            <field name=\"Control_Field\" bits=\"256:263\"/>\n\
            <field name=\"Log_Message_Interval\" bits=\"264:271\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_LSO\" size=\"128\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Length\" bits=\"16:31\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"32:47\"/>\n\
            <field name=\"Session_ID\" bits=\"48:63\"/>\n\
            <field name=\"Ns\" bits=\"64:79\"/>\n\
            <field name=\"Nr\" bits=\"80:95\"/>\n\
            <field name=\"Offset_Size\" bits=\"96:111\"/>\n\
            <field name=\"Offset_Padding\" bits=\"112:127\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_LS\" size=\"96\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Length\" bits=\"16:31\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"32:47\"/>\n\
            <field name=\"Session_ID\" bits=\"48:63\"/>\n\
            <field name=\"Ns\" bits=\"64:79\"/>\n\
            <field name=\"Nr\" bits=\"80:95\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_LO\" size=\"96\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Length\" bits=\"16:31\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"32:47\"/>\n\
            <field name=\"Session_ID\" bits=\"48:63\"/>\n\
            <field name=\"Offset_Size\" bits=\"64:79\"/>\n\
            <field name=\"Offset_Padding\" bits=\"80:95\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_L\" size=\"64\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1";

const char *NetworkStructures_6="\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Length\" bits=\"16:31\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"32:47\"/>\n\
            <field name=\"Session_ID\" bits=\"48:63\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_Base\" size=\"48\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"16:31\"/>\n\
            <field name=\"Session_ID\" bits=\"32:47\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_SO\" size=\"112\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"16:31\"/>\n\
            <field name=\"Session_ID\" bits=\"32:47\"/>\n\
            <field name=\"Ns\" bits=\"48:63\"/>\n\
            <field name=\"Nr\" bits=\"64:79\"/>\n\
            <field name=\"Offset_Size\" bits=\"80:95\"/>\n\
            <field name=\"Offset_Padding\" bits=\"96:111\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_S\" size=\"80\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"16:31\"/>\n\
            <field name=\"Session_ID\" bits=\"32:47\"/>\n\
            <field name=\"Ns\" bits=\"48:63\"/>\n\
            <field name=\"Nr\" bits=\"64:79\"/>\n\
        </structure>\n\
        <structure name=\"L2TP_O\" size=\"80\" order=\"msb\">\n\
            <field name=\"T\" bits=\"0:0\"/>\n\
            <field name=\"L\" bits=\"1:1\"/>\n\
            <field name=\"Reserved\" bits=\"2:3\"/>\n\
            <field name=\"S\" bits=\"4:4\"/>\n\
            <field name=\"Reserved\" bits=\"5:5\"/>\n\
            <field name=\"O\" bits=\"6:6\"/>\n\
            <field name=\"P\" bits=\"7:7\"/>\n\
            <field name=\"Reserved\" bits=\"8:11\"/>\n\
            <field name=\"Ver\" bits=\"12:15\"/>\n\
            <field name=\"Tunnel_ID\" bits=\"16:31\"/>\n\
            <field name=\"Session_ID\" bits=\"32:47\"/>\n\
            <field name=\"Offset_Size\" bits=\"48:63\"/>\n\
            <field name=\"Offset_Padding\" bits=\"64:79\"/>\n\
        </structure>\n\
        <structure name=\"L2TP\" size=\"128\" expansion=\"Dynamic\" order=\"msb\">\n\
            <option expansion=\"L2TP_LSO\"  L=\"1\" S=\"1\" O=\"1\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_LS\"   L=\"1\" S=\"1\" O=\"0\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_L\"    L=\"1\" S=\"0\" O=\"0";

const char *NetworkStructures_7="\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_LO\"   L=\"1\" S=\"0\" O=\"1\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_SO\"   L=\"0\" S=\"1\" O=\"1\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_S\"    L=\"0\" S=\"1\" O=\"0\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_O\"    L=\"0\" S=\"0\" O=\"1\" trim=\"MS\" />\n\
            <option expansion=\"L2TP_Base\" L=\"0\" S=\"0\" O=\"0\" trim=\"MS\" />\n\
            <field name=\"L\" bits=\"1:1\" />\n\
            <field name=\"S\" bits=\"4:4\" />\n\
            <field name=\"O\" bits=\"6:6\" />\n\
        </structure>\n\
        <structure name=\"PPP_CONST\" size=\"16\" order=\"msb\">\n\
            <field name=\"Address\" bits=\"0:7\"/>\n\
            <field name=\"Control\" bits=\"8:15\"/>\n\
        </structure>\n\
        <structure name=\"PPP_NEXT_PROTOCOL\" size=\"16\" order=\"msb\">\n\
            <field name=\"Next_protocol\" bits=\"0:15\" resolution=\"PPP_Next_Header\"/>\n\
        </structure>\n\
    </signal-structures>\n\
    <signal-params>\n\
        <signal name=\"OAM_Opcode\" size=\"8\">\n\
            <entry value=\"1\" name=\"CCM\" />\n\
            <entry value=\"3\" name=\"LBM\" />\n\
            <entry value=\"2\" name=\"LBR\" />\n\
            <entry value=\"5\" name=\"LTM\" />\n\
            <entry value=\"4\" name=\"LTR\" />\n\
            <entry value=\"33\" name=\"AIS\" />\n\
            <entry value=\"35\" name=\"LCK\" />\n\
            <entry value=\"37\" name=\"TST\" />\n\
            <entry value=\"39\" name=\"Linear_APS\" />\n\
            <entry value=\"40\" name=\"Ring_APS\" />\n\
            <entry value=\"41\" name=\"MCC\" />\n\
            <entry value=\"43\" name=\"LMM\" />\n\
            <entry value=\"42\" name=\"LMR\" />\n\
            <entry value=\"45\" name=\"1DM\" />\n\
            <entry value=\"47\" name=\"DMM\" />\n\
            <entry value=\"46\" name=\"DMR\" />\n\
            <entry value=\"49\" name=\"EXM\" />\n\
            <entry value=\"48\" name=\"EXR\" />\n\
            <entry value=\"51\" name=\"VSM\" />\n\
            <entry value=\"50\" name=\"VSR\" />\n\
            <entry value=\"52\" name=\"CSF\" />\n\
            <entry value=\"55\" name=\"SLM\" />\n\
            <entry value=\"54\" name=\"SLR\" />\n\
        </signal>\n\
        <signal name=\"OAM_CCM_Period\" size=\"3\">\n\
            <entry value=\"0\" name=\"Invalid\" />\n\
            <entry value=\"1\" name=\"3.33ms\" />\n\
            <entry value=\"2\" name=\"10ms\" />\n\
            <entry value=\"3\" name=\"100ms\" />\n\
            <entry value=\"4\" name=\"1s\" />\n\
            <entry value=\"5\" name=\"10s\" />\n\
            <entry value=\"6\" name=\"1min\" />\n\
            <entry value=\"7\" name=\"10min\" />\n\
        </signal>\n\
        <signal name=\"ETH_Type\" size=\"16\">\n\
            <entry value=\"0x0800\" name=\"IPv4\"/>\n\
            <entry value=\"0x8100\" name=\"VLAN\"/>\n\
            <entry value=\"0x8847\" name=\"MPLS\"/>\n\
            <entry value=\"0x8902\" name=\"OAM\"/>\n\
        </signal>\n\
        <signal name=\"GPE_Next_Protocol\" size=\"8\">\n\
            <entry value=\"0x1\" name=\"IPv4\"/>\n\
            <entry value=\"0x2\" name=\"IPv6\"/>\n\
            <entry value=\"0x3\" name=\"ETH\"/>\n\
            <entry value=\"0x4\" name=\"Network_Service_Header\"/>\n\
            <entry value=\"0x5\" name=\"MPLS\"/>\n\
        </signal>\n\
        <signal name=\"BIER_Next_Protocol\" size=\"8\">\n\
            <entry value=\"0\" name=\"Reserved\"/>\n\
            <entry value=\"1\" name=\"MPLS_Downstream\"/>\n\
            <entry value=\"2\" name=\"MPLS_Upstream\"/>\n\
            <entry value=\"3\" name=\"ETH\"/>\n\
            <entry value=\"4\" name=\"IPv4\"/>\n\
            <entry value=\"5\" name=\"OAM\"/>\n\
            <entry value=\"6\" name=\"IPv6\"/>\n\
            <entry value=\"63\" name=\"Reserved\"/>\n\
        </signal>\n\
        <signal name=\"PPP_Next_Header\" ";

const char *NetworkStructures_8="size=\"16\">\n\
            <entry value=\"0x21\" name=\"IPv4\"/>\n\
            <entry value=\"0x57\" name=\"IPv6\"/>\n\
            <entry value=\"0xC021\" name=\"LCP\"/>\n\
            <entry value=\"0x8021\" name=\"NCP\"/>\n\
        </signal>\n\
    </signal-params>\n\
</top>\n\
";

const char *UnsupportedDebugSignals_0="<?xml version=\"1.0\"?>\n\
<signals>\n\
    <!-- List of Signals that do not exist on a specific platform, \n\
    but we will not return an error in validate_signal from tests -->\n\
    <signal block=\"IRPP\" from=\"IPMF2\" name=\"Key_F\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ITPP\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"LLR\" name=\"Packet_Header\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"NIF\" name=\"Header\">\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"VTT5\" name=\"Incoming_Stag_Exist\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"VTT5\" name=\"Incoming_Tag_Exist\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"VTT5\" name=\"Incoming_Tag_Index\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"SEXEM3\" name=\"Hit\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"TCAM\" name=\"Hit_F\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"IPMF3\" name=\"parsing_start_offset\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"IPMF3\" name=\"parsing_start_offset_valid\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"IPMF3\" name=\"parsing";

const char *UnsupportedDebugSignals_1="_start_type\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"IPMF3\" name=\"parsing_start_type_valid\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" from=\"IPMF3\" name=\"visibility\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ERPP\" from=\"Fabric\" name=\"FTMH_TM_Action_Type\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ERPP\" from=\"EPMF\" name=\"context\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ETParser\" name=\"Global_Out_LIF_0\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ETParser\" name=\"Global_Out_LIF_1\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ETParser\" name=\"Global_Out_LIF_2\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ETParser\" name=\"Global_Out_LIF_3\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ETParser\" name=\"packet_header\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"";

const char *UnsupportedDebugSignals_2="BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_FTMH_TC\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_FTMH_DP\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_PPH_In_LIF_Profile\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_PPH_TTL\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_CUD_Out_LIF_0\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_CUD_Out_LIF_1\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_CUD_Out_LIF_2\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_CUD_Out_LIF_3\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"PRP2\" name=\"ACE_Field_PPH_Fwd_Layer_Additiona";

const char *UnsupportedDebugSignals_3="l_Info\">\n\
        <device chip=\"BCM88690_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88690_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"1\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"1\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"FWD\" name=\"vsds\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"FWD\" name=\"ttl\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ENC1\" name=\"vsds\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"ENC1\" name=\"ttl\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"Term\" name=\"forward_code\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" name=\"pp_dsp\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"FWD\" name=\"cud_outlif_or_mcdb_ptr\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
    <signal block=\"ETPP\" from=\"FWD\" name=\"out_pp_port\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
        <device chip=\"BCM88480_A0\"/>\n\
        <device chip=\"BCM88480_B0\"/>\n\
        <device chip=\"BCM88800_A0\"/>\n\
        <device chip=\"BCM88850_A0\"/>\n\
        <device chip=\"BCM88830_A0\"/>\n\
    </signal>\n\
</signals>\n\
";

const char *RestrictedDebugSignals_0="<?xml version=\"1.0\"?>\n\
<signals>\n\
    <!-- List of Signals which exists in specific device,\n\
    for which SDK should not return the read value -->\n\
    <signal block=\"IRPP\" to=\"VTT1\" name=\"Hit\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT1\" name=\"Hit_0\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT1\" name=\"Hit_1\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT2\" name=\"Hit\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT2\" name=\"Hit_0\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT2\" name=\"Hit_1\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT4\" name=\"Hit\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT4\" name=\"Hit_0\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"VTT4\" name=\"Hit_1\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"FWD1\" name=\"Hit\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"FWD1\" name=\"Hit_0\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"FWD1\" name=\"Hit_1\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"FWD1\" name=\"Hit_2\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
    <signal block=\"IRPP\" to=\"FWD1\" name=\"Hit_3\">\n\
        <device chip=\"BCM88690_A0\"/>\n\
        <device chip=\"BCM88690_B0\"/>\n\
    </signal>\n\
</signals>\n\
";

const char *TranslatedDebugSignals_0="<?xml version=\"1.0\"?>\n\
<signals>\n\
    <!-- defining translated from user expected signals to device specific signals \n\
-->\n\
    <UserSignal from=\"NIF\" name=\"Header\">\n\
        <device chip=\"BCM88480_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"0\"/>\n\
        <DeviceSignal from=\"PRT\" to=\"IParser\" name=\"Pkt_Header\"/>\n\
    </UserSignal>\n\
    <UserSignal from=\"NIF\" name=\"PTC\">\n\
        <device chip=\"BCM88480_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88480_B0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88800_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88850_A0\" adapter=\"0\"/>\n\
        <device chip=\"BCM88830_A0\" adapter=\"0\"/>\n\
        <DeviceSignal from=\"PRT\" to=\"IParser\" name=\"PTC\"/>\n\
    </UserSignal>\n\
</signals>\n\
";

const char *TestCases_0="<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n\
<top>\n\
    <packets>\n\
        <packet name=\"simple\">\n\
           <source port=\"200\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH0\">\n\
               <field name=\"DA\" value=\"00:01:02:03:04:05\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"SIP\" value=\"10.20.30.41\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
        <packet name=\"default\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH2\">\n\
               <field name=\"SA\" value=\"00:66:77:88:99:AA\"/>\n\
               <field name=\"DA\" value=\"00:11:22:33:44:55\"/>\n\
               <field name=\"Inner_VLAN.VID\" value=\"24\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"DIP\" value=\"10.01.01.222\"/>\n\
           </proto>\n\
           <proto name=\"TCP\">\n\
               <field name=\"Dst_Port\" value=\"200\"/>\n\
               <field name=\"Control\" value=\"16\"/>\n\
               <field name=\"Win\" value=\"16\"/>\n\
           </proto>\n\
        </packet>\n\
        <!--\n\
          These packet structures are reserved for TDM tests. See \\src\\appl\\ctest\\dnx\\ctest_dnx_tdm.c\n\
          Note that 'length' is the size of the packet, including PTCH.\n\
          a. Sending from CPU to the port which is on loopback:\n\
            So, when actually sent over, say, Ethernet, the legth would be larger by 4 bytes of CRC\n\
            and smaller by 2 bytes of PTCH (So, altogether, a size of 252 here will result in sending\n\
            a packet of size 254 to the loopback port and in receiving that size).\n\
          b. Following that, within the chip, the ETHERNET CRC is removed (-4 bytes) but an internal\n\
            2 bytes CRC is added. Also, FTMH header (4 bytes for 'optimized') is added so the specified\n\
            lenght of 252 above becomes 256 bytes. This is the maximum for Q2A,\n\
          So, maximal size, as sent by CPU, including PTCH, is 252 for Q2A and 507 for\n\
          J2C.\n\
          However, we only set 248 (or 503). \n\
          This is because, if FTMH header is NOT removed by egress editing, then a packet which\n\
          starts with size 248/503 (incl. PTCH) enters egress NIF with size 252 (or 507), which\n\
          is the max allowed (4 bytes of EHERNET CRC are added at the NIF).\n\
          We only need to send this maximal size, and not more, since we have a loopback\n\
          at the egress NIF.\n\
        -->\n\
        <packet name=\"tdm_01\" length=\"248\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH2\">\n\
               <field name=\"SA\" value=\"00:66:77:88:99:AA\"/>\n\
               <field name=\"DA\" value=\"00:11:22:33:44:55\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'TC'\n\
               -->\n\
               <field name=\"Outer_VLAN.PCP\" value=\"6\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'DP'\n\
               -->\n\
               <field name=\"Outer_VLAN.DEI\" value=\"1\"/>\n\
               <field name=\"Outer_VLAN.VID\" value=\"100\"/>\n\
               <field name=\"Inner_VLAN.VID\" value=\"24\"/>\n\
           <field name=\"Type\" value=\"123456\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"DIP\" value=\"10.01.01.222\"/>\n\
               <field name=\"TOS\" value=\"105\"/>\n\
           </proto>\n\
           <proto name=\"TCP\"/>\n\
        </packet>\n\
        <packet name=\"tdm_02\" length=\"503\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH2\">\n\
               <field name=\"SA\" value=\"00:66:77:88:99:AA\"/>\n\
   ";

const char *TestCases_1="            <field name=\"DA\" value=\"00:11:22:33:44:55\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'TC'\n\
               -->\n\
               <field name=\"Outer_VLAN.PCP\" value=\"6\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'DP'\n\
               -->\n\
               <field name=\"Outer_VLAN.DEI\" value=\"1\"/>\n\
               <field name=\"Inner_VLAN.VID\" value=\"24\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"DIP\" value=\"10.01.01.222\"/>\n\
               <field name=\"TOS\" value=\"105\"/>\n\
           </proto>\n\
           <proto name=\"TCP\"/>\n\
        </packet>\n\
        <packet name=\"tdm_03\" length=\"210\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH2\">\n\
               <field name=\"SA\" value=\"00:66:77:88:99:AA\"/>\n\
               <field name=\"DA\" value=\"00:11:22:33:44:55\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'TC'\n\
               -->\n\
               <field name=\"Outer_VLAN.PCP\" value=\"6\"/>\n\
               <!--\n\
                 This field is interpreted by the network processor as 'DP'\n\
               -->\n\
               <field name=\"Outer_VLAN.DEI\" value=\"1\"/>\n\
               <field name=\"Inner_VLAN.VID\" value=\"24\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"DIP\" value=\"10.01.01.222\"/>\n\
               <field name=\"TOS\" value=\"105\"/>\n\
           </proto>\n\
           <proto name=\"TCP\"/>\n\
        </packet>\n\
\n\
        <packet name=\"mpls_ipv4\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH1\">\n\
               <field name=\"DA\" value=\"00:66:77:88:99:AA\"/>\n\
           </proto>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"SIP\" value=\"192.0.0.111\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
        <packet name=\"ipv6\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH1\">\n\
               <field name=\"DA\" value=\"00:66:77:88:99:AA\"/>\n\
           </proto>\n\
           <proto name=\"IPv6\">\n\
               <field name=\"SIP\" value=\"cdef:1234:4321:5678:8765:ab01:01ab:fedc\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
        <packet name=\"mpls_ipv6\">\n\
           <source port=\"201\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH1\">\n\
               <field name=\"DA\" value=\"00:66:77:88:99:AA\"/>\n\
           </proto>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"MPLS\"/>\n\
           <proto name=\"IPv6\">\n\
               <field name=\"SIP\" value=\"cdef:1234:4321:5678:8765:ab01:01ab:fedc\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
        <packet name=\"sa_equals_da\">\n\
           <source port=\"200\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH0\">\n\
               <field name=\"DA\" value=\"00:01:02:03:04:05\"/>\n\
               <field name=\"SA\" value=\"00:01:02:03:04:05\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"SIP\" value=\"10.20.30.41\"/>\n\
           </proto>\n\
        </packet>\n\
        <packet name=\"sat\" length=\"1000\">\n\
           <source port=\"218\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ITMH_base\"/>\n\
           <proto name=\"ETH0\">\n\
               <field name=\"DA\" value=\"00:01:02:03:04:05\"";

const char *TestCases_2="/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"SIP\" value=\"10.20.30.41\"/>\n\
           </proto>\n\
           <stream time=\"5\" rate=\"1000\" burst=\"10000\"/>\n\
        </packet>\n\
        <packet name=\"ipv4_checksum_error\" length=\"256\">\n\
           <source port=\"200\"/>\n\
           <proto name=\"PTCH_2\"/>\n\
           <proto name=\"ETH0\">\n\
               <field name=\"DA\" value=\"00:01:02:03:04:05\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
               <field name=\"SIP\" value=\"10.20.30.41\"/>\n\
               <field name=\"Checksum\" value=\"0x5555\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
        <packet name=\"ipv4_raw\">\n\
           <proto name=\"IPv4\">\n\
                <field name=\"Total_Length\" value=\"160\"/>\n\
           </proto>\n\
        </packet>\n\
        <packet name=\"ipv4_explicit_cs_and_len\" length=\"22\">\n\
           <proto name=\"ETH1\"/>\n\
           <proto name=\"MPLS\">\n\
                <field name=\"TTL\" value=\"0xff\"/>\n\
           </proto>\n\
           <proto name=\"IPv4\">\n\
                <field name=\"Total_Length\" value=\"0xabcd\"/>\n\
                <field name=\"Checksum\" value=\"0xdcba\"/>\n\
           </proto>\n\
           <proto name=\"UDP\"/>\n\
        </packet>\n\
    </packets>\n\
    <signals>\n\
       <set name=\"layer1\">\n\
           <signal name=\"Layer_Protocols.1\" block=\"IRPP\" from=\"VTT1\" value=\"1\"/>\n\
       </set>\n\
       <set name=\"default\">\n\
           <signal name=\"Layer_Protocols.0\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_ETHERNET\"/>\n\
           <signal name=\"Layer_Protocols.1\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_IPV4\"/>\n\
           <signal name=\"Layer_Protocols.2\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_TCP\"/>\n\
       </set>\n\
       <set name=\"mpls_ipv4\">\n\
           <signal name=\"Layer_Protocols.0\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_ETHERNET\"/>\n\
           <signal name=\"Layer_Protocols.1\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_MPLS\"/>\n\
           <signal name=\"Layer_Protocols.2\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_MPLS\"/>\n\
           <signal name=\"Layer_Protocols.3\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_IPV4\"/>\n\
           <signal name=\"Layer_Protocols.4\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_UDP\"/>\n\
       </set>\n\
       <set name=\"mpls_IPv6\">\n\
           <signal name=\"Layer_Protocols.0\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_ETHERNET\"/>\n\
           <signal name=\"Layer_Protocols.1\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_MPLS\"/>\n\
           <signal name=\"Layer_Protocols.2\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_MPLS\"/>\n\
           <signal name=\"Layer_Protocols.3\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_IPV6\"/>\n\
           <signal name=\"Layer_Protocols.4\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_UDP\"/>\n\
       </set>\n\
       <set name=\"IPv6\">\n\
           <signal name=\"Layer_Protocols.0\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_ETHERNET\"/>\n\
           <signal name=\"Layer_Protocols.1\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_IPV6\"/>\n\
           <signal name=\"Layer_Protocols.2\" block=\"IRPP\" from=\"VTT1\" value=\"LAYER_TYPES_UDP\"/>\n\
       </set>\n\
    </signals>\n\
</top>\n\
";

const char *export_config_0="<?xml version=\"1.0\"?>\n\
<top>\n\
    <!--<command line=\"dnx data export\" />\n\
    <command line=\"dnx dbal table dump all\" />-->\n\
</top>\n\
";

const char *export_dump_all_0="<?xml version=\"1.0\"?>\n\
<top>\n\
    <!-- Signals are retrieved as Shared Between Cores (sbc=\"1\") for legacy purposes -->\n\
    <command line=\"sig get all show=hw,nocond\" sbc=\"1\"/>\n\
    <!-- Diagnostic commands -->\n\
    <command line=\"pp vis ekleap full\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ikleap silence=false\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ppi\" category=\"diagnostics\" />\n\
    <command line=\"pp vis pkttm\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fdt\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fer\" category=\"diagnostics\" />\n\
    <command line=\"pp vis term\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ive\" category=\"diagnostics\" />\n\
    <command line=\"pp vis eve\" category=\"diagnostics\" />\n\
    <command line=\"pp vis context\" category=\"diagnostics\" />\n\
</top>\n\
";

const char *export_export_test_0="<?xml version=\"1.0\"?>\n\
<top>\n\
    <!-- Signals are retrieved as Shared Between Cores (sbc=\"1\") for legacy purposes -->\n\
    <!-- command line=\"sig get all show=hw,nocond full=false\" sbc=\"1\"/-->\n\
    <!-- Diagnostic commands -->\n\
    <command line=\"pp vis pkttm\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ppi\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fdt\" category=\"diagnostics\" />\n\
    <command line=\"pp vis SYS_Header\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fer fwd\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fer rpf\" category=\"diagnostics\" />\n\
    <command line=\"pp vis term\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ive\" category=\"diagnostics\" />\n\
    <command line=\"pp vis eve\" category=\"diagnostics\" />\n\
    <command line=\"pp vis eve stage=NaTiVe\" category=\"diagnostics\" />\n\
    <command line=\"pp vis last\" category=\"diagnostics\" />\n\
    <command line=\"pp vis context\" category=\"diagnostics\" />\n\
    <command line=\"pp vis context stage=vtt1\" category=\"diagnostics\" />\n\
    <command line=\"pp vis cos TYpe=PROP\" category=\"diagnostics\" />\n\
    <command line=\"pp vis cos PIPE=INGress\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ikleap\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ekleap\" category=\"diagnostics\" />\n\
</top>\n\
";

const char *export_metadata_0="<?xml version=\"1.0\"?>\n\
<top>\n\
    <!-- Signals are retrieved as Shared Between Cores (sbc=\"1\") for legacy purposes -->\n\
    <command line=\"sig get all show=hw,nocond\" sbc=\"1\"/>\n\
    <!-- Diagnostic commands -->\n\
    <command line=\"pp vis ekleap full\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ikleap silence=false\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ppi\" category=\"diagnostics\" />\n\
    <command line=\"pp vis pkttm\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fdt\" category=\"diagnostics\" />\n\
    <command line=\"pp vis fec\" category=\"diagnostics\" />\n\
    <command line=\"pp vis term\" category=\"diagnostics\" />\n\
    <command line=\"pp vis ive\" category=\"diagnostics\" />\n\
    <command line=\"pp vis eve\" category=\"diagnostics\" />\n\
    <command line=\"pp vis context\" category=\"diagnostics\" />\n\
</top>\n\
";
_INTERNAL_AUTO_GENERATED_ARRAYS_MARKER

shr_error_e
pre_compiled_common_common_xml_to_buf(
    char *filePath,
    char **buf,
    long int * size_p)
{
    char *file_buf;
    long int _internal_size_p;
    long int offset;

    SHR_FUNC_INIT_VARS(NO_UNIT);
    
    *size_p = 0;

    _INTERNAL_AUTO_GENERATED_FILE_SEARCH

    if(!sal_strncmp("DNX-Devices.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(DNX_Devices_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, DNX_Devices_0, sal_strnlen(DNX_Devices_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("NetworkHeadersObjects.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkHeadersObjects_5, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, NetworkHeadersObjects_0, sal_strnlen(NetworkHeadersObjects_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkHeadersObjects_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkHeadersObjects_1, sal_strnlen(NetworkHeadersObjects_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkHeadersObjects_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkHeadersObjects_2, sal_strnlen(NetworkHeadersObjects_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkHeadersObjects_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkHeadersObjects_3, sal_strnlen(NetworkHeadersObjects_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkHeadersObjects_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkHeadersObjects_4, sal_strnlen(NetworkHeadersObjects_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkHeadersObjects_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkHeadersObjects_5, sal_strnlen(NetworkHeadersObjects_5, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("NetworkStructures.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(NetworkStructures_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_5, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_6, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_7, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(NetworkStructures_8, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, NetworkStructures_0, sal_strnlen(NetworkStructures_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_1, sal_strnlen(NetworkStructures_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_2, sal_strnlen(NetworkStructures_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_3, sal_strnlen(NetworkStructures_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_4, sal_strnlen(NetworkStructures_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_4, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_5, sal_strnlen(NetworkStructures_5, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_5, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_6, sal_strnlen(NetworkStructures_6, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_6, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_7, sal_strnlen(NetworkStructures_7, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(NetworkStructures_7, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, NetworkStructures_8, sal_strnlen(NetworkStructures_8, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("UnsupportedDebugSignals.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(UnsupportedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(UnsupportedDebugSignals_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(UnsupportedDebugSignals_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(UnsupportedDebugSignals_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, UnsupportedDebugSignals_0, sal_strnlen(UnsupportedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(UnsupportedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, UnsupportedDebugSignals_1, sal_strnlen(UnsupportedDebugSignals_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(UnsupportedDebugSignals_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, UnsupportedDebugSignals_2, sal_strnlen(UnsupportedDebugSignals_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(UnsupportedDebugSignals_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, UnsupportedDebugSignals_3, sal_strnlen(UnsupportedDebugSignals_3, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("RestrictedDebugSignals.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(RestrictedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, RestrictedDebugSignals_0, sal_strnlen(RestrictedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("TranslatedDebugSignals.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(TranslatedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, TranslatedDebugSignals_0, sal_strnlen(TranslatedDebugSignals_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("TestCases.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(TestCases_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(TestCases_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        _internal_size_p += sal_strnlen(TestCases_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, TestCases_0, sal_strnlen(TestCases_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(TestCases_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, TestCases_1, sal_strnlen(TestCases_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));

        offset += sal_strnlen(TestCases_1, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);
        sal_strncpy(file_buf + offset, TestCases_2, sal_strnlen(TestCases_2, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("export/config.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(export_config_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, export_config_0, sal_strnlen(export_config_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("export/dump_all.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(export_dump_all_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, export_dump_all_0, sal_strnlen(export_dump_all_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("export/export_test.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(export_export_test_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, export_export_test_0, sal_strnlen(export_export_test_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    if(!sal_strncmp("export/metadata.xml", filePath, RHFILE_MAX_SIZE))
    {
        _internal_size_p = 0;
        _internal_size_p += sal_strnlen(export_metadata_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE);

        *size_p = _internal_size_p;
        offset = 0;
        file_buf = sal_alloc(*size_p, "buf");

        sal_strncpy(file_buf, export_metadata_0, sal_strnlen(export_metadata_0, COMMON_COMMON_PRE_COMPILED_STRING_MAX_SIZE));


        *buf = file_buf;
        SHR_EXIT();
    }
    _INTERNAL_AUTO_GENERATED_FILE_SEARCH
    
    SHR_SET_CURRENT_ERR(_SHR_E_EXISTS);
    SHR_EXIT();
exit:
    SHR_FUNC_EXIT;
}


