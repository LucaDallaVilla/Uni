.globl _start

.text

_start:
	

print:

exit:
    	addi x17, x0, 10  # call number 10 = exit
    	ecall
