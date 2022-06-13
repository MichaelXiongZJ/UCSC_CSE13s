#include "review.h"

#include <stdio.h>
#include <stdlib.h>

#include <assert.h>  //debug

void print_tnode(tnode *node) { printf("%s: %d\n", node->word, node->count); }

int main(void) {

//additional tester by Whumst
{
srand(0);
printf("testing sum_and_diff...\n");
int sum, diff, a, b;
for (int _ = 0; _ < 10000; _++) {
    a = rand()%1001 - 500;
    b = rand()%1001 - 500;
    sum_and_difference(a, b, &sum, &diff);
    assert(sum-a == b && sum-b==a);
    assert(diff+b == a && diff-a == -b);
}
printf("sum_and_diff tests passed!!!\n");
printf("testing ll_length...\n");
LLint* ll = NULL;
assert(ll_length(ll)==ll_length_iterative(ll) && ll_length(ll)==0);
for (size_t len = 1; len < 1001; len++) {
    ll = NULL;
    for (size_t i = 0; i<len; i++) {
        LLint* p = calloc(1, sizeof(LLint));
        p->val = rand()%100000 - 50000;
        if (ll != NULL) {
            LLint* walk;
            for (walk = ll; walk!=NULL && walk->next != NULL; walk=walk->next)
                ;
            walk->next = p;
        } else {
            ll = p;
        }
    }
    assert(ll_length(ll)==ll_length_iterative(ll) && ll_length(ll)==len);
    while(ll != NULL) {
        LLint *temp = ll;
        ll = ll->next;
        free(temp);
    }
}
printf("ll_length tests passed!!!\n");

printf("testing reverse_double...\n");
for (size_t len = 0; len < 5000; len++) {
    double arr1[len];
    double arr2[len];
    for (size_t i = 0; i<len; i++) {
        arr1[i] = (rand()%100000)/1000.0;
        arr2[i] = arr1[i];
    }
    reverse_doubles_with_stack(arr2, len);
    for (size_t i = 0; i<len; i++) {
        assert(arr1[i] == arr2[len-1-i]);
    }
}
printf("reverse_double tests passed!!!\n");
printf("testing word search...\n");
for (int _ = 0; _ < 1000; _++) {
    int alphabet_occurances[26];
    char tempString[2] = {0, '\0'};
    tnode *counts = NULL;
    for (int letter = 0; letter<26; letter++) {
        alphabet_occurances[letter] = rand()%50;
        tempString[0] = 'a'+letter;
        for (int __ = 0; __ < alphabet_occurances[letter]; __++) {
            counts = word_observe(tempString, counts);
        }
        assert(word_count(tempString, counts) == alphabet_occurances[letter]);
    }
    for (int letter = 0; letter<26; letter++) {
        tempString[0] = 'a'+letter;
        assert(word_count(tempString, counts) == alphabet_occurances[letter]);
    }
    delete_tree(counts);
}
printf("word search tests passed!!!\n");
}

  // Your code for testing your functions in review.c goes here. You'll want to
  // figure out how to call all the different functions in here; it's a good
  // exercise!

  tnode *counts = NULL;

  // demo calls for counting up some words, possibly helpful.
  counts = word_observe("dog", counts);
  counts = word_observe("dog", counts);

  counts = word_observe("apple", counts);
  counts = word_observe("hello", counts);
  counts = word_observe("pineapple", counts);
  counts = word_observe("pineapple", counts);
  counts = word_observe("pineapple", counts);

  counts = word_observe("zebra", counts);
  counts = word_observe("zebra", counts);
  counts = word_observe("zebra", counts);
  counts = word_observe("zebra", counts);

  // how many times did we see "apple"?
  printf("apple: %d\n", word_count("apple", counts));
  printf("dog: %d\n", word_count("dog", counts));
  printf("pineapple: %d\n", word_count("pineapple", counts));
  printf("zebra: %d\n", word_count("zebra", counts));

  delete_tree(counts);

  return 0;
}
