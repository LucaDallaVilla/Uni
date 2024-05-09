.globl _start

.data
    num1: .dword 5 # a
    num2: .dword 6 # b
    
.text

_start:
    # call MCD
    la    a0, num1
    la    a1, num2
    ld    a0, 0(a0) # a
    ld    a1, 0(a1) # b 
    jal   ra, mcm

	#print result
	li a7, 1
	ecall

    #exit
    li    a7, 10
    ecall

mcd:
	add t0, a0, zero
	add t1, a1, zero
	while:
		beq t0, t1, endwhile
		blt t0, t1, else
		sub t0, t0, t1
		j while
		else:
		sub t1, t1, t0
		j while
	endwhile:
		add a0, t0, zero
		jr ra
		
mcm:
    addi sp, sp, -8
	sw ra, 0(sp)
	mul t3, t0, t1 # a*b
	jal ra, mcd # salva MCD(a,b) in a0
	div t3, t3, a0 # (a*b)/MCD
	add a0, zero, t3 # salvo in a0 il risultato da ritornare
	lw ra, 0(sp)
	addi sp, sp, 8
	jr ra
		