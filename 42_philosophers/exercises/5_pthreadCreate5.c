#include <pthread.h>
#include <stdio.h>

#define NUM_THREADS 3

void *fun(void *arg)
{
	int *threadNumber = (int *)arg;
	printf("hello from thread: %d\n", *threadNumber);
}

int main()
{
	pthread_t threads[NUM_THREADS];

	int threadArgs[NUM_THREADS];

	for (int i = 0; i < NUM_THREADS; i++)
	{
		threadArgs[i] = i + 1;
		pthread_create(&threads[i], NULL, fun, &threadArgs[i]);
	}

	for (int i = 0; i < NUM_THREADS; i++)
	{
		pthread_join(threads[i], NULL);
	}
}

/* bazen 1 3 2 oluyor bazen 1 2 3, threadlerin o anki hızına göre değişiyor */
