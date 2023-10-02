#include <stdio.h>
#include <unistd.h>

/* execve() mevcut proseste bir başka prosesi çalıştırmaya yarar. */

int main()
{
	char *argumanlar[] = {"pwd", NULL};
	char *cevre_degiskenleri[] = {NULL};

	execve("/bin/pwd", argumanlar, cevre_degiskenleri);

	return 1;
}
