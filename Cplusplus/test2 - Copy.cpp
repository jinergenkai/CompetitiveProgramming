// CPP Program to find the number in a
// range having maximum product of the
// digits

#include <bits/stdc++.h>
using namespace std;

// Returns the product of digits of number x
int product(int x)
{
	int prod = 1;
	while (x) {
		prod *= (x % 10);
		x /= 10;
	}
	return prod;
}

// This function returns the number having
// maximum product of the digits
int findNumber(string a, string b)
{
	// Converting both integers to strings


	// Let the current answer be r
	int ans = r;
	for (int i = 0; i < b.size(); i++) {
		if (b[i] == '0')
			continue;

		// Stores the current number having
		// current digit one less than current
		// digit in b
		string curr = b;
		curr[i] = ((curr[i] - '0') - 1) + '0';

		// Replace all following digits with 9
		// to maximise the product
		for (int j = i + 1; j < curr.size(); j++)
			curr[j] = '9';

		// Convert string to number
		int num = 0;
		for (auto c : curr)
			num = num * 10 + (c - '0');

		// Check if it lies in range and its product
		// is greater than max product
		if (num >= l && product(ans) < product(num))
			ans = num;
	}

	return ans;
}

// Driver Code
int main()
{
    string a, b; cin >> a >> b;
    findNumber(a, b);
}
