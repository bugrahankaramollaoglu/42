#include <iostream>

/* A class is made abstract by declaring at least one
of its functions as pure virtual function. A pure virtual
function is specified by placing "= 0" in its declaration.  */

class Box
{
public:
	// pure virtual function
	virtual double getVolume() = 0;

private:
	double length;	// Length of a box
	double breadth; // Breadth of a box
	double height;	// Height of a box
};

int main()
{
	// Box b; // ilklendiremiyoruz çünkü abstract class
}
