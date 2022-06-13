#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "stack_calculator.h"

// Allocate a new Stack struct and return a pointer to it.
Stack *stack_create(void) {
  // this one is complete, no need to change it!
  Stack *out;
  out = (Stack *)calloc(1, sizeof(Stack));
  return out;
}

// Add a new node at the front of the stack. Return false if we are unable to do
// so (eg, if memory allocation fails).
bool stack_push(Stack *s, CalculatorItem item) {
  // your code here
  Node *topitem = NULL;
  topitem = (Node *)calloc(1, sizeof(Node));
  topitem->item = item;
  topitem->next = s->top;
  s->top = topitem;

  return true;
}

// Pop the stack and put the result into the output pointer.
// return false if the stack is NULL or if it is empty.
bool stack_pop(Stack *s, CalculatorItem *output) {
  // your code here
  if(s->top == NULL){
    return false;
  }
  Node *temp = s->top;
  *output = s->top->item;
  s->top = s->top->next;

  free(temp);
  temp = NULL;

  return true;
}

// Returns true if the specified stack is empty.
bool stack_empty(Stack *s) {
  // your code here
  return s->top == NULL;
}

// Free all of the memory used by this stack, including its linked list.
// When you are done, set the pointer to NULL.
void stack_delete(Stack **s) {
  // your code here
  CalculatorItem output;
  while((*s)->top != NULL){
    stack_pop(*s, &output);
  }
  free(*s);
  *s = NULL;
}

// Returns true if we were able to successfully perform the computation step,
// and false if there was an error of some kind.
bool stack_compute_step(Stack *s, CalculatorItem item) {
  // your code here

  if(item.type == NUMBER){
    stack_push(s, item);
  }else{
    CalculatorItem temp;
    stack_pop(s, &temp);
    float second = temp.value;
    stack_pop(s, &temp);
    float first = temp.value;
    float result;
    switch (item.type){

    case ADD:
      result = first + second;
      break;
    
    case SUBTRACT:
      result = first - second;
      break;

    case MULTIPLY:
      result = first * second;
      break;

    case DIVIDE:
      result = first / second;
      break;

    default:
      return false;
    }
    temp.value = result;
    temp.type =  NUMBER;
    stack_push(s, temp);
  }

  return true;
}
