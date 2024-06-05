#include <iostream>

/* abstract class yani soyut sınıf kavrami büyük projelerde kullanılır.
temel işlevi kendisinden alt sınıflara üstSınıf rolü oynamasıdır.
yani bu soyut sınıftan birçok sınıf miras alır ve özelliklerini taşır ama
kendisi tam bir sınıf görevi görmediğinden ilklendirilemez. kraliçe arı
gibi düşünülebilir, birçok arıya miras verir ama kendisi tam bir arı görevi görmez */

/* kullanırken kurallar
	* başına -abstract- anahtar kelimesini alır.
	* virtual almaz çünkü zaten sanaldır
	* obje oluşturmazlar
	* bir abstract class nonAbstract (concrete) metot barındırabilir
	  ama normal bir sınıfta abstract metotlar olmaz
	* abstract metotlar override ile kullanılmalıdır
	* static metotlar abstract olamaz
	* abstract sınıflar private olamaz, public ya da protected */

/* şeması

class AbstractClass {
public:
	virtual void abstractMethod() = 0;
	// Other member variables and methods...
};

*/

// bir classı abstract yapmak için en az bir pure-virtual-function yeterlidir

/* abstract classın tam zıttına concrete class denir, yani bildiğimiz,
ilklendirilebilir, objelendirilebilir sınıflar. */
