

/*
 *  CS370 - Lab 3
 *  Program name: Symtable
 *  Purpose of program: Implements Symbol Table
 *  written by: Ziad Arafat
 *  Date Written: 2020-02-15
 */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#ifndef SYMTABLE_H
#define SYMTABLE_H

/*
 * Insert()
 * Inputs:
 *      char *sym: a pointer to the symbol char array we want to insert
 *      int address: an integer address to pair with the symbol
 */
void Insert(char *sym, int address); // insert a symbol, and address

void Display(); // Display the symboltable

/*
 * Delete()
 * Input char sym: a pointer to the symbol char array we want to remove
 */
void Delete(char *sym);

// search for a symbol in the table and return weather it was found
int Search(char * sym); // changed input to symbol

// removed Modify

/*
 * Structure for our linked list that stores the symbol table. 
 * Contains a char pointer to a symbol, an integer with the address
 * and a pointer to the next SymTab node
 */
struct SymbTab {
	char *symbol; // arrays storing the label and symbol data

	int addr; // integer storing the address

	struct SymbTab *next; // points to the next node
};

#endif