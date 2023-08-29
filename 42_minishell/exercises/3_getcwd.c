
#include <unistd.h>
#include <stdio.h>

// getcwd() programın çalıştığı dizini verir

int main()
{
	char path[200];
	getcwd(path, 45);
	printf("our path is: %s\n", path); // our path is: /media/bugra/depo/yazilim/42/9_minishell/exc
}

// sadece buffer büyüklüğü yeterliyse yazdırır, değilse ya da herhangi bir hata durumunda NULL döndürür.

