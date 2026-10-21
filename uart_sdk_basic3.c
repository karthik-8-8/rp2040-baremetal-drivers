#include <stdio.h>
#include "pico/stdlib.h"
#include <string.h>

int main()
{
 stdio_init_all();
 sleep_ms(2000);

 gpio_init(25);
 gpio_set_dir(25,GPIO_OUT);

 char checker[25];

while(1)
{
    printf("Y or N for light blinking :");
    fgets(checker,sizeof(checker),stdin);
    printf("i received this [%s] \n",checker);

    if((strcmp(checker,"blink now\r\n"))==0)
        {
            gpio_put(25,1);                                                                                       
            sleep_ms(2000);
            gpio_put(25,0);

        }
}

}