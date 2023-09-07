#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

/* Tells the update functions that we have moved onto a new (empty) line, usually after
outputting a newline. */

int main()
{
	char *input;

	while ((input = readline("> ")) != NULL)
	{
		// Process the input

		// Add the input to the history
		add_history(input);

		// Free the input buffer
		free(input);

		// Move the cursor to a new line
		rl_on_new_line();
	}
}
