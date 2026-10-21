#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"

#define CS_PIN 17

int main()
{
    spi_init(spi0, 1000 * 1000);      // 1 MHz

    gpio_set_function(16, GPIO_FUNC_SPI);
    gpio_set_function(18, GPIO_FUNC_SPI);
    gpio_set_function(19, GPIO_FUNC_SPI);

    gpio_init(CS_PIN);
    gpio_set_dir(CS_PIN, GPIO_OUT);
    gpio_put(CS_PIN, 1);

    uint8_t tx = 0xA5;
    uint8_t rx;

    while (1)
    {
        gpio_put(CS_PIN, 0);

        spi_write_read_blocking(spi0, &tx, &rx, 1);

        gpio_put(CS_PIN, 1);

        sleep_ms(1000);
    }
}//refer chatgpt spi pined chat 