# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic 

# Entry point target
all: lab5

# Compile all the THINGS!
lab5: lab5.l lab5.y symtable.c symtable.h
	lex lab5.l
	yacc -d --verbose --debug lab5.y
	gcc $(FLAGS) y.tab.c lex.yy.c symtable.c -o lab5 -lm

# remove the binary and other generated stuff
clean:
	rm lab5 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab5 -s

# executes our code to test it's functionality
test:
	./lab5 < testinput.txt