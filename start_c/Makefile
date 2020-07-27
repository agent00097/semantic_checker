CFLAGS=-g -Og -Wall -Wno-unused-variable -Wno-unused-function -std=c99 -lfl
CC=gcc

p3_c:	p3.lex.yy.c p3.tab.c
	$(CC) -o $@ p3.lex.yy.c p3.tab.c $(CFLAGS)

p3.lex.yy.c:	p3_c.l
	flex -o $@ p3_c.l

p3.tab.c:	p3_c.y
	bison -o p3.tab.c -dv p3_c.y

clean:	
	rm -f p3_c p3.lex.yy.c p3.tab.* p3.output

