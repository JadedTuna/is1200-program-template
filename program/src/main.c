#include "userlib.h"

#include <pic32mx.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
FILE *const stdout = 0; // FIXME: this really shouldn't be needed

char text[] = "hello world!";

void simple_delay(int cycles) {
    for (; cycles > 0; cycles--) {
        int i;
        for (i = 6000; i; i--)
            ;
    }
}

int main(void) {
    char buf[5] = {0};
    serial_write("Entering user program\r\n");
    for (;;) {
        uint8_t state;
        state = io_buttons();
        state |= io_switches() << 4;
        PORTE = state;

        if (state == 0xFF)
            break;
    }
    serial_write("Exiting user program\r\n");

    return 0;
}