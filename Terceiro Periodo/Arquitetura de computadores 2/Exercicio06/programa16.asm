# x -> $s0
# y -> $s1
# z -> $s2

ori $s0, $zero, 0x186a
sll $s0, $s0, 8

ori $s1, $zero, 0x1388
sll $s1, $s1, 4

ori $s2, $zero, 0x61a8
sll $s2, $s2, 4

div $s0, $s2
mflo $t0
mult $s1, $t0

mflo $s3