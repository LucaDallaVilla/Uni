.globl _start

.data
    size:  .word 8
    array: .word 1,5,3,7,2,6,4,8
    
.text

_start:
    # chiama invert
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)        
    jal  ra, invert
    
    #exit
    li   a7, 10
    ecall

invert:
    # copia parametri invert
    add t0, zero, a0
    add t1, zero, a1
    add t2, zero, ra
    
    srai t3, t1, 1
    li t4, 0
    for:
        bge t4, t3, endfor
        
        # size-i-1
        sub t5, zero, t4
        add t5, t5, t1
        addi t5, t5, -1
        
        # calling swap()
        add a0, zero, a0
        add a1, zero, t4
        add a2, zero, t1
        jal ra, swap
        
        addi t4, t4, 1
        j for
        
    endfor:
    	add a0, zero t0
    	add a1, zero, t1
    	add ra, zero, t2
    	jr ra
    
    
swap:
    slli a1, a1, 2
    slli a2, a2, 2
    
    # int temp = array[x]
    add t0, zero, a0
    
    add t0, t0, a1
    lw t1, 0(t0) # temp
    
    # array[x] = array[y]
    add t0, zero, a0
    add t0, t0, a2
    lw t2, 0(t0)
    add t0, zero, a0
    add t0, t0, a1
    sw t2, 0(t0)
    
    # array[y] = temp
    add t0, zero, a0
    add t0, t0, a2
    sw t1, 0(t0)
    
    jr ra