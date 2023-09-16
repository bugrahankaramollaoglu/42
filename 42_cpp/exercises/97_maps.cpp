#include <iostream>
#include <map>

// maps are dictionaries of python.

int main()
{
	// Declaration of an empty map with string keys and integer values
	std::map<std::string, int> myMap;

	myMap.insert(std::pair<std::string, int>("apple", 5));
	myMap.insert(std::pair<std::string, int>("banana", 2));
	myMap.insert(std::pair<std::string, int>("melon", 1));
	myMap.insert(std::pair<std::string, int>("pears", 7));

	myMap.erase("pears");

	// If the key doesn't exist, it adds a new key-value
	// pair with a default-constructed value.
	int numOfApples = myMap["apple"];

	// if the key doesn't exist, it throws exception unlike []
	int numOfApples2 = myMap.at("apple");

	// checks whether or not a key exists (either returns 1 or 0)
	int numOfApples3 = myMap.count("grape"); // 0

	// iterate
	for (const auto& pair : myMap) {
		/* ... */
	}



}
