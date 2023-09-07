#include <iostream>

class MyClass
{
private:
	int value;

public:
	MyClass(int v) : value(v) {}

	// Const member function
	int getValue() const {
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
	const MyClass obj(50);	  // Create a const object
	int val = obj.getValue(); // Calling a const member function is allowed
	std::cout << val << "\n";
	// obj.setValue(10); // Error: Cannot call a non-const member function on a const object
}
