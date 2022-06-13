#include "final.h"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  char **sequences;

  sequences = alphabet_sequences(1);
  if (!sequences) {
    printf("sequences is NULL -- wanted an array of alphabet chunks!\n");
  } else {
    printf("sequences[0] should be \"a\", got: %s\n", sequences[0]);
  }

  // leaking memory here, being sloppy during the final. What is the world
  // coming to?
  sequences = alphabet_sequences(28);
  if (!sequences) {
    printf("sequences is NULL -- wanted an array of alphabet chunks!\n");
  } else {
    printf("sequences[27] should be \"ab...yzab\", got: %s\n", sequences[27]);
  }

  sequences = alphabet_sequences(260);
  for(int i = 0; i < 260; i++){
    printf("sequences[%d] = %s\n", i, sequences[i]);
  }

  return 0;
}
