# FLAGS = -O0 -Wall -Wextra -pedantic

FLAGS = -O0 -Wextra -pedantic

all: lab1

lab1: lex.yy.o
	gcc $(FLAGS) -o lab1 lex.yy.o

lex.yy.o: lex.yy.c
	gcc $(FLAGS) -c lex.yy.c

lex.yy.c: lab1.l
	lex lab1.l

reset: clean
	rm lab1 lex.yy.c

clean:
	rm -rf *.o

memcheck:
	valgrind ./lab1 < /etc/passwd -s

test:
	./lab1 < /etc/passwd
