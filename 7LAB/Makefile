# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic 

# Entry point target
all: lab7

# Compile all the THINGS!
lab7: lab7.l lab7.y ast.c ast.h symtable.c symtable.h
	lex lab7.l
	yacc -d --verbose --debug lab7.y
	gcc $(FLAGS) y.tab.c lex.yy.c ast.c symtable.c -o lab7 -lm

# remove the binary and other generated stuff
clean:
	rm lab7 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab7 -s

# executes our code to test it's functionality
test:
	./lab7 < testinput.txt