
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

/* signal(signal, buSignalGeldiginceCalisacakFonksiyon) şeklindedir
	1) SIG_INT -> görevi sonlandırır (ctrl+c)
	2) SIG_QUIT -> programdan cıkar (ctrl + \)
	3) SIG_IGN -> ignore eder, does nothing
 */

void signalTaker(int sigNumber)
{
	printf("received SIGINT with num: %d\n", sigNumber);
}

int main()
{
	while (1)
	{
		if (signal(SIGINT, signalTaker) == SIG_ERR)
		{
			printf("sinyal alınamadı\n");
			return 1;
		}
	}
}
