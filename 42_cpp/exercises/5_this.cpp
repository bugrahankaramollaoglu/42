#include <iostream>

/* In C++, each object gets its own copy of data members and all objects share
a single copy of member functions. To refer to your current instance,
use the special instance pointer this. */

/* birden fazla kullanım sebebi vardır
	1) member fonksiyonlarla kullanımı

		class MyClass {
			private:
				int value;
			public:
				void setValue(int val) {
					// Use 'this' to access the member variable 'value'
					this->value = val;
			}
		};

	2) returning the current instance. useful for method chaining

		class Person {
			private:
				std::string name;
			public:
				Person& setName(const std::string& n) {
					this->name = n;
					return *this; // Return the current instance
				}
		};

	3) constructorlarda, aynı isimli member variable ve contructor parametreleri karışmasın diye

		class Point {
			private:
				int x, y;
			public:
				Point(int x, int y) {
					this->x = x;
					this->y = y;
				}
		};
*/
