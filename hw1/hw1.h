#pragma once

#include <stdbool.h>

double area_of_disk(double radius);

double area_of_ring(double outer_radius, double inner_radius);

int bigger_minus_smaller(int number_a, int number_b);

bool value_in_range(int lower_bound, int x, int upper_bound);

// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
