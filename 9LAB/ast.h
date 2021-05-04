/*   Abstract syntax tree code


 Header file
 Shaun Cooper January 2020

*/

/*
Ziad Arafat - Apr 26 2021
Lab 9
4/3/2021 added variable to ASTnode to handle labels for strings

*/

#include <malloc.h>
#include <stdio.h>

#ifndef AST_H
#define AST_H
static int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what
sort of production rule we came across */

/* added all the needed tree nodes */
enum AST_Tree_Element_Type {
	A_PROGRAM,
	A_EXTERN,
	A_PACKAGE,
	A_METHODDEC,
	A_NUMBER,
	A_WHILESTMT,
	A_BLOCK,
	A_EXPR,
	A_PARAM,
	A_VARDEC,
	A_ExternType,
	A_ARRAYTYPE,
	A_METHODID,
	A_CONSTANT_INT,
	A_CONSTANT_BOOL,
	A_CONSTANT_STRING,
	A_BREAK,
	A_VAR_RVALUE,
	A_VAR_LVALUE, // added this to fix last lab
	A_RETURN,
	A_ASSIGN,
	A_IF,
	A_IFBODY,
	A_ELSE,
	A_METHODCALL,
	A_CONTINUE

	// missing
};

/* Added all the needed operators */
enum AST_Operators {
	A_PLUS,
	A_MINUS,
	A_UMINUS,
	A_TIMES,
	A_DIVIDE,
	A_MOD,
	A_AND,
	A_OR,
	A_LEFTSHIFT,
	A_RIGHTSHIFT,
	A_LT,
	A_GT,
	A_EQ,
	A_LEQ,
	A_GEQ,
	A_NEQ,
	A_NOT
	// missing
};

enum AST_Decaf_Types {
	A_Decaf_INT,
	A_Decaf_BOOL,
	A_Decaf_VOID,
	A_Decaf_STRING,
	A_Decaf_CHAR
	// missing
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code
*/
typedef struct ASTnodetype {
	enum AST_Tree_Element_Type type;
	enum AST_Operators operator;
	char *name;
	int value;
	struct SymbTab *symbol;
	enum AST_Decaf_Types A_Declared_Type;
	int size;
	///.. missing
	struct ASTnodetype *S1, *S2, *next; /* used for holding IF and WHILE
                                         components -- not very descriptive */
	char *label;
} ASTnode;

#include "symtable.h"

/* uses malloc to create an ASTnode and passes back the heap address of the
 * newley created node */
ASTnode *ASTCreateNode(enum AST_Tree_Element_Type mytype);

void PT(int howmany); // prints howmany spaces

ASTnode *program; // Global Pointer for connection between YACC and backend

/*  Print out the abstract syntax tree */
void ASTprint(int level,
	      ASTnode *p); // prints tree with level horizontal spaceing

// checks that two nodes match in type and length
int check_parameters(ASTnode *formal, ASTnode *actual);

// created this because it was starting to look messy in yacc
// takes an operator and a type and returns 1 if they are compatible 0 if not
int check_operators(enum AST_Operators op, enum AST_Decaf_Types type);

#endif // of AST_H
