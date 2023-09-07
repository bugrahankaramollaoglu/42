#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

/* Change what’s displayed on the screen to reflect the current contents of rl_line_buffer */

int main()
{
	char *input;

	while ((input = readline("> ")) != NULL)
	{
		// Process the input

		// Modify the current line
		// ...

		// Redisplay the modified line
		rl_redisplay();

		// Add the input to the history
		add_history(input);

		// Free the input buffer
		free(input);

		// Move the cursor to a new line
		rl_on_new_line();
	}

	return 0;
}
