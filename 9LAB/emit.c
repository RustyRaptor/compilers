

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

// PRE: ptr to ASTnode
// POST: all MIPS code in fp file relating to the decaf AST
void emit_mips(ASTnode *p); // emits the mips code in text section

FILE *fp = NULL;

char *CURRENT_FUNC; // need to know Current Function for return on main

void EMITAST(ASTnode *p, FILE *fp); // recursive wlka of AST produces MIPS

void emit_expr(ASTnode *p, FILE *fp); // helpr function for EMITAST

// A data structure linked list which allows to keep track of current
// labels for break and cotinue

struct LabelList {
	char *s;
	struct LabelList *next;
};

// global variables to maintain break and continue targets
//

struct LabelList *BreakList, *ContinueList;

// used to maintain the containeing FOR/WHILE labels
void PushLabelBreakList(char *S)
{
	struct LabelList *myNode;
	// Missing
} // of PushLabelBreakList

// used to maintain the containeing FOR/WHILE labels
void PushLabelContinueList(char *S)
{
	struct LabelList *myNode;
	// missing
} // of PushLabelContinueList

// remove inner most Break label
void PopLabelBreakList()
{
	BreakList = BreakList->next;
}

// remove inner most continue lable
void PopLabelContinueList()
{ // missing
}

static int GLABEL = 0; // global label counter

// creates one_up labels of the form _L%d
//  PRE:  none
//  POST:  new copy of strring of the form _L% and GLABEL is incremented
char *genlabel()
{
	char s[100];
	char *S1;
	// missing
}

// Emit the HEADERS, etcs
//

// PRE none
// Post requred header for MIPS in FILE fp
//
void Emit_Global_headers(FILE *fp, ASTnode *program)
{
	fprintf(fp, "\n\n#\tPackage %s \n\n", program->name);
	fprintf(fp, ".data # start of the DATA section, strings first\n\n");
	Emit_Write_Global_Strings(fp, program);
	fprintf(fp, "_NL: .asciiz \"\\n \"# New line\n");
	fprintf(fp, ".align 2 # start all of global variable aligned\n\n");
	Emit_Global(program);

	fprintf(fp, "\n.text\n ");
	fprintf(fp, "\n.globl main\n\n ");
	// emit_default_extern_methods(fp);
} // of Emit_Global_headers

// this function outputs through global "fp" all of the global variables
// // defined in the source code

// PRE ptr to AST
// POST output to fp with every GLOBAL variable at level 0
// declared and if needed, initialize
//   Recursive
//   INPUT
//   package foo {
//           var y int =7;
//           var Z int ;
//           var A[100] int ;
//           var x bool = true;
//    }
//
//
//
//   Creates
//   y:      .word 7         # define a global variable with initial value
//   Z:      .space 4                # define a global variable
//   A:      .space 400              # define a global variable
//   x:      .word 1         # define a global variable with initial value
//
void Emit_Global(ASTnode *p)
{
	if (p == NULL)
		return;
	// missing
}

// program to write out the label, string pair
// NB: T_STRING_LIT needs a label in the SDSA in YACC file
// PRE Ptr to AST
// POST  all strings are printed with a one up label
//
//    print_string("hello");
//
//    would generate tin the .data section
//    _L0:    .asciiz "hello"         # global string
//
//   Each string has unique label via genlabel().  You will need to assign a
//   label to the string AST node for T_STRING_LIT
//
void Emit_Write_Global_Strings(FILE *fp, ASTnode *program)
{
	if (program == NULL)
		return;
	// missing  includes recrusive calls

} // of Emit_Write_Global_Strings

// helper routine which outputs label, command,and comment lines
void emit(FILE *fp, char *label, char *command, char *comment)
{
	char s[100];

	fprintf(fp, "%s\t%s\t\t%s\n", label, command, comment);
}

