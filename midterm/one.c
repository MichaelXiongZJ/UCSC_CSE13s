#include "midterm.h"

#include <stdio.h>

int num_with_highest_square(int a, int b, int c) {
  int a_sqr = a*a;
  int b_sqr = b*b;
  int c_sqr = c*c;
  if((a_sqr >= b_sqr) && (a_sqr >= c_sqr)){
    return a;
  } else if((b_sqr >= a_sqr) && (b_sqr >= c_sqr)){
    return b;
  } else{
    return c;
  }
}
