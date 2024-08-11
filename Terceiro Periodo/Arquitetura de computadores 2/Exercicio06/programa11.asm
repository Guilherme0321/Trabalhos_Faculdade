# x -> $s0
# z -> $s1
# y -> $s2
.text
	lui $t0, 0x1001
	lw $s0, 0 ($t0)
	lw $s1, 4 ($t0)
	
	sub $t1, $s0, $s1
	
	ori $t2, $zero, 0x493E
	sll $t2, $t2, 4
	add $s2, $t1, $t2
	
	sw $s2, 8 ($t0)
.data
	x: .word 100000
	z: .word 200000
	y: .word 0 