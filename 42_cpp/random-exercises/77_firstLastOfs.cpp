#include <iostream>
#include <algorithm>
#include <string>

/* bu tip find() fonksiyonlarından 4 tane vardır
	1) find_first_not_of() -> eşleşmeyen ilkinin indisini bulur
	2) find_first_of() -> eşleşen ilkinin indisini bulur
	3) find_last_of() -> eşleşen sonuncunun indisini bulur
	4) find_last_not_of() -> eşleşmeyen sonuncunun indisini bulur */

int main()
{
	std::string str = "++++b++b+++";

	size_t index = str.find_first_not_of('+');
	size_t index2 = str.find_first_of('+');
	size_t index3 = str.find_last_of('+');
	size_t index4 = str.find_last_not_of('+');

	std::cout << "first char that's not '+' is at index: " << index << std::endl; // 4
	std::cout << "first char that's '+' is at index: " << index2 << std::endl;	  // 0
	std::cout << "last char that's '+' is at index: " << index3 << std::endl;	  // 10
	std::cout << "last char that's not '+' is at index: " << index4 << std::endl; // 7

	return 0;
}
