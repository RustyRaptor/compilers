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
    enum AST_Operators operator;
}


// I commented out the tokens that aren't being used.

// I also removed the token for T_LT because idk why one was a token and the 
// other was a char??


// Added a token for each of the lex tokens
%token T_AND
%token T_ASSIGN
%token T_BOOLTYPE
%token T_BREAK
/* %token T_CHARCONSTANT */
%token T_CONTINUE
/* %token T_DOT */
%token T_ELSE
%token T_EQ
%token T_EXTERN
%token T_FALSE
/* %token T_FOR */
%token T_FUNC
%token T_GEQ
/* %token T_GT */
%token <string> T_ID
%token T_IF
%token <value> T_INTCONSTANT
%token T_INTTYPE
%token T_LEFTSHIFT
%token T_LEQ
%token T_NEQ
/* %token T_NULL */
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

%type <astnode> Externs ExternDefn FullExternParmList ExternParmList FieldDecl
%type <astnode> FieldDecls ArrayType MethodDecl MethodDecls Block VarDecl
%type <astnode> IdTypeList IdTypeList1 VarDecls Statement Statements ReturnStmt
%type <astnode> Constant BoolConstant BreakStmt Additiveexpression Term
%type <astnode> Factor Simpleexpression Expr Assign Lvalue IfStmt WhileStmt
%type <astnode> MethodCall MethodArgs FullMethodArgs MethodArg ContinueStmt
%type <asttype> MethodType Type ExternType 
%type <operator> Multop Addop Relop


/* added all the rules from DECAF and reformatted them to work with Bison */
/* for each of the rules with a list of tokens I created a recursive rule
that allows for one or more of the token. 
*/

/* Replaced any instance of '=' with T_ASSIGN */

%%    /* end specs, begin rules */
Program: 
        Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}' {
                PROGRAM = ASTCreateNode(A_PROGRAM);
                PROGRAM->S1 = $1;
                PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
                PROGRAM->S2->name = $3;
                PROGRAM->S2->S1 = $5; 
                PROGRAM->S2->S2 = $6;
        };

Externs: 
        /* empty */ { $$ = NULL; }
        | ExternDefn Externs { $1->next = $2; };

ExternDefn: 
        T_EXTERN T_FUNC T_ID '(' ExternParmList ')' MethodType ';' {
                $$ = ASTCreateNode(A_EXTERN);
                $$->name = $3;
                $$->A_Declared_Type = $7; 
                $$->S1 = $5;
        };

ExternParmList: 
        /* empty */  { $$ = NULL; }
        | FullExternParmList {$$ = $1;} ;

FullExternParmList: 
        ExternType {
                $$ = ASTCreateNode(A_ExternType);
                $$->A_Declared_Type = $1;
        }
        | ExternType ',' ExternParmList {
                $$ = ASTCreateNode(A_ExternType);
                $$->A_Declared_Type = $1;
                $$->next = $3;
        };

FieldDecls:
        /* empty */ {$$ = NULL;}
        | FieldDecl FieldDecls {
                $$ = $1;
                $$->next = $2;
        };

FieldDecl: 
        T_VAR T_ID Type ';' {
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->A_Declared_Type = $3; 

        }
        | T_VAR T_ID ArrayType ';' {
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->S1 = $3;
                $$->A_Declared_Type = $3->A_Declared_Type;

        }
        | T_VAR T_ID Type T_ASSIGN Constant ';' {
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->A_Declared_Type = $3;
                $$->S2 = $5;

        };

MethodDecls: 
        /* empty */ {$$ = NULL;}
        | MethodDecl MethodDecls {
                $$ = $1;
                $$->next = $2;
        };

MethodDecl: 
        T_FUNC T_ID '(' IdTypeList ')' MethodType Block {
                $$ = ASTCreateNode(A_METHODDEC);
                $$->name = $2;
                $$->A_Declared_Type = $6;
                $$->S1 = $4; // $4;
                $$->S2 = $7; // $7;
        };

