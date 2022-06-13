#include "midterm.h"

#include <stdio.h>

LLint *push(LLint *list, int val) {
  LLint *out = (LLint *)calloc(1, sizeof(LLint));
  out->next = list;
  out->val = val;
  return out;
}

int reduce(LLint *nums, int (*f)(int, int), int initial) {

  int current = initial;
  while (nums != NULL){
    current = (*f)(current, nums->val);
    nums = nums->next;
  }
  return current;
}
