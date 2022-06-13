#include "midterm.h"

#include <stdio.h>
#include <math.h>

double *exponents(int start, int end, double power) {
  
  int length = end - start + 1;
  double* result;

  result = (double*)calloc(length, sizeof(double));

  for(int i = 0; i <= length; i++){
    result[i] = pow((double)(start + i), power);
  }

  return result;
}
