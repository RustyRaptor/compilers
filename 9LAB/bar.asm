#                  PACKAGE foo 

.data	# Data section starts here, strings first 

_NL: .asciiz "\n" # NEWLINE STRING 

.align 2 # start all global variable aligned

y:	.word 7	 # global var initialized
Z:	.space 4	 # global var uninitialized
A:	.space 400	 # global var uninitialized
x:	.word 1	 # global var initialized


.text # start of text segment (code)

.globl main # Force MIPS to start at main label



main:		# MAIN METHOD LABEL

	subu $t0 $sp 8		 #set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address in offset 0
	sw $sp 4($t0)		 #Store the old stack pointer in offset 4
	move $sp $t0		 #set the stack pointer to the new value


	li $v0 0		 #return NULL zero (0)
	lw $ra ($sp) 		 #reset return address 
	lw $ra 4($sp)		 #reset stack pointer 
	li $v0, 10		 #Main function ends 
	syscall		 #MAIN FUNCTION EXIT 
