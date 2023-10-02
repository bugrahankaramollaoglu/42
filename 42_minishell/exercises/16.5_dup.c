#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* dup() fonksiyonu bir fd'yi klonlamaya yarar. bunu yaparken de
yeni fd'yi en küçük numaralı fd id'sine atar. dup2 ise spesifik id'ye atiyor. */

int main()
{
	int fd1, fd2;
	fd1 = open("mydup", O_CREAT | O_RDWR | O_TRUNC, 777);
	if (!fd1)
		return 1;
	fd2 = dup(fd1);
	// write(fd1, "hello there\n", 12); // bu da çalışıyor
	// write(fd2, "hello there\n", 12); // bu da çalışıyor çünkü kopyaladık
	close(fd1);
	close(fd2);
}
