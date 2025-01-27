/*
 * 
 * 
 * This license is set out in https://raw.githubusercontent.com/Broadcom-Network-Switching-Software/OpenBCM/master/Legal/LICENSE file.
 * 
 * Copyright 2007-2022 Broadcom Inc. All rights reserved.
 *
 */

#ifndef __BCM_PTP_H__
#define __BCM_PTP_H__

#if defined(INCLUDE_PTP)

#include <bcm/types.h>

/* Miscellaneous PTP defines */
#define BCM_PTP_CLOCK_EUID_IEEE1588_SIZE    8          /* Clock EUID size per
                                                          IEEE 1588 standard. */
#define BCM_PTP_MAX_L2_HEADER_LENGTH        64         /* Maximum L2 Header
                                                          length. */
#define BCM_PTP_MAX_NETW_ADDR_SIZE          16         /* Maximum Network
                                                          Address Size. */
#define BCM_PTP_MAX_TOD_FORMAT_STRING       128        /* Maximum Network
                                                          Address Size. */
#define BCM_PTP_EXT_STACK_FAULT_INFO_DEFAULT_MAX_SIZE 1024       /* Recommended maximum
                                                          buffer size for fault
                                                          info. */
#define BCM_PTP_TRACEABILITY_NO_OVERRIDE    0xFF       /* Flag used to clear the
                                                          traceability override
                                                          configuration. */
#define BCM_PTP_IEEE1588_ALL_PORTS          0xFFFF     /* All ports identifier
                                                          (as defined in IEEE
                                                          1588-2008 std,
                                                          sections 7.5.2.3,
                                                          13.12.1 and 15.3.1). */

/* PTP Stack info flags */
#define BCM_PTP_STACK_WITH_ID               0x0001     /* Use the specified PTP
                                                          Stack ID */
#define BCM_PTP_STACK_EXTERNAL_TOP          0x0002     /* Specifies PTP stack
                                                          instance runs on
                                                          external processor */
#define BCM_PTP_STACK_TIMESTAMPER_COMBINED_MODE 0x0004     /* Flag to enable TS0 and
                                                          TS1 timestamper in
                                                          combined mode */

/* PTP Clock info flags */
#define BCM_PTP_CLOCK_FLAGS_TRIGGERED_DELREQ 0x00000001 /* Sync-triggered Delay
                                                          Requests */
#define BCM_PTP_CLOCK_FLAGS_FIXED_DELREQ    0x00000002 /* Fixed-interval Delay
                                                          Requests */
#define BCM_PTP_CLOCK_FLAGS_ONEWAY_BIT      0x00000004 /* One-way operation bit */
#define BCM_PTP_CLOCK_FLAGS_TELECOM_PROFILE_BIT 0x00000008 /* Telecom profile bit */
#define BCM_PTP_CLOCK_FLAGS_DELREQ_ALTMASTER_BIT 0x00000020 /* Alternate master
                                                          Delay_Req messages bit */
#define BCM_PTP_CLOCK_FLAGS_SYNCOAM_BIT     0x00000040 /* Set Sync OAM register,
                                                          and override
                                                          servo-reported phase */
#define BCM_PTP_CLOCK_FLAGS_PROFILE_TYPE_START_BIT 0x00000080 /* Bit 8-11 represents
                                                          profile type */
#define BCM_PTP_CLOCK_FLAGS_TARGETED_DELREQ_DELRESP_TX_BIT 0x00000800 /* Feature to reduce
                                                          replication of delay
                                                          request and delay resp */
#define BCM_PTP_CLOCK_FLAGS_UNTAGGED_DELREQ_DELRESP_TX_BIT 0x00001000 /* Use to send untagged
                                                          delay request and
                                                          delay resp */
#define BCM_PTP_CLOCK_NTP_TOD_UPDATE_DISABLE 0x00002000 /* Flag to disable NTP
                                                          ToD updates */
#define BCM_PTP_CLOCK_PTP_TOD_UPDATE_DISABLE 0x00004000 /* Flag to disable PTP
                                                          ToD updates */
#define BCM_PTP_CLOCK_FLAGS_SIGNALING_MULTI_TLV_BIT 0x20000000 /* Multi-TLV signaling
                                                          message support bit */

/* Maximum Number of Unicast Masters */
#define BCM_PTP_MAX_UNICAST_MASTER_TABLE_ENTRIES 10         

/* Number of Telecom G8265 Profile Packet Masters */
#define BCM_PTP_TELECOM_MAX_NUMBER_PKTMASTERS BCM_PTP_MAX_UNICAST_MASTER_TABLE_ENTRIES 

/* 
 * Specifies PTP PHY clock synchronization is performed on a modular
 * system
 */
#define BCM_PTP_SYNC_PHY_MODULAR    0x0001     

/* Bits in servo configuration flags. */
#define BCM_PTP_SERVO_PHASE_ONLY        (0x01)     /* Phase-only bit. */
#define BCM_PTP_SERVO_LOCK_SWITCH_FREQ  (0x02)     /* Switch-frequency lock bit. */
#define BCM_PTP_SERVO_IGNORE_FREQ       (0x04)     /* Ignore-frequency bit. */
#define BCM_PTP_SERVO_PHASE_HOLDOVER    (0x08)     /* Servo phase holdover bit. */
#define BCM_PTP_SERVO_FREQUENCY_ONLY    (0x10)     /* Frequency only mode */

/* Maximum number of C-TDEV timescales. */
#define BCM_PTP_CTDEV_NUM_TIMESCALES_MAX    (12)       

/* PTP message flag fields bit postition */
#define BCM_PTP_PKT_FLAG_LI_61              0          
#define BCM_PTP_PKT_FLAG_59                 1          
#define BCM_PTP_PKT_FLAG_CUR_UTCOFFS_VAL    2          
#define BCM_PTP_PKT_FLAG_TIMESCALE          3          
#define BCM_PTP_PKT_FLAG_TIME_TRACEABLE     4          
#define BCM_PTP_PKT_FLAG_FREQ_TRACEABLE     5          
#define BCM_PTP_PKT_FLAG_SYNC_UNCERTAIN     6          
#define BCM_PTP_PKT_FLAG_ALT_MASTER         8          
#define BCM_PTP_PKT_FLAG_TWO_STEP           9          
#define BCM_PTP_PKT_FLAG_UNICAST            10         
#define BCM_PTP_PKT_FLAG_PROF_SPEC1         13         
#define BCM_PTP_PKT_FLAG_PROF_SPEC2         14         
#define BCM_PTP_PKT_FLAG_SECURITY           15         

/* PTP Stack ID type */
typedef int bcm_ptp_stack_id_t;

/* PTP Clock Identity type */
typedef uint8 bcm_ptp_clock_identity_t[8];

/* PTP Time of Day Format Types */
typedef enum bcm_ptp_time_type_e {
    bcmPTPTimeDefault   /* Default */
} bcm_ptp_time_type_t;

/* PTP Timesource Types */
typedef enum bcm_ptp_time_source_e {
    bcmPTPTimeSourceAtomicClock = 0x10, /* Atomic Clock */
    bcmPTPTimeSourceGPS = 0x20,         /* Global Positioning System */
    bcmPTPTimeSourceTerRadio = 0x30,    /* Terrestrial Radio */
    bcmPTPTimeSourcePtp = 0x40,         /* PTP-based source */
    bcmPTPTimeSourceNTP = 0x50,         /* Network Time Protocol source */
    bcmPTPTimeSourceHandSet = 0x60,     /* Handset */
    bcmPTPTimeSourceOther = 0x90,       /* Other timesource */
    bcmPTPTimeSourceInternalOsc = 0xA0  /* Internal Oscillator */
} bcm_ptp_time_source_t;

/* PTP Clock Accuracy */
typedef enum bcm_ptp_clock_accuracy_e {
    bcmPTPClockAccuracy25ns = 0x0020,   /* Time is accurate to with 25 ns */
    bcmPTPClockAccuracy100ns = 0x0021,  /* Time is accurate to with 100 ns */
    bcmPTPClockAccuracy250ns = 0x0022,  /* Time is accurate to with 250 ns */
    bcmPTPClockAccuracy1us = 0x0023,    /* Time is accurate to with 1 us */
    bcmPTPClockAccuracy2500ns = 0x0024, /* Time is accurate to with 2500 ns */
    bcmPTPClockAccuracy10us = 0x0025,   /* Time is accurate to with 10 us */
    bcmPTPClockAccuracy25us = 0x0026,   /* Time is accurate to with 25 us */
    bcmPTPClockAccuracy100us = 0x0027,  /* Time is accurate to with 100 us */
    bcmPTPClockAccuracy250us = 0x0028,  /* Time is accurate to with 250 us */
    bcmPTPClockAccuracy1ms = 0x0029,    /* Time is accurate to with 1 ms */
    bcmPTPClockAccuracy2500us = 0x002a, /* Time is accurate to with 2500 us */
    bcmPTPClockAccuracy10ms = 0x002b,   /* Time is accurate to with 10 ms */
    bcmPTPClockAccuracy25ms = 0x002c,   /* Time is accurate to with 25 ms */
    bcmPTPClockAccuracy100ms = 0x002d,  /* Time is accurate to with 100 ms */
    bcmPTPClockAccuracy250ms = 0x002e,  /* Time is accurate to with 250 ms */
    bcmPTPClockAccuracy1s = 0x002f,     /* Time is accurate to with 1 s */
    bcmPTPClockAccuracy10s = 0x0030,    /* Time is accurate to with 10 s */
    bcmPTPClockAccuracyL10s = 0x0031,   /* Time is accurate to > 10 s */
    bcmPTPClockAccuracyUnknown = 0x00FE, /* Time accuracy is unknown */
    bcmPTPClockAccuracyReserved = 0x00FF /* Reserved */
} bcm_ptp_clock_accuracy_t;

/* 
 * Flags to indicate the fields of bcm_ptp_clock_quality_t in
 * bcm_ptp_clock_quality_set/get
 */
#define BCM_PTP_CLOCK_QUALITY_CLASS         (0x1)      
#define BCM_PTP_CLOCK_QUALITY_ACCURACY      (0x2)      
#define BCM_PTP_CLOCK_QUALITY_OFFSET_SCALED_LOG_VARIANCE (0x4)      

/* PTP callback types */
typedef enum bcm_ptp_cb_type_e {
    bcmPTPCallbackTypeManagement, 
    bcmPTPCallbackTypeEvent, 
    bcmPTPCallbackTypeSignal, 
    bcmPTPCallbackTypeFault, 
    bcmPTPCallbackTypeCheckPeers, 
    bcmPTPCallbackCount 
} bcm_ptp_cb_type_t;

/* PTP Clock types */
typedef enum bcm_ptp_clock_type_e {
    bcmPTPClockTypeOrdinary = 1,    /* PTP/1588 Ordinaly Clock, a.k.a OC */
    bcmPTPClockTypeBoundary = 2,    /* PTP/1588 Boundary Clock, a.k.a BC */
    bcmPTPClockTypeTransparent = 3  /* PTP/1588 Transparent Clock, a.k.a TC */
} bcm_ptp_clock_type_t;

/* PTP TOD Source */
typedef enum bcm_ptp_tod_source_e {
    bcmPTPTODSourceNone,        /* TOD Source None */
    bcmPTPTODSourceSerial,      /* TOD Source is UART-0 */
    bcmPTPTODSourceEthernet,    /* TOD Source is Ethernet */
    bcmPTPTODSourceSerial1,     /* TOD Source is UART-1 */
    bcmPTPTODSourceSerial2,     /* TOD Source is UART-2 */
    bcmPTPTODSourceSerial3,     /* TOD Source is UART-3 */
    bcmPTPTODSourceMaster       /* TOD Source is master */
} bcm_ptp_tod_source_t;

/* PTP TOD Formats */
typedef enum bcm_ptp_tod_format_e {
    bcmPTPTODFormatString,      /* PTP TOD format is user specified string */
    bcmPTPTODFormatUBlox,       /* PTP TOD format is as defined in U-Blox spec */
    bcmPTPTODFormatChinaTcom,   /* PTP TOD format is as defined in CCSA spec */
    bcmPTPTODFormatBCM,         /* PTP TOD format is BCM */
    bcmPTPTODFormatBCMTS,       /* PTP TOD format is BCMTS */
    bcmPTPTODFormatG8271        /* PTP TOD format is as specified in ITU-T
                                   G.8271 Annexure A */
} bcm_ptp_tod_format_t;

/* PTP Source Types */
typedef enum bcm_ptp_source_type_e {
    bcmPTPSourceTypePTP,            /* Time source is ptp */
    bcmPTPSourceTypeGpsTimestamp,   /* Time source is GPS */
    bcmPTPSourceTypeSyncETimestamp, /* Time source is Sync-E */
    bcmPTPSourceTypeE1Timestamp,    /* Time source is E1 Timestamp */
    bcmPTPSourceTypeT1Timestamp,    /* Time source is T1 Timestamp */
    bcmPTPSourceTypeRedundancy,     /* Redundant time source */
    bcmPTPSourceTypeFrequencyOnly,  /* Frequency only source */
    bcmPTPSourceTypeModular = 133   /* Modular time source */
} bcm_ptp_source_type_t;

/* PTP Timestamp Source */
typedef int bcm_ptp_timestamp_source_t;

/* PTP SyncE port */
typedef int bcm_ptp_synce_port_t;

/* PTP Delay Mechanism types */
typedef enum bcm_ptp_delay_mechanism_e {
    bcmPTPDelayMechanismEnd2End = 1,    /* PTP Delay mechanism: End to End */
    bcmPTPDelayMechanismPeer2Peer = 2,  /* PTP Delay mechanism: Peer to Peer */
    bcmPTPDelayMechansimDisabled = 0xFE /* PTP Delay mechanism: Disabled */
} bcm_ptp_delay_mechanism_t;

/* PTP messageType  IEEE Std. 1588-2008 */
typedef enum bcm_ptp_message_type_e {
    bcmPTP_MESSAGE_TYPE_SYNC = 0x0,     /* Sync Message */
    bcmPTP_MESSAGE_TYPE_DELAY_REQ = 0x1, /* Delay Request Message */
    bcmPTP_MESSAGE_TYPE_PDELAY_REQ = 0x2, /* Peer Delay Request Message */
    bcmPTP_MESSAGE_TYPE_PDELAY_RESP = 0x3, /* Peer Delay Response Message */
    bcmPTP_MESSAGE_TYPE_FOLLOW_UP = 0x8, /* Follow Up Message */
    bcmPTP_MESSAGE_TYPE_DELAY_RESP = 0x9, /* Delay Response Message */
    bcmPTP_MESSAGE_TYPE_PDELAY_RESP_FOLLOW_UP = 0xA, /* Peer Delay Response Follow Up Message */
    bcmPTP_MESSAGE_TYPE_ANNOUNCE = 0xB, /* Announce Message */
    bcmPTP_MESSAGE_TYPE_SIGNALING = 0xC, /* Signaling Message */
    bcmPTP_MESSAGE_TYPE_MANAGEMENT = 0xD, /* Management Message */
    bcmPTP_MESSAGE_TYPE_ARP = 0xFF      /* ARP Message not in PTP Standard */
} bcm_ptp_message_type_t;

/* PTP tlvType enumeration. Ref. IEEE Std. 1588-2008, Chapter 14.1.1. */
typedef enum bcm_ptp_tlv_type_e {
    bcmPTPTlvTypeManagement = 0x0001,   /* Management TLV type. */
    bcmPTPTlvTypeManagementErrorStatus = 0x0002, /* Management error status TLV type. */
    bcmPTPTlvTypeOrganizationExtension = 0x0003, /* Organization extension TLV type. */
    bcmPTPTlvTypeRequestUnicastTransmission = 0x0004, /* Request unicast transmission TLV
                                           type. */
    bcmPTPTlvTypeGrantUnicastTransmission = 0x0005, /* Grant unicast transmission TLV type. */
    bcmPTPTlvTypeCancelUnicastTransmission = 0x0006, /* Cancel unicast transmission TLV type. */
    bcmPTPTlvTypeAckCancelUnicastTransmission = 0x0007 /* Acknowledge cancel unicast
                                           transmission TLV type. */
} bcm_ptp_tlv_type_t;

typedef struct bcm_ptp_cb_types_s {
    SHR_BITDCL w[_SHR_BITDCLSIZE(bcmPTPCallbackCount)]; 
} bcm_ptp_cb_types_t;

typedef int (*bcm_ptp_ext_stack_io_wr_fn_ptr)(
    void *cookie, 
    uint32 address, 
    uint32 value);

typedef int (*bcm_ptp_ext_stack_io_rd_fn_ptr)(
    void *cookie, 
    uint32 address, 
    uint32 *value);

/* PTP External Stack Processor Info object */
typedef struct bcm_ptp_external_stack_info_s {
    uint32 flags;                       /* Control flags */
    bcm_ptp_stack_id_t id;              /* PTP stack identifier */
    uint16 ethertype;                   /* RCPU EtherType */
    uint16 signature;                   /* RCPU signature */
    uint16 tpid;                        /* RCPU tpid */
    uint16 vlan;                        /* RCPU vlan */
    uint8 vlan_pri;                     /* VLAN priority. External Stack
                                           Processor Only. */
    uint16 reflected_ethertype;         /* RCPU reflected EtherType */
    bcm_mac_t switch_mac;               /* Switch MAC address */
    bcm_mac_t host_mac;                 /* Host MAC address. External Stack
                                           Processor Only. */
    bcm_mac_t top_mac;                  /* ToP stack MAC address. External Stack
                                           Processor Only. */
    bcm_ip_t host_ip_addr;              /* host IPv4 address. External Stack
                                           Processor Only. */
    bcm_ip_t top_ip_addr;               /* ToP IPv4 address. External Stack
                                           Processor Only. */
    bcm_port_t port;                    /* ToP port. External Stack Processor
                                           Only. */
    bcm_ptp_ext_stack_io_rd_fn_ptr read_fn; /* PCI Read Function */
    bcm_ptp_ext_stack_io_wr_fn_ptr write_fn; /* PCI Write Function */
    void *cookie;                       /* User-specified identifer for external
                                           stack */
} bcm_ptp_external_stack_info_t;

