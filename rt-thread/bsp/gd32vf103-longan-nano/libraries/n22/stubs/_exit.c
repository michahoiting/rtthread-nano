/* See LICENSE of license details. */

#include <unistd.h>

#include "rtthread.h"
#include "gd32vf103_longan_nano.h"
#include "stub.h"

void _exit(int code)
{
//  const char message[] = "\nProgram has exited with code:";
//  write(STDERR_FILENO, message, sizeof(message) - 1);
//  write_hex(STDERR_FILENO, code);
//  write(STDERR_FILENO, "\n", 1);
    rt_kprintf("\nProgram has exited with code:%d\n", code);
    rt_kprintf("System halted.\n");

    gd_longan_nano_led_off(LED1);
    gd_longan_nano_led_off(LED2);
    gd_longan_nano_led_off(LED3);
    for (;;) {
        extern volatile uint32_t systick;
        static uint32_t done = 0;

        if (systick > done) {
            done = systick + 100;
            gd_longan_nano_led_toggle(LED1);
            gd_longan_nano_led_toggle(LED2);
            gd_longan_nano_led_toggle(LED3);
        }
        __WFI();
    }
}
