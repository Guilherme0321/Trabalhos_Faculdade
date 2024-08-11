ori $8, $zero, 0x1234
sll $8, $8, 16
ori $8, $8, 0x5678

andi $12, $8, 0x00FF
srl $8, $8, 8
andi $11, $8, 0x00FF
srl $8, $8, 8
andi $10, $8, 0x00FF
srl $8, $8, 8
andi $9, $8, 0x00FF