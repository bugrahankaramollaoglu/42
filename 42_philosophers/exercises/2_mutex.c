#include <stdio.h>

/* mutex thread senkronizasyonu sağlar. birden çok thread
yazma işlemi yapmaya çalıştığında shared data'yı korur.
mutexlenmiş bir değişkene tek ve aynı seferde yalnızca tek bir thread
ulaşabilir ve onu değiştirebilir. */

/* bir mutex nasıl kullanılır?

// mutex yarattık
pthread_mutex_t myMutex;

// ilklendirdik
pthread_mutex_init(philo->myMutex, NULL);

// kitledik
pthread_mutex_lock(philo->myMutex);

// kilidini açtık
pthread_mutex_unlock(philo->myMutex);

// yok ettik
pthread_mutex_destroy(philo->myMutex);

*/
