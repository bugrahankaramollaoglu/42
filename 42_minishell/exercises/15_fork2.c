#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int main()
{
	pid_t pid;
	pid = fork();
	pid = fork();
	printf("hem mother hem child proses buna girecek, o yüzden 4 kere yazdırılacak\n");
}
