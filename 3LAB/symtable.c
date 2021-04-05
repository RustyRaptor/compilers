/*
 * Ziad Arafat
 * Feb 15 2021
 * Setup and understand symbol table tool functions in c
 * 
 * Changes:
 *      - reformated document with clang-format
 *      - Moved all the prototypes and globals into symtable.h
 *      - Commented the .h file
 *      - Commented the .c file
 *      - Reformatted printfs to reflect what the output will look like 
 *      - Added description of the data structure used.
 *      - Changed SymTab to use a char pointer for symbol
 *      - Changed all code to handle char pointed instead of label char array
 *      - Made all functions non-interactive with parameters. 
 *      - Adjusted main code to pass inputs to the functions
 * 
 * The main data structure in this code is a linked list. It's called SymTab. 
 * It has 3 main fields. The label-symbol strings, the address integer, and the
 * next pointer. 
 * 
 * The label and symbol are just a name and the symbol itself we are storing. 
 * The address is an integer storing the address of the symbol. 
 * 
 * The next pointer is just a pointer that points to the next Node which is
 * another instance of SymTab so it is recursive in the sense that the struct
 * uses a pointer to an instance of itself. 
 */

#include "symtable.h"

int size = 0; // stores the current size of the symtable

// moved the prototypes and struct definition to symtable.h

struct SymbTab *first, *last; // Initialize our head and tail of the linked list

/*
 * The main function will display a text menu with numbers corresponding to
 * each option. It takes inputs from  user and passes them to the respective
 * function and displays results.
 */
int main()
{
	int op, y;

	// removed label
	// added symbol string with size 100
	char sym[100];
	int addr = 0; // added variable to store address input

	do {
		printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");

		printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.END\n");

		printf("\n\tEnter your option : ");

		scanf("%d", &op); // Get the user input

		switch (op) {
		case 1:
			// added prompt to get symbol and address from user
			printf("Enter a symbol to INSERT: \n");
			scanf("%s", sym);

			printf("Enter an address to INSERT:\n");
			scanf("%d", &addr);

			// Pass inputs to Insert();
			Insert(sym, addr);
			break;
		case 2:
			Display();
			break;
		case 3:
			// added prompt to get symbol and address from user
			printf("Enter a symbol to DELETE: \n");
			scanf("%s", sym);

			// pass sym input to Delete()
			Delete(sym);
			break;
		case 4:
			printf("\n\tEnter the symbol to be SEARCHED : ");
			scanf("%s", sym); // search sym instead of label

			y = Search(sym);

			printf("\n\tSearch Result:");
			if (y == 1) {
				printf("\n\tThe symbol is present in the symbol table\n");
			} else {
				printf("\n\tThe symbol is not present in the symbol table\n");
			}
			break;
		case 5:
			exit(0);
		}
	} while (op < 6);
}

/*
 * Insert() 
 * Inputs:
 *      char *sym: the symbol we want to add to the table
 *      int address: the address for the symbol we are adding.
 * 
 * Inserts a new symbol-address pair to the symbol table if the symbol isn't
 * already there.
 */
void Insert(char *sym, int address)
{
	int n;

	n = Search(sym);
	// remove prompt for input
	if (n == 1) {
		printf("\n\tThe symbol exists already in the symbol table\n\tDuplicate can't be inserted");
	} else {
		struct SymbTab *p;

		p = malloc(sizeof(struct SymbTab));

		// remove user input
		p->symbol = strdup(sym); // copy symbol to new node
		p->addr = address; // add address to new node

		p->next = NULL;

		if (size == 0) {
			first = p;
			last = p;
		} else {
			last->next = p;
			last = p;
		}

		size++;
	}
	printf("\n\tLabel inserted\n");
}

/*
 * Display() 
 * Uses a cursor node to traverse the symtable and display the contents of
 * each entry.
 */
void Display()
{
	struct SymbTab *p;
	p = first;

	printf("\n\tSYMBOL\t\tADDRESS\n"); // remove LABEL in print
	for (int i = 0; i < size; i++) {
		// removed the label value from the print
		printf("\t%s\t\t%d\n", p->symbol, p->addr);
		p = p->next;
	}
}

/*
 * Search()
 * Input: symbol, the symbol to search for
 * Output: 1 if the symbol was found. 0 if it wasn't. 
 * 
 * Traverses the linked list until it finds the symbol
 */
int Search(char *symbol) // changed input to symbol char pointer
{
	int i, flag = 0;
	struct SymbTab *p;
	p = first;
	for (i = 0; i < size; i++) {
		// Changed label to symbol
		if (strcmp(p->symbol, symbol) == 0) {
			flag = 1;
		}
		p = p->next;
	}
	return flag;
}

// Removed Modify()

/*
 * Delete()
 * Input: sym, the symbol to delete from the table
 * 
 * Deletes a symbol from the table using a cursom and redirecting the next
 * pointer of a node.
 */
void Delete(char *sym)
{
	int a;
	// removed char array
	struct SymbTab *p, *q;
	p = first;

	// removed print and scanf

	a = Search(sym);
	if (a == 0)
		printf("\n\tLabel not found\n");
	else {
		// replaced label with symbol
		if (strcmp(first->symbol, sym) == 0)
			first = first->next;
		// replaced label with symbol
		else if (strcmp(last->symbol, sym) == 0) {
			q = p->next;
			// replaced label with symbol
			while (strcmp(q->symbol, sym) != 0) {
				p = p->next;
				q = q->next;
			}
			p->next = NULL;
			last = p;
		} else {
			q = p->next; // replaced label with symbol
			while (strcmp(q->symbol, sym) != 0) {
				p = p->next;
				q = q->next;
			}
			p->next = q->next;
		}
		size--;
		printf("\n\tAfter Deletion:\n");
		Display();
	}
}
