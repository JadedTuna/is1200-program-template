# Very simple and dumbed down crt0
# All the relevant initialization was already done in the kernel,
# no need to mess with things here

.global _reset

.section .reset,"ax",@progbits
.set noreorder
.ent _reset
_reset:
	# No arguments to program
	addi $s8, $ra, 0

	addi $a0, $zero, 0
	addi $a1, $zero, 0

	jal	main
	nop

	# Return back
	jr $s8
	nop

.end _reset
