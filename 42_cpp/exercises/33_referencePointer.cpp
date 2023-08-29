#include <iostream>

int main()
{
	int num = 54;
	int *numPtr = &num;
	int &numRef = num;

	// num == *numPtr == numRef

	std::cout << "num = " << num << std::endl; // 54
	*numPtr = 23;
	std::cout << "num = " << num << std::endl; // 23
	numRef = 12;
	std::cout << "num = " << num << std::endl; // 12
}
