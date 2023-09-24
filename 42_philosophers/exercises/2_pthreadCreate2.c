#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

/* void *fun(void *arg)
{ 
	int threadNumber = *((int *)arg);
	printf("hello from thread: %d\n", threadNumber);
} */

void *fun(void *arg)
{
	int *threadNumber = (int *)arg;
	printf("hello from thread: %d\n", *threadNumber);
}

int main()
{
	pthread_t thread1, thread2;

	int arg1 = 1;
	int arg2 = 2;
	pthread_create(&thread1, NULL, fun, &arg1);
	pthread_create(&thread2, NULL, fun, &arg2);

	/* eğer pthread_join() ile threadlerin bitmesini main prosese
	bekletmezsek main proses erkenden biter ve threadler hiçbir şey
	ekrana yazdıramadan tüm program sonlanır. */
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
}
