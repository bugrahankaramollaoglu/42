#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	char *command = "/bin/ls";
	char *args[] = {command, NULL};
	char *envp[] = {NULL};

	execve(command, args, envp);

	// execve only returns if an error occurs
	perror("execve");
	return 1;
}

