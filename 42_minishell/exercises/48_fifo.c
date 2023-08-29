#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

/* pipelarda yalnızca belli prosesler arasında iletişim kurabiliyodun
fifo sayesinde açık olan tüm prosesler arasında bilgi alıp gönderebilirsin */

int main(int ac, char **av)
{
	mkfifo("myfifo1", 0777);
	int fd = open("myfifo1", O_WRONLY);
	char *str = "pepsi\n";
	write(fd, str, sizeof(str)-1);
	close(fd);
}

/* bu kodu tek terminalde çalıştırırsan proses asılı kalır, yani kapanmaz
bunun sebebi open fonksiyonunu fifolarla kullandıgında bir baska prosesten (terminalden)
o dosyanın read-end'ini de açman gerekir. bunun için bu kodu çalıştırdıktan sonra
bir başka terminalde myfifo1 dosyasını cat'le okursan (cat) içeriğini yazdıracak ve
bu terminalden de çıkacaktır */
