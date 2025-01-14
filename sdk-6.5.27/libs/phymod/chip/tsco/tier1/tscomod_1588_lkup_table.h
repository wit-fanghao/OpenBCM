#include <phymod/phymod.h>

#define TSCOMOD_TS_DEFAULT_TABLE_SIZE 40
#define TSCOMOD_TS_TABLE_SIZE 80
#define TSCOMOD_TS_ENTRY_SIZE 3
#define TSCOMOD_TS_PSLL_BASED_ENTRY_SIZE 4
#define TSCOMOD_TS_TX_MEM_SIZE 160
#define TSCOMOD_TS_RX_MPP_MEM_SIZE 80

#define TSCOMOD_TS_RX_MPP1_NATIVE_START_ADDR 40
#define TSCOMOD_TS_RX_MPP_EVEN_BANK_NATIVE_TO_ADDR(na)      (na * 2)
#define TSCOMOD_TS_RX_MPP_ODD_BANK_NATIVE_TO_ADDR(na)       ((na * 2)+1)

typedef enum {
    TSCOMOD_SPEED_10G_IEEE_KR1,
    TSCOMOD_SPEED_25G_IEEE_KS1_CS1,
    TSCOMOD_SPEED_25G_IEEE_KR1_CR1,
    TSCOMOD_SPEED_40G_IEEE_KR4,
    TSCOMOD_SPEED_40G_IEEE_CR4,
    TSCOMOD_SPEED_50G_IEEE_KR1_CR1,
    TSCOMOD_SPEED_50G_IEEE_NRZ_KR1_CR1,
    TSCOMOD_SPEED_100G_IEEE_KR4,
    TSCOMOD_SPEED_100G_IEEE_CR4,
    TSCOMOD_SPEED_100G_IEEE_KR2_CR2,
    TSCOMOD_SPEED_100G_IEEE_NRZ_KR2_CR2,
    TSCOMOD_SPEED_100G_IEEE_KR1_CR1,
    TSCOMOD_SPEED_200G_IEEE_KR4_CR4,
    TSCOMOD_SPEED_200G_IEEE_NRZ_KR4_CR4,
    TSCOMOD_SPEED_200G_IEEE_KR2_CR2,
    TSCOMOD_SPEED_400G_IEEE_KR4_CR4,
    TSCOMOD_SPEED_20G_BRCM_CR1,
    TSCOMOD_SPEED_20G_BRCM_KR1,
    TSCOMOD_SPEED_25G_BRCM_CR1,
    TSCOMOD_SPEED_25G_BRCM_KR1,
    TSCOMOD_SPEED_25G_BRCM_NO_FEC_KR1_CR1,
    TSCOMOD_SPEED_25G_BRCM_FEC_528_KR1_CR1,
    TSCOMOD_SPEED_40G_BRCM_CR2,
    TSCOMOD_SPEED_40G_BRCM_KR2,
    TSCOMOD_SPEED_50G_BRCM_CR2_KR2_NO_FEC,
    TSCOMOD_SPEED_50G_BRCM_CR2_KR2_RS_FEC,
    TSCOMOD_SPEED_50G_BRCM_FEC_544_CR2_KR2,
    TSCOMOD_SPEED_50G_BRCM_FEC_528_CR1_KR1,
    TSCOMOD_SPEED_50G_BRCM_FEC_272_CR1_KR1,
    TSCOMOD_SPEED_50G_BRCM_NO_FEC_NRZ_CR1_KR1,
    TSCOMOD_SPEED_50G_BRCM_FEC_528_NRZ_CR1_KR1,
    TSCOMOD_SPEED_50G_BRCM_FEC_272_NRZ_CR1_KR1,
    TSCOMOD_SPEED_100G_BRCM_NO_FEC_X4,
    TSCOMOD_SPEED_100G_BRCM_KR4_CR4,
    TSCOMOD_SPEED_100G_BRCM_NO_FEC_KR2_CR2,
    TSCOMOD_SPEED_100G_BRCM_FEC_528_KR2_CR2,
    TSCOMOD_SPEED_100G_BRCM_FEC_272_CR2_KR2,
    TSCOMOD_SPEED_100G_BRCM_NO_FEC_NRZ_KR2_CR2,
    TSCOMOD_SPEED_100G_BRCM_FEC_528_NRZ_KR2_CR2,
    TSCOMOD_SPEED_100G_BRCM_FEC_272_NRZ_KR2_CR2,
    TSCOMOD_SPEED_100G_BRCM_KR1_CR1,
    TSCOMOD_SPEED_100G_BRCM_FEC_272_KR1_CR1,
    TSCOMOD_SPEED_200G_BRCM_FEC_544_CR8_KR8,
    TSCOMOD_SPEED_200G_BRCM_NO_FEC_KR4_CR4,
    TSCOMOD_SPEED_200G_BRCM_KR4_CR4,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_CR4_KR4,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_N4,
    TSCOMOD_SPEED_200G_BRCM_NO_FEC_NRZ_KR4_CR4,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_NRZ_CR4_KR4,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_NRZ_N4,
    TSCOMOD_SPEED_200G_BRCM_NRZ_KR4_CR4,
    TSCOMOD_SPEED_200G_BRCM_KR2_CR2,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_KR2_CR2,
    TSCOMOD_SPEED_200G_BRCM_FEC_272_N2,
    TSCOMOD_SPEED_400G_BRCM_FEC_KR8_CR8,
    TSCOMOD_SPEED_400G_BRCM_FEC_272_N8,
    TSCOMOD_SPEED_400G_BRCM_NO_FEC_NRZ_KR8_CR8,
    TSCOMOD_SPEED_400G_BRCM_FEC_NRZ_KR8_CR8,
    TSCOMOD_SPEED_400G_BRCM_FEC_272_NRZ_N8,
    TSCOMOD_SPEED_400G_BRCM_FEC_272_KR4_CR4,
    TSCOMOD_SPEED_MODE_COUNT
} tscomod_1588_table_index_t;

typedef struct tscomod_1588_lkup_table_entry_s {
    /* Index for the default speed entry. */
    uint32_t mapped_spd_table_index;
    phymod_fec_type_t fec_type;
    /* Index for 1588 table. */
    tscomod_1588_table_index_t ts_table_index;
    uint32_t table_size;
} tscomod_1588_lkup_table_entry_t;

typedef uint32_t tscomod_ts_table_entry[TSCOMOD_TS_TABLE_SIZE][TSCOMOD_TS_ENTRY_SIZE];
typedef uint32_t tscomod_ts_table_entry_mem[TSCOMOD_TS_ENTRY_SIZE];

int tscomod_1588_table_index_get(uint32_t speed_index, int *ts_table_index, uint32_t *table_size);
int tscomod_tbl_entry_to_psll_entry_map(uint32_t *tbl_entry, uint32_t *psll_entry);
int tscomod_psll_entry_to_tbl_entry_map(uint32_t *psll_entry, uint32_t *tbl_entry);

extern tscomod_ts_table_entry* tscomod_ts_table_tx_sop_get(void);
extern tscomod_ts_table_entry* tscomod_ts_table_rx_sop_get(void);
extern tscomod_ts_table_entry* tscomod_ts_table_tx_sfd_get(void);
extern tscomod_ts_table_entry* tscomod_ts_table_rx_sfd_get(void);
