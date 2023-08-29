#include <iostream>
using namespace std;

/* cpp'de bir classın içerisinde prototoiplerini tanımladığın
fonksiyonları dışarıda className::funcName şeklinde tanımlarsan
mainde className.funcName şeklinde kullanabilirsin */

class Rectangle
{
public:
	double width;
	double length;
	double depth;

	// member functions
	void setWidth(double w);
	void setLength(double l);
	void setDepth(double d);
	double getVolume();
};

void Rectangle::setWidth(double w)
{
	width = w;
}

void Rectangle::setLength(double l)
{
	length = l;
}

void Rectangle::setDepth(double d)
{
	depth = d;
}

double Rectangle::getVolume()
{
	return width * length * depth;
}

int main()
{
	Rectangle rec1;
	double volume = 0.0;

	rec1.setLength(6.0);
	rec1.setWidth(4.0);
	rec1.setDepth(2.0);

	cout << rec1.getVolume() << endl; // 48
}
