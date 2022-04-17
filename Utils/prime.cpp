#include <cmath>
#include <vector>
#include <iostream>
#include <cstdint>

//
// Simple method to determine if number is prime
//
template <class T>
bool isPrime(T n)
{
	if (n <= 1)
		return false;

	if (n <= 3)
		return true;

	if ((n % 2 == 0) || (n % 3 == 0))
		return false;

	for (T i = 5; i * i <= n; i += 6)
		if ((n % i == 0) || (n % (i + 2) == 0))
			return false;

	return true;
}

//
// Get all prime numbers less than n, inclusive (efficient up to n < 10 million)
//
// Time Complexity => O(n * log(log(n)))
//
template <class T>
std::vector<T> sieveOfEratosthenes(T n)
{
	// std::cout << "\n sieveOfEratosthenes: " << n << std::endl;

	// vector<bool> to represent if numbers from 0..n are prime (defaults to true...will set to false below)
	std::vector<bool> temp(n, true);

	for (T p = 2; p * p <= n; ++p)
	{
		// std::cout << "\n p = " << p << ", " << p * p << " <= " << n;
		//  current number is prime...mark all multiples of p
		//  greater than or equal to the square of it as not prime
		if (temp[p] == true)
		{
			for (T i = p * p; i <= n; i += p)
			{
				// std::cout << "\n\t" << i;
				temp[i] = false;
			}
		}
		// std::cout << std::endl;
	}
	// std::cout << std::endl;

	std::vector<T> primes;
	for (size_t i = 2; i < temp.size(); ++i)
	{
		if (temp[i] == true)
			primes.push_back(i);
	}

	return primes;
}

//
// Find all prime factors of a number n
//
// Time Complexity: O(log n)
//
template <class T>
std::vector<T> primeFactors(T n)
{
	std::vector<T> factors;

	T composite = 2;
	T num = n;

	while (num > 1)
	{
		// check if it's a factor
		if (num % composite == 0)
		{
			factors.push_back(composite);
			num /= composite;
		}
		else
		{
			composite++;
		}
	}

	return factors;
}

//
// Get the next prime after a number n
//
template <class T>
T nextPrime(T n)
{
	if (n <= 1)
		return 2;

	T prime = n;
	bool found = false;

	while (!found)
	{
		prime++;

		if (isPrime(prime))
			found = true;
	}

	return prime;
}

//
// Get the nth prime (e.g. 2, 3, 5, 7, 11, 13 ... 13 is the 6th prime)
//
template <class T>
T getNthPrime(T n)
{
	uint64_t prime = 1;

	for (uint64_t i = 0; i < n; ++i)
		prime = nextPrime(prime);

	return prime;
}