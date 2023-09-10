#include <iostream>

/* there are different types of casting in cpp */

int main() {
	// 1) C-style casting: (type)value
	char letter = (char)97;
	std::cout << letter << std::endl; // a

	// 2) static casting: static_cast<type>(value)
	char letter2 = static_cast<char>(97);
	std::cout << letter2 << std::endl; // a

	// 3) dynamic casting: converts a pointer or reference
	// from one type to another type: dynamic_cast<type>(value)

	// 4) const casting: casts a const value to nonCast
	// const_cast<type&>(value)
	const int myConst = 42;
	// myConst = 50; // error
	int &nonConst = const_cast<int&>(myConst);
	nonConst = 50; // not error

	// there are others ... but trivial
}
