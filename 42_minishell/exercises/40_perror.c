#include <stdio.h>
#include <errno.h>

/* perror() fonksiyonu 2FD'sine yani STDERR'e hata yazdırmaya yarar */

int main()
{
	FILE *file = fopen("rıonegğ.txt", "r");
	if (!file)
	{
		perror("böyle dosya yok\n");
		return 1;
	}
	fclose(file);
}
