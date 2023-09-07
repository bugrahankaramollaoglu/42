#include <iostream>
#include <string>

void byPtr(std::string *str);
void byConstPtr(std::string const *str);
void byRef(std::string &str);
void byConstRef(std::string const &str);

int main()
{
	std::string str = "i like animes";
	std::cout << str << std::endl; // i like animes
	byPtr(&str);				   // or byRef(str) ama constlar değiştir(e)mez
	std::cout << str << std::endl; // i like animes and i like mangas
}

void byPtr(std::string *str)
{
	*str += " and i like mangas";
}

void byConstPtr(std::string const *str)
{
	std::cout << *str << std::endl;
}
void byRef(std::string &str)
{
	str += " and i like mangas";
}

void byConstRef(std::string const &str)
{
	std::cout << str << std::endl;
}
