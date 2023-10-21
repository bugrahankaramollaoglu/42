#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/* dup2() function bir fd'yi (@1) bir başka kanala/fd'ye (stream)
kopyalamaya yarar. eğer @1 açıksa kapatılır. sonra @2ye kopyalar.
@1 açık kalır, kapamak istiyosan close() ile kapamalısın.
dup() da aynı şeyi yapiyordu ama dup2'nin aksine @2 almiyordu, onun
yerine açıktaki en düşük fd'ye kopyaliyodu. return olarak @2'yi döndürür. */

int main()
{
	int fd = open("myfile", O_CREAT | O_WRONLY);
	dup2(fd, STDOUT_FILENO); // ya da 1 de diyebilirdin
	printf("bugra\n");
	printf("kara\n");
	printf("molla\n");
	printf("oglu\n");
	/* STDOUT olarak newFile'ı verdiğimiz için STDOUTa yazdıran tüm fonksiyonlar
	terminale değil myfile dosyasının içine yazdıracak artık. */
}
