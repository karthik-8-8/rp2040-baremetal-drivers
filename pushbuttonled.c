#include <stdio.h>
#define SIO_BASE 0xD0000000
#define  IO_BANK0_BASE 0x40014000
#define  PADS_BANK0_BASE 0x4001C000

#define REG32(addr)   (*(volatile unsigned int*)(addr))

#define  GPIO_IN        REG32(SIO_BASE+0x004)
#define GPIO_OUT_SET   REG32(SIO_BASE+0x014)
#define GPIO_OUT_CLR   REG32(SIO_BASE+0x018)

#define GPIO25_CTRL    REG32(IO_BANK0_BASE+0x0CC)
#define GPIO25_PAD     REG32(PADS_BANK0_BASE+0x068)

#define GPIO14_CTRL    REG32(IO_BANK0_BASE+0x074)
#define GPIO14_PAD     REG32(PADS_BANK0_BASE+0x03C)
#define GPIO_OE_SET REG32(SIO_BASE+0x024)

int main()
{
    GPIO25_CTRL=5;
    GPIO14_CTRL=5;

    // electrically  configure the 25th pin 

    //GPIO25_PAD=0;
    GPIO_OE_SET = (1<<25);
    GPIO25_PAD &=~(1<<7);

    GPIO25_PAD |=(1<<6);

    //GPIO25_PAD &=~(1<<2);
    //GPIO25_PAD &=~(1<<3);

    // electrically configure the 14th pin 

    //GPIO14_PAD=0;

    //GPIO14_PAD &=~(1<<7);

    GPIO14_PAD |=(1<<6);

    GPIO14_PAD &=~(1<<2);
    GPIO14_PAD |=(1<<3);

    // sio configuration 


    
    while(1)
    {
        if(GPIO_IN & (1<<14))
            {
                GPIO_OUT_CLR =(1<<25);
            }
        else
            {

                GPIO_OUT_SET=(1<<25);
            }
    }
}