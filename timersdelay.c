#include <stdio.h>
#include <stdint.h>

#define REG32(addr)     (*(volatile unsigned int *)(addr))

#define IO_BANK0_BASE   0x40014000
#define PADS_BANK0_BASE 0x4001C000
#define SIO_BASE        0xD0000000
#define TIMER_BASE      0x40054000

#define TIMERAWL     REG32(TIMER_BASE+0x28)
#define GPIO25_CTRL  REG32(IO_BANK0_BASE+0x0CC)
#define GPIO25_PAD   REG32(PADS_BANK0_BASE + 0x068)
#define GPIO_OE_SET  REG32(SIO_BASE + 0x024)

#define GPIO_OUT_SET REG32(SIO_BASE + 0x014)
#define GPIO_OUT_CLR REG32(SIO_BASE + 0x018)



void sleep_ms(uint32_t Tms)
{
  uint32_t start=TIMERAWL;
  while((TIMERAWL-start)<(Tms * 1000))
  {}
}

int main()
{
    GPIO25_CTRL=5;

    GPIO_OE_SET =(1<<25);

    while(1)
        {
            GPIO_OUT_SET =(1<<25);
            sleep_ms(500);
            GPIO_OUT_CLR =(1<<25);
            sleep_ms(500);

        }



}