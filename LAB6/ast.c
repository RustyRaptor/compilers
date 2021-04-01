/*   Abstract syntax tree code

     This code is used to define an AST node, 
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper February 2020

*/

#include <stdio.h>
#include <malloc.h>
#include "ast.h"

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum AST_Tree_Element_Type mytype)
{
	ASTnode *p;
	if (mydebug)
		fprintf(stderr, "Creating AST Node \n");
	p = (ASTnode *)malloc(sizeof(ASTnode)); // get head data
	p->type = mytype; // set up the Element type
	p->S1 = NULL;
	p->S2 = NULL; // det default values
	p->value = 0;
	return (p);
}

/*  Helper function to print tabbing */

void PT(int howmany)
{
	for (int i = 0; i < howmany; i++) {
		printf(" ");
	}
}

void AST_Print_Type(enum AST_Decaf_Types t)
{
	switch (t) {
	case A_Decaf_INT:
		printf(" INT ");
		break;
	case A_Decaf_BOOL:
		printf(" BOOLEAN ");
		break;
	case A_Decaf_STRING:
		printf(" STRING ");
		break;
	case A_Decaf_VOID:
		printf(" VOID ");
		break;
	default:
		fprintf(stderr, "Unknown AST DECAF TYPE !!!\n");
	} // of switch

} // of AST_Print_Type

/*  Print out the abstract syntax tree */
void ASTprint(int level, ASTnode *p)
{
	int i;
	if (p == NULL)
		return;
	else {
		PT(level); /*indent */
		switch (p->type) {
		case A_VAR_RVALUE:
			printf("Variable %s \n", p->name);
                        if (p->S1 != NULL) {
                                PT(level + 2);
                                printf("[\n");
                                ASTprint(level+2, p->S1);
                                PT(level + 2);
                                printf("]\n");
                        }
			break;
		case A_PROGRAM:
			// printf("PROGRAM \n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 1, p->S2);
			break;
		case A_EXTERN:
			printf("EXTERN FUNC %s\n", p->name);
			// printf("\n");
			ASTprint(level + 1, p->S1);
			// printf("\n");
			
			printf("END EXTERN with Type:\n ");
                        AST_Print_Type(p->A_Declared_Type);
			break;

		case A_PACKAGE:
			printf("Package : %s\n", p->name);
                        PT(level + 2);
			// printf("{\n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 1, p->S2);
                        PT(level + 2);
			printf("\n");
			break;
		case A_ExternType:
			printf("EXTERN Type ");
			AST_Print_Type(p->A_Declared_Type);
                        printf("\n");

			break;
		case A_VARDEC:
			printf("Variable ");
			printf(" %s", p->name);

			if (p->S1 != NULL) {
				printf("[");
				printf("%d", p->S1->value);
				printf("] ");
			}
                        printf(" with type ");
			AST_Print_Type(p->A_Declared_Type);
			printf(" ");
			if (p->S2 != NULL) {
				printf("= %d", p->S2->value);
			}
			printf("\n");
			// ASTprint(level, p->S1);
			break;
		case A_METHODDEC:
			printf("METHOD FUNCTION  '%s' with type ", p->name);
			AST_Print_Type(p->A_Declared_Type);
			/* print out the parameter list */
			if (p->S1 == NULL) {
				printf("\n");
				PT(level + 2);
				printf(" (NONE) ");
			} else {
				printf("\n");
				PT(level + 2);
				printf("(\n");
				ASTprint(level + 2, p->S1);
				PT(level + 2);
				printf(")");
			}
			printf("\n");
			ASTprint(level + 2, p->S2); // print out the block
			break;

		case A_METHODID:
			printf("Method Variable");
			printf(" %s", p->name);
			AST_Print_Type(p->A_Declared_Type);
			printf("\n");

			break;
		case A_PARAM:
			printf("PARAMETER ");
			if (p->operator== A_Decaf_INT)
				printf(" INT ");
			if (p->operator== A_Decaf_BOOL)
				printf(" VOID ");
			if (p->operator== A_Decaf_VOID)
				printf(" BOOLEAN ");
			printf("%s ", p->name);
			if (p->value == -1)
				printf("[]");
			ASTprint(level + 2, p->S1);
			printf("\n");
			break;
		case A_EXPR:
			printf("EXPR ");
			switch (p->operator) {
			case A_PLUS:
				printf(" + ");
				break;
			case A_MINUS:
				printf(" - ");
				break;
			case A_DIVIDE:
				printf(" / ");
				break;
			case A_EQ:
				printf(" == ");
				break;
			case A_LEQ:
				printf(" <= ");
				break;
			case A_GEQ:
				printf(" >= ");
				break;
			case A_GT:
				printf(" > ");
				break;
			case A_LT:
				printf(" < ");
				break;
			case A_LEFTSHIFT:
				printf(" << ");
				break;
			case A_RIGHTSHIFT:
				printf(" >> ");
				break;
			case A_MOD:
				printf(" %% ");
				break;
			case A_AND:
				printf(" && ");
				break;
			case A_OR:
				printf(" || ");
				break;
			case A_NEQ:
				printf(" != ");
				break;
			case A_TIMES:
				printf(" * ");
				break;
			case A_NOT:
				printf(" !");
				break;
			case A_UMINUS:
				printf(" Unary Minus");
				break;
			default:
				printf("Unknown EXPR Operator");
			}
			printf("\n");
			ASTprint(level + 1, p->S1);
			if (p->operator!= A_NOT && p->operator != A_UMINUS)
				ASTprint(level + 1, p->S2);
			break;
		case A_BLOCK:
			printf("BLOCK STATEMENT \n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 1, p->S2);
			break;
		case A_WHILESTMT:
			printf("WHILE STATEMENT \n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 2, p->S2);
			break;

		case A_CONSTANT_INT:
			printf("CONSTANT INTEGER  %d\n", p->value);
			break;
                case A_CONSTANT_STRING:
			printf("CONSTANT STRING  %s\n", p->name);
			break;
                        
		case A_CONSTANT_BOOL:
			printf("CONSTANT BOOLEAN  ");
			if (p->value == 1) {
				printf("true\n");
			} else {
				printf("false\n");
			}
			break;
		case A_BREAK:
			printf("BREAK STATEMENT   \n");
			break;
		case A_RETURN:
			printf("RETURN STATEMENT   \n");
			ASTprint(level + 1, p->S1);
			break;
                case A_ASSIGN:
			printf("ASSIGNMENT STATEMENT\n");
			ASTprint(level + 1, p->S1);
                        ASTprint(level + 1, p->S2);
			break;
                case A_IF:
                        printf("IF STATEMENT   \n");
			ASTprint(level + 1, p->S1);
                        ASTprint(level + 1, p->S2);
			break;
                case A_IFBODY:
                        // printf("IF BODY   \n");
			ASTprint(level + 1, p->S1);
                        ASTprint(level + 1, p->S2);
			break;
                
                case A_ELSE:
                        printf("ELSE   \n");
			ASTprint(level + 1, p->S1);
			break;
                case A_METHODCALL:
                        printf(" METHOD CALL name: %s\n", p->name);
                        PT(level);
                        printf("(\n");
                        printf("METHOD ARG \n");
			ASTprint(level + 1, p->S1);
                        PT(level);
                        printf(")\n");
			break;

		default:
			printf("unknown type in ASTprint\n");
		}
		ASTprint(level, p->next);
	}
}

/* dummy main program so I can compile for syntax error independently   
 */
// void main()
// {
// }
/* */
