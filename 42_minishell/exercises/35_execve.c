#include <stdio.h>
#include <unistd.h>

/* execve() mevcut proseste bir başka prosesi çalıştırmaya yarar. */

int main()
{
	char *argumanlar[] = {"pwd", NULL};
	char *cevre_degiskenleri[] = {"PATH=/usr/bin", "TERM=linux", NULL};

	execve("/bin/pwd", argumanlar, cevre_degiskenleri);

	// Eğer execve() geri dönerse, bir hata oluşmuştur
	perror("execve ran erroneously\n");

	return 1;
}
