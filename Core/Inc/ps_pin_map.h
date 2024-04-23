#ifndef PS_PIN_MAP_H
#define PS_PIN_MAP_H

#include "ps_hardware_defs.h"

namespace ps
{
#if defined HARDWARE_VERSION_0P1
    const int AD8250_GAIN_A0 = 0;
    const int AD8250_GAIN_A1 = 1;
    const int TIA_SW1_IN1 = 2;
    const int TIA_SW1_IN2 = 5;
    const int TIA_SW1_IN3 = 6;
    const int TIA_SW1_IN4 = 7;
    const int TIA_SW2_IN1 = 8;
    const int TIA_SW2_IN2 = 9;
    const int TIA_SW2_IN3 = 22;
    const int TIA_SW2_IN4 = 23;
#elif defined (HARDWARE_VERSION_0P2) && defined (DEVBOARD_TEENSY)
    const int DAC_GAIN_A0 = 0;
    const int DAC_GAIN_A1 = 1;
    const int TIA_GAIN_A0 = 5;
    const int TIA_GAIN_A1 = 6;
    const int REF_GAIN_A0 = 20;
    const int REF_GAIN_A1 = 21;
    const int SW_CTR_ELECT = 7;
    const int SW_REF_ELECT = 8;
    const int SW_WRK_ELECT = 9;
#elif defined (HARDWARE_VERSION_0P2) && defined (DEVBOARD_ITSY_BITSY)
#define ANALOG_SPI SPI2
#define REF_ELECT_UNI_cs_pin GPIO_PIN_7
#define REF_ELECT_UNI_cs_GPIO_Port GPIOA
#define REF_ELECT_UNI_rd_pin GPIO_PIN_7
#define REF_ELECT_UNI_rd_GPIO_Port GPIOA
#define TIA_OUT_UNI_cs_pin GPIO_PIN_0
#define TIA_OUT_UNI_cs_GPIO_Port GPIOB
#define TIA_OUT_UNI_rd_pin GPIO_PIN_0
#define TIA_OUT_UNI_rd_GPIO_Port GPIOB
#define DAC_GAIN_A0_Pin GPIO_PIN_9
#define DAC_GAIN_A0_GPIO_Port GPIOC
#define DAC_GAIN_A1_Pin GPIO_PIN_8
#define DAC_GAIN_A1_GPIO_Port GPIOA
#define SW_WRK_ELECT_Pin GPIO_PIN_13
#define SW_WRK_ELECT_GPIO_Port GPIOA
#define SW_CTR_ELECT_Pin GPIO_PIN_4
#define SW_CTR_ELECT_GPIO_Port GPIOB
#define SW_REF_ELECT_Pin GPIO_PIN_5
#define SW_REF_ELECT_GPIO_Port GPIOB
#define TIA_GAIN_A1_Pin GPIO_PIN_6
#define TIA_GAIN_A1_GPIO_Port GPIOB
#define REF_GAIN_A0_Pin GPIO_PIN_7
#define REF_GAIN_A0_GPIO_Port GPIOB
#define REF_GAIN_A1_Pin GPIO_PIN_8
#define REF_GAIN_A1_GPIO_Port GPIOB
#define TIA_GAIN_A0_Pin GPIO_PIN_9
#define TIA_GAIN_A0_GPIO_Port GPIOB
#else
    #error "HARDWARE_VERSION must be specified"
#endif

#if defined DEVBOARD_TEENSY
    const int DAC_UNI_PIN = A14;
    const int TIA_OUT_UNI_PIN = A1;
    const int REF_ELECT_UNI_PIN = A2;
#elif defined DEVBOARD_ITSY_BITSY
#define DAC_UNI_channel 1
//#define TIA_OUT_UNI_channel 2
//#define REF_ELECT_UNI_channel 3
#define PWM_timer TIM2
#else
    #error "DEVBOARD must be specified"
#endif

#if defined MUX_CAPABLE
    #if defined DEVBOARD_TEENSY
    // Multiplexer switch pins
    const int MUX_WRK1_TO_TIA = 24;
    const int MUX_WRK1_TO_GND = 28;
    const int MUX_WRK2_TO_TIA = 25;
    const int MUX_WRK2_TO_GND = 29;
    const int MUX_WRK3_TO_TIA = 26;
    const int MUX_WRK3_TO_GND = 30;
    const int MUX_WRK4_TO_TIA = 27;
    const int MUX_WRK4_TO_GND = 31;
    const int MUX_WRK5_TO_TIA = 4;
    const int MUX_WRK5_TO_GND = 11;
    const int MUX_WRK6_TO_TIA = 19;
    const int MUX_WRK6_TO_GND = 13;
    const int MUX_WRK7_TO_TIA = 18;
    const int MUX_WRK7_TO_GND = 10;
    const int MUX_CTR_CONN = 3;
    const int MUX_REF_CONN = 12;
    #else
        #error "DEVBOARD doesn't support multiplexer"
    #endif
#endif

}

#endif
