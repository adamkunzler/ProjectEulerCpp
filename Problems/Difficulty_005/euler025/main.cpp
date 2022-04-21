#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "../../../Utils/stringNumbers.cpp"
#include "../../../Utils/time.cpp"

// index of first fibonacci number to contain 1000 digits

void run();

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
	int goalDigits{1000};

	std::string n{""};
	std::string nMinus1{"1"};
	std::string nMinus2{"1"};
	uint64_t i = 2;
	while (true)
	{
		n = add(nMinus1, nMinus2);

		nMinus2 = nMinus1;
		nMinus1 = n;
		i++;

		// std::cout << "\ni: " << i << "\tn: " << n;

		if (n.length() == goalDigits)
			break;
	}

	std::cout << "\ni: " << i << "\tn: " << n;
	// std::cout << "\nn: " << n;
	// std::cout << "\nfib: " << fib;
}
