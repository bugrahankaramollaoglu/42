#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int id = fork();
	if (id == 0)
		sleep(1);
	printf("current id: %d, parent id: %d\n", getpid(), getppid());
}

/* mesela burada child'ı 1 saniye beklettiğimiz için main proses daha erken
biterek programı sonlandırdı ama child bitmediği için program yarıda kaldı. bu durumdaki
child proseslere zombie processes deniyor. bunun önüne geçmek için her fork kullandıgında
wait() de kullanmalısın

int main(int ac, char **av)
{
	int id = fork();
	if (id == 0)
		sleep(1);
	printf("current id: %d, parent id: %d\n", getpid(), getppid());
	if (id != 0)
		wait(NULL);
} */