/* PTP Stack Info object */
typedef struct bcm_ptp_stack_info_s {
    uint32 flags;                       /* control flags */
    bcm_ptp_stack_id_t id;              /* PTP stack identifier */
    bcm_ptp_external_stack_info_t *ext_stack_info; /* External Stack Info. External Stack
                                           Processor Only. */
} bcm_ptp_stack_info_t;

/* Clock Quality */
typedef struct bcm_ptp_clock_quality_s {
    uint8 clock_class;                  /* Clock Class */
    bcm_ptp_clock_accuracy_t clock_accuracy; /* Clock Accuracy */
    uint16 offset_scaled_log_variance;  /* Offset Scaled Log Variance */
} bcm_ptp_clock_quality_t;

/* PTP Port Identity Structure */
typedef struct bcm_ptp_port_identity_s {
    bcm_ptp_clock_identity_t clock_identity; /* Clock Identity */
    uint16 port_number;                 /* Port Number */
} bcm_ptp_port_identity_t;

/* Clock Instance Information */
typedef struct bcm_ptp_clock_info_s {
    uint32 flags;                       /* Flags */
    int clock_num;                      /* Clock Identifier (numeric) */
    bcm_ptp_clock_identity_t clock_identity; /* Clock Identity */
    bcm_ptp_clock_type_t type;          /* PTP Clock Type */
    uint16 num_ports;                   /* Number of Ports */
    uint8 clock_class;                  /* Clock Class */
    uint8 domain_number;                /* Domain Number */
    uint16 scaled_log_variance;         /* Scaled Log Variance */
    uint8 priority1;                    /* Priority 1 */
    uint8 priority2;                    /* Priority 2 */
    uint8 slaveonly;                    /* Slave Only */
    uint8 twostep;                      /* Two Step */
    uint8 tc_primary_domain;            /* Transparent Clock Primary Domain */
    bcm_ptp_delay_mechanism_t tc_delay_mechanism; /* Transparent Clock Delay Mechanism */
    uint8 announce_receipt_timeout_minimum; /* Announce Receipt Timeout Minimum */
    uint8 announce_receipt_timeout_default; /* Announce Receipt Timeout Default */
    uint8 announce_receipt_timeout_maximum; /* Announce Receipt Timeout Maximum */
    int log_announce_interval_minimum;  /* Log Announce Interval Minimum */
    int log_announce_interval_default;  /* Log Announce Interval Default */
    int log_announce_interval_maximum;  /* Log Announce Interval Maximum */
    int log_sync_interval_minimum;      /* Log Sync Interval Minimum */
    int log_sync_interval_default;      /* Log Sync Interval Default */
    int log_sync_interval_maximum;      /* Log Sync Interval Maximum */
    int log_min_delay_req_interval_minimum; /* Log min PDelay request interval or
                                           log min delay request interval
                                           minimum */
    int log_min_delay_req_interval_default; /* Log min PDelay request interval or
                                           log min delay request interval
                                           default */
    int log_min_delay_req_interval_maximum; /* Log min PDelay request interval or
                                           log min delay request interval
                                           maximum */
    uint8 domain_number_minimum;        /* Domain Number minimum */
    uint8 domain_number_default;        /* Domain Number default */
    uint8 domain_number_maximum;        /* Domain Number maximum */
    uint8 priority1_minimum;            /* Priority 1 minimum */
    uint8 priority1_default;            /* Priority 1 default */
    uint8 priority1_maximum;            /* Priority 1 maximum */
    uint8 priority2_minimum;            /* Priority 2 minimum */
    uint8 priority2_default;            /* Priority 2 default */
    uint8 priority2_maximum;            /* Priority 2 maximum */
    uint8 number_virtual_interfaces;    /* unused */
    uint8 local_priority;               /* Local priority of the clock */
    uint8 max_steps_removed;            /* maxStepsRemoved for the PTP clock */
    uint32 holdover_in_spec_secs;       /* Holdover In-Spec time for the PTP
                                           clock in seconds */
    uint32 sync_receipt_timeout_msecs;  /* Sync Receipt Timeout value in
                                           milliseconds */
    uint32 delay_resp_receipt_timeout_msecs; /* Delay_resp Receipt Timeout value in
                                           milliseconds */
} bcm_ptp_clock_info_t;

/* PTP Clock Dataset flags */
#define BCM_PTP_DATASET_TWOSTEP_ONLY    0x0001     /* Specifies Two-step only */
#define BCM_PTP_DATASET_SLAVE_ONLY      0x0002     /* Specifies Slave Only */

/* PTP Default Dataset */
typedef struct bcm_ptp_default_dataset_s {
    uint32 flags;                       /* Flags */
    uint16 number_ports;                /* Number of ports */
    uint8 priority1;                    /* Priority 1 */
    uint8 priority2;                    /* Priority 2 */
    uint8 domain_number;                /* Domain number */
    bcm_ptp_clock_quality_t clock_quality; /* Clock quality */
    bcm_ptp_clock_identity_t clock_identity; /* Clock Identity */
    uint8 local_priority;               /* local priority of clock */
    uint8 max_steps_removed;            /* maxStepsRemoved for the PTP clock */
} bcm_ptp_default_dataset_t;

/* PTP Current Dataset */
typedef struct bcm_ptp_current_dataset_s {
    uint16 steps_removed;       /* Steps Removed from Master */
    uint64 offset_from_master;  /* Offset from Master in timeinterval (scaled
                                   nanoseconds) */
    uint64 mean_path_delay;     /* Mean Path Delay in nanoseconds */
} bcm_ptp_current_dataset_t;

/* PTP Parent Dataset */
typedef struct bcm_ptp_parent_dataset_s {
    bcm_ptp_port_identity_t parent_port_identity; /* Parent Port Identity */
    uint8 ps;                           /* ps */
    uint16 observed_parent_offset_scaled_log_variance; /* Observed Parent Offset Scaled Log
                                           Variance */
    uint32 observed_parent_clock_phase_change_rate; /* Observed Parent Clock Phase Change
                                           Rate */
    uint8 grandmaster_priority1;        /* Grandmaster Priority 1 */
    bcm_ptp_clock_quality_t grandmaster_clock_quality; /* Grandmaster Clock quality */
    uint8 grandmaster_priority2;        /* Grandmaster Priority 2 */
    bcm_ptp_clock_identity_t grandmaster_identity; /* Grandmaster Identity */
} bcm_ptp_parent_dataset_t;

/* PTP Transparent Clock Default Dataset */
typedef struct bcm_ptp_transparent_clock_default_dataset_s {
    bcm_ptp_clock_identity_t clock_identity; /* Clock Identity */
    uint16 number_ports;                /* Number Of Ports */
    bcm_ptp_delay_mechanism_t delay_mechanism; /* Delay Mechanism */
    uint8 primary_domain;               /* Primary Domain */
} bcm_ptp_transparent_clock_default_dataset_t;

/* PTP Transparent Clock Default Dataset */
typedef struct bcm_ptp_transparent_clock_port_dataset_s {
    bcm_ptp_port_identity_t port_identity; /* Clock Port identity */
    uint8 faulty;                       /* Faulty */
    int log_min_pdelay_req_interval;    /* Log Minimun Peer Delay Interval */
    uint64 peer_mean_path_delay;        /* Peer Mean Path Delay in Nanoseconds */
} bcm_ptp_transparent_clock_port_dataset_t;

/* Coordinated Universal Time (UTC) dataset definiton */
typedef struct bcm_ptp_utc_s {
    uint16 utc_offset;  /* Current UTC offset */
    uint8 leap61;       /* 1-> Plus one second, 0-> No leap second. */
    uint8 leap59;       /* 1-> Minus one second, 0-> No leap second. */
    uint8 utc_valid;    /* 1-> Correct offset to UTC, 0-> No sync to UTC. */
} bcm_ptp_utc_t;

/* Clock data traceability */
typedef struct bcm_ptp_trace_s {
    uint8 time_traceable;           /* Time traceable */
    uint8 frequency_traceable;      /* Frequency traceable */
    uint8 check_trc_flag_enable;    /* Time tracability flag of announce message
                                       will be checked for valid time channel
                                       when enable */
} bcm_ptp_trace_t;

/* PTP Timescale properties */
typedef struct bcm_ptp_timescale_s {
    bcm_ptp_time_source_t time_source;  /* PTP time source */
    uint8 ptp_timescale;                /* PTP timescale */
} bcm_ptp_timescale_t;

/* PTP Time Properties Dataset */
typedef struct bcm_ptp_time_properties_s {
    bcm_ptp_utc_t utc_info;             /* UTC properties */
    bcm_ptp_trace_t trace_info;         /* Trace properties */
    bcm_ptp_timescale_t timescale_info; /* Timescale properties */
    uint32 ptp_pkt_flags;               /* PTP packet flags */
} bcm_ptp_time_properties_t;

/* PTP Network Protocol enumeration (See IEEE 1588, Chapter 7.4.1) */
typedef enum bcm_ptp_protocol_e {
    bcmPTPUDPIPv4 = 1,  /* Ethernet / UDP / IPv4 */
    bcmPTPUDPIPv6 = 2,  /* Ethernet / UDP / IPv6 */
    bcmPTPIEEE8023 = 3  /* Ethernet Layer 2 */
} bcm_ptp_protocol_t;

/* PTP Clock Port Type enumeration. */
typedef enum bcm_ptp_port_type_e {
    bcmPTPPortTypeStandard = 1,         /* Master-or-Slave port type */
    bcmPTPPortTypeMasterOnly = 2,       /* Master-only port type */
    bcmPTPPortTypeSlaveOnly = 3,        /* Slave-only port type */
    bcmPTPPortTypeVirtual = 4,          /* Virtual port type as defined in
                                           G.8275.1(Annex-C) */
    bcmPTPPortTypeCustomizedVirtual = 5 /* Customized virtual port type */
} bcm_ptp_port_type_t;

/* PTP Timestamp Source enumeration. */
typedef enum bcm_ptp_timestamp_mechanism_e {
    bcmPTPToPTimestamps = 0x01,         /* Internal ToP timestamps */
    bcmPTPRCPUTimestamps = 0x02,        /* Timestamps from switch */
    bcmPTPPhyCorrectionTimestamps = 0x11, /* Timestamps from PHY CF update */
    bcmPTPMac32CorrectionTimestamps = 0x12, /* Timestamps from Unimac 32-bit update */
    bcmPTPMac48CorrectionTimestamps = 0x14 /* Timestamps from Unimac 48-bit update */
} bcm_ptp_timestamp_mechanism_t;

/* PTP Clock Port address */
typedef struct bcm_ptp_clock_port_address_s {
    bcm_ptp_protocol_t addr_type;       /* Clock Port address type */
    uint8 address[BCM_PTP_MAX_NETW_ADDR_SIZE]; /* Address */
} bcm_ptp_clock_port_address_t;

/* Bits in Port Rx Packets Criteria Mask */
#define BCM_PTP_RXMAP_ACCEPT_MULTICAST      (0x01)     /* Port should accept
                                                          packets with PTP
                                                          multicast destination
                                                          address */
#define BCM_PTP_RXMAP_MATCH_OUTER_VLAN      (0x02)     /* Port should check
                                                          incoming packet outer
                                                          VLAN vs
                                                          rx_packets_vlan */
#define BCM_PTP_RXMAP_MATCH_INNER_VLAN      (0x04)     /* Port should check
                                                          incoming packet inner
                                                          VLAN vs
                                                          rx_packets_vlan */
#define BCM_PTP_RXMAP_MATCH_INGRESS_PORT    (0x08)     /* Port should check
                                                          incoming ingress port
                                                          vs
                                                          rx_packets_port_mask */
#define BCM_PTP_RXMAP_MATCH_ANY_ADDR        (0x10)     /* Port should NOT check
                                                          incoming destination
                                                          address vs port
                                                          address */

/* PTP TOD UART Parity */
typedef enum bcm_ptp_tod_parity_e {
    bcmPTPTODUartParityNone,    /* TOD UART Parity None */
    bcmPTPTODUartParityOdd,     /* TOD UART Parity Odd */
    bcmPTPTODUartParityEven     /* TOD UART Parity Even */
} bcm_ptp_tod_parity_t;

/* virtual PTP port information */
typedef struct bcm_ptp_clock_port_virtual_info_s {
    uint8 clock_class;                  /* clock class */
    bcm_ptp_clock_accuracy_t clock_accuracy; /* clock accuracy */
    uint16 offset_scaled_log_variance;  /* offset scaled log variance */
    uint16 steps_removed;               /* steps removed */
    uint8 GM_prio2;                     /* GM priority2 */
    int tod_offset_sec;                 /* PTP Offset Seconds Added */
    int tod_offset_ns;                  /* PTP Offset Nanoseconds Added */
    bcm_ptp_tod_format_t format;        /* PTP TOD Format */
    uint8 format_str[BCM_PTP_MAX_TOD_FORMAT_STRING]; /* PTP Format String (null terminated) */
    uint8 mask_str[BCM_PTP_MAX_TOD_FORMAT_STRING]; /* PTP Mask String (null terminated) */
    uint16 ether_type;                  /* EtherType for TOD pkts */
    uint8 onepps_in_gpio;               /* GPIO pin for 1PPS input/output.
                                           Required only for
                                           bcmPTPPortTypeCustomizedVirtual */
    bcm_ptp_tod_source_t tod_source;    /* PTP TOD Source */
    uint32 tod_baud_rate;               /* PTP ToD baud rate */
    int ts_sync_enable;                 /* Enable timestamper sync feature */
    bcm_ptp_tod_parity_t tod_parity;    /* TOD UART PARITY enum value
                                           NONE|ODD|EVEN */
} bcm_ptp_clock_port_virtual_info_t;

/* PTP Clock Port information */
typedef struct bcm_ptp_clock_port_info_s {
    bcm_ptp_clock_port_address_t port_address; /* Clock Port address */
    bcm_mac_t mac;                      /* MAC address */
    uint8 multicast_l2_size;            /* Multicast L2 header size (octets) */
    uint8 multicast_l2[BCM_PTP_MAX_L2_HEADER_LENGTH]; /* Multicast L2 header */
    uint8 multicast_pdelay_l2_size;     /* Multicast Peer-Delay L2 header size
                                           (octets) */
    uint8 multicast_pdelay_l2[BCM_PTP_MAX_L2_HEADER_LENGTH]; /* Multicast Peer-Delay L2 header */
    uint8 multicast_tx_enable;          /* Multicast transmit enable */
    bcm_ptp_port_type_t port_type;      /* Port Type */
    uint8 announce_receipt_timeout;     /* Announce receipt timeout */
    int log_announce_interval;          /* Log Announce interval */
    int log_sync_interval;              /* Log Sync interval */
    int log_min_delay_req_interval;     /* Log Minimum Delay Request interval */
    bcm_ptp_delay_mechanism_t delay_mechanism; /* Delay Mechanism */
    bcm_ptp_timestamp_mechanism_t rx_timestamp_mechanism; /* Receive Timestamp Mechanism */
    uint16 rx_packets_vlan;             /* Port Rx Packets Vlan */
    uint32 rx_packets_port_mask_high32; /* Port Rx Packets Mask High bits */
    uint32 rx_packets_port_mask_low32;  /* Port Rx Packets Mask Low bits */
    uint8 rx_packets_criteria_mask;     /* Port Rx Packets Criteria Mask */
    uint8 local_priority;               /* Local priority of the clock port */
    bcm_ptp_clock_port_virtual_info_t vport_info; /*  configuration of virtual port */
    uint8 ttl;                          /* time-to-live or hop-count 1-255 */
    uint8 ip_dscp;                      /* DSCP value 0-63 */
} bcm_ptp_clock_port_info_t;

/* PTP Clock Port Dataset */
typedef struct bcm_ptp_port_dataset_s {
    bcm_ptp_port_identity_t port_identity; /* Clock Port identity */
    uint8 port_state;                   /* Port state. */
    int log_min_delay_req_interval;     /* Log minimum delay request interval */
    uint64 peer_mean_path_delay;        /* Peer Mean path delay (nanoseconds) */
    int log_announce_interval;          /* Log Announce interval */
    uint8 announce_receipt_timeout;     /* Announce receipt timeout */
    int log_sync_interval;              /* Log synchronization interval */
    bcm_ptp_delay_mechanism_t delay_mechanism; /* Delay Mechanism */
    int log_min_pdelay_req_interval;    /* Log minimum peer delay request
                                           interval */
    uint8 version_number;               /* Version Number */
    uint8 local_priority;               /* clock port's local priority */
    uint8 not_slave;                    /* notSlave config of the clock port */
    int signal_fail;                    /* Boolean indicating signal_fail for a
                                           port */
} bcm_ptp_port_dataset_t;

