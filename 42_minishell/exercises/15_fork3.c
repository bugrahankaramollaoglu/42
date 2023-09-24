#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
		printf("bu satırı parent process calıstıracak\n");
	if (pid == 0)
		printf("bu satırı child process calıstıracak");
	if (pid < 0)
		printf("hata durumu\n");
}
