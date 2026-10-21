#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/uart.h"

int main()
{
    uart_init(uart0, 115200);

    gpio_set_function(0, GPIO_FUNC_UART);
    gpio_set_function(1, GPIO_FUNC_UART);

    while (1)
    {
        uart_puts(uart0, "Hello UART\r\n");
        sleep_ms(1000);
    }
}