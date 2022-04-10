#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// find the smallest number that is evenly divided by each number from 1 to n

// TODO - find way to optimize...find LCM of each value from 1 to n and then multiply

void run(int max);

int main()
{
	run(20);

	return EXIT_SUCCESS;
}

void run(int max)
{
	// brute force
	int current = max;
	while (true)
	{
		bool isFound = true;
		for (int i = 2; i <= max; i++)
		{
			if (current % i != 0)
			{
				isFound = false;
				break;
			}
		}

		if (isFound)
			break;

		// not found
		current++;
	}

	std::cout << "\n Smallest number: " << current << std::endl;
}
