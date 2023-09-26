#include <iostream>

/* const can be used in multiple ways

1. variables

	const int x = 40;

	x++; // not okey
	x = 52; // not okey

2. pointers

	a. we can either make what the pointer points to constant

		const int *p = &x; // okey

		*p = 5; // not okey

	b. or we can make the pointer itself constant

		int* const p = &x; // okey

		p = &y; // not okey

	c. or both

		const int* const p = &x; // okey

		*p = 5; // not okey

		p = &y; // not okey either

3. function arguments or return types

	void f(const int i)
	{
		i++;    // error
	}

	const int g()
	{
		const int a = 40;
		return a;
	}

4. class data members

	class Test
	{
		const int i;
		public:
			Test(int x): i(x) {
				cout << "i is: " << i;
			}
	};

5. class member functions

6. objects */
