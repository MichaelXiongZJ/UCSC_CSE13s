#include "wordle_game.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Once your other functions are working, please revert your main() to its
// initial state, but please feel free to change it, during development. You'll
// want to test out each individual function!
int main(void) {
  char **vocabulary;
  size_t num_words;
  int num_guesses = 0;

  srand(time(NULL));

  // load up the vocabulary and store the number of words in it.
  vocabulary = load_vocabulary("vocabulary.txt", &num_words);

  // Randomly select one of the words from the file to be today's SECRET WORD.
  int word_index = rand() % num_words;
  char *secret = vocabulary[word_index];

  // input buffer -- we'll use this to get a guess from the user.
  char guess[80];

  //for Hard Mode
  char revealed[26] = {0};

  // buffer for scoring each guess.
  char result[6] = {0};
  bool success = false;

  printf("\nTime to guess a 5-letter word! (press ctrl-D to exit)\n");
  printf("==============================\n\n");
  //printf("answer: %s\n", secret);       //show answer

  while (!success) {
    printf("guess: ");
    if (fgets(guess, 80, stdin) == NULL) {
      break;
    }
    // Whatever the user input, cut it off at 5 characters.
    guess[5] = '\0';
    // if(guess[0] == '?'){  //cheat code, for debug
    //   printf("ANSWER REVEAL: %s\n", secret);
    //   break;
    // }
    if (!valid_guess(guess, vocabulary, num_words)) {
      printf("Not a valid guess.\n");
      printf("\n==============================\n\n");
      continue;
    } else if(conflicted_guess(guess, revealed)){  //HARD_MODE: check if guess has letter that are already crossed out
      printf("Letter already tried.\n");
      printf("Eliminated letters: %s\n", revealed);
      printf("\n==============================\n\n");
      continue;
    }else {
      num_guesses++;
    }
    success = score_guess(secret, guess, result);
    //add revealed letters to set
    add_to_set(result, revealed, guess);
    printf("%s\n", guess);
    printf("%s\n", result);
    printf("\n==============================\n\n");
  }

  if (success) {
    printf("you win, in %d guesses!\n", num_guesses);
  }
  free_vocabulary(vocabulary, num_words);

  return 0;
}
