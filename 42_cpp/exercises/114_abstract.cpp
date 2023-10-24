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
	// derived.my_fun();
}

/* why do we need abstract classes or interfaces?

Abstraction: Abstract classes and interfaces help create high-level
abstractions in your code, allowing you to define contracts or blueprints
for classes without specifying their concrete details. This is useful for
simplifying complex systems by breaking them down into smaller,
manageable components.

Encapsulation: Abstract classes and interfaces encapsulate behavior
and data into self-contained units, which is a core concept in
object-oriented programming. This ensures that the implementation
details of a class are hidden from the outside world, and only a
well-defined interface is exposed.

Polymorphism: Abstract classes and interfaces enable polymorphism,
which means you can write code that works with objects of various
classes that implement the same interface or inherit from the same
abstract class. This promotes flexibility and reusability in your code.

Inheritance: interfaces allow multiple inheritances

 */
