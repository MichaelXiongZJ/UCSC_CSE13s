/*
 * All of your code goes in here. You need to finish these functions.
 */

#include "hw2.h"

int next_collatz_number(int n) {
	if(n == 1){
		return 1;
	}else if(n%2 == 0){
		return n/2;
	}else{
		return n*3 + 1;
	}
}

int count_collatz_steps(int n) {
	if(n == 1){
		return 0;
	}else if(n%2 == 0){
		return count_collatz_steps(n/2) + 1;
	}else{
		return count_collatz_steps(n*3+1) + 1;
	}
}

int maximum(int *nums, int len) {
	int max = 0;
	int a;
	for(a = 0; a < len; a++){
		if(nums[a] > max){
			max = nums[a];
		}
	}
	return max;
}

int sum_positive(int *nums, int len) {
	int sum = 0;
	int a;
	for(a = 0; a < len; a++){
		if(nums[a] > 0){
			sum += nums[a];
		}
	}
	return sum;
}

int count_negative(int *nums, int len) {
	int count = 0;
	int a;
	for(a = 0; a < len; a++){
		if(nums[a] < 0){
			count++;
		}
	}
	return count;
}