/* PTP Clock Peer address */
typedef struct bcm_ptp_clock_peer_address_s {
    uint8 raw_l2_header_length;         /* Raw L2 Header Length */
    uint8 raw_l2_header[BCM_PTP_MAX_L2_HEADER_LENGTH]; /* Raw L2 Header */
    bcm_ptp_protocol_t addr_type;       /* Peer Port address type */
    bcm_ip_t ipv4_addr;                 /* Peer IPv4 address */
    bcm_ip6_t ipv6_addr;                /* Peer IPv6 address */
} bcm_ptp_clock_peer_address_t;

/* PTP Peer Info Structure */
typedef struct bcm_ptp_clock_peer_s {
    bcm_ptp_clock_identity_t clock_identity; /* Clock Identity */
    uint16 remote_port_number;          /* Remote Clock Port Number */
    uint16 local_port_number;           /* Local Clock Port Number */
    bcm_ptp_clock_peer_address_t peer_address; /* Peer Port address */
    bcm_ptp_timestamp_mechanism_t tx_timestamp_mech; /* Send Timestamp Mechanism */
    int log_peer_delay_request_interval; /* Log Peer Delay Request Interval */
    int log_sync_interval;              /* Log Sync Interval */
    int announce_receive_timeout;       /* Announce Receive Timeout */
    int log_announce_interval;          /* Log Announce Interval */
    int log_delay_request_interval;     /* Log Delay Request Interval */
    bcm_ptp_delay_mechanism_t delay_mechanism; /* Delay Mechanism */
} bcm_ptp_clock_peer_t;

/* PTP Peer Unicast Master Entry */
typedef struct bcm_ptp_clock_unicast_master_s {
    int log_sync_interval;              /* PTP Clock Log Sync Interval */
    int log_announce_interval;          /* PTP Clock Log Announce Interval */
    int log_query_interval;             /* PTP Clock Log Query Interval */
    int log_min_delay_request_interval; /* PTP Clock Log Minimun Delay Request
                                           Interval */
    bcm_ptp_clock_peer_address_t address; /* PTP Clock Master address */
} bcm_ptp_clock_unicast_master_t;

/* PTP TOD IN */
typedef struct bcm_ptp_tod_input_s {
    bcm_ptp_tod_source_t source;        /* PTP TOD Source */
    bcm_ptp_clock_peer_address_t peer_address; /* Peer Address For TOD Over Ethernet */
    int tod_offset_sec;                 /* PTP Offset Seconds Added */
    int tod_offset_ns;                  /* PTP Offset Nanoseconds Added */
    bcm_ptp_tod_format_t format;        /* PTP TOD Format */
    uint8 format_str[BCM_PTP_MAX_TOD_FORMAT_STRING]; /* PTP Format String (null terminated) */
    uint8 mask_str[BCM_PTP_MAX_TOD_FORMAT_STRING]; /* PTP Mask String (null terminated) */
    uint32 tod_baud_rate;               /* PTP ToD baud rate */
    int ts_sync_enable;                 /* Enable timestamper sync feature */
    bcm_ptp_tod_parity_t tod_parity;    /* TOD UART PARITY enum value
                                           NONE|ODD|EVEN */
} bcm_ptp_tod_input_t;

/* ptp channel configuration flags */
#define BCM_PTP_CHANNEL_SYNCE_CONFIG_NO_L1MUX_SELECT 0x0        /* SyncE input config
                                                          will be done without
                                                          L1 mux config */

/* PTP SyncE Clock type enumeration. */
typedef enum bcm_ptp_synce_clock_type_e {
    bcmPTPSynceClockPrimary = 0x00,     /* PTP SyncE Clock Primary */
    bcmPTPSynceClockSecondary = 0x01    /* PTP SyncE Clock Secondary */
} bcm_ptp_synce_clock_type_t;

/* PTP TOD Channel */
typedef struct bcm_ptp_channel_s {
    bcm_ptp_source_type_t type;         /* PTP Channel Source Type */
    bcm_ptp_timestamp_source_t source;  /* TSGPIO pin index or syncE port index */
    int frequency;                      /* PTP Channel Frequency */
    int tod_index;                      /* PTP Channel Index */
    int freq_priority;                  /* PTP Channel Frequency Priority */
    int freq_enabled;                   /* PTP Channel Frequency Enabled */
    int time_prio;                      /* PTP Channel Time Priority */
    int time_enabled;                   /* PTP Channel Time Enabled */
    int freq_assumed_QL;                /* PTP Channel Requency Assumed QL */
    int time_assumed_QL;                /* PTP Channel Time Assumed QL */
    int assumed_QL_enabled;             /* PTP Channel Assumed QL Enabled */
    int resolution;                     /* PTP Channel Resolution */
    bcm_ptp_synce_port_t synce_input_port; /* PTP SyncE input port */
    bcm_ptp_synce_clock_type_t synce_input_clk_type; /* PTP SyncE Input Clock type */
    uint32 synce_config_flags;          /* PTP synce configuration flags */
} bcm_ptp_channel_t;

/* PTP GPIO PIN */
typedef int bcm_ptp_gpio_pin_t;

/* PTP Signal Out */
typedef struct bcm_ptp_signal_output_s {
    bcm_ptp_gpio_pin_t pin;             /* PTP Signal GPIO pin */
    int frequency;                      /* PTP Signal Frequency */
    int phase_lock;                     /* PTP Phase Lock */
    int pulse_width_ns;                 /* PTP Pulse Width */
    int pulse_offset_ns;                /* PTP Pulse Offset */
    bcm_ptp_synce_port_t synce_output_port; /* PTP SyncE output port */
} bcm_ptp_signal_output_t;

/* PTP TOD OUT */
typedef struct bcm_ptp_tod_output_s {
    bcm_ptp_tod_source_t source;        /* PTP TOD Source */
    bcm_ptp_clock_peer_address_t peer_address; /* Peer Address For TOD Over Ethernet */
    int tod_offset_src;                 /* PTP Offset Seconds Added */
    int tod_offset_ns;                  /* PTP Offset Nanoseconds Added */
    uint32 tod_delay_ns;                /* PTP Delay Added in Nanoseconds */
    bcm_ptp_tod_format_t format;        /* PTP TOD Format */
    int frequency;                      /* PTP Signal Frequency */
    int format_str_len;                 /* PTP Format String Length */
    uint8 format_str[BCM_PTP_MAX_TOD_FORMAT_STRING]; /* PTP Format String (null terminated) */
    uint32 tod_baud_rate;               /* PTP ToD baud rate */
    int pps_out_pin;                    /* GPIO pin [0..5] assoiciated with TOD
                                           out */
    int ts_sync_enable;                 /* Enable timestamper sync feature */
    bcm_ptp_tod_parity_t tod_parity;    /* TOD UART PARITY enum value
                                           NONE|ODD|EVEN */
} bcm_ptp_tod_output_t;

/* PTP Timesource Status */
typedef struct bcm_ptp_timesource_status_s {
    int tod_status;         /* PTP Timesource TOD Status */
    int phase_status;       /* PTP Timesource Phase Status */
    int frequency_status;   /* PTP Timesource Frequency Status */
} bcm_ptp_timesource_status_t;

/* PTP Call Back Function Message Data Type */
typedef struct bcm_ptp_cb_msg_s {
    uint32 flags;                   /* Flags */
    bcm_ptp_protocol_t protocol;    /* PTP Protocol Type */
    int src_addr_offset;            /* Source Address Offset */
    int msg_offset;                 /* Offset to the Start of Message */
    uint32 length;                  /* Length of the Message */
    uint8 *data;                    /* Pointer to addtional data */
} bcm_ptp_cb_msg_t;

/* PTP PHY Sync Function Input Data Type */
typedef struct bcm_ptp_sync_phy_input_s {
    uint32 flags;           /* Flags */
    int framesync_pin;      /* Pin to be used for PHY Framesync (SYNC_IN1) */
    int freq_pin;           /* Pin configured for PHY 4KHz reference.  -1 for BS
                               HB */
    uint64 reference_time;  /* DPLL Reference time to be programmed into PHYs */
} bcm_ptp_sync_phy_input_t;

/* PTP BS TIME INFO GET Function output Data Type */
typedef struct bcm_ptp_bs_time_info_s {
    uint64 bshb0_time;      /* BS0HB TS0 time to be programmed into PHY */
    uint64 bshb1_time;      /* BS1HB TS0 time to be programmed into PHY */
    int64 systime_bs0_sec;  /* BS0HB ptp systime seconds to be programmed into
                               PHY */
    int systime_bs0_nsec;   /* BS0HB ptp systime nseconds to be programmed into
                               PHY */
    int64 systime_bs1_sec;  /* BS1HB ptp systime seconds to be programmed into
                               PHY */
    int systime_bs1_nsec;   /* BS1HB ptp systime nseconds to be programmed into
                               PHY */
} bcm_ptp_bs_time_info_t;

/* PTP Servo Types. */
typedef enum bcm_ptp_servo_type_e {
    bcmPTPServoTypeExt = 0, /* 3rd-party servo. */
    bcmPTPServoTypeBCM = 1  /* Broadcom Phase Profile Servo. */
} bcm_ptp_servo_type_t;

/* PTP Servo FLL State. */
typedef enum bcm_ptp_fll_state_e {
    bcmPTPFLLStateAcquiring,    /* FLL acquiring lock. */
    bcmPTPFLLStateWarmup,       /* FLL warmup state. */
    bcmPTPFLLStateFastLoop,     /* FLL fast loop. */
    bcmPTPFLLStateNormal,       /* FLL normal loop. */
    bcmPTPFLLStateBridge,       /* FLL bridge state. */
    bcmPTPFLLStateHoldover      /* FLL holdover state. */
} bcm_ptp_fll_state_t;

/* PTP Servo State. */
typedef enum bcm_ptp_servo_state_e {
    bcmPtpServoStateAcquiring = bcmPTPFLLStateAcquiring, /*  acquiring lock. */
    bcmPtpServoStateWarmup = bcmPTPFLLStateWarmup, /*  warmup state. */
    bcmPtpServoStateFastLoop = bcmPTPFLLStateFastLoop, /*  fast loop. */
    bcmPtpServoStateNormal = bcmPTPFLLStateNormal, /*  normal loop. */
    bcmPtpServoStateBridge = bcmPTPFLLStateBridge, /*  bridge state. */
    bcmPtpServoStateHoldover = bcmPTPFLLStateHoldover, /*  holdover state. */
    bcmPtpServoStateInitial,            /*  initial state. */
    bcmPtpServoStateUnqualified,        /*  unqualified. */
    bcmPtpServoStateFreqLocked,         /*  freq locked. */
    bcmPtpServoStateTimeLocked,         /*  time locked. */
    bcmPtpServoStateHoldoverInSpec,     /*  holdover in spec. */
    bcmPtpServoStateHoldoverOutOfSpec,  /*  holdover out of spec */
    bcmPtpServoStateFreerun,            /*  free-run. */
    bcmPtpServoStateLast                /*  Last. */
} bcm_ptp_servo_state_t;

/* PTP Servo Locked Status. */
typedef enum bcm_ptp_servo_lock_status_e {
    bcmPTPServoStatusUnlocked,          /* Servo in Unlocked State. */
    bcmPTPServoStatusFreqLocked,        /* Servo only Frequency locked. */
    bcmPTPServoStatusPhaseLocked,       /* Servo only Phase locked. */
    bcmPTPServoStatusFreqPhaseLocked    /* Servo Frequency and Phase both
                                           locked. */
} bcm_ptp_servo_lock_status_t;

/* PTP Timesource Redundant Status */
typedef enum bcm_ptp_redundant_status_e {
    bcm_ptp_redundant_active = 0, 
    bcm_ptp_redundant_standby = 1, 
    bcm_ptp_redundant_transition_to_active = 2, 
    bcm_ptp_redundant_transition_to_standby = 3 
} bcm_ptp_redundant_status_t;

/* Telecom clock type as defined in Table.1 of ITU-T G8275.1 */
typedef enum bcm_ptp_g8275p1_clock_type_e {
    bcmPtpG8275P1ClockTypeTelecomGM = 0, /* Telecom GM - Master-only OC/BC. */
    bcmPtpG8275P1ClockTypeTelecomBC = 1, /* Telecom BC -Boundary clock. */
    bcmPtpG8275P1ClockTypeTelecomTSC = 2 /* Telecom SC - Slave-only OC . */
} bcm_ptp_g8275p1_clock_type_t;

/* Telecom clock state as defined in ITU-T G8275.1 */
typedef enum bcm_ptp_g8275p1_clock_state_e {
    bcmPtpG8275P1ClockStateFreeRun = 0, /* clock not synchronized/synchronizing
                                           to a time source. */
    bcmPtpG8275P1ClockStateLocked = 1,  /* clock synchronized to a time source
                                           with acceptable accuracy. */
    bcmPtpG8275P1ClockStateHoldoverInSpec = 2, /* clock no-longer synchronized to a
                                           time source but with performance
                                           within desired specification. */
    bcmPtpG8275P1ClockStateHoldoverOutOfSpec = 3 /* clock no-longer synchronized to a
                                           time source and performance NOT
                                           within desired specification. */
} bcm_ptp_g8275p1_clock_state_t;

/* 
 * G781 Quality level values that can be mapped to ITU-T G8275.1 specific
 * frequency source category
 */
typedef enum bcm_ptp_g8275p1_quality_level_e {
    bcmPtpG8275P1QlInvalid = 0,         /* Invalid QL. */
    bcmPtpG8275P1QlOptIPrc = 0x10,      /* ITU-T G.781 QL Option I. */
    bcmPtpG8275P1QlOptISsua = 0x11,     /* ITU-T G.781 QL Option I. */
    bcmPtpG8275P1QlOptISsub = 0x12,     /* ITU-T G.781 QL Option I. */
    bcmPtpG8275P1QlOptIIPrs = 0x20,     /* ITU-T G.781 QL Option II. */
    bcmPtpG8275P1QlOptIISt2 = 0x21,     /* ITU-T G.781 QL Option II. */
    bcmPtpG8275P1QlOptIISt3e = 0x22,    /* ITU-T G.781 QL Option II. */
    bcmPtpG8275P1QlNaSlv = 0xff         /* Not Applicable (packet slave). */
} bcm_ptp_g8275p1_quality_level_t;

/* clock traceability information */
typedef struct bcm_ptp_g8275p1_clock_traceability_info_s {
    bcm_ptp_g8275p1_clock_type_t clock_type; /* Telecom clock type */
    bcm_ptp_g8275p1_clock_state_t clock_state; /* Telecom clock state */
    bcm_ptp_g8275p1_quality_level_t ql; /* Clock quality level */
    int freq_traceable;                 /* Boolean value - 1:traceable
                                           0:non-traceable */
} bcm_ptp_g8275p1_clock_traceability_info_t;

/* PTP Telecom G8265 Profile Pktmaster State */
typedef enum bcm_ptp_telecom_g8265_pktmaster_state_e {
    bcm_ptp_telecom_g8265_pktmaster_state_unused = 0, 
    bcm_ptp_telecom_g8265_pktmaster_state_init = 1, 
    bcm_ptp_telecom_g8265_pktmaster_state_valid = 2 
} bcm_ptp_telecom_g8265_pktmaster_state_t;

/* PTP ITU-T G.781 synchronization network options */
typedef enum bcm_ptp_telecom_g8265_network_option_e {
    bcm_ptp_telecom_g8265_network_option_disable = 0, 
    bcm_ptp_telecom_g8265_network_option_I = 1, 
    bcm_ptp_telecom_g8265_network_option_II = 2, 
    bcm_ptp_telecom_g8265_network_option_III = 3 
} bcm_ptp_telecom_g8265_network_option_t;

/* PTP ITU-T G.781 Quality Levels */
typedef enum bcm_ptp_telecom_g8265_quality_level_e {
    bcm_ptp_telecom_g8265_ql_invalid = 0, 
    bcm_ptp_telecom_g8265_ql_I_prc = 0x10, /* ITU-T G.781 QL Option I */
    bcm_ptp_telecom_g8265_ql_I_ssua = 0x11, /* ITU-T G.781 QL Option I */
    bcm_ptp_telecom_g8265_ql_I_ssub = 0x12, /* ITU-T G.781 QL Option I */
    bcm_ptp_telecom_g8265_ql_I_sec = 0x13, /* ITU-T G.781 QL Option I */
    bcm_ptp_telecom_g8265_ql_I_dnu = 0x14, /* ITU-T G.781 QL Option I */
    bcm_ptp_telecom_g8265_ql_II_prs = 0x20, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_stu = 0x21, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_st2 = 0x22, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_tnc = 0x23, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_st3e = 0x24, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_st3 = 0x25, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_smc = 0x26, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_prov = 0x28, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_II_dus = 0x29, /* ITU-T G.781 QL Option II */
    bcm_ptp_telecom_g8265_ql_III_unk = 0x30, /* ITU-T G.781 QL Option III */
    bcm_ptp_telecom_g8265_ql_III_sec = 0x31, /* ITU-T G.781 QL Option III */
    bcm_ptp_telecom_g8265_ql_na_slv = 0xff /* Not Applicable (packet slave) */
} bcm_ptp_telecom_g8265_quality_level_t;

