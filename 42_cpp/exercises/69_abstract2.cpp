#include <iostream>

/* In C++, when you inherit from a base class with a pure
virtual function, you are required to provide an
implementation for that pure virtual function in the
derived class. */

class AClass
{
public:
	AClass() {}
	~AClass() {}

public:
	virtual void sayHello() = 0;
};

class Derived : AClass
{
public:
	Derived() {}
	~Derived() {}

	void sayHello() override
	{
		std::cout << "Hello from Derived\n";
	}
};

int main()
{
	Derived der;
	der.sayHello(); // hello from derived
}
