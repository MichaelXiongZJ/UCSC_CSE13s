str_suffix:
	Check from the end of the string, looping with pointer by the length of the suffix string, return false once they unmatch. Otherwise true.

dot_product:
	Find each pair of value using the pointer parameters, and loop with +1 on each of their pointer.

reduce:
	Create an int current = initial, call parameter function with parameters of reduce's parameter and current in a recursive loop. Set current = funciton output. Return current in the end.

max_with_reduce:
	call reduce, and pass in a helper function as parameter. helper: if value from array is bigger than it, return the value.

sum_positive_with_reduce:
	call reduce, and pass in a helper function as parameter. helper: if value > 0, sum += value. return the value.
