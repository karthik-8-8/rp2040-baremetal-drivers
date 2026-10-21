#include <stdio.h>
#include <stdint.h>

#define RESET_BASE 0x4000C000UL
#define SPI0_BASE  0x4003C000UL
#define IO_BANK0_BASE 0x40014000UL

#define reg_32(addr)    (*(volatile uint32_t*)(addr))

#define RESET   reg_32(RESET_BASE+0x0)
#define RESET_DONE reg_32(RESET_BASE+0x8)

#define SSPCR0  reg_32(SPI0_BASE+0x000)
#define SSPCR1  reg_32(SPI0_BASE+0x004)
#define SSPDR  reg_32(SPI0_BASE+0x008)
#define SSPSR  reg_32(SPI0_BASE+0x00C)
#define SSPCPSR  reg_32(SPI0_BASE+0x010)

#define GPIO16_CTRL reg_32(IO_BANK0_BASE+0x084)
#define GPIO17_CTRL reg_32(IO_BANK0_BASE+0x08C)
#define GPIO18_CTRL reg_32(IO_BANK0_BASE+0x094)
#define GPIO19_CTRL reg_32(IO_BANK0_BASE+0x09C)


uint8_t spi_transfer(uint8_t data)
{
    // TNF = 1: TX FIFO has space
    while (!(SSPSR & (1u << 1)))
    {
    }

    SSPDR = data;

    // RNE = 1: RX FIFO is not empty
    while (!(SSPSR & (1u << 2)))
    {
    }

    return (uint8_t)SSPDR;
}

int main()
{
    RESET&=~(1<<16); 
    while(!(RESET_DONE & (1<<16)))
        {
        }
    GPIO16_CTRL=1;
    GPIO17_CTRL=1;
    GPIO18_CTRL=1;
    GPIO19_CTRL=1;
    
    SSPCR1 &=~(1<<1);
    
    SSPCR0 &= ~(1<<7);
    SSPCR0 &= ~(1<<6);

    SSPCR0 &= ~(15<<0);
    SSPCR0 |=(7<<0);

    SSPCR0 &=~(3<<4);
    SSPCR0 &= ~(0x0FFu<<8);

    SSPCPSR=2;

    SSPCR1 &=~(1u<<2);
    SSPCR1 |=(1u<<1);
    
    uint8_t received = spi_transfer('N');

    while(1)
    {
    }

}