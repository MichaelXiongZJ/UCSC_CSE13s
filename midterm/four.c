#include "midterm.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b) { //inspired by minsort_iter() example by Prof. Rudnick
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

char *alphabetize_word(char *word) { //inspired by minsort_iter() example by Prof. Rudnick

  int length = strlen(word);
  char* result = (char*)calloc(length, sizeof(char));
  strcpy(result, word);

  for (int start = 0; start < length; start++){
    int index = start;
    char smallest = 'z';
    for(int i = start; i <  length; i++){
      if(result[i] < smallest){
        smallest = result[i];
        index = i;
      }
    }
    swap(&result[start], &result[index]);
  }
  return result;

  }
