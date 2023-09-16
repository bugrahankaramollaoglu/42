#include <iostream>

/* template yapısına birden fazla parametre de
verebiliriz. mesela az öncekine length ekleyelim */

template <typename T, int length>
class Array
{
public:
	// 10 olan yerlere length yaziyoruz
	T array[length];

	void fill(T val)
	{
		for (int i = 0; i < length; i++)
			array[i] = val;
	}

	void print()
	{
		for (int i = 0; i < length; i++)
			std::cout << array[i] << " ";
	}

	T &ar(int index)
	{
		return array[index];
	}
};

int main()
{
	// artik burayi değişken aracılıgıyla belirliyoruz
	Array<int, 4> intArr;
	intArr.fill(3);
	intArr.print();

	std::cout << "\n";

	Array<char, 8> charArr;
	charArr.fill('a');
	charArr.print();
}
