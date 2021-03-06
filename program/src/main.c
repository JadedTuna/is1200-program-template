#include <pic32mx.h>
#include <stdint.h>
#include <stddef.h>
#include "syscalls.h"

char text[] = "hello world!";

void simple_delay(int cycles) {
    for (; cycles > 0; cycles--) {
        int i;
        for (i = 6000; i; i--)
            ;
    }
}

void serial_write(const char *s) {
	PORTE = 0x66;
	kernel_syscall(0x04, (uint32_t)s, 0, 0);
	PORTE = 0xFC;
}

int main(void) {
	void *ptr = main;
    TRISE &= ~0xff;

    // PORTE debugging FTW
    PORTE = 0x0F;
    serial_write("Syscall from loaded ELF!");
    PORTE = 0xF0;

	simple_delay(500);
	PORTE = 0xFC;
	simple_delay(500);

	return 0;
}