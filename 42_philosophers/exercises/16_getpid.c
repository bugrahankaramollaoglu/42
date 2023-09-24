#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == 0)
	{
		// This code is executed by the child process
		printf("Child process: My PID is %d.\n", getpid());
	}
	else if (child_pid > 0)
	{
		// This code is executed by the parent process
		printf("Parent process: Child's PID is %d.\n", child_pid);
	}
	else
	{
		perror("fork");
		return 1;
	}

	printf("PID %d is done.\n", getpid());

	return 0;
}
