#include <iostream>
using namespace std;

class Base
{
public:
	Base()
	{
		std::cout << "base constructor called" << std::endl;
	}
	~Base()
	{
		std::cout << "base destructor called" << std::endl;
	}

};

/* aşağıdaki örnekte eğer 1. örnekteki gibi çağırırsan objeyi hem constructor
hem destructor çağrılır, sebebi ise stackin hem yapım hem yıkım işlemini
otomatik yapmasıdır. ama 2. örnekteki gibi dinamik yaratırsan delete ile silmezsen
sadece constructor çağrılır */

int main()
{
	// Base base;

	// Base *base = new Base();
	// delete base;
}
