#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* how to send a wholed array using pipe */

int main()
{
	int fd[2];
	pipe(fd);

	int id = fork();
	int x;
	if (id == 0)
	{
		close(fd[0]);
		int ar[5] = {1, 2, 3, 4, 5};
		write(fd[1], ar, sizeof(ar));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int arReceived[5];
		read(fd[0], arReceived, sizeof(arReceived));
		close(fd[0]);
		printf("the array received: ");
		for (int i = 0; i < 5; i++)
			printf("[%d]", arReceived[i]);
		printf("\n");
	}
	close(fd[0]);
	close(fd[1]);
}
