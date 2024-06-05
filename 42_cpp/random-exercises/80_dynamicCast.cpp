#include <iostream>

/* polymorphic pointerların conversionında kullanılır.
mesela bir base class pointerını derived class
pointerına ya da tam tersi çevirme */

/* In polymorphic scenarios, you might have a base class
pointer or reference that actually points to a derived
class object. To safely work with the derived class's
specific features, you need to determine its actual
type and potentially convert it to the derived class
type. This is where dynamic_cast comes into play. */

/* sentaksı şöyledir

Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);   */

/* dynamic_cast checks if the object pointed to by basePtr
is actually of type Derived (or a class derived from Derived).
If it is, it returns a pointer to the object cast to Derived*.
If not, it returns a null pointer (nullptr) if you're casting
to a pointer type, or throws a std::bad_cast exception if
you're casting to a reference type. */

class Base
{
public:
	virtual void foo()
	{
		std::cout << "Base::foo()" << std::endl;
	}
};

class Derived : public Base
{
public:
	void foo() override
	{
		std::cout << "Derived::foo()" << std::endl;
	}

	void derivedSpecificFunction()
	{
		std::cout << "Derived-specific function" << std::endl;
	}
};

int main()
{
	Base *basePtr = new Derived();

	// Using dynamic_cast to safely downcast
	Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

	if (derivedPtr)
	{
		derivedPtr->foo(); // Calls Derived::foo()
		derivedPtr->derivedSpecificFunction();
	}
	else
	{
		std::cout << "Dynamic cast failed!" << std::endl;
	}

	delete basePtr;

	/* *basePtr'mizi derivedPtr'ye convert ettik dynamic_cast<> ile */

	return 0;
}
