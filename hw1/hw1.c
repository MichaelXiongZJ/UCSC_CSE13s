#include "hw1.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

// For the value of Pi, please use M_PI, which is defined in math.h.
double area_of_disk(double radius) {
  // your code here
	return M_PI*radius*radius;
  // remove all these UNUSED things when you actually write the function.
  //UNUSED(radius);
  //return 0;
}

double area_of_ring(double outer_radius, double inner_radius) {
  // your code here
	return M_PI*(outer_radius*outer_radius-inner_radius*inner_radius);
  //UNUSED(outer_radius);
  //UNUSED(inner_radius);
  //return 0;
}

int bigger_minus_smaller(int a, int b) {
  // your code here
	if (b > a){
		int temp = b;
		b = a;
		a = temp;
	}
	return a - b;
  //UNUSED(a);
  //UNUSED(b);
  //return 0;
}

bool value_in_range(int lower_bound, int x, int upper_bound) {
  // your code here
	if (x>=lower_bound && x<=upper_bound){
		return true;
	}else{
		return false;
	}
  //unused(lower_bound);
  //unused(upper_bound);
  //unused(x);
  //return false;
}
