/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 17:20:02 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:37:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// src'den dst'e destSize'ın bir eksiği kadar sonundan itibaren ekler
// strncat'ten farkı budur. bu -1 olayı null'a yer açmasını sağlar.
// burada destSize destination'a atanan maksimum kelime uzunlugu hakkı
// mesela normalde strleri birlestirince 6 kelimelik bir sonuç çıksın,
// eğer destSize olarak minimum 6 vermeyip 3 verirsen ilk iki harfini
// yazdırır sadece, 3. harf hakkını her zaman null'a saklar

size_t ft_strlcat(char *dst, const char *src, size_t destSize)
{
    size_t j;
    size_t k;

    j = 0;
    k = 0;

    // dest'in sonuna gelene kadar ve dest bitene kadar
    // j'yi arttırarak
    // j'yi dest'in uzunluguna eşitlemiş
    while (dst[j] && j < destSize)
        j++;

    // src'nin sonuna gelene kadar da dest'in sonundan itibaren (j + k),
    // src'yi dest'e ekliyor
    while ((src[k]) && ((j + k + 1) < destSize))
    {
        dst[j + k] = src[k];
        k++;
    }

    // finalde null ekleme
    if (j != destSize)
        dst[j + k] = '\0';

    // idkwb finalde birleştirilmiş stringi değil
    // uzunluklarını döndürüyor
    return (j + ft_strlen(src));
}

/* int main()
{
    char dst[] = "ne";
    char src[] = "niye";
    printf("%zu", ft_strlcat(dst, src, 10));
    printf("\n%s", dst);
    printf("\n%s\n", src);
    return 0;
}
 */