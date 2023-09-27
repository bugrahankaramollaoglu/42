#include <iostream>
#include <string>

/* getter ve setter olarak bilinirler
getter'lar bir sınıfın içerisindeki değişkenleri
almaya yararken setter değiştirmeye yarar */

class Person
{
private:
	std::string _name;

public:
	std::string getName() const
	{
		return _name;
	}

	void setName(const std::string &newName)
	{
		_name = newName;
	}
};

int main()
{
	Person person;

	person.setName("bugra");
	std::cout << "Name: " << person.getName() << std::endl;

	return 0;
}
