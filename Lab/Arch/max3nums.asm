.globl _start

.data        
	x: .word 1
	y: .word 2
	z: .word 3
	result: .word 0
    
.text

_start:
	lw t0, x
	lw t1, y
	lw t2, z
	add t3, zero, zero
	
	bge t0, t1, cond1
	bge t1, t2, cond2
	add t3, t3, t2
	j save
	
cond1:	
	bge t0, t2, cond3
	add t3, t3, t2
	j save
	
cond2:	
	add t3, t3, t1
	j save
	
cond3:	
	add t3, t3, t0
	j save
	
save:	
	la t4, result
	sw t3, 0(t4)
	
exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
