#pragma once

#include <stdbool.h>
#include <stdio.h>

bool score_guess(char *secret, char *guess, char *result);

bool valid_guess(char *guess, char **vocabulary, size_t num_words);

char **load_vocabulary(char *filename, size_t *num_words);

void free_vocabulary(char **vocabulary, size_t num_words);

bool conflicted_guess(char *guess, char *revealed);

void add_to_set(char* result, char* revealed, char* guess);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
