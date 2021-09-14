

#	Package fibinaci 

.data # start of the DATA section, strings first

_L0:	.asciiz "in fib"		# global string
_L1:	.asciiz "hello"		# global string
_NL: .asciiz "\n "# New line
.align 2 # start all of global variable aligned

y:	.word 7		# define a global variable with initial value
Z:	.space 4		# define a global variable
A:	.space 400		# define a global variable
x:	.word 1		# define a global variable with initial value

.text
 
.globl main

 			
			
fib:			#Start of Function 
	subu $t0  $sp 44		#set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address 
	sw $sp 4($t0)		 #Store the old stack pointer 
	move $sp $t0 		# set the stack pointer to the new value
			
	sw $a0 8($sp)		#copy function register to formal
			
			
			
	la $a0 _L0		#get string address for print
	li $v0, 4		#print a string
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a0 ($a0)		#expression is identifier
	sw $a0  16($sp)		#store LHS of expression in memory
	li $a0 0		# expresion a number
	move $a1, $a0		#right hand side needs to be a1
	lw $a0  16($sp)		#fetch LHS of expression from memory
	add $a1 ,$a1, 1		#EXPR LE add one to do compare
	slt $a0 ,$a0, $a1		#EXPR LE
	sw $a0  16($sp)		#store RHS of expression in memory
	beq $a0 $0 _L2		#IF branch to else part
	li $a0 0		# expresion a number
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	jr $ra       		# return to our caller
	j _L3		#IF S1 end
_L2:	 			# ELSE target
_L3:	 			# End of IF 
			
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a0 ($a0)		#expression is identifier
	sw $a0  20($sp)		#store LHS of expression in memory
	li $a0 1		# expresion a number
	move $a1, $a0		#right hand side needs to be a1
	lw $a0  20($sp)		#fetch LHS of expression from memory
	slt $t2 ,$a0, $a1		#EXPR EQUAL
	slt $t3 ,$a1, $a0		#EXPR EQUAL
	nor $a0 ,$t2, $t3		#EXPR EQUAL
	andi $a0 , 1		#EXPR EQUAL
	sw $a0  20($sp)		#store RHS of expression in memory
	beq $a0 $0 _L4		#IF branch to else part
	li $a0 1		# expresion a number
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	jr $ra       		# return to our caller
	j _L5		#IF S1 end
_L4:	 			# ELSE target
_L5:	 			# End of IF 
			
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a0 ($a0)		#expression is identifier
	sw $a0  24($sp)		#store LHS of expression in memory
	li $a0 1		# expresion a number
	move $a1, $a0		#right hand side needs to be a1
	lw $a0  24($sp)		#fetch LHS of expression from memory
	sub $a0, $a0, $a1		#EXPR SUB
	sw $a0  24($sp)		#store RHS of expression in memory
	sw $a0 28($sp)		# stor arg value in our runtime stack
			#set up the A0 - A3 registers to call function
	lw $a0 28($sp)		# load parameter value from stack into hand shake register 
			# about to call a function, set up each parameter in the new activation record
	jal fib		#jump and link to function
	sw $a0  40($sp)		#store LHS of expression in memory
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a0 ($a0)		#expression is identifier
	sw $a0  32($sp)		#store LHS of expression in memory
	li $a0 2		# expresion a number
	move $a1, $a0		#right hand side needs to be a1
	lw $a0  32($sp)		#fetch LHS of expression from memory
	sub $a0, $a0, $a1		#EXPR SUB
	sw $a0  32($sp)		#store RHS of expression in memory
	sw $a0 36($sp)		# stor arg value in our runtime stack
			#set up the A0 - A3 registers to call function
	lw $a0 36($sp)		# load parameter value from stack into hand shake register 
			# about to call a function, set up each parameter in the new activation record
	jal fib		#jump and link to function
	move $a1, $a0		#right hand side needs to be a1
	lw $a0  40($sp)		#fetch LHS of expression from memory
	add $a0, $a0, $a1		#EXPR ADD
	sw $a0  40($sp)		#store RHS of expression in memory
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	jr $ra       		# return to our caller
	li $v0 0    		#  return  NULL zero (0) 
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	jr $ra       		# return to our caller
			
			
main:			#Start of Function 
	subu $t0  $sp 32		#set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address 
	sw $sp 4($t0)		 #Store the old stack pointer 
	move $sp $t0 		# set the stack pointer to the new value
			
			
			
	li $a0 4		# expresion a number
	sw $a0 12($sp)		# stor arg value in our runtime stack
			#set up the A0 - A3 registers to call function
	lw $a0 12($sp)		# load parameter value from stack into hand shake register 
			# about to call a function, set up each parameter in the new activation record
	jal fib		#jump and link to function
	sw $a0, 16($sp)		#store RHS value in memory
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a1, 16($sp)		# Get RHS stored value
	sw $a1 ($a0)		# ASSIGN final store 
			
	li $a0 5		# expresion a number
			#print an INT
	li $v0 1		#set up write call
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
			
			
	la $a0 _L1		#get string address for print
	li $v0, 4		#print a string
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
	li $a0 8		#get Identifier offset
	 add $a0,$a0,$sp		# we have direct reference to memory 
	lw $a0 ($a0)		#expression is identifier
			#print an INT
	li $v0 1		#set up write call
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
			
	li $v0 0    		#  return  NULL zero (0) 
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	li $v0, 10		#Main function ends 
	syscall		#MAIN FUNCTION EXITS
