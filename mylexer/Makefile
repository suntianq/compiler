.PHONY:lc,lcc,clean
lc:
	flex mylexer.l
	gcc lex.yy.c -o lc.out
	./lc.out
lcc:
	flex -+ mylexer.l
	g++ lex.yy.cc -o lcc.out
	./lcc.out
clean:
	rm *.out