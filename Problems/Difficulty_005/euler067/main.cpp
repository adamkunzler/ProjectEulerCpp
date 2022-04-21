#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include <fstream>
#include <string>

#include "../../../Utils/time.cpp"
#include "../../../Utils/numbers.cpp"
#include "../../../Utils/strings.cpp"

// maximum path sum 2

void run();
int numRows(int n);
std::vector<int> loadTriangle();

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
	std::vector<int> triangle = loadTriangle();

	int rows = numRows(triangle.size());

	// bottom to top starting at 2nd to last row
	for (int row = rows - 1; row > 0; --row)
	{
		for (int col = 0; col < row; ++col)
		{
			int parent = seriesSum(row - 1) + col;
			int child1 = seriesSum(row) + col;
			int child2 = seriesSum(row) + 1 + col;

			triangle[parent] += std::max(triangle[child1], triangle[child2]);
		}
	}

	std::cout << "\n\n Max Sum Path: " << triangle[0] << std::endl;

	// for (auto x : triangle)
	// 	std::cout << " " << x;
}

std::vector<int> loadTriangle()
{
	std::vector<int> data;

	std::ifstream file("triangle.txt");
	if (!file.is_open())
		return data;

	std::string line;
	while (std::getline(file, line))
	{
		auto elements = split(line, " ");
		for (auto x : elements)
			data.push_back(std::stoi(x));
	}

	file.close();

	return data;
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