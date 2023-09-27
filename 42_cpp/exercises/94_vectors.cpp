#include <vector>
#include <iostream>

// vectors are arrays of diff type that can shrink/grow in size
// en sık kullanılan container'lardan bir tanesidir.

int main()
{
	// create an empty vector
	std::vector<int> myVec;
	// or default initialize it
	std::vector<int> myVec2(5);
	// or initialize it
	std::vector<int> myVec3 = {1, 2, 3, 4, 5};

	// add from back
	myVec.push_back(10);
	myVec.push_back(20);
	myVec.push_back(30);
	myVec.push_back(40);

	// insert at spesific position
	myVec.insert(myVec.begin() + 4, 50); // now vec: 10, 20, 30, 40, 50

	// access
	std::cout << myVec[2];
	std::cout << myVec.at(2);

	// learn size
	std::cout << myVec.size();

	// iterate
	for (int i = 0; i < myVec.size(); i++)
	{
		/* ... */
	}

	// or like this
	for (int i : myVec)
	{
		/* ... */
	}

	// or like this
	for (auto it = myVec.begin(); it != myVec.end(); ++it)
	{
		// Access *it to get the current element
	}

	// remove the last element
	myVec.pop_back();

	// remove the spesific element (myVec[3])
	myVec.erase(myVec.begin() + 3);

	// learn capacity
	std::cout << myVec.capacity();

	// clear a vector
	myVec.clear();

	// access first and last elements
	std::cout << myVec.front();
	std::cout << myVec.back();

	std::cout << "\n";
	return 0;
}
