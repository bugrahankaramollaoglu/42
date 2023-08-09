
#include <unistd.h>
#include <stdio.h>

// chdir() dizin değiştirmeye yarar

int main()
{
	char path[50];
	getcwd(path, 45);
	printf("our path is: %s\n", path); // our path is: /media/bugra/depo/yazilim/42/9_minishell/exc
	chdir("/media/bugra/depo");		   // şimdi bu dizine girer
	getcwd(path, 45);
	printf("our path is: %s\n", path); // our path is: /media/bugra/depo/
}
