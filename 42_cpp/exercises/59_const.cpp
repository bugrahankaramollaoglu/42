#include <iostream>

class Deneme {
	public:
		const char* fun(const std::string str) const;
};


const char *Deneme::fun(const std::string str) const
{
	/* .... */
}

/* yukarıda son const yalnızca bir classın member fonksiyonları
ile beraber kullanılabilir. yani void fun() const {} diyemezsin,
nonMember hatası alırsın. bu sondaki const'un anlamı ise şu:
bu metodu yalnızca classın const objeleriyle kullanabilirsin.
böylelikle fonksiyonun çağırdığı objeyi değiştirmediğinden emin olursun. */



