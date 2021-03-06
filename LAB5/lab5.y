%{
#include <stdio.h>
#include <ctype.h>
int yylex();


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
        created entry for multiplication in similar format to existing rules.
        Fixed unary minus by making it one side only as opposed to the existing two sided
        expression.
*/


%%    /* end specs, begin rules */



%%    /* end of rules, start of program */

int main(){ 
        yyparse();
}