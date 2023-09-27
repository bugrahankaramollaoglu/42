#include <iostream>
#include <cstdint>

/* uintptr_t is an unsigned integer type that holds the value of a pointer.
often used in low-level programming when you need to manipulate raw memory
addresses, perform pointer arithmetic, or perform operations that require
treating pointers as integers */

int main()
{
	int x = 42;
	int *ptr = &x;

	std::cout << "ptr: " << ptr << std::endl;					   // 0x7ffc8936324c
	uintptr_t uinVal = reinterpret_cast<uintptr_t>(ptr);		   // Convert pointer to uintptr_t
	std::cout << "uinVal: " << uinVal << std::endl;				   // 140722610516556
	int *newPtr = reinterpret_cast<int *>(uinVal);				   // Convert uintptr_t back to a pointer
	std::cout << "Value through newPtr: " << *newPtr << std::endl; // 42
	std::cout << "Value through newPtr: " << newPtr << std::endl;  // 0x7ffc8936324c (#1 ile aynı)

	return 0;
}
