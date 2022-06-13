#pragma once

#include <stdio.h>
#include <stdlib.h>

// Question one.
int num_with_highest_square(int a, int b, int c);

// Question two.
double *exponents(int start, int end, double power);

// Question three.
typedef struct LLint {
  int val;
  struct LLint *next;
} LLint;

int reduce(LLint *nums, int (*f)(int, int), int initial);
LLint *push(LLint *list, int val);

// Question four.
char *alphabetize_word(char *word);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
