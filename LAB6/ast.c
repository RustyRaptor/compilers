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
	// MISSING
}

void AST_Print_Type(enum AST_Decaf_Types t)
{
	switch (t) {
	case A_Decaf_INT:
		printf(" INT ");
		break;
	case A_Decaf_BOOL:
		printf(" BOOL ");
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
		case A_PROGRAM:
			printf("PROGRAM \n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 1, p->S2);
			break;
		case A_EXTERN:
			printf("EXTERN FUNC %s ", p->name);
			printf(" ( ");
			ASTprint(level + 1, p->S1);
			printf(" ) ");
			AST_Print_Type(p->A_Declared_Type);
			printf("\n");
			break;

		case A_PACKAGE:
			printf("PACKAGE %s", p->name);
			printf("{\n");
			ASTprint(level + 1, p->S1);
			ASTprint(level + 1, p->S2);
			printf("}\n");
			break;
		case A_ExternType:
			printf("ExternType ");
			AST_Print_Type(p->A_Declared_Type);

			break;
		case A_VARDEC:
			printf("Variable ");
			printf(" %s", p->name);

			if (p->S1 != NULL) {
				printf("[ ");
				printf("%d", p->S1->value);
				printf(" ] ");
			}
			AST_Print_Type(p->A_Declared_Type);
			printf(" ");
			if (p->S1 == NULL) {
				printf("= %d", p->value);
			}
			printf("\n");
			// ASTprint(level, p->S1);
			break;
		case A_METHODDEC:
			printf("Method '%s' with type ", p->name);
			AST_Print_Type(p->A_Declared_Type);
			/* print out the parameter list */
			if (p->S1 == NULL) {
				PT(level + 2);
				printf(" (NONE) ");
			} else {
				PT(level + 2);
				printf("( ");
				ASTprint(level + 2, p->S1);
				PT(level + 2);
				printf(" ) ");
			}
			printf("\n");
			ASTprint(level + 2, p->S2); // print out the block
			break;

		case A_METHODID:
			printf("Method Variable");
			printf(" %s", p->name);
			AST_Print_Type(p->A_Declared_Type);
			// printf("\n");

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
			}
			printf("\n");
			ASTprint(level + 1, p->S1);
			if (p->operator!= A_NOT)
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
		case A_NUMBER:
			printf("NUMBER with value %d\n", p->value);
			ASTprint(level + 1, p->S1);
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
