/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:12:09 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 15:00:45 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* srcden deste n kadar kopyalar */

#include <unistd.h>
#include <stdio.h>

/* char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	a = 0;

	// en fazla n kadar
	// src'nin sonuna gelene kadar
	while ((a < n) && src[a])
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return dest;
} */

/* ikinci yol
char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	char *p = dest;
	int i = 0;
	while (*src && i++ < n)
	{
		*p++ = *src++;
	}
	return dest;
} */

int main()
{
	char d[] = "12345678";
	char s[] = "bugra";
	printf("d artık: %s\n", ft_strncpy(d, s, 5));
}

/* strncpy kullanırken negatif değer verirsek ortaya undefined behaviour çıkar
yani OS, architecture ve compiler'a bağlı olarak değişken sonuçlar da çıkabilir,
pozitif halindeki doğru sonuç da çıkabilir. unsigned int demek non-negatif demektir
yani 0 dahil 0+ tüm sayılar unsigned int'in aralığına girer (INT_MAX altındaysa tabi).
%u ile yazdırılır.  */

/* unsigned int tipinde bir değişkene - bir değer vermek undefine behaviour'a yol açar.
yani çalışabilir de çalışmayabilir de.

#include <stdio.h>

int main() {
	unsigned int num = -42;
	printf("The value of num is %u\n", num);
	return 0;
}

bu ifade random bi deger verir. aynı seyi %u yerine %d ile yapsaydın
-42 verecekti. */
