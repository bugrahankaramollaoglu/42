#include <iostream>

/* pure virtual function nedir? bir base classı abstract
yapmakta kullanılır. eğer base class altındaki metot
virtual anahtar kelimesiyle kullanılmış, 0'a eşitlenmiş ve bir
özellik yüklenmemişse o class artık bir abstract classtır çünkü
herhangi bir özelliği olmadığı, boş olduğu için ilklendirilemez.
sentaksı şöyledir:

virtual returnType functionName() = 0;

bu metodun yeniden yazılması zorunludur onu da inherit alan alt sınıflar
yapabilir sadece */

class Animal
{
public:
	// Animal sınıfını abstract yapan şey bu pure virtual function'dır
	virtual void makeSound() = 0;
	void sleep()
	{
		std::cout << "zzz" << std::endl;
	}
};

class Dog : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "hav" << std::endl;
	}
};

class Cat : public Animal
{
public:
	void makeSound() override
	{
		std::cout << "miyav" << std::endl;
	}
};

int main()
{
	// Cannot create an instance of an abstract class.
	// Animal animal;

	Dog dog;
	dog.makeSound();
	dog.sleep();

	Cat cat;
	cat.makeSound();
	cat.sleep();

	return 0;
}
