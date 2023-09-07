#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	id;
	int	n;
	int	i;

	id = fork();
	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}
	if (id != 0)
	{
		// that means we are in mother process so we can wait for the child to finish
		wait(&i); // [1][2][3][4][5][6][7][8][9][10]
	}
	for (i = n; i < n + 5; i++)
	{
		printf("[%d]", i);
		fflush(stdout);
	}
}
