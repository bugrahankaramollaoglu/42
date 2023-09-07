/* Replace the contents of rl_line_buffer with text. The point and mark are pre-
served, if possible. If clear undo is non-zero, the undo list associated with the current
line is cleared. */

#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int main()
{
	char *input;

	while ((input = readline("> ")) != NULL)
	{
		// Process the input

		// Replace the current line with new text
		rl_replace_line("New line", 1);

		// Move the cursor to the end of the new line
		rl_point = rl_end;

		// Redisplay the line
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
