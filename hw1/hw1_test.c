#include "hw1.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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

int main(void) {
  printf("**********************\n");
  printf("tests for area_of_disk\n");

  should_be_equal("area_of_disk(2.0)", 12.5663, area_of_disk(2.0));
  should_be_equal("area_of_disk(3.5)", 38.4845, area_of_disk(3.5));
  should_be_equal("area_of_disk(10.0)", 314.159, area_of_disk(10.0));

  printf("\n**********************\n");
  printf("tests for area_of_ring\n");
  should_be_equal("area_of_ring(10.0, 1.0)", 311.018, area_of_ring(10.0, 1.0));
  should_be_equal("area_of_ring(5.0, 2.0)", 65.973, area_of_ring(5.0, 2.0));

  // Actual size of a standard compact disc in cm^2.
  should_be_equal("area_of_ring(6.0, 0.75)", 111.33, area_of_ring(6.0, 0.75));

  printf("\n**********************\n");
  printf("tests for bigger_minus_smaller\n");
  should_be_exactly_equal("bigger_minus_smaller(10, 5)", 5,
                          bigger_minus_smaller(10, 5));
  should_be_exactly_equal("bigger_minus_smaller(5, 10)", 5,
                          bigger_minus_smaller(5, 10));
  should_be_exactly_equal("bigger_minus_smaller(10, 10)", 0,
                          bigger_minus_smaller(10, 10));
  should_be_exactly_equal("bigger_minus_smaller(10, -10)", 20,
                          bigger_minus_smaller(10, -10));
  should_be_exactly_equal("bigger_minus_smaller(-10, -10)", 0,
                          bigger_minus_smaller(-10, -10));

  printf("\n**********************\n");
  printf("tests for value_in_range\n");
  should_be_exactly_equal("value_in_range(0, 2, 5)", true,
                          value_in_range(0, 2, 5));

  should_be_exactly_equal("value_in_range(0, 0, 5)", true,
                          value_in_range(0, 0, 5));

  should_be_exactly_equal("value_in_range(0, 10, 5)", false,
                          value_in_range(0, 10, 5));

  return 0;
}
