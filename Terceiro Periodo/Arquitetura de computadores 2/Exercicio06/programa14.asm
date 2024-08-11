# x -> $s0
# result -> $s1
.text
	lui $t0, 0x1001
	lw $s0, 0 ($t0)
	
	andi $s1, $s0, 0x0001
		
	fim:
		sw $s1, 4 ($t0)
.data
	x: .word 11