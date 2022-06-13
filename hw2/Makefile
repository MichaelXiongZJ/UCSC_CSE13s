CC = clang

# You'll need to uncomment this line once you're done with your code.
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw2_test

hw2_test: hw2.o hw2_test.o
	$(CC) hw2.o hw2_test.o -o hw2_test

hw2.o: hw2.c hw2.h
	$(CC) $(CFLAGS) -c hw2.c

hw2_test.o: hw2_test.c hw2.h
	$(CC) $(CFLAGS) -c hw2_test.c

clean:
	rm -f hw2_test hw2.o hw2_test.o

format:
	clang-format -i -style=file *.{c,h}