/* PTP Telecom G8265 Packet Timing Signal Fail Data */
typedef struct bcm_ptp_telecom_g8265_ptsf_s {
    uint8 loss_announce;        /* Count of Announce Message Loss */
    uint8 loss_sync;            /* Count of Sync Message Loss */
    uint8 unusable; 
    uint8 loss_timing_sync;     /* Count of Timing Sync Message Loss */
    uint8 loss_timing_sync_ts;  /* Count of Sync Message Timestamps Loss */
    uint8 loss_timing_delay;    /* Count of Timing Delay Request Message Loss */
    uint32 counter; 
    uint64 timestamp; 
} bcm_ptp_telecom_g8265_ptsf_t;

/* PTP Telecom G8265 Message Receipt Timeouts (msec) */
typedef struct bcm_ptp_telecom_g8265_receipt_timeouts_s {
    uint32 announce; 
    uint32 sync; 
    uint32 delay_resp; 
} bcm_ptp_telecom_g8265_receipt_timeouts_t;

/* PTP Telecom G8265 Message Elapsed Times (msec) */
typedef struct bcm_ptp_telecom_g8265_elapsed_times_s {
    uint32 announce; 
    uint32 sync; 
    uint32 sync_ts; 
    uint32 delay_resp; 
} bcm_ptp_telecom_g8265_elapsed_times_t;

/* PTP Telecom G8265 Packet timing and PDV statistics */
typedef struct bcm_ptp_telecom_g8265_pktstats_s {
    uint64 pdv_scaled_allan_var; 
} bcm_ptp_telecom_g8265_pktstats_t;

/* PTP Telecom G8265 Priority */
typedef struct bcm_ptp_telecom_g8265_priority_s {
    uint8 override; 
    uint16 value; 
} bcm_ptp_telecom_g8265_priority_t;

/* PTP Query Window Statistics */
typedef struct bcm_ptp_window_stats_s {
    uint8 min; 
    uint16 max; 
    uint16 fall_events; 
    uint16 rise_events; 
} bcm_ptp_window_stats_t;

/* PTP Telecom G8265 Pckmaster Historical Information and QL Degradation */
typedef struct bcm_ptp_telecom_g8265_hql_s {
    bcm_ptp_window_stats_t clock_class_window; 
    uint8 degrade_ql; 
    uint32 counter; 
    uint64 timestamp; 
} bcm_ptp_telecom_g8265_hql_t;

/* PTP Telecom G8265 Profile Packet Master Selector Data */
typedef struct bcm_ptp_telecom_g8265_selector_s {
    uint8 lockout; 
    uint8 non_reversion; 
    uint8 wait_to_restore; 
    uint64 wait_sec; 
} bcm_ptp_telecom_g8265_selector_t;

/* PTP Telecom G8265 Profile PacketMaster Data */
typedef struct bcm_ptp_telecom_g8265_pktmaster_s {
    bcm_ptp_port_identity_t port_identity; /* Port Identity */
    bcm_ptp_clock_port_address_t port_address; /* Clock Port address */
    uint8 clock_class;                  /* Clock Class */
    bcm_ptp_telecom_g8265_quality_level_t quality_level; /* Quality Level */
    uint8 grandmaster_priority1;        /* Grandmaster Priority1 */
    uint8 grandmaster_priority2;        /* Grandmaster Priority2 */
    bcm_ptp_telecom_g8265_priority_t priority; /* G8265 Priority */
    bcm_ptp_telecom_g8265_selector_t selector; /* G8265 Selector */
    bcm_ptp_telecom_g8265_ptsf_t ptsf;  /* G8265 Ptsf */
    bcm_ptp_telecom_g8265_elapsed_times_t elapsed_times; /* G8265 Elapsed Times */
    bcm_ptp_telecom_g8265_pktstats_t pktstats; /* G8265 Packet Stats */
    bcm_ptp_telecom_g8265_hql_t hql;    /* G8265 HQL */
    bcm_ptp_telecom_g8265_pktmaster_state_t state; /* G8265 Pktmaster State */
    uint32 fmds_counter;                /* G8265 FMDS counter */
} bcm_ptp_telecom_g8265_pktmaster_t;

/* PTP Telecom G8265 Profile Data */
typedef struct bcm_ptp_telecom_g8265_profile_s {
    bcm_ptp_telecom_g8265_network_option_t network_option; /* G8265 Packet Network Option */
    bcm_ptp_telecom_g8265_receipt_timeouts_t receipt_timeouts; /* G8265 Packet Receipt Timeouts */
    bcm_ptp_telecom_g8265_pktstats_t thresholds; /* G8265 Packet Stats Thresholds */
    int previous_gm;                    /* Previous Grandmaster */
    int selected_gm;                    /* Selected Grandmaster */
    bcm_ptp_telecom_g8265_pktmaster_t gm[BCM_PTP_TELECOM_MAX_NUMBER_PKTMASTERS]; /* Grandmaster */
} bcm_ptp_telecom_g8265_profile_t;

/* PTP foreign master data and metadata. */
typedef struct bcm_ptp_foreign_master_entry_s {
    bcm_ptp_port_identity_t port_identity; /* Clock port identity. */
    bcm_ptp_clock_port_address_t address; /* Clock port address. */
    uint8 clockClass;                   /* PTP clockClass. */
    uint8 grandmasterPriority1;         /* GM PTP priority1. */
    uint8 grandmasterPriority2;         /* GM PTP priority2. */
    bcm_ptp_window_stats_t clockClass_window; /* PTP clockClass query-window
                                           statistics. */
    uint32 ms_since_sync;               /* Milliseconds since last Sync message. */
    uint32 ms_since_sync_ts;            /* Milliseconds since last Sync
                                           timestamp message (Sync or
                                           Follow_Up). */
    uint32 ms_since_del_resp;           /* Milliseconds since last Delay_Resp
                                           message. */
    uint16 announce_messages;           /* Number of announce messages. */
    uint64 pdv_scaled_allan_var;        /* MTSD scaled Allan variance (nsec-sq). */
    uint16 offset_scaled_log_variance;  /* log variance field of announce msg. */
    bcm_ptp_clock_accuracy_t clock_accuracy; /* Clock Accuracy */
    uint16 steps_removed;               /* steps removed field of announce msg. */
    bcm_ptp_clock_identity_t grandmaster_identity; /* Grandmaster Id field of announce msg. */
    bcm_gport_t phy_port;               /* module num and phy port of card on
                                           which foreign master is seen */
} bcm_ptp_foreign_master_entry_t;

/* PTP foreign master dataset. */
typedef struct bcm_ptp_foreign_master_dataset_s {
    uint8 num_foreign_masters;          /* Number of foreign masters. */
    uint8 current_best_master;          /* Best foreign master index. */
    bcm_ptp_foreign_master_entry_t foreign_master[10]; /* Foreign masters. */
} bcm_ptp_foreign_master_dataset_t;

/* Peer dataset entry. */
typedef struct bcm_ptp_peer_entry_s {
    uint16 local_port_number;           /* Local port number. */
    bcm_ptp_clock_identity_t clock_identity; /* Peer clock identity. */
    bcm_ptp_clock_port_address_t port_address; /* Peer port address. */
    uint64 tx_announces;                /* Tx Announce messages. */
    uint64 rx_announces;                /* Rx Announce messages. */
    uint64 tx_syncs;                    /* Tx Sync messages. */
    uint64 rx_syncs;                    /* Rx Sync messages. */
    uint64 tx_followups;                /* Tx Follow_Up messages. */
    uint64 rx_followups;                /* Rx Follow_Up messages. */
    uint64 tx_delayreqs;                /* Tx Delay_Req messages. */
    uint64 rx_delayreqs;                /* Rx Delay_Req messages. */
    uint64 tx_delayresps;               /* Tx Delay_Resp messages. */
    uint64 rx_delayresps;               /* Rx Delay_Resp messages. */
    uint64 tx_mgmts;                    /* Tx Management messages. */
    uint64 rx_mgmts;                    /* Rx Management messages. */
    uint64 tx_signals;                  /* Tx Signaling messages. */
    uint64 rx_signals;                  /* Rx Signaling messages. */
    uint64 rejected;                    /* Rejected messages. */
    bcm_gport_t phy_port;               /* module num and phy port of card on
                                           which peer is seen */
    uint16 remote_port_number;          /* Remote clock port number */
} bcm_ptp_peer_entry_t;

/* Packet count statistics. */
typedef struct bcm_ptp_packet_counters_s {
    uint32 packets_transmitted;         /* Packets transmitted. */
    uint32 packets_received;            /* Packets received. */
    uint32 packets_discarded;           /* Packets discarded. */
    uint32 rcpu_encap_packets_received; /* RCPU-encapsulated packets received. */
    uint32 ipv4_packets_received;       /* IPv4 packets received. */
    uint32 ipv6_packets_received;       /* IPv6 packets received. */
    uint32 l2_ptp_packets_received;     /* L2 PTP packets received. */
    uint32 udp_ptp_packets_received;    /* UDP PTP packets received. */
    uint32 enduro_sync_packets_transmitted; /* Enduro sync packets transmitted. */
    uint32 enduro_sync_packets_received; /* Enduro sync packets received. */
    uint32 rx_queue_overflows;          /* Rx queue overflows. */
    uint32 port_packets_transmitted[32]; /* Per-port packets transmitted. */
    uint32 port_packets_received[32];   /* Per-port packets received. */
    uint32 port_packets_discarded[32];  /* Per-port packets discarded. */
} bcm_ptp_packet_counters_t;

/* Phase Offsets for Path Asymmetry. */
typedef struct bcm_ptp_phase_offset_s {
    int64 reported_phase_offset;    /* Report Phase Offset. */
    int64 delta_phase_offset;       /* Delta Phase Offset. */
    int64 fixed_phase_offset;       /* Fixed Phase Offset. */
    int use_fixed_phase_offset;     /* Flag to use fixed phase offset. */
    int phase_slew_rate_ppb;        /* Max slew rate phase offset is changed. */
    uint32 sync_phase_offset_ns;    /* Max offset to adjust by slew. */
    int64 gps_to_ptp_offset_auto;   /* Switching offset computed by FW. */
    int64 gps_to_ptp_offset_manual; /* Switching offset provided by user. */
    int enable_gps_to_ptp_auto;     /* Enable usage of auto offset. */
} bcm_ptp_phase_offset_t;

/* PTP callback result/decision. */
typedef enum bcm_ptp_callback_e {
    bcmPTPCallbackReject,   /* Callback rejects action. */
    bcmPTPCallbackAccept    /* Callback accepts action. */
} bcm_ptp_callback_t;

/* Signaling arbiter message data. */
typedef struct bcm_ptp_cb_signaling_arbiter_msg_s {
    int flags;                          /* Flags. */
    bcm_ptp_stack_id_t ptp_id;          /* PTP stack ID. */
    int clock_num;                      /* PTP clock number. */
    int port_num;                       /* PTP clock port number. */
    bcm_ptp_cb_msg_t *msg;              /* Message data and dimensions. */
    bcm_ptp_clock_info_t *clock_info;   /* PTP clock instance information. */
    bcm_ptp_tlv_type_t *tlv_type;       /* Signaling message TLV type. */
    bcm_ptp_message_type_t *messageType; /* PTP message type. */
    int *logInterMessagePeriod;         /* PTP message logInterMessagePeriod. */
    uint32 *durationField;              /* PTP message service duration. */
    bcm_ptp_clock_peer_t *slave;        /* PTP slave. */
} bcm_ptp_cb_signaling_arbiter_msg_t;

/* Signaling arbiter callback function. */
typedef bcm_ptp_callback_t (*bcm_ptp_signaling_arbiter_t)(
    int unit, 
    bcm_ptp_cb_signaling_arbiter_msg_t *amsg, 
    void *user_data);

/* C-TDEV alarm callback data. */
typedef struct bcm_ptp_ctdev_alarm_data_s {
    uint64 freq_corr_ppt;               /* Frequency correction (ppt). */
    int num_tau;                        /* Number of timescales over which
                                           C-TDEV is calculated. */
    int tau_sec[BCM_PTP_CTDEV_NUM_TIMESCALES_MAX]; /* Timescales, tau. */
    uint64 tdev_psec[BCM_PTP_CTDEV_NUM_TIMESCALES_MAX]; /* C-TDEV(tau). */
    uint32 elapsed_sec;                 /* Elapsed data time for C-TDEV
                                           calculations. */
} bcm_ptp_ctdev_alarm_data_t;

/* C-TDEV alarm callback function. */
typedef int (*bcm_ptp_ctdev_alarm_cb)(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_ctdev_alarm_data_t *ctdev_alarm_data);

/* PTP servo oscillator data types */
typedef enum bcm_ptp_osc_type_e {
    bcmPTPOscTypeRB,        /* Rubidium Oscillator */
    bcmPTPOscTypeDOCXO,     /* Double oven OCXO */
    bcmPTPOscTypeOCXO,      /* OCXO */
    bcmPTPOscTypeMiniOCXO,  /* Mini OCXO */
    bcmPTPOscTypeTCXO       /* TOCXO */
} bcm_ptp_osc_type_t;

/* PTP servo transport mode types */
typedef enum bcm_ptp_transport_mode_e {
    bcmPTPTransportModeEthernet,        /* PTP Ethernet mode */
    bcmPTPTransportModeDSL,             /* PTP DSL mode */
    bcmPTPTransportModeMicrowave,       /* PTP microwave mode */
    bcmPTPTransportModeSONET,           /* PTP SONET mode */
    bcmPTPTransportModeSlowEthernet,    /* PTP Slow Ethernet mode */
    bcmPTPTransportModeHighJitter       /* PTP High Jitter */
} bcm_ptp_transport_mode_t;

/* PTP Servo Configuration Data Type */
typedef struct bcm_ptp_servo_config_s {
    bcm_ptp_osc_type_t osc_type;        /* Local oscillator type */
    bcm_ptp_transport_mode_t transport_mode; /* PTP transport mode */
    uint32 ptp_phase_mode;              /* Bit-mapped phase mode of servo loop */
    int freq_corr_hourly;               /* OCXO frequency offset sampled hourly
                                           - (deprecated) */
    bcm_ptp_timestamp_t time_corr_hourly; /* Timestamp for hourly frequency offset
                                           - (deprecated) */
    int freq_calib_factory;             /* OCXO frequency offset at factory -
                                           (deprecated) */
    bcm_ptp_timestamp_t time_calib_factory; /* Timestamp for factory frequency
                                           offset - (deprecated) */
    uint32 bridge_time;                 /* Bridge time in seconds */
    int freq_corr;                      /* OCXO frequency offset. */
    bcm_ptp_timestamp_t freq_corr_time; /* Timestamp for frequency offset. */
    bcm_ptp_servo_type_t servo;         /* Servo type. */
    uint32 flags;                       /* Servo configuration flags. */
    uint32 filter_profile;              /* Servo filter selection. */
} bcm_ptp_servo_config_t;

/* PTP Servo Status Information. */
typedef struct bcm_ptp_servo_status_s {
    bcm_ptp_servo_state_t servo_state;  /* servo state enumeration. */
    uint32 servo_state_dur;             /* servo state duration (sec). */
    bcm_ptp_servo_lock_status_t lock_status; /* Servo Locked Status
                                           (Locked/Unlocked). */
} bcm_ptp_servo_status_t;

/* ESMC definitions and data types. */
typedef enum bcm_esmc_network_option_e {
    bcm_esmc_network_option_g781_I = 1, 
    bcm_esmc_network_option_g781_II = 2, 
    bcm_esmc_network_option_g781_III = 3 
} bcm_esmc_network_option_t;

typedef enum bcm_esmc_quality_level_e {
    bcm_esmc_g781_I_ql_prc = 0x0100, 
    bcm_esmc_g781_I_ql_ssua = 0x0101, 
    bcm_esmc_g781_I_ql_ssub = 0x0102, 
    bcm_esmc_g781_I_ql_sec = 0x0103, 
    bcm_esmc_g781_I_ql_dnu = 0x0104, 
    bcm_esmc_g781_I_ql_inv0 = 0x010f, 
    bcm_esmc_g781_I_ql_inv1 = 0x011f, 
    bcm_esmc_g781_I_ql_inv3 = 0x013f, 
    bcm_esmc_g781_I_ql_inv5 = 0x015f, 
    bcm_esmc_g781_I_ql_inv6 = 0x016f, 
    bcm_esmc_g781_I_ql_inv7 = 0x017f, 
    bcm_esmc_g781_I_ql_inv9 = 0x019f, 
    bcm_esmc_g781_I_ql_inv10 = 0x01af, 
    bcm_esmc_g781_I_ql_inv12 = 0x01cf, 
    bcm_esmc_g781_I_ql_inv13 = 0x01df, 
    bcm_esmc_g781_I_ql_inv14 = 0x01ef, 
    bcm_esmc_g781_I_ql_failed = 0x01ff, 
    bcm_esmc_g781_I_ql_nsupp = 0x01ff, 
    bcm_esmc_g781_I_ql_unc = 0x01ff, 
    bcm_esmc_g781_II_ql_prs = 0x0200, 
    bcm_esmc_g781_II_ql_stu = 0x0201, 
    bcm_esmc_g781_II_ql_st2 = 0x0202, 
    bcm_esmc_g781_II_ql_tnc = 0x0203, 
    bcm_esmc_g781_II_ql_st3e = 0x0204, 
    bcm_esmc_g781_II_ql_st3 = 0x0205, 
    bcm_esmc_g781_II_ql_smc = 0x0206, 
    bcm_esmc_g781_II_ql_prov = 0x0207, 
    bcm_esmc_g781_II_ql_dus = 0x0208, 
    bcm_esmc_g781_II_ql_inv2 = 0x022f, 
    bcm_esmc_g781_II_ql_inv3 = 0x023f, 
    bcm_esmc_g781_II_ql_inv5 = 0x025f, 
    bcm_esmc_g781_II_ql_inv6 = 0x026f, 
    bcm_esmc_g781_II_ql_inv8 = 0x028f, 
    bcm_esmc_g781_II_ql_inv9 = 0x029f, 
    bcm_esmc_g781_II_ql_inv11 = 0x02bf, 
    bcm_esmc_g781_II_ql_failed = 0x02ff, 
    bcm_esmc_g781_II_ql_nsupp = 0x02ff, 
    bcm_esmc_g781_II_ql_unc = 0x02ff, 
    bcm_esmc_g781_III_ql_unk = 0x0300, 
    bcm_esmc_g781_III_ql_sec = 0x0301, 
    bcm_esmc_g781_III_ql_inv1 = 0x031f, 
    bcm_esmc_g781_III_ql_inv2 = 0x032f, 
    bcm_esmc_g781_III_ql_inv3 = 0x033f, 
    bcm_esmc_g781_III_ql_inv4 = 0x034f, 
    bcm_esmc_g781_III_ql_inv5 = 0x035f, 
    bcm_esmc_g781_III_ql_inv6 = 0x036f, 
    bcm_esmc_g781_III_ql_inv7 = 0x037f, 
    bcm_esmc_g781_III_ql_inv8 = 0x038f, 
    bcm_esmc_g781_III_ql_inv9 = 0x039f, 
    bcm_esmc_g781_III_ql_inv10 = 0x03af, 
    bcm_esmc_g781_III_ql_inv12 = 0x03cf, 
    bcm_esmc_g781_III_ql_inv13 = 0x03df, 
    bcm_esmc_g781_III_ql_inv14 = 0x03ef, 
    bcm_esmc_g781_III_ql_inv15 = 0x03ff, 
    bcm_esmc_g781_III_ql_failed = 0x03ff, 
    bcm_esmc_g781_III_ql_nsupp = 0x03ff, 
    bcm_esmc_g781_III_ql_unc = 0x03ff, 
    bcm_esmc_ql_unresolvable = 0xffff 
} bcm_esmc_quality_level_t;

