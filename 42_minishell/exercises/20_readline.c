#include <stdio.h>
#include <stdlib.h>

char *readLine()
{
	char *line = NULL;
	size_t buffer = 0;
	getline(&line, &buffer, stdin);
	return line;
}

int main()
{
	printf("enter a text: ");
	char *inp = readLine();
	printf("you entered: %s", inp);
	free(inp);
}
