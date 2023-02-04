/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:29:11 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/19 17:24:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// src'den dest'e n byte kadar hafıza alanında kopyalama yapar

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	// parametrede size_t verildiği için karşılaştırırken hata
	// almamak için bunu da size_t yapiyoruz
	size_t counter;

	// İşlem, fonksiyon içerisinde tanımlanan
	// ve adresleri src ve dest pointerlarının
	// adreslerine işaretlenmiş s ve d pointerları
	// üzerinden gerçekleştirilir.
	char *so;
	char *de;

	counter = 0;

	// önce char pointera çeviriyoruz yeni stringlerimizi
	de = (char *)dst;
	so = (char *)src;

	// eğer 2si de boşsa null döndür
	if (!dst && !src)
		return (NULL);

	// n kadar işlem yapıyoruz
	while (counter < n)
	{
		// kopyalama işlemini yap
		de[counter] = so[counter];
		counter++;
	}
	return (dst);
}

// direkt so'dan de'ye kopyalıyoruz
// fakat aynı hafıza alanında işlem yapıyosak işler karışıyor
// o zaman da sorun çıkmaması için memmove kullanıyoruz

/* int	main()
{
	unsigned char	dst[] = "abcd";
	unsigned char	src[] = "1234";
	printf("-----with memcpy-------\n");
	printf("old src is: %s\n", src);
	printf("old dest is: %s\n", dst);
	ft_memcpy(dst, src, 4);
	printf("-----Now-----");
	printf("\nnew src is: %s\n", src);
	printf("new dest is: %s\n", dst);
}  */

/* // aynı hafıza alanında iş yapılırsa
int main()
{
	char a[] = "abcd";
	printf("-----with memcpy-------\n");
	printf("old a is: %s\n", a);
	ft_memcpy(a, a+2, 4);
	printf("-----Now-----");
	printf("\nnew a is: %s\n", a);
}  // cd verir yani c d \0 \0 */

/* int    main()
{
	char    a[] = "abcd";
	printf("-----with memcpy-------\n");
	printf("old a is: %s\n", a);
	ft_memcpy(a+2, a, 4);
	printf("-----Now-----");
	printf("\nnew a is: %s\n", a);
} // ababab verir */
