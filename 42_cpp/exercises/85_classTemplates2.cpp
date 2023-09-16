#include <iostream>

/* class templatelerin çalışma mantığı şu şekildedir
class Array altında
	string/int/double array[10],
	void fill(string/int/double val) vs.
demek yerine tek bir template yaratiyoruz. bu template
<typename T> kısmında T'nin yerine yazdığımız veri tipini
alıp class altında T gördüğü yerlere koymaya yariyor.
Array<int> dediğimizde T gördüğü yerlere int getiriyor.
bu kadar basit. */

template <typename T>
class Array
{
public:
	T array[10];

	void fill(T val)
	{
		for (int i = 0; i < 10; i++)
			array[i] = val;
	}

	void print()
	{
		for (int i = 0; i < 10; i++)
			std::cout << array[i] << " ";
	}

	T &ar(int index)
	{
		return array[index];
	}
};

int main()
{
	Array<int> intArr;
	intArr.fill(3);
	intArr.print();

	std::cout << "\n";

	Array<char> charArr;
	charArr.fill('a');
	charArr.print();
}
