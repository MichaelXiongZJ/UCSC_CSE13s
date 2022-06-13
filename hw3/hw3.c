/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw3.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool str_suffix(char *haystack, char *needle) {
	int str_len = strlen(haystack);
	int suf_len = strlen(needle);
	if(str_len >= suf_len){
		for(int a = 0; a < suf_len; a++){
			if(*(haystack + str_len - a - 1) != *(needle + suf_len - a - 1)){
				return false;
			}
		}
		return true;
	}
	return false;
}

float dot_product(float *vec_a, float *vec_b, int length) {
	float product = 0;
 	for(int a = 0; a < length; a++){
		product = product + (*(vec_a+a))*(*(vec_b+a));
	}
	return product;
}

int reduce(int *nums, int length, int (*f)(int,int), int initial) {
	int current = initial;
	for(int a = 0; a < length; a++){
		current = (*f)(current, *(nums+a));	
	}
	return current;
}


// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!

int maximum(int a, int b){
 	if(b > a){
		return b;
	}
	return a;

}

int sum_positive(int a, int b){
	if(b > 0){
		a += b;
	}
	return a;
}

int maximum_with_reduce(int *nums, int length) {
	return reduce(nums, length, *maximum, INT_MIN);
}

int sum_positive_with_reduce(int *nums, int length) {
	return reduce(nums, length, *sum_positive, 0);
}


