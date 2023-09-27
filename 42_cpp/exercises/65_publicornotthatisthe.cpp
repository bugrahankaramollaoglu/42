#include <iostream>

/* what is the difference between putting
private or public keywords as suffix to baseClass
when inheriting? */

class BaseClass
{
public:
	int publicMember;

private:
	int privateMember;

protected:
	int protectedMember;
};

/* when you use it like that the base class's public
and protected members become private members of the
derived class. This means that outside of the derived
class, you cannot access any of the base class's members*/

class DerivedClass : BaseClass
{
	// privateMember and protectedMember are private in DerivedClass
};

/* but if we use it like that, publicMember remains public, and you
can access it from outside the DerivedClass. protectedMember becomes
protected, so it can be accessed by member functions of DerivedClass
but not from outside the class.*/

class DerivedClass2 : public BaseClass
{
	// publicMember remains public, and protectedMember remains protected in DerivedClass
};
