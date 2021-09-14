

//  Subprograms which output MIPS code.
//
//   Shaun Cooper Spring 2015
/// Updated Spring 2017 to utilize the data segement portion of MIPS instead of
/// advancing the Stack and Global pointers to accomodate global variables.
//  Shaun Cooper December 2020 updated for DECAF format
/*
Ziad Arafat - Apr 26 2021
Lab 9
Apr 26 2021:
        - Implemented emit_all()
                - emit package name comment
                - emit data section  comments
                - emit globals comments
                - emit text (code) section comments
May 3 2021:
        - Implemented emit_strings()
        - Implemented emit_global()
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "emit.h"

/* Function prototypes for functions only used internally */

// PRE: An integer indicating number of newlines
// POST: Emit x number of newlines to the asm
void emit_nl(int x);

// PRE: ptr to ASTnode
// POST: all MIPS code in fp file relating to the decaf AST
void emit_mips(ASTnode *p); // emits the mips code in text section

// PRE: ptr to ASTnode
// POST: MIPS code needed for a method call to work.
void emit_method_call(ASTnode *p); // handles emiting method calls

// PRE: ptr to ASTnode
// POST: inline MIPS code that generates the print
void emit_print_string(ASTnode *p); // handles the print_string methods

// PRE: ptr to METHOD_CALL that is named print_int
// POST: inline MIPS code that generates the print
void emit_print_int(ASTnode *p); // handles the print_int methods

// PRE: ptr to method call read_int
// POST: $a0 will be the value read
void emit_read_int(ASTnode *p); // handles the print_int methods

// PRE: ptr to an expression
// POST: MIPS code such that $a0 has the value of the expr in p
void emit_expr(ASTnode *p);

// PRE: ptr to an identifier. (LVALUE or RVALUE)
// POST: $a0 is thje memory address of the identifier
void emit_ident(ASTnode *p);

// PRE: PTR to an enture AST
// POST: output to ASMS file that prints labels and the strings associated
//      Each ASTnode that is a string will have p->label updated
//      be that generated label
//      We need that assignment later so that we can access the string
//      via the label
void emit_strings(ASTnode *p);

// PRE: ptr to an ASTnode
// POST: output to the data section for those nodes
//      as A_VARDEC with level 0
//      produce different output for assigned values to scalars.
//
void emit_global(ASTnode *p); // emits the global/static variables

// PRE: P is ptr to A_ASSIGN
// POST: MIPS code in fp that assigns a value
void emit_assign(ASTnode *p);

// PRE: ptr to an ASTnode for A_IF
// POST: emit the MIPS code needed for an if/else statement to fp
void emit_if(ASTnode *p);

// PRE: ptr to an A_WHILE ASTnode
// POST: emit the MIPS assembly needed to do a while loop to fp
void emit_while(ASTnode *p);

// PRE: ptr to an ASTnode of an A_VAR_LVALUE or A_VAR_RVALUE of an array
// POST: emit the proper evaluation of the array index to MIPS code in fp
void emit_array(ASTnode *p);

// PRE: ptr to an ASTnode of type A_RETURN
// POST: emit mips code that will return the current function
void emit_return(ASTnode *p);

FILE *fp = NULL; // Pointer to the assembly file we want to emit to

static int GLABEL = 0; // global label counter

// PRE: no input
// POST: char i* to a one up string of the form "_L%d"
char *GEN_LABEL()
{
	char label_num[100];

	// sprintf() is kinda like fprintf but instead of directing
	// to a file it's going to a string
	// Now we insert GLABEL using the formatter.
	sprintf(label_num, "_L%d", GLABEL);

	// increment GLABEL for next time we get called
	GLABEL++;

	return strdup(label_num);
}

