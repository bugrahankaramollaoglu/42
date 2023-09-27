#include <iostream>
using namespace std;

/* cpp'de değişkenler referanslarla kullanılabilir
it is an alias for a variable, do not confuse with pointers
A reference is declared using the & symbol after a variable's type. For example

int original = 42;
int &ref = original;
ref += 3; -> 'ref' is now a reference to 'ginal'  */

int main()
{
	int i = 5;
	int &i2 = i;
	i2++;
	i2++;
	i2++;
	cout << i2 << "\n"; // 8
}

/*  References must be initialized when declared. Once a reference is
initialized, it cannot be made to refer to a different variable.
References cannot be null; they must always refer to a valid object. */
