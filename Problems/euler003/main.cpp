#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>

#include "../../Utils/prime.cpp"

// largest prime factor of a number

void run(uint64_t);

int main()
{
	// run(13195); // expected 5 7 13 29
	run((uint64_t)600851475143);

	return EXIT_SUCCESS;
}

void run(uint64_t num)
{
	// std::vector<uint64_t> primes = sieveOfEratosthenes(num / 2);
	auto factors = primeFactors(num);
	for (auto i : factors)
		std::cout << " " << i;
}
