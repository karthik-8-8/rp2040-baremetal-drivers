#include <stdio.h>
#include <stdint.h>

#define reg_32(addr)    *(volatile uint32_t*)(addr)

#define  IO_BANK0_BASE 0x40014000UL
#define  PWM_BASE      0x40050000UL
#define TIMER_BASE      0x40054000

#define TIMERAWL     reg_32(TIMER_BASE+0x28)


#define GPIO0_CTRL  reg_32(IO_BANK0_BASE+0x004)

#define CH0_CSR reg_32(PWM_BASE+0x00)
#define CH0_DIV reg_32(PWM_BASE+0x04)
#define CH0_CTR reg_32(PWM_BASE+0x08)
#define CH0_CC reg_32(PWM_BASE+0x0C)
#define CH0_TOP reg_32(PWM_BASE+0x10)

void delay_ms(uint32_t Tms)
{
  uint32_t start=TIMERAWL;
  while((TIMERAWL-start)<(Tms * 1000))
  {}
}
int main()
{
    GPIO0_CTRL=4;

    CH0_DIV=(125<<4);
    CH0_TOP=999;
    CH0_CC=0;
    CH0_CSR |=(1<<0);
while (1)
{
    // Fade up
    for (int i = 0; i <= 999; i++)
    {
        CH0_CC =(CH0_CC & 0xFFFF0000) | i;
        delay_ms(2);
    }
    // Fade down
    for (int i = 999; i >= 0; i--)
    {
        CH0_CC =(CH0_CC & 0xFFFF0000) | i;
        delay_ms(2);
    }
}


}


