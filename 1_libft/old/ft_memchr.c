/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 01:36:49 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/19 18:36:48 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// *s içinde arayacağımız string, c aranacak şey, n de s'de ilk kaç karakteri arayacağımız
// s'nin ilk n karakterinde c'yi bulursa devamını sonuna kadar yazdırır
// memchr("bugrahan", 'g', 3) --> grahan ama 2 deseydim b u 'da g olmadıgı icin null dönerdi

/* strchr stops when it hits a null character 
   but memchr does not; this is why the former 
   does not need a length parameter but the latter does. */

void *ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;

	// ilk n karakteri tarayacağımızdan bunu yazdık
	while (i < n)
	{
		// s'de c'ye denk geldiği anda
		if (((unsigned char *)s)[i] == (unsigned char)c)
			// s+i. pointer'ı return ediyor yani stringin c dahil tüm kalanını
			// s'ye  +i ekleyip s[0]'ın döngü boyunca
			// +1 +2 +3. (i++) halini almazsan her zaman stringin tamamını döndürür.
			// çünkü s'nin pointeri (*s) her zaman ilk karakterin kutucugunu isaret eder
			// oradan sonuna kadar yazdırır. + i dediğimizde ilk değil 3. 5. karaktere atıyor
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/* int main()
{
	char x[] = "bugrahan";
	printf("%s", ft_memchr(x, 'g', 6));
} */