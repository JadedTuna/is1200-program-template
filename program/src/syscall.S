.global kernel_syscall
# FIXME: clean up this function
kernel_syscall:
	# disable $at
	.set noat

	# caller-save registers, and some others since this
	# is an ISR without shadow registers (most likely)
	addi	$sp, $sp, -72
	sw	$ra,  0($sp)
	sw	$at,  4($sp)

	sw	$v0,  8($sp)
	sw	$v1, 12($sp)

	sw	$a0, 16($sp)
	sw	$a1, 20($sp)
	sw	$a2, 24($sp)
	sw	$a3, 28($sp)

	sw	$t0, 32($sp)
	sw	$t1, 36($sp)
	sw	$t2, 40($sp)
	sw	$t3, 44($sp)
	sw	$t4, 48($sp)
	sw	$t5, 52($sp)
	sw	$t6, 56($sp)
	sw	$t7, 60($sp)
	sw	$t8, 64($sp)
	sw	$t9, 68($sp)

	syscall
	# This nop shouldn't be needed
	# But somehow, sometimes, it is
	# I don't know why. At this point I don't care
	nop

	lw	$t9, 68($sp)
	lw	$t8, 64($sp)
	lw	$t7, 60($sp)
	lw	$t6, 56($sp)
	lw	$t5, 52($sp)
	lw	$t4, 48($sp)
	lw	$t3, 44($sp)
	lw	$t2, 40($sp)
	lw	$t1, 36($sp)
	lw	$t0, 32($sp)

	lw	$a3, 28($sp)
	lw	$a2, 24($sp)
	lw	$a1, 20($sp)
	lw	$a0, 16($sp)

	lw	$v1, 12($sp)
	# Dirty, but should work for now
	# lw	$v0,  8($sp)

	lw	$at,  4($sp)
	lw	$ra,  0($sp)
	addi	$sp, $sp, 72

	# enable $at
	.set at
	
	jr	$ra
	nop
