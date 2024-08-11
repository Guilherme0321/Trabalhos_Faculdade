# x -> $s0

.text
	lui $t0, 0x1001
	lw $t0, 0 ($t0)
	lw $t0, 0 ($t0)
	lw $t0, 0 ($t0)
.data
	x: .word 0x10010004
	y: .word 0x10010008
	z: .word 15