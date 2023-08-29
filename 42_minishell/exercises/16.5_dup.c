#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* dup() fonksiyonu bir fd'yi klonlamaya yarar. */

int main()
{
	int fd1, fd2;
	fd1 = open("36.txt", O_CREAT | O_RDWR | O_TRUNC, 777);
	if (!fd1)
		return 1;
	fd2 = dup(fd1);
	write(fd1, "hello\n", 6); // bu da çalışıyor
	write(fd2, "there\n", 6); // bu da çalışıyor
							  // çünkü artık fd1 de fd2 de 36.txt'i gösteriyor
	close(fd1);
	close(fd2);
}
