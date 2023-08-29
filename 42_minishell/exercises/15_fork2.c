#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
	pid_t pid;
	pid = fork();
	printf("hem mother hem child proses buna girecek, o yüzden 2 kere yazdırılacak\n");
}
