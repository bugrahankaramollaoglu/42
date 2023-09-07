
// pipe, IPC, interprocess yani prosesler arası iletişimi sağlayan protokolün adıdır.
// bir prosesin outputunu diğerine input olarak vermeye yarar.
// pipe(int pipefd[2]) fonksiyonu C'de pipe yaratmada kullanılır.
// bu pipe daha sonra prosesler arası veri akışı sağlar.
// parametre olarak iki elemanli bir int array alir.
// bu elemanlarin her biri birer file descriptor'dır.
// arrayin birinci elemanı pipe'tan okuma ikinci elemani pipe'a yazma işlemi yapar

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int main()
{
	int myPipe[2]; // pipe'ın fd'lerini tutacak array

	int ret = pipe(myPipe); // pipe() fonksiyonu başarılıysa 0, değilse -1 döndürür.

	if (ret == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Read File Descriptor Value: %d\n", myPipe[0]);	// 3
		printf("Write File Descriptor Value: %d\n", myPipe[1]); // 4
	}
}
