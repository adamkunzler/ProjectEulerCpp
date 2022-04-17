#include <iostream>
#include <numeric>

#include "../../../Utils/prime.cpp"

// sum of primes below 2 million

void run(uint64_t);

int main()
{
	std::cout << std::endl
			  << std::endl;

	// run(10); // expected => 17
	run(2000000);

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run(uint64_t max)
{
	std::vector<uint64_t> primes = sieveOfEratosthenes<uint64_t>(max);
	uint64_t sum2 = std::accumulate<>(primes.begin(), primes.end(), 0);

	uint64_t sum = 0;
	for (uint64_t i = 1; i < max; ++i)
	{
		if (isPrime(i))
			sum += i;
	}
	std::cout << "Sum: " << sum << std::endl;
	std::cout << "Sum2: " << sum2 << std::endl;
}
