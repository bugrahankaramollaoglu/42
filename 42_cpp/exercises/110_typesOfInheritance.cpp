#include <iostream>

/* üç şekilde inherit edebilirsin public, private ve protected */

class Base
{
public:
	int publicVar = 42;
	void publicFunction()
	{
		std::cout << "Base's public function" << std::endl;
	}

	void commonFunction()
	{
		std::cout << "Base's common function" << std::endl;
	}
};

// en sık kullanılan
class DerivedPublic : public Base
{
public:
	void callBasePublicMembers()
	{
		std::cout << "Accessing Base's public members from DerivedPublic:" << std::endl;
		std::cout << "publicVar: " << publicVar << std::endl;
		publicFunction();
		commonFunction(); // Common function is also accessible
	}
};

class DerivedProtected : protected Base
{
public:
	void callBasePublicMembers()
	{
		// DerivedProtected can still access the protected members, but it cannot access public members directly
		// publicVar and publicFunction are not accessible here
		std::cout << "Accessing Base's public members from DerivedProtected:" << std::endl;
		// publicVar and publicFunction are not accessible here
		commonFunction(); // Common function is accessible
	}
};

class DerivedPrivate : private Base
{
public:
	void callBasePublicMembers()
	{
		// DerivedPrivate can't access public or protected members of Base
		std::cout << "Accessing Base's public members from DerivedPrivate:" << std::endl;
		// publicVar and publicFunction are not accessible here
		commonFunction(); // Common function is accessible
	}
};

int main()
{
	DerivedPublic derivedPublic;
	derivedPublic.callBasePublicMembers(); // Public members are accessible

	DerivedProtected derivedProtected;
	// dprot.callBasePublicMembers(); // Will result in a compilation error because the base class members are protected

	DerivedPrivate derivedPrivate;
	// dpriv.callBasePublicMembers(); // Will result in a compilation error because the base class members are private

	return 0;
}
