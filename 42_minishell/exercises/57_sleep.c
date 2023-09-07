#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t child_pid = fork();

	// The child process
	if (child_pid == 0)
	{
		sleep(1); // Sleep for one second
		printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
			   getpid(), child_pid);
	}
	else
	{
		printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
			   getpid(), child_pid);
	}

	// 56'nın aynısı ama sadece parentı değil childı 1 saniye uyutuyoruz
	// bu durumda child blogu okunmadan program bitiyor çünkü
	// main bitmiş oluyor ve main process bittikten sonra bütün program sonlanıyor
}
