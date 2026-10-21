#include <stdio.h>
#include "pico/stdlib.h"

int main()
{
    stdio_init_all(); // starts usb connection
    sleep_ms(2000);
    gpio_init(25);
    gpio_set_dir(25,GPIO_OUT);

    unsigned int checker=0;

    while(1)
        {   
          printf("tell checker :");  
          scanf("%d",&checker);
          if((checker%5)==0)
          {
            gpio_put(25,1);
            sleep_ms(3000); 
            gpio_put(25,0);
          }

        }
}