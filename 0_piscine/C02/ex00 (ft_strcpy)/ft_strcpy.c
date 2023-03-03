/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:31:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/03 19:31:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* src'den dest stringine kopyalar */

#include <stdio.h>
#include <unistd.h>

/* birinci yol
char	*ft_strcpy(char *dest, char *src)
{
	int i; // sataç

	i = 0;
	while (src[i]) // while src[i] != '\0' yani src bitene kadar
	{
		dest[i] = src[i]; // kopyalama işlemi
		i++;
	}
	dest[i] = '\0'; // sonuna da null koy
	return (dest);  // finalde de döndür
} */

/* ikinci yol (pointerlarla)
char	*ft_strcpy(char *dest, char *src)
{
	char *p = dest;
	while (*src != '\0')
	{
		*p++ = *src++;
	}
	*p = '\0';
	return (dest);
}

burada dest'i gösteren bir başka pointer yaratıyoruz ve onun tuttugu
adrese kopyalama işlemini yapiyoruz. dolayısıyla ona yazdırılan her byte
adres dest'in adresi oldugu icin dest'in kendisine (adresine) yazdırılmış oluyor.
aşağıdaki gibi direkt dest'in kendisi üzerinde işlem yapamiyoruz

while (*src != '\0')
{
	*dest++ = *src++;
}

çünkü biz ancak bir pointerın gösterdiği adresteki değeri
modifiye edebiliriz, adresin kendisini değiştiremeyiz. öyle deseydik
dest'in gösterdiği hafıza blogunu degistirmeye calısırdık, bu da undefined
behaviour'a sebep olur. char *p sayesinde orijinal dest'i değiştirmeden kopyası
üzerinden işlem yapabiliyoruz böylece destin adresi değil adresteki değerle oynuyoruz. */

/* üçüncü yol
char *ft_strcpy(char *dest, const char *src)
{
	char *p = dest;
	while (*p++ = *src++)
		;
	return dest;
} */

#include <stdlib.h>

int main(void)
{
	char *s = "bugra";
	char d[5];
	printf("%s", ft_strcpy(d, s));
}
