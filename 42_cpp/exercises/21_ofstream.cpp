#include <iostream>
#include <fstream>

/* With ofstream, you can easily open a file for writing */

int main()
{
	std::ofstream myf;
	myf.open("file2.txt"); // if not extant, will be created
	int num = 52;
	myf << num << std::endl; // file2.txt'de artik 52 var
}
