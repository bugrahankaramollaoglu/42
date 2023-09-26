#include <iostream>
#include <string>

/* generics in c++ is the idea to allow mere types
to be parameters to methods, classes and interfaces. Generic Programming enables
the programmer to write a general algorithm which will work with all data types.
böylelikle gelen parametrenin integer, string, char vs. olup olmadıgına bakmaksızın
her tip için geçerli bir algoritma yazilabilir. c++'de genericler templateler aracılığıyla
hayata geçiyor. mesela her tip için geçerli bir sort() fonksiyonu yazalim: */

// Template function to sort an array of any data type using the bubble sort algorithm.
template <typename T>
void bubbleSort(T arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				// Swap arr[j] and arr[j+1] if they are in the wrong order
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{
	// Sort an array of integers
	int intArray[] = {5, 2, 9, 1, 5};
	int intSize = sizeof(intArray) / sizeof(intArray[0]);
	bubbleSort(intArray, intSize);

	std::cout << "Sorted Integer Array: ";
	for (int i = 0; i < intSize; ++i)
	{
		std::cout << intArray[i] << " ";
	}
	std::cout << std::endl;

	// Sort an array of doubles
	double doubleArray[] = {3.14, 1.618, 2.718, 0.577, 2.718};
	int doubleSize = sizeof(doubleArray) / sizeof(doubleArray[0]);
	bubbleSort(doubleArray, doubleSize);

	std::cout << "Sorted Double Array: ";
	for (int i = 0; i < doubleSize; ++i)
	{
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	// Sort an array of characters
	char charArray[] = {'z', 'a', 'g', 'd', 'x'};
	int charSize = sizeof(charArray) / sizeof(charArray[0]);
	bubbleSort(charArray, charSize);

	std::cout << "Sorted Char Array: ";
	for (int i = 0; i < charSize; ++i)
	{
		std::cout << charArray[i] << " ";
	}
	std::cout << std::endl;

	// Sort an array of strings
	std::string stringArray[] = {"apple", "banana", "cherry", "date", "fig"};
	int stringSize = sizeof(stringArray) / sizeof(stringArray[0]);
	bubbleSort(stringArray, stringSize);

	std::cout << "Sorted String Array: ";
	for (int i = 0; i < stringSize; ++i)
	{
		std::cout << stringArray[i] << " ";
	}
	std::cout << std::endl;

	return 0;
}
