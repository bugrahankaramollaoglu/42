#include <iostream>

template <typename T>
void Swap(T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
T Max(T a, T b)
{
	return (a > b) ? a : b;
}

template <typename T>
T Min(T a, T b)
{
	return (a < b) ? a : b;
}
