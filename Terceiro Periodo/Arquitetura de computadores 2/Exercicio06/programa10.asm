.text
	lui $t0, 0x1001
	lw $s0, 0 ($t0) # s0 = 5
	lw $s1, 4 ($t0) # s1 = 7
	
	sll $t1, $s0, 7 # t1 = s0 x 2^7
	sub $t1, $t1, $s0 # ti -= s0
	
	sll $t2, $s1, 6 # t2 = s1 x 2^6
	add $t2, $t2, $s1 # t2 += s1
	
	sub $t3, $t1, $t2
	addi $s2, $t3, 1
	
	sw $s2, 8 ($t0)
	
	
# 127x - 65z +1
.data
	x: .word 5 # $s0
	z: .word 7 # $s1
	y: .word 0 # $s2