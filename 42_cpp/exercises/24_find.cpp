#include <iostream>
#include <string>

// find() searches for a substr in a string, equivalent of substr() in c

int main()
{
	std::string mainString = "Hello, world! How are you?";
	std::string substring = "world";

	size_t foundPos = mainString.find(substring);

	if (foundPos != std::string::npos)
	{
		std::cout << "Substring found at position: " << foundPos << std::endl;
	}
	else
	{
		std::cout << "Substring not found." << std::endl;
	}

	return 0;
}
