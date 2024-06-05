#include <iostream>

/* References are essentially aliases, while pointers
are variables that store memory addresses. */

/* References cannot be reassigned after initialization,
while pointers can be changed to point to different objects. */

/* References are often used in function parameters
to avoid copying large objects and to allow functions
to modify the original data. This is particularly
useful for passing objects by reference: */

void modifyValue(int &num)
{
	num = 99;
}

int main()
{
	int value = 10;
	modifyValue(value); 
	std::cout << value << "\n"; // 99
}
