main.o: main.c mystring.h
	gcc -Wall -c main.c
mystring.o: mystring.c mystring.h
	gcc -Wall -c mystring.c
copier: main.o mystring.o
	gcc -Wall -o copier main.o mystring.o
cap: capitalizer.c
	gcc -Wall -o cap capitalizer.c
