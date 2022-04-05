#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// square of sum minus sum of squares of first x natural numbers

void run(int max);

int main()
{
	run(100);

	return EXIT_SUCCESS;
}

void run(int max)
{
	int sum = (max / 2) * (1 + max);
	int sumSquared = sum * sum;
	std::cout << "Sum Squared: " << sumSquared << std::endl;

	int sumOfSquares = (max * (max + 1) * ((max * 2) + 1)) / 6;
	std::cout << "Sum of Squares: " << sumOfSquares << std::endl;

	int diff = sumSquared - sumOfSquares;
	std::cout << "Diff: " << diff << std::endl;
}
