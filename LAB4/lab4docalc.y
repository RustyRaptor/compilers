%{
#include <stdio.h>
#include <ctype.h>
#include "symtable.h"
int yylex();

int regSize = 99999;

int regs[9999];
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s \n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P

%union
{
    int value;
    char* string;
}


%type <value> expr

%token <value> INTEGER
%token <string> VARIABLE
%token T_INT

%left '|'
%left '&'
%left '+' '-'

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

P       :   DECLS list
        ;

DECLS   :   DECLS DECL 
        |   /* empty */ 
        ;

DECL    : T_INT VARIABLE ';' '\n'  
        {
                if (Search($2) == 1 ) {
                        printf("The variable exists already");
                } else if (size >= regSize) {
                        printf("The table is full");
                } else {
                        Insert($2, size);
                        
                }

                
                
                // check if VARIABLE $2 is already defined
                // if not check to make sure our symtab has enuf room
                // you should make a global variable that defines the size
                // of our memory
        };

DECL    : T_INT VARIABLE '=' expr ';' '\n'  
        {
                if (Search($2) == 1 ) {
                        printf("The variable exists already");
                } else if (size >= regSize) {
                        printf("The table is full");
                } else {
                        Insert($2, size);
                        regs[FetchAddress($2)] = $4;
                }
                // check if VARIABLE $2 is already defined
                // if not check to make sure our symtab has enuf room
                // you should make a global variable that defines the size
                // of our memory
        };

list    :    /* empty */
        |    list stat '\n'
        |    list error '\n'
            { yyerrok; }
        ;

stat    :    expr
            { fprintf(stderr,"The answer is %d\n", $1); }
        |       VARIABLE '=' expr { 
                        if (Search($1) == 1) { 
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
    |    expr '|' expr
            { $$ = $1 | $3; }
    |    expr '*' expr { $$ = $1 * $3; }
    |    '-' expr %prec UMINUS
            { $$ = -$2; }
    |   VARIABLE
        {
                if (Search($1) == 1) { 
                                $$ = regs[FetchAddress($1)]; 
                        } else {
                                printf("Undefined variable");
                        }
                
                /* fprintf(stderr,"Found a variable value = %d\n",$$); */ 
        }
    |    INTEGER {$$=$1; fprintf(stderr,"found an integer \n");}
    ;



%%    /* end of rules, start of program */

int main(){ 
        yyparse();
}