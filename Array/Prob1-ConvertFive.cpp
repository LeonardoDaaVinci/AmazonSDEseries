Convert Five:
	ConvertFive program states that for a given n digit number, replace all the digits whose value is 0 with 5.

Required Functions to solve this:
	The solution for this problem has two important modules to it.
	1.  Convert the given n digit number into vector of digits --> vector<int> getDigits (int n)
	2. 	Convert digits to back to number --> int GetNumberFromDigits(vector<int> digits)
	
Solution:
	1.Let the given number be X.
	2.The first step of the solution is to convert the number X into vector of digits. 
	3.Replace all the digits whose value is 0 with 5, in the above extracted digit array.This shall be done in the
		second step itself.
	4.Now having all the digits from unit (at position 0) through the end, recreate the number 
		by multiplying digits with powers of 10 and adding it accordingly
	
Code:

// Get the digits of number 
// O(n)
vector<int> getDigits(int x)
{
	vector<int> res;
	while (x >9)
	{
		int rem = x % 10;
		if (rem == 0)
			res.push_back(5);
		else
			res.push_back(rem);

		x = x / 10;
	}
	res.push_back(x);
	return res;
}

// Function to recreate a number from digits with 
// digits[0] implying the unit position.
// O(n)
int getNumber(vector<int> digits)
{
	int res=0;
	for (int i = 0; i<digits.size(); i++)
	{
		res += digits[i] * pow(10, i);
	}
	return res;
}

// Function that replaces all the digits whose value is 0 with 5.
// O(n)
int convertFive(int n) {
	// Your code here
	int res=0;
	vector<int> digits = getDigits(n);
	res = getNumber(digits);
	return res;
}