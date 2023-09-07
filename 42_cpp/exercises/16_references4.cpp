#include <iostream>

void adder(int &ref)
{
	ref += 5;
}

int main()
{
	int x = 12;
	int &xRef = x;
	adder(xRef);
	std::cout << x << "\n";
}

