/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 *
 */

#include <rtthread.h>
#include "board.h"
#include "riscv_encoding.h"

#ifdef RT_USING_SERIAL
#include <drv_usart.h>
#endif

// Global 'tick' value.
volatile uint32_t systick = 0;
volatile uint32_t systick_ms = 20;

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
    static uint32_t done = 0;

    // Increment the global 'tick' value.
    systick++;
    if (systick > done) {
        done = systick + systick_ms;
        gd_longan_nano_led_toggle(LED4);
    }

    /* clear value */
    *(volatile rt_uint64_t *) (TMR_CTRL_ADDR + TMR_MTIME) = 0;

    // /* enter interrupt */
    // rt_interrupt_enter(); // THIS WILL BREAK INTERRUPT HANDING

    /* tick increase */
    rt_tick_increase();

    // /* leave interrupt */
    // rt_interrupt_leave(); // THIS WILL BREAK INTERRUPT HANDING
}

/* fixed misaligned bug for qemu */
void *__wrap_memset(void *s, int c, size_t n)
{
    return rt_memset(s, c, n);
}

#if defined(RT_USING_USER_MAIN) && defined(RT_USING_HEAP)
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

void rt_hw_board_init(void) {

extern void riscv_clock_init(void);
    riscv_clock_init();

    set_csr(mstatus, MSTATUS_MIE);

    gd_longan_nano_led_init(LED1); /* Thread 1 */
    gd_longan_nano_led_init(LED2); /* Thread 2 */
    gd_longan_nano_led_init(LED3); /* Unused */
    gd_longan_nano_led_init(LED4); /* Systick interrupt */
    gd_longan_nano_led_init(LED5); /* Thread main */
    gd_longan_nano_led_init(LED6); /* systick_loop */

    gd_longan_nano_led_off(LED1);
    gd_longan_nano_led_off(LED2);
    gd_longan_nano_led_off(LED3);
    gd_longan_nano_led_off(LED4);
    gd_longan_nano_led_off(LED5);
    gd_longan_nano_led_off(LED6);

    systick_config(TMR_FREQ / RT_TICK_PER_SECOND);

#ifdef RT_USING_HEAP
    rt_system_heap_init(rt_heap_begin_get(), rt_heap_end_get);
#endif

    /* USART driver initialization is open by default */
#ifdef RT_USING_SERIAL
    rt_hw_usart_init();
#endif

    /* Set the shell console output device */
#ifdef RT_USING_CONSOLE

#ifdef RT_USING_DEVICE
    rt_console_set_device(RT_CONSOLE_DEVICE_NAME);
#else
    gd_longan_nano_com_init(LONGAN_NANO_COM0);
    rt_kputs("\nUSART0 start done\n");
#endif

#endif

    /* Board underlying hardware initialization */
#ifdef RT_USING_COMPONENTS_INIT
    rt_components_board_init();
#endif
}

void rt_hw_console_output(const char *str)
{
extern int puts(const char* string);
    puts(str);
}

/******************** end of file *******************/
