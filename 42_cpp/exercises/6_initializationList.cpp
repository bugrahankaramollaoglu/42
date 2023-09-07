#include <iostream>

class Sample
{

	public:
		// attributes
		char a1;
		int a2;
		float a3;

		Sample(char p1, int p2, float p3);
};

// tek seferde : ve ,'lerle bir constructor'ın parametrelerini ilklendirme
// buna initialization list denir. tüm const parametreler bu şekilde
// ilklendirilmelidir yoksa garbage-value atanır
Sample::Sample(char p1, int p2, float p3) : a1(p1), a2(p2), a3(p3)
{
		std::cout << "\nConstructor called" << std::endl;
		std::cout << "this->a1 = " << this->a1 << std::endl;
		std::cout << "this->a2 = " << this->a2 << std::endl;
		std::cout << "this->a3 = " << this->a3 << std::endl;
}

int main(void)
{
		Sample instance('a', 42, 4.2f);
		std::cout << "\n";
}
