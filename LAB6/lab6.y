/*
Ziad Arafat - Mar 8 2021
Lab 5
*/

%{
#include <stdio.h>
#include <ctype.h>

#include "ast.h"

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

struct ASTnodetype *PROGRAM;

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
    struct ASTnodetype *astnode;
    enum AST_Decaf_Types asttype;
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
%token <string> T_ID
%token T_IF
%token <value> T_INTCONSTANT
%token T_INTTYPE
%token T_LEFTSHIFT
%token T_LEQ
%token T_NEQ
%token T_NULL
%token T_OR
%token T_PACKAGE
%token T_RETURN
%token T_RIGHTSHIFT
%token <string> T_STRINGCONSTANT
%token T_STRINGTYPE
%token T_TRUE
%token T_VAR
%token T_VOID
%token T_WHILE

/* %token <string> T_STRING_LIT
%token <value> T_INT_LIT */

%type <astnode> Externs ExternDefn FullExternParmList ExternParmList FieldDecl FieldDecls
%type <asttype> MethodType Type ExternType Constant 
/* %type <astnode> ExternParmList
%type <astnode> FieldDecls 
%type <astnode> MethodDecls
%type <astnode> IdTypeList
%type <astnode> VarDecls
%type <astnode> Statements
%type <astnode> MethodArgs
%type <astnode> Program
%type <astnode> ExternDefn
%type <astnode> FullExternParmList
%type <astnode> FieldDecl
%type <astnode> MethodDecl
%type <astnode> Block
%type <astnode> VarDecl
%type <astnode> Statement

%type <astnode> Assign
%type <astnode> Assigns
%type <astnode> Lvalue
%type <astnode> MethodCall
%type <astnode> MethodArg
%type <astnode> FullMethodArgs
%type <astnode> Expr
%type <astnode> Simpleexpression
%type <astnode> Relop
%type <astnode> Additiveexpression
%type <astnode> Addop
%type <astnode> Term
%type <astnode> Multop
%type <astnode> Factor
%type <astnode> ExternType
%type <astnode> Type
%type <astnode> MethodType
%type <astnode> BoolConstant
%type <astnode> ArrayType
%type <astnode> Constant */

/* added all the rules from DECAF and reformatted them to work with Bison */

/* for each of the rules with a list of tokens I created a recursive rule
that allows for one or more of the token. 
*/

/* Replaced any instance of '=' with T_ASSIGN */

%%    /* end specs, begin rules */
Program         : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}'
                {
                        PROGRAM = ASTCreateNode(A_PROGRAM);
                        PROGRAM->S1 = $1;
                        PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
                        PROGRAM->S2->name = $3;
                        PROGRAM->S2->S1 = $5; // TODO: Field Decls $5
                        PROGRAM->S2->S2 = NULL; // TODO: Method Decls $6

                }
                ;

Externs         : /* empty */ { $$ = NULL; }
                | ExternDefn Externs 
                { $1->next = $2; }
                ;

ExternDefn      : T_EXTERN T_FUNC T_ID '(' ExternParmList ')' MethodType ';'
                        {
                                $$ = ASTCreateNode(A_EXTERN);
                                $$->name = $3;
                                $$->A_Declared_Type = $7; 
                                $$->S1 = $5;
                        }
                   ;

ExternParmList: /* empty */  { $$ = NULL; }
                | FullExternParmList {$$ = $1;}  
                
                ;

FullExternParmList: ExternType 
                {
                        $$ = ASTCreateNode(A_ExternType);
                        $$->A_Declared_Type = $1;
                }
                | ExternType ',' ExternParmList 
                {
                        $$ = ASTCreateNode(A_ExternType);
                        $$->A_Declared_Type = $1;
                        $$->next = $3;
                }
                ;

FieldDecls      : /* empty */ {$$ = NULL;}
                | FieldDecl FieldDecls
                {
                $$ = $1;
                $$->next = $2;
                }
                ;

FieldDecl       : T_VAR T_ID Type ';' 
                {
                      $$ = ASTCreateNode(A_VARDEC);
                      $$->name = $2;
                      $$->A_Declared_Type = $3;

                }
                | T_VAR T_ID ArrayType ';'
                {
                      $$ = ASTCreateNode(A_VARDEC);
                      $$->name = $2;
                //       $$->A_Declared_Type = $3;
                      // TODO: Implement Arrays

                }
                | T_VAR T_ID Type T_ASSIGN Constant ';'
                {
                      $$ = ASTCreateNode(A_VARDEC);
                      $$->name = $2;
                      $$->A_Declared_Type = $3;
                      $$->value = $5;

                }
                ;

