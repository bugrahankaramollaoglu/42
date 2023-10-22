#include <iostream>

class MyClass
{
private:
	int value;

public:
	MyClass(int v) : value(v) {}

	// Const member function
	int getValue() const
	{
		return value;
	}

	// Non-const member function
	void setValue(int v)
	{
		value = v;
	}
};

int main()
{
	const MyClass obj(50);

	int val = obj.getValue(); // Calling a const member function is allowed
	std::cout << val << "\n"; // 50

	// obj.setValue(10); // Error: Cannot call a non-const member function on a const object
}

/* 	// 1. const: func will not modify data members of the class
	// 2. const: func will not modify the object it is called on
	const std::string fun() const; */

