
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/* dup2(old_fd, new_fd) fonksiyonu old_fd'nin new_fd'li klonunu yaratır
new_fd now refers to the same file as old_fd but the file that new_fd had previously pointed
is now closed (because a fd cannot point to two different files at the same time.)
This can be useful for redirecting input or output to a different file or device.
If dup2() is successful, it returns the new file descriptor. If an error occurs, it returns -1. */

int main()
{
	int fd = open("asd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	else
	{
		int new_fd = dup2(fd, STDOUT_FILENO); // fd'yi stdoutput fd'sine kopyalıyiroz
		if (new_fd == -1)
		{
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		printf("This message will be written to asd.txt\n");
		close(fd);
	}
}
