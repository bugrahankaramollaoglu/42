#include <string>
#include <iostream>
#include <sstream>

/* The stringstream class is a combination of a string
and an input/output stream. It can be used to read from
or write to a string, or to convert between strings
and other data types. 4 tane temel metodu vardır

	1) clear()

	2) str() boş kullanırsan bütün içeriği yazdırır,
	doldurursan onu ss bufferına yazdırır

	3) >> write (adds string to stringStream object)

	4) << read	(reads a string from stringStream object) */


// Count the number of words in a string
int countWords(std::string s)
{
	std::stringstream ss(s);

	std::string words;

	int numWords(0);
	while (ss >> words)
		numWords++;
	return numWords;
}

int main()
{
	std::string myStr = "bugra kara molla oglu";
	std::cout << countWords(myStr) << std::endl; // 4
}
