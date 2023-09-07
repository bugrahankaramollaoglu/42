#include <iostream>

class MyClass
{
public:
	void display(int num)
	{
		std::cout << "Value: " << num << std::endl;
	}
};

/* function pointers sentaksının aksine member-function pointers
sentaksı şöyledir: returnType (ClassName::*pointerName)(parameterTypes); */

int main()
{
	MyClass obj;
	void (MyClass::*ptr)(int) = &MyClass::display;

	(obj.*ptr)(42); // Calls obj.display(42)

	return 0;
}
