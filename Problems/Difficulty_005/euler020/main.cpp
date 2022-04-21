#include <iostream>
#include <ios>
#include <cmath>
#include <string>
#include <numeric>

#include "../../../Utils/stringNumbers.cpp"

// sum of the digits of 100!

void run(std::string);

int main()
{
	std::cout << std::endl
			  << std::endl;

	run("100"); // expected => 10! = 3628800 = 3+6+2+8+8+0+0 = 27
	// run("100");

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run(std::string n)
{
	// std::cout << "\nTEST => " << factorial(100) << std::endl;

	std::string f = factorial(n);
	// std::cout << "\n\n factorial: " << f;

	auto sum = std::accumulate(f.begin(), f.end(), 0, lambdaStringDigitsSum);

	std::cout << "\n"
			  << n << "! => " << f << std::endl;
	std::cout << "\tSum: " << sum << std::endl;
}