/* 
 * Extended Synchronous Status Message (SSM) codes for various SyncE
 * clock types as per ITU-T G.8264Amd2
 */
typedef enum bcm_esmc_essm_code_e {
    bcmEsmcEssmCodeNone = 0x0,      /* default operating mode  - no G.8264Amd2
                                       support */
    bcmEsmcEssmCodeEEC = 0xFF,      /* SyncE clock type - EEC/G.781 */
    bcmEsmcEssmCodePRTC = 0x20,     /* SyncE clock type -  PRTC */
    bcmEsmcEssmCodeEPRTC = 0x21,    /* SyncE clock type -  ePRTC */
    bcmEsmcEssmCodeEEEC = 0x22      /* SyncE clock type -  eEEC */
} bcm_esmc_essm_code_t;

typedef enum bcm_esmc_pdu_type_e {
    bcm_esmc_pdu_type_info, 
    bcm_esmc_pdu_type_event 
} bcm_esmc_pdu_type_t;

typedef struct bcm_esmc_pdu_data_s {
    bcm_mac_t source_mac; 
    bcm_esmc_pdu_type_t pdu_type; 
    bcm_esmc_quality_level_t ql; 
    uint8 ssm_code; 
    bcm_esmc_essm_code_t essm_code; /* SyncE clock type as per G.8264amd2 */
    uint8 essm_flag;                /* bit 0 means mixed EEC/eEEC and bit 1 mean
                                       partial chain */
    uint8 essm_eec_count;           /* Number of cascaded EEC as per G.8264amd2 */
    uint8 essm_eeec_count;          /* Number of cascaded eEEC as per G.8264amd2 */
} bcm_esmc_pdu_data_t;

typedef int (*bcm_esmc_rx_cb)(
    int unit, 
    int stack_id, 
    int ingress_port, 
    bcm_esmc_pdu_data_t *pdu_data);

typedef struct bcm_tdpll_input_clock_ql_change_cb_data_s {
    int input_clk_index; 
    bcm_esmc_quality_level_t prior_ql; 
    bcm_esmc_quality_level_t current_ql; 
} bcm_tdpll_input_clock_ql_change_cb_data_t;

typedef int (*bcm_tdpll_input_clock_ql_change_cb)(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_ql_change_cb_data_t *cb_data);

/* T-DPLL definitions and data types. */
#define BCM_TDPLL_INPUT_CLOCK_NUM_GPIO  (6)        
#define BCM_TDPLL_INPUT_CLOCK_NUM_SYNCE (2)        
#define BCM_TDPLL_INPUT_CLOCK_NUM_1588  (2)        
#define BCM_TDPLL_INPUT_CLOCK_NUM_MAX   (BCM_TDPLL_INPUT_CLOCK_NUM_GPIO +  \
                           BCM_TDPLL_INPUT_CLOCK_NUM_SYNCE + \
                           BCM_TDPLL_INPUT_CLOCK_NUM_1588) 

#define BCM_TDPLL_OUTPUT_CLOCK_NUM_BROADSYNC (2)        
#define BCM_TDPLL_OUTPUT_CLOCK_NUM_SYNCE    (4)        
#define BCM_TDPLL_OUTPUT_CLOCK_NUM_1588     (1)        
#define BCM_TDPLL_OUTPUT_CLOCK_NUM_GPIO     (6)        
#define BCM_TDPLL_OUTPUT_CLOCK_NUM_MAX      (BCM_TDPLL_OUTPUT_CLOCK_NUM_BROADSYNC + \
                           BCM_TDPLL_OUTPUT_CLOCK_NUM_SYNCE + \
                           BCM_TDPLL_OUTPUT_CLOCK_NUM_1588 + \
                           BCM_TDPLL_OUTPUT_CLOCK_NUM_GPIO) 

#define BCM_TDPLL_DPLL_INSTANCE_NUM_MAX (BCM_TDPLL_OUTPUT_CLOCK_NUM_MAX - \
                           BCM_TDPLL_OUTPUT_CLOCK_NUM_GPIO) 

typedef enum bcm_tdpll_dpll_bandwidth_units_e {
    bcm_tdpll_dpll_bandwidth_mHz, 
    bcm_tdpll_dpll_bandwidth_Hz, 
    bcm_tdpll_dpll_bandwidth_kHz 
} bcm_tdpll_dpll_bandwidth_units_t;

typedef struct bcm_tdpll_dpll_bandwidth_s {
    uint32 value; 
    bcm_tdpll_dpll_bandwidth_units_t units; 
} bcm_tdpll_dpll_bandwidth_t;

typedef enum bcm_tdpll_dpll_phase_mode_e {
    bcm_tdpll_dpll_phase_mode_none, 
    bcm_tdpll_dpll_phase_mode_pbo, 
    bcm_tdpll_dpll_phase_mode_pboslew 
} bcm_tdpll_dpll_phase_mode_t;

typedef struct bcm_tdpll_dpll_phase_control_s {
    bcm_tdpll_dpll_phase_mode_t mode; 
    int offset_ns; 
} bcm_tdpll_dpll_phase_control_t;

typedef struct bcm_tdpll_dpll_properties_s {
    bcm_tdpll_dpll_bandwidth_t bandwidth; 
    bcm_tdpll_dpll_phase_control_t phase_control; 
} bcm_tdpll_dpll_properties_t;

typedef struct bcm_tdpll_dpll_bindings_s {
    SHR_BITDCL input_clocks[_SHR_BITDCLSIZE(BCM_TDPLL_INPUT_CLOCK_NUM_MAX)]; 
    SHR_BITDCL output_clocks[_SHR_BITDCLSIZE(BCM_TDPLL_OUTPUT_CLOCK_NUM_MAX)]; 
} bcm_tdpll_dpll_bindings_t;

typedef struct bcm_tdpll_dpll_instance_s {
    int index; 
    bcm_tdpll_dpll_bindings_t bindings; 
    bcm_tdpll_dpll_properties_t properties; 
    int reference; 
} bcm_tdpll_dpll_instance_t;

typedef struct bcm_tdpll_input_clock_l1mux_s {
    int index; 
    int port; 
} bcm_tdpll_input_clock_l1mux_t;

typedef struct bcm_tdpll_input_clock_frequency_s {
    uint32 clock; 
    uint32 tsevent; 
    int tsevent_quotient; 
} bcm_tdpll_input_clock_frequency_t;

typedef enum bcm_tdpll_input_clock_monitor_type_e {
    bcm_tdpll_input_clock_monitor_type_soft_warn, 
    bcm_tdpll_input_clock_monitor_type_hard_accept, 
    bcm_tdpll_input_clock_monitor_type_hard_reject 
} bcm_tdpll_input_clock_monitor_type_t;

typedef enum bcm_tdpll_notification_type_e {
    bcmTdpllNotificationTypeRefchange 
} bcm_tdpll_notification_type_t;

typedef enum bcm_tdpll_callback_type_e {
    bcmTdpllCallbackTypeMonitor, 
    bcmTdpllCallbackTypeSelector, 
    bcmTdpllCallbackTypeNotification 
} bcm_tdpll_callback_type_t;

typedef struct bcm_tdpll_input_clock_monitor_s {
    uint64 tsevent_dt; 
    uint64 tsevent_time; 
    uint64 tsevent_num; 
    uint64 dt_ns; 
    uint64 dtref_ns; 
    uint64 dt_sum_ns; 
    uint64 dtref_sum_ns; 
    uint64 prior_evnum; 
    uint32 numev_sum; 
    int freq_error_ppb; 
    int over_soft_warn_threshold; 
    int under_hard_accept_threshold; 
    int over_hard_reject_threshold; 
    uint32 num_missing_tsevent; 
} bcm_tdpll_input_clock_monitor_t;

typedef struct bcm_tdpll_input_clock_select_s {
    bcm_esmc_quality_level_t ql; 
    int priority; 
    int lockout; 
} bcm_tdpll_input_clock_select_t;

typedef struct bcm_tdpll_input_clock_s {
    int index; 
    bcm_tdpll_input_clock_l1mux_t l1mux; 
    bcm_mac_t mac; 
    uint32 state; 
    bcm_tdpll_input_clock_frequency_t frequency; 
    bcm_tdpll_input_clock_monitor_t monitor; 
    bcm_tdpll_input_clock_select_t select; 
    int dpll_use[BCM_TDPLL_DPLL_INSTANCE_NUM_MAX]; 
} bcm_tdpll_input_clock_t;

typedef struct bcm_tdpll_input_clock_monitor_cb_data_s {
    int index; 
    bcm_tdpll_input_clock_monitor_type_t monitor_type; 
    int monitor_value; 
} bcm_tdpll_input_clock_monitor_cb_data_t;

typedef int (*bcm_tdpll_input_clock_monitor_cb)(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_monitor_cb_data_t *cb_data);

typedef struct bcm_tdpll_input_clock_selector_cb_data_s {
    int dpll_index; 
    int prior_selected_clock; 
    int selected_clock; 
} bcm_tdpll_input_clock_selector_cb_data_t;

typedef int (*bcm_tdpll_input_clock_selector_cb)(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_selector_cb_data_t *cb_data);

typedef struct bcm_tdpll_input_clock_ref_change_cb_data_s {
    bcm_tdpll_notification_type_t noti_type; 
    int dpll_index; 
    int prior_selected_clock; 
    int selected_clock; 
} bcm_tdpll_input_clock_ref_change_cb_data_t;

typedef struct bcm_tdpll_input_clock_cb_data_s {
    bcm_tdpll_callback_type_t callback_type; 
    void *cb_info; 
} bcm_tdpll_input_clock_cb_data_t;

typedef int (*bcm_tdpll_input_clock_cb)(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_cb_data_t *cb_data);

typedef struct bcm_tdpll_output_clock_frequency_s {
    uint32 synth; 
    uint32 tsevent; 
    int tsevent_quotient; 
    uint32 deriv; 
    int deriv_quotient; 
} bcm_tdpll_output_clock_frequency_t;

typedef struct bcm_tdpll_output_clock_s {
    int index; 
    uint32 state; 
    bcm_tdpll_output_clock_frequency_t frequency; 
} bcm_tdpll_output_clock_t;

typedef enum bcm_tdpll_holdover_mode_e {
    bcm_tdpll_holdover_mode_instantaneous, 
    bcm_tdpll_holdover_mode_avg1s, 
    bcm_tdpll_holdover_mode_manual, 
    bcm_tdpll_holdover_mode_fast_average, 
    bcm_tdpll_holdover_mode_slow_average 
} bcm_tdpll_holdover_mode_t;

/* Frequency correction */
typedef int32 bcm_tdpll_frequency_correction_t;

typedef struct bcm_tdpll_holdover_data_s {
    bcm_tdpll_frequency_correction_t freq_instantaneous; 
    bcm_tdpll_frequency_correction_t freq_avg1s; 
    bcm_tdpll_frequency_correction_t freq_manual; 
    bcm_tdpll_frequency_correction_t freq_fast_average; 
    bcm_tdpll_frequency_correction_t freq_slow_average; 
    int freq_fast_average_valid; 
    int freq_slow_average_valid; 
    bcm_tdpll_holdover_mode_t mode; 
} bcm_tdpll_holdover_data_t;

typedef struct bcm_ptp_servo_threshold_s {
    int32 bcmPtpServoThresholdFreqLock; 
    int32 bcmPtpServoThresholdFreqUnlock; 
    int32 bcmPtpServoThresholdPhaseLock; 
    int32 bcmPtpServoThresholdPhaseUnlock; 
} bcm_ptp_servo_threshold_t;

/* Clock Port Drop Packet count statistics. */
typedef struct bcm_ptp_clock_port_packet_drop_counters_s {
    uint32 domain_mismatch;             /* default DS domain number mismatch. */
    uint32 memory_alloc_failure;        /* memory allocation failed. */
    uint32 pkt_len_too_short;           /* Invalid packet length. */
    uint32 pkt_rcvd_on_bad_port_state;  /* PTP packet received on bad port state */
    uint32 ptp_profile_mismatch;        /* PTP profile does not match. */
    uint32 clock_port_mismatch;         /* No match to clock port */
    uint32 ptp_packet_parsing_failure;  /* Assigned to clock port, but failed
                                           PTP parsing. */
    uint32 unicast_delreq_from_unknown_slave; /* Unicast Delay Request from unknown
                                           slave. */
    uint32 announce_rcvd_on_master_only_port; /* Announce message received on master
                                           only port. */
    uint32 announce_rcvd_with_invalid_steps_removed_field; /* Announce message with invalid steps
                                           removed field. */
    uint32 announce_from_unknown_unicast_master; /* Announce message received from a
                                           master not present in unicast master
                                           table. */
    uint32 announce_rcvd_on_gps_timesource_ptp_port; /* Announce message received on a ptp
                                           port having timesource as GPS. */
    uint32 sync_rcvd_invalid;           /* Invalid sync packet (e.g duplicate
                                           sync packet). */
    uint32 sync_rcvd_on_ptp_port_without_master; /* sync packet received on port on which
                                           master is not present. */
} bcm_ptp_clock_port_packet_drop_counters_t;

#define BCM_PTP_TELECOM_G8265_MAP_QUALITY_LEVEL_CLOCK_CLASS(ql, clock_class)  \
    do {                                                                         \
        switch (ql) {                                                            \
        case bcm_ptp_telecom_g8265_ql_II_prs:                                    \
            clock_class = 80;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_stu:                                    \
            /* Fall through. */                                                  \
        case bcm_ptp_telecom_g8265_ql_III_unk:                                   \
            clock_class = 82;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_I_prc:                                     \
            clock_class = 84;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_st2:                                    \
            clock_class = 86;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_I_ssua:                                    \
            /* Fall through. */                                                  \
        case bcm_ptp_telecom_g8265_ql_II_tnc:                                    \
            clock_class = 90;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_I_ssub:                                    \
            clock_class = 96;                                                    \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_st3e:                                   \
            clock_class = 100;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_st3:                                    \
            clock_class = 102;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_I_sec:                                     \
            /* Fall through. */                                                  \
        case bcm_ptp_telecom_g8265_ql_III_sec:                                   \
            clock_class = 104;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_smc:                                    \
            clock_class = 106;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_II_prov:                                   \
            clock_class = 108;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_I_dnu:                                     \
            /* Fall through. */                                                  \
        case bcm_ptp_telecom_g8265_ql_II_dus:                                    \
            clock_class = 110;                                                   \
            break;                                                               \
        case bcm_ptp_telecom_g8265_ql_na_slv:                                    \
            /* Not applicable (packet slave). */                                 \
            clock_class = 255;                                                   \
            break;                                                               \
        default:                                                                 \
            /*                                                                   \
             * Mapping unsuccessful.                                             \
             * Maximum alternate PTP profile clockClass value                    \
             * in the range [68,122] used by telecom profile.                    \
             * Ref. IEEE Std. 1588-2008, Clause 7.6.2.4.                         \
             */                                                                  \
            clock_class = 122;                                                   \
        }                                                                        \
    } while (0)                                                                          

#ifndef BCM_HIDE_DISPATCHABLE

/* Initializes the PTP subsystem */
extern int bcm_ptp_init(
    int unit);

/* Shut down the PTP subsystem */
extern int bcm_ptp_detach(
    int unit);

/* Create a PTP stack instance */
extern int bcm_ptp_stack_create(
    int unit, 
    bcm_ptp_stack_info_t *ptp_info);

