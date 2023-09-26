#include <iostream>

int main()
{
	int x = 42;

	void *vPtr = &x;
	int *intPtr = static_cast<int *>(vPtr);
	std::cout << *intPtr << std::endl; // 42
}
