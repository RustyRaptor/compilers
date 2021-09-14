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
lab9: ast.c ast.h symtable.c symtable.h emit.c emit.h lex.yy.c y.tab.c	
	gcc $(FLAGS) y.tab.c lex.yy.c ast.c symtable.c emit.c -o lab9 -lm

lex.yy.c: lab9.l
	lex lab9.l

y.tab.c: lab9.y
	yacc -d --verbose --debug lab9.y

# remove the binary and other generated stuff
clean:
	rm -f lab9 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab9 -s

# executes our code to test it's functionality
test:
	make clean
	make
	# ./lab9 -o foo < test.decaf
	# ./lab9 -o bar < test1.decaf
	# ./lab9 -o bar2 < test2.decaf
	# ./lab9 -o bar3 < test3.decaf
	./lab9 -o bar4 < test4.decaf
	# ./lab9 -o bar5 < test5.decaf

debug: lab9
	./lab9 -d -o bar < test.decaf