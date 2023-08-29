#include <stdio.h>
#include <termios.h>

/* tcgetattr(int fd, struct termios *term) fonksiyonu terminalin
o anki özelliklerini döndürür. @1 burada terminalin file descriptor'ıdır
termios struct'ta ise terminal özellikleri tutulacak */

int main()
{
	int fd = open(stdin);
	struct termios term;

	if (tcgetattr(fd, &term) == -1)
	{
		perror("tcgetattr hatasi\n");
		exit(1);
	}

	// daha sonra terminalini değiştirebilirsin ...
}
