#include <stdint.h>
#include <stdio.h>

#define UART0_BASE 0x40034000UL
#define RESET_CONTROLLER 0x4000c000UL
#define IO_BANK0_BASE   0x40014000UL

#define UARTDR  (*(volatile uint32_t *) (UART0_BASE+0x000))
#define UARTFR  (*(volatile uint32_t *) (UART0_BASE+0x018))
#define UARTIBRD  (*(volatile uint32_t *) (UART0_BASE+0x024))
#define UARTFBRD  (*(volatile uint32_t *) (UART0_BASE+0x028))
#define UARTLCR_H  (*(volatile uint32_t *) (UART0_BASE+0x02C))
#define UARTCR  (*(volatile uint32_t *) (UART0_BASE+0x030))

#define RESET (*(volatile uint32_t *) (RESET_CONTROLLER+0x0))
#define RESET_DONE (*(volatile uint32_t *) (RESET_CONTROLLER+0x8))

#define GPIO0_CTRL  (*(volatile uint32_t *) (IO_BANK0_BASE+0x004))
#define GPIO1_CTRL  (*(volatile uint32_t *) (IO_BANK0_BASE+0x00C))

void uart_putc(char c)
{
    while(UARTFR&(1<<5))
        {
        }

    UARTDR=c;
}

void uart_puts(const char *str)
{

    while(*(str)!='\0')
        {
        uart_putc(*(str++));
        }
}

char uart_getc()
{
    while(UARTFR&(1<<4))
    {
    }
    return UARTDR;
   
}


int main()
{
    RESET&=~(1<<22);
    while(!((1<<22)&RESET_DONE))
        {
        }

    GPIO0_CTRL&=~(0xF);
    GPIO0_CTRL|=(0x2);
    GPIO1_CTRL&=~(0xF);
    GPIO1_CTRL|=(0x2);

    UARTCR=0;

    UARTIBRD=26;
    UARTFBRD=3;

    UARTLCR_H = (3 << 5) | (1 << 4);

    UARTCR=(3<<8)|(1<<0);

    uart_putc('A');
    uart_puts("Hello RP2040!");
    
    while(1)
        {
            char c = uart_getc();
            uart_putc(c);
        }

}