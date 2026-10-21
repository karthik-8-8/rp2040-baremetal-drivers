#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    gpio_init(25);
    gpio_init(14);

    gpio_set_dir(25,GPIO_OUT);
    gpio_set_dir(14,GPIO_IN);

    gpio_pull_up(14);

    while(1)
    {
        if(gpio_get(14)==0)
            gpio_put(25,1);
        else
            gpio_put(25,0);
    }
}
