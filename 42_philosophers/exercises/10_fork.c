#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* fork() bir prosesin kendisini ve bütün alt proseslerini
kopyalamasına denir. fork()'tan başka execve() ve system() gibi
başka proses yaratma teknikleri de vardır. aynı anda birden fazla programı
senkronize çalıştırabilen modern bilgisayarlarda her bir program açışımızda
implicit olarak fork() çalışır, bu sayede çalışan program kendisini kopyalayarak
child process yaratır. daha sonra bu child proses execve() ile çalıştıracağı komutu
işler. bu sayede yeni bir komut çalıştırdığımızda bir önceki sonlandırılmaz.
c/c++ fork() satırını gördüğü anda child için bir adres blogu ayırır. burada parentin
memory segmentinin ve fd'lerinin kopyası vardır. parenti ile iletişim kurabilmek için
çoğunlukla pipe'lar oluşturur. fork()'un vFork(), rFork() gibi varyantları vardır. */

/* fork()'un dönüş değerini ister intte ister pid_t'de tutabilirsin.
pid_t daha çok tercih edilir. */

/* fork() -1 döndürürse hata vardır
0 döndürürse child proses girer
0 harici döndürürse parent girer */

int main()
{
	pid_t pid;

	pid = fork(); // create a new process

	if (pid == -1)
	{ // error handling
		fprintf(stderr, "Failed to fork\n");
		exit(1);
	}
	else if (pid == 0)
	{ // child process
		printf("Hello from child!\n");
	}
	else
	{ // parent process
		printf("Hello from parent! Child PID = %d\n", pid);
	}
}
