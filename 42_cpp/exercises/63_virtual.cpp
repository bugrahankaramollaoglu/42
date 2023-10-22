#include <iostream>
using namespace std;

/* there are 2 use cases of <virtual> when used with a
method like <--virtual void fun()-->

1) polymorphism: virtual anahtar kelimesi sayesinde polymorphism yapmiş oluyoruz
that means you can call a function on an object, and the appropriate
function implementation will be determined at runtime based on the
actual type of the object rather than the type of the reference or pointer.

2) inheritance: virtual anahtar kelimesi sayesinde bir fonksiyonu derived classta
yeniden yazabiliyoruz (override)

*/

class Base
{
public:
	virtual void print()
	{
		std::cout << "Printing from Base class" << std::endl;
	}
};

class Derived : public Base
{
public:
	void print() override
	{
		std::cout << "Printing from Derived class" << std::endl;
	}
};

int main()
{
	Base *basePtr = new Derived(); // Polymorphism: Base class pointer pointing to a Derived object
	basePtr->print();			   // Calls the Derived class's print function

	delete basePtr;
	return 0;
}
