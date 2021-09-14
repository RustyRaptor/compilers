

#	Package foo 

.data # start of the DATA section, strings first

_NL: .asciiz "\n "# New line
.align 2 # start all of global variable aligned

y:	.word 7		# define a global variable with initial value
Z:	.space 4		# define a global variable
A:	.space 400		# define a global variable
x:	.word 1		# define a global variable with initial value

.text
 
.globl main

 			
			
main:			#Start of Function 
	subu $t0  $sp 8		#set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address 
	sw $sp 4($t0)		 #Store the old stack pointer 
	move $sp $t0 		# set the stack pointer to the new value
			
			
			
	li $v0 0    		#  return  NULL zero (0) 
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	li $v0, 10		#Main function ends 
	syscall		#MAIN FUNCTION EXITS