MethodDecls     : /* empty */ 
                   | MethodDecl MethodDecls 
                   
                   ;

MethodDecl      : T_FUNC T_ID '(' IdTypeList ')' MethodType Block
                   ;

IdTypeList      : /* empty */ 
                   | IdTypeList1 
                   
                   ;

IdTypeList1     : T_ID Type
                   | T_ID Type ',' IdTypeList 
                   
                   ;

Block           : '{' VarDecls Statements '}'
                   ;

VarDecls        : /* empty */ 
                   | VarDecl VarDecls 
                   
                   ;

VarDecl         : T_VAR T_ID Type ';'
                | T_VAR T_ID ArrayType ';'
                   ;

Statements      : /* empty */ 
                   | Statement Statements 
                   
                   ;

Statement       : Block
                | Assign ';'
                | MethodCall ';'
                | T_IF '(' Expr ')' Block T_ELSE Block 
                | T_IF '(' Expr ')' Block 
                | T_WHILE '(' Expr ')' Block
                | T_RETURN ';'
                | T_RETURN '(' ')' ';' 
                | T_RETURN '(' Expr ')' ';' 
                | T_BREAK ';'
                | T_CONTINUE ';'
                ;

Assign          : Lvalue T_ASSIGN Expr
                   ;
/* Assigns         : Assign
                   | Assign ',' Assigns 
                   
                   ; */

Lvalue          : T_ID
                   | T_ID '[' Expr ']' 
                   
                   ;


MethodCall      : T_ID '(' MethodArgs ')'
                   ;

MethodArg       : Expr
                   ;

MethodArgs      : /* empty */ 
                   | FullMethodArgs 
                   
                   ;

FullMethodArgs  : MethodArg
                   | MethodArg ',' MethodArgs 
                   
                   ;





/* Statement       : T_FOR '(' Assigns ';' Expr ';' Assigns ')' Block
                   ; */





Expr            : Simpleexpression
                   ;
Simpleexpression: Additiveexpression
                   | Simpleexpression Relop Additiveexpression 
                   
                   ;

Relop           : T_LEQ | '<' | T_GT | T_GEQ | T_EQ | T_NEQ
                   ;

Additiveexpression : Term
                   | Additiveexpression Addop Term 
                   
                   ;

Addop           : '+' | '-'
                   ;

Term            : Factor
                   | Term Multop Factor 
                   
                   ;
/* added modulus as a multi operator */
Multop          : '*' | '/' | '%' | T_AND | T_OR | T_LEFTSHIFT | T_RIGHTSHIFT
                   ;

Factor          : T_ID
                   | MethodCall 
                   
                   | T_ID '[' Expr ']' 
                   
                   | Constant 
                   
                   | '(' Expr ')' 
                   
                   | '!' Factor 
                   
                   | '-' Factor 
                   
                   ;




ExternType     : T_STRINGTYPE { $$ = A_Decaf_STRING; }
                | Type 
                   
                ;

Type            : T_INTTYPE 
                { $$ = A_Decaf_INT;}
                | T_BOOLTYPE  
                { $$ = A_Decaf_BOOL;}
                ;

MethodType      : T_VOID  { $$ = A_Decaf_VOID; }
                | Type { $$ = $1;}
                   
                ;

BoolConstant   : T_TRUE 
                | T_FALSE 
                   
                ;

ArrayType      : '[' T_INTCONSTANT ']' Type
                  ;
/* added String and Char as constants */
Constant        : T_INTCONSTANT {
                        $$ = A_Decaf_INT;
                }
                
                | T_STRINGCONSTANT {
                        $$ = A_Decaf_STRING;
                }

                | T_CHARCONSTANT {
                        $$ = A_Decaf_CHAR;
                }

                | BoolConstant {
                        $$ = A_Decaf_BOOL;
                }
                   
                  ;
%%    /* end of rules, start of program */

int main(){
        
        yyparse();
        printf("parsing done\n");
        // We know PROGRAM points to our AST
        ASTprint(1, PROGRAM);
}
