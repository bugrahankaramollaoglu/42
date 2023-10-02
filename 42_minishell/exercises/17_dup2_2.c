#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* dup2(int old_fd, int new_fd) fonksiyonu dup() gibi bir fd'yi kopyalamaya yarar.
ama farkı şudur: dup() en küçük kullanılmayan fd'yi atarken, dup2() fonksiyonunda
istediğimiz fd'yi belirleyebiliyoruz. */

int main()
{
	int fd1 = open("mydup2", O_CREAT | O_RDWR, 777);
	int fd2 = dup2(fd1, 324);
	write(fd2, "asd\n", 4); // mydup2'ye yazdırdı
	printf("%d\n", fd2);	// 324 id ile yeni bir fd yarattik
}
