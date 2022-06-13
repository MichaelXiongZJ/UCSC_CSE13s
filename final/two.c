#include "final.h"

#include <stdio.h>

char *make_string(int size){
  char *str = calloc(size+1, sizeof(char));
  for(int i = 0; i < size; i++){
    int copy = i;
    while(copy >= 26){
      copy -= 26;
    }
    str[i] = 'a' + copy;
  }
  return str;
}

char **alphabet_sequences(int maxsize) {
  // Your code here!
  // remember, you're going to need to allocate the array of strings you're
  // returning. and you'll also need to allocate each string in that array.
  char **result = calloc(maxsize, sizeof(char*));
  for(int i = 0; i < maxsize; i++){
    result[i] = make_string(i+1);
  }
  return result;
}