/* Routine to set the specific  memory address of an IDENTifier in $a0.
   The calling routine will need to get value if needed
    PRE : PTR to indent
   POST:  $a0 has the mem location of ident
*/

void emit_ident(ASTnode *p, FILE *fp)
{
	char s[100];

	/* the IDENT is either a straight ID , or array reference

      For straight ID, we get the offset, multiply by wordsize

      For array reference, we have to see if the expression is a NUMBER
      or an expression.
      If a number we do immediate i
      If an expression we fetch from memory using the result of the expression
      and then load in the result of the expression
   */

	/* we assume the node is IDENT and is properly conected */

	//  $t3 is the holder of offset into the IDENTIFIER
	//  $t2 first holds the offset of the IDENT from stack and then
	//   is the direct reference into the stack

	if (p->S1 == NULL) { // we have a straight identifier
	} else { // this is an array
		// missing
	}

	/* we always get to the starting point of the identifier*/
	/*  If the Identifier is a GLOBAL, we load that address, otherwise, we need to
     find the offset of the identifier

 */

	// figure out if it is static (data segment) or stack
	// missing

	// if we have an ARRAY then add on offset
	if (p->S1 != NULL) {
		printf("");
	}
	// missing

} // of function emit_ident

// Given a PTR to a function call, handle it
//
void handle_function_call(ASTnode *p, FILE *fp)
{
	char s[100];
	ASTnode *fparm, *arglist;
	// we are handed a pointer to perform a function/subroutine call
	// we need to take our parameters and place in the correct new Activation
	// record, and then call the function

	// take care of the three special external function as inline

	fparm = p->symbol->fparms;
	arglist = p->S1;

	if (strcmp(p->name, "print_string") == 0) {
		// assume $a0 is the label address
		sprintf(s, "la $a0 %s", arglist->S1->label);
		emit(fp, "", "", "");
		emit(fp, "", s, "#get string address for print");
		emit(fp, "", "li $v0, 4", "#print a string");
		emit(fp, "", "syscall", "");
		emit(fp, "", "", "");
		emit(fp, "", "li $v0, 4", "#print NEWLINE");
		sprintf(s, "la $a0, _NL");
		emit(fp, "", s, "#print NEWLINE string location");
		emit(fp, "", "syscall", "");
		return;
	}

	// $a0 is the value to print
	if (strcmp(p->name, "print_int") == 0) {
		printf("it is a print int\n");
		emit_expr(arglist->S1, fp);
		printf("it is a print int\n");
		emit(fp, "", "", "#print an INT");
		emit(fp, "", "li $v0 1", "#set up write call");
		emit(fp, "", "syscall", "");
		emit(fp, "", "", "");
		emit(fp, "", "li $v0, 4", "#print NEWLINE");
		sprintf(s, "la $a0, _NL");
		emit(fp, "", s, "#print NEWLINE string location");
		emit(fp, "", "syscall", "");
		emit(fp, "", "", "");
		return;
	}
	//
	// $v0 will be the value read in
	if (strcmp(p->name, "read_int") == 0) {
		emit(fp, "", "", "");
		emit(fp, "", "", "# read Int $v0 has return value");
		emit(fp, "", "li $v0 5", "#read in a number ");
		emit(fp, "", "syscall", "#now read  ");
		emit(fp, "", "move $a0, $v0", "#copy $v0 to $a0 ");
		emit(fp, "", "", "");
		return;
	}
	// all other method calls handled below

	// evaluate the args, and place them in $a0-$a3

	// missing

	// now call the function

	emit(fp, "", "",
	     "# about to call a function, set up each parameter in the new "
	     "activation record");

	sprintf(s, "jal %s", p->name);
	emit(fp, "", s, "#jump and link to function");
}

/*  Routine to create the Function startup  processes */

