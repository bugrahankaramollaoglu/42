/* open function is used to open files or create new files.
It provides a way to access the contents of files for
reading, writing, or both.

#include <fcntl.h>

int open(const char *path, int flags, mode_t mode);
	path: The path to the file you want to open or create.
	flags: Flags that control how the file should be opened. These can be combined using the bitwise OR operator (|). Some commonly used flags include:
		O_RDONLY: Open the file for reading only.
		O_WRONLY: Open the file for writing only.
		O_RDWR: Open the file for reading and writing.
		O_CREAT: Create the file if it does not exist.
		O_TRUNC: Truncate the file if it already exists.
		O_APPEND: Append to the file instead of overwriting its contents.
	mode: The permissions to be set on the file if it is created. It is only used when
	the O_CREAT flag is included. You can use symbolic constants like S_IRUSR
	(read permission for the owner), S_IWGRP (write permission for the group), etc.,
	combined with bitwise OR operator (|) to specify the desired permissions  */

/* open() fonksiyonu finalde açtığı dosyanın file descriptor numarasını döndürür.
hata varsa -1 yazdırır errno'ya */

#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	const char *path = "/home/bugra/Desktop/bugra.txt";

	int myFd = open(path, O_RDWR);
	if (myFd != -1)
	{
		printf("dosya var ya da yaratıldı\n");
	}
	else
	{
		printf("dosya yok ya da erişim reddedildi\n");
		exit(1);
	}
}
