#include <iostream>
#include <vector>

// collatz sequence - starting number under 1 million has the longest chain
//
// n -> n/2 (n is even)
// n -> 3n + 1 (n is odd)
//
// e.g. 13 40 20 10 5 16 8 4 2 1

void run();
unsigned int collatz(unsigned int);
std::vector<unsigned int> collatzSequence(unsigned int);

int main()
{
	std::cout << std::endl
			  << std::endl;

	run();

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run()
{
	size_t max{0};
	std::vector<unsigned int> maxSequence;

	for (size_t i = 2; i < 1000000; ++i)
	{
		auto sequence = collatzSequence(i);
		if (sequence.size() > max)
		{
			max = sequence.size();
			maxSequence = sequence;
		}
	}

	std::cout << "Collatz(" << maxSequence[0] << ") => \t";
	for (auto x : maxSequence)
		std::cout << x << " ";
	std::cout << "\nChain Length:\t" << maxSequence.size();

	// auto sum = std::accumulate(f.begin(), f.end(), 0, lambdaStringDigitsSum);
}

std::vector<unsigned int> collatzSequence(unsigned int startN)
{
	unsigned int n = startN;
	std::vector<unsigned int> sequence;
	sequence.push_back(n);

	for (;;)
	{
		n = collatz(n);
		sequence.push_back(n);

		if (n == 1)
			break;
	}
	return sequence;
}

unsigned int collatz(unsigned int n)
{
	if (n % 2 == 0)
		return n / 2;
	return 3 * n + 1;
}