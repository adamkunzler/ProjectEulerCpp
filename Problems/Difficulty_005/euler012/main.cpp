#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <chrono>

#include "../../../Utils/stringNumbers.cpp"
#include "../../../Utils/numbers.cpp"
#include "../../../Utils/time.cpp"

// first triangular number to have over 500 divisors
// forumla => 1/2 * n * (n + 1)
// think of as additive analog of factorial (e.g. n + (n - 1) + .. + 2 + 1)
// 1, 1 + 2, 1 + 2 + 3, 1 + 2 + 3 + 4, etc...

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
	bool found = false;
	uint64_t n = 0;
	for (uint64_t i = 1; !found; ++i)
	{
		// calculate next triangle number
		n += i;

		auto factors = factor(n);

		if (factors.size() > 500)
		{
			// if (n > 50)
			found = true;
			for (auto x : factors)
				std::cout << x << " ";
		}
	}
}
