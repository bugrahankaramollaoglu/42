#include <stdio.h>
#include <pthread.h>

pthread_mutex_t myMutex;
int sharedCounter = 0;

/* eğer mutex kullanırsak burada sayi tam 200.000 oluyor
ama kullanmazsak her seferinde 100bin'in üstünde random
bir sayı oluyor. sebebi şu: hem thread1 hem thread2 sharedCounter
değişkenini 1 arttirmaya çalışıyor (çünkü yaratılırken bu threadlere
bu değişkeni arttıran fonksiyonu çalıştırmalarını söylüyoruz). eğer
bu fonksiyon içerisinde bir mutex değişkeni yaratip lock/unlock()
demezsek o değişkene aynı anda iki thread de hafızada erişebiliyor,
biri okuma yaparken diğeri arttırabilir. her bir thread zaten arttırıldığının
bilgisine sahip olmadıgı icin < 100k kuralı yıkılmış olur ve fazla sonuç çıkar. */
void *incrementCounter(void *arg)
{
	pthread_mutex_lock(&myMutex);
	for (int i = 0; i < 100000; i++)
		sharedCounter++;
	pthread_mutex_unlock(&myMutex);
}

int main()
{
	pthread_mutex_init(&myMutex, NULL);

	pthread_t thread1, thread2;

	pthread_create(&thread1, NULL, incrementCounter, NULL);
	pthread_create(&thread2, NULL, incrementCounter, NULL);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&myMutex);

	printf("The counter is now %d\n", sharedCounter);
}
