#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

/* fork işlemi yaptıgında main prosesteki tüm değişkenler hafıza alanında
childa kopyalanır ama fork satırından sonra yaptıgın degisiklikler birbirini
etkilemez. */

int	main(int ac, char **av)
{
	int	id;
	int	n;

	id = fork();
	if (id != 0)
	{
		ac = 5;
		printf("%d\n", ac); // 5
	}
	else if (id == 0)
	{
		printf("%d\n", ac); // 1 (farklı ac kopyalarında işlem yapiyor farklı prosesler.
		// her birinin kendine özel hafıza alanı var.)
	}
}
