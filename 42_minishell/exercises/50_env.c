#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av, char **env)
{
	for (char **en = env; *en; en++)
		printf("%s\n", *en);
}

/*

extern char **environ;

int main() {
  char **s = environ;

  for (; *s; s++)
	printf("%s\n", *s);
}

*/
