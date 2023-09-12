#include <iostream>

/* there are different types of casting in cpp */

int main() {
	// 1) C-style casting: (type)value
	char letter = (char)97;
	std::cout << letter << std::endl; // a

	// 2) static casting: static_cast<type>(value)
	float x;
	int y;

	x = 13.37;
	y = 42;
	float z = static_cast<int>(x + y);
	std::cout << z << std::endl; // 55

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
