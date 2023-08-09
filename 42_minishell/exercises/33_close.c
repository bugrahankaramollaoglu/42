#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

// close() fonksiyonu açık bir fd'yi kapatmaya yarar

int main()
{
	int fd = open("29.txt", O_CREAT, O_RDWR | 421);
	if (!fd)
		exit(1);
	/* .... */
	if (close(fd) == -1)
	{
		printf("could not close the file\n");
		return 1;
	}
	return 0;
}
