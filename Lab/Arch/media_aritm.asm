.globl _start

.data        
	v1: .word 1
	v2: .word 2
	v3: .word 3
	v4: .word 4
	result: .word 0
    
.text

_start:
	# Carica i valori nella memoria in registri
	lw  t0, v1
	lw  t1, v2
	lw  t2, v3
	lw  t3, v4
	
	# Calcola la somma dei valori
	add t4, zero, zero
	add t4, t0, t1
	add t4, t4, t2
	add t4, t4, t3
	
	srai t4, t4, 2
	
	# Salva il risultato nella memoria
	la t5, result
	sw t4, 0(t5)
	

exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
