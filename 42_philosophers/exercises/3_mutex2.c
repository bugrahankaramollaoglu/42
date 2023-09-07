#include <stdio.h>
#include <pthread.h>

// Global variables
int sharedCounter = 0;
pthread_mutex_t mutex;

// Function to be executed by multiple threads
void *threadFunction(void *arg)
{
	for (int i = 0; i < 5; i++)
	{
		pthread_mutex_lock(&mutex); // Acquire the mutex lock

		sharedCounter++; // Access the shared resource

		pthread_mutex_unlock(&mutex); // Release the mutex lock

		printf("Thread %d: Counter = %d\n", *((int *)arg), sharedCounter);
	}

	return NULL;
}

int main()
{
	pthread_t threads[2];
	int threadIds[2] = {1, 2};

	pthread_mutex_init(&mutex, NULL); // Initialize the mutex, not lock
	// @2 of mutx_init() gives extra attributes

	for (int i = 0; i < 2; i++)
	{
		pthread_create(&threads[i], NULL, threadFunction, &threadIds[i]);
	}

	for (int i = 0; i < 2; i++)
	{
		pthread_join(threads[i], NULL);
	}

	pthread_mutex_destroy(&mutex); // Destroy the mutex

	return 0;
}