// PRE: A pointer to the top of our AST for DECAF
// POST: Mips code which implements the DECAF representation
void emit_all(ASTnode *p)
{
	fprintf(fp, "#                  PACKAGE %s \n\n", p->S2->name);
	fprintf(fp, ".data\t# Data section starts here, strings first \n\n");

	// print all strings
	emit_strings(p);
	fprintf(fp, "_NL: .asciiz \"\\n\" # NEWLINE STRING \n\n");
	fprintf(fp, ".align 2 # start all global variable aligned\n\n");

	// print all globals
	emit_global(p);
	fprintf(fp, "\n\n.text # start of text segment (code)\n\n");
	fprintf(fp, ".globl main # Force MIPS to start at main label\n\n");
	// TODO: print out the text (mips)
	emit_mips(p); // prints out the mips code in the text segment.
}

// PRE: PTR to an entire AST (p is the entry point)
// POST: output to ASM file that prints labels and the strings associated
//      Each ASTnode that is a string will have p->label updated
//      be that generated label
//      We need that assignment later so that we can access the string
//      via the label

void emit_strings(ASTnode *p)
{
	if (p == NULL) {
		return;
	}
	if (p->type == A_CONSTANT_STRING) {
		p->label = GEN_LABEL();
		fprintf(fp, "%s:\t.asciiz\t%s\n", p->label, p->name);
	}

	emit_strings(p->S1);
	emit_strings(p->S2);
	emit_strings(p->next);
}
// emits the global/static variables
// PRE: ptr to an ASTnode
// POST: output to the data section for those nodes
//      as A_VARDEC with level 0
//      produce different output for assigned values to scalars.
//
void emit_global(ASTnode *p)
{
	// make sure node is not null
	if (p == NULL) {
		return;
	}

	// if it's a vardec and the level is 0 that means its a global variable
	if ((p->type == A_VARDEC) &&
	    (p->symbol->level ==
	     0)) { // if there's an assignment set it to a word
		if (p->S2 != NULL) {
			fprintf(fp,
				"%s:\t.word %d\t # global var initialized\n",
				p->name, p->S2->value);
		} else {
			// else if there is no assignment allocate empty space of the
			// true size of the variable.
			fprintf(fp,
				"%s:\t.space %d\t # global var uninitialized\n",
				p->name, p->size * WS);
		}
	}

	// call again on S1, S2, and next
	emit_global(p->S1);
	emit_global(p->S2);
	emit_global(p->next);
}

// PRE label, code, comment
// POST: output to file with ASM formatted output
//
// This is a general command to emit code to the asm with labels and comments
// L: the label (string)
// I: The instruction (string)
// C: The comment (string)
// to omit any of them pass an empty string
void emit(char *L, char *I, char *C)
{
	if (L != "") {
		fprintf(fp, "%s:\t%s\t\t #%s\n", L, I, C);
	} else {
		fprintf(fp, "\t%s\t\t #%s\n", I, C);
	}
}

// PRE: ptr to a method decl
// POST: MIPS code for the method
void emit_method_dec(ASTnode *p)
{
	char s[100];
	fprintf(fp, "\n\n%s:\t\t# MAIN METHOD LABEL\n\n", p->name);

	// set up activation record

	sprintf(s, "subu $t0 $sp %d",
		p->symbol->mysize * WS); // makes the subu size dynamic
	emit("", s, "set up $t0 to be the new spot for SP");
	emit("", "sw $ra ($t0)", "Store the return address in offset 0");
	emit("", "sw $sp 4($t0)", "Store the old stack pointer in offset 4");
	emit("", "move $sp $t0", "set the stack pointer to the new value");
	emit_nl(2);

	// hand shake for entry into a method.

	// p->S1 is the parameter for the method stored in the activation record
	// p->S2 is the block of code of the function
	emit_mips(p->S2); // emit the block of the function

	// deal with the return to other method or return to system

	emit("", "li $v0 0", "return NULL zero (0)");
	emit("", "lw $ra ($sp) ", "reset return address ");
	emit("", "lw $ra 4($sp)", "reset stack pointer ");

	// Special MIPS stop which has code 10 -- Only done in end of MAIN function
	// syscall will stop when v0 is 10
	if (strcmp(p->name, "main") == 0) {
		emit("", "li $v0, 10", "Main function ends ");
		emit("", "syscall", "MAIN FUNCTION EXIT ");
	}
}

