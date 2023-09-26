#include <iostream>

template <typename T, size_t N>
void PrintArray(const T (&arr)[N])
{
	for (const auto &element : arr)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
