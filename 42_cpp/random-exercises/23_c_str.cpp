#include <iostream>
#include <string>

int main()
{
	std::string cppString = "bugra";

	const char *cString = cppString.c_str();

	std::cout << "C++ string:     " << cppString << std::endl;
	std::cout << "C-style string: " << cString << std::endl;

	return 0;
}
