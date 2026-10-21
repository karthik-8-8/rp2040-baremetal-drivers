#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    sleep_ms(2000);

    unsigned int count = 0;

    while(1) {
        printf("Count is: %d\n", count);
        count++;
        sleep_ms(1000);
    }
}