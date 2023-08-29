#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>

/* two way communication between two processes using pipes
bir pipe aynı anda hem okuma hem de yazma yapamaz
bunun için iki adet pipe kullanmalıyız */

int main(int ac, char **av)
{
	int pipe1[2], pipe2[2];
	pipe(pipe1);
	pipe(pipe2);
	int pid = fork();
	if (pid == 0)
	{
		close(pipe1[0]);
		close(pipe2[1]);
		int x;
		read(pipe2[0], &x, sizeof(int));
		printf("received %d\n", x);
		x *= 10;
		write(pipe1[1], &x, sizeof(int));
		printf("wrote %d\n", x);
		close(pipe1[1]);
		close(pipe2[0]);
	}
	else
	{
		close(pipe1[1]);
		close(pipe2[0]);
		srand(time(NULL));
		int y = rand() % 10;
		write(pipe2[1], &y, sizeof(int));
		printf("wrote %d\n", y);
		read(pipe1[0], &y, sizeof(int));
		printf("result %d\n", y);
	}
}
