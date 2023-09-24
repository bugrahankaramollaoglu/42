#include <pthread.h>
#include <stdio.h>

// şu şekilde çalıştırarak dataRace kontrolü yapabilirsin
// gcc main.c - fsanitize = thread

int count = 0;

void *increment(void *arg)
{
	int i;
	for (i = 0; i < 1000000; i++)
		count++;
	return (NULL);
}

int main(void)
{
	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, increment, NULL);
	pthread_create(&thread2, NULL, increment, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Final count value: %d\n", count);
}

/* yukarıdaki kodda ortak bir count isminde değişkenimiz var. global tanımladıgımız
bu değişkeni iki thread de arttırmaya çalışıyor. pthread_create() fonksiyonlarından
birini silersek bu degisken istendigi gibi 100000 oluyor fakat aynı anda ikisi de
yaparsa (paralel) tamamlanamadan data race oluyor ve her calıstıgında random bir yerde
arttırma islemi tıkanıyor. mutex ya da semaphore gibi senkronizasyon islemi kullanmadıgımız
icin bu sorun meydana geliyor. the final value of count is not deterministic,
and can vary between runs of the program. This is because both threads are racing to increment count,
and it's possible for one thread to read the value of count, increment it,
and write the new value back to count before the other thread has a chance to read
the updated value. This can result in lost updates or overwrites,
leading to an incorrect final value for count.

In the code above, we use pthread_join() twice to wait for both thread1 and thread2
to complete before printing the final value of count. This ensures that we get
the correct final value of count, and that the program does not terminate prematurely. */
