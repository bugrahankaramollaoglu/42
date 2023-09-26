#include <iostream>

class MyClass
{
public:
	void display(int num)
	{
		std::cout << "Value: " << num << std::endl;
	}
};

/* member fonksiyonlar yani bir sınıfın altındaki fonksiyonları
gösteren pointerlar normal fonksiyonların pointerlarından farklıdır:
returnType (ClassName::*pointerName)(parameterTypes) = &ClassName:funcName */

int main()
{
	MyClass obj;
	void (MyClass::*myPtr)(int) = &MyClass::display;

	(obj.*myPtr)(42); 

	return 0;
}
