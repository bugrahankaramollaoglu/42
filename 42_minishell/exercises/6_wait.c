#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/* waitpid() fonksiyonu parenti sonlandirmadan önce
child proseslerin sonlanmasını beklememize yarar

#include <sys/wait.h>

pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);

aralarındaki fark şu:
wait() fonksiyonu herhangi bir child prosesin bitmesini bekler
herhangi biri bittigi anda onun pid'sini döndürür
waitpid()'te ise spesifik bir pid'yi parametre olarak vererek
onun bitmesini bekleyebilirsin */

int main(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		printf("Child: I'm the child, my internal pid is %d.\n", pid);
		sleep(1); // Sleep 1 second.
		/* önce parent kendi komutlarını bitirir. daha sonra
		child okumaya başlar fakat o bitmeden parent bittiği için
		kendisi sonlanamaz */
		printf("Child: Done!\n");
	}
	else if (pid > 0)
	{
		printf("Parent: I'm the parent, my child's pid is %d.\n", pid);
		printf("Parent: Done!\n");
		wait(&pid); // burada child'ın bitmesi beklendiği için parent yarım kalmaz	
	}
}
