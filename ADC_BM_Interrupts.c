
//just the model copied from gpt 



#include <stdint.h>
#include <stdio.h>
#include "pico/stdlib.h"

#define reg_32(addr)    (*(volatile uint32_t *)(addr))

#define ADC_BASE        0x4004C000UL
#define RESET_BASE      0x4000C000UL
#define IO_BANK0_BASE   0x40014000UL
#define PADS_BANK0_BASE 0x4001C000UL
#define PPB_BASE        0xE0000000UL

#define CS      reg_32(ADC_BASE+0x00)
#define RESULT  reg_32(ADC_BASE+0x04)
#define FCS     reg_32(ADC_BASE+0x08)
#define FIFO    reg_32(ADC_BASE+0x0C)

/* ADC Interrupt Registers */
#define INTR    reg_32(ADC_BASE+0x14)
#define INTE    reg_32(ADC_BASE+0x18)
#define INTS    reg_32(ADC_BASE+0x20)

#define RESET       reg_32(RESET_BASE+0x00)
#define RESET_DONE  reg_32(RESET_BASE+0x08)

#define GPIO26_CTRL reg_32(IO_BANK0_BASE+0x0D4)
#define PADS_BANK26 reg_32(PADS_BANK0_BASE+0x6C)

#define NVIC_ISER   reg_32(PPB_BASE+0xE100)

volatile uint16_t ADC_value;

void isr_adc(void)
{
    if (INTS & (1<<0))
    {
        ADC_value = FIFO & 0x0FFF;

        /* Clear interrupt flag */
        INTR = (1<<0);
    }
}

int main()
{
    stdio_init_all();
    sleep_ms(2000);

    RESET &= ~(1<<0);
    while(!(RESET_DONE & (1<<0)));

    PADS_BANK26 |= (1<<7);
    PADS_BANK26 &= ~(1<<6);
    PADS_BANK26 &= ~(3<<2);

    GPIO26_CTRL = 31;

    CS &= ~(7<<12);
    CS |= (1<<0);

    FCS |= (1<<0);      // FIFO Enable

    /* Interrupt when FIFO has 1 sample */
    FCS |= (1<<24);     // Example threshold (concept)

    /* Enable ADC Interrupt */
    INTE |= (1<<0);

    /* Enable ADC IRQ in NVIC */
    NVIC_ISER |= (1<<ADC_IRQ_NUMBER);

    /* Continuous conversion */
    CS |= (1<<3);

    while(1)
    {
        printf("%u\n", ADC_value);

        sleep_ms(100);
    }
}