#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t child_pid = fork();
	if (child_pid == 0)
		printf("\ncurrent pid is %d and child_pid is %d\n", getpid(), child_pid); // current pid is 17015 and child_pid is 17016
	else
		printf("\ncurrent pid is %d and child_pid is %d\n", getpid(), child_pid); // current pid is 17016 and child_pid is 0
																				  // çünkü bu child'ın childi yok o yüzden 0
	printf("\n");
	return 0;
}
