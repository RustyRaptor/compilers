/*
Ziad Arafat - Mar 8 2021
Lab 5
*/

%{
#include <stdio.h>
#include <ctype.h>

int yylex();

extern int yylineno; // import the yylineno variable
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
        // changed these to output to stderr
  fprintf(stderr, "%s \n", s);

  // print out the line number of the syntax error.
  fprintf(stderr, "Error on line:  %d \n", yylineno); 
}


%}
/*  defines the start symbol, what values come back
from LEX and how the operators are associated */
/* changed to P  */
%start Program

/* Defines possible types */
%union
{
    int value;
    char* string;
}

// Added a token for each of the lex tokens
%token T_AND
%token T_ASSIGN
%token T_BOOLTYPE
%token T_BREAK
%token T_CHARCONSTANT
%token T_CONTINUE
%token T_DOT
%token T_ELSE
%token T_EQ
%token T_EXTERN
%token T_FALSE
%token T_FOR
%token T_FUNC
%token T_GEQ
%token T_GT
%token T_ID
%token T_IF
%token T_INTCONSTANT
%token T_INTTYPE
%token T_LEFTSHIFT
%token T_LEQ
%token T_NEQ
%token T_NULL
%token T_OR
%token T_PACKAGE
%token T_RETURN
%token T_RIGHTSHIFT
%token T_STRINGCONSTANT
%token T_STRINGTYPE
%token T_TRUE
%token T_VAR
%token T_VOID
%token T_WHILE

/* added all the rules from DECAF and reformatted them to work with Bison */

/* for each of the rules with a list of tokens I created a recursive rule
that allows for one or more of the token. 
*/

/* Replaced any instance of '=' with T_ASSIGN */

%%    /* end specs, begin rules */
Program            : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}'
                   ;

Externs            : /* empty */ 
                   | ExternDefn Externs
                   ;

ExternDefn         : T_EXTERN T_FUNC T_ID '(' ExternParmList ')' MethodType ';'
                   ;

ExternParmList     : /* empty */ 
                   | FullExternParmList 
                   ;

FullExternParmList : ExternType 
                   | ExternType ',' ExternParmList 
                   ;

FieldDecls         : /* empty */
                   | FieldDecl FieldDecls
                   ;

FieldDecl          : T_VAR T_ID Type ';'
                   ;

FieldDecl          : T_VAR T_ID ArrayType ';'
                   ;

FieldDecl          : T_VAR T_ID Type T_ASSIGN Constant ';'
                   ;

MethodDecls        : /* empty */
                   | MethodDecl MethodDecls
                   ;

MethodDecl         : T_FUNC T_ID '(' IdTypeList ')' MethodType Block
                   ;

IdTypeList         : /* empty */
                   | IdTypeList1
                   ;

IdTypeList1        : T_ID Type
                   | T_ID Type ',' IdTypeList
                   ;

Block              : '{' VarDecls Statements '}'
                   ;

VarDecls           : /* empty */
                   | VarDecl VarDecls
                   ;

VarDecl            : T_VAR T_ID Type ';'
                   ;

VarDecl            : T_VAR T_ID ArrayType ';'
                   ;

Statements         : /* empty */
                   | Statement Statements
                   ;

Statement          : Block
                   ;

Statement          : Assign ';'
                   ;

Assign             : Lvalue T_ASSIGN Expr
                   ;
/* Assigns            : Assign
                   | Assign ',' Assigns
                   ; */

Lvalue             : T_ID
                   | T_ID '[' Expr ']'
                   ;

Statement          : MethodCall ';'
                   ;

MethodCall         : T_ID '(' MethodArgs ')'
                   ;

MethodArg          : Expr
                   ;

MethodArgs         : /* empty */
                   | FullMethodArgs
                   ;

FullMethodArgs     : MethodArg
                   | MethodArg ',' MethodArgs
                   ;

Statement          : T_IF '(' Expr ')' Block T_ELSE Block 
                   | T_IF '(' Expr ')' Block
                   ;

Statement          : T_WHILE '(' Expr ')' Block
                   ;

/* Statement          : T_FOR '(' Assigns ';' Expr ';' Assigns ')' Block
                   ; */

Statement          : T_RETURN ';'
                   | T_RETURN '(' ')' ';'
                   | T_RETURN '(' Expr ')' ';'
                   ;

Statement          : T_BREAK ';'
                   ;

Statement          : T_CONTINUE ';'
                   ;



Expr               : Simpleexpression
                   ;
Simpleexpression   : Additiveexpression
                   | Simpleexpression Relop Additiveexpression
                   ;

Relop              : T_LEQ | '<' | T_GT | T_GEQ | T_EQ | T_NEQ
                   ;

Additiveexpression : Term
                   | Additiveexpression Addop Term
                   ;

Addop              : '+' | '-'
                   ;

Term               : Factor
                   | Term Multop Factor
                   ;
/* added modulus as a multi operator */
Multop             : '*' | '/' | '%' | T_AND | T_OR | T_LEFTSHIFT | T_RIGHTSHIFT
                   ;

Factor             : T_ID
                   | MethodCall
                   | T_ID '[' Expr ']'
                   | Constant
                   | '(' Expr ')'
                   | '!' Factor
                   | '-' Factor
                   ;




ExternType        : T_STRINGTYPE 
                  | Type
                  ;

Type              : T_INTTYPE 
                  | T_BOOLTYPE 
                  ;

MethodType        : T_VOID 
                  | Type
                  ;

BoolConstant      : T_TRUE 
                  | T_FALSE
                  ;

ArrayType         : '[' T_INTCONSTANT ']' Type
                  ;
/* added String and Char as constants */
Constant          : T_INTCONSTANT
                  | T_STRINGCONSTANT
                  | T_CHARCONSTANT
                  | BoolConstant
                  ;
%%    /* end of rules, start of program */

int main(){
        
        yyparse();
}
