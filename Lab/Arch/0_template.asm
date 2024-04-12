.globl _start

.text

.data
	str: .string "THis is the source string."
	
_start:
	li t1, 0 # result
	jal strlen
	add t1, t1, a0
	
	
strlen:
	li t2, 0 # i
loop:	
	li t3, 0 # str[i]
	lw t3, i(str)
	addi t2, t2, 1
	bne t3, zero, loop
	add a0, zero, t2
	jr ra	

print:
	
	
exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
