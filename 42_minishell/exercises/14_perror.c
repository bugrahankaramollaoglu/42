
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

// perror() stderr'e hata verdirmeye yarıyan fonksiyondur.

int main()
{
	FILE *fp;

	// try to open a non-existent file
	fp = fopen("nonexistent.txt", "r");
	if (fp == NULL)
	{
		// print an error message using perror()
		perror("hata -> "); // No such file or directory yazdırır
		exit(1);
	}

	fclose(fp);
	return 0;
}
