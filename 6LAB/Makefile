# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic 

# Entry point target
all: lab6

# Compile all the THINGS!
lab6: lab6.l lab6.y ast.c ast.h
	lex lab6.l
	yacc -d --verbose --debug lab6.y
	gcc $(FLAGS) y.tab.c lex.yy.c ast.c -o lab6 -lm

# remove the binary and other generated stuff
clean:
	rm lab6 lex.yy.c y.tab.c y.tab.h

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab6 -s

# executes our code to test it's functionality
test:
	./lab6 < testinput.txt