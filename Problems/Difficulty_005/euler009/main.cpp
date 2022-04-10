#include <iostream>

typedef unsigned int uint;

// pythagorean triplet => a < b < c, for which, a^2 + b^2 = c^2
// find pythagorean triplet where a + b + c  = 1000

void run();

int main()
{
	run();

	return EXIT_SUCCESS;
}

void run()
{
	for (uint a = 1; a <= 1000; ++a)
		for (uint b = 1; b <= 1000; ++b)
			for (uint c = 1; c <= 1000; ++c)
			{
				bool sumIsThousand = (a + b + c == 1000);
				bool isPythagorean = (a * a + b * b == c * c);
				if (sumIsThousand && isPythagorean)
				{
					std::cout << "\n"
							  << a << " + " << b << " + " << c << " = 1000\n";
					break;
				}
			}
}
