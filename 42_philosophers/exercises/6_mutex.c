#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

/* mutex thread senkronizasyonu sağlar. birden çok thread
yazma işlemi yapmaya çalıştığında shared data'yı korur.
mutexlenmiş bir değişkene tek ve aynı seferde yalnızca tek bir thread
ulaşabilir ve onu değiştirebilir. */

// bir mutex nasıl kullanılır?
int main()
{

	// mutex yarattık
	pthread_mutex_t myMutex;

	// ilklendirdik
	pthread_mutex_init(&myMutex, NULL);

	// kitledik
	pthread_mutex_lock(&myMutex);

	// kilidini açtık
	pthread_mutex_unlock(&myMutex);

	// yok ettik
	pthread_mutex_destroy(&myMutex);
}
