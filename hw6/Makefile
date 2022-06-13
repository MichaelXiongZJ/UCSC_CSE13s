CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: hw6

hw6: wordle_game.o hw6.o
	$(CC) wordle_game.o hw6.o -o hw6

hw6.o: hw6.c wordle_game.h
	$(CC) $(CFLAGS) -c hw6.c 

wordle_game.o: wordle_game.c wordle_game.h
	$(CC) $(CFLAGS) -c wordle_game.c 

clean:
	rm -f hw6 wordle_game.o hw6.o

format:
	clang-format -i -style=file *.[ch]