IdTypeList: 
        /* empty */ { $$ = NULL; }
        | IdTypeList1 { $$ = $1; };

IdTypeList1: 
        T_ID Type {
                $$ = ASTCreateNode(A_METHODID);
                $$->name = $1;
                $$->A_Declared_Type = $2;
        }
        | T_ID Type ',' IdTypeList  {
                $$ = ASTCreateNode(A_METHODID);
                $$->name = $1;
                $$->A_Declared_Type = $2;
                $$->next = $4;
        };

Block: 
        '{' VarDecls Statements '}' {
                $$ = ASTCreateNode(A_BLOCK);
                $$->S1 = $2;
                $$->S2 = $3;
        };

VarDecls: 
        /* empty */ { $$ = NULL; }
        | VarDecl VarDecls {
                $$ = $1;
                $$->next = $2;
        };

VarDecl: 
        T_VAR T_ID Type ';' {
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->A_Declared_Type = $3;
        }
        | T_VAR T_ID ArrayType ';' {
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->S1 = $3;
                $$->A_Declared_Type = $$->S1->A_Declared_Type;
        };

Statements: 
        /* empty */ { $$ = NULL; }
        | Statement Statements {
                $$ = $1;
                $$->next = $2;
        };

/* Moved all of the Statement into one rule and moved each item into it's own
separate rule.
 */
 /* Connected  these all */
Statement: 
        Block { $$ = $1; }
        | Assign ';' { $$ = $1; }
        | MethodCall ';' { $$ = $1; }
        | IfStmt { $$ = $1; }
        | WhileStmt { $$ = $1; }
        | ReturnStmt { $$ = $1; }
        | BreakStmt { $$ = $1; }
        | ContinueStmt { $$ = $1; }
        ;

/* Created a continue statement idk if this was needed */
ContinueStmt: T_CONTINUE  ';' {$$ = ASTCreateNode(A_CONTINUE);};

WhileStmt: 
        T_WHILE '(' Expr ')' Block {
                $$ = ASTCreateNode(A_WHILESTMT);
                $$->S1 = $3;
                $$->S2 = $5;
        };

BreakStmt: T_BREAK ';' { $$ = ASTCreateNode(A_BREAK); };

IfStmt: 
        T_IF '(' Expr ')' Block T_ELSE Block {
                $$ = ASTCreateNode(A_IF);
                $$->S1 = $3;
                $$->S2 = ASTCreateNode(A_IFBODY);
                $$->S2->S1 = $5;
                $$->S2->S2 = ASTCreateNode(A_ELSE);
                $$->S2->S2->S1 = $7;
        }
        | T_IF '(' Expr ')' Block {
                $$ = ASTCreateNode(A_IF);
                $$->S1 = $3;
                $$->S2 = ASTCreateNode(A_IFBODY);
                $$->S2->S1 = $5;
                $$->S2->S2 = NULL;
        }
        ;

ReturnStmt: 
        T_RETURN ';' { $$ = ASTCreateNode(A_RETURN);}
        | T_RETURN '(' ')' ';'  { $$ = ASTCreateNode(A_RETURN);}
        | T_RETURN '(' Expr ')' ';' {
                $$ = ASTCreateNode(A_RETURN);
                $$->S1 = $3; 
        };

Assign: 
        Lvalue T_ASSIGN Expr {
                $$ = ASTCreateNode(A_ASSIGN);
                $$->S1 = $1;
                $$->S2 = $3;
        };

/* Assigns: Assign
                   | Assign ',' Assigns 
                   
                   ; */

Lvalue: 
        T_ID {
                /* I am using A_VAR_RVALUE for both the LVALUE and RVALUE
                Mostly because the node serves the same purpose.
                 */
                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;
        } 
        | T_ID '[' Expr ']' {
                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;
                $$->S1 = $3;
        };


MethodCall: 
        T_ID '(' MethodArgs ')' {
                $$ = ASTCreateNode(A_METHODCALL);
                $$->name = $1;
                $$->S1 = $3;
        };

MethodArg: Expr { $$ = $1; };

