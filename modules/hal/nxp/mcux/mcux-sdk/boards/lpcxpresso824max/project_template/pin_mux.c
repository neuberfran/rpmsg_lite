/*
 * Copyright 2017-2021 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v8.0
processor: LPC824
package_id: LPC824M201JHI33
mcu_data: ksdk2_0
processor_version: 0.9.4
board: LPCXpresso824
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_gpio.h"
#include "fsl_iocon.h"
#include "fsl_swm.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
    BOARD_InitDEBUG_UARTPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitPins(void)
{
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitLEDsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '11', peripheral: GPIO, signal: 'PIO0, 27', pin_signal: PIO0_27, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled, hysteresis: disabled,
    opendrain: disabled, smode: bypass, clkdiv: div0}
  - {pin_num: '10', peripheral: GPIO, signal: 'PIO0, 16', pin_signal: PIO0_16, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled, hysteresis: disabled,
    opendrain: disabled, smode: bypass, clkdiv: div0}
  - {pin_num: '2', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: LED_RED, direction: OUTPUT, gpio_init_state: 'true', mode: inactive, invert: disabled,
    hysteresis: disabled, opendrain: disabled, smode: bypass, clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitLEDsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitLEDsPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t LED_RED_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 2)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_RED_GPIO, BOARD_INITLEDSPINS_LED_RED_PORT, BOARD_INITLEDSPINS_LED_RED_PIN, &LED_RED_config);

    gpio_pin_config_t LED_GREEN_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO0_16 (pin 10)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_GREEN_GPIO, BOARD_INITLEDSPINS_LED_GREEN_PORT, BOARD_INITLEDSPINS_LED_GREEN_PIN, &LED_GREEN_config);

    gpio_pin_config_t LED_BLUE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 1U,
    };
    /* Initialize GPIO functionality on pin PIO0_27 (pin 11)  */
    GPIO_PinInit(BOARD_INITLEDSPINS_LED_BLUE_GPIO, BOARD_INITLEDSPINS_LED_BLUE_PORT, BOARD_INITLEDSPINS_LED_BLUE_PIN, &LED_BLUE_config);

    const uint32_t LED_RED = (/* No addition pin function */
                              IOCON_PIO_MODE_INACT |
                              /* Disable hysteresis */
                              IOCON_PIO_HYS_DI |
                              /* Input not invert */
                              IOCON_PIO_INV_DI |
                              /* Disables Open-drain function */
                              IOCON_PIO_OD_DI |
                              /* Bypass input filter */
                              IOCON_PIO_SMODE_BYPASS |
                              /* IOCONCLKDIV0 */
                              IOCON_PIO_CLKDIV0);
    /* PIO0 PIN12 (coords: 2) is configured as GPIO, PIO0, 12. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_12, LED_RED);

    const uint32_t LED_GREEN = (/* No addition pin function */
                                IOCON_PIO_MODE_INACT |
                                /* Disable hysteresis */
                                IOCON_PIO_HYS_DI |
                                /* Input not invert */
                                IOCON_PIO_INV_DI |
                                /* Disables Open-drain function */
                                IOCON_PIO_OD_DI |
                                /* Bypass input filter */
                                IOCON_PIO_SMODE_BYPASS |
                                /* IOCONCLKDIV0 */
                                IOCON_PIO_CLKDIV0);
    /* PIO0 PIN16 (coords: 10) is configured as GPIO, PIO0, 16. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_16, LED_GREEN);

    const uint32_t LED_BLUE = (/* No addition pin function */
                               IOCON_PIO_MODE_INACT |
                               /* Disable hysteresis */
                               IOCON_PIO_HYS_DI |
                               /* Input not invert */
                               IOCON_PIO_INV_DI |
                               /* Disables Open-drain function */
                               IOCON_PIO_OD_DI |
                               /* Bypass input filter */
                               IOCON_PIO_SMODE_BYPASS |
                               /* IOCONCLKDIV0 */
                               IOCON_PIO_CLKDIV0);
    /* PIO0 PIN27 (coords: 11) is configured as GPIO, PIO0, 27. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_27, LED_BLUE);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitDEBUG_UARTPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '22', peripheral: USART0, signal: TXD, pin_signal: PIO0_7/ADC_0, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '31', peripheral: USART0, signal: RXD, pin_signal: PIO0_18/ADC_8, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitDEBUG_UARTPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitDEBUG_UARTPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: Enable. */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t DEBUG_UART_RX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Disable hysteresis */
                                    IOCON_PIO_HYS_DI |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI |
                                    /* Bypass input filter */
                                    IOCON_PIO_SMODE_BYPASS |
                                    /* IOCONCLKDIV0 */
                                    IOCON_PIO_CLKDIV0);
    /* PIO0 PIN18 (coords: 31) is configured as USART0, RXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_18, DEBUG_UART_RX);

    const uint32_t DEBUG_UART_TX = (/* Selects pull-up function */
                                    IOCON_PIO_MODE_PULLUP |
                                    /* Disable hysteresis */
                                    IOCON_PIO_HYS_DI |
                                    /* Input not invert */
                                    IOCON_PIO_INV_DI |
                                    /* Disables Open-drain function */
                                    IOCON_PIO_OD_DI |
                                    /* Bypass input filter */
                                    IOCON_PIO_SMODE_BYPASS |
                                    /* IOCONCLKDIV0 */
                                    IOCON_PIO_CLKDIV0);
    /* PIO0 PIN7 (coords: 22) is configured as USART0, TXD. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_7, DEBUG_UART_TX);

    /* USART0_TXD connect to P0_7 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_TXD, kSWM_PortPin_P0_7);

    /* USART0_RXD connect to P0_18 */
    SWM_SetMovablePinSelect(SWM0, kSWM_USART0_RXD, kSWM_PortPin_P0_18);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitSWD_DEBUGPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '6', peripheral: SWD, signal: SWCLK, pin_signal: SWCLK/PIO0_3, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '7', peripheral: SWD, signal: SWDIO, pin_signal: SWDIO/PIO0_2, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
  - {pin_num: '3', peripheral: SYSCON, signal: RESETN, pin_signal: RESETN/PIO0_5, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled, smode: bypass,
    clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitSWD_DEBUGPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitSWD_DEBUGPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables clock for switch matrix.: Enable. */
    CLOCK_EnableClock(kCLOCK_Swm);

    const uint32_t DEBUG_SWD_SWDIO = (/* Selects pull-up function */
                                      IOCON_PIO_MODE_PULLUP |
                                      /* Disable hysteresis */
                                      IOCON_PIO_HYS_DI |
                                      /* Input not invert */
                                      IOCON_PIO_INV_DI |
                                      /* Disables Open-drain function */
                                      IOCON_PIO_OD_DI |
                                      /* Bypass input filter */
                                      IOCON_PIO_SMODE_BYPASS |
                                      /* IOCONCLKDIV0 */
                                      IOCON_PIO_CLKDIV0);
    /* PIO0 PIN2 (coords: 7) is configured as SWD, SWDIO. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_2, DEBUG_SWD_SWDIO);

    const uint32_t DEBUG_SWD_SWDCLK = (/* Selects pull-up function */
                                       IOCON_PIO_MODE_PULLUP |
                                       /* Disable hysteresis */
                                       IOCON_PIO_HYS_DI |
                                       /* Input not invert */
                                       IOCON_PIO_INV_DI |
                                       /* Disables Open-drain function */
                                       IOCON_PIO_OD_DI |
                                       /* Bypass input filter */
                                       IOCON_PIO_SMODE_BYPASS |
                                       /* IOCONCLKDIV0 */
                                       IOCON_PIO_CLKDIV0);
    /* PIO0 PIN3 (coords: 6) is configured as SWD, SWCLK. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_3, DEBUG_SWD_SWDCLK);

    const uint32_t DEBUG_SWD_RESETN = (/* Selects pull-up function */
                                       IOCON_PIO_MODE_PULLUP |
                                       /* Disable hysteresis */
                                       IOCON_PIO_HYS_DI |
                                       /* Input not invert */
                                       IOCON_PIO_INV_DI |
                                       /* Disables Open-drain function */
                                       IOCON_PIO_OD_DI |
                                       /* Bypass input filter */
                                       IOCON_PIO_SMODE_BYPASS |
                                       /* IOCONCLKDIV0 */
                                       IOCON_PIO_CLKDIV0);
    /* PIO0 PIN5 (coords: 3) is configured as SYSCON, RESETN. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_5, DEBUG_SWD_RESETN);

    /* SWCLK connect to P0_3 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWCLK, true);

    /* SWDIO connect to P0_2 */
    SWM_SetFixedPinSelect(SWM0, kSWM_SWDIO, true);

    /* RESETN connect to P0_5 */
    SWM_SetFixedPinSelect(SWM0, kSWM_RESETN, true);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitBUTTONsPins:
