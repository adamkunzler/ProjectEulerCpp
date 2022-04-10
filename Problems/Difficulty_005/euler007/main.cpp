#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#include "../../../Utils/prime.cpp"

// 10001st prime number

void run(uint64_t);

int main()
{
	run(10001);

	return EXIT_SUCCESS;
}

void run(uint64_t n)
{
	uint64_t prime = getNthPrime(n);
	std::cout << "\n " << n << "th prime => " << prime;
}
