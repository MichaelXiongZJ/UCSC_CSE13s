stack_push:
	add the item onto the front of the stack *s, and allocate memory for it. Set the current top as next. return false if unable to do so, otherwise true

stack_pop:
	Remove the top value in the stack and put the value in the output pointer parameter. Set the next node as top, return false if stack is empty/null, otherwise true.

stack_empty:
	return true if the stack top is NULL, otherwise false.

stack_delete:
	use while loop to iterate thru all nodes, free() on everything. reset pointer to NULL

stack_compute_step:
	pop the top 2 values in the stack, do the calculation depends on the type. and push result on the front. return false if error, otherwise true.


