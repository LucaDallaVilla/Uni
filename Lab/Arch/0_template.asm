.globl _start

.data
    size:   .word  8                  # size of the array        
    array:  .dword 1,2,3,4,5,6,7,8    # array of long integers
    result: .word  -1                 # store the result
    
.text

_start:
la t0, size
lw t0, 0(t0)
la t1, array
la t2, result

addi t0, t0, -1

loop:
blez t0, end_loop_1
ld t3, 0(t1)
ld t4, 8(t1)
bgt t3, t4, end_loop_0
addi t0, t0, -1
addi t1, t1, 8
j loop

end_loop_1:
li t5, 1
sw t5, 0(t2)

end_loop_0:
li t5, 0
sw t5, 0(t2)