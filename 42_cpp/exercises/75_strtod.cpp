#include <iostream>

// string to double

int main()
{
	char str[] = "5.3456abc";
	char *end;
	double num;

	num = strtod(str, &end);
	std::cout << num << std::endl; // 5.3456
	std::cout << end << std::endl; // abc
}
