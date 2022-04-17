#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#include "../../../Utils/strings.cpp"

std::string multiply(std::string, std::string);
void test(std::string, std::string, std::string);

int main()
{
	// std::string a{"27"};
	// std::string b{"3"}; // 81
	// std::string a{"27"};
	// std::string b{"13"}; // 351
	std::string a{"67"};
	std::string b{"84"}; // 5628
	std::cout << "\n Multiply: " << a << " x " << b << " = " << multiply(a, b);
	std::cout << "\n\n";

	return EXIT_SUCCESS;
}