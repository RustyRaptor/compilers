# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic

# Entry point target
all: lab2remove

# executable target 
lab2remove: lex.yy.o
	gcc $(FLAGS) -o lab2remove lex.yy.o

# compile the object code
lex.yy.o: lex.yy.c
	gcc $(FLAGS) -c lex.yy.c

# generate the c code from lex
lex.yy.c: lab2remove.l
	lex lab2remove.l

# reset the code base to just the source files
reset: clean
	rm lab2remove lex.yy.c

# remove the object file
clean:
	rm -rf *.o

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab2remove < ./comment.tst -s

# executes our code to test it's functionality
test:
	./lab2remove < ./comment.tst
