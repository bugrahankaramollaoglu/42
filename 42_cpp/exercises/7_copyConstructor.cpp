#include <iostream>

/* A copy constructor in C++ is a special constructor
that's used to create a new object as a copy of
an existing object of the same class:

	ClassName(const ClassName& other);

1) Implicit Copying: Whenever you create a new object using an
existing object, the copy constructor can be invoked
implicitly by the compiler.

ClassName obj1;        // Create an object
ClassName obj2 = obj1; // Implicit invocation of copy constructor

2) Explicit Copying: You can also explicitly call the copy
constructor to create a copy of an object.

ClassName obj1;
ClassName obj2(obj1);  // Explicit invocation of copy constructor

3) Defining the Copy Constructor: When you don't provide a custom copy constructor,
the compiler generates a default copy constructor that performs a shallow
copy (bitwise copy) of the object's members. However, if your class contains
dynamic memory allocations, resource handles, or other complex data, you might
need to define a custom copy constructor to ensure proper copying behavior.

class DynamicArray {
private:
	int* data;
	int size;
public:
	// Constructor
	DynamicArray(int s) : size(s) {
		data = new int[size];
	}

	// Copy Constructor (Deep Copy)
	DynamicArray(const DynamicArray& other) : size(other.size) {
		data = new int[size];
		for (int i = 0; i < size; ++i) {
			data[i] = other.data[i];
		}
	}

	// Destructor
	~DynamicArray() {
		delete[] data;
	}
};	*/


