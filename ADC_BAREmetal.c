#include  <stdint.h>
#include  <stdio.h>
#include  "pico/stdlib.h"

#define reg_32(addr)    *(volatile uint32_t*)(addr)

#define ADC_BASE  0x4004c000UL
#define RESET_BASE 0x4000C000UL
#define IO_BANK0_BASE 0x40014000UL
#define PADS_BANK0_BASE 0x4001C000UL 

#define CS  reg_32(ADC_BASE+0x00)
#define RESULT  reg_32(ADC_BASE+0x04)
#define DIV reg_32(ADC_BASE+0x10)
#define FCS reg_32(ADC_BASE+0x08)
#define FIFO reg_32(ADC_BASE+0x0C)


#define RESET   reg_32(RESET_BASE+0x0)
#define RESET_DONE reg_32(RESET_BASE+0x8)


#define GPIO26_CTRL reg_32(IO_BANK0_BASE+0x0D4)
#define PADS_BANK26 reg_32(PADS_BANK0_BASE+0x6C)


int main()
{
    stdio_init_all();
    sleep_ms(2000);
    RESET &=~(1<<0);
    while(!(RESET_DONE&(1<<0)))
        {
        }
    PADS_BANK26 |=(1<<7);
    PADS_BANK26 &=~(1<<6);
    PADS_BANK26 &=~(3<<2);

    GPIO26_CTRL =31;


    CS&=~(7<<12);
    CS|=(1<<0); 
    //DIV=(12500<<8);
    FCS|=(1<<0);
    uint16_t ADC_value;
    CS|=(1<<3);
while(1)
{    
    while(!(FCS&(15<<16)))
        {
        }
    ADC_value = FIFO & (0x0FFF);
    printf("DIGITAL VALUE--->%u\n",ADC_value);
    //sleep_ms(100);
}
    

}



