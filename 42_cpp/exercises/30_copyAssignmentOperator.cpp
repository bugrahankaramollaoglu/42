#include <iostream>

// bir objeyi kopyalarken = operatörü kullanılır
// copy assignment operators' syntax: className &operator=(const className &old)

// The copy assignment operator is called whenever selected by overload resolution,
// e.g. when an object appears on the left side of an assignment expression.
// The default copy assignment operator performs a memberwise (shallow) copy,
// where each member is copied by its own copy assignment operator
// (which may also be programmer-declared or compiler-generated).
// The copy assignment operator is also used to implement copy semantics for return by value
// and as the argument in pass-by-value.

class MyClass
{
private:
	int data;

public:
	// Constructor
	MyClass(int value) : data(value) {}

	// Copy Assignment Operator
	MyClass &operator=(const MyClass &old)
	{
		// if it is the same object
		// no need to copy
		if (this != &old)
		{
			data = old.data;
			return *this; // Handling self-assignment
		}
		return *this;
	}

	void display()
	{
		std::cout << data << std::endl;
	}
};

int main()
{
	// Create two objects
	MyClass obj1(10);
	MyClass obj2(20);

	// Display initial data of objects
	std::cout << "\nObject 1: ";
	obj1.display();

	std::cout << "Object 2: ";
	obj2.display();

	// Use the copy assignment operator to copy data from obj1 to obj2
	obj2 = obj1;
	std::cout << "\nkopyalamadan sonra\n"
			  << std::endl;

	// Display updated data of objects
	std::cout << "Object 1: ";
	obj1.display();

	std::cout << "Object 2: ";
	obj2.display();
	std::cout << std::endl;

	return 0;
}