/* Destroys a PTP stack instance */
extern int bcm_ptp_stack_destroy(
    int unit, 
    bcm_ptp_stack_id_t ptp_id);

/* Gets information associated with a PTP stack instance */
extern int bcm_ptp_stack_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    bcm_ptp_stack_info_t *ptp_info);

/* 
 * Gets information associated with all PTP stack instances, and their
 * number
 */
extern int bcm_ptp_stack_get_all(
    int unit, 
    int max_size, 
    bcm_ptp_stack_info_t *ptp_info, 
    int *no_of_stacks);

/* Set Time Of Day format for PTP stack instance. */
extern int bcm_ptp_time_format_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    bcm_ptp_time_type_t type);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Callback function type for PTP */
typedef int (*bcm_ptp_cb)(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_cb_type_t type, 
    bcm_ptp_cb_msg_t *msg, 
    void *user_data);

#ifndef BCM_HIDE_DISPATCHABLE

/* Register a callback for handling PTP events and messages */
extern int bcm_ptp_cb_register(
    int unit, 
    bcm_ptp_cb_types_t cb_types, 
    bcm_ptp_cb cb, 
    void *user_data);

/* Unregister a callback */
extern int bcm_ptp_cb_unregister(
    int unit, 
    bcm_ptp_cb_types_t cb_types, 
    bcm_ptp_cb cb);

/* Register an arbiter for handling PTP signaling logic */
extern int bcm_ptp_signaling_arbiter_register(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_signaling_arbiter_t arb, 
    void *user_data);

/* Unregister an arbiter for handling PTP signaling logic */
extern int bcm_ptp_signaling_arbiter_unregister(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num);

/* Create PTP Clock instance. */
extern int bcm_ptp_clock_create(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    bcm_ptp_clock_info_t *clock_info);

/* Get PTP Clock instance information. */
extern int bcm_ptp_clock_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_info_t *clock_info);

/* Set PTP Clock instance user description. */
extern int bcm_ptp_clock_user_description_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 *desc);

/* Get PTP Clock instance default dataset. */
extern int bcm_ptp_clock_default_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_default_dataset_t *dataset);

/* Get PTP Clock instance current dataset. */
extern int bcm_ptp_clock_current_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_current_dataset_t *dataset);

/* Get PTP Clock instance parent dataset. */
extern int bcm_ptp_clock_parent_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_parent_dataset_t *dataset);

/* Get PTP Clock instance time properties. */
extern int bcm_ptp_clock_time_properties_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_time_properties_t *data);

/* Get foreign master dataset. */
extern int bcm_ptp_foreign_master_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_foreign_master_dataset_t *data_set);

/* Get PTP Clock priority 1. */
extern int bcm_ptp_clock_priority1_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *priority1);

/* Set PTP Clock priority 1. */
extern int bcm_ptp_clock_priority1_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 priority1);

/* Get PTP Clock priority 2. */
extern int bcm_ptp_clock_priority2_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *priority2);

/* Set PTP Clock priority 2. */
extern int bcm_ptp_clock_priority2_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 priority2);

/* Get PTP Clock local priority . */
extern int bcm_ptp_clock_local_priority_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 *local_priority);

/* Set PTP Clock local priority . */
extern int bcm_ptp_clock_local_priority_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 local_priority);

/* Get PTP Clock's maxStepsRemoved. */
extern int bcm_ptp_clock_max_steps_removed_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 *max_steps_removed);

/* Set PTP Clock's maxStepsRemoved. */
extern int bcm_ptp_clock_max_steps_removed_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 max_steps_removed);

/* Get PTP Clock domain. */
extern int bcm_ptp_clock_domain_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *domain);

/* Set PTP Clock domain. */
extern int bcm_ptp_clock_domain_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 domain);

/* Get PTP Clock slave_only. */
extern int bcm_ptp_clock_slaveonly_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *slaveonly);

/* Set PTP Clock slave_only. */
extern int bcm_ptp_clock_slaveonly_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 slaveonly);

/* Get PTP Clock Accuracy info. */
extern int bcm_ptp_clock_accuracy_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_accuracy_t *accuracy);

/* Set PTP Clock Accuracy info. */
extern int bcm_ptp_clock_accuracy_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_accuracy_t *accuracy);

/* Get PTP Clock quality info. */
extern int bcm_ptp_clock_quality_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_quality_t *clock_quality, 
    uint32 flags);

/* Set PTP Clock Quality info. */
extern int bcm_ptp_clock_quality_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_quality_t clock_quality, 
    uint32 flags);

/* 
 * Gets applicable clock class value for given clock traceability
 * information.
 */
extern int bcm_ptp_g8275p1_traceability_info_clock_class_map(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_g8275p1_clock_traceability_info_t traceability_info, 
    uint8 *clock_class);

/* Get PTP Clock Time. */
extern int bcm_ptp_clock_time_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_timestamp_t *time);

/* Set PTP Clock Time. */
extern int bcm_ptp_clock_time_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_timestamp_t *time);

/* Get PTP Clock Timescale info. */
extern int bcm_ptp_clock_timescale_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_timescale_t *timescale);

/* Set PTP Clock Timescale info. */
extern int bcm_ptp_clock_timescale_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_timescale_t *timescale);

/* Get PTP Clock Traceability info. */
extern int bcm_ptp_clock_traceability_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_trace_t *trace);

/* Set PTP Clock Traceability info. */
extern int bcm_ptp_clock_traceability_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_trace_t *trace);

/* Get PTP Clock UTC info. */
extern int bcm_ptp_clock_utc_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_utc_t *utc);

/* Set PTP Clock UTC info. */
extern int bcm_ptp_clock_utc_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_utc_t *utc);

/* Configure PTP Clock Port information. */
extern int bcm_ptp_clock_port_configure(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_clock_port_info_t *info);

/* Get PTP Clock Port Identity. */
extern int bcm_ptp_clock_port_identity_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_port_identity_t *identity);

/* Get PTP Clock Port Type. */
extern int bcm_ptp_clock_port_type_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_port_type_t *type);

/* Get PTP Clock Port Protocol. */
extern int bcm_ptp_clock_port_protocol_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_protocol_t *protocol);

/* Get PTP Clock Port MAC Address. */
extern int bcm_ptp_clock_port_mac_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_mac_t *mac);

/* Get PTP Clock Port Information. */
extern int bcm_ptp_clock_port_info_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_clock_port_info_t *info);

/* Get PTP Clock Port Dataset Information. */
extern int bcm_ptp_clock_port_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_port_dataset_t *dataset);

/* Get PTP Clock Port Delay Mechanism. */
extern int bcm_ptp_clock_port_delay_mechanism_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 *delay_mechanism);

/* Set PTP Clock Port Delay Mechanism. */
extern int bcm_ptp_clock_port_delay_mechanism_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 delay_mechanism);

/* Set PTP Clock Port Latency. */
extern int bcm_ptp_clock_port_latency_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 latency_in, 
    uint32 latency_out);

/* Get PTP Clock Port Latency. */
extern int bcm_ptp_clock_port_latency_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 *latency_in, 
    uint32 *latency_out);

/* Set PTP Clock Port Delay Asymmetry. */
extern int bcm_ptp_clock_port_delay_asymmetry_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int delay_asymmetry_ns);

/* Get PTP Clock Port Delay Asymmetry. */
extern int bcm_ptp_clock_port_delay_asymmetry_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int *delay_asymmetry_ns);

/* Set PTP Clock Port Log Announce Interval. */
extern int bcm_ptp_clock_port_log_announce_interval_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int interval);

/* Get PTP Clock Port Log Announce interval. */
extern int bcm_ptp_clock_port_log_announce_interval_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int *interval);

/* Get PTP Clock Port Announce Receipt Timeout. */
extern int bcm_ptp_clock_port_announce_receipt_timeout_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 *timeout);

/* Set PTP Clock Port Announce Receipt Timeout. */
extern int bcm_ptp_clock_port_announce_receipt_timeout_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 timeout);

/* Get PTP Clock Port Log Sync Interval. */
extern int bcm_ptp_clock_port_log_sync_interval_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int *interval);

/* Set PTP Clock Port Log Sync Interval. */
extern int bcm_ptp_clock_port_log_sync_interval_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int interval);

/* Get PTP Clock Port Version Number. */
extern int bcm_ptp_clock_port_version_number_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    uint32 *version);

/* Get PTP Clock Port Log Min PDelay Request Interval. */
extern int bcm_ptp_clock_port_log_min_pdelay_req_interval_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int *interval);

/* Set PTP Clock Port Log Min Peer Delay Request Interval. */
extern int bcm_ptp_clock_port_log_min_pdelay_req_interval_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int interval);

/* Get PTP Clock Port Log Min Delay Request Interval. */
extern int bcm_ptp_clock_port_log_min_delay_req_interval_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int *interval);

/* Set PTP Clock Port Log Min Delay Request Interval. */
extern int bcm_ptp_clock_port_log_min_delay_req_interval_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int interval);

/* Enable PTP Clock Port. */
extern int bcm_ptp_clock_port_enable(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port);

/* Disable PTP Clock Port. */
extern int bcm_ptp_clock_port_disable(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port);

/* Add PTP Clock Static Unicast Slave */
extern int bcm_ptp_static_unicast_slave_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_peer_t *slave_info);

/* List PTP Clock Static Unicast Slaves */
extern int bcm_ptp_static_unicast_slave_list(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int max_num_slaves, 
    int *num_slaves, 
    bcm_ptp_clock_peer_t *slave_info);

/* Remove PTP Clock Static Unicast Slave */
extern int bcm_ptp_static_unicast_slave_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_peer_t *slave_info);

/* Clear All PTP Clock Static Unicast Slaves */
extern int bcm_ptp_static_unicast_slave_table_clear(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num);

/* Get PTP Clock Static Unicast Master Table Size */
extern int bcm_ptp_static_unicast_master_table_size_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int *max_table_entries);

/* Add PTP Clock Static Unicast Master Table Entry */
extern int bcm_ptp_static_unicast_master_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_unicast_master_t *master_info);

/* List PTP Static Unicast Master Table */
extern int bcm_ptp_static_unicast_master_list(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int max_num_masters, 
    int *num_masters, 
    bcm_ptp_clock_peer_address_t *master_addr);

/* Remove PTP Clock Static Unicast Master Entry */
extern int bcm_ptp_static_unicast_master_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_peer_address_t *master_info);

/* Clear PTP Clock Static Unicast Master Table */
extern int bcm_ptp_static_unicast_master_table_clear(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num);

/* Add PTP Clock Signaled Unicast Master Entry */
extern int bcm_ptp_signaled_unicast_master_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_unicast_master_t *master_info, 
    uint32 mask);

/* Remove PTP Clock Signaled Unicast Master Entry */
extern int bcm_ptp_signaled_unicast_master_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_peer_address_t *master_info);

/* Clear All PTP Clock Static Unicast Slaves */
extern int bcm_ptp_signaled_unicast_slave_table_clear(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int callstack);

/* List PTP Clock Signaled Unicast Slaves */
extern int bcm_ptp_signaled_unicast_slave_list(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int max_num_slaves, 
    int *num_slaves, 
    bcm_ptp_clock_peer_t *slave_info);

/* Set PTP Default Default Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 duration);

/* Get PTP Default Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 *duration);

/* Set PTP Master's Minimum Allowed Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_min_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 duration_min);

/* Get PTP Master's Minimum Allowed Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_min_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 *duration_min);

/* Set PTP Master's Maximum Allowed Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_max_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 duration_max);

/* Get PTP Master's Maximum Allowed Unicast Request Duration */
extern int bcm_ptp_unicast_request_duration_max_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 *duration_max);

/* Get PTP Clock Acceptable Master Table Size */
extern int bcm_ptp_acceptable_master_table_size_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int *max_table_entries);

/* Add PTP Clock Acceptable Master Table Entry */
extern int bcm_ptp_acceptable_master_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int priority1_alt_value, 
    bcm_ptp_clock_peer_address_t *master_info);

/* List PTP Acceptable Master Table */
extern int bcm_ptp_acceptable_master_list(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int max_num_masters, 
    int *num_masters, 
    bcm_ptp_clock_peer_address_t *master_addr);

/* Remove PTP Clock Acceptable Master Entry */
extern int bcm_ptp_acceptable_master_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_peer_address_t *master_info);

/* Clear PTP Clock Acceptable Master Table */
extern int bcm_ptp_acceptable_master_table_clear(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num);

/* Get PTP Clock Acceptable Master Table Enabled State */
extern int bcm_ptp_acceptable_master_enabled_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint8 *enabled);

/* Set PTP Clock Acceptable Master Enabled state */
extern int bcm_ptp_acceptable_master_enabled_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint8 enabled);

/* Get PTP Clock Primary Domain */
extern int bcm_ptp_primary_domain_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *primary_domain);

/* Set PTP Clock Primary Domain */
extern int bcm_ptp_primary_domain_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int primary_domain);

/* Get PTP Transparent Clock Default Dataset */
extern int bcm_ptp_transparent_clock_default_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_transparent_clock_default_dataset_t *data_set);

/* Get PTP Transparent Clock Port Dataset */
extern int bcm_ptp_transparent_clock_port_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint16 clock_port, 
    bcm_ptp_transparent_clock_port_dataset_t *data_set);

/* Set PTP TOD Input Sources */
extern int bcm_ptp_tod_input_sources_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int num_tod_sources, 
    bcm_ptp_tod_input_t *tod_sources);

/* Get PTP Input Timesource Status */
extern int bcm_ptp_timesource_input_status_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_timesource_status_t *status);

/* Get PTP TOD Input Sources */
extern int bcm_ptp_tod_input_sources_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *num_tod_sources, 
    bcm_ptp_tod_input_t *tod_sources);

/* Get PTP input channels. */
extern int bcm_ptp_input_channels_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *num_channels, 
    bcm_ptp_channel_t *channels);

/* Set PTP Input Channels */
extern int bcm_ptp_input_channels_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int num_channels, 
    bcm_ptp_channel_t *channels);

/* Set PTP Input Channels Precedence Mode */
extern int bcm_ptp_input_channel_precedence_mode_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int channel_select_mode);

/* Set PTP Input Channels Switching Mode */
extern int bcm_ptp_input_channel_switching_mode_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int channel_switching_mode);

/* Set PTP TOD Output */
extern int bcm_ptp_tod_output_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *tod_output_id, 
    bcm_ptp_tod_output_t *output_info);

/* Get PTP TOD Output */
extern int bcm_ptp_tod_output_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *tod_output_count, 
    bcm_ptp_tod_output_t *tod_output);

/* Remove PTP TOD Output */
extern int bcm_ptp_tod_output_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int tod_output_id);

/* Set PTP Signal Output */
extern int bcm_ptp_signal_output_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *signal_output_id, 
    bcm_ptp_signal_output_t *output_info);

/* Get PTP Signal Output */
extern int bcm_ptp_signal_output_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *signal_output_count, 
    bcm_ptp_signal_output_t *signal_output_id);

/* Remove PTP Signal Output */
extern int bcm_ptp_signal_output_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int signal_output_id);

/* Synchronize PHY clock to the TOP clock */
extern int bcm_ptp_sync_phy(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_sync_phy_input_t sync_input);

/* Query the BSHB timestamp for PHY DPLL config to sync with TOP clock */
extern int bcm_ptp_bs_time_info_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_bs_time_info_t *time);

/* Get PTP servo configuration properties */
extern int bcm_ptp_servo_configuration_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_config_t *config);

/* Set PTP servo configuration properties */
extern int bcm_ptp_servo_configuration_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_config_t *config);

/* Get PTP servo status. */
extern int bcm_ptp_servo_status_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_status_t *status);

/* Set servo thresholds. */
extern int bcm_ptp_servo_threshold_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_threshold_t *threshold);

/* Get servo thresholds. */
extern int bcm_ptp_servo_threshold_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_threshold_t *threshold);

/* Get peer dataset. */
extern int bcm_ptp_peer_dataset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    int max_num_peers, 
    bcm_ptp_peer_entry_t *peers, 
    int *num_peers);

/* Get PTP Clock slave peer aging time for cleanup */
extern int bcm_ptp_clock_peer_age_timer_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 *aging_time);

/* Set PTP Clock slave Peer Aging time for cleanup */
extern int bcm_ptp_clock_peer_age_timer_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 aging_time);

/* Get PTP Clock flag field override mask/value get */
extern int bcm_ptp_pkt_flags_override_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *override_flag, 
    uint32 *override_value);

/* Set PTP Clock flag field override mask/value set */
extern int bcm_ptp_pkt_flags_override_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 override_flag, 
    uint32 override_value);

/* Get packet counts/statistics. */
extern int bcm_ptp_packet_counters_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_packet_counters_t *counters);

#endif /* BCM_HIDE_DISPATCHABLE */

/* 
 *  Bits#13:0 of "counter_bitmap" indicates a PTP packet counter. When
 * set to 1, will clear the corresponding packet counter. Bits#31:14 are
 * ignored.
 */
