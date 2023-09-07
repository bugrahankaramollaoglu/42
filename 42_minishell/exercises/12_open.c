
#include <stdio.h>
#include <fcntl.h>

/* open("dosya", bayraklar, izinler) fonksiyonu dosya işlemlerinde kullanılır
O_RDONLY: Okuma izni
O_WRONLY: Yazma izni
O_CREAT: Dosya yoksa olustur
O_TRUNC: Dosya mevcutsa erisim izin verir ve içindeki verileri siler
 */

int main()
{
	int a = open("deneme.txt", O_RDONLY | O_CREAT, 0400); // flagler ve izinler belirledik, a'ya da dosyanın fd'sini attık
	printf("%u\n", a);
}
