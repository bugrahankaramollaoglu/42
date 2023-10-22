#include <iostream>

class MyClass
{
public:
	int publicValue;
	void publicFunction()
	{
		std::cout << "This is a public function." << std::endl;
	}

private:
	// privatelarin başına _ koymak onları fark etmeyi kolaylaştırır
	int _privateValue;
	
	void privateFunction()
	{
		std::cout << "This is a private function." << std::endl;
	}
};

int main()
{
	MyClass obj;

	obj.publicValue = 42; // Accessing public attribute
	obj.publicFunction(); // Calling public function

	// obj._privateValue = 10;   // Error: privateValue is private
	// obj.privateFunction();   // Error: privateFunction is private

	return 0;
}
