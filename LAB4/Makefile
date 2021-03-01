# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic

# Entry point target
all: lab4

# Compile all the THINGS!
lab4: lab4docalc.l lab4docalc.y symtable.c symtable.h
	lex lab4docalc.l
	yacc -d lab4docalc.y
	gcc $(FLAGS) y.tab.c lex.yy.c symtable.c -o lab4

# remove the binary and other generated stuff
clean:
	rm lab4 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab4 -s

# executes our code to test it's functionality
test:
	./lab4