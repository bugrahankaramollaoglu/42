
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

// derlerken -lreadline ile derlemelisin

/* Clear the history list by deleting all of the entries, in the same manner as the History
library’s clear_history() function. This differs from clear_history because it
frees private data Readline saves in the history list */

int main()
{
	add_history("command1");
	add_history("command2");
	add_history("command3"); // bu fonksiyonla 3 tane komut ekledik history'ye

	rl_clear_history(); // bunla da siliyoruz geçmişi
}
