#include <unistd.h>
#include <stdio.h>

/* access(const char * path, mode) fonksiyonu bir dosyanın konumunu alır, eğer dosya varsa
modu uygular ve 0 döndürür yoksa -1 döndürür */

/* modlar

F_OK: checks whether the file exists
R_OK: gets read permission if file exists
W_OK: gets write permission if file exists
X_OK: gets execute permission if file exists  */

int main()
{
	if (access("asd.txt", F_OK | R_OK) == 0)
		printf("dosya mevcut\n");
	else
		printf("dosya mevcut degil\n");
}
