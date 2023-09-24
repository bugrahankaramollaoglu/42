#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* fork() fonksiyonundan sonra gelen her şey iki kere işlenir, biri
main proseste diğeri child proseste. kullanilan fork() sayisi üzeri 2
kadar proses yaratilir. mesela ilk fork() 2, ikinci fork 4, üçüncü fork()
8 tane child proses yaratir. */

int main()
{
	/* fork a process */
	fork();
	fork();
	/* the child and parent will execute every line of code after the fork (each separately)*/
	printf("Hello world!\n");
	return 0;
}
