#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

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

	/* bir önceki dosya için bir başka çözüm de şu:
	pthread_create() ile threadleri yarattıktan sonra sleep(1) atarsan
	main o esnada beklerken threadler başlar ve yazarlar işlemlerini ekrana.
	bu durumda pthread_join()'lere yani main prosesine sub-threadleri
	bekleme komutu vermene htiyaç kalmaz. */
	sleep(1);
}
