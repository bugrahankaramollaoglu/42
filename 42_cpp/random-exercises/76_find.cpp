#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string str = "This is a sample string";
	char target = 's';

	// Use std::find to search for the character 's'
	auto it = std::find(str.begin(), str.end(), target);

	// Check if the character was found
	if (it != str.end())
	{	
		std::size_t index = std::distance(str.begin(), it);
		std::cout << "Found '" << target << "' at index: " << index << std::endl;
	}
	else
	{
		std::cout << "'" << target << "' not found in the string." << std::endl;
	}

	return 0;
}
