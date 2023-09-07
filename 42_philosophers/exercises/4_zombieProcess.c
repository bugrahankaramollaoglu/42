#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// eğer bir child process bitmeden main biterse o child
// asla bitemez, buna zombie process denir

int main()
{
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		// Child process
		exit(0);
	}
	else
	{
		// Parent process
		sleep(10);	// Parent process sleeps for 10 seconds
		wait(NULL); // Parent waits for child process to exit
		while (1)
		{
			sleep(1); // Parent process continues to execute, creating a zombie child
		}
	}
}