- options: {callFromInitBoot: 'false', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '4', peripheral: GPIO, signal: 'PIO0, 4', pin_signal: PIO0_4/ADC_11, direction: INPUT, mode: pullUp, invert: disabled, hysteresis: disabled, opendrain: disabled,
    smode: bypass, clkdiv: div0}
  - {pin_num: '2', peripheral: GPIO, signal: 'PIO0, 12', pin_signal: PIO0_12, identifier: SW2, direction: INPUT, mode: pullUp, invert: disabled, hysteresis: disabled,
    opendrain: disabled, smode: bypass, clkdiv: div0}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBUTTONsPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
/* Function assigned for the Cortex-M0P */
void BOARD_InitBUTTONsPins(void)
{
    /* Enables clock for IOCON block.: Enable. */
    CLOCK_EnableClock(kCLOCK_Iocon);
    /* Enables the clock for the GPIO0 module */
    CLOCK_EnableClock(kCLOCK_Gpio0);

    gpio_pin_config_t SW1_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_4 (pin 4)  */
    GPIO_PinInit(BOARD_INITBUTTONSPINS_SW1_GPIO, BOARD_INITBUTTONSPINS_SW1_PORT, BOARD_INITBUTTONSPINS_SW1_PIN, &SW1_config);

    gpio_pin_config_t SW2_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U,
    };
    /* Initialize GPIO functionality on pin PIO0_12 (pin 2)  */
    GPIO_PinInit(BOARD_INITBUTTONSPINS_SW2_GPIO, BOARD_INITBUTTONSPINS_SW2_PORT, BOARD_INITBUTTONSPINS_SW2_PIN, &SW2_config);

    const uint32_t SW2 = (/* Selects pull-up function */
                          IOCON_PIO_MODE_PULLUP |
                          /* Disable hysteresis */
                          IOCON_PIO_HYS_DI |
                          /* Input not invert */
                          IOCON_PIO_INV_DI |
                          /* Disables Open-drain function */
                          IOCON_PIO_OD_DI |
                          /* Bypass input filter */
                          IOCON_PIO_SMODE_BYPASS |
                          /* IOCONCLKDIV0 */
                          IOCON_PIO_CLKDIV0);
    /* PIO0 PIN12 (coords: 2) is configured as GPIO, PIO0, 12. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_12, SW2);

    const uint32_t SW1 = (/* Selects pull-up function */
                          IOCON_PIO_MODE_PULLUP |
                          /* Disable hysteresis */
                          IOCON_PIO_HYS_DI |
                          /* Input not invert */
                          IOCON_PIO_INV_DI |
                          /* Disables Open-drain function */
                          IOCON_PIO_OD_DI |
                          /* Bypass input filter */
                          IOCON_PIO_SMODE_BYPASS |
                          /* IOCONCLKDIV0 */
                          IOCON_PIO_CLKDIV0);
    /* PIO0 PIN4 (coords: 4) is configured as GPIO, PIO0, 4. */
    IOCON_PinMuxSet(IOCON, IOCON_INDEX_PIO0_4, SW1);

    /* Disable clock for switch matrix. */
    CLOCK_DisableClock(kCLOCK_Swm);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
