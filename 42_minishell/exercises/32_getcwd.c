/* bu fonksiyon o anki konumu vermeye yarar */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_pwd()
{
	char *whereami = malloc(sizeof(char) * 256);
	if (!whereami)
		return;
	else
	{
		if (getcwd(whereami, 256))
			printf("%s\n", whereami);
	}
}

int main()
{
	ft_pwd();
}
