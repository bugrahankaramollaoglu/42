#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("61.txt", O_CREAT | O_RDWR, 777);

	dup2(fd, STDOUT_FILENO);

	printf("hello\n");
}
