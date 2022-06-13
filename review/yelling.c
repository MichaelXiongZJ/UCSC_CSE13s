#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  // You're going to have to use argc to decide whether to open up a file, or to
  // read from stdin.
  // If you haven't seen them before, you will likely want to use the functions
  // `fgetc()` and `fputc()`.
  FILE *input;
  char c;
  if(argc > 1){ //load stream
    input = fopen(argv[1], "r");
  }else{
    input = stdin;
  }
  while ((c = fgetc(input)) != EOF) {
    if(c >= 'a' && c <= 'z'){ //if c is within {a...z}
      c = c - 'a' + 'A';
    }
    fputc(c, stdout);
  }
  return 0;
}
