
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	while (1)
	{
		char *line = readline("enter: ");
		add_history(line);
		printf("%s\n", line);
		if (strcmp(line, "quit") == 0)
			break;
	}
	system("leaks a.out");
}

// derlerken -lreadline -lncurses flagiyle derlemelisin
