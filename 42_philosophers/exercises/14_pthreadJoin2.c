#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *myTurn(void *arg)
{
	for (int i = 0; i < 8; i++)
	{
		sleep(1);
		printf("my turn! %d\n", i);
	}
	return NULL;
}

void yourTurn()
{
	for (int i = 0; i < 3; i++)
	{
		sleep(1);
		printf("your turn! %d\n", i);
	}
}

int main()
{
	pthread_t newThread;
	pthread_create(&newThread, NULL, myTurn, NULL);
	yourTurn();
	// pthread_join(newThread, NULL);
	return 0;
}
