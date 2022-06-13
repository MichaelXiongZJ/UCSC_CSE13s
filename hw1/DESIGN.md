area_of_disk:
	Return A = Pi*r^2
area_of_ring:
	Return A = Pi*(R^2-r^2)
bigger_minus_smaller:
	Input x, y
	If (y > x){
		temp = y
		y = x
		x = temp
	}
	return x - y
value_in_range:
	if (x>low && x<high){
		return true
	}else{
		return false
	}
caat:
Make a new array of char, and copy each char from the input and paste it twice in the new array.
