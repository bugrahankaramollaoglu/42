#include <iostream>
#include <exception>

class Deneme
{
public:
	class SifiraBölmeHatasi : public std::exception {
	public:
		const char *what() const throw() {
			return "sifira bölemezsin";
		}
	};
};

int main()
{
	Deneme deneme;
	try
	{
		int i = 13;
		int i2 = 0;

		if (i2 == 0)
			throw Deneme::SifiraBölmeHatasi();

		std::cout << i / i2 << "\n";
	}
	catch (const Deneme::SifiraBölmeHatasi &e) {
		std::cout << e.what() << "\n";
	}
}