// PRE: ptr to ASTnode
// POST: all MIPS code in fp file relating to the decaf AST
//      This is the main hub for selecting the correct method to
//      emit nodes
void emit_mips(ASTnode *p)
{ // emits the mips code in text section
	if (p == NULL) {
		return;
	}

	// Change print method depending on the Node type
	switch (p->type) {
	case A_PROGRAM:
		emit_mips(p->S2);
		break;
	case A_PACKAGE:
		// S1 is fielddecs because they have already been added in .global
		emit_mips(p->S2); // print the method decls
		break;
	case A_METHODDEC: // call the helper for printing methods
		emit_method_dec(p);
		break;
	case A_BLOCK: // handle blocks
		// p->S1 are local variables, handled by activation rec.
		emit_mips(p->S2);
		break;

	case A_METHODCALL: // handle method calls
		emit_method_call(p);
		break;
	case A_ASSIGN:
		emit_assign(p); // emit the assign mips code
		break;
	case A_IF:
		emit_if(p); // emit the if statement logic mips code
		break;
	case A_WHILESTMT:
		emit_while(p); // emit the while statement mips code.
		break;
	// case A_RETURN:
	// 	emit_return(p); // emit the while statement mips code.
	// 	break;
	default:
		// if none of the cases match print a warning.
		printf("emit_mips UNKNOWN AST type\n");
	}

	emit_mips(p->next);
}

// PRE: ptr to ASTnode
// POST: MIPS code needed for a method call to work.
//
// Note: for print_int(), print_string(), and read_int(), we will
// inline code these methods all others are handled with evaluating
// the params, placing them in appropriate registers and calling
// the method named
void emit_method_call(ASTnode *p) // handles emiting method calls
{ // Pre defined function call routines
	// picked based on the method call's name.
	if (strcmp(p->name, "print_int") == 0) {
		emit_print_int(p);
	} else if (strcmp(p->name, "print_string") == 0) {
		emit_print_string(p);
	} else if (strcmp(p->name, "read_int") == 0) {
		emit_read_int(p);
	} else {
		// printf("NO METHOD CALL IMPLEMENTED for %s YET\n", p->name);
		char s[100];

		// use a cursor for traversing linked lists.
		// this way we can traverse all the arguments efficiently
		ASTnode *cursor = p->S1;

		while (cursor != NULL) {
			emit_expr(cursor); // evaluate the argument

			// store the argument in the stack pointer in it's offset
			sprintf(s, "sw $a0, %d($sp)",
				cursor->symbol->offset * WS);
			emit("", s, "Store the argument value in the stack");

			// go to next argument
			cursor = cursor->next;
		}

		int num = 0; // keep track of which register $a0-$a3

		cursor = p->S1;
		while (cursor != NULL) {
			// We only have 4 registers to use for this.
			// make sure we only use 4
			if (num >= 4) {
				printf("Too many arguments in function %s \n",
				       p->name);
				exit(1);
			}

			emit_expr(
				cursor); // evaluate the argument and store in $a0

			// load the arguments from the stack pointers into
			// their $a0-$a3 registers
			sprintf(s, "lw $a%d, %d($sp)", num,
				cursor->symbol->offset * WS);
			emit("", s,
			     "load the argument from the stack to a0, a1, a2, a3 respectively and as necessary");

			// go to the next argument.
			cursor = cursor->next;

			// go to the next register
			num++;
		}
	}
}

