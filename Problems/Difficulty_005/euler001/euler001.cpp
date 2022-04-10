#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

// multiples of 3 and 5

void run(int max);
std::vector<int> getMultiplesOf(int num, int max);

int main()
{
	run(1000);

	return EXIT_SUCCESS;
}

void run(int max)
{
	std::vector<int> v1 = getMultiplesOf(3, max);
	std::vector<int> v2 = getMultiplesOf(5, max);
	v1.insert(v1.end(), v2.begin(), v2.end());

	std::set<int> multiples;
	for (int n : v1)
		multiples.insert(n);

	int sum = std::accumulate(multiples.begin(), multiples.end(), 0);

	// for (int n : multiples)
	// 	std::cout << n << ", ";

	// std::cout << std::endl;

	std::cout << "sum: " << sum << std::endl;
}

std::vector<int> getMultiplesOf(int num, int max)
{
	std::vector<int> result;
	int current = num;

	while (current < max)
	{
		result.push_back(current);
		current += num;
	}

	return result;
}
