# x -> $s0
# y -> $s1
# z -> $s2

addi $s0, $zero, 3
addi $s1, $zero, 4

add $t0, $s0, $s0 # 2x
add $t0, $t0, $t0 # 4x
add $t0, $t0, $t0 # 8x
add $t0, $t0, $t0 # 16x
sub $t0, $t0, $s0 # 16x - x = 15x


sll $t1, $s1, 6

add $t1, $t1, $s1
add $t1, $t1, $s1
add $t1, $t1, $s1


add $t2, $t0, $t1
sll $s2, $t2, 2