.globl _start

.text

_start:
	addi t0, zero, 3 # a
	addi t1, zero 4 # b
	addi t2, zero, 0 # R
	addi t6, zero, 2 # 2
	
	
	addi t3, zero, 0 # i=0
loop1:	bge t3, t0, exit
		addi t4, zero, 0 # j=0
loop2:		bge t4, t1, endloop2
			addi t5, zero, 0
			mul t5, t2, t6
			add t2, t5, t3
			add t2, t2, t4
	
			addi t4, t4, 1 # j += 1
			j loop2

endloop2:
	addi t3, t3, 1 # i += 1
	j loop1

exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
