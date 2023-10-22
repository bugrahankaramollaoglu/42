#include <iostream>
#include <string>

/* deep copy ve shallow copy nedir?

shallow copy yani sığ kopyalamada sadece data memberlar kopyalanır
pointer değişkenler kopyalanmaz

deep copyde ise ikisi de kopyalanır */

/* copy constructor şeması şöyledir:

class ClassName {
	ClassName(const ClassName &obj) {
		// Constructor code here
	}
};


 */

// let's see deep copy

class Deneme
{
public:
	int *x;

public:
	Deneme(int val)
	{
		x = new int(val);
	}
	Deneme(const Deneme &obj)
	{
		x = new int(*obj.x); // deep copied
	}
	~Deneme() {}
};

int main()
{
	Deneme deneme(10);
	Deneme deneme2 = deneme;

	std::cout << *(deneme.x) << std::endl;	// 10
	std::cout << *(deneme2.x) << std::endl; // 10

	*deneme.x = 20;

	std::cout << *(deneme.x) << std::endl;	// 20
	std::cout << *(deneme2.x) << std::endl; // 10. deep copy oldugundan farklı kaldılar
}

/* orthodox canonical formda deep copy kullanıyoruz. eğer
bir class yarattıgında copy constructor yazmazsan class bir obje kopyalama
işlemi yaptıgında otomatik olarak kendi default copy constructorını kullanır
ama o da her zaman shallow copy yapar, deep değil */
