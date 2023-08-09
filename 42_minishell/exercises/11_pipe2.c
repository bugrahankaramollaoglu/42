
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// pipe 2

int main(void)
{
	int pipefds[2];
	char buffer[5];

	if (pipe(pipefds) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}

	char *pin = "235\0";

	// pipe'a yazma yapiyor
	printf("Writing PIN to pipe...\n");
	write(pipefds[1], pin, 5);
	printf("Done.\n\n");

	// pipe'tan okuma yapiyor
	printf("Reading PIN from pipe...\n");
	read(pipefds[0], buffer, 5);
	printf("Done.\n\n");

	printf("PIN from pipe: %s\n", buffer);
}
