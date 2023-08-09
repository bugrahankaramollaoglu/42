/* read function is used to read data from an open file
descriptor. It allows you to read a specified number of
bytes from a file or input source.

#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);

	- fd numaralı dosyadan
	- okunan bytelar buf'ta birikir
	- count kadar byte okunur */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define BUF 20

int main()
{
	const char *path = "/home/bugra/Desktop/bugra.txt";
	char buffer[BUF];

	int myFd = open(path, O_RDWR);

	if (myFd != -1)
	{
		ssize_t byteRead = read(myFd, buffer, BUF);

		if (byteRead == -1)
			printf("could not read file\n");
		else if (byteRead == 0)
			printf("EOF reached\n");
		else
			printf("read %zd bytes from the file with fd of %d\n", byteRead, myFd);
		close(myFd);
	}
	else
		printf("could not open file\n");
}
