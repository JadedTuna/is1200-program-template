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
    TRISE &= ~0xff;
    TRISFSET = 2;

    if (PORTF & 2)
        serial_write("Button pressed\r\n");
    else
        serial_write("Button not pressed\r\n");

    // PORTE debugging FTW
    PORTE = 0x0F;
    serial_write("Syscall from loaded ELF!\r\n");
    PORTE = 0xF0;

    serial_write(text);
    serial_write("\r\n");

    for (;;) {
        uint8_t state = 0;
        state = io_buttons();
        state |= io_switches() << 4;
        PORTE = state;
    }

    simple_delay(500);
    PORTE = 0xFC;
    simple_delay(500);

    return 0;
}