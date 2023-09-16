#include <iostream>
#include <set>

int main()
{
	std::set<int> mySet;

	mySet.insert(50);
	mySet.insert(60);
	mySet.insert(70);

	mySet.erase(60);

	mySet.count(60); // 1

	// checks if elem is extant. if not returns set.end()
	std::set<int>::iterator it = mySet.find(42);
	if (it == mySet.end())
	{
		std::cout << "bulunamadı\n";
	}

	// traverse tru iterator
	for (std::set<int>::iterator it = mySet.begin(); it != mySet.end(); it++)
	{
		/* ... */
	}

	/* you can also use std::set_union,
	std::set_intersection, and std::set_difference
	from the <algorithm> header. */

	mySet.clear();
}
