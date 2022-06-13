CC = clang

# Make sure to use the full CFLAGS before turning in. Uncomment this for lax
# checking during development, if you need to.
# CFLAGS =

# You can comment this out and use the above CFLAGS instead if you need to,
# during development.
CFLAGS = -Wall -Wpedantic -Werror -Wextra


all: hw5 graphsearch_test

hw5: hw5.o graphsearch.o
	$(CC) graphsearch.o hw5.o -o hw5

graphsearch_test: graphsearch_test.o graphsearch.o
	$(CC) graphsearch.o graphsearch_test.o -o graphsearch_test

graphsearch.o: graphsearch.c graphsearch.h
	$(CC) $(CFLAGS) -c graphsearch.c

graphsearch_test.o: graphsearch_test.c graphsearch.h
	$(CC) $(CFLAGS) -c graphsearch_test.c

hw5.o: hw5.c graphsearch.h
	$(CC) $(CFLAGS) -c hw5.c

# use graphviz to generate visualizations of graphs!
# sudo apt install graphviz to make this work
graph1.dot.png: graph1.dot
	dot graph1.dot -O -Tpng

graph2.dot.png: graph2.dot
	dot graph2.dot -O -Tpng

clean:
	rm -f hw5 hw5.o graphsearch.o

format:
	clang-format -i -style=file *.[ch]
