CC = clang

# You'll need to delete this line once you're done with your code.
# CFLAGS =

# You'll need to uncomment this line once you're done with your code.
CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: hw4 stack_calculator_test

hw4: hw4.o stack_calculator.o
	$(CC) stack_calculator.o hw4.o -o hw4

stack_calculator_test: stack_calculator_test.o stack_calculator.o
	$(CC) stack_calculator.o stack_calculator_test.o -o stack_calculator_test

stack_calculator.o: stack_calculator.c stack_calculator.h
	$(CC) $(CFLAGS) -c stack_calculator.c

stack_calculator_test.o: stack_calculator_test.c stack_calculator.h
	$(CC) $(CFLAGS) -c stack_calculator_test.c

hw4.o: hw4.c stack_calculator.h
	$(CC) $(CFLAGS) -c hw4.c

clean:
	rm -f hw4 stack_calculator_test hw4.o stack_calculator.o stack_calculator_test.o

format:
	clang-format -i -style=file *.[ch]
