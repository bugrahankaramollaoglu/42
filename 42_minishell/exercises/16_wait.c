
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

// wait(int *status) fonksiyonu bir prosesi, child processlerinden biri ölene kadar bekletir.
// biri ölünce onun pid'sini parent processe iletir. parametresi ölecek child'in pid'sini tutacak bir int ptr'dir.
// hata olursa -1 döndürür

int main()
{
	pid_t pid;
	int status;
	pid = fork();
	if (pid == -1)
	{
		printf("fork failed\n");
		return 1;
	}
	else if (pid == 0)
	{
		printf("I am the child process with pid %d\n", getpid());
		// code for child process
		return 0;
	}
	else
	{
		printf("I am the parent process with pid %d\n", getpid());
		printf("Waiting for child process with pid %d to terminate...\n", pid);
		printf("\n");
		wait(&status);
		printf("Child process with pid %d has terminated with status %d\n", pid, status);
	}
}
