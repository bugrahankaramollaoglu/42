#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

/* bir child parentının exact kopyasıdır, hafızasıyla, data segmentiyle etc.
ama parentta olan her şey childda da olmaz. mesela */

int i = 10;

int main()
{
	pid_t pid;
	pid = fork();
	if (pid == -1)
	{
		printf("hata\n");
		exit(1);
	}
	else
		printf("fork() işlemi başarili\n");
	if (pid == 0)
	{
		printf("it is child process with pid of %d\n", pid);
		printf("i in child: %d\n", i); // 10
	}
	else if (pid > 0)
	{
		printf("it is parent process. child's pid is %d\n", pid);
		i = 20;
		printf("i in parent: %d\n", i); // 20
										// i'yi forkladıktan sonra değiştirdiğimiz için
										// parenttaki değişiklik childda da uygulanmaz
	}
}
