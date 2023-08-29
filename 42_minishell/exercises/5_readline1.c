#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>

// readline(char *p) fonksiyonu p promptuyla bir string bekler senden
// aldığı stringi de döndürür
// eğer p NULL ise prompt yazdırmadan bekler
// eğer boş bir inputta EOF görürse NULL olarak algılar
// dolu bir inputta EOF görürse \n olarak algılar

// derlerken -lreadline flagiyle derlemelisin

int main()
{
	char *a = readline("enter here sth: ");
	printf("%s\n", a);
}