MethodArgs:
        /* empty */ {
                $$ = NULL;
        }
        | FullMethodArgs {
                $$ = $1;
        };

FullMethodArgs: 
        MethodArg {
                $$ = $1;
        }
        | MethodArg ',' MethodArgs {
                $$ = $1;
                $$->next = $3;
        }
        ;




/* Statement: T_FOR '(' Assigns ';' Expr ';' Assigns ')' Block
                   ; */





Expr: Simpleexpression { $$ = $1; };

Simpleexpression:
        Additiveexpression { $$ = $1; }
        | Simpleexpression Relop Additiveexpression {
                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1;
                $$->operator = $2;
                $$->S2 = $3;
        };

Relop:
        '<'     { $$ = A_LT; }
        | '>'   { $$ = A_GT; }
        | T_EQ  { $$ = A_EQ; }
        | T_LEQ { $$ = A_LEQ; }
        | T_GEQ { $$ = A_GEQ; }
        | T_NEQ { $$ = A_NEQ; };

Additiveexpression:
        Term { $$ = $1; }
        | Additiveexpression Addop Term {
                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1;
                $$->operator = $2;
                $$->S2 = $3;
        };

Addop: 
        '+' { $$ = A_PLUS; } 
        | '-' { $$ = A_MINUS; };
                   
Term: 
        Factor { $$ = $1; }
        | Term Multop Factor {
                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1;
                $$->operator = $2;
                $$->S2 = $3;
        };
/* added modulus as a multi operator */
Multop: 
        '*' { $$ = A_TIMES; }
        | '/' { $$ = A_DIVIDE; }
        | '%' { $$ = A_MOD; }
        | T_AND { $$ = A_AND; }
        | T_OR { $$ = A_OR; }
        | T_LEFTSHIFT { $$ = A_LEFTSHIFT; }
        | T_RIGHTSHIFT { $$ = A_RIGHTSHIFT; };

Factor: 
        T_ID {
                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;

        }
        | MethodCall { $$ = $1; }
        | T_ID '[' Expr ']' {
                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;
                $$->S1 = $3;
        }
        | Constant { $$ = $1; }
        | '(' Expr ')' { $$ = $2; }
        | '!' Factor {
                $$ = ASTCreateNode(A_EXPR);
                $$->operator = A_NOT;
                $$->S1 = $2;
        }
        /* moved this around a lot until I got it working in here */
        | T_STRINGCONSTANT {
                $$ = ASTCreateNode(A_CONSTANT_STRING);
                $$->name = $1;
        }
        | '-' Factor {
                $$ = ASTCreateNode(A_EXPR);
                $$->operator = A_UMINUS;
                $$->S1 = $2;
        };




ExternType:
        T_STRINGTYPE { $$ = A_Decaf_STRING; }
        | Type 
        ;

Type: 
        T_INTTYPE { $$ = A_Decaf_INT; }
        | T_BOOLTYPE{ $$ = A_Decaf_BOOL; };

MethodType: 
        T_VOID { $$ = A_Decaf_VOID; }
        | Type { $$ = $1; };

BoolConstant: 
        T_TRUE {
        $$ = ASTCreateNode(A_CONSTANT_BOOL);
        $$->value = 1;
        }
        | T_FALSE {
        $$ = ASTCreateNode(A_CONSTANT_BOOL);
        $$->value = 0;
        };

ArrayType: 
        '[' T_INTCONSTANT ']' Type {
                $$ = ASTCreateNode(A_ARRAYTYPE);
                $$->value = $2;
                $$->A_Declared_Type = $4;
        }
                  ;
/* added String and Char as constants */
Constant: 
        T_INTCONSTANT {
                $$ = ASTCreateNode(A_CONSTANT_INT);
                $$->value = $1;
        }

        | BoolConstant {
                $$ = $1;
        };
%%    /* end of rules, start of program */

int main(){
        yyparse();
        printf("Parsing completed\n");
        // We know PROGRAM points to our AST
        ASTprint(0, PROGRAM);
        printf("Finished printing AST ");
}