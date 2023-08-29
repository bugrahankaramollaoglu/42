#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* exit() fonksiyonu programdan çıkmaya yarar. içerisine
çıkış durumu yazılır. exit(0) başarıyla, exit(1) başarısız çıkış
yapıldıgını gosterir. program bitince otomatik olarak 0'la exit eder.
return'den farkı: return fonksiyondan exit tüm koddan çıkar.*/

int main()
{
	char a[256];
	while (1)
	{
		printf("enter quit to exit: ");
		scanf("%s", a);
		if (strcmp(a, "quit") == 0)
		{
			printf("quit yazildi\n");
			exit(0);
		}
	}
}
