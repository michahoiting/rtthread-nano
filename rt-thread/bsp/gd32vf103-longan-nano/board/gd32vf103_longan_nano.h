/*!
    \file    gd32vf103-longan-nano-bare-metal-blink/drivers/gd32vf103_longan_nano.h
    \brief   definitions for GD32VF103 Sipeed Longan Nano's leds, keys and COM
             ports hardware resources

    \version 2019-6-5, V1.0.0, demo for GD32VF103
*/

/*
    Copyright (c) 2019, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef GD32VF103_LONGAN_NANO_H
#define GD32VF103_LONGAN_NANO_H

#ifdef cplusplus
 extern "C" {
#endif

#include "gd32vf103.h"

/*
 * Sipeed Longan Nano developer board
 * 
 * CPU: GD32VF103CBT6
 * ROM: 128KB Flash @ 0x08000000 - 0x0801ffff
 * RAM: 32KB SRAM   @ 0x20000000 - 0x20007fff
 * 
 * Peripherals listes below:
 * - 4 x Universal 16-bit Timer
 * - 2 x Basic 16-bit Timer
 * - 1 x Advanced 16-bit Timer
 * - Watchdog timer
 * - RTC
 * - Systick
 * - 3 x USART
 * - 2 x I2C
 * - 3 x SPI
 * - 2 x I2S
 * - 2 x CAN
 * - 1 x USBFS(OTG)
 * - 2 x ADC(10 channel)
 * - 2 x DAC
 */

/* exported types */
typedef enum 
{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
    LED4 = 3,
    LED5 = 4,
    LED6 = 5,
} led_typedef_enum;

typedef enum 
{
    KEY_A = 0,
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;

/* sipeed longan nano board low layer led */
#define LEDn                             6U

/* red led */
#define LONGAN_NANO_LED1_PIN                         GPIO_PIN_13
#define LONGAN_NANO_LED1_GPIO_PORT                   GPIOC
#define LONGAN_NANO_LED1_GPIO_CLK                    RCU_GPIOC

/* green led */
#define LONGAN_NANO_LED2_PIN                         GPIO_PIN_1
#define LONGAN_NANO_LED2_GPIO_PORT                   GPIOA
#define LONGAN_NANO_LED2_GPIO_CLK                    RCU_GPIOA

/* blue led */
#define LONGAN_NANO_LED3_PIN                         GPIO_PIN_2
#define LONGAN_NANO_LED3_GPIO_PORT                   GPIOA
#define LONGAN_NANO_LED3_GPIO_CLK                    RCU_GPIOA

/* led A4*/
#define LONGAN_NANO_LED4_PIN                         GPIO_PIN_4
#define LONGAN_NANO_LED4_GPIO_PORT                   GPIOA
#define LONGAN_NANO_LED4_GPIO_CLK                    RCU_GPIOA

/* led A5*/
#define LONGAN_NANO_LED5_PIN                         GPIO_PIN_5
#define LONGAN_NANO_LED5_GPIO_PORT                   GPIOA
#define LONGAN_NANO_LED5_GPIO_CLK                    RCU_GPIOA

/* led A6*/
#define LONGAN_NANO_LED6_PIN                         GPIO_PIN_6
#define LONGAN_NANO_LED6_GPIO_PORT                   GPIOA
#define LONGAN_NANO_LED6_GPIO_CLK                    RCU_GPIOA

#define COMn                             3U

#define LONGAN_NANO_COM0                             USART0
#define LONGAN_NANO_COM0_TX_PIN                      GPIO_PIN_9
#define LONGAN_NANO_COM0_RX_PIN                      GPIO_PIN_10
#define LONGAN_NANO_COM0_GPIO_PORT                   GPIOA
#define LONGAN_NANO_COM0_GPIO_CLK                    RCU_GPIOA
#define LONGAN_NANO_COM0_CLK                         RCU_USART0

#define LONGAN_NANO_COM1                             USART1
#define LONGAN_NANO_COM1_TX_PIN                      GPIO_PIN_2
#define LONGAN_NANO_COM1_RX_PIN                      GPIO_PIN_3
#define LONGAN_NANO_COM1_GPIO_PORT                   GPIOA
#define LONGAN_NANO_COM1_GPIO_CLK                    RCU_GPIOA
#define LONGAN_NANO_COM1_CLK                         RCU_USART1

#define LONGAN_NANO_COM2                             USART2
#define LONGAN_NANO_COM2_TX_PIN                      GPIO_PIN_10
#define LONGAN_NANO_COM2_RX_PIN                      GPIO_PIN_11
#define LONGAN_NANO_COM2_GPIO_PORT                   GPIOB
#define LONGAN_NANO_COM2_GPIO_CLK                    RCU_GPIOB
#define LONGAN_NANO_COM2_CLK                         RCU_USART2

#define KEYn                             1U

/* BOOT0 push-button (non documented, but goes high when pressed) */
#define LONGAN_NANO_KEY_BOOT0_PIN                        GPIO_PIN_8
#define LONGAN_NANO_KEY_BOOT0_GPIO_PORT                  GPIOA
#define LONGAN_NANO_KEY_BOOT0_GPIO_CLK                   RCU_GPIOA
#define LONGAN_NANO_KEY_BOOT0_EXTI_LINE                  EXTI_8
#define LONGAN_NANO_KEY_BOOT0_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOA
#define LONGAN_NANO_KEY_BOOT0_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_8
#define LONGAN_NANO_KEY_BOOT0_EXTI_IRQn                  EXTI10_15_IRQn

/* function declarations */
/* configure led GPIO */
void gd_longan_nano_led_init(led_typedef_enum lednum);
/* turn on selected led */
void gd_longan_nano_led_on(led_typedef_enum lednum);
/* turn off selected led */
void gd_longan_nano_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void gd_longan_nano_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_longan_nano_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
/* return the selected key state */
uint8_t gd_longan_nano_key_state_get(key_typedef_enum key);
/* configure COM port */
void gd_longan_nano_com_init(uint32_t com);

#ifdef cplusplus
}
#endif

#endif /* GD32VF103_LONGAN_NANO_H */
