# x -> $s0
.text
	lui $t0, 0x1001
	
	lw $s0, 0 ($t0)
	
	srl $t1, $s0, 31
	ori $t2, $zero, 0x0001
	
	bne $t1, $t2, fim
	negative:
		sub $s0, $zero, $s0
	fim: 
		sw $s0, 0 ($t0)
	 
.data
	a: .word 10