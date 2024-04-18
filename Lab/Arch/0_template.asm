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
lw t2, 0(t1) # valore massimo trovato
li t3, 1 # i

loop:
bge t3, t0, exit
lw t4, 0(t1)
bgt t4, t2, sum
a:
addi t3, t3, 1
addi t1, t1, 4
j loop

sum:
add t2, zero, t4
j a
    
exit:
la t5, result
sw t2, 0(t5)
addi a7, zero, 10
ecall