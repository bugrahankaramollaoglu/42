#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/* zombie process işlemi biten ama systemtray'de kalmaya
devam edenlere denir. sonsuz looplarda görülür */

int main()
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
		return 1;
	else if (pid == 0)
	{
		printf("child with %d\n", pid);
		printf("child done\n");
	}
	else
	{
		printf("parent\n of %d\n", pid);
		while (1)
			;
		sleep(1);
	}
}

/* bu durumda parent hiç bitmediği için onun cocugu yetim kalmıs oldu
bu durumu önlemek için wait() ve waitpid() fonksiyonlarını kullanmalıyız*/
