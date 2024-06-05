#include <iostream>

/* give me 10 exercises in different levels of difficulty
from beginner to advanced so that I can learn class
templates thoroughly - chatgpt  */

template <typename T, int len>
class MyArr
{
public:
	T arr[len];

	void fill(T val)
	{
		for (int i = 0; i < len; i++)
			arr[i] = i + val;
	}

	T &getIndex(T index)
	{
		return arr[index];
	}

	void print()
	{
		for (int i = 0; i < len; i++)
			std::cout << arr[i] << " ";
		std::cout << "\n";
	}
};

int main()
{
	MyArr<char, 5> ma;
	ma.fill('a');
	ma.print();
	std::cout << ma.getIndex(3) << "\n";
}
