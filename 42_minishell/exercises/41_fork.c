#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* forking allows you to duplicate your process, that is create a child process
if the id of that fork is 0, we are in child process
if not we are in mother process
2 ^ fork() sayisi kadar kod blogların calısır. */

int	main(int ac, char **av)
{
	int	id;

	id = fork();
	if (id == 0) // we are in child
		printf("child\n");
	else
	{
		usleep(0000.1);
		printf("mother\n");
	}
}

/* mesela bu kodda fork satırına gelindiği anda child proses de devreye
giriyor ve çok ufak bir zaman farklıyla ikisi de okumaya başlıyor. şu durumda
önce else'e yani mothera giriyor ama mesela onu usleep ile bekletirsek child proses
öne geçiyor ve ilk child yazdırılıyor. (fun fact: minimum usleep(0000.1)'den sonra
bu dediğim çalışıyor). */
