/*
Ziad Arafat - Mar 8 2021
Lab 5
*/

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "ast.h"
#include "symtable.h"

int level = 0; // the level of the scope we are in. 
int offset = 0; // Keeps track of fielddecl offset values
int goffset = 0; // keeps track of 
int maxoffset;

int yylex();

extern int yylineno; // import the yylineno variable
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
        // changed these to output to stderr
  fprintf(stderr, "%s ", s);

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
        // uhh I noticed package name was in the output but cooper literally said
        // we don't wanna do that in the video so I just didn't lol. 
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
                // we need to see if $3 has already been defined.
                // if so => BARF
                if (Search($3, level, 0) != NULL) {
                        yyerror("Symbol already deafined");
                        yyerror($3);
                        exit(1);
                }
                $$ = ASTCreateNode(A_EXTERN);
                $$->name = $3;
                $$->A_Declared_Type = $7;
                $$->size = 0; 
                $$->S1 = $5; // set the S1 to the list of params node

                // set our symbol to the return value of Insert()
                $$->symbol = Insert($3,$7,ID_Sub_Type_Extern_Method, level, 0, 0, $5);
                // offset++;
                
                // moved to main
                Display(); // Display the table for debugging
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
                // Before we create the node let's check if the T_ID is used
                if (Search($2, level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror($2);
                        exit(1);
                }
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->A_Declared_Type = $3; 
                $$->size = 1; // scalars are size 1
                
                // insert the variable into the symtable
                $$->symbol = Insert($2,$3,ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }
        | T_VAR T_ID ArrayType ';' {
                // Before we create the node let's check if the T_ID is used
                if (Search($2, level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror($2);
                        exit(1);
                }
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->S1 = $3; // set S1 to the ArrayType
                $$->A_Declared_Type = $3->A_Declared_Type; // duplicate the type in the array
                $$->size = $3->size; // Arrays are based on the ArrayType value
                // insert the variable into the symtable
                $$->symbol = Insert($2,$3->A_Declared_Type,ID_Sub_Type_Array, level, $$->size, offset, NULL);
                offset += $3->size; // increment the offset by the size of the array.
        }
        | T_VAR T_ID Type T_ASSIGN Constant ';' {
                // we do the same thing in here that we did for the one without the T_ASSIGN

                // Before we create the node let's check if the T_ID is used
                if (Search($2, level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror($2);
                        exit(1);
                }
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->A_Declared_Type = $3; // set type to the Type output node 
                $$->size = 1; // this is still a scalar so we set size to 1. 
                $$->symbol = Insert($2,$3,ID_Sub_Type_Scalar, level,$$->size, offset, NULL);
                offset++; // increment offset by 1 because it's a scalar. 
                $$->S2 = $5; // set S2 to the Constant node

        };

MethodDecls: 
        /* empty */ {$$ = NULL;}
        | MethodDecl MethodDecls {
                $$ = $1;
                $$->next = $2; // set the next to the right recursive value
        };

MethodDecl: 
        // set global offset to offset them reset our offset
        // this way we resume global offsets and our offset is ready for next block
        T_FUNC T_ID { goffset = offset;  offset = 2; maxoffset = offset; } 
        '(' IdTypeList ')' MethodType 
        { Insert($2,$7,ID_Sub_Type_Method, level, 0, 0, $5); } Block {

                // increment anything greater than $2 by 1 for the new component
                $$ = ASTCreateNode(A_METHODDEC);
                $$->name = $2;
                $$->A_Declared_Type = $7;
                // $$->size = 1; changed to offset
                $$->S1 = $5; // $5;
                $$->S2 = $9; // $9;
                $$->symbol = Search($2, level, 0);
                $$->size = maxoffset;
                $$->symbol->mysize = maxoffset; // max size needed to run program
                offset = goffset;
        };

IdTypeList: 
        /* empty */ { $$ = NULL; }
        | IdTypeList1 { $$ = $1; };

IdTypeList1: 
        T_ID Type {
                // Before we create the node let's check if the T_ID is used
                if(Search ($1, level + 1, 0)!= NULL) {
                        yyerror("Duplicate method arg name");
                        yyerror($1);
                }
                
                $$ = ASTCreateNode(A_METHODID);
                $$->name = $1;
                $$->A_Declared_Type = $2;
                $$->size = 1;

                $$->symbol=Insert($1,$2,ID_Sub_Type_Scalar, level+1, 1, offset, NULL);
                offset++; // increment offset by 1 as per instructions
        }
        | T_ID Type ',' IdTypeList  {
                // Before we create the node let's check if the T_ID is used

                // check if there are duplicate args
                if(Search ($1, level + 1, 0)!= NULL) {
                        yyerror("Duplicate method arg name");
                        yyerror($1);
                }
                $$ = ASTCreateNode(A_METHODID);
                $$->name = $1;
                $$->A_Declared_Type = $2;
                $$->size = 1;

                // we do level + 1 because the args are part of the block created by the method. 
                $$->symbol=Insert($1,$2,ID_Sub_Type_Scalar, level+1, 1, offset, NULL);
                offset++; // increment offset by 1 as per instructions
                $$->next = $4;
        };

Block: 
        // increment level as soon as we open a block
        '{' { level++; } VarDecls Statements '}' {
                $$ = ASTCreateNode(A_BLOCK);

                // incremented these because added in-rule action
                $$->S1 = $3; // set S1 to the VarDecls
                $$->S2 = $4; // set S2 to the Statements
                Display(); // Display here so we can see the symtab at each level
                // if the offset is greater than the maxoffset of the method
                // then we set the maxoffset to the offset to fix it's max value
                if (offset > maxoffset) {
                        maxoffset = offset;
                }

                // We delete all the symbols at the current level before leaving. 
                // this way they don't conflict with levels lower. 
                offset -= Delete(level); 
                
                // decrement level since we finished the block
                level--;
                
        };

VarDecls: 
        /* empty */ { $$ = NULL; }
        | VarDecl VarDecls {
                $$ = $1;
                $$->next = $2;
        };

VarDecl: 
        T_VAR T_ID Type ';' {
                // Before we create the node let's check if the T_ID is used
                if (Search($2, level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror($2);
                        exit(1);
                }

                // Create an A_VARDEC node 
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2; // set it's name to T_ID
                $$->A_Declared_Type = $3; // set it's type to outpit of Type

                // insert the variable into the symtable
                $$->symbol = Insert($2,$3,ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
                // Display(); // debugging only 
        }
        | T_VAR T_ID ArrayType ';' {
                // Before we create the node let's check if the T_ID is used
                if (Search($2, level, 0) != NULL) {
                        yyerror("Variable already defined");
                        yyerror($2);
                        exit(1);
                }
                $$ = ASTCreateNode(A_VARDEC);
                $$->name = $2;
                $$->S1 = $3; // set S1 to the ArrayType node
                $$->A_Declared_Type = $3->A_Declared_Type;
                $$->size = $3->size; // set the size to the size of the ArrayType node

                // insert the variable into the symtable
                $$->symbol = Insert($2,$3->A_Declared_Type, ID_Sub_Type_Array, level, $$->size, offset, NULL);
                offset += $3->size; // increment offset by the size of the array.
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
                $$->S1 = $3; // set S1 to thje Expr
                $$->S2 = $5; // Set S2 to the Block
        };

BreakStmt: T_BREAK ';' { $$ = ASTCreateNode(A_BREAK); };

IfStmt: 
        T_IF '(' Expr ')' Block T_ELSE Block {
                $$ = ASTCreateNode(A_IF); 
                $$->S1 = $3; // set S1 to the Expression node
                $$->S2 = ASTCreateNode(A_IFBODY); // create a separate node for the body in S2
                $$->S2->S1 = $5;  // set the S1 of the body to the block of the IF
                $$->S2->S2 = ASTCreateNode(A_ELSE); // create a new node for the else statement after the body

                // set the S1 of the Else to the Else's Block
                $$->S2->S2->S1 = $7;
        }
        | T_IF '(' Expr ')' Block {
                $$ = ASTCreateNode(A_IF);

                // Set S1 to the Expression node
                $$->S1 = $3;
                $$->S2 = ASTCreateNode(A_IFBODY);  // create a separate node for the body in S2
                $$->S2->S1 = $5; // set the S1 of the body to the block
                $$->S2->S2 = NULL;  // since we have no Else we set it's node to NULL this time
        };

ReturnStmt: 
        T_RETURN ';' { $$ = ASTCreateNode(A_RETURN);}
        | T_RETURN '(' ')' ';'  { $$ = ASTCreateNode(A_RETURN);}
        | T_RETURN '(' Expr ')' ';' {
                $$ = ASTCreateNode(A_RETURN);
                $$->S1 = $3;  // set the S1 to the expression we returned
        };

Assign: 
        Lvalue T_ASSIGN Expr {

                // make sure the left and right hand types are matching
                if ( $1->A_Declared_Type != $3->A_Declared_Type) {
                        yyerror("Type mismatch on assignment");
                        exit(1);
                }
                $$ = ASTCreateNode(A_ASSIGN);
                $$->S1 = $1; // set the S1 to the left hand side 
                $$->S2 = $3; // set the S2 to the right hand side
        };

/* Assigns: Assign
                   | Assign ',' Assigns 
                   
                   ; */

Lvalue: 
        T_ID {
                /* I am using A_VAR_RVALUE for both the LVALUE and RVALUE
                Mostly because the node serves the same purpose.
                 */

                /* well apparently that was wrong so I changed to a new 
                   node type LVALUE which now has it's own case and enum
                */

                // grab the symbol from the table corresponding the T_ID
                struct SymbTab *p; 
                p = Search($1, level, 1);

                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror($1);
                        exit(1);
                }
                
                // Make sure the type is a scalar and not an array/method
                if (p->SubType != ID_Sub_Type_Scalar){
                        yyerror($1);
                        yyerror("needs to be a scalar, wrong subtype");
                        exit(1);
                }

                $$ = ASTCreateNode(A_VAR_LVALUE);
                $$->name = $1;
                $$->symbol = p;
                $$->A_Declared_Type = p->Type;
        } 
        | T_ID '[' Expr ']' {
                struct SymbTab *p;
                p = Search($1, level, 1);

                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror($1);
                        exit(1);
                }
                
                // Make sure it's an array and not a Scalar/Method
                if (p->SubType != ID_Sub_Type_Array){
                        yyerror($1);
                        yyerror("needs to be an array, wrong subtype");
                        exit(1);
                }
                $$ = ASTCreateNode(A_VAR_LVALUE);
                $$->name = $1;
                $$->S1 = $3;
                $$->symbol = p;
                $$->A_Declared_Type = p->Type; // the type is the same as the symbol we got it from
        };


MethodCall: 
        T_ID '(' MethodArgs ')' {
                 struct SymbTab *p;
                p = Search($1, level, 1);
                
                // if we didn't find one lets barf because it wasnt defined
                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror($1);
                        exit(1);
                }

                // Make sure it's a Method or Extern Method and not an Array/Scalar
                if ((p->SubType != ID_Sub_Type_Method) && (p->SubType != ID_Sub_Type_Extern_Method)){
                        yyerror($1);
                        yyerror("needs to be a method, wrong subtype");
                        exit(1);
                }

                // check that the formal params match the params of the method
                // definition

                if (check_parameters(p->fparms, $3) == 0) {
                        yyerror("Formal and actual params do not match");
                        yyerror($1);
                        exit(1);
                }
                
                $$ = ASTCreateNode(A_METHODCALL);
                $$->name = $1;
                $$->S1 = $3;
                $$->symbol = p;
                $$->A_Declared_Type = p->Type; // type matches it's formal type
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

                // make type of left is type of right 
                if (($1->A_Declared_Type != $3->A_Declared_Type)) {
                        yyerror("both sides need to be the same type");
                        exit(1);
                }
                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1; // set S1 to left hand side 
                $$->operator = $2; // set the operator to return of Relop
                $$->S2 = $3; // set S2 to the right hand side
                $$->A_Declared_Type = $1->A_Declared_Type; // duplicate the type from one of the left or right (left)
                $$->name = TEMP_CREATE(); // create a temporary symbol to hold value
                $$->symbol = Insert($$->name,$$->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);

                // increment offset by 1 because of the temporary value being stored
                offset++;
                
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
        if (($1->A_Declared_Type != $3->A_Declared_Type) ||
	    (check_operators($2, $1->A_Declared_Type) == 0)) {
		yyerror("addition and subtraction need INTs only");
		exit(1);
	}
                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1;
                $$->operator = $2;
                $$->S2 = $3;
                $$->A_Declared_Type = A_Decaf_INT;
                $$->name = TEMP_CREATE();
                $$->symbol = Insert($$->name,$$->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        };

Addop: 
        '+' { $$ = A_PLUS; } 
        | '-' { $$ = A_MINUS; };
                   
Term: 
        Factor { $$ = $1; }
        | Term Multop Factor {
                // check that left is equal to right
                if ($1->A_Declared_Type != $3->A_Declared_Type) {
                        yyerror("type mismatch");
                        exit(1);
                }

                // use my check_operators() function to make sure the operator
                // is compatible with the types
                if (check_operators($2, $1->A_Declared_Type) == 0) {
                        if($1->A_Declared_Type == A_Decaf_BOOL) {
                                yyerror("Cannot use BOOL in INT operation");
                        } else {
                                yyerror("Cannot use INT in BOOL operation");
                        }
                        exit(1);
                }

                $$ = ASTCreateNode(A_EXPR);
                $$->S1 = $1;
                $$->operator = $2;
                $$->S2 = $3;
                $$->name = TEMP_CREATE();
                $$->symbol = Insert($$->name,$$->A_Declared_Type, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
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
                struct SymbTab *p;
                p = Search($1, level, 1);

                if(p == NULL) {
                        yyerror("Symbol on LVALUE not defined");
                        yyerror($1);
                        exit(1);
                }

                if (p->SubType != ID_Sub_Type_Scalar){
                        yyerror($1);
                        yyerror("needs to be an scalar, wrong subtype");
                        exit(1);
                }
                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;
                $$->symbol = p;
                $$->A_Declared_Type = p->Type;

        }
        | MethodCall { $$ = $1; }
        | T_ID '[' Expr ']' {
                struct SymbTab *p;
                p = Search($1, level, 1);
                if(p == NULL) {
                        yyerror("Symbol on RVALUE not defined");
                        yyerror($1);
                        exit(1);
                }

                if (p->SubType != ID_Sub_Type_Array){
                        yyerror($1);
                        yyerror("needs to be an array, wrong subtype");
                        exit(1);
                }

                $$ = ASTCreateNode(A_VAR_RVALUE);
                $$->name = $1;
                $$->S1 = $3;
                $$->symbol = p;
                $$->A_Declared_Type = p->Type;
        }
        | Constant { $$ = $1; }
        | '(' Expr ')' { $$ = $2; }
        | '!' Factor {

                // check if our right is a bool
                if ($2->A_Declared_Type != A_Decaf_BOOL) {
                        yyerror("Type mismatch, expected boolean");
                        exit(1);
                }

                $$ = ASTCreateNode(A_EXPR);
                $$->operator = A_NOT;
                $$->S1 = $2;

                // set type to boolean because !bool is a bool 
                $$->A_Declared_Type = A_Decaf_BOOL;

                $$->name = TEMP_CREATE();
                $$->symbol = Insert($$->name,A_Decaf_BOOL, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
        }

        /* moved this around a lot until I got it working in here */
        | T_STRINGCONSTANT {
                $$ = ASTCreateNode(A_CONSTANT_STRING);
                $$->name = $1;
                $$->A_Declared_Type = A_Decaf_STRING;
        }
        | '-' Factor {
                // check if our right is an int
                if ($2->A_Declared_Type != A_Decaf_INT) {
                        yyerror("Type mismatch, expected integer");
                        exit(1);
                }
                $$ = ASTCreateNode(A_EXPR);
                $$->operator = A_UMINUS;
                $$->S1 = $2;
                // set type to boolean because UMINUS is for numbers 
                $$->A_Declared_Type = A_Decaf_INT;
                $$->name = TEMP_CREATE();
                $$->symbol = Insert($$->name,A_Decaf_BOOL, ID_Sub_Type_Scalar, level, 1, offset, NULL);
                offset++;
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
        $$->A_Declared_Type = A_Decaf_BOOL;
        }
        | T_FALSE {
        $$ = ASTCreateNode(A_CONSTANT_BOOL);
        $$->value = 0;
        $$->A_Declared_Type = A_Decaf_BOOL;
        };

ArrayType: 
        '[' T_INTCONSTANT ']' Type {
                $$ = ASTCreateNode(A_ARRAYTYPE);
                $$->value = $2;
                $$->A_Declared_Type = $4;
                $$->size = $2;
                // printf("THE SIZE IS %d %d", $2, $$->size);// debug 
        };
/* added String and Char as constants */
Constant: 
        T_INTCONSTANT {
                $$ = ASTCreateNode(A_CONSTANT_INT);
                $$->value = $1;
                $$->A_Declared_Type = A_Decaf_INT;
        }

        | BoolConstant {
                $$ = $1;
        };
%%    /* end of rules, start of program */

int main(){
        yyparse();
        printf("Parsing completed\n");
        Display(); // I noticed in cooper's output he Displays after the printf
        // We know PROGRAM points to our AST
        ASTprint(0, PROGRAM);
        printf("Finished printing AST ");
}