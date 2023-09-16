#include <iostream>

template <typename T>
class Swap
{
public:
	Swap(T &a, T &b) : first(a), second(b) {}

	void swap_them()
	{
		T tmp = first;
		first = second;
		second = tmp;
	}

private:
	T &first;
	T &second;
};

int main()
{
	int a = 10;
	int b = 20;
	Swap<int> s(a, b);
	s.swap_them();
	std::cout << a << "\n"; // 20
	std::cout << b << "\n"; // 10

	std::string x = "bugra";
	std::string y = "kara";
	Swap<std::string> s2(x, y);
	s2.swap_them();
	std::cout << x << "\n"; // kara
	std::cout << y << "\n"; // bugra
}
