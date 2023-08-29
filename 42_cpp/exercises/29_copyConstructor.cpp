#include <iostream>

// bir objeyi başka bir objeye kopyalamak için kullanılır

// In C++, the copy constructor is typically defined with a specific signature:
// className(const className &old)

/* if you do not explicitly define a copy constructor
for your class, C++ will provide a default copy constructor
that performs a shallow copy. This means that the member
variables are copied, but if those variables themselves
are pointers or have dynamically allocated memory,
only the memory addresses will be copied, not the actual data.  */

class Deneme
{
private:
	int data;

public:
	// constructor
	Deneme(int val)
	{
		data = val;
	}

	// copy constructor
	Deneme(const Deneme &old)
	{
		data = old.data;
		std::cout << "copy constructor called" << std::endl;
	}

	void display()
	{
		std::cout << "Data: " << data << std::endl;
	}
};

int main()
{
	Deneme obj1(12);
	Deneme obj2 = obj1; // copy constructor called
	obj1.display();
	obj2.display();
}
