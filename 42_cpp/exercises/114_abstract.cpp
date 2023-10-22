#include <iostream>

/* abstract vs. interface

pure virtual function (aka abstract function) nedir?

virtual void myFun() = 0;

dersen o fonksiyon artık pure virtual fonksiyon olur.
ve eğer bir sınıf içerisinde pure virtual fonksiyon tutuyorsa
o sınıf artık normal bir sınıf degil abstract bir class olur yani
artık ilklendirilemezler. yalnızca miras vermeye yararlar.
ek olarak miras alan sınıflar base sınıftaki bütün pure fonksiyonları
kendi içlerinde implement etmek zorundadırlar. */

class Base
{
public:
	virtual void my_fun() = 0;
};

class Derived : public Base
{
	void my_fun() override
	{
		std::cout << "implementing" << std::endl;
	}
};

int main()
{
	Derived derived;
	derived.my_fun();
}