// PRE: ptr to METHOD_CALL that is named print_string
// POST: inline MIPS code that generates the print
void emit_print_string(ASTnode *p) // handles the print_string methods
{
	emit_expr(p->S1); // $a0 will be the value in print_int
	emit("", "li $v0 4", "set up write call");
	emit("", "syscall", "print a string");

	emit("", "li $v0, 4", "print NEWLINE");
	emit("", "la $a0, _NL", "print NEWLINE string location");
	emit("", "syscall", "call print a NEWLINE");
	emit_nl(2);
}

// PRE: ptr to METHOD_CALL that is named print_int
// POST: inline MIPS code that generates the print
void emit_print_int(ASTnode *p) // handles the print_int methods
{
	emit("", "", "EMIT PRINT INT HERE");
	emit_expr(p->S1); // $a0 will be the value in print_int
	emit("", "li $v0 1", "set up write call");
	emit("", "syscall", "print a number");

	emit("", "li $v0, 4", "print NEWLINE");
	emit("", "la $a0, _NL", "print NEWLINE string location");
	emit("", "syscall", "call print a NEWLINE");
	emit_nl(2);
}

// PRE: ptr to an expression
// POST: MIPS code such that $a0 has the value of the expr in p
void emit_expr(ASTnode *p)
{
	char s[100];

	if (p == NULL) {
		printf("Illegal use of emit_expr NULL input");
		exit(1);
	}

	// handle bas e cases
	// no default case because that will be the recursive call
	switch (p->type) {
	case A_CONSTANT_INT:
	case A_CONSTANT_BOOL:
		sprintf(s, "li $a0, %d", p->value);
		emit("", s, "expr constant value");
		return;
		break;
	case A_CONSTANT_STRING:
		sprintf(s, "la $a0, %s", p->label);
		emit("", s, "expr constant is a string");
		return;
		break;
	case A_METHODCALL:
		emit_method_call(p); // $a0 will be the result value
		return;
		break;
	case A_VAR_RVALUE:
	case A_VAR_LVALUE:
		emit_ident(p); // $a0 now contains the memory address
		emit("", "lw $a0 ($a0)",
		     "load from the memory address a value");
		return;
		break;
	}

	// In our A_EXPR we need to eval S1 and perhaps S2
	// if there is an RHS
	emit_expr(p->S1); // $a0 will now contain the LHS

	// check if there is a RHS.
	//
	// if there is an RHS store the LHS then eval the RHS

	if (p->S2 != NULL) {
		// Store LHS in stack temporarily to make space for LHS
		sprintf(s, "sw $a0, %d($sp)", p->symbol->offset * WS);
		emit("", s, "store $a0 (LHS) temporarily so we can eval RHS");

		emit_expr(p->S2); // Now $a0 has the RHS

		// PUT RHS in $a1
		emit("", "move $a1, $a0", "move RHS to $a1");

		// Load LHS into $a0
		sprintf(s, "lw $a0, %d($sp)", p->symbol->offset * WS);
		emit("", s, "get LHS from storage");
		// List of operators
		switch (p->operator) {
		case A_PLUS:
			emit("", "add $a0, $a0, $a1", "add");
			break;

		case A_MINUS:
			emit("", "sub $a0, $a0, $a1", "subact");
			break;

		case A_LT:
			emit("", "slt $a0, $a0, $a1", "less than");
			break;

		case A_GT:
			emit("", "sgt $a0, $a0, $a1", "greater than");
			break;

		case A_LEQ:
			emit("", "sle $a0, $a0, $a1", "less than or eq to");
			break;

		case A_GEQ:
			emit("", "sge $a0, $a0, $a1", "greater than or eq to");
			break;

		case A_EQ:
			emit("", "seq $a0, $a0, $a1", "equal to");
			break;

		case A_NEQ:
			emit("", "sne $a0, $a0, $a1", "Not equal");
			break;

		case A_TIMES:
			break;

		case A_DIVIDE:
			break;

		case A_MOD:
			break;

		case A_OR:
			emit("", "or $a0, $a0, $a1", "OR");
			break;

		case A_AND:
			emit("", "and $a0, $a0, $a1", "AND");
			break;

		case A_LEFTSHIFT:
			emit("", "sllv $a0, $a0, $a1", "LEFTSHIFT");
			break;

		case A_RIGHTSHIFT:
			emit("", "srlv $a0, $a0, $a1", "RIGHTSHIFT");
			break;

		case A_UMINUS:
			emit("", "neg $a0, $a0", " UNARY MINUS");
			break;

		default:
			printf("Exist EXPR operator unknown");
		}
	}
}

