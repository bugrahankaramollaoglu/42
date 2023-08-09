#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	int id;
	int x;

	id = fork();
	if (id == 0)
	{
		x = 7;
	}
	else if (id != 0)
	{
		/* buradaki wait fonksiyonu sayesinde child bitiyor
		sonra main kaldıgı yerden devam ediyor */
		wait(NULL);
		x = 5;
	}
	for (int i = x; i <= 10; i++)
	{
		printf("[%d]", i);
	}
	printf("\n");
}
