.globl _start

.data
    src: .string "prova test"
	dst: .string ""
	
.text

_start:
    la a0, src
    la a1, dst
    jal ra, strcpy

	# prints sdt string
	add a0, zero, a1
	li a7, 4
	ecall	

    #exit
    li a7, 10
    ecall

strcpy:
	add t0, a0, zero
	add t1, a1, zero
	loop:
		lb t2, 0(t0) # src[i]
		beq t2, zero, endloop
		sb t2, 0(t1) # dst[i] = src[i]
		addi t0, t0, 1
		addi t1, t1, 1
		j loop
	endloop:
		sb zero, 0(t1) # dst[-1] = "\0"
		jr ra