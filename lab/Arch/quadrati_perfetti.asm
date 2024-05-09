.globl _start

.text

_start:
	addi t0, x0, 1 #i
    	addi t1, x0, 5 #N
    	addi t2, x0, 0 #risultato
    	addi t3, x0, 0 #risultato moltiplica i*i
    
loop1:
	bgt t0, t1, exit
 	addi t3, x0, 0
    	mul t3, t0, t0
    	add t2, t2, t3
    	addi t0, t0, 1
    	j loop1

exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall