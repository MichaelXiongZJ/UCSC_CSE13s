CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw3_test

hw3_test: hw3.o hw3_test.o
	$(CC) hw3.o hw3_test.o -o hw3_test

hw3.o: hw3.c hw3.h
	$(CC) $(CFLAGS) -c hw3.c

hw3_test.o: hw3_test.c hw3.h
	$(CC) $(CFLAGS) -c hw3_test.c

clean:
	rm -f hw3_test hw3.o hw3_test.o

format:
	clang-format -i -style=file *.{c,h}
