.text
	lui $t0, 0x1001
	
	lw $s0, 0 ($t0)
	lw $s1, 4 ($t0)
	
	ori $t1, $zero, 0
	
	ori $t2, $zero, 0x0001
	
	loop:
	beq $t1, $s1, fim
		
		mult $s0, $t2
		
		mflo $t2
		
		addi $t1, $t1, 1
		j loop
	fim:
	
	sw $t2, 8 ($t0)
.data
	x: .word 3
	y: .word 2