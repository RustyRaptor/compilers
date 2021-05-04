# Ziad Arafat
# Lab9 MIPS Code Generation from AST.c
# April 2021

# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic 

# Entry point target
all: lab9

# Compile all the THINGS!
lab9: lab9.l lab9.y ast.c ast.h symtable.c symtable.h emit.c emit.h
	lex lab9.l
	yacc -d --verbose --debug lab9.y
	gcc $(FLAGS) y.tab.c lex.yy.c ast.c symtable.c emit.c -o lab9 -lm

# remove the binary and other generated stuff
clean:
	rm lab9 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab9 -s

# executes our code to test it's functionality
test:
	./lab9 < testinput.txt