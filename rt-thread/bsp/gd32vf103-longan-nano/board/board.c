/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 * 2020 12-21     mhoiting     Added Sipeed Longan Nano support
 */

#include <rtthread.h>
#include "board.h"

/*  System Tick Configuration */
static void systick_config(rt_uint32_t ticks) {

    /* set value */
    *(rt_uint64_t *) (TMR_CTRL_ADDR + TMR_MTIMECMP) = ticks;

    /* clear value */
    *(rt_uint64_t *) (TMR_CTRL_ADDR + TMR_MTIME) = 0;

    /* enable interrupt */
    eclic_irq_enable(CLIC_INT_TMR, 0, 0);
}

/* This is the timer interrupt service routine. */
void eclic_mtip_handler(void) {
    /* clear value */
    *(volatile rt_uint64_t *) (TMR_CTRL_ADDR + TMR_MTIME) = 0;

    /* tick increase */
    rt_tick_increase();
}

/* fixed misaligned bug for qemu */
void *__wrap_memset(void *s, int c, size_t n)
{
    return rt_memset(s, c, n);
}

#if defined (RT_USING_USER_MAIN) && defined (RT_USING_HEAP)
RT_WEAK void *rt_heap_begin_get(void)
{
extern void *_end;
    return &_end;
}

RT_WEAK void *rt_heap_end_get(void)
{
extern void *_heap_end;
    return &_heap_end;
}
#endif

#if defined (BSP_USING_USART) && defined (BSP_USING_UART)
/* Provide a console output function for RT-Thread */
static void usart_put_char(uint8_t ch) {
    usart_data_transmit(LONGAN_NANO_UART, ch);
    while (usart_flag_get(LONGAN_NANO_UART, USART_FLAG_TBE) == RESET) {
        /* busy-wait */
    }
}

void rt_hw_console_output(const void *string) {
    uint8_t ch;
    while (ch = * (uint8_t *) string++) {
        usart_put_char(ch);
        if (ch == '\n') usart_put_char('\r');
    }
}
#endif

void rt_hw_board_init(void) {

    /* Initialize system clocks */
    SystemInit();

    /* Initialize the ECLIC */
    eclic_init(ECLIC_NUM_INTERRUPTS);
    eclic_mode_enable();

    /* Initialize System Tick */
    systick_config(TMR_FREQ / RT_TICK_PER_SECOND);

    gd_longan_nano_led_init(LED1);
    gd_longan_nano_led_init(LED2);
    gd_longan_nano_led_init(LED3);
    gd_longan_nano_led_init(LED4); /* Additional personal leds */
    gd_longan_nano_led_init(LED5);
    gd_longan_nano_led_init(LED6);

    gd_longan_nano_led_off(LED1);
    gd_longan_nano_led_off(LED2);
    gd_longan_nano_led_off(LED3);
    gd_longan_nano_led_off(LED4);
    gd_longan_nano_led_off(LED5);
    gd_longan_nano_led_off(LED6);

    /* Set the shell console output device */
#ifdef RT_USING_CONSOLE
#ifdef RT_USING_DEVICE
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#endif
#if defined (BSP_USING_USART) && defined (BSP_USING_UART)
    gd_longan_nano_com_init(LONGAN_NANO_UART);
#endif
#endif

#ifdef RT_USING_HEAP
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get);
#endif

    /* Board underlying hardware initialization */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
}

/******************** end of file *******************/
