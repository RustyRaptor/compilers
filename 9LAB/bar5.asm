#                  PACKAGE fibinaci 

.data	# Data section starts here, strings first 

_L0:	.asciiz	"in fib"
_L1:	.asciiz	"hello"
_NL: .asciiz "\n" # NEWLINE STRING 

.align 2 # start all global variable aligned

y:	.word 7	 # global var initialized
Z:	.space 4	 # global var uninitialized
A:	.space 400	 # global var uninitialized
x:	.word 1	 # global var initialized


.text # start of text segment (code)

.globl main # Force MIPS to start at main label



fib:		# MAIN METHOD LABEL

	subu $t0 $sp 44		 #set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address in offset 0
	sw $sp 4($t0)		 #Store the old stack pointer in offset 4
	move $sp $t0		 #set the stack pointer to the new value


	la $a0, _L0		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 16($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 0		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 16($sp)		 #get LHS from storage
	sle $a0, $a0, $a1		 #less than or eq to
	beq $a0 $0 _L2		 #Branch to first label if expression is 0
	j _L3		 #And the cow jumped over the else 🐄
_L2:			 #First Label for entering else
_L3:			 #Second Label for jumping over the else
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 20($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 1		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 20($sp)		 #get LHS from storage
	seq $a0, $a0, $a1		 #equal to
	beq $a0 $0 _L4		 #Branch to first label if expression is 0
	j _L5		 #And the cow jumped over the else 🐄
_L4:			 #First Label for entering else
_L5:			 #Second Label for jumping over the else
	li $v0 0		 #return NULL zero (0)
	lw $ra ($sp) 		 #reset return address 
	lw $ra 4($sp)		 #reset stack pointer 


main:		# MAIN METHOD LABEL

	subu $t0 $sp 32		 #set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address in offset 0
	sw $sp 4($t0)		 #Store the old stack pointer in offset 4
	move $sp $t0		 #set the stack pointer to the new value


	li $a0, 4		 #expr constant value
	sw $a0, 12($sp)		 #Store the argument value in the stack
	li $a0, 4		 #expr constant value
	lw $a0, 12($sp)		 #load the argument from the stack to a0, a1, a2, a3 respectively and as necessary
	sw $a0 16($sp)		 #store RHS of assign temporarily
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a1, 16($sp)		 #load back RHS into $a1
	sw $a1, ($a0)		 #Store assign value
			 #EMIT PRINT INT HERE
	li $a0, 5		 #expr constant value
	li $v0 1		 #set up write call
	syscall		 #print a number
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	la $a0, _L1		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


			 #EMIT PRINT INT HERE
	li $a0, 28		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	li $v0 1		 #set up write call
	syscall		 #print a number
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	li $v0 0		 #return NULL zero (0)
	lw $ra ($sp) 		 #reset return address 
	lw $ra 4($sp)		 #reset stack pointer 
	li $v0, 10		 #Main function ends 
	syscall		 #MAIN FUNCTION EXIT 
