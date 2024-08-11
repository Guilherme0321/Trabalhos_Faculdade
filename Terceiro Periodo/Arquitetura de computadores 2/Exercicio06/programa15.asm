# i -> $s0
# vet -> $s1
# len -> $s2
# soma -> $s3
.text
	lui $s1, 0x1001
	
	or $s0, $zero, $zero # i = 0
	ori $s2, $zero, 100 # len = 100
	
	writeArray:
		beq $s0, $s2, fimWriteArray # if i != len
			sll $t1, $s0, 2 # temp = i * 4
	 		add $t0, $s1, $t1 # t0 = vet + temp
	 		
	 		sll $t3, $s0, 1 # t3 = i * 2
	 		addi $t3, $t3, 1 # t3 += 1
	 		
	 		sw $t3, 0 ($t0) # vet[i] = t3
	 		
	 		addi $s0, $s0, 1 # i++
		j writeArray
		
	fimWriteArray:
		ori $s0, $zero, 0 # i = 0
		ori $t0, $zero, 0 # t0 = 0
		ori $t1, $zero, 0 # t1 = 0
		readArray:
			beq $s0, $s2, fim
				sll $t1, $s0, 2 # temp = i * 4
				add $t0, $s1, $t1 # t0 = vet + temp
				
				lw $t2, 0 ($t0) # t2 = vet[i]
				add $s3, $s3, $t2 # soma += t2
				
				addi $s0, $s0, 1 # i++
			j readArray
	fim:
		
		
	
	