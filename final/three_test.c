#include "final.h"

#include <stdio.h>
#include <stdlib.h>

BinaryTree *build_tree(int value, BinaryTree *left, BinaryTree *right) {
  BinaryTree *out = calloc(1, sizeof(BinaryTree));
  out->val = value;
  out->left = left;
  out->right = right;

  return out;
}

int main(void) {
  BinaryTree *tree =
      build_tree(14, build_tree(3, NULL, NULL),
                 build_tree(15, NULL, build_tree(42, NULL, NULL)));

  // Here we should find 42 at depth 2 (path is 14->15->42)
  int count = count_values_at_least(42, tree);
  printf("should have a count of 1, got %d\n", count);

  count = count_values_at_least(14, tree);
  printf("should have a count of 3, got %d\n", count);

  BinaryTree *sec_tree = build_tree(20, build_tree(59, build_tree(12, NULL, NULL), build_tree(49, NULL,NULL)), build_tree(89, build_tree(78,NULL,NULL), build_tree(21, NULL, NULL)));
  count = count_values_at_least(0, sec_tree);
  printf("\nMyTest:\n");
  printf("shoudl have a count of 7, got %d\n", count);


  return 0;
}