#define BCM_PTP_PKT_COUNTER_TX              (1 << 0)   
#define BCM_PTP_PKT_COUNTER_RX              (1 << 1)   
#define BCM_PTP_PKT_COUNTER_DISCARD         (1 << 2)   
#define BCM_PTP_PKT_COUNTER_RCPU_ENCAP_RX   (1 << 3)   
#define BCM_PTP_PKT_COUNTER_IPV4_RX         (1 << 4)   
#define BCM_PTP_PKT_COUNTER_IPV6_RX         (1 << 5)   
#define BCM_PTP_PKT_COUNTER_L2_RX           (1 << 6)   
#define BCM_PTP_PKT_COUNTER_UDP_RX          (1 << 7)   
#define BCM_PTP_PKT_COUNTER_ENDUROSYNC_TX   (1 << 8)   
#define BCM_PTP_PKT_COUNTER_ENDUROSYNC_RX   (1 << 9)   
#define BCM_PTP_PKT_COUNTER_RXQUEUE_OVERFLOWS (1 << 10)  
#define BCM_PTP_PKT_COUNTER_PORT_TX         (1 << 11)  
#define BCM_PTP_PKT_COUNTER_PORT_RX         (1 << 12)  
#define BCM_PTP_PKT_COUNTER_PORT_DISCARD    (1 << 13)  
#define BCM_PTP_PKT_COUNTER_ALL             (0x3FFF)   /* clear all packet
                                                          counters ( both common
                                                          and port-specific). */
#define BCM_PTP_PKT_COUNTER_COMMON          (0x07FF)   /* clear all common
                                                          packet counters */
#define BCM_PTP_PKT_COUNTER_PORT_SPECIFIC   (0x3800)   /* clear all
                                                          port-specific packet
                                                          counters */

#ifndef BCM_HIDE_DISPATCHABLE

/* Reset/Clear packet counts/statistics. */
extern int bcm_ptp_packet_counters_clear(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    uint32 counter_bitmap);

/* Set phase offsets for path asymmetry compensation */
extern int bcm_ptp_phase_offset_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    const bcm_ptp_phase_offset_t *offset);

/* Get phase offsets for path asymmetry compensation */
extern int bcm_ptp_phase_offset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_phase_offset_t *offset);

/* ESMC PDU transmit (Tx). */
extern int bcm_esmc_tx(
    int unit, 
    int stack_id, 
    bcm_pbmp_t pbmp, 
    bcm_esmc_pdu_data_t *esmc_pdu_data);

/* Register ESMC PDU Rx callback. */
extern int bcm_esmc_rx_callback_register(
    int unit, 
    int stack_id, 
    bcm_esmc_rx_cb rx_cb);

/* Unregister ESMC PDU Rx callback. */
extern int bcm_esmc_rx_callback_unregister(
    int unit, 
    int stack_id);

/* Get ESMC PDU tunneling-enabled Boolean. */
extern int bcm_esmc_tunnel_get(
    int unit, 
    int stack_id, 
    int *enable);

/* Set ESMC PDU tunneling-enabled Boolean. */
extern int bcm_esmc_tunnel_set(
    int unit, 
    int stack_id, 
    int enable);

/* Get ITU-T G.781 networking option for SyncE. */
extern int bcm_esmc_g781_option_get(
    int unit, 
    int stack_id, 
    bcm_esmc_network_option_t *g781_option);

/* Set ITU-T G.781 networking option for SyncE. */
extern int bcm_esmc_g781_option_set(
    int unit, 
    int stack_id, 
    bcm_esmc_network_option_t g781_option);

/* 
 * Get synchronization status message (SSM) code corresponding to ITU-T
 * G.781 quality level (QL).
 */
extern int bcm_esmc_QL_SSM_map(
    int unit, 
    bcm_esmc_network_option_t opt, 
    bcm_esmc_quality_level_t ql, 
    uint8 *ssm_code);

/* 
 * Get ITU-T G.781 quality level (QL) corresponding to synchronization
 * status message (SSM) code.
 */
extern int bcm_esmc_SSM_QL_map(
    int unit, 
    bcm_esmc_network_option_t opt, 
    uint8 ssm_code, 
    bcm_esmc_quality_level_t *ql);

/* Register input clock esmc quality change callback. */
extern int bcm_tdpll_input_clock_ql_change_callback_register(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_ql_change_cb ql_change_cb);

/* Unregister input clock esmc quality change callback. */
extern int bcm_tdpll_input_clock_ql_change_callback_unregister(
    int unit, 
    int stack_id);

/* Get logical DPLL instance input/output bindings. */
extern int bcm_tdpll_dpll_bindings_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_bindings_t *bindings);

/* Set logical DPLL instance input/output bindings. */
extern int bcm_tdpll_dpll_bindings_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_bindings_t *bindings);

/* Get reference clocks for DPLL instances. */
extern int bcm_tdpll_dpll_reference_get(
    int unit, 
    int stack_id, 
    int max_num_dpll, 
    int *dpll_ref, 
    int *num_dpll);

/* Get DPLL bandwidth. */
extern int bcm_tdpll_dpll_bandwidth_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_bandwidth_t *bandwidth);

/* Set DPLL bandwidth. */
extern int bcm_tdpll_dpll_bandwidth_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_bandwidth_t *bandwidth);

/* Get DPLL instance's phase control configuration. */
extern int bcm_tdpll_dpll_phase_control_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_phase_control_t *phase_control);

/* Set DPLL instance's phase control configuration. */
extern int bcm_tdpll_dpll_phase_control_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_tdpll_dpll_phase_control_t *phase_control);

/* 
 * Start/stop T-DPLL input clock monitoring, reference selection, and
 * switching state machine
 */
extern int bcm_tdpll_input_clock_control(
    int unit, 
    int stack_id, 
    int enable);

/* Get MAC address of input clock. */
extern int bcm_tdpll_input_clock_mac_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_mac_t *mac);

/* Set MAC address of input clock. */
extern int bcm_tdpll_input_clock_mac_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_mac_t *mac);

/* 
 * Get fractional frequency error of an input clock from input-clock
 * monitoring process.
 */
extern int bcm_tdpll_input_clock_frequency_error_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *freq_error_ppb);

/* 
 * Get monitor threshold state of an input clock from input-clock
 * monitoring process.
 */
extern int bcm_tdpll_input_clock_threshold_state_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_input_clock_monitor_type_t threshold_type, 
    int *threshold_state);

/* Get input clock enable Boolean. */
extern int bcm_tdpll_input_clock_enable_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *enable);

/* Set input-clock enable Boolean. */
extern int bcm_tdpll_input_clock_enable_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    int enable);

/* Get L1 mux mapping (mux index and port number) of input clock. */
extern int bcm_tdpll_input_clock_l1mux_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_input_clock_l1mux_t *l1mux);

/* Set L1 mux mapping (mux index and port number) of input clock. */
extern int bcm_tdpll_input_clock_l1mux_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_input_clock_l1mux_t *l1mux);

/* 
 * Get valid Boolean of an input clock from input-clock monitoring
 * process.
 */
extern int bcm_tdpll_input_clock_valid_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *valid);

/* Set input-clock valid Boolean from monitoring process. */
extern int bcm_tdpll_input_clock_valid_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    int valid);

/* Get input clock frequency. */
extern int bcm_tdpll_input_clock_frequency_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 *clock_frequency, 
    uint32 *tsevent_frequency);

/* Set input clock frequency. */
extern int bcm_tdpll_input_clock_frequency_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 clock_frequency, 
    uint32 tsevent_frequency);

/* Get input clock quality level (QL). */
extern int bcm_tdpll_input_clock_ql_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_esmc_quality_level_t *ql);

/* Set input clock quality level (QL). */
extern int bcm_tdpll_input_clock_ql_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_esmc_quality_level_t ql);

/* Get input clock priority for reference selection. */
extern int bcm_tdpll_input_clock_priority_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *priority);

/* Set input clock priority for reference selection. */
extern int bcm_tdpll_input_clock_priority_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    int priority);

/* Get input clock lockout Boolean for reference selection. */
extern int bcm_tdpll_input_clock_lockout_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *lockout);

/* Set input clock lockout Boolean for reference selection. */
extern int bcm_tdpll_input_clock_lockout_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    int lockout);

/* Get input clock monitoring interval. */
extern int bcm_tdpll_input_clock_monitor_interval_get(
    int unit, 
    int stack_id, 
    uint32 *monitor_interval);

/* Set input clock monitoring interval. */
extern int bcm_tdpll_input_clock_monitor_interval_set(
    int unit, 
    int stack_id, 
    uint32 monitor_interval);

/* 
 * Get monitor threshold for input-clock valid classification required in
 * reference selection.
 */
extern int bcm_tdpll_input_clock_monitor_threshold_get(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_monitor_type_t threshold_type, 
    uint32 *threshold);

/* 
 * Set monitor threshold for input-clock valid classification required in
 * reference selection.
 */
extern int bcm_tdpll_input_clock_monitor_threshold_set(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_monitor_type_t threshold_type, 
    uint32 threshold);

/* Get QL-enabled Boolean for reference selection. */
extern int bcm_tdpll_input_clock_ql_enabled_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int *ql_enabled);

/* Set QL-enabled Boolean for reference selection. */
extern int bcm_tdpll_input_clock_ql_enabled_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int ql_enabled);

/* Get revertive mode Boolean for reference selection and switching. */
extern int bcm_tdpll_input_clock_revertive_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int *revertive);

/* Set revertive mode Boolean for reference selection and switching. */
extern int bcm_tdpll_input_clock_revertive_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int revertive);

/* Get best (i.e. selected) reference for a DPLL instance. */
extern int bcm_tdpll_input_clock_best_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int *best_clock);

/* Register input clock monitoring callback. */
extern int bcm_tdpll_input_clock_monitor_callback_register(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_monitor_cb monitor_cb);

/* Unregister input clock monitoring callback. */
extern int bcm_tdpll_input_clock_monitor_callback_unregister(
    int unit, 
    int stack_id);

/* Register input clock reference selection callback. */
extern int bcm_tdpll_input_clock_selector_callback_register(
    int unit, 
    int stack_id, 
    bcm_tdpll_input_clock_selector_cb selector_cb);

/* Unregister input clock reference selection callback. */
extern int bcm_tdpll_input_clock_selector_callback_unregister(
    int unit, 
    int stack_id);

/* Register callback for different tdpll callback types. */
extern int bcm_tdpll_input_clock_callback_register(
    int unit, 
    int stack_id, 
    bcm_tdpll_callback_type_t type, 
    bcm_tdpll_input_clock_cb callback);

/* Unregister the tdpll callback. */
extern int bcm_tdpll_input_clock_callback_unregister(
    int unit, 
    int stack_id, 
    bcm_tdpll_callback_type_t type);

/* Get output clock enable Boolean. */
extern int bcm_tdpll_output_clock_enable_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    int *enable);

/* Create output clock. */
extern int bcm_tdpll_output_clock_create(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_pbmp_t pbmp, 
    bcm_tdpll_dpll_bandwidth_t *bandwidth);

/* Set output clock enable Boolean. */
extern int bcm_tdpll_output_clock_enable_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    int enable);

/* Get output-clock (synthesizer) frequency. */
extern int bcm_tdpll_output_clock_synth_frequency_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 *synth_frequency, 
    uint32 *tsevent_frequency);

/* Set output-clock (synthesizer) frequency. */
extern int bcm_tdpll_output_clock_synth_frequency_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 synth_frequency, 
    uint32 tsevent_frequency);

/* Get synthesizer derivative-clock frequency. */
extern int bcm_tdpll_output_clock_deriv_frequency_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 *deriv_frequency);

/* Set synthesizer derivative clock frequency. */
extern int bcm_tdpll_output_clock_deriv_frequency_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    uint32 deriv_frequency);

/* Get holdover configuration data. */
extern int bcm_tdpll_output_clock_holdover_data_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_holdover_data_t *hdata);

/* Set manual holdover frequency correction. */
extern int bcm_tdpll_output_clock_holdover_frequency_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_frequency_correction_t hfreq);

/* Get holdover mode. */
extern int bcm_tdpll_output_clock_holdover_mode_get(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_holdover_mode_t *hmode);

/* Set holdover mode. */
extern int bcm_tdpll_output_clock_holdover_mode_set(
    int unit, 
    int stack_id, 
    int clock_index, 
    bcm_tdpll_holdover_mode_t hmode);

/* Reset holdover frequency calculations. */
extern int bcm_tdpll_output_clock_holdover_reset(
    int unit, 
    int stack_id, 
    int clock_index);

/* Execute state machine for Rx ESMC PDU. */
extern int bcm_tdpll_esmc_rx_state_machine(
    int unit, 
    int stack_id, 
    int ingress_port, 
    bcm_esmc_pdu_data_t *esmc_pdu_data);

/* Get quality level (QL) for ESMC. */
extern int bcm_tdpll_esmc_ql_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_quality_level_t *ql);

/* Set quality level (QL) for ESMC. */
extern int bcm_tdpll_esmc_ql_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_quality_level_t ql);

/* Get quality level (QL) for ESMC during holdover. */
extern int bcm_tdpll_esmc_holdover_ql_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_quality_level_t *ql);

/* Set quality level (QL) for ESMC during holdover. */
extern int bcm_tdpll_esmc_holdover_ql_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_quality_level_t ql);

/* Get MAC address for ESMC. */
extern int bcm_tdpll_esmc_mac_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_mac_t *mac);

/* Set MAC address for ESMC. */
extern int bcm_tdpll_esmc_mac_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_mac_t *mac);

/* Get ESMC PDU receive (Rx) enable state. */
extern int bcm_tdpll_esmc_rx_enable_get(
    int unit, 
    int stack_id, 
    int *enable);

/* Set ESMC PDU receive (Rx) enable state. */
extern int bcm_tdpll_esmc_rx_enable_set(
    int unit, 
    int stack_id, 
    int enable);

/* Get ESMC PDU transmit (Tx) enable state. */
extern int bcm_tdpll_esmc_tx_enable_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int *enable);

/* Set ESMC PDU transmit (Tx) enable state. */
extern int bcm_tdpll_esmc_tx_enable_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    int enable);

/* Get port bitmap for ESMC Rx. */
extern int bcm_tdpll_esmc_rx_portbitmap_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_pbmp_t *pbmp);

/* Set port bitmap for ESMC Rx. */
extern int bcm_tdpll_esmc_rx_portbitmap_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_pbmp_t pbmp);

/* Get port bitmap for ESMC Tx. */
extern int bcm_tdpll_esmc_tx_portbitmap_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_pbmp_t *pbmp);

/* Set port bitmap for ESMC Tx. */
extern int bcm_tdpll_esmc_tx_portbitmap_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_pbmp_t pbmp);

/* Set SyncE clock type as per ITU-T G8264amd2. */
extern int bcm_tdpll_esmc_essm_code_set(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_essm_code_t  essm_code);

/* Get SyncE clock type as per ITU-T G8264amd2. */
extern int bcm_tdpll_esmc_essm_code_get(
    int unit, 
    int stack_id, 
    int dpll_index, 
    bcm_esmc_essm_code_t  *essm_code);

#endif /* BCM_HIDE_DISPATCHABLE */

/* TDPLL event callback type */
typedef enum bcm_tdpll_event_cb_type_e {
    bcmTdpllEventCbTypeQlChange,    /* QL change in ESMC Rx. */
    bcmTdpllEventCbTypeEsmcTimeout, /* Timeout of ESMC Rx PDUs. */
    bcmTdpllEventCbTypeSynceTsMiss, /* SyncE TS event missed. */
    bcmTdpllEventCbTypeLinkDown,    /* port linkdown notification. */
    bcmTdpllEventCbTypeMax          /* Number of event types supported. */
} bcm_tdpll_event_cb_type_t;

typedef struct bcm_tdpll_event_cb_data_s {
    bcm_tdpll_event_cb_type_t cb_event_type; /* event type that triggered the
                                           callback . */
    void *cb_data; 
} bcm_tdpll_event_cb_data_t;

typedef struct bcm_tdpll_ql_change_event_cb_data_s {
    bcm_tdpll_event_cb_type_t event_type; /* event type that triggered the
                                           callback. */
    bcm_port_t port;                    /* Ingress port number for which the QL
                                           change is seen */
    bcm_esmc_quality_level_t ql_old;    /* previous QL. */
    bcm_esmc_quality_level_t ql_new;    /* current QL. */
} bcm_tdpll_ql_change_event_cb_data_t;

typedef struct bcm_tdpll_esmc_timeout_event_cb_data_s {
    bcm_tdpll_event_cb_type_t event_type; /* Event callback type. */
    bcm_port_t port;                    /* Ingress port number for which the
                                           ESMC timeout is seen */
} bcm_tdpll_esmc_timeout_event_cb_data_t;

typedef struct bcm_tdpll_synce_ts_miss_event_cb_data_s {
    bcm_tdpll_event_cb_type_t event_type; /* Event callback type. */
    bcm_port_t port;                    /* Ingress port number for which the TS
                                           event loss is detected */
} bcm_tdpll_synce_ts_miss_event_cb_data_t;

typedef struct bcm_tdpll_port_linkdown_event_cb_data_s {
    bcm_tdpll_event_cb_type_t event_type; /* Event callback type. */
    bcm_port_t port;                    /* Ingress port number for which the
                                           port linkdown is detected */
} bcm_tdpll_port_linkdown_event_cb_data_t;

/* prototype for callback function to register for events. */
typedef int (*bcm_tdpll_event_cb_f)(
    int unit, 
    int stack_id, 
    bcm_tdpll_event_cb_data_t *data);

#ifndef BCM_HIDE_DISPATCHABLE

/* Register for notifications related to ESMC support with external DPLL */
extern int bcm_tdpll_event_callback_register(
    int unit, 
    int stack_id, 
    bcm_tdpll_event_cb_f event_cb);

/* 
 * Unregister for notifications related to ESMC support with external
 * DPLL
 */
