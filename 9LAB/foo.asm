#                  PACKAGE foo 

.data	# Data section starts here, strings first 

_NL: .asciiz "\n" # NEWLINE STRING 

.align 2 # start all global variable aligned



.text # start of text segment (code)

.globl main # Force MIPS to start at main label



main:		# MAIN METHOD LABEL

