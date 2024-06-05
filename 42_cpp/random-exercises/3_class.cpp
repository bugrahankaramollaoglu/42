#include <iostream>

class Deneme
{
public:
	Deneme();
	~Deneme();
};

Deneme::Deneme()
{
	std::cout << "constructor called" << std::endl;
}

Deneme::~Deneme()
{
	std::cout << "destructor called" << std::endl;
}

int main()
{
	/* burada Deneme sınıfını deneme isminde bir objeyle
	örneklendiriyoruz (instantiation). Bir sınıftan bir obje çağrıldığında
	otomatik olarak Contructor ve destructor da çağrılır, o yüzden yazdırıldılar.  */
	Deneme deneme;
}

/* ek bilgi:

public: altında yazdıgın tüm metot ve attributelar bütün kod genelinde erişilebilirdir.
public haricinde ya private ya da protected tanımlayabilirsin. private tanımladıgın
özelliklere yalnızca setX() getX() gibi fonksiyonlarla yine sınıf içerisinde ulaşabilirsin.
haricinde ulaşamazsın. mesela

class Deneme {
	private:
		int a = 42;
};

dersen daha sonra mainde

Deneme deneme;
deneme.a = 50; diyemezsin. public olsaydı diyebilirdin. ama bir setter yazsaydık

class Deneme {
	private:
		int a = 42;
	public:
		void setVal(int val) {
			a = val;
		}
};

bu setter aracılıgıyla erisebilirdik. yani private tanımladıgın degiskenlere sadece
public metotların üzerinden erisip modifiye edebilirsin

Deneme deneme;
deneme.setVal(50); şeklinde

protected tanımlarsan sadece derived class ve class içerisinden erişebilirsin, public gibi *

ayrıca anahtar kelimesiz kullanırsan da otomatik olarak private olurlar

class Deneme {
	int a;
};

a burada private attribute yerine geçer.  */
