//----------------------------------------------------------
/* Timer Registers */

typedef struct {                                /*!< (@ 0x40008000) TIMER0 Structure                                           */
  volatile           uint32_t  TASKS_START;                  /*!< (@ 0x00000000) Start Timer                                                */
  volatile           uint32_t  TASKS_STOP;                   /*!< (@ 0x00000004) Stop Timer                                                 */
  volatile           uint32_t  TASKS_COUNT;                  /*!< (@ 0x00000008) Increment Timer (Counter mode only)                        */
  volatile           uint32_t  TASKS_CLEAR;                  /*!< (@ 0x0000000C) Clear time                                                 */
  volatile           uint32_t  TASKS_SHUTDOWN;               /*!< (@ 0x00000010) Deprecated register - Shut down timer                      */
  volatile const     uint32_t  RESERVED[11];
  volatile           uint32_t  TASKS_CAPTURE[6];             /*!< (@ 0x00000040) Description collection[0]: Capture Timer value
                                                                    to CC[0] register                                          */
  volatile const     uint32_t  RESERVED1[58];
  volatile           uint32_t  EVENTS_COMPARE[6];            /*!< (@ 0x00000140) Description collection[0]: Compare event on CC[0]
                                                                    match                                                      */
  volatile const     uint32_t  RESERVED2[42];
  volatile           uint32_t  SHORTS;                       /*!< (@ 0x00000200) Shortcut register                                          */
  volatile const     uint32_t  RESERVED3[64];
  volatile           uint32_t  INTENSET;                     /*!< (@ 0x00000304) Enable interrupt                                           */
  volatile           uint32_t  INTENCLR;                     /*!< (@ 0x00000308) Disable interrupt                                          */
  volatile const     uint32_t  RESERVED4[126];
  volatile           uint32_t  MODE;                         /*!< (@ 0x00000504) Timer mode selection                                       */
  volatile           uint32_t  BITMODE;                      /*!< (@ 0x00000508) Configure the number of bits used by the TIMER             */
  volatile const     uint32_t  RESERVED5;
  volatile           uint32_t  PRESCALER;                    /*!< (@ 0x00000510) Timer prescaler register                                   */
  volatile const     uint32_t  RESERVED6[11];
  volatile           uint32_t  CC[6];                        /*!< (@ 0x00000540) Description collection[0]: Capture/Compare register
                                                                    0                                                          */
} NRF_TIMER_Type;                               /*!< Size = 1368 (0x558)

//------------------------------------------------------------------------------------------------------------------------------------------------

/** @brief Timer bit width. */
typedef enum
{
    NRF_TIMER_BIT_WIDTH_8  = TIMER_BITMODE_BITMODE_08Bit, ///< Timer bit width 8 bit.
    NRF_TIMER_BIT_WIDTH_16 = TIMER_BITMODE_BITMODE_16Bit, ///< Timer bit width 16 bit.
    NRF_TIMER_BIT_WIDTH_24 = TIMER_BITMODE_BITMODE_24Bit, ///< Timer bit width 24 bit.
    NRF_TIMER_BIT_WIDTH_32 = TIMER_BITMODE_BITMODE_32Bit  ///< Timer bit width 32 bit.
} nrf_timer_bit_width_t;

//--------------------------------------------------------------------------------------

/* Defining Bitmode as per datasheet truthtable value */

#define TIMER_BITMODE_BITMODE_16Bit (0UL) /*!< 16 bit timer bit width */
#define TIMER_BITMODE_BITMODE_08Bit (1UL) /*!< 8 bit timer bit width */
#define TIMER_BITMODE_BITMODE_24Bit (2UL) /*!< 24 bit timer bit width */
#define TIMER_BITMODE_BITMODE_32Bit (3UL) /*!< 32 bit timer bit width */

//-------------------------------------------------------------------------------------

/* Timer interupt Interupt service routine */
// TIMER0_IRQn
#define nrfx_timer_0_irq_handler    TIMER0_IRQHandler

//--------------------------------------------------------------------------------------
/* Defining Mode of operation either timer or counter */

/* Send 0 for timer operation 
   Send 1 for counter operation
   Send 2 for low power counter operation

   By default 0 timer operation is selected
*/

#define TIMER_MODE_TIMERMODE   (0UL) /*!< Timer mode */
#define TIMER_MODE_COUNTERMODE (1UL) /*!< Counter mode */
#define TIMER_MODE_LOWCOUNTERMODE (2UL) /*!< Low power Counter mode */

//---------------------------------------------------------------------------------------------------------------------------------------------------


/* Register: TIMER_PRESCALER */
/* Description: Timer prescaler register */

/* Bits 3..0 : Prescaler value */
#define TIMER_PRESCALER_PRESCALER_Pos (0UL) /*!< Position of PRESCALER field. */
#define TIMER_PRESCALER_PRESCALER_Msk (0xFUL << TIMER_PRESCALER_PRESCALER_Pos) /*!< Bit mask of PRESCALER field. */

//---------------------------------------------------------------------------------------------------------------------------------------------------


/* Enum to define prescalars */

/** @brief Timer prescalers. */
typedef enum
{
    NRF_TIMER_FREQ_16MHz = 0, ///< Timer frequency 16 MHz.
    NRF_TIMER_FREQ_8MHz,      ///< Timer frequency 8 MHz.
    NRF_TIMER_FREQ_4MHz,      ///< Timer frequency 4 MHz.
    NRF_TIMER_FREQ_2MHz,      ///< Timer frequency 2 MHz.
    NRF_TIMER_FREQ_1MHz,      ///< Timer frequency 1 MHz.
    NRF_TIMER_FREQ_500kHz,    ///< Timer frequency 500 kHz.
    NRF_TIMER_FREQ_250kHz,    ///< Timer frequency 250 kHz.
    NRF_TIMER_FREQ_125kHz,    ///< Timer frequency 125 kHz.
    NRF_TIMER_FREQ_62500Hz,   ///< Timer frequency 62500 Hz.
    NRF_TIMER_FREQ_31250Hz    ///< Timer frequency 31250 Hz.
} nrf_timer_frequency_t;

//-------------------------------------------------------------------------------------------------------------------------------------------------------

/** @brief Timer interrupts. */
typedef enum
{
       TIMER_INTENSET_Disabled = 0;
       TIMER_INTENSET_Enabled  = 1;
} nrf_timer_int_t;

//-------------------------------------------------------------------------------------------------------------------------------------------------------


