# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic

# Entry point target
all: lab2docalc

# compile the yacc code
y.tab.c: lab2docalc.y
	yacc -d lab2docalc.y

# compile the lex code
lex.yy.c: lab2docalc.l
	lex lab2docalc.l

# compile the generated c code
lab2docalc: y.tab.c lex.yy.c
	gcc y.tab.c lex.yy.c -o lab2docalc

# reset the code base to just the source files
reset: clean
	rm lab2docalc lex.yy.c y.tab.c y.tab.h

# remove the object file
clean:
	rm -rf *.o

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab2docalc < ./comment.tst -s

# executes our code to test it's functionality
test:
	./lab2docalc
