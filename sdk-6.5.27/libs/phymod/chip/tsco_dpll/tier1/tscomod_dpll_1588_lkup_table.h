#include <phymod/phymod.h>

#define TSCOMOD_DPLL_TS_DEFAULT_TABLE_SIZE 40
#define TSCOMOD_DPLL_TS_TABLE_SIZE 80
#define TSCOMOD_DPLL_TS_ENTRY_SIZE 3
#define TSCOMOD_DPLL_TS_PSLL_BASED_ENTRY_SIZE 4
#define TSCOMOD_DPLL_TS_TX_MEM_SIZE 160
#define TSCOMOD_DPLL_TS_RX_MPP_MEM_SIZE 80

typedef enum {
    TSCOMOD_DPLL_SPEED_10G_IEEE_KR1,
    TSCOMOD_DPLL_SPEED_25G_IEEE_KS1_CS1,
    TSCOMOD_DPLL_SPEED_25G_IEEE_KR1_CR1,
    TSCOMOD_DPLL_SPEED_40G_IEEE_KR4,
    TSCOMOD_DPLL_SPEED_40G_IEEE_CR4,
    TSCOMOD_DPLL_SPEED_50G_IEEE_KR1_CR1,
    TSCOMOD_DPLL_SPEED_50G_IEEE_NRZ_KR1_CR1,
    TSCOMOD_DPLL_SPEED_100G_IEEE_KR4,
    TSCOMOD_DPLL_SPEED_100G_IEEE_CR4,
    TSCOMOD_DPLL_SPEED_100G_IEEE_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_IEEE_NRZ_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_IEEE_KR1_CR1,
    TSCOMOD_DPLL_SPEED_100G_IEEE_KR1_CR1_OPT,
    TSCOMOD_DPLL_SPEED_200G_IEEE_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_IEEE_NRZ_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_IEEE_KR2_CR2,
    TSCOMOD_DPLL_SPEED_400G_IEEE_KR4_CR4,
    TSCOMOD_DPLL_SPEED_20G_BRCM_CR1,
    TSCOMOD_DPLL_SPEED_20G_BRCM_KR1,
    TSCOMOD_DPLL_SPEED_25G_BRCM_CR1,
    TSCOMOD_DPLL_SPEED_25G_BRCM_KR1,
    TSCOMOD_DPLL_SPEED_25G_BRCM_NO_FEC_KR1_CR1,
    TSCOMOD_DPLL_SPEED_25G_BRCM_FEC_528_KR1_CR1,
    TSCOMOD_DPLL_SPEED_40G_BRCM_CR2,
    TSCOMOD_DPLL_SPEED_40G_BRCM_KR2,
    TSCOMOD_DPLL_SPEED_50G_BRCM_CR2_KR2_NO_FEC,
    TSCOMOD_DPLL_SPEED_50G_BRCM_CR2_KR2_RS_FEC,
    TSCOMOD_DPLL_SPEED_50G_BRCM_FEC_544_CR2_KR2,
    TSCOMOD_DPLL_SPEED_50G_BRCM_FEC_528_CR1_KR1,
    TSCOMOD_DPLL_SPEED_50G_BRCM_FEC_272_CR1_KR1,
    TSCOMOD_DPLL_SPEED_50G_BRCM_NO_FEC_NRZ_CR1_KR1,
    TSCOMOD_DPLL_SPEED_50G_BRCM_FEC_528_NRZ_CR1_KR1,
    TSCOMOD_DPLL_SPEED_50G_BRCM_FEC_272_NRZ_CR1_KR1,
    TSCOMOD_DPLL_SPEED_100G_BRCM_NO_FEC_X4,
    TSCOMOD_DPLL_SPEED_100G_BRCM_KR4_CR4,
    TSCOMOD_DPLL_SPEED_100G_BRCM_NO_FEC_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_FEC_528_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_FEC_272_CR2_KR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_NO_FEC_NRZ_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_FEC_528_NRZ_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_FEC_272_NRZ_KR2_CR2,
    TSCOMOD_DPLL_SPEED_100G_BRCM_KR1_CR1,
    TSCOMOD_DPLL_SPEED_100G_BRCM_FEC_272_KR1_CR1,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_544_CR8_KR8,
    TSCOMOD_DPLL_SPEED_200G_BRCM_NO_FEC_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_CR4_KR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_N4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_NO_FEC_NRZ_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_NRZ_CR4_KR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_NRZ_N4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_NRZ_KR4_CR4,
    TSCOMOD_DPLL_SPEED_200G_BRCM_KR2_CR2,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_KR2_CR2,
    TSCOMOD_DPLL_SPEED_200G_BRCM_FEC_272_N2,
    TSCOMOD_DPLL_SPEED_400G_BRCM_FEC_KR8_CR8,
    TSCOMOD_DPLL_SPEED_400G_BRCM_FEC_272_N8,
    TSCOMOD_DPLL_SPEED_400G_BRCM_NO_FEC_NRZ_KR8_CR8,
    TSCOMOD_DPLL_SPEED_400G_BRCM_FEC_NRZ_KR8_CR8,
    TSCOMOD_DPLL_SPEED_400G_BRCM_FEC_272_NRZ_N8,
    TSCOMOD_DPLL_SPEED_400G_BRCM_FEC_272_KR4_CR4,
    TSCOMOD_DPLL_SPEED_MODE_COUNT
} tscomod_dpll_1588_table_index_t;

typedef struct tscomod_dpll_1588_lkup_table_entry_s {
    /* Index for the default speed entry. */
    uint32_t mapped_spd_table_index;
    phymod_fec_type_t fec_type;
    /* Index for 1588 table. */
    tscomod_dpll_1588_table_index_t ts_table_index;
    uint32_t table_size;
} tscomod_dpll_1588_lkup_table_entry_t;

typedef uint32_t tscomod_dpll_ts_table_entry[TSCOMOD_DPLL_TS_TABLE_SIZE][TSCOMOD_DPLL_TS_ENTRY_SIZE];
typedef uint32_t tscomod_dpll_ts_table_entry_mem[TSCOMOD_DPLL_TS_ENTRY_SIZE];

int tscomod_dpll_1588_table_index_get(uint32_t speed_index, int *ts_table_index, uint32_t *table_size);

extern tscomod_dpll_ts_table_entry* tscomod_dpll_ts_table_tx_sop_get(void);
extern tscomod_dpll_ts_table_entry* tscomod_dpll_ts_table_rx_sop_get(void);
extern tscomod_dpll_ts_table_entry* tscomod_dpll_ts_table_tx_sfd_get(void);
extern tscomod_dpll_ts_table_entry* tscomod_dpll_ts_table_rx_sfd_get(void);
