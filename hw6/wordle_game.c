#include "wordle_game.h"
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


//helper function
bool has_guess(char *secret, char *guess, int index){
  for(int i = 0; i < 5; i++){
    if(i != index){
      if(guess[index] == secret[i]){
        return true;
      }
    }
  }
  return false;
}

//helper function
bool is_in_set(char* set, char target){
  int len = strlen(set);
  for(int i = 0; i < len; i++){
    if(set[i] == target){
      return true;
    }
  }
  return false;
}

//Hard Mode: store the letters that are crossed out
void add_to_set(char* result, char* revealed, char* guess){
  for(int i = 0; i < 5; i++){
    if(result[i] == 'x'){
      if(!is_in_set(revealed, guess[i])){
        revealed = strncat(revealed, &guess[i], 1);
      }
    }
  }
}

// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
  for(int i = 0; i < 5; i++){
    char color = 'x';
    if(guess[i] == secret[i]){
      color = 'g';
    }else if(has_guess(secret, guess, i)){
      color = 'y';
    }
    result[i] = color;
  }
  for(int i = 0; i < 5; i++){
    if(result[i] != 'g'){
      return false;
    }
  }
  return true;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for(size_t i = 0; i < num_words; i++){
    if(!strcmp(guess, vocabulary[i])){
      return true;
    }
  }
  return false;
}

//function for HARD MODE  
//check if the guess word conflict with the already revealed letters
bool conflicted_guess(char *guess, char *revealed){
  for (int i = 0; i < 5; i++){
    if(is_in_set(revealed, guess[i])){
      return true;
    }
  }
  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  char **out = NULL;
  // TODO(you): finish this function
  FILE *file = fopen(filename, "r");
  size_t str_size;
  int words_count = 1;
  out = (char**)malloc(words_count * sizeof(char*));  //allocate the array 

  char *temp = NULL;

  ssize_t size;
  while((size = getline(&temp, &str_size, file)) != -1){
    out = (char**)realloc(out, words_count * sizeof(char*)); //extend the array allocation
    temp[5] = '\0';
    out[words_count-1] = temp; //allocate each string
    temp = NULL;
    words_count++;
  }
  free(temp);
  *num_words = --words_count;
  fclose(file);
  return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for(size_t i = 0; i < num_words; i++){
    free(vocabulary[i]);
  }
  free(vocabulary);
}