// PRE: An integer indicating number of newlines
// POST: Emit x number of newlines to the asm
void emit_nl(int x)
{
	for (int i = 0; i < x; i++) {
		fprintf(fp, "\n");
	}
}

// PRE: ptr to an identifier. (LVALUE or RVALUE)
// POST: $a0 is thje memory address of the identifier
void emit_ident(ASTnode *p)
{
	// If it's an array we have a separate method for it
	if (p->symbol->SubType == ID_Sub_Type_Array) {
		emit_array(p);
		return;
	}
	char s[100];

	// check if it's being used incorrectly
	// Can only be used on a LHS or RHS node
	if (p->type != A_VAR_LVALUE && p->type != A_VAR_RVALUE) {
		printf("Illegal use of emit_ident\n");
		exit(1);
	}

	// Check if it's a global variable
	if (p->symbol->level == 0) {
		// load in the address using the name from the symtable
		sprintf(s, "la $a0, %s", p->name);
		emit("", s, "load global address of variable");
	} else { // else if it's a local variable

		// load the true offset into $a0
		sprintf(s, "li $a0, %d", p->symbol->offset * WS);
		emit("", s, "offset for variable address");

		// add the true offset to the stack pointer value
		emit("", "add $a0, $a0, $sp",
		     "exact location for stack variable");
	}
}

// PRE: P is ptr to A_ASSIGN
// POST: MIPS code in fp that assigns a value.
void emit_assign(ASTnode *p)
{
	char s[100];
	// make sure node is type A_ASSIGN
	if (p->type != A_ASSIGN) {
		printf("Illegal use of emit_assign");
		exit(1);
	}

	// get value for RVALUE
	// Store it temporarily so that LHS doesn't overwrite $a0
	// get the address of LHS
	// retrieve value from memory
	// store ther value at the address of LHS
	emit_expr(p->S2); // expression of the assign

	// store it into the holding spot in memory
	//
	sprintf(s, "sw $a0 %d($sp)", p->symbol->offset * WS);
	emit("", s, "store RHS of assign temporarily");

	emit_ident(p->S1); // get address of LHS

	sprintf(s, "lw $a1, %d($sp)", p->symbol->offset * WS);

	emit("", s, "load back RHS into $a1");

	emit("", "sw $a1, ($a0)", "Store assign value");
}

// PRE: ptr to method call read_int
// POST: $a0 will be the value read
void emit_read_int(ASTnode *p) // handles the print_int methods
{
	emit("", "li $v0, 5", "read int from user");
	emit("", "syscall", "to read a number");
	emit("", "move $a0, $v0", "Move the number into $a0");
}

// PRE: ptr to an ASTnode for A_IF
// POST: emit the code needed for an if/else statement
//      Two labels, a branch, and jump are used to navigate
//      the logic of an if else statemtent.
void emit_if(ASTnode *p)
{
	char s[100];

	// Generate the two labels
	char *label_one = GEN_LABEL();
	char *label_two = GEN_LABEL();

	// $a0 will now contain the evaluated expression
	emit_expr(p->S1);

	// Branch when the expression is equal to 0
	// to the first label in order to skip over the if block
	// and execute the else block
	sprintf(s, "beq $a0 $0 %s", label_one);
	emit("", s, "Branch to first label if expression is 0");

	emit_mips(p->S2->S1); // emit the if's main block

	sprintf(s, "j %s",
		label_two); // Jump to the second label to skip else
	emit("", s, "And the cow jumped over the else 🐄");

	// sandwich the else between the first and second label
	// This allows us to either enter the else or skip to after it.
	emit(label_one, "", "First Label for entering else");

	// Let's only emit the else if the else block is there.
	if (p->S2->S2 != NULL) {
		emit_mips(p->S2->S2); // emit else block
	} // if there is no else block it will just be an empty label sandwich

	emit(label_two, "", "Second Label for jumping over the else");
}

