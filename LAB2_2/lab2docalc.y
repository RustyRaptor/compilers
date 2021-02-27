%{
#include <stdio.h>
#include <ctype.h>
int yylex();

int regs[26];
int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s \n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start list

%token INTEGER
%token  VARIABLE

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

list    :    /* empty */
    |    list stat '\n'
    |    list error '\n'
            { yyerrok; }
    ;

stat    :    expr
            { fprintf(stderr,"The answer is %d\n", $1); }
    |    VARIABLE '=' expr
            { regs[$1] = $3; }
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
    |    VARIABLE
            { $$ = regs[$1]; fprintf(stderr,"Found a variable value = %d\n",$1); }
    |    INTEGER {$$=$1; fprintf(stderr,"found an integer \n");}
    ;



%%    /* end of rules, start of program */

int main(){ 
        yyparse();
}