#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
	pid_t my_pid = fork();

	if (my_pid == 0)
	{
		printf("buraya giren child proses. id'si:  %d\n", getpid());
	}
	else if (my_pid > 0)
	{
		printf("buraya giren parent proses. id'si: %d\n", getpid());
	}
}
