#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/* dup2(int old_fd, int new_fd) fonksiyonu dup() gibi, bir fd'yi kopyalamaya yarar.
ama farkı şudur: dup() en küçük kullanılmayan fd'yi atarken, dup2() fonksiyonunda
istediğimiz fd'yi belirleyebiliyoruz. */

int main()
{
	int fd1 = open("dosya1", O_CREAT | O_RDWR, 777);

	int fd2 = dup2(fd1, fd2);

	write(fd2, "fd2 yazdirdim\n", 14); // dup2 ile kopyaladıgımızdan dosya1'e yazdıracak
}
