CC = clang

# You can use the strict compiler flags if you like -- it may help in debugging! 
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: hw1_test caat

hw1_test: hw1_test.o hw1.o
	$(CC) hw1.o hw1_test.o -o hw1_test

hw1_test.o: hw1_test.c hw1.h
	$(CC) $(CFLAGS) -c hw1_test.c

hw1.o: hw1.c hw1.h
	$(CC) $(CFLAGS) -c hw1.c

caat: caat.c
	$(CC) $(CFLAGS) caat.c -o caat

clean:
	rm -f hw1_test caat *.o

format:
	clang-format -i -style=file *.[ch]
