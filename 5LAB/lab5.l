/*      Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
        along with single string elements like '+'.

        This LEX definition is the companion to the docalc.y YACC routine which
        is a simple calculator

        Shaun Cooper
        January 2015
*/

/* Ziad Arafat Mar 8 2021 */

%{

#include "y.tab.h"
#include <string.h> 
int yylex();
int mydebug=0;

int aHexToInt(char * hexstr)
{
        // I used the code we used in one of the 273 labs and adapted it to
        // work on any number of chars.

        // Uses the difference of the ASCII table values of the chars to get
        // the value. 

        size_t len = strlen(hexstr)-1;
        int mult = 1;
        int val = 0;

        // since we already check to make sure it's 0-9 we don't need to
        // exclude the x in 0x and obviously the 0 will make no change to the
        // value. 
        if (*(hexstr + len) >= '0' && *(hexstr + len) <= '9') val = (*(hexstr + len) - '0') * mult;
        else if (*(hexstr + len) >= 'a' && *(hexstr + len) <= 'f') val = (*(hexstr + len) - 'a' + 10) * mult;
        else if (*(hexstr + len) >= 'A' && *(hexstr + len) <='F') val = (*(hexstr + len) - 'A' + 10) * mult;

        mult *= 16;

        char *hexstrptr;
        for (hexstrptr = hexstr+(len-1); hexstrptr != hexstr; hexstrptr--){
                if (*hexstrptr >= '0' && *hexstrptr <= '9') val += (*hexstrptr - '0') * mult;
                else if (*hexstrptr >= 'a' && *hexstrptr <= 'f') val += (*hexstrptr - 'a' + 10) * mult;
                else if (*hexstrptr >= 'A' && *hexstrptr <='F') val += (*hexstrptr - 'A' + 10) * mult;
                mult *= 16;
        }
       
        // printf("The hex value is: %d\n", val);

        return val;
}

%}

/*
CHANGES:
        - added the DECAF tokens
        - Added some debug prints to the tokens
        - Added square brackets to the lex directive
        - Added '<' token to the directive
        - Added modulus '%'
        - Added directive for HEX numbers
        - Created function to convert hex numbers to their int value
        - Disabled the newline return token
*/


%%
"&&"       {return(T_AND);}

"=" {
        if (mydebug) fprintf(stderr,"T_ASSIGN found\n");
        return(T_ASSIGN);
}

"bool"     {return(T_BOOLTYPE);}
"break"    {return(T_BREAK);}
"continue" {return(T_CONTINUE);}
\.         {return(T_DOT);}
"else"     {return(T_ELSE);}
"=="       {return(T_EQ);}
"extern"   {return(T_EXTERN);}
"false"    {return(T_FALSE);}
"for"      {return(T_FOR);}
"func"     {return(T_FUNC);}
">="       {return(T_GEQ);}
">"        {return(T_GT);}

"if"       {if (mydebug) fprintf(stderr,"T_IF found\n");return(T_IF);}

"int" {
        if (mydebug) fprintf(stderr,"T_INTTYPE found\n");
        return(T_INTTYPE);

}

"<<"       {return(T_LEFTSHIFT);}
"<="       {return(T_LEQ);}
"!="       {return(T_NEQ);}
"null"     {return(T_NULL);}
"||"       {return(T_OR);}
"package"  {return(T_PACKAGE);}
"return"   {return(T_RETURN);}
">>"       {return(T_RIGHTSHIFT);}
"string"   {return(T_STRINGTYPE);}
"true"     {return(T_TRUE);}
"var"      {if (mydebug) fprintf(stderr,"T_VAR found\n");return(T_VAR);}
"void"     {if (mydebug) fprintf(stderr,"T_VOID found\n");return(T_VOID);}
"while"    {return(T_WHILE);}

\'.\' {
        yylval.value=yytext[1];
        return(T_CHARCONSTANT);
}

\".*\" {
        yylval.string=strdup(yytext);
        return(T_STRINGCONSTANT);
}

[a-zA-Z][a-zA-Z0-9_]* {
        if (mydebug) {
                fprintf(stderr,"Identifier found %s\n", yytext);
        }
        yylval.string=strdup(yytext);
        return(T_ID);
}

0x[0-9A-Za-f][0-9A-Za-f]* {
        if (mydebug) fprintf(stderr,"Hex found %s\n", yytext); 
        yylval.value=aHexToInt((char *)yytext);
        return(T_INTCONSTANT);
}


[0-9][0-9]* {
        if (mydebug) fprintf(stderr,"Integer found %s\n", yytext); 
        yylval.value=atoi((const char *)yytext);
        return(T_INTCONSTANT);
}

[ \t] {
        if (mydebug) fprintf(stderr,"Whitespace found\n");
}

[\-+*/%();{},\[\]!<] {
        if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
        return (*yytext);
}

\n {
        if (mydebug) fprintf(stderr,"carriage return %c\n",*yytext); 
}
\/\/.* { /* this is a comment line for double slash  Return nothing, keep going */ }
%%

int yywrap(void)
{
        return 1;
}