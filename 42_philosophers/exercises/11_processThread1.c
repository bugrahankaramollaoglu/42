#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/* threadler */

void *thread_function(void *arg)
{
	int *thread_id = (int *)arg;
	printf("Thread %d is running...\n", *thread_id);
	sleep(2);
	printf("Thread %d is done.\n", *thread_id);

	return NULL;
}

int main()
{
	pthread_t thread1, thread2;
	int thread_id1 = 1, thread_id2 = 2;

	pthread_create(&thread1, NULL, thread_function, &thread_id1);
	pthread_create(&thread2, NULL, thread_function, &thread_id2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Main thread is done.\n");
}
