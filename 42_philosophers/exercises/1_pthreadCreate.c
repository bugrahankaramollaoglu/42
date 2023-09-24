#include <pthread.h>
#include <stdio.h>

/* başlangıçta main çalışırken program bir tane ana threadle başlar.
ondan sonraki bütün threadler pthread_create() fonksiyonuyla yaratılmalıdır. */

void *fun(void *arg)
{
	printf("Hello from the thread!\n");
	return NULL;
}

/* pthread_create(1,2,3,4) fonksiyonunda
	@1 -> yaratılacak threadin adresi
	@2 -> thread attributes. genelde NULL
	@3 -> threadin çalıştıracağı fonksiyon: (void*)fun(void*)
	@4 -> bu fonksiyona gelecek parametre. */

int main()
{
	pthread_t thread;

	pthread_create(&thread, NULL, fun, NULL);
	pthread_join(thread, NULL);

	return 0;
}
