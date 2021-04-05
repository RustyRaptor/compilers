# Ziad Arafat
# 2021
#   LAB3 Symbol Table Tools
#

# FLAGS = -O0 -Wall -Wextra -pedantic

# the gcc options so I don't have to copy paste them everywhere
# any time I make changes to them. 
FLAGS = -O0 -Wextra -pedantic -Wall

# Entry point target
all: lab3

# Compile symboltable tools	
lab3:	symtable.c symtable.h
	gcc $(FLAGS) -o lab3  symtable.c


# reset the code base to just the source files
reset: clean
	rm lab3 lex.yy.c y.tab.c y.tab.h

# remove the object file
clean:
	rm -rf *.o

# runs valgrind to look for any memory mistakes
memcheck:
	valgrind ./lab3 --leak-check=full -s

# executes our code to test it's functionality
test:
	./lab3
