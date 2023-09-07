/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 22:51:04 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/07 14:08:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* wtf is minitalk

mesela client'tan server'a "bugra" mesajını atmak istiyosun.
bugra char stringinin hepsini tek seferde atıp yazdıramıyosun. harf
harf yazdırmak zorundasın, harfleri de bit bit yazdırmak zorundasın.
tek tek 8 seferde (bir char=8bit) atmalısın.
önce bugra'nın b'si gider. sonra b'nin 8bitinden 1.si (en soldaki bit) gider.
mesela b'nin binary karşılığı 10101101 olsun. bunu bit_and_shift() fonksiyonu
7 bit sağa kaydırır ve 00000001 olur. bunu & 1 ile işleme sokarsa buradan 1 gelir
buradan gelen 1 kill() fonksiyonuyla SIGUSR1'i 1 yapar.
o da signal catche bir yollar o da	bit_editing(void)'e 1 yollar
bit_editing de gelen binary'yi 7 bit sola kaydırarak önce 8. sonra 7. ...
en son da 1. yani en sol bitini int set'e atar. set 8'e tamamlanınca bit==0 olur
ve char halinde %c ile yazdırılır. sonra resetlenir bir sonraki harfin 8 biti için
aynı süreç tekrarlanır (toplamda harf*8 kadar).

*/

// bu fonksiyon birer birer bitler aliyor,
// bitlerin sayisi 8e tamamlandığında char olarak yazdiriyor
// bu bitler ft_signal_catch() fonksiyonundan geliyor
void ft_bit_editing(int x)
{
	static int bit;
	static int set;

	// stringin her harfini teker teker,
	// her harfin de 8 bitini teker teker işleyeceğiz
	// bunun için bit=7 tanımlıyoruz ki shift (kaydırma) işlemi yaptıgımızda
	// elimizde bir bit kalsın. burada bit 7tane 0 değil direkt 7 sayısıdır
	bit = 7;
	// stringin her harfi, bit işlemleri bittiği anda, set'e atılacak
	// ve yazdırılacak.
	set = 0;
	// set'e x'in 7, 6, 5 ... bit sola kaydırılmış halini atiyoruz.
	set += (x << bit);
	// eğer bit bitmişse harfin son biti de yazdirilmis demektir
	// bu durumda %c ile yazdırıyoruz charı ve bit/set sıfırlıyoruz ki
	// bir sonraki harfe geçsin
	if (bit == 0)
	{
		ft_printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void ft_signal_catch(int x)
{
	// SIGUSR1 (30 da diyebilirsin). 1 gelirse bit_editing()'e 1 gönderiyosun
	if (x == SIGUSR1)
		ft_bit_editing(1);
	// SIGUSR2 (31 de diyebilirsin). 0 gelirse bit_editing()'e 0 gönderiyosun
	else
		ft_bit_editing(0);
}

int main(void)
{
	int pid;

	// getpid() built-in fonksiyonuyla process ID alip pid'e atiyor
	pid = getpid();
	ft_printf("pid: %u\n", pid);
	/* 	signal() fonksiyonuyla SIGUSR1'den sinyal gelirse sağdaki (2. parametre) fonksiyona sokuyor
		burada string olarak gelen mesajı harf harf,
		harfleri de bit bit yazdıracagız. bitler 0 ve 1lerden
		oluştuğu için SIGUSR1'i 1,
		SIGUSR2'yi 0 olarak alacagız (tersi de olabilir, fark etmez). daha sonra
		harfin biti neyse (0 ya da 1) onu signal catche gönderecegiz o da  onu bit_editing'e yani bit olarak gelen 8adet
		veriyi bir tane harfe dönüştüren fonksiyonumuza atacak. */
	signal(SIGUSR1, ft_signal_catch);
	signal(SIGUSR2, ft_signal_catch);
	// sonsuz döngüye sokuyor sınırsız sayıda mesaj girmeye yarıyor
	// dolayısıyla yukarıdaki signal() fonksiyonları sürekli sinyal bekliyor
	while (1)
		pause();
}
