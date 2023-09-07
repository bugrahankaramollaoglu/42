#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

/* başlangıçta main çalışırken program bir tane ana threadle başlar.
ondan sonraki bütün threadler pthread_create() fonksiyonuyla yaratılmalıdır. */

void *worker(void *data)
{
	char *name = (char *)data;
	for (int i = 0; i < 100; i++)
	{
		usleep(50000);
		printf("hello from thread %s\n", name);
	}
	printf("thread %s is done\n", name);
	return 0;
}

int main()
{
	pthread_t t1, t2;
	pthread_create(&t1, NULL, worker, "bugra");
	pthread_create(&t2, NULL, worker, "cemre");
	sleep(5);
	pthread_exit(NULL);
	return 0;
}
