#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "../../../Utils/stringNumbers.cpp"
#include "../../../Utils/time.cpp"

// self powers - last 10 digits of series 1^1 + 2^2 + ... 1000^1000

void run();
std::string power(std::string base, uint64_t power);

int main()
{
	std::cout << std::endl
			  << std::endl;

	auto start = std::chrono::steady_clock::now();
	run();
	std::cout << "\n\nElapsed(ms)=" << since(start).count() << std::endl;

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run()
{
	int goal{1000};

	std::string sum{"0"};
	std::string product{"1"};
	for (int i = 1; i <= goal; ++i)
	{
		product = power(std::to_string(i), i);
		sum = add(sum, product);
	}

	std::cout << "\n sum: " << sum;
	std::cout << "\n last 10 digits: " << sum.substr(sum.length() - 10, 10);
}
