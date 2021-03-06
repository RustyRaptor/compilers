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
"&&"                    {return(T_AND);}
"="                     {return(T_ASSIGN);}
"bool"                  {return(T_BOOLTYPE);}
"break"                 {return(T_BREAK);}
"char_lit"              {return(T_CHARCONSTANT);}
"continue"              {return(T_CONTINUE);}
"."                     {return(T_DOT);}
"else"                  {return(T_ELSE);}
"=="                    {return(T_EQ);}
"extern"                {return(T_EXTERN);}
"false"                 {return(T_FALSE);}
"for"                   {return(T_FOR);}
"func"                  {return(T_FUNC);}
">="                    {return(T_GEQ);}
">"                     {return(T_GT);}
"identifier"            {return(T_ID);}
"if"                    {return(T_IF);}
"int_lit"               {return(T_INTCONSTANT);}
"int"                   {return(T_INTTYPE);}
"<<"                    {return(T_LEFTSHIFT);}
"<="                    {return(T_LEQ);}
"!="                    {return(T_NEQ);}
"null"                  {return(T_NULL);}
"||"                    {return(T_OR);}
"package"               {return(T_PACKAGE);}
"return"                {return(T_RETURN);}
">>"                    {return(T_RIGHTSHIFT);}
"string_lit"            {return(T_STRINGCONSTANT);}
"string"                {return(T_STRINGTYPE);}
"true"                  {return(T_TRUE);}
"var"                   {return(T_VAR);}
"void"                  {return(T_VOID);}
"whil"                  {return(T_WHILE);}

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

[=\-+*/%&|();^] {
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