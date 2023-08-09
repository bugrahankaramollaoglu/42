/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:50:30 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/07 14:07:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// CLI'dan int alınamadıgı icin processID'yi ft_atoi() ile integer'a çeviriyoruz
int ft_atoi(char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result);
}

/* client'ı açtığımız terminalde yazdığımız mesajı ./server'da direkt char *string olarak yazdıramıyoruz
o yüzden her kelimenin her harfinin her bitini (8 bit her harfte) işleyip göndermemiz gerekiyor. o yüzden
mesela "ben bugra" mesajı için 9 char var 9*8 = 72 bitlik işlem yapiyoruz. yani bu fonksiyon 72 kere çağrılıyor
bu 8bitten bir biti alabilmek için bit kaydırma metodunu kullanıyoruz. yani 8bitin bitlerini almaya önce
en soldaki bitten başlayacağız. bunu da alabilmek için bitlerini önce 7 kere sonra 6 sonra 5... en son 1 sola
kaydırıyoruz. */
void ft_bit_and_shift(int pid, char *str)
{
	int i;
	unsigned char c;

	// bitleri kaydırırken kullanılacak indis
	// bitleri kaydırılacak harfi tutuyor
	// str bitene kadar
	while (*str)
	{
		// i'ye burada 8 veriyoruz. neden burada 8 de diğerinde 7'ydi?
		// çünkü 8 biti toplamda 7 kaydırma yapıyoruz. bir byte'ı 8 kaydırırsan 0 gelir (unsigned binary'de)
		i = 8;
		// burada *str'yi önce c'ye atıyoruz (mesela bugra diyelim,
		b'yi c charına atar)
			// sonra ++ ile stringin pointerı u'ya gider,
			yani artık ugra'yı gösterir. c = *str++;
			// bu işlemi 8 defa yapar fakat i'yi 7'den başlatır
			// post increment oldugu için.
			while (i--)
		{
			// önce c'yi (örnekte 'b') bit olarak i kadar (7 kadar) sağa öteler
			// mesela b == 10010101 olsun. bunu 7 sağa ötelersen
			// 00000001 olur. bunun 1 ile (yani 00000001) ile and'ini alırsan
			// 1 gelir (çünkü 1 & 1 = 1 verir)
			// 1 geldikten sonra sigusr1'e 1'i gönderir
			// her 8 bit toplandıgında onu
			// % c ile yazdırır(bir harfi) ve sayaçları sıfırlar
			// daha sonra i--'den ötürü i her seferinde 1 azalır böylece 7, 6,
			// 5 ... defa sola kaydırılır bit ki sırayla 8 bitin 8ini de alabilelim.
			if ((c >> i) & 1)
				// soldaki ifade 1 dönerse buna girip pid'e 1 gönderiyor
				kill(pid, SIGUSR1);
			else // dönmezse buna giriyor ve pid'e 0 gönderiyor
				kill(pid, SIGUSR2);
			// 100 ms bekliyor ki sinyaller karışmasın
			usleep(100);
		}
	}
}

int main(int ac, char **av)
{
	// argüman sayısı 3 değilse (./client pid_number "your_message" şeklinde girilmemişse)
	if (ac != 3)
	{
		ft_printf("wrong input. you must input 3 parameters");
		return (1);
	}
	// atoi ile sadece pid'i inte çeviriyor diğeri (string mesajın) char *str kalıyor
	ft_bit_and_shift(ft_atoi(av[1]), av[2]);
}
