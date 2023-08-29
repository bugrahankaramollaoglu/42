#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

/* The parent process does not systematically take care of its
children. In the following example, we will force the child
process to sleep for 1 second before ending, but let
 the parent terminate right away: */

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
	}
}

/* parent proses child prosesi beklemeden çıktığı için
child process yarım kalır ve kapanmaz. kendisi bitmeden, daha doğrusu
parenti child'ının bitmesini beklemeden kapanan durumlarda child process
orphan process adını alır ve sonlanamaz. bu durumda parenti init, ppid'si 1 olur. */
