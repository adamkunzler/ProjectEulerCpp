#include <iostream>
#include <string>
#include <algorithm>

#include "../../../Utils/strings.cpp"

void test(std::string, std::string, std::string);

int main()
{
	// std::string a{"87"};
	// std::string b{"278"};
	std::string a{"999"};
	std::string b{"99"};

	test("999", "99", "1098");
	test("99", "999", "1098");
	test("1", "0", "1");
	try
	{
		test("", "123", "BAD DATA");
	}
	catch (const std::exception &e)
	{
		std::cerr << " " << e.what() << '\n';
	}
	test("123456", "656565", "780021");
	test("9898989898", "6767676767", "16666666665");
	test("16666666665", "65498745897914654", "65498762564581319");

	//   add(a, b);

	return EXIT_SUCCESS;
}

void test(std::string a, std::string b, std::string expected)
{
	std::string result = add(a, b);
	std::cout << "\n\n TEST => " << a << " + " << b << " = " << result;
	std::cout << "\n\t EXPECTED => " << expected << "\t" << (result == expected ? "PASS" : "FAIL");
}
