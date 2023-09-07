#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* waitpid() fonksiyonu ana prosese (belirli ya da herhangi bir) child prosesin
bitmesini bekletmeye ve hangi kodla bittiyse onu öğrenmemize yarar. */

int main()
{
	// fork() fonksiyonu child proses yaratır, yarattığı childin
	// pid'ini döndürür.
	pid_t childPid = fork();

	// child açılamamış demektir
	if (childPid == -1)
		return 1;
	// child açılmış demektir
	else if (childPid == 0)
	{
		printf("it is child... waiting for it to finish\n");
		sleep(3);
		printf("child is finished\n");
		return 0;
	}
	// buna girerse şu an main prosesteyiz demektir
	else
	{
		int status;
		printf("it is parent\n");
		pid_t terminatedChildPid = waitpid(childPid, &status, 0);
		if (terminatedChildPid == -1)
		{
			printf("waitpid calısmadı\n");
			return 1;
		}
	}
}
