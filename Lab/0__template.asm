.globl _start

.data 

.text

_start:
	addi t0, zero, 4
	addi t1, zero, 5
	addi t2, zero, 2
	
	addi t3, t0, 0
	bge t3, t1, else1
	add t3, zero, t1
else1:	
	bge t3, t2, else2
	add t3, zero, t2
else2:
    
print:
	addi a0 t3 0
	li a7 1
	ecall

exit:
    addi x17, x0, 10  # call number 10 = exit
    ecall
