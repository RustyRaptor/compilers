

#	Package foo 

.data # start of the DATA section, strings first

_L0:	.asciiz "hello"		# global string
_NL: .asciiz "\n "# New line
.align 2 # start all of global variable aligned

y:	.word 7		# define a global variable with initial value
Z:	.space 4		# define a global variable
A:	.space 400		# define a global variable
x:	.word 1		# define a global variable with initial value

.text
 
.globl main

 			
			
main:			#Start of Function 
	subu $t0  $sp 20		#set up $t0 to be the new spot for SP
	sw $ra ($t0)		 #Store the return address 
	sw $sp 4($t0)		 #Store the old stack pointer 
	move $sp $t0 		# set the stack pointer to the new value
			
			
			
	li $a0 5		# expresion a number
			#print an INT
	li $v0 1		#set up write call
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
			
			
	la $a0 _L0		#get string address for print
	li $v0, 4		#print a string
	syscall		
			
	li $v0, 4		#print NEWLINE
	la $a0, _NL		#print NEWLINE string location
	syscall		
			
	li $v0 0    		#  return  NULL zero (0) 
	lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	li $v0, 10		#Main function ends 
	syscall		#MAIN FUNCTION EXITS
