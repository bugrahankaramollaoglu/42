/* access function is used to check the accessibility of a file
or directory. It allows you to determine if a file or directory
can be accessed in a specific way, such as checking for read,
write, or execute permissions.

int access(const char *path, int mode);
	path: The path to the file or directory that you want to check accessibility for.
	mode: The mode that specifies the type of access you want to check. It can be a combination of one or more of the following flags:
		R_OK: Check for read access.
		W_OK: Check for write access.
		X_OK: Check for execute (search) access.
		F_OK: Check for existence of the file or directory.
 */

/* The access function returns 0 if the requested access is granted,
and -1 if the access is denied or an error occurs. The specific
error can be determined by examining the value of the errno global variable. */

#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	const char *filePath = "/media/bugra/depo/yazilim/42/9_minishell/exc/25.c";

	// Check if the file exists and has read access
	if (access(filePath, F_OK | R_OK) == 0)
		printf("File exists and has read access.\n");
	else
	{
		if (errno == ENOENT)
			printf("File does not exist.\n");
		else if (errno == EACCES)
			printf("File exists, but access is denied.\n");
		else
			printf("An error occurred while checking file accessibility.\n");
	}

	return 0;
}
