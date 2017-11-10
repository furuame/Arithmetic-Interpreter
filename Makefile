interpreter.o: interpreter.c interpreter.h token.h
	gcc -Wall -g -c -o $@ $<

main: main.c interpreter.o
	gcc -Wall -g -o $@ $^

clean:
	rm interpreter.o main
