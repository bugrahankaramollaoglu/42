#include <iostream>

/* reference ile pointer arasındaki fark nedir

1) pointer adres tutan değişkenlerdir, referans ise birer aliastır
2) pointerlar null olabilir referanslar olamaz
3) pointerlar başka objeye atanabilir referanslar değişmez
4) aritmetik işlemleri pointerla yaparsin referansla yapamazsin

Use pointers when you need dynamic memory management, nullable
objects, or need to reassign the pointer to different objects

Use references when you want to avoid null references, have a
simpler syntax for function parameters, or want to provide
an alias for an existing object

Always prefer references over pointers for function parameters
when you don't need to modify the parameter, as they provide
safety and cleaner syntax. */

int main()
{
	int num = 42;
	int *ptr = &num; // Pointer to int
	int &ref = num;	 // Reference to int

	std::cout << "Original value: " << num << std::endl;

	// Using a pointer to modify the value
	*ptr = 99; // Dereference the pointer and assign a new value
	std::cout << "After modifying with pointer: " << num << std::endl;

	// Using a reference to modify the value
	ref = 99; // Modify the value through the reference
	std::cout << "After modifying with reference: " << num << std::endl;

	return 0;
}
