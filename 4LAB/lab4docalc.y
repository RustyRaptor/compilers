%{
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"
int yylex();

int regSize = 5; // created variable to hold size of the regs array

int regs[5]; // changed size to be big enough
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s \n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated changed to P  */
/* changed to P  */
%start P 

/* Defines possible types */
%union
{
    int value;
    char* string;
}


/*

 set expr to have type value
 INTEGER is type value
 VARIABLE is type string
  */
%type <value> expr

%token <value> INTEGER
%token <string> VARIABLE

%token T_INT

%left '|'
%left '&'
%left '+' '-'
%left '^'

%left '*' '/' '%' '(' /*add a opening parenthesis */
%left UMINUS

/* add a closing parenthesis */
%right ')'

/* 
        created entry for multiplication in similar format to existing rules.
        Fixed unary minus by making it one side only as opposed to the existing two sided
        expression.
*/


%%    /* end specs, begin rules */

/* add the context free grammar rules */

/* start */
P       :   DECLS list
        ;

/* define DECLS as declarations or empty */
DECLS   :   DECLS DECL 
        |   /* empty */ 
        ;

/* define declaration as int var; newline */
DECL    : T_INT VARIABLE ';' '\n'  
        {
                /* check if the variable exists then insert or barf */
                if (Search($2) == 1 ) {
                        printf("The variable exists already");
                } else if (size >= regSize) {
                        printf("The table is full");
                } else {
                        Insert($2, size);
                        
                }

        };

list    :    /* empty */
        |    list stat '\n'
        |    list error '\n'
            { yyerrok; }
        ;

stat    :    expr
            { fprintf(stderr,"The answer is %d\n", $1); }
        |       VARIABLE '=' expr { 
                        // check if it exists first or barf
                        if (Search($1) == 1) { 
                                // now we get the correct address from the table
                                regs[FetchAddress($1)] = $3;
                        } else {
                                printf("Undefined variable");
                        }
                }
    ;

expr    :    '(' expr ')'
            { $$ = $2; }
    |    expr '-' expr
            { $$ = $1 - $3; }
    |    expr '+' expr
            { $$ = $1 + $3; }
    |    expr '/' expr
            { $$ = $1 / $3; }
    |    expr '%' expr
            { $$ = $1 % $3; }
    |    expr '&' expr
            { $$ = $1 & $3; }
    |    expr '^' expr
            { $$ = powfuck($1, $3); }
    |    expr '|' expr
            { $$ = $1 | $3; }
    |    expr '*' expr { $$ = $1 * $3; }
    |    '-' expr %prec UMINUS
            { $$ = -$2; }
    |   VARIABLE
        {
                // check if it exists before trying to access
                if (Search($1) == 0) { 
                        printf("Undefined variable %s\n", $1);
                        $$ = 0; // give it a default value
                        
                } else {
                        
                        // get the address to find value
                        $$ = regs[FetchAddress($1)]; 
                }
                
        }
    |    INTEGER {$$=$1; fprintf(stderr,"found an integer \n");}
    ;



%%    /* end of rules, start of program */

int main(){ 
        yyparse();
}