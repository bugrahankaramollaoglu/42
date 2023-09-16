#include <iostream>

// function template

template <typename T>
T myMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	std::cout << myMax<int>(3, 7) << std::endl;		 // 7
	std::cout << myMax<char>('b', 's') << std::endl; // s
}
