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


add $t1, $s1, $s1 # 2y
add $t1, $t1, $t1 # 4y
add $t1, $t1, $t1 # 8y
add $t1, $t1, $t1 # 16y
add $t1, $t1, $t1 # 32y
add $t1, $t1, $t1 # 64y

add $t1, $t1, $s1 # 64y + y
add $t1, $t1, $s1 # 64y + y
add $t1, $t1, $s1 # 64y + y


add $t2, $t0, $t1
add $t3, $t2, $t2
add $t3, $t3, $t2
add $s2, $t3, $t2