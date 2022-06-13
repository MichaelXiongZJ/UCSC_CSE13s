#include <stdio.h>

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_calculator.h"

bool approximately_equal(double a, double b) {
  // difference is less than 0.001?
  return fabs(a - b) < 0.001;
}

void should_be_equal(const char *message, double expected, double actual) {
  printf("%s\n", message);
  printf("%s: wanted %f, got %f\n",
         approximately_equal(expected, actual) ? "SUCCESS" : "FAILURE",
         expected, actual);
}

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

void ptr_should_be_equal(const char *message, void *expected, void *actual) {
  printf("%s\n", message);
  printf("%s: wanted %p, got %p\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {

  printf("**********************\n");
  printf("tests for stack_push\n");
  Stack *stack1 = stack_create();
  CalculatorItem five = {NUMBER, 5.0};
  CalculatorItem six = {NUMBER, 6.0};

  stack_push(stack1, five);
  stack_push(stack1, six);
  should_be_equal("second stack element should be 5", 5.0,
                  stack1->top->next->item.value);
  should_be_equal("first stack element should be 6", 6.0,
                  stack1->top->item.value);

  printf("\n**********************\n");
  printf("tests for stack_pop\n");
  CalculatorItem output;
  bool result;

  result = stack_pop(stack1, &output);
  should_be_equal("popped something, expect 6", 6.0, output.value);
  should_be_exactly_equal("expect true", true, result);
  result = stack_pop(stack1, &output);
  should_be_equal("popped something, expect 5", 5.0, output.value);
  should_be_exactly_equal("expect true", true, result);
  result = stack_pop(stack1, &output);
  should_be_exactly_equal("expect false", false, result);

  printf("\n**********************\n");
  printf("tests for stack_empty\n");
  Stack *stack2 = stack_create();
  result = stack_empty(stack2);
  should_be_exactly_equal("expect true", true, result);
  stack_push(stack2, five);
  result = stack_empty(stack2);
  should_be_exactly_equal("expect false", false, result);

  printf("\n**********************\n");
  printf("tests for stack_delete\n");
  // note that we'll also make sure that no memory is leaked, in autograding
  stack_delete(&stack1);
  ptr_should_be_equal("stack1 should be set to NULL", NULL, stack1);

  printf("\n**********************\n");
  printf("tests for stack_compute_step\n");
  Stack *stack3 = stack_create();
  stack_compute_step(stack3, five);
  stack_compute_step(stack3, six);
  should_be_equal("first stack element should be 6", 6.0,
                  stack3->top->item.value);
  CalculatorItem plus = {ADD, 0.0};
  stack_compute_step(stack3, plus);
  should_be_equal("first stack element should be 11", 11.0,
                  stack3->top->item.value);
  CalculatorItem eleven = {NUMBER, 11.0};
  stack_compute_step(stack3, eleven);
  stack_compute_step(stack3, plus);
  should_be_equal("first stack element should be 22", 22.0,
                  stack3->top->item.value);

  stack_compute_step(stack3, eleven);
  CalculatorItem divide = {DIVIDE, 0.0};
  stack_compute_step(stack3, divide);
  should_be_equal("first stack element should be 2", 2.0,
                  stack3->top->item.value);
  CalculatorItem two = {NUMBER, 2.0};
  stack_compute_step(stack3, two);
  CalculatorItem multiply = {MULTIPLY, 0.0};
  stack_compute_step(stack3, multiply);
  should_be_equal("first stack element should be 4", 4.0,
                  stack3->top->item.value);

  CalculatorItem four = {NUMBER, 4.0};
  stack_compute_step(stack3, four);
  CalculatorItem subtract = {SUBTRACT, 0.0};
  stack_compute_step(stack3, subtract);
  should_be_equal("first stack element should be 0", 0.0,
                  stack3->top->item.value);

  result = stack_pop(stack3, &output);
  should_be_equal("popped value should be 0", 0.0, output.value);
  result = stack_empty(stack3);
  should_be_exactly_equal("stack3 should now be empty", true, result);
  printf("now deleting stacks\n");
  stack_delete(&stack3);
  stack_delete(&stack2);
  printf("You should be passing valgrind\n");
  return 0;
}
