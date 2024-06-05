#include <iostream>
#include <string>

/* built-in string functions in c++

length, at, insert, substr, append, ==, find, replace, stoi, iteration, */

int main()
{
	std::string me = "bugra";

	std::cout << me.length() << std::endl; // 5

	std::cout << me.at(2) << std::endl; // g

	me.insert(5, "han");
	std::cout << me << std::endl; // bugrahan

	std::cout << me.substr(2, 5) << std::endl; // graha

	std::string you = " ahmet";
	me.append(you);
	std::cout << me << std::endl; // bugrahan ahmet

	std::cout << (me == you) << std::endl; // 0

	size_t pos = me.find("ra");
	std::cout << pos << std::endl; // 3. indiste ra buldu

	me.replace(9, 3, "xx");		  // 9. indise xx ekliyor, 3 karakter sonrasını siliyor
	std::cout << me << std::endl; // bugrahan xxet

	std::string num = "42";
	int num2 = std::stoi(num);

	for (char c : num)
		std::cout << c << " "; // 4 2
}
