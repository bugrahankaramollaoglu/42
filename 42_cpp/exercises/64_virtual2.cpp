#include <iostream>

// apart from that if you use virtual keyword with
// destructors, it causes the proper-destruct-chain
// this allows the correct way of calling destructor
// functions, hence the memory-freeings, from derived
// to base class, allowing no leaks whatsoever

class Base
{
	public:
		virtual ~Base() {
			std::cout << "Base destructor" << std::endl;
		}
};
