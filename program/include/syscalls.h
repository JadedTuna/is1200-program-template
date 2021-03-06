#ifndef _PROG_SYSCALLS_H
#define _PROG_SYSCALLS_H

uint32_t kernel_syscall(uint32_t srvnum, uint32_t a0, uint32_t a1, uint32_t a2);
void serial_write(const char *s);

#endif /* _PROG_SYSCALLS_H */