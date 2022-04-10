#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdint>
#include <string>

// largest palindrome product

void run();
bool isPalindrome(uint32_t n);

int main()
{
	run();

	return EXIT_SUCCESS;
}

void run()
{
	uint32_t max = 999;
	uint32_t current = 0;
	uint32_t lhs = 0;
	uint32_t rhs = 0;
	uint32_t sum = 0;

	for (uint32_t i = 1; i <= max; ++i)
	{
		for (uint32_t j = 1; j <= max; ++j)
		{
			sum = i * j;
			if (isPalindrome(sum) && (sum > current))
			{
				lhs = i;
				rhs = j;
				current = sum;

				std::cout << "PALINDROME FOUND: " << current << " = " << lhs << " x " << rhs << std::endl;
			}
		}
	}

	std::cout << "\n LARGEST PALINDROME => "
			  << current << " = " << lhs << " x " << rhs << std::endl;
}

bool isPalindrome(uint32_t n)
{
	std::string word = std::to_string(n);
	std::string word2{word};

	std::reverse(word2.begin(), word2.end());

	return (word == word2);
}
