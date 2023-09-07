#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int fd1 = open("38.txt", O_CREAT | O_RDWR, 777);
	int fd2 = dup2(fd1, 1);
	printf("tüm printfler\n");
	printf("dosyaya yazdirilacak\n");
	printf("çünkü fd olarak biri\n");
	printf("yani STDOUT'u seçtik\n");
}
