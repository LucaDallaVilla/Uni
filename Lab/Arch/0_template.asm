.globl _start

.data
size:   .word 2
array:  .word -12, 2
result: .word -1
.text

_start:
la t0, size
lw t0, 0(t0)
la t1, array
li t2, 0 # risultato

loop:
ble t0, zero, exit
lw t3, 0(t1)
andi t3, t3, 1
beqz t3, pari
addi t2, t2, 1
pari:
addi t1, t1, 4
addi t0, t0, -1
j loop

exit:
la t4, result
sw t2, 0(t4)
addi a7, zero, 10
ecall
