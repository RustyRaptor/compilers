#                  PACKAGE foo 

.data	# Data section starts here, strings first 

_L0:	.asciiz	"x is 5"
_L1:	.asciiz	"x is not 5"
_L2:	.asciiz	"hello, what is the meaning of life: "
_L3:	.asciiz	"The meaning of life is: "
_NL: .asciiz "\n" # NEWLINE STRING 

.align 2 # start all global variable aligned

y:	.word 7	 # global var initialized
Z:	.space 4	 # global var uninitialized
A:	.space 400	 # global var uninitialized
x:	.word 1	 # global var initialized


.text # start of text segment (code)

.globl main # Force MIPS to start at main label



dothis:		# MAIN METHOD LABEL

	subu $t0 $sp 24		 #set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address in offset 0
	sw $sp 4($t0)		 #Store the old stack pointer in offset 4
	move $sp $t0		 #set the stack pointer to the new value


	li $a0, 12		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 16($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 5		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 16($sp)		 #get LHS from storage
	seq $a0, $a0, $a1		 #equal to
	beq $a0 $0 _L4		 #Branch to first label if expression is 0
	la $a0, _L0		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	j _L5		 #And the cow jumped over the else 🐄
_L4:			 #First Label for entering else
	la $a0, _L1		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


_L5:			 #Second Label for jumping over the else
	li $v0 0		 #return NULL zero (0)
	lw $ra ($sp) 		 #reset return address 
	lw $ra 4($sp)		 #reset stack pointer 


main:		# MAIN METHOD LABEL

	subu $t0 $sp 60		 #set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address in offset 0
	sw $sp 4($t0)		 #Store the old stack pointer in offset 4
	move $sp $t0		 #set the stack pointer to the new value


	la $a0, _L2		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	li $v0, 5		 #read int from user
	syscall		 #to read a number
	move $a0, $v0		 #Move the number into $a0
	sw $a0 16($sp)		 #store RHS of assign temporarily
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a1, 16($sp)		 #load back RHS into $a1
	sw $a1, ($a0)		 #Store assign value
	la $a0, _L3		 #expr constant is a string
	li $v0 4		 #set up write call
	syscall		 #print a string
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


			 #EMIT PRINT INT HERE
	li $a0, 24		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	li $v0 1		 #set up write call
	syscall		 #print a number
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	li $a0, 0		 #expr constant value
	sw $a0 28($sp)		 #store RHS of assign temporarily
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a1, 28($sp)		 #load back RHS into $a1
	sw $a1, ($a0)		 #Store assign value
_L6:			 #First label to restart while loop's block
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 32($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 0		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 32($sp)		 #get LHS from storage
	sgt $a0, $a0, $a1		 #greater than
	beq $a0 $0 _L7		 #Branch to second label if expression is 0
			 #EMIT PRINT INT HERE
	li $a0, 36		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	li $v0 1		 #set up write call
	syscall		 #print a number
	li $v0, 4		 #print NEWLINE
	la $a0, _NL		 #print NEWLINE string location
	syscall		 #call print a NEWLINE


	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 40($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 1		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 40($sp)		 #get LHS from storage
	sub $a0, $a0, $a1		 #subact
	sw $a0 44($sp)		 #store RHS of assign temporarily
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a1, 44($sp)		 #load back RHS into $a1
	sw $a1, ($a0)		 #Store assign value
	j _L6		 #And the little dog laughed to see such loops
_L7:			 #Second label to jump to from the exit condition
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a0 ($a0)		 #load from the memory address a value
	sw $a0, 36($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 1		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 36($sp)		 #get LHS from storage
	add $a0, $a0, $a1		 #add
	sw $a0, 40($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 2		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 40($sp)		 #get LHS from storage
	sub $a0, $a0, $a1		 #subact
	sw $a0, 44($sp)		 #store $a0 (LHS) temporarily so we can eval RHS
	li $a0, 5		 #expr constant value
	move $a1, $a0		 #move RHS to $a1
	lw $a0, 44($sp)		 #get LHS from storage
	add $a0, $a0, $a1		 #add
	sw $a0 48($sp)		 #store RHS of assign temporarily
	li $a0, 8		 #offset for variable address
	add $a0, $a0, $sp		 #exact location for stack variable
	lw $a1, 48($sp)		 #load back RHS into $a1
	sw $a1, ($a0)		 #Store assign value
	li $a0, 5		 #expr constant value
	sw $a0, 52($sp)		 #Store the argument value in the stack
	li $a0, 1		 #expr constant value
	sw $a0, 56($sp)		 #Store the argument value in the stack
	li $a0, 5		 #expr constant value
	lw $a0, 52($sp)		 #load the argument from the stack to a0, a1, a2, a3 respectively and as necessary
	li $a0, 1		 #expr constant value
	lw $a1, 56($sp)		 #load the argument from the stack to a0, a1, a2, a3 respectively and as necessary
	li $v0 0		 #return NULL zero (0)
	lw $ra ($sp) 		 #reset return address 
	lw $ra 4($sp)		 #reset stack pointer 
	li $v0, 10		 #Main function ends 
	syscall		 #MAIN FUNCTION EXIT 
