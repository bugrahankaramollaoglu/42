#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int counter = 0;
pthread_mutex_t myMutex;

void *increment(void *content)
{
	int i = 0;
	for (i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&myMutex);
		counter++;
		pthread_mutex_unlock(&myMutex);
	}
}

int main()
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, increment, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count value: %d\n", counter);
}
