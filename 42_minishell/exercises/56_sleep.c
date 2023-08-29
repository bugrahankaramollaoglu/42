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
		printf("### Child ###\nCurrent PID: %d and Child PID: %d\n",
			   getpid(), child_pid);
	}
	else
	{
		sleep(1); // Sleep for one second
		printf("### Parent ###\nCurrent PID: %d and Child PID: %d\n",
			   getpid(), child_pid);
	}

	// burada görüyoruz ki main child'dı 1 saniye bekleyip öyle çalışıyor.
	// ama
	// 57.c'de durum farklı
}
