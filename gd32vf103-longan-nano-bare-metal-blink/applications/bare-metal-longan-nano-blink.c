#include <stdio.h>

#include "gd32vf103_longan_nano.h"
#include "systick.h"

int main(void)
{
    gd_longan_nano_com_init(LONGAN_NANO_COM0);
    gd_longan_nano_led_init(LED1);

    /* Wait for the USB to serial converter to pick up the carrier */
    delay_1ms(500);

    puts("Application started\n");

    int i;
    for (i=0; i<100; i++)
    {
        gd_longan_nano_led_on(LED1);
        delay_1ms(100);
        gd_longan_nano_led_off(LED1);
        delay_1ms(100);
    }

    puts("Application stopped\n");
    return 0;
}
