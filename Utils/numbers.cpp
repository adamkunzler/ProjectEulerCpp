#include <set>
#include <cmath>

// isPythagorean() -- see euler009
// collatz sequence -- see euler014
// sumOfSeries => int sum = (n * (1 + n)) / 2) e.g. 1 + 2 + 3 + 4 + .. + n
// sumOfSquares => int sumOfSquares = (max * (max + 1) * ((max * 2) + 1)) / 6; e.g. 1*1 + 2*2 + 3*3 + 4*4 + .. + n*n
// fibonacci - get x number, get nth, get all less than max

// misc.cpp
// isPalindrome -- see euler004

template <class T>
std::set<T> factor(T n)
{
	std::set<T> factors;

	T s = (T)std::sqrt(n);
	for (T i = 1; i <= s; ++i)
	{
		if (n % i > 0)
			continue;

		factors.insert(i);
		factors.insert(n / i);
	}

	return factors;
}

int seriesSum(int n)
{
	return ((n * (1 + n)) / 2);
}