
#include <stdio.h>
#include <stdlib.h> // getenv'i barındırır

// getenv() gives the value of an environment variable.
// içine değerini almak istediğimiz ortam değişkeninin adını yaziyoruz
// bulamazsa NULL verir

int main()
{
	printf("%s\n", getenv("HOME")); // /home/bugra
	printf("%s\n", getenv("USER")); // bugra
}
