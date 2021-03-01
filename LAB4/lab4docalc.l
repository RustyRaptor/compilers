        /*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
        */ 

%{
int mydebug=0;
#include "y.tab.h"
int yylex();

%}

        /*
        - added an entry for parenthesis to the tokens directive
        - added int directive to return T_INT token
        - changed the directive for VARIABLE to accept multichar variables
        - added semicolon as a token
        */
%%
"int" {
    return(T_INT);
}
[a-zA-Z][a-zA-Z0-9]* {
        if (mydebug) fprintf(stderr,"Letter found\n");
        yylval.string=strdup(yytext);
        return(VARIABLE);

}
[0-9][0-9]* {
        if (mydebug) fprintf(stderr,"Digit found\n"); 
        yylval.value=atoi((const char *)yytext);
        return(INTEGER);
}

[ \t] {
        if (mydebug) fprintf(stderr,"Whitespace found\n");
}

[=\-+*/%&|();] {
        if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
        return (*yytext);
}

\n {
        if (mydebug) fprintf(stderr,"carriage return %c\n",*yytext); 
        return (*yytext);
}
%%

int yywrap(void)
{ return 1;}