#include "class.hpp"

/* The Orthodox Canonical Class Form

A default constructor: used internally to initialize objects and
data members when no other nameue is available.

A copy constructor: used in the implementation of
call-by-nameue parameters.

An assignment operator: used to assign one nameue to another.

A destructor: Invoked when an object is deleted. */

/* 42cpp modüllerinde OOCF kullanmamızı istiyor. bunun sebebi
bir objeyi baska bir objeye kopyalarken shallow değil
deep copy yapması. shallow kopyalanan iki obje varsa ve biri üzerinden
bir degiskeni degistirirsen digerinde de degisir. deep copy ise
degistirmez. asagıda iki isimli objeye bir objesini attık ve daha sonra
iki objesinin name degiskenini 50 yaptik. deep copy oldugundan bir'inki degismedi.
shallow olsaydı ikiyi degistirmek bir'i de degistirirdi. */

int main()
{
	Deneme bir;
}
