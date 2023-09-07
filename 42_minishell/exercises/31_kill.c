#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

/* kill() fonksiyonu sinyal göndermeye yarar */

void signalTaker(int pidNumber)
{
	printf("CTRL+C'ye basildi\n");
	exit(1);
}

int main()
{
	printf("press CTRL+C to finish\n");
	int pid = getpid();
	while (1)
	{
		signal(SIGINT, signalTaker);
	}
}
