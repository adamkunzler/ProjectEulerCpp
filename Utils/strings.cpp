#include <vector>
#include <string>
#include <stdexcept>
#include <algorithm>

int charToInt(char c)
{
	return c - '0';
}

char intToChar(int i)
{
	return i + '0';
}

//
// modifies s (so passing by value)
//
std::vector<std::string> split(std::string s, std::string delimiter)
{
	std::vector<std::string> result;

	size_t position = 0;
	std::string token;

	// loop while the delimiter exists in the string s
	while ((position = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, position);
		result.push_back(token);
		s.erase(0, position + delimiter.length());
	}

	if (s.length() > 0)
		result.push_back(s);

	return result;
}

//
// lambda to sum digits in string (e.g. "123" = 1 + 2 + 3 = 6)
//
auto lambdaStringDigitsSum = [&](int a, char b)
{
	int x = charToInt(b);
	return a + x;
};

//
// add two numbers represented as strings
//
std::string add(std::string a, std::string b)
{
	if (a.length() == 0 || b.length() == 0)
		throw std::invalid_argument("INVALID NUMBER");

	std::string result{""};

	// figure out the length of the longest number
	size_t max = std::max(a.length(), b.length());

	int carry{0};
	for (size_t i = 0; i < max; ++i)
	{
		// get last digits
		int digitA = (i >= a.length()) ? 0 : charToInt(a[a.length() - (1 + i)]);
		int digitB = (i >= b.length()) ? 0 : charToInt(b[b.length() - (1 + i)]);

		// sum the digits
		std::string sum = std::to_string(digitA + digitB + carry);
		carry = 0;

		// if sum is a single digit (e.g. 3 + 5 = 8)...add it to the result
		// if sum is 2 digits (e.g. 8 + 4 = 12)...add the last digit (e.g. 2) to the result carry the first digit
		if (sum.length() == 1)
		{
			result.push_back(sum[0]);
		}
		else
		{
			carry = charToInt(sum[0]);
			result.push_back(sum[1]);
		}

		// if this is the last digit in the max number and carry has a value
		// add the carry digit to the result
		if ((i == max - 1) && (carry > 0))
		{
			result.push_back(intToChar(carry));
		}
	}

	// built the result backwards...need to reverse it to get correct answer
	std::reverse(result.begin(), result.end());

	return result;
}

//
// multiply two numbers represented as strings
//
std::string multiply(std::string a, std::string b)
{
	// order inputs from large to small
	std::string largeNum;
	std::string smallNum;
	if ((a.length() >= b.length()))
	{
		largeNum = a;
		smallNum = b;
	}
	else
	{
		largeNum = b;
		smallNum = a;
	}

	// std::cout << "\n largeNum: " << largeNum << "\tsmallNum: " << smallNum;

	std::vector<std::string> numsToAdd;

	// loop over digits of small number, multiplying by the digits of the large number
	for (size_t i = 0; i < smallNum.length(); ++i)
	{
		std::string numToAdd;

		// add trailing 0s
		for (size_t k = 0; k < i; ++k)
		{
			numToAdd.push_back('0');
		}

		int digit = charToInt(smallNum[smallNum.length() - 1 - i]);
		int carry{0};
		for (size_t j = 0; j < largeNum.length(); ++j)
		{
			// get the largeNum digit
			int d = charToInt(largeNum[largeNum.length() - 1 - j]);
			// std::cout << "\n\n multiplying " << digit << " by " << d;

			// calculate the product of the two digits
			std::string product = std::to_string(digit * d + carry);
			carry = 0;
			// std::cout << "\n product " << product;

			// if product is a single digit (e.g. 3 + 2 = 6)...add it to the result
			// if product is 2 digits (e.g. 3 * 7 = 21)...add the last digit (e.g. 1) to the result carry the first digit
			if (product.length() == 1)
			{
				numToAdd.push_back(product[0]);
			}
			else
			{
				carry = charToInt(product[0]);
				numToAdd.push_back(product[1]);
			}

			// if this is the last digit in the large number and carry has a value
			// add the carry digit to the numToAdd
			if ((j == largeNum.length() - 1) && (carry > 0))
			{
				numToAdd.push_back(intToChar(carry));
			}

			// std::cout << "\n numToAdd: " << numToAdd;
		}

		// reverse the numToAdd and add to list of numbers to add together
		std::reverse(numToAdd.begin(), numToAdd.end());
		numsToAdd.push_back(numToAdd);
	}

	// add all the nums together
	// std::cout << "\n\n Numbers to add:";
	// for (auto x : numsToAdd)
	// std::cout << "\n\t" << x;

	if (numsToAdd.size() == 1)
		return numsToAdd[0];

	std::string result{"0"};
	for (auto x : numsToAdd)
		result = add(result, x);

	// std::cout << "\n\n result: " << result;

	return result;
}

//
// calculate factorial for numbers represented as strings
//
std::string factorial(std::string n)
{
	std::string result{"1"};
	int num = std::stoi(n);
	for (int i = num; i > 1; --i)
	{
		result = multiply(result, std::to_string(i));
		// std::cout << "\n i = " << i << "\t\tresult: " << result;
	}
	return result;
}