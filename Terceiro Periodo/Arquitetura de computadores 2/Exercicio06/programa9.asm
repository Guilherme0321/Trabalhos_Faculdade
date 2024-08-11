
.text
	#ori $t0, $zero, 0x1001
	#sll $t0, $t0, 16 
	
	lui $t0, 0x1001
	
	lw $s0, 0 ($t0)
	lw $s1, 4 ($t0)
	lw $s2, 8 ($t0)
	lw $s3, 12 ($t0)
	
	add $t1, $s0, $s1
	add $t2, $s2, $s3
	add $s4, $t1, $t2
	
	sw $s4, 16 ($t0) 
	
	
.data
	x1: .word 15 # $s0
	x2: .word 25 # $s1
	x3: .word 13 # $s2
	x4: .word 17 # $s3
	Soma: .word -1 #s4