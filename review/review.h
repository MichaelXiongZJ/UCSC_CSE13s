#pragma once

#include <stdlib.h>

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference);

// Problem 2

typedef struct LLint {
  int val;
  struct LLint *next;
} LLint;

// This one ought to be recursive.
size_t ll_length(LLint *node);

// Do this one iteratively.
size_t ll_length_iterative(LLint *node);

// Problem 3.

// TODO(you): define LLdouble here.
typedef struct LLdouble {
  double val;
  struct LLdouble *next;
} LLdouble;

void reverse_doubles_with_stack(double *array, size_t array_len);

// Problem 4.

typedef struct tnode {
  char *word;
  int count;
  struct tnode *left;
  struct tnode *right;
} tnode;

tnode *word_observe(char *word, tnode *node);

int word_count(char *word, tnode *node);

void delete_tree(tnode *node);
