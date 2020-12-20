/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-07-23     tyustli      first version
 */

#include <rtthread.h>
#include <gd32vf103_longan_nano.h>
// TODO #include "riscv_encoding.h"

extern volatile uint32_t systick;

static void systick_delay_ms(uint32_t ms) {

  // Calculate the 'system tick' value to wait until.
  uint32_t done = systick + ms;

  // Wait until the 'systick' value ticks up enough.
  while ( systick < done ) {
      __WFI();
  }
}

static int main_loop(void) {
    gd_longan_nano_led_init(LED1);
    gd_longan_nano_led_init(LED2);

    gd_longan_nano_led_on(LED2);

    while (1)
    {
        gd_longan_nano_led_on(LED1);
        // rt_thread_mdelay(700);
        systick_delay_ms(7);

        gd_longan_nano_led_off(LED1);
        // rt_thread_mdelay(300);
        systick_delay_ms(3);

        gd_longan_nano_led_off(LED2);
    }
}

int main(int argc, char *argv[]) {

    main_loop();

    return RT_EOK;
}

/******************** end of file *******************/
