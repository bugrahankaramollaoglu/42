#include <pthread.h>
#include <stdio.h>

int count = 1;
pthread_mutex_t mutex;

void *print_odd(void *arg)
{
	while (count <= 10)
	{
		// we should mutex lock before modifying the shared value
		pthread_mutex_lock(&mutex);
		if (count % 2 == 1)
		{
			printf("Odd: %d\n", count);
			count++;
		}
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void *print_even(void *arg)
{
	while (count <= 10)
	{
		pthread_mutex_lock(&mutex);
		if (count % 2 == 0)
		{
			printf("Even: %d\n", count);
			count++;
		}
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int main()
{
	pthread_t odd_thread, even_thread;
	pthread_mutex_init(&mutex, NULL);

	pthread_create(&odd_thread, NULL, print_odd, NULL);
	pthread_create(&even_thread, NULL, print_even, NULL);

	pthread_join(odd_thread, NULL);
	pthread_join(even_thread, NULL);

	pthread_mutex_destroy(&mutex);

	return 0;
}
