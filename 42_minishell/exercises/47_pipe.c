#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

/* prosesler arası iletişim kurmanın bi yolu pipe'tır.
forkladıktan sonra her bi proses değişkenlerin birer kopyasını
tuttugundan birinde yapılan degisiklikleri digeri göremiyodu.
bunun bi cözümü pipe kullanmak. pipe sayesinde dosyalar üzerinden
iletişim kurabiliyor iki farklı proses. pipe iki elemanlı bir integer
array aliyor. bu fd arrayinde fd[0] read-end için yani okuma yapmak için
fd[1] ise write-end yani yazma işlemi yapmak için kullanılıyor. */

int main(int ac, char **av)
{
	/* fd[0] --> read_end
	   fd[1] --> write_end */
	int fd[2];

	// rutin hata kontrolü
	if (pipe(fd) == -1)
		return 1;

	int id = fork(); // fork() satırına kadar yaptıgın her şey childda da kopyalanır, fd[2] dahil
	if (id == 0)
	{
		close(fd[0]); // childdan bir şey okumayacagımızdan kapatiyoruz
		/* child proseste inputla aldigimiz degiskeni main'e göndermek istiyoruz */
		int x;
		printf("enter a num: ");
		scanf("%d", &x);
		/* onu da böyle yapiyoruz */
		if (write(fd[1], &x, sizeof(int)) == -1)
		{
			printf("could not write\n");
			return 2;
		}
		close(fd[1]);
	}
	else
	{
		close(fd[1]); // we don't write to it, so we close that
		int y;
		if (read(fd[0], &y, sizeof(int)) == -1)
		{
			printf("could not read\n");
			return 3;
		}
		close(fd[0]);
		printf("num got from child is: %d\n", y);
	}

	/* fork() satırından sonra parent'ın mı child'ın mı önce execute'a başlayacağı
	OS'a göre değişir. ama kodun çalışmasını garantileyen şey şudur: mesela parent daha
	hızlı çalıştı. 43. satırda okuma yapmaya çalışacak read() fonksiyonundan ama eğer arka
	planda senkronize giden child henüz yazma işlemi yapmamışsa yapana kadar bekletilir bu okuma
	işlemi. yazdığı anda okuma yapılır. bu bloklama işlemi otomatik yapılır ve wait() işlemine
	gerek duyulmaz.  */

	return 0;
}
