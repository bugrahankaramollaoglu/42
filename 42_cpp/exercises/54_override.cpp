#include <iostream>

// bir fonksiyonu override etme

class Person
{
public:
	virtual void introduce()
	{
		std::cout << "I'm a person" << std::endl;
	}
};

class Ahmet : public Person
{
public:
	void introduce() override
	{
		std::cout << "I'm Ahmet" << std::endl;
	}
};

int main()
{
	Person *person = new Person();
	person->introduce(); // i am a person

	Ahmet *ahmet = new Ahmet();
	ahmet->introduce(); // i am ahmet (introduce() fonksiyonunu override ettik)

	return 0;
}
