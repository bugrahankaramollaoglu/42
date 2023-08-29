#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
	char *myUser = getenv("USER");
	printf("%s\n", myUser);
	int i = -1;
	while (env[++i])
	{
		printf("INDEX = %d %s\n", i, env[i]);
	}
}
