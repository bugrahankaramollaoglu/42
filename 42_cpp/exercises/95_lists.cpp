#include <iostream>
#include <list>

// lists (usually implemented as doubly linked lists)

int main()
{
	// create list in different ways
	std::list<int> myList;
	std::list<int> myList2(5);
	std::list<int> myList3 = {1, 2, 3, 4, 5};

	// add from back
	myList.push_back(10);
	myList.push_back(20);
	myList.push_front(30);
	myList.push_front(40);

	// learn size
	// std::cout << myList.size();

	// iterate
	for (int i = 0; i < myList.size(); i++)
	{
		/* ... */
	}

	// or like this
	for (int i : myList)
	{
		/* ... */
	}

	// or like this
	for (auto it = myList.begin(); it != myList.end(); ++it)
	{
		// Access *it to get the current element
	}

	// access: lists cannot use [] but use iterators to access elements
	std::list<int> l = {10, 20, 30};
	std::list<int>::iterator it = l.begin();
	std::cout << *it << " "; // 10
	it++;
	std::cout << *it << " "; // 20
	it++;
	std::cout << *it << " "; // 30
	myList2.erase(it);		 // 30 gitti

	// remove the last element
	myList.pop_back();

	// access first and last elements
	std::cout << myList.front();
	std::cout << myList.back();

	// clear a list
	myList.clear();

	std::cout << "\n";
	return 0;
}
