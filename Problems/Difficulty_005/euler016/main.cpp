#include <iostream>
#include <ios>
#include <cmath>
#include <string>
#include <numeric>

#include "../../../Utils/strings.cpp"

// sum of the digits of a number

void run(uint64_t);

int main()
{
	std::cout << std::endl
			  << std::endl;

	run(15); // expected => 2^15 = 32768 = 3 + 2 + 7 + 6 + 8 = 26
	run(1000);

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run(uint64_t power)
{
	std::cout << "\n To Power " << power << std::endl;

	// calculate 2^power and convert to string (need to trim off trailing fractional pieces since std::pow returns double)
	auto product = std::to_string(std::pow(2, power));
	product = product.substr(0, product.find("."));

	// lambda to convert char to int and then sum
	auto lambda = [&](int a, char b)
	{
		int y = charToInt(b);
		// std::cout << "\t\t a: " << a << "\t b:" << y << std::endl;
		return a + y;
	};

	// calculate sum with lambda
	auto sum = std::accumulate(product.begin(), product.end(), 0, lambda);

	std::cout << "\tProduct: " << product << std::endl;
	std::cout << "\tSum: " << sum << std::endl;
}
