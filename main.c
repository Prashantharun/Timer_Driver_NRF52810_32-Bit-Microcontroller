/*
  
  Project : Basic Timer Pheripheral Driver
  Developer : Prashanth Arun 
  Date : 28/08/2020
 
  Github : https://github.com/Prashantharun
*/

//-----------------------------------------------------------------------------------

#include <stdbool.h>
#include <stdint.h>
#include "nrf.h"
#include "nrf_timer.h"
#include "bsp.h"
#include "app_error.h"

//--------------------------------------------------------------------------------------

 /* Global Variables */

   uint32_t count = 0;

//--------------------------------------------------------------------------------------

 /* Pointer to the structure of Timer */

 NRF_TIMER_Type * p_reg;

//----------------------------------------------------------------------------------------

/* Init Function to intialize the timer pheripheral */

void NRF_timer_init(NRF_TIMER_Type *  p_reg, nrf_timer_mode_t modes, nrf_timer_bit_width_t bitwidths, nrf_timer_frequency_t frequencys, nrf_timer_int_t interupptstatus)
{
   p_reg->TASKS_STOP = 1;
   p_reg->MODE = modes;
   p_reg->BITMODE = bitwidths;
   p_reg->PRESCALER = frequencys;
   setprescalar(&p_reg, frequencys);
   p_reg->INTENSET = interupptstatus;
   p_reg->TASKS_START = 1;
}

//---------------------------------------------------------------------------------------

/* Interrupt handler, an ISR called when timer register overflow occurs */

void nrfx_timer_0_irq_handler(void)
{
    count++;

    /* Clearing the timer overflow flag */
    p_reg->TASKS_CLEAR = 1;
}

//----------------------------------------------------------------------------------------

/* Function to set the bit width or Bit Mode */

/* Send 8 for 8 bitmode timer operation 
   Send 16 for 16 bitmode timer operation
   Send 24 for 24 bitmode timer operation
   Send 32 for 32 bitmode timer operation

   By default 16 bit is selected
*/

void set_bitmode(NRF_TIMER_Type *  p_reg, uint32_t bitwidth)
{
    switch (bitwidth)
    {
       case 8 :
       {
          p_reg->BITMODE = TIMER_BITMODE_BITMODE_08Bit;
          break;
       }

       case 16 :
       {
          p_reg->BITMODE = TIMER_BITMODE_BITMODE_16Bit;
          break;
       }

       case 24 :
       {
          p_reg->BITMODE = TIMER_BITMODE_BITMODE_24Bit;
          break;
       }

       case 32 :
       {
          p_reg->BITMODE = TIMER_BITMODE_BITMODE_32Bit;
          break;
       }

       default :
       {
          p_reg->BITMODE = TIMER_BITMODE_BITMODE_16Bit;
          break;
       }
    }
}

//---------------------------------------------------------------------------------------

/* Function to set the Mode of operation of timer */

/* Timer can be operated either as a timer or counter */

void setmode(NRF_TIMER_Type *  p_reg, uint32_t timermode)
{
       switch (bitwidth)
    {
       case 0 :
       {
          p_reg->MODE = TIMER_MODE_TIMERMODE;
          break;
       }

       case 1 :
       {
          p_reg->MODE = TIMER_MODE_COUNTERMODE;
          break;
       }

       case 2 :
       {
          p_reg->MODE = TIMER_MODE_LOWCOUNTERMODE;
          break;
       }

       default :
       {
          p_reg->MODE = TIMER_MODE_TIMERMODE;
          break;
       }
    }

}

//---------------------------------------------------------------------------------------

/* Function to set the prescalar 

 frequency = 16 MHz / (2 power PRESCALER) 
    NRF_TIMER_FREQ_16MHz = 0,     ///< Timer frequency 16 MHz.
    NRF_TIMER_FREQ_8MHz = 1,      ///< Timer frequency 8 MHz.
    NRF_TIMER_FREQ_4MHz = 2,      ///< Timer frequency 4 MHz.
    NRF_TIMER_FREQ_2MHz = 3,      ///< Timer frequency 2 MHz.
    NRF_TIMER_FREQ_1MHz = 4,      ///< Timer frequency 1 MHz.
    NRF_TIMER_FREQ_500kHz = 5,    ///< Timer frequency 500 kHz.
    NRF_TIMER_FREQ_250kHz = 6,    ///< Timer frequency 250 kHz.
    NRF_TIMER_FREQ_125kHz = 7,    ///< Timer frequency 125 kHz.
    NRF_TIMER_FREQ_62500Hz = 8,   ///< Timer frequency 62500 Hz.
    NRF_TIMER_FREQ_31250Hz = 9,   ///< Timer frequency 31250 Hz.
*/

void setprescalar(NRF_TIMER_Type *  p_reg, nrf_timer_frequency_t frequency)
{
    p_reg->PRESCALER = (p_reg->PRESCALER & ~TIMER_PRESCALER_PRESCALER_Msk) |
                         ((frequency << TIMER_PRESCALER_PRESCALER_Pos) &
                              TIMER_PRESCALER_PRESCALER_Msk);
}

//--------------------------------------------------------------------------------------

/* CallBackfunction after timer interuppt */

void Timer_interrupt_CallBackfunction()
{
   /*
       I will this callback use to do some operations.   
   */
}

//--------------------------------------------------------------------------------------

/* Start Function which intializes two  */

void start_function(uint32_t timeus, void (*ptr)())
{
   NRF_timer_init(&p_reg, TIMER_MODE_TIMERMODE, NRF_TIMER_BIT_WIDTH_8, NRF_TIMER_FREQ_8MHz, TIMER_INTENSET_Enabled);

   /* Start the timer */
   p_reg->TASKS_START = 1;
   
   /*

    input frequency= Fosc = 16 Mhz

    Prescaler = NRF_TIMER_FREQ_8MHz = 1,      ///< Timer frequency 8 MHz.

    Tick Counter frequency = 1/F =  0.125 u s

    Delay required = timeus

    Delay required = Timer Count * Tick Counter frequency

    Timer Count = Delay required / Tick Counter frequency

   */
   
    Timer_count =  timeus/0.000000125;

}

//-------------------------------------------------------------------------------------

/* Stop Function */

void stop_function()
{
   p_reg->TASKS_STOP = 1;

   p_reg->TASKS_CLEAR = 1;
}

//---------------------------------------------------------------------------------------

/**
 * @brief Function for main application entry.
 */
int main(void)
{
  void (*ptr)() = &Timer_interrupt_CallBackfunction;

//-------------------------------------------------------------------------------------------
    
    while (1)
    {
        __WFI();  //Wait for interrupt

       /* count value is incremented by ISR of Timer once 8 bit Timer register overflows */

      if(Timer_count = count)   //Once count reaches 16000 value, exactly 512 ms delay will be generated
       {
         count = 0;
       }
    }
}

/** @} */
