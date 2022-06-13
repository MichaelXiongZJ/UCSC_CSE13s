#pragma once

int next_collatz_number(int n);

int count_collatz_steps(int n);

int maximum(int *nums, int len);

int sum_positive(int *nums, int len);

int count_negative(int *nums, int size);


// Idea for the UNUSED macro from Stack Overflow user mtvec. Thanks!
// https://stackoverflow.com/a/3599170
#define UNUSED(x) (void)(x)
