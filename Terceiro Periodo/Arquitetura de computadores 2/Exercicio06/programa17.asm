.text
	lui $t0, 0x1001
	
	lw $s0, 0 ($t0)
	lw $s1, 4 ($t0)
	
	ori $t1, $zero, 0
	
	loop:
	beq $t1, $s1, fim
		add $s3, $s3, $s0
		addi $t1, $t1, 1
		j loop
	fim:
	
	sw $s3, 8 ($t0)
.data
	x: .word 10
	y: .word 20