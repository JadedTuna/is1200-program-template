#ifndef _PROG_USERLIB_H
#define _PROG_USERLIB_H

#include <stddef.h>
#include <stdint.h>

#define BTN_1 1
#define BTN_2 1 << 1
#define BTN_3 1 << 2
#define BTN_4 1 << 3

#define SWTCH_1 1
#define SWTCH_2 1 << 1
#define SWTCH_3 1 << 2
#define SWTCH_4 1 << 3

uint32_t kernel_syscall(uint32_t srvnum, uint32_t a0, uint32_t a1, uint32_t a2);
void serial_write(const char *s);
void serial_nwrite(const char *s, size_t size);
void serial_putc(char c);
char serial_getc(void);
size_t serial_readline(char *buffer, size_t size);
int serial_printf(const char *format, ...);
uint8_t io_buttons(void);
uint8_t io_switches(void);

#endif /* _PROG_USERLIB_H */
