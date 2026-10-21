#include <stdio.h>
#include <stdint.h>

#define reg_32(addr)    *(volatile uint32_t*)(addr)

#define IO_BANK0_BASE   0x40014000
#define PADS_BANK0_BASE 0x4001C000
#define SIO_BASE        0xD0000000
#define TIMER_BASE      0x40054000



#define GPIO25_CTRL reg_32(IO_BANK0_BASE+0x0cc)
#define GPIO0_CTRL  reg_32(IO_BANK0_BASE+0x004)
#define GPIO14_CTRL reg_32(IO_BANK0_BASE+0x074)

#define PADS14      reg_32(PADS_BANK0_BASE+0x3C)

#define GPIO_OUT_SET reg_32(SIO_BASE+0x014)
#define GPIO_OUT_CLR reg_32(SIO_BASE+0x018)
#define GPIO_OE_SET  reg_32(SIO_BASE+0x024)
#define GPIO_IN  reg_32(SIO_BASE+0x004)


#define TIMERAWL  reg_32(TIMER_BASE+0x28)

void task_led1(void)
{
    static uint32_t last = 0;
    static uint8_t state = 0;

    uint32_t now = TIMERAWL;

    if(now - last >= 500000)
    {
        last = now;

        if(state)
        {
            GPIO_OUT_CLR = (1<<25);
        }
        else
        {
            GPIO_OUT_SET = (1<<25);
        }

        state ^= 1;
    }
}
void task_led2(void)
{
    static uint32_t last = 0;
    static uint8_t state = 0;

    uint32_t now = TIMERAWL;

    if(now - last >= 250000)
    {
        last = now;

        if(state)
        {
            GPIO_OUT_CLR = (1<<0);
        }
        else
        {
            GPIO_OUT_SET = (1<<0);
        }

        state ^= 1;
    }
}
void task_button()
{
if((GPIO_IN&(1<<14))==0)
{
    //on buzzer 
}



}


int main()
{
GPIO0_CTRL=5;
GPIO25_CTRL=5;
GPIO14_CTRL=5;
GPIO_OE_SET=(1<<0)|(1<<25);

PADS14=PADS14 | (1<<6) | (1<<3);
PADS14&=~((1<<2)|(1<<7));

while(1)
{
    task_led1();
    task_led2();
    task_button();
}

}