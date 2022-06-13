#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "hw2.h"


void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  int test_array_1[] = {100, 5, 3, -12, 109, -100};
  int test_array_2[] = {-55, 3, -12, 109, -100, 12, -12, 7000, 12};

  printf("**********************\n");
  printf("tests for next_collatz_number\n");
  should_be_exactly_equal("next_collatz_number(47)",
      142, next_collatz_number(47));
  should_be_exactly_equal("next_collatz_number(175)",
      526, next_collatz_number(175));
  should_be_exactly_equal("next_collatz_number(526)",
      263, next_collatz_number(526));

  printf("\n**********************\n");
  printf("tests for count_collatz_steps\n");
  should_be_exactly_equal("count_collatz_steps(2)",
      1,
      count_collatz_steps(2));
  should_be_exactly_equal("count_collatz_steps(4)",
      2,
      count_collatz_steps(4));
  should_be_exactly_equal("count_collatz_steps(5)",
      5,
      count_collatz_steps(5));


  printf("\n**********************\n");
  printf("tests for maximum\n");
  should_be_exactly_equal("maximum of test_array_1",
      109,
      maximum(test_array_1, 6));
  should_be_exactly_equal("maximum of test_array_2",
      7000,
      maximum(test_array_2, 9));

  printf("\n**********************\n");
  printf("tests for sum_positive\n");
  should_be_exactly_equal("sum_positive of test_array_1",
      217,
      sum_positive(test_array_1, 6));
  should_be_exactly_equal("sum_positive of test_array_2",
      7136,
      sum_positive(test_array_2, 9));

  printf("\n**********************\n");
  printf("tests for count_negative\n");
  should_be_exactly_equal("count_negative of test_array_1",
      2,
      count_negative(test_array_1, 6));
  should_be_exactly_equal("count_negative of test_array_2",
      4,
      count_negative(test_array_2, 9));

  return 0;
}
