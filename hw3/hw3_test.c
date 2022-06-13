#include "hw3.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

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

int count_negative_helper(int cumulative, int nextval) {
  return cumulative + ((nextval < 0) ? 1 : 0);
}

void test_str_suffix(char *haystack, char *needle, bool expected) {
  printf("haystack: %s\n", haystack);
  printf("needle  : %s\n", needle);
  bool result = str_suffix(haystack, needle);
  printf("%s: do we think it's a suffix? %s\n",
      (result == expected)? "SUCCESS" : "FAILURE",
      result ? "yes" : "no");
}

int main(void) {
  int test_array_1[] = {100, 5, 3, -12, 109, -100};
  int test_array_2[] = {-55, 3, -12, 109, -100, 12, -12, 7000, 12};

  printf("**********************\n");
  printf("tests for str_suffix\n");
  test_str_suffix("", "", true);
  test_str_suffix("long string here", "", true);
  test_str_suffix("long string here", "here", true);
  test_str_suffix("long string here", "long string", false);
  test_str_suffix("", "something other than nothing", false);
  test_str_suffix("unrelated strings", "completely different", false);


  printf("\n**********************\n");
  printf("tests for dot_product\n");
  float vec1[] = {1.0, 0, 0};
  float vec2[] = {0, 0, 1.0};
  float vec3[] = {2.0, 2.0, 2.0};

  should_be_equal("dot_product of vec1 and vec2",
      0.0, dot_product(vec1, vec2, 3));
  should_be_equal("dot_product of vec1 and vec3",
      2.0, dot_product(vec1, vec3, 3));
  should_be_equal("dot_product of vec2 and vec3",
      2.0, dot_product(vec2, vec3, 3));
  should_be_equal("dot_product of vec3 and vec3",
      12.0, dot_product(vec3, vec3, 3));


  printf("\n**********************\n");
  printf("tests for reduce\n");
  should_be_exactly_equal("reduce with count_negative on test_array_1",
      2,
      reduce(test_array_1, 6, count_negative_helper, 0));
  should_be_exactly_equal("reduce with count_negative on test_array_2",
      4,
      reduce(test_array_2, 9, count_negative_helper, 0));

  printf("\n**********************\n");
  printf("tests for maximum_with_reduce\n");
  should_be_exactly_equal("maximum of test_array_1",
      109,
      maximum_with_reduce(test_array_1, 6));
  should_be_exactly_equal("maximum of test_array_2",
      7000,
      maximum_with_reduce(test_array_2, 9));

  printf("\n**********************\n");
  printf("tests for sum_positive_with_reduce\n");
  should_be_exactly_equal("sum_positive of test_array_1",
      217,
      sum_positive_with_reduce(test_array_1, 6));
  should_be_exactly_equal("sum_positive of test_array_2",
      7136,
      sum_positive_with_reduce(test_array_2, 9));

  printf("\nstudent tests below: \n");
  srand(0);
  for (int l = 0; l<1000; l++) {
    int strLen = rand()%10; // random number 0-9
    char str[strLen+1];
    for (int i = 0; i<strLen; i++) {
        str[i] = rand()%(127-32) + 32; // random ascii character 32 - 126
    }
    str[strLen] = '\0'; // string is 0 terminated
    for (int i = 0; i<strLen+1; i++) {
        assert(str_suffix(str, str+i)); // actual suffix is a suffix

        char copy[strLen+1];
        
        for(int j = 0; j<strLen+1; j++) {
            copy[j] = str[j];
        } // copy of str
        
        for(int j = i; j<strLen; j++) {
            char temp = copy[j];
            copy[j] = 9; // try replacing each char in the substring with a tab
            assert(!str_suffix(str, copy+i));
            copy[j] = temp;     
        }
    }
  }
  printf("**********************\nStudent Str Suffix Tests Passed\n");

   for (int l = 0; l<1000; l++) {
    int len = rand()%4; // random length 0-3
    float product = 0.0;
    float multi1[len];
    float multi2[len];
    for (int i = 0; i<len; i++) {
        float numerator = rand()%20 - 10;
        float denominator = rand()%10+1;
        product += numerator/denominator;
        float m1 = rand()%10+1;
        multi1[i] = m1;
        multi2[i] = numerator/m1/denominator;
    }
    assert(fabs(product - dot_product(multi1, multi2, len)) < 0.01);
  }
  printf("**********************\nStudent Dot Product Tests Passed\n");

  int min = -3;
  int max = 4;

  for (int l = 0; l < 1000; l++) {
      int aLen = rand()%5;
      int a[aLen];

      int numNegatives = rand()%(aLen+1);
      int numPositives = aLen - numNegatives;
      int numNegativesCopy = numNegatives;
      int sum = rand()%(max*numPositives + 1); 
      int remain = sum;                                            

      for (int i = 0; i < aLen; i++) {
          int valid = -1;
          int num;
          while (valid == -1) {
              num = (rand()%(max-min)) + min;
              if (num < 0 && numNegatives > 0) {
                  valid *= -1;
                  numNegatives--;
              } else if (num >= 0 && numPositives > 0 && remain-num >= 0) {
                  valid *= -1;
                  numPositives--;
                  remain -= num;
              }
          }
          a[i] = num;
      }

      assert(sum_positive_with_reduce(a, aLen)+remain == sum);
      assert(reduce(a, aLen, count_negative_helper, 0) == numNegativesCopy);


      if (aLen > 0) {
          int randomIndex = rand()%aLen;
          a[randomIndex] = max;
          assert(maximum_with_reduce(a, aLen) == max);
      }
  }
  printf("**********************\nStudent Reduce/Max/Count Tests Passed\n");
}
