#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int newFile = open("file1.txt", O_CREAT | O_WRONLY);
	dup2(newFile, STDOUT_FILENO);
	printf("bugra\n");
	printf("kara\n");
	printf("molla\n");
	printf("oglu\n");
	/* STDOUT olarak newFile'ı verdiğimiz için STDOUTa yazdıran tüm fonksiyonlar
	terminale değil file1.txt dosyasının içine yazdıracak artık. */
}
