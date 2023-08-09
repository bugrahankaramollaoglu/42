#include <errno.h>
#include <string.h>
#include <stdio.h>

/* hata numarasını insan formatında string olarak vermeye yarar.
hata numarasını parametre olarak alır ve stringe pointer döndürür. */

int main()
{
	char *errMessage = strerror(0); // success
	errMessage = strerror(1);		// operation not permitted
	errMessage = strerror(2);		// no such file or directory
	errMessage = strerror(3);		// no such process
	errMessage = strerror(4);		// interrupted system call  .....

	printf("%s\n", errMessage);
}
