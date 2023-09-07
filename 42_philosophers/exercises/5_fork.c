
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;

	pid = fork(); // create a new process

	if (pid == -1)
	{ // error handling
		fprintf(stderr, "Failed to fork\n");
		exit(1);
	}
	else if (pid == 0)
	{ // child process
		printf("Hello from child!\n");
	}
	else
	{ // parent process
		printf("Hello from parent! Child PID = %d\n", pid);
	}
}
