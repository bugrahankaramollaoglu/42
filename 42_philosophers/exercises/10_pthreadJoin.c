#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// pthread_join() fonksiyonuyla mevcut threadin bir başka
// threadin işini bitmesini beklemesini sağlayabiliriz. böylece sorun çıkmaz

void *thread_function(void *arg)
{
	// Do some work...
	printf("Thread is doing some work...\n");
	sleep(2);
	printf("Thread is done.\n");

	return NULL;
}

int main()
{
	pthread_t thread;
	int result;

	// Create a thread
	result = pthread_create(&thread, NULL, thread_function, NULL);
	if (result != 0)
	{
		perror("pthread_create");
		return 1;
	}

	printf("Thread created.\n");

	// Wait for the thread to finish using pthread_join
	result = pthread_join(thread, NULL);
	if (result != 0)
	{
		perror("pthread_join");
		return 1;
	}

	printf("Thread joined.\n");

	return 0;
}
