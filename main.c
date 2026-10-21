#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    //initialising 25th pin and also IO_BANK0 as 5 and PADS_BANK0 initialized or resets
    gpio_init(25);

    //configuring the pin as output that is GPIO_OE_SET
    gpio_set_dir(25,GPIO_OUT);

    while(1)
        {
        gpio_put(25,1);
        sleep_ms(500);
        gpio_put(25,0);
        sleep_ms(500);
        }
}