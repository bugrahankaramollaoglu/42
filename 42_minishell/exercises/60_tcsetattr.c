#include <stdio.h>
#include <termios.h>

/* tcsetattr() fonksiyonu bir fd'ye bir terminal ayarlarını
apply etmeye yarar. */

int main()
{
	int fd = fileno(stdin);
	struct termios old_term, new_term;

	// terminalimizi açtık
	tcgetattr(fd, &old_term);

	// kopyalayalım
	new_term = old_term;

	// terminal ayarlarını değiştirelim (ECHO özelliğini (yazarken görme) siliyoruz)
	// lflag stands for - local flag. termios structının lokal ayarlarını işaret eder.
	new_term.c_lflag &= ~ECHO;

	// echo'suz terminale geçiş yapti
	// TCSANOW hemen etki etmesini sağlar
	tcsetattr(fd, TCSANOW, &new_term);

	printf("enter a password: ");
	char password[20];
	fgets(password, sizeof(password), stdin);
	printf("\n");

	printf("password: %s\n", password);

	// echolu terminale geçiş yaptı echo geri geldi
	tcsetattr(fd, TCSANOW, &old_term);
}
