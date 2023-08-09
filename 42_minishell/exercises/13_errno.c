
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

// kodun hata verdiğinde bu hata kodları ERRNO isimli, errno.h kütüphanesinde saklı
// bir değişkende tutulur. başlangıçta değeri 0'dır. daha sonra hatanın kodu atanır.

int main()
{
	int fd = open("nonExtant.txt", O_RDONLY);
	printf("%d\n", errno); // 2. that means no such file
}
