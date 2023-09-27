#include <iostream>

/* cpp'de member attributes/functions bir class içerisinde
tanımlanan değişken ya da fonksiyonlara denirken nonmemberlar
classlarla ilgileri olmayan, normal yollarla tanımlanan
değişken ya da fonksiyonlardır. */

// Non-member attributes
int globalValue = 100;

// Non-member function
void globalFunction()
{
	std::cout << "This is a global function." << std::endl;
}

class MyClass
{
public:
	// Member attribute
	int memberValue;

	// Member function
	void memberFunction()
	{
		std::cout << "This is a member function." << std::endl;
	}
};

int main()
{
	MyClass obj;

	// Accessing and modifying member attribute
	obj.memberValue = 42;
	std::cout << "Member value: " << obj.memberValue << std::endl;

	// Calling member function
	obj.memberFunction();

	// Accessing non-member attribute and calling non-member function
	std::cout << "Global value: " << globalValue << std::endl;
	globalFunction();

	return 0;
}
