#include "final.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>


bool is_letter(char c){
  if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
    return true;
  }
  return false;
}

size_t word_count(char *text) {
  // Your code here!
  // Count up all the words that occur in the given string. A new word starts
  // when you see a letter a-z or A-Z.
  int length = strlen(text);
  size_t counter = 0;
  for(int i = 0; i < length; i++){
    if(is_letter(text[i])){
      counter++;
      while(!(!is_letter(text[i]) && is_letter(text[i+1]))){
        i++;
      }
      
    }
  }
  return counter;
}