// PRE: ptr to an A_WHILE ASTnode
// POST: emit the MIPS assembly needed to do a while loop to fp
void emit_while(ASTnode *p)
{
	char s[100];

	// Generate the two labels
	char *label_one = GEN_LABEL();
	char *label_two = GEN_LABEL();

	emit(label_one, "", "First label to restart while loop's block");

	// now the expression is evaluated in $a0
	emit_expr(p->S1);

	// Branch equal to 0 to the second label this is the exit condition
	sprintf(s, "beq $a0 $0 %s", label_two);
	emit("", s, "Branch to second label if expression is 0");

	// emit the body of the while loop
	emit_mips(p->S2);

	// jump back up to the start of the loop using first label
	sprintf(s, "j %s",
		label_one); // Jump to the first label to repeat
	emit("", s, "And the little dog laughed to see such loops");

	// emit the second label used to skip over the while body
	emit(label_two, "", "Second label to jump to from the exit condition");
}

// PRE: ptr to an ASTnode of an A_VAR_LVALUE or A_VAR_RVALUE of an array
// POST: emit the proper evaluation of the array index to MIPS code in fp
//      at the end of this function $a0 will have the true address of the
//      item indexed in the array
void emit_array(ASTnode *p)
{
	// Copied the code from emit_ident
	// 1. Evaluate the expression in the array index argument
	// 2. multiply it by WS and store it in a new register $t3
	// 3. load the starting address of the array
	// 4. add the product result to the address to the get the offset
	//      of the index in the argument

	char s[100];

	// check if it's being used incorrectly
	// Can only be used on a LHS or RHS node
	if (p->type != A_VAR_LVALUE && p->type != A_VAR_RVALUE) {
		printf("Illegal use of emit_ident\n");
		exit(1);
	}

	emit_expr(p->S1); // Expression is evaluated in $a0

	// Check if it's a global variable
	if (p->symbol->level == 0) {
		// Multiply the index evaluated by 4 to get the real offset
		// Stored in a secondary register
		emit("", "sll $a1, $a0, 2", "Multiply by 4");

		// load in the starting offset of the array
		sprintf(s, "la $a0, %s", p->name);
		emit("", s, "load global address of array");

		// add the relative offset of the index to the starting offset
		// of the array store in $a0
		emit("", "add $a0, $a0, $a1", "");

	} else { // else if it's a local variable
		// Multiply the index evaluated by 4 to get the real offset
		// Stored in a secondary register
		emit("", "sll $a1, $a0, 2", "Multiply by 4");

		sprintf(s, "li $a0, %d", p->symbol->offset * WS);
		emit("", s, "offset for variable address");
		emit("", "add $a0, $a1, $sp",
		     "exact location for stack variable");
	}
}

// PRE: ptr to an ASTnode of type A_RETURN
// POST: emit mips code that will return the current function
void emit_return(ASTnode *p)
{
	/*
        li $v0 0    		#  return  NULL zero (0) 
        lw $ra ($sp)		# reset return address 
	lw $sp 4($sp)		# reset stack pointer 
	jr $ra       		# return to our caller
        */
	if (p->S1 != NULL) {
		char s[100];
		emit_expr(p->S1);
		emit("", "move $v0, $a0", "emit the expression in $a0");
	} else {
		emit("", "li $v0 0", "return null ");
	}
	emit("", "lw $ra ($sp)", " reset return address ");
	emit("", "lw $sp 4($sp)", "reset stack pointer ");
	emit("", "jr $ra  ", "return to our caller");
}
