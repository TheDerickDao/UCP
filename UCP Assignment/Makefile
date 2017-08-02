CC = gcc
CFLAGS = -Wall -ansi -pedantic -g
OBJ = program.o settings.o readFile.o check.o
EXEC = program

$(EXEC): $(OBJ)
	$(CC) -g $(OBJ) -o $(EXEC)

program.o: program.c settings.h readFile.h check.h
	$(CC) -c program.c $(CFLAGS)

setting.o: settings.c settings.h
	$(CC) -c settings.c $(CFLAGS)

readFile.o: readFile.c readFile.h settings.h
	$(CC) -c readFile.c $(CFLAGS)

check.o: check.c check.h
	$(CC) -c check.c $(CFLAGS)

clean:
	rm -f $(OBJ) $(EXEC)
