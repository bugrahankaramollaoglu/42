#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// read() from a file

int main()
{
	int fd = open("file", O_RDWR);
	int fd2 = open("file2", O_RDWR | O_CREAT);
	if (!fd)
	{
		perror("hata");
		return 1;
	}
	char buf[1024];
	// neden size_t değil ssize_t kullandik? çünkü read -1 döndürebilir,
	// ssize_t de size_t aksine signed bir veri tipidir.
	ssize_t readBytes = read(fd, buf, sizeof(buf));
	write(fd2, buf, readBytes);
	close(fd);
}