extern int bcm_tdpll_event_callback_unregister(
    int unit, 
    int stack_id);

/* Initialize Telecom G8265 Profile */
extern int bcm_ptp_telecom_g8265_init(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num);

/* Get Telecom G8265 Profile Network Option */
extern int bcm_ptp_telecom_g8265_network_option_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_network_option_t *network_option);

/* Set Telecom G8265 Profile Network Option */
extern int bcm_ptp_telecom_g8265_network_option_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_network_option_t network_option);

/* Set Telecom G8265 Quality Level */
extern int bcm_ptp_telecom_g8265_quality_level_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_quality_level_t ql);

/* Set Telecom G8265 Profile Message Receipt Timeout */
extern int bcm_ptp_telecom_g8265_receipt_timeout_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_message_type_t message_type, 
    uint32 receipt_timeout);

/* Get Telecom G8265 Profile Message Receipt Timeout */
extern int bcm_ptp_telecom_g8265_receipt_timeout_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_message_type_t message_type, 
    uint32 *receipt_timeout);

/* Set Telecom G8265 Profile Pakcet Stats Thresholds */
extern int bcm_ptp_telecom_g8265_pktstats_thresholds_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_pktstats_t thresholds);

/* Get Telecom G8265 Profile Pakcet Stats Thresholds */
extern int bcm_ptp_telecom_g8265_pktstats_thresholds_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_pktstats_t *thresholds);

/* List Telecom G8265 Profile Packet Masters */
extern int bcm_ptp_telecom_g8265_packet_master_list(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int max_master_count, 
    int *num_masters, 
    int *best_master, 
    bcm_ptp_telecom_g8265_pktmaster_t *pktmaster);

/* Get Telecom G8265 Profile Best Packet Master */
extern int bcm_ptp_telecom_g8265_packet_master_best_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_telecom_g8265_pktmaster_t *pktmaster);

/* Add Telecom G8265 Profile Packet Master */
extern int bcm_ptp_telecom_g8265_packet_master_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_port_address_t *address);

/* Get Telecom G8265 Profile Packet Master By Address */
extern int bcm_ptp_telecom_g8265_packet_master_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_port_address_t *address, 
    bcm_ptp_telecom_g8265_pktmaster_t *pktmaster);

/* Remove Telecom G8265 Profile Packet Master */
extern int bcm_ptp_telecom_g8265_packet_master_remove(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int port_num, 
    bcm_ptp_clock_port_address_t *address);

/* Set Telecom G8265 Profile Pakcet Master Lockout */
extern int bcm_ptp_telecom_g8265_packet_master_lockout_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 lockout, 
    bcm_ptp_clock_port_address_t *address);

/* Set Telecom G8265 Profile Packet Master Non Reversion */
extern int bcm_ptp_telecom_g8265_packet_master_non_reversion_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 nonres, 
    bcm_ptp_clock_port_address_t *address);

/* Set Telecom G8265 Profile Duration Wait */
extern int bcm_ptp_telecom_g8265_packet_master_wait_duration_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint64 wait_sec, 
    bcm_ptp_clock_port_address_t *address);

/* Set Telecom G8265 Profile Packet Master Priority Override */
extern int bcm_ptp_telecom_g8265_packet_master_priority_override(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint8 override, 
    bcm_ptp_clock_port_address_t *address);

/* Set Telecom G8265 Profile Packet Master Priority */
extern int bcm_ptp_telecom_g8265_packet_master_priority_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint16 priority, 
    bcm_ptp_clock_port_address_t *address);

/* Shutdown Telecom G8265 Profile */
extern int bcm_ptp_telecom_g8265_shutdown(
    int unit);

/* Get enable/disable state of modular system functionality. */
extern int bcm_ptp_modular_enable_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *enable, 
    uint32 *flags);

/* Set enable/disable state of modular system functionality. */
extern int bcm_ptp_modular_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int enable, 
    uint32 flags);

/* Get verbose program control option of modular system functionality. */
extern int bcm_ptp_modular_verbose_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *verbose);

/* Set verbose program control option of modular system functionality. */
extern int bcm_ptp_modular_verbose_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int verbose);

/* Get PHY port bitmap. */
extern int bcm_ptp_modular_portbitmap_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_pbmp_t *pbmp);

/* Set PHY port bitmap. */
extern int bcm_ptp_modular_portbitmap_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_pbmp_t pbmp);

/* Get PHY timestamping configuration state and data. */
extern int bcm_ptp_modular_phyts_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *phyts, 
    int *framesync_pin);

/* Set PHY timestamping configuration state and data. */
extern int bcm_ptp_modular_phyts_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int phyts, 
    int framesync_pin);

/* Get enable/disable state of C-TDEV processing. */
extern int bcm_ptp_ctdev_enable_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *enable, 
    uint32 *flags);

/* Set enable/disable state of C-TDEV processing. */
extern int bcm_ptp_ctdev_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int enable, 
    uint32 flags);

/* Get verbose program control option of C-TDEV processing. */
extern int bcm_ptp_ctdev_verbose_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *verbose);

/* Set verbose program control option of C-TDEV processing. */
extern int bcm_ptp_ctdev_verbose_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int verbose);

/* Get C-TDEV recursive algorithm forgetting factor (alpha). */
extern int bcm_ptp_ctdev_alpha_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint16 *alpha_numerator, 
    uint16 *alpha_denominator);

/* Set C-TDEV recursive algorithm forgetting factor (alpha). */
extern int bcm_ptp_ctdev_alpha_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint16 alpha_numerator, 
    uint16 alpha_denominator);

/* Register a C-TDEV alarm callback function. */
extern int bcm_ptp_ctdev_alarm_callback_register(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_ctdev_alarm_cb alarm_cb);

/* Unregister a C-TDEV alarm callback function. */
extern int bcm_ptp_ctdev_alarm_callback_unregister(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num);

/* Set or Clear the drop counters for a clock port. */
extern int bcm_ptp_clock_port_drop_counters_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    int enable);

/* Set or Clear the drop counters for a clock port. */
extern int bcm_ptp_clock_port_drop_counters_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 clock_port, 
    bcm_ptp_clock_port_packet_drop_counters_t *per_port_packet_drop_counters);

/* Set flags to be used for overriding BMCA. */
extern int bcm_ptp_clock_bmca_override_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 flags, 
    uint32 enable_mask);

/* Get flags to be used for overriding BMCA. */
extern int bcm_ptp_clock_bmca_override_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 *flags, 
    uint32 *enable_mask);

#endif /* BCM_HIDE_DISPATCHABLE */

/* Macros required for APTS automatic switching feature. */
#define BCM_PTP_CLOCK_APTS_MAX_FREQ_SOURCES (3)        /* Max number of
                                                          frequency sources
                                                          supported */
#define BCM_PTP_CLOCK_APTS_MAX_TIME_SOURCES (2)        /* Max number of time
                                                          sources supported */
#define BCM_PTP_CLOCK_APTS_MAX_INPUT_PIN_CONFIGS (2)        /* Max number of input
                                                          pin configs supported */

/* APTS supported sources. */
typedef enum bcm_ptp_clock_apts_source_e {
    bcmPtpClockAptsSourceSynceInternalDpll = 0x01, 
    bcmPtpClockAptsSourceSynceExternalDpll = 0x02, 
    bcmPtpClockAptsSourceGps = 0x04, 
    bcmPtpClockAptsSourcePtp = 0x08, 
    bcmPtpClockAptsSourceLast = 0xFFFF 
} bcm_ptp_clock_apts_source_t;

/* Supported APTS operating modes. */
typedef enum bcm_ptp_clock_apts_mode_e {
    bcmPtpClockAptsModeSyncEGps,        /* Frequency source: SyncE, Time source:
                                           GPS */
    bcmPtpClockAptsModeSyncEPtp, 
    bcmPtpClockAptsModeGpsGps, 
    bcmPtpClockAptsModePtpPtp, 
    bcmPtpClockAptsModeSyncEHoldover, 
    bcmPtpClockAptsModeHoldoverHoldover, 
    bcmPtpClockAptsModeLast 
} bcm_ptp_clock_apts_mode_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Get enable/disable status of the APTS automatic switching feature. */
extern int bcm_ptp_clock_apts_enable_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *enable);

/* Set enable/disable status of the APTS automatic switching feature. */
extern int bcm_ptp_clock_apts_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int enable);

/* Get the configured APTS time and frequency priorities */
extern int bcm_ptp_clock_apts_source_prio_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *num_sources, 
    bcm_ptp_clock_apts_source_t *priority_list);

/* Set the APTS time and frequency priorities */
extern int bcm_ptp_clock_apts_source_prio_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int num_sources, 
    bcm_ptp_clock_apts_source_t *priority_list);

/* Get the current APTS mode of operation */
extern int bcm_ptp_clock_apts_mode_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_apts_mode_t *current_mode);

/* Get the APTS source state */
extern int bcm_ptp_clock_apts_source_enable_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_apts_source_t source, 
    int *enable);

/* Set the APTS source state */
extern int bcm_ptp_clock_apts_source_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_apts_source_t source, 
    int enable);

#endif /* BCM_HIDE_DISPATCHABLE */

/* PTP External PHY sync - Pin to be used for PHY Framesync (SYNC_IN1) */
typedef enum bcm_ptp_extphy_framesync_pin_e {
    bcm_ptp_extphy_framesync_pin_tsgpio0 = 0, /* TS GPIO0 */
    bcm_ptp_extphy_framesync_pin_tsgpio1 = 1, /* TS GPIO1 */
    bcm_ptp_extphy_framesync_pin_gpio0 = 2, /* GPIO0 */
    bcm_ptp_extphy_framesync_pin_gpio1 = 3, /* GPIO1 */
    bcm_ptp_extphy_framesync_pin_gpio2 = 4, /* GPIO2 */
    bcm_ptp_extphy_framesync_pin_gpio3 = 5 /* GPIO3 */
} bcm_ptp_extphy_framesync_pin_t;

/* PTP External PHY sync - Pin configured for PHY 4KHz reference */
typedef enum bcm_ptp_extphy_freq_pin_e {
    bcm_ptp_extphy_freq_pin_bs0_hb = -1, /* BS0 Heartbit */
    bcm_ptp_extphy_freq_pin_bs1_hb = -2 /* BS1 hearbit */
} bcm_ptp_extphy_freq_pin_t;

/* 
 * PHY sync user function that will be called while running phy sync
 * state machine
 */
typedef int (*bcm_ptp_external_phy_sync)(
    int unit, 
    int stack_id, 
    int clock_num, 
    bcm_pbmp_t pbm, 
    uint64 ref_phase);

/* PTP external PHY config */
typedef struct bcm_ptp_external_phy_config_s {
    bcm_ptp_extphy_framesync_pin_t framesync_pin; /* Pin to be used for PHY Framesync
                                           (SYNC_IN1) e.g. GPIO3 */
    bcm_ptp_extphy_freq_pin_t freq_pin; /* Pin configured for PHY 4KHz reference
                                           - BS0 HB or BS1 HB */
    uint64 cpu_latency_nsec;            /* Latency to configure external phy
                                           ports */
    bcm_pbmp_t pbm;                     /* external phy port bitmap e.g ge0-ge3 */
    bcm_ptp_external_phy_sync ext_physync_func; /* PHY sync user function will be called
                                           while running phy sync state machine */
} bcm_ptp_external_phy_config_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Run state machine to synchronize CMIC time with external PHY time */
extern int bcm_ptp_external_phy_synchronize(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_external_phy_config_t *extphy_config);

/* Set the GPS offset value */
extern int bcm_ptp_clock_apts_gps_offset_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int offset_nsec);

/* Get the GPS offset value */
extern int bcm_ptp_clock_apts_gps_offset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    int *offset_nsec);

#endif /* BCM_HIDE_DISPATCHABLE */

/* PTP tlv_action enumeration. Specify the action for sending TLV */
typedef enum bcm_ptp_tlv_action_e {
    bcmPtpTlvActionAppendGrantUnicastTransmissionTlv, /* Append TLV to GRANT_UNICAST_TX TLV */
    bcmPtpTlvActionLast                 /* TLV action last */
} bcm_ptp_tlv_action_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Add a new TLV config */
extern int bcm_ptp_clock_port_tlv_config_add(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_index, 
    uint32 clock_port, 
    bcm_ptp_tlv_type_t tlv_type, 
    uint16 data_len, 
    uint8 *data, 
    bcm_ptp_tlv_action_t action, 
    int config_id);

/* delete existing TLV config */
extern int bcm_ptp_clock_port_tlv_config_delete(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_index, 
    uint32 clock_port, 
    int config_id);

/* delete all TLV config */
extern int bcm_ptp_clock_port_tlv_config_delete_all(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_index, 
    uint32 clock_port);

/* Enable or disable a config */
extern int bcm_ptp_clock_tlv_enable_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_index, 
    uint32 clock_port, 
    int config_id, 
    int enable);

/* Get the status of a config */
extern int bcm_ptp_clock_tlv_enable_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_index, 
    uint32 clock_port, 
    int config_id, 
    int *enable);

#endif /* BCM_HIDE_DISPATCHABLE */

/* PTP enum to represent schematic pins relevent to PTP module. */
typedef enum bcm_ptp_clock_input_pin_e {
    bcm_ptp_pin_gpio0 = 0,  /* TS GPIO0 */
    bcm_ptp_pin_gpio1 = 1,  /* TS GPIO1 */
    bcm_ptp_pin_gpio2 = 2,  /* GPIO0 */
    bcm_ptp_pin_gpio3 = 3,  /* GPIO1 */
    bcm_ptp_pin_gpio4 = 4,  /* GPIO2 */
    bcm_ptp_pin_gpio5 = 5,  /* GPIO3 */
    bcm_ptp_pin_bs0_hb = 6  /* BS0_HB */
} bcm_ptp_clock_input_pin_t;

/* APTS source - individual input pin configuration properties */
typedef struct bcm_ptp_clock_apts_input_pin_config_s {
    uint32 signal_frequency;            /* Frequency of signal pin e.g 1000000,
                                           100 (Hz) */
    uint32 ts_event_frequency;          /* Firmware timestamp event frequency of
                                           signal e.g 100, 1 (Hz) */
    bcm_ptp_clock_input_pin_t input_pin; /* Schematic pin identifier e.g GPIO0,
                                           GPIO1, BS0 HB */
} bcm_ptp_clock_apts_input_pin_config_t;

/* APTS source - detailed configuration */
typedef struct bcm_ptp_clock_apts_input_source_config_s {
    bcm_ptp_tod_source_t tod_in_source; /* UART number for TOD in */
    uint32 num_pin_configs;             /* Number of pin configurations */
    bcm_ptp_clock_apts_input_pin_config_t pin_config[BCM_PTP_CLOCK_APTS_MAX_INPUT_PIN_CONFIGS]; /* Pin configuration for schematic pins
                                           e.g GPIO0, GPIO1, BS0 HB */
} bcm_ptp_clock_apts_input_source_config_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Set APTS config for particular APTS source */
extern int bcm_ptp_clock_apts_input_source_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_clock_apts_source_t apts_source, 
    bcm_ptp_clock_apts_input_source_config_t *input_source_config);

/* Get APTS config for particular APTS source */
extern int bcm_ptp_clock_apts_input_source_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_nUM, 
    bcm_ptp_clock_apts_source_t apts_source, 
    bcm_ptp_clock_apts_input_source_config_t *input_source_config);

#endif /* BCM_HIDE_DISPATCHABLE */

/* PTP Servo Performance Information */
typedef struct bcm_ptp_servo_performance_s {
    bcm_ptp_servo_status_t status;  /* PTP Servo state data */
    int64 freq_correction;          /* Frequency correction (ppb) */
    int64 phase_correction;         /* Phase correction (nsec) */
    int64 residual_phase_error;     /* Residual Phase error (nsec) */
    uint64 min_round_trip_delay;    /* Minimum round trip delay (nsec) */
    uint16 fwd_pkt_rate;            /* Sync Packet Rate (pkts/sec) */
    uint16 rev_pkt_rate;            /* Delay Packet Rate (pkts/sec) */
} bcm_ptp_servo_performance_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Get PTP servo performance information. */
extern int bcm_ptp_servo_performance_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    bcm_ptp_servo_performance_t *perf);

#endif /* BCM_HIDE_DISPATCHABLE */

/* PTP and NTP ToD offset flags */
#define BCM_PTP_TOD_PTP_OFFSET  0x00000001 /* To set/get the ptp tod offset */
#define BCM_PTP_TOD_NTP_OFFSET  0x00000002 /* To set/get the ntp tod offset */

/* PTP base time structure. */
typedef bcm_time_spec_t bcm_ptp_time_spec_t;

#ifndef BCM_HIDE_DISPATCHABLE

/* Set NTP and PTP ToD offset. */
extern int bcm_ptp_ntp_tod_offset_set(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 flags, 
    bcm_ptp_time_spec_t *ptp_tod_offset, 
    bcm_ptp_time_spec_t *ntp_tod_offset);

/* Get NTP and PTP ToD offset. */
extern int bcm_ptp_ntp_tod_offset_get(
    int unit, 
    bcm_ptp_stack_id_t ptp_id, 
    int clock_num, 
    uint32 flags, 
    bcm_ptp_time_spec_t *ptp_tod_offset, 
    bcm_ptp_time_spec_t *ntp_tod_offset);

#endif /* defined(INCLUDE_PTP) */

#endif /* BCM_HIDE_DISPATCHABLE */

#endif /* __BCM_PTP_H__ */
