# Python3 Program to find the number
# in a range having maximum product
# of the digits

# Returns the product of digits
# of number x
def product(x) :
	
	prod = 1
	while (x) :
		prod *= (x % 10)
		x //= 10;
	
	return prod

# This function returns the number having
# maximum product of the digits
def findNumber(l, r) :
	
	# Converting both integers to strings
	a = str(l);
	b = str(r);

	# Let the current answer be r
	ans = r
	
	for i in range(len(b)) :
		if (b[i] == '0') :
			continue

		# Stores the current number having
		# current digit one less than current
		# digit in b
		curr = list(b)
		curr[i] = str(((ord(curr[i]) -
						ord('0')) - 1) + ord('0'))

		# Replace all following digits with 9
		# to maximise the product
		for j in range(i + 1, len(curr)) :
			curr[j] = str(ord('9'))
			
		# Convert string to number
		num = 0
		for c in curr :
			num = num * 10 + (int(c) - ord('0'))
			num = num % int(1e9+7)

		# Check if it lies in range and its
		# product is greater than max product
		if (num >= l and product(ans) < product(num)) :
			ans = num % int(1e9+7)

	return ans

# Driver Code
if __name__ == "__main__" :
	
	# 1000 100000000000000000 582926302
	l, r = 1000, 100000000000000000
	print(findNumber(l, r))

	l, r = 51, 62
	print(findNumber(l, r))

# This code is contributed by Ryuga
