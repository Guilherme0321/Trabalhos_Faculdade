# $s0 -> x
# $s1 -> y
# $s2 -> z

ori $s0, $zero, 0x7fff
sll $s0, $s0, 16
ori $s0, $s0, 0xffff

ori $s1, $zero, 0x493e
sll $s1, $s1, 4

sll $t0, $s1, 2
sub $s2, $s0, $t0