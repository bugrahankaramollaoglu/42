#include <iostream>

class AClass {
	public:
		AClass() { std::cout << "AClass constructor\n"; }
		virtual ~AClass() = 0; // şu şekilde pure virtual function bırakamazsın.
		// concrete bir definition ile tanımlaman lazım aşağıdaki gibi (eğer derived
		// sınıf kullanacaksa). destructor da illaki kullanılıyor.
};

AClass::~AClass()
{
	std::cout << "AClass destructor" << std::endl;
}

class Derived : AClass {
	public:
		Derived() { std::cout << "derived constructor\n"; }
		~Derived() { std::cout << "derived destructor\n"; }
};

int main() {
	// AClass ac; // can't bc abstract classes cannot be initialized
	Derived der;
}