void emit_func_start(ASTnode *p, FILE *fp)
{
	printf("working on FUNCTION %s\n", p->name);
	char s[100];
	sprintf(s, "%s:", p->name);
	emit(fp, "", "", ""); /* blank line */
	emit(fp, "", "", ""); /* blank line */
	emit(fp, s, "", "#Start of Function ");

	CURRENT_FUNC = p->name; // so we know what it is in return statement

	// if this is the main program output the needed header to carve out stack
	// space for the global variables

	// figure out how much stack we need , we will use $t0 to store this value
	// missing

	// we now copy the $a0 - $a3 registers to their respective locations
	// missing
	//
	emit(fp, "", "", ""); /* blank line */
	emit(fp, "", "", ""); /* blank line */
}

// Produce code for end of function and returns .
//  Basically, we need to assign $a0 a value from the return or 0 if it is void
//  Then set the $ra from the top of stack
//   and then set the stack to old stack
//  and then jump register

void emit_func_return(ASTnode *p, FILE *fp)
{
	char s[100];
	/* figure out what return value to send */

	//  implicit return
	if (p == NULL) {
		// missing

	} else // explicit return
	{ /* we have a number or an expression */
		printf("return statement not null\n");
		emit_expr(p, fp);
	}

	/* set ra and sp */

	// missing needs to be special for MAIN
}

/* The basic algorithm
 * pre condition p is derived from expression
 * we will set $a0 to the value of emit expression
 */

void emit_expr(ASTnode *p, FILE *fp)
{
	char s[100];

	/*   base cases */
	switch (p->type) { // missing
		break;

	} // of switch for base cases

	// we have an expression

	// recursive case LHS

	//  recusive case RHS
	//  Put things together

	// now execute the desired operation
	switch (p->operator) {
	case A_PLUS:
		emit(fp, "", "add $a0, $a0, $a1", "#EXPR ADD");
		break;
		// missing
	}

	// store the result in memory
}

//  routine to do an assignment statement
//  PRE:  PTR to assignment
//  POST:  MIPS code for assignment

void emit_assign(ASTnode *p, FILE *fp)
{
}

// Given an IF Statement, generate the mips code to do the jumping we need to
// do

void emit_if(ASTnode *p, FILE *fp)
{
}

// handle the WHILE statement
void emit_while(ASTnode *p, FILE *fp)
{
}

/*  EMIT the Abstract syntax tree */
// PRE: PTR to AST
// POST: MIPS code in fp for each AST instruction
void EMITAST(ASTnode *p, FILE *fp)
{
	char s[100];
	int i;
	if (p == NULL)
		return;

	switch (p->type) {
	case A_PACKAGE:
		EMITAST(p->S1, fp); // externs
		EMITAST(p->S2, fp); // PACKAGE_SUB
		break;
		// missing

	default:
		printf("%d:  unknown type in EMITAST\n", p->type);
	}
	EMITAST(p->next, fp); // always do the next
}

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
	if (p == NULL) {
		return;
	}
	if ((p->type == A_VARDEC) && (p->symbol->level == 0)) {
		if (p->S2 != NULL) {
			fprintf(fp,
				"%s:\t.word %d\t # global var initialized\n",
				p->name, p->S2->value);
		} else {
			fprintf(fp,
				"%s:\t.space %d\t # global var uninitialized\n",
				p->name, p->size * WS);
		}
	}

	emit_global(p->S1);
	emit_global(p->S2);
	emit_global(p->next);
}

// PRE: ptr to a method decl
// POST: MIPS code for the method
void emit_method_dec(ASTnode *p)
{
	fprintf(fp, "\n\n%s:\t\t# MAIN METHOD LABEL\n\n", p->name);
}

// PRE: ptr to ASTnode
// POST: all MIPS code in fp file relating to the decaf AST
void emit_mips(ASTnode *p)
{ // emits the mips code in text section
	if (p == NULL)
		return;

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
	default:
		printf("emit_mips UNKNOWN AST type\n");
	}

	emit_mips(p->next);
}