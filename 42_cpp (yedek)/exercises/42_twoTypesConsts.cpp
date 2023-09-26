#include <iostream>

/* there are two types of consts in c++

void fun() const {
	// code
}

buradaki const'un anlamı şu: bu fonksiyon, üzerine çağrıldığı objeyi
değiştirmeyecek. yukarıdaki gibi tanımladığın bir fonksiyonu yalnızca
const bir objede kullanabilirsin. mesela

	int getData() const
	{
		return data;
	}

	const MyClass obj;
	int value = obj.getData();

eğer getData()'nın constunu silersen hata verir

classında constructor yoksa ve objenin constunu silersen yine verir
çünkü const objeler ilklendirilmelidir, constructor ilklendirme görevi görür


	class MyClass {
	public:
		void nonConstFunction() {
			// This function can modify the object's data members.
		}

		void constFunction() const {
			// This function cannot modify the object's data members.
		}
	};

ret fun() const {} şeklinde tanımladıgın fonksiyonları hem const hem nonConst
class objeleriyle kullanabilirsin ama nonConst fonksiyonları yalnızca nonConst
class objeleriyle kullanabilirsin. */

/* ayriyeten bir de fonksiyonun başında const kullanabilirsin. bu durumda
fonksiyonun dönüş değerinin const bir değer olduğunu söylersin.

const int getVal() {
	return val;
}

*/

class Rectangle
{
public:
	Rectangle(int width, int height) : width_(width), height_(height) {}

	int area() const
	{
		// This function doesn't modify the object's state.
		return width_ * height_;
	}

	void resize(int newWidth, int newHeight)
	{
		// This function modifies the object's state.
		width_ = newWidth;
		height_ = newHeight;
	}

private:
	int width_;
	int height_;
};

int main()
{
	const Rectangle constRect(5, 10);
	Rectangle nonConstRect(3, 6);

	int area1 = constRect.area();
	int area2 = nonConstRect.area();

	// you can modify this bc it does not have const {}
	nonConstRect.resize(4, 8);

	// but you cannot modify that bc it has const {}
	// constRect.resize(8, 12);

	return 0;
}
