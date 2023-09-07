#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

/* sistemde bir fonksiyon hata verdiğinde hata kodu
errno isimli bir ortam değişkenine yazılır. bu değişkendeki
koda daha sonra istediğin gibi ulaşabilirsin */

int main()
{
	if (open("non.txt", O_RDONLY))
		printf("%s\n", strerror(errno));
}
