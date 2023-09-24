#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

void *worker(void *data)
{
	char *name = (char *)data;
	for (int i = 0; i < 100; ++i)
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
	sleep(1);

	/* eğer pthread_exit() demezsek bugra/cemre is done satırlarını
	görmüyoruz. sebebi şu: main proses pthread_exit() gördügü zaman
	t1 ve t2 threadlerinin bitmesini beklemeden sonlanmıyor. */

	/* ya da pthread_exit() olmasa bile <100 yerine <10 ya da usleep(elli bin) yerine
	beş bin dersek bugra/cemre is done satırlarını görüyoruz. bunun sebebi ise şu:
	main proses 1 saniye beklerken is done yazdırmaya <100 ya da 50.000 bekletildiginde
	threadlerin vakti olmuyor, ama her işlemde daha az bekletirsek main bitmeden bitebiliyolar */
	pthread_exit(NULL);
	return 0;
}
