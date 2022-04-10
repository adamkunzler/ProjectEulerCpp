#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// sum of even fibonacci

void run(int max);

int main()
{
	run(4000000);

	return EXIT_SUCCESS;
}

void run(int max)
{
	int current = 1;
	int previous = 1;

	std::vector<int> evens;

	while (current <= max)
	{
		std::cout << current << ", ";

		if (current % 2 == 0)
			evens.push_back(current);

		int temp = current + previous;
		previous = current;
		current = temp;
	}

	long sum = std::accumulate(evens.begin(), evens.end(), 0);
	std::cout << "\n sum: " << sum << std::endl;
}
