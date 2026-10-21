#include<stdio.h>

#define IO_BANK0_BASE   0x40014000
#define PADS_BANK0_BASE 0x4001C000
#define SIO_BASE        0xD0000000
#define PPB_BASE        0xE0000000

#define REG32(addr)     (*(volatile unsigned int *)(addr))

#define GPIO25_CTRL     REG32(IO_BANK0_BASE+0x0CC)
//#define GPIO14_CTRL     (IO_BANK0_BASE+)


#define GPIO_OE_SET     REG32(SIO_BASE+0x024)
#define GPIO_OUT_XOR    REG32(SIO_BASE+0x01C)

#define GPIO14_PAD      REG32(PADS_BANK0_BASE+0x03C)

#define PROCO_INTE1     REG32(IO_BANK0_BASE+0x104)
#define PROCO_INTS1     REG32(IO_BANK0_BASE+0x124)
#define INTR1           REG32(IO_BANK0_BASE+0x0F4)


#define NVIC_ISER       REG32(PPB_BASE+0xE100)


void isr_io_bank0()
{
    if(PROCO_INTS1 & (1<<26))
    {
        GPIO_OUT_XOR=(1<<25);
        //reset the flag
        INTR1=(1<<26);
    }    
}

int main()
{
    GPIO25_CTRL=5;

    //electric configuration pin 14

    GPIO14_PAD |=(1<<3);
    GPIO14_PAD &=~(1<<2);
    GPIO14_PAD |=(1<<6);

    //GPIO25 configuration;
    GPIO_OE_SET =(1<<25);


    //interrupt handling
    PROCO_INTE1 |= (1<<26);

    //NVIC configuration
    NVIC_ISER =(1<<13);

    while(1)
    {        
    }
}

