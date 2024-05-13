.globl _start
.data
      buffer: .string  "BADPass4"
.text
_start:
    # call passrules
    la   a0, buffer
    jal  ra, passrules

    #exit
    li   a7, 10
    ecall
    

contains:
	while:
		lb t0, 0(a0) # str[i]
		beqz t0, endwhile
		blt t0, a1, next
		bgt t0, a2, next
		addi a0, zero, 1
		jr ra
	next:
		addi a0, a0, 1
		j while
	endwhile:
		addi a0, zero, 0
		jr ra
		
		
passrules:
    addi sp, sp, -4
    sw ra, 0(sp)
    add s0, a0, zero
    
    add a0, s0, zero
    li a1, 65
    li a2, 90
    jal ra, contains
    add s1, a0, zero
    
    add a0, s0, zero
    li a1, 48
    li a2, 57
    jal ra, contains
    add s2, a0, zero
    
    and a0, s1, s2
    lw ra, 0(sp)
    addi sp, sp, 4
    
    jr ra
	
	
	
