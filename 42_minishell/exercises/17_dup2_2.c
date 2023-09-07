#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* dup2(int old_fd, int new_fd) fonksiyonu dup() gibi bir fd'yi kopyalamaya yarar.
ama farkı şudur: dup() en küçük kullanılmayan fd'yi atarken, dup2() fonksiyonunda
istediğimiz fd'yi belirleyebiliyoruz. */

int main()
{
	int fd1 = open("37.txt", O_CREAT | O_RDWR, 777);
	int fd2 = dup2(fd1, 324);
	write(fd2, "asd\n", 4); // 37.txt'e yazdırdı
	printf("%d\n", fd2);	// 324
}
