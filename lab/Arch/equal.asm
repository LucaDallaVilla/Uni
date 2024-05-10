.globl _start

.data        
    array: .word 1,2,3,4,5,4,3,2,1
    size:  .word 9
        
.text

_start:
    # chiama palindrome
    la   a0, array
    la   a1, size
    lw   a1, 0(a1)
    jal  ra, palindrome
        
    #exit
    li   a7, 10
    ecall

equal:
	# load array[x]
	add t0, a0, zero
	slli a1, a1, 2
	add t0, t0, a1
	lw t1, 0(t0)
	
	# load array[y]
	add t0, a0, zero
	slli a2, a2, 2
	add t0, t0, a2
	lw t2, 0(t0)
	
	# check
	bne t1, t2, different
	addi a0, zero, 1
	jr ra
	different:
	addi a0, zero, 0
	jr ra
	
	
palindrome:
	addi sp, sp, -24
	sd ra, 0(sp)
	sd a0, 8(sp)
	sd a1, 16(sp)

    li t0, 0 # i
    addi t1, a1, -1 # j
    li t2, 1 # result
    
    while:
    	bge t0, t1, endwhile
		add a1, t0, zero
		add a2, t1, zero
    	jal ra, equal
    	and t2, t2, a0
    	addi t0, t0, 1
    	addi t1, t1, -1
    	j while
    endwhile:
		ld ra, 0(sp)
		ld a0, 8(sp)
		ld a1, 16(sp)
		addi sp, sp, 24
		add a0, t2, zero
		jr ra
    
    