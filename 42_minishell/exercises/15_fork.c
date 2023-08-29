
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// fork() fonksiyonu prosesi kopyalar ve pid_t türünden bir pid döndürür.
// bu kopyalamanın sonunda child ve parent olmak üzere iki prosesimiz olur.
// bu pid numarası 0'sa child prosesteyiz demektir. değilse parenttayizdir.

int main()
{
	pid_t pid;

	// fork'u çağırarak main prosesten child yarattık
	pid = fork();

	if (pid == 0)
		printf("I am the child process with pid %d\n", getpid());
	else if (pid > 0)
		printf("I am the parent process with pid %d\n", getpid());
	else if (pid < 0)
	{
		printf("fork failed\n");
		return 1;
	}
}

/* bu kodda önce main process baştan aşağıya okuyor kodu, pid'i 0 olmadıgından parent printfine giriyor
daha sonra fork() sayesinde yarattıgın child process de aynısını yapiyor ama 0 oldugundan childa giriyor  */
