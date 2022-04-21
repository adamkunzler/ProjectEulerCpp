#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>

#include "../../../Utils/time.cpp"

// maximum path sum 1
/*

Find the maximum total from top to bottom of the triangle below:

			  75
			 95 64
			17 47 82
		   18 35 87 10
		  20 04 82 47 65
		 19 01 23 75 03 34
		88 02 77 73 07 63 67
	   99 65 04 28 06 16 70 92
	  41 41 26 56 83 40 80 70 33
	 41 48 72 33 47 32 37 16 94 29
	53 71 44 65 25 43 91 52 97 51 14
   70 11 33 28 77 73 17 78 39 68 17 57
  91 71 52 38 17 14 91 43 58 50 27 29 48
 63 66 04 68 89 53 67 30 73 16 69 87 40 31
04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

*/
void run();
int numRows(int n);
int seriesSum(int);

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
	/*
								3-0
							7-1		4-2
						2-3		4-4		6-5
					8-6		5-7		9-8		3-9

	*/
	std::vector<int> triangle2{3, 7, 4, 2, 4, 6, 8, 5, 9, 3};
	std::vector<int> triangle{
		75,
		95, 64,
		17, 47, 82,
		18, 35, 87, 10,
		20, 4, 82, 47, 65,
		19, 1, 23, 75, 3, 34,
		88, 2, 77, 73, 7, 63, 67,
		99, 65, 4, 28, 6, 16, 70, 92,
		41, 41, 26, 56, 83, 40, 80, 70, 33,
		41, 48, 72, 33, 47, 32, 37, 16, 94, 29,
		53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14,
		70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57,
		91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48,
		63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31,
		4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};

	int rows = numRows(triangle.size());
	// std::cout << "\n rows: " << rows;

	// bottom to top starting at 2nd to last row
	for (int row = rows - 1; row > 0; --row)
	{
		// std::cout << "\n\n row:" << row;

		for (int col = 0; col < row; ++col)
		{
			int parent = seriesSum(row - 1) + col;
			int child1 = seriesSum(row) + col;
			int child2 = seriesSum(row) + 1 + col;

			// std::cout << "\n parent: " << triangle[parent];
			// std::cout << "\n\t child 1: " << triangle[child1];
			// std::cout << "\n\t child 2: " << triangle[child2];

			triangle[parent] += std::max(triangle[child1], triangle[child2]);
		}
	}

	std::cout << "\n\n Max Sum Path: " << triangle[0] << std::endl;

	// for (auto x : triangle)
	// 	std::cout << " " << x;
}

int seriesSum(int n)
{
	return ((n * (1 + n)) / 2);
}

int numRows(int n)
{
	int rows = 0;
	int i = 1;
	while (n > 0)
	{
		n -= i++;
		rows++;
	}
	return rows;
}