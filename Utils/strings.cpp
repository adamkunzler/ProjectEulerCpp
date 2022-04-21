#include <vector>
#include <string>

//
// splits a string by the specified delimiter
// 	(modifies s (so passing by value))
//
std::vector<std::string> split(std::string s, std::string delimiter)
{
	std::vector<std::string> result;

	size_t position = 0;
	std::string token;

	// loop while the delimiter exists in the string s
	while ((position = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, position);
		result.push_back(token);
		s.erase(0, position + delimiter.length());
	}

	if (s.length() > 0)
		result.push_back(s);

	return result;
}

std::string removeChar(std::string str, char c)
{
	std::string result;
	for (size_t i = 0; i < str.size(); i++)
	{
		char currentChar = str[i];
		if (currentChar != c)
			result += currentChar;
	}
	return result;
}