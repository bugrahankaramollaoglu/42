#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *input;

	// Read lines until "exit" is entered
	while ((input = readline("> ")) != NULL)
	{
		// Add the command to the history
		if (input[0] != '\0')
			add_history(input);

		// Check for the exit condition
		if (strcmp(input, "exit") == 0)
		{
			free(input);
			break;
		}

		// Process the input (in this case, just printing it)
		printf("you entered: %s\n", input);

		// Free the input buffer
		free(input);
	}

	return 0;
}
