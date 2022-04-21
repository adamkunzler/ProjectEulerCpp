#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <algorithm>

#include "../../../Utils/time.cpp"
#include "../../../Utils/strings.cpp"

// number letter counts
//  1 to 3 = one two three = 3 + 3 + 5 = 15 letters used

void run();
std::string numberToWord(int);

int main()
{
	std::cout << std::endl
			  << std::endl;

	auto start = std::chrono::steady_clock::now();
	run();
	std::cout << "\n\nElapsed(ms)=" << since(start).count() << std::endl;

	std::cout << std::endl
			  << std::endl;

	return EXIT_SUCCESS;
}

void run()
{
	int count = 0;
	std::string temp;

	for (int i = 1; i <= 1000; ++i)
	{
		std::string word = numberToWord(i);
		std::cout << "\n " << word << "\t" << word.length();

		for (auto c : word)
			if (c != '-' && c != ' ')
				count++;

		// count += word.length();
	}

	// std::cout << "\n17: " << numberToWord(17);
	// std::cout << "\n10: " << numberToWord(10);
	// std::cout << "\n110: " << numberToWord(110);
	// std::cout << "\n117: " << numberToWord(117);
	// std::cout << "\n137: " << numberToWord(137);

	std::cout << "\nCount: " << count;
}

std::string digits[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string teens[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string tens[] = {"ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

//
// returns the word form of a number. e.g. 315 = three hundred and fifteen
// TODO: refactor as class
//
std::string numberToWord(int n)
{

	auto getTens = [](int x)
	{
		if (x > 10 && x < 20)
			return teens[x - 10];

		int tensPlace = (x / 10);
		int onesPlace = (x % 10);

		std::string number{tens[tensPlace - 1]};
		if (tensPlace > 0 && onesPlace > 0)
			number += "-" + digits[onesPlace];
		else if (onesPlace > 0)
			number += digits[onesPlace];

		return number;
	};

	auto getHundreds = [](int x, auto getTens)
	{
		std::string number{""};
		number += digits[x / 100] + " hundred";

		if (x % 100 == 0)
			return number;

		number += " and " + getTens(x % 100);
		return number;
	};

	// handle numbers 1 - 9
	if (n < 10)
		return digits[n];

	// handle numbers 10 - 19
	if (n < 20)
		return teens[n - 10];

	// handle numbers 20 - 99
	if (n < 100)
		return getTens(n);

	// handle number 100 - 999
	if (n < 1000)
	{
		return getHundreds(n, getTens);
	}

	if (n == 1000)
		return "one thousand";

	return "<UKNOWN>";
}
