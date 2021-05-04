

//  Subprograms which output NASM code.
//
//   Shaun Cooper Spring 2017
/// Updated Spring 2017 to utilize the data segement portion of NASM instead of
/// advancing the Stack and Global pointers to accomodate global variables.

// NASM is called on linux as
//  gcc foo.s
/*
Ziad Arafat - Apr 26 2021
Lab 9
Apr 26 2021:
        - prototyped emit_all()
        - prototyped GEN_LEBEL()

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EMIT_H
#define EMIT_H

#include "ast.h"
#include "symtable.h"
#define WSIZE 4 // number of bytes in a word
#define WS 4 // number of bytes in a word
#define LOGWSIZE 2 // number of shifts to get to WSIZE
extern FILE *fp;

// PRE: no input
// POST: char i* to a one up string of the form "_L%d"
char *GEN_LABEL();

// PRE: A pointer to the top of our AST for DECAF
// POST: Mips code which implements the DECAF representation

void emit_all(ASTnode *p);

// PRE: PTR to an enture AST
// POST: output to ASMS file that prints labels and the strings associated
//      Each ASTnode that is a string will have p->label updated
//      be that generated label
//      We need that assignment later so that we can access the string
//      via the label
void emit_strings(ASTnode *p);

char *genlabel(); // needed in YACC for T_STRING_LIT

void Emit_Global_headers(FILE *fp, ASTnode *program);

void EMITAST(ASTnode *p, FILE *fp);
void emit_expr(ASTnode *p, FILE *fp);

void emit(FILE *fp, char *label, char *command, char *comment);

void emit_default_extern_methods(FILE *fp);

void Emit_Write_Global_Strings(FILE *fp, ASTnode *program);

char *ER(char *S, int offset, char *r);
char *ES(char *s, int offset);

void emit_ident(ASTnode *p, FILE *fp);

void emit_header(FILE *fp, int NUM, int offset);

void handle_function_call(ASTnode *p, FILE *fp);

void emit_func_start(ASTnode *p, FILE *fp);

void emit_func_return(ASTnode *p, FILE *fp);

void emit_expr(ASTnode *p, FILE *fp);

void emit_assign(ASTnode *p, FILE *fp);

void emit_if(ASTnode *p, FILE *fp);
void emit_while(ASTnode *p, FILE *fp);

void Emit_Global(ASTnode *p);
void EMITAST(ASTnode *p, FILE *fp);

// PRE: ptr to an ASTnode
// POST: output to the data section for those nodes
//      as A_VARDEC with level 0
//      produce different output for assigned values to scalars.
//       
void emit_global(ASTnode *p); // emits the global/static variables




#endif // of EMIT.h
