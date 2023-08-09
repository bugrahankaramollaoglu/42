#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* wait() fonksiyonu bir main prosesi childlar sonlanana kadar bitirmeye yarar */

int main()
{
	pid_t childPid = fork();

	if (childPid == 0)
	{
		// Child process
		printf("Child process executing.\n");
		sleep(2); // Simulate some work

		// Exit the child process
		printf("Child process exiting.\n");
		return 42;
	}
	else if (childPid > 0)
	{
		// Parent process
		printf("Parent process waiting for child process to terminate.\n");

		int status;
		pid_t terminatedChildPid = wait(&status);

		if (terminatedChildPid == -1)
		{
			// An error occurred
			printf("An error occurred while waiting for child process.\n");
		}
		else
		{
			if (WIFEXITED(status))
			{
				// Child process terminated normally
				int exitStatus = WEXITSTATUS(status);
				printf("Child process with PID %d terminated with status %d.\n", terminatedChildPid, exitStatus);
			}
			else if (WIFSIGNALED(status))
			{
				// Child process terminated due to a signal
				int signalNumber = WTERMSIG(status);
				printf("Child process with PID %d terminated due to signal %d.\n", terminatedChildPid, signalNumber);
			}
		}
	}
	else
	{
		// Forking failed
		printf("Forking failed.\n");
	}

	return 0;
}
