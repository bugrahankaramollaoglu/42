#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// pthread_detach() function is used to detach a thread.
// A detached thread is a thread that will free its resources
//  when it is finished. A detached thread cannot be joined.
//  If you want to join a thread, you should not detach it.

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

	// Detach the thread
	result = pthread_detach(thread);
	if (result != 0)
	{
		perror("pthread_detach");
		return 1;
	}

	printf("Thread created and detached.\n");

	// Main thread continues execution...
	sleep(3); // Give some time for the detached thread to finish

	return 0;
}
