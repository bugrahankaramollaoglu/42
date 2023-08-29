#include <stdio.h>
#include <signal.h>
#include <pthread.h>

void signalHandler(int a)
{
	printf("Received CTRL+C signal\n");
}

int main()
{
	while (1)
	{
		signal(SIGINT, signalHandler);
	}
}
