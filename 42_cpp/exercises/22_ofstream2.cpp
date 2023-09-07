#include <iostream>
#include <fstream>

/* With ofstream, you can easily open a file for writing */

int main()
{
	std::ofstream myf;
	myf.open("file2.txt"); // if not extant, will be created
	char a[] = "bugrahan\n";
	myf.write(a, sizeof(a));
}
