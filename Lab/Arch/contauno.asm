.globl _start

.text

_start:
	li t0, 127 #input
	li t1, 1 #mask
	li t2, 0 #result of mask operation
	li t3, 32 #n bits
	li t4, 0 #var del ciclo
	li t5, 0 #contatore 1
	
loop:	
	bge t4, t3, exit
	add t2, zero, zero # azzero risultato della mask
	and t2, t0, t1 # faccio la mask tra t0 e t1
	slli t1, t1, 1 # slitto a sinistra la mask
	addi t4, t4, 1 # i += 1
	bnez t2, if # se t2 != 0, t5 += 1
	j loop

if:	
	addi t5, t5, 1 # t5 += 1
	j loop
	
exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
