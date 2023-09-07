
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/* readline kütüphanesinde
	1) readline(char*) fonksiyonu bir char* input alır
	2) rl_clear_history(void) geçmişi siler
	3) add_history(char*) bir char*'i geçmişe kaydediyor. program çalıştıgı müddetce erisebiliyoruz bunlara
	   yukarı ok tusuyla. minishell'deki history mevzusunu bununla cözülüyor  */

int main()
{
	while (1)
	{
		char *line = readline("Enter a line of text (quit to exit) >> ");
		if (strcmp(line, "quit") == 0)
		{
			printf("BYE\n");
			exit(1);
		}
		else if (line != NULL)
		{
			printf("You entered >> %s\n", line);
			free(line);
		}
		else
			printf("Error reading input.\n");
	}
}

// derlerken -lreadline -lncurses flagiyle derlemelisin
