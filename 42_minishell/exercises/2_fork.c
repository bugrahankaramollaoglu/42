#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* fork() fonksiyonu parentın klonu bir child process yaratmada kullanılır.
yaratılan bu proses eşzamanlı çalışır. */

// pid_t fork(void);

/* burada pid_t veri tipi sadece pid tutan bir signed integer tipidir. eğer fork()
fonksiyonu -1 döndürürse, fork() işlemi yapılamamış demektir. 0 döndürürse o an child
process içindeyiz demektir. diğer türlü parent prosesteyizdir. */

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		printf("hata\n");
		exit(1);
	}
	else
		printf("fork() işlemi başarili\n");
	if (pid == 0)
		printf("it is child process with pid of %d\n", pid);
	else if (pid > 0)
		printf("it is parent process. child's pid is %d\n", pid);
}

/* yukarıda 19. satıra gelindiğinde child yaratılıyor. bu noktadan sonra
parent da child da işleme başlıyor. parentın pid 0 olmadığından alttakine,
child'ın 0 olduğundan üsttekine giriyorlar ayrı ayrı. */

