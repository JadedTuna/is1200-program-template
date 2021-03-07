# Very simple and dumbed down crt0
# All the relevant initialization was already done in the kernel,
# no need to mess with things here

.global _reset

.section .reset,"ax",@progbits
.set noreorder
.ent _reset
_reset:
	# No arguments to program
	addiu	$sp, $sp, -8
	sw		$ra, 4($sp)
	sw		$s8, 0($sp)
	addi	$s8, $sp, 0

	addi	$a0, $zero, 0
	addi	$a1, $zero, 0

	jal		main
	nop

	addi	$sp, $s8, 0
	lw		$s8, 0($sp)
	lw		$ra, 4($sp)

	# Return back
	jr		$ra
	nop

.end _reset
