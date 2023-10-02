#include <unistd.h>
#include <stdio.h>

// read() from STDIN so that it échoes

int main()
{
	char buf[1024];
	ssize_t bytesRead = read(STDIN_FILENO, buf, sizeof(buf));
	if (bytesRead)
	{
		write(STDIN_FILENO, buf, bytesRead);
	}
}
