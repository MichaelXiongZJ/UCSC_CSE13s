#include "review.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions for you to implement. Most of the work for this homework will be
// done in here, but you'll also need to make changes to review.h and yelling.c.

// Problem 1
void sum_and_difference(int a, int b, int *sum, int *difference) {
  //  TODO(you): your code here
  *sum = a + b;
  *difference = a - b;
}

// Problem 2

// This one ought to be recursive.
size_t ll_length(LLint *node) {
  //  TODO(you): your code here
  if(!node){
    return 0;
  }else if(!node->next){
    return 1;
  }else{
    return 1 + ll_length(node->next);
  }
}

// Do this one iteratively.
size_t ll_length_iterative(LLint *node) {
  //  TODO(you): your code here
  size_t result = 0;
  if(node){
    LLint *temp = node;
    while(temp->next){
      temp = temp->next;
      result++;
    }
    result++;
  }
  return result;
}

// Problem 3.

//helper
LLdouble *add_to_LLdouble(LLdouble *set, double val){
  LLdouble *newfront = calloc(1, sizeof(LLdouble));
  newfront->val = val;
  newfront->next = set;
  return newfront;
}

//helper
LLdouble *pop(LLdouble *set, double *result){
  *result = set->val;
  LLdouble *temp = set->next;
  free(set);
  set = NULL;
  return temp;
}

void reverse_doubles_with_stack(double *array, size_t array_len) {
  // This function will reverse the order of the array pointed to by *array.
  // Make sure to define your linked list data structure in review.h, and use
  // stack behavior (LIFO) to get the numbers in the reversed order.
  // There is a way to do this without a stack data structure, I know. But this
  // is for practice with data structures.
  //
  //  TODO(you): your code here
  LLdouble *double_stack = calloc(1, sizeof(LLdouble));
  double_stack->next = NULL;
  for(size_t i = 0; i < array_len; i++){
    double_stack = add_to_LLdouble(double_stack, array[i]);
  }
  for(size_t i = 0; i < array_len; i++){
    double_stack = pop(double_stack, array+i);
  }
  free(double_stack);
}

// Problem 4.

tnode *word_observe(char *word, tnode *node) {
  // This function returns a pointer to a tnode because you may have to allocate
  // a new one. You might take a NULL pointer to start with.
  // Also, this means that you can very cleanly do this with recursion.

  if(!node){  //make new node
    tnode *new_node = calloc(1, sizeof(tnode));
    node = new_node;
    node->word = strdup(word);
    node->count = 1;
  }else{
    int dif = strcmp(node->word, word);
    if(dif == 0){
      node->count++;
    }else if(dif < 0){
      node->left = word_observe(word, node->left);
    }else{
      node->right = word_observe(word, node->right);
    }
  }
  return node;
}


int word_count(char *word, tnode *node) {
  // Default return values; here for you to change.
  if(!node){ //node is NULL
    return 0;
  }else if(strcmp(node->word, word) == 0){
    return node->count;
  }else if(strcmp(node->word, word) < 0){
    return word_count(word, node->left);
  }else if(strcmp(node->word, word) > 0){
    return word_count(word, node->right);
  }else{  //word is NULL
    return 0;
  }
}

void delete_tree(tnode *node) {
  // Free the whole tree and all associated memory. This can be recursive or
  // not, your choice!
  if(node){
    delete_tree(node->left);
    delete_tree(node->right);
    free(node->word);
    node->word = NULL;
    free(node);
    node = NULL;
  } 
}
