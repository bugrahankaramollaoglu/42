#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

/* bir prosesin altında çalışan ve onun aynı kaynakları
ve file descriptorları kullanan lat prosese child proses denir.
her prosesin birden fazla child prosesi ama yalnızca tek bir parent
prosesi olabilir. eğer bir prosesin parent prosesi yoksa o proses
çekirdek tarafından direkt yaratılmıştır. her bilgisayarın her bootta
ilk çalışan prosesi <init> prosesidir ve asla kapanmaz. */

/* bir child iki şekilde bitebilir: exit() ile çıkabilir ya da sinyallerle kesilebilir.
bir child proses ölürse parent prosesine SIGCHLD sinyali gönderilir, genelde
bu sinyal ignore edilir.  */

/* bir child bitmeden parent proses biterse orphan proses olur, init daha sonra adopt eder
bir child ölmesine rağmen kaynak tüketiyorsa zombie proses olur. */

int main()
{
	pid_t child_pid = fork();

	if (child_pid < 0)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		printf("Child process running.\n");
		// sleep(5); // bu olursa child is done yazdirilmadan parent bitiyor
		printf("Child process (%d) is done.\n", getpid());
	}
	else
	{
		printf("Parent process running\n");
		printf("Parent process created a child: %d\n", child_pid);
	}

	return 0;
}

