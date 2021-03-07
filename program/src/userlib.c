#include "userlib.h"

#include "syscalls.h"

#include <stdio.h>
#include <string.h>

/**
 * Blocking serial write for NULL-terminated strings.
 *
 * @param s String to write.
 */
void serial_write(const char *s) { serial_nwrite(s, strlen(s)); }

/**
 * Blocking serial write.
 *
 * @param s Data buffer.
 * @param size Number of bytes to write.
 */
void serial_nwrite(const char *s, size_t size) {
    kernel_syscall(SYSCALL_SERIAL_NWRITE, (uint32_t)s, size, 0);
}

uint8_t io_buttons(void) { return kernel_syscall(SYSCALL_BTN_STATES, 0, 0, 0); }

uint8_t io_switches(void) { return kernel_syscall(SYSCALL_SWTCH_STATES, 0, 0, 0); }

/**
 * Blocking serial printf.
 *
 * @param format Format string.
 * @param ... Arguments.
 * @return Number of bytes written.
 */
int serial_printf(const char *format, ...) {
    char buffer[4096] = { 0 };
    va_list ap;
    int rv;

    va_start(ap, format);
    rv = vsnprintf(buffer, ~(size_t)0, format, ap);
    va_end(ap);
    serial_write(buffer);

    return rv;
}