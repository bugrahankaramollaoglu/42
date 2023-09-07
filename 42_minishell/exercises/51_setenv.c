#include <stdio.h>
#include <stdlib.h>

/* ortam değişkeni atamanın export haricindeki ikinci yolu */

int main()
{
	setenv("MY_NAME", "bugra", 1);
	char *val = getenv("MY_NAME");
	if (val)
		printf("%s\n", val);
}
