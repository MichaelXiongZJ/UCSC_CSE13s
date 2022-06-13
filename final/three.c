#include "final.h"

#include <stdio.h>

int count_values_at_least(int value, BinaryTree *tree) {
  // Your code here!
  // Remember, this is just a regular binary tree, not a binary *search* tree.
  if(!tree){  //end of tree
    return 0;
  }
  int counter = 0;
  if(tree->val >= value){
    counter++;
  }
  counter += count_values_at_least(value, tree->left);
  counter += count_values_at_least(value, tree->right);
  return counter;
}
