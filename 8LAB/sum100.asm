 
#  this program calculates the sum of squares up to and including 100

# well it used to. Now it reads an integer from the user then calculates 
# the sum of squares up until that integer. 
.data
L1: .asciiz "Please enter value: "
str: .asciiz "The sum from 0 ... "
str1: .asciiz " is: "

.text  # directive that we are in the code segment

# Sets up the environment so we have something to work with. 
# Sets up the activation record
# creates 
main:
        # We need enough memory to keep track of the
        # Stack POinter, Return Address, Counting Variable i and sum variable s
        # so we need 4 words of memory which translates to 4 * 4 bytes = 16
        # Therefore we carve out 16 bytes from the stack to use for our program
        # EDIT: we changed it to 20 to accomodate the user input

        # a0 here is being user to temporarily store the stack pointer we want
        # so that we can store the stack pointer and RA
        subu $a0, $sp, 20 # We want 4 mem locations for main SP, RA, i , s

        # Store the valies of RA and the stack pointer in memory
        # So we can use them later if we need to change them
        sw $ra, 4($a0)  # we need to store the RA in the Activation record
        sw $sp, ($a0) # store SP

        # once we adjust the SP we can discard a0 and use the SP for our memory
        # access
        move $sp, $a0  # adjust SP

        # this variable is used to keep track of our count
        # Initialize the counting variable to 0 so we can count from 0 to 100
        sw $0, 8($sp)  # store 0 into memory -- counting variable 

        # this is the sum variable to put in the sum of the counting numbers
        # initialize the sum variable to 0 so we can add up the sum
        sw $0, 12($sp)  # store 0 into memory -- accumulating variable

        # prints the prompt string in L1
        li $v0, 4
        la $a0, L1
        syscall

        # Reads a user input integer
        li $v0, 5
        syscall

        # stores the user's integer into the memory at 16
        sw $v0, 16($sp)

# loops from t0 to 100
loop:
        # load the counting variable into register T6
        lw $t6, 8($sp)  #

        # Multiply the count by itself and store in another register t7
        mul $t7, $t6, $t6  #  i * i

        # Load the summation variable into register t8
        lw $t8, 12($sp)   #  s

        # add the squared count value to the sum register and store it in t9
        addu $t9, $t8, $t7  #  s + i*i

        # Update the sum variable with the new value in t9
        sw $t9, 12($sp)  #   s= s + i*i

        # We load the original counter value back into t6
        # this way we can inrement the original value and not the squared one
        lw $t6, 8($sp)    # i 

        # increment the value and store it in t0 
        addu $t0, $t6, 1  # i+1

        # store it back in the counter now it's incremented for next loop
        sw $t0, 8($sp)  #  i = i + 1

        # load the input number into a register
        lw $t2, 16($sp)

        # Branch to the loop if the counter is less or equal to 100 otherwise continue
        ble $t0, $t2, loop  #   keep doing it for 100 times
        nop   # 

# Prints out the result of calculation

        # load the string from the data segment that has the first part
        la $a0, str
        # v0 has to be 4 when you do a syscall to print for some reason? idk
        li $v0 4  #   print the string
        # This will print to the screen what's in a0
        syscall # 
        nop   # 
        
        # print out the number the user entered
        lw $a0, 16($sp)
        li $v0 1 #   Print the number
        syscall
        nop   # 


        # print out the "is" part of the string
        la $a0, str1
        li $v0 4  #   print the string
        syscall # 

         # Now load the result of the summing and print it 
        lw $a0, 12($sp)
        li $v0 1 #   Print the number
        syscall
        nop   # 
        
        # Set the return address and stack pointer back
        # This way we can return to where we were before calling main
        lw $ra, 4($sp)
        lw $sp , ($sp)  # put back Ra and SP
        
        # loading 10 into v0 will cause syscall to exit the main function.
        li $v0, 10
        syscall     #  exit for MAIN only
        


        