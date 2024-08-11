# x -> $s0
# y ->  $s1
# z -> #s2

addi $t0, $zero, 0x186a
sll $s0, $t0, 4

addi $t1, $zero, 0x30d4 
sll $s1, $t1, 4
add $s2, $s0, $s1


