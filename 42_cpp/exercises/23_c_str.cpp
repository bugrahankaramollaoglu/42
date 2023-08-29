#include <iostream>
#include <string>

int main()
{
	std::string cppString = "bugra";

	// Using c_str() to obtain a C-style string
	const char *cString = cppString.c_str();

	std::cout << "C++ string:     " << cppString << std::endl;
	std::cout << "C-style string: " << cString << std::endl;

	return 0;
}
