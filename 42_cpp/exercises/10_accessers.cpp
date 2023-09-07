#include <iostream>
#include <string>

/* getter ve setter olarak bilinirler
getter'lar bir sınıfın içerisindeki değişkenleri
almaya (değiştirmeye değil) yararken setter değiştirmeye (almaya değil) yarar */

class Person
{
private:
	std::string _name;
	int _age;

public:
	// Getter for name
	std::string getName() const
	{
		return _name;
	}

	// Setter for name
	void setName(const std::string &newName)
	{
		_name = newName;
	}

	// Getter for age
	int getAge() const
	{
		return _age;
	}

	// Setter for age
	void setAge(int newAge)
	{
		if (newAge >= 0)
		{
			_age = newAge;
		}
	}
};

int main()
{
	Person person;

	person.setName("bugra");
	person.setAge(22);

	std::cout << "Name: " << person.getName() << std::endl;
	std::cout << "Age: " << person.getAge() << std::endl;

	return 0;
}
