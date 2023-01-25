/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:00:06 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/25 14:46:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
    // bunun 128 olma sebebi 128in 8 kere 2ye bölünebilir olması
    // 128-64-32-16-8-4-2-1 böylece 8 kere 0 ya da 1 yaziyor
    int i = 128;
    while (i)
    {
        if (octet >= i)
        {
            write(1, "1", 1);
            octet %= i;
            i /= 2;
        }
        else
        {
            write(1, "0", 1);
            i /= 2;
        }
    }
}

/*
    mesela 53 sayısını bit olarak yazdıralım.
    128 bitene kadar (0 olana kadar)
        - 53, 128'den büyük olmadıgı icin else girdi ve 0 yazdı i 64 oldu
        - 63'ten de büyük olmadıgı icin else girdi ve 0 yazdı i 32 oldu
        - 32'den büyük oldugu icin if girdi 1 yazdı, octet 21 oldu i 26 oldu
        - 21 26'dan büyük olmadıgı icin else girdi 0 yazdı i 13 oldu
        - 21 13'ten büyük oldugu icin if girdi, 1 yazdı, octet 8, i 6 oldu
        - 8 6'dan büyük oldugu icin if girdi, 1 yazdı, octet 2, i 3 oldu
        - 2 3'ten büyük olmadıgı icin else girdi, 0 yazdı, i 1 oldu
        - 2 1'den büyük oldugu icin en son if girdi, 1 yazdı, octet 1, i 0 oldu
        - i 0 oldugu icin döngüden cıkıldı ve 0010 1101 yazdırıldı
*/
/* 
int main()
{
    print_bits(93);
}


#include <unistd.h>

void print_bits(unsigned char octet)
{
	int	i;
	unsigned char bit;

	i = 8;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
} */

int main(void)
{
	print_bits(0);
	write(1, "\n", 1);
	print_bits(1);
	write(1, "\n", 1);
	print_bits(2);
	write(1, "\n", 1);
	print_bits(10);
	write(1, "\n", 1);
	print_bits(113);
	write(1, "\n", 1);
	print_bits(255);
	write(1, "\n", 1);
	return (0);
}
