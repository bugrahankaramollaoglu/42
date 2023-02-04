/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 17:02:04 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/25 12:25:06 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* memcpy vs. memmove farkı:
    o memcpy: directly copies from one place to another
    o memmove: overlap olmasın diye aynı hafıza alanındaysa starts the copying from the end of the string.
*/

// src'den dest'e n kadar hafıza alanında kopyalıyor

void *ft_memmove(void *dest, const void *src, size_t n)
{
    // sayacımız
    unsigned int i;

    i = 0;

    // eğer 2si de boşsa null döndür
    if (!dest && !src)
        return (NULL);

    // burada da diyor ki eğer dest'in başlangıcı src'nin başlangıcından
    // sağdaysa kopyalarken sıkıntı çıkar, o yüzden sondan başla kopyalamaya
    if (dest > src)
    {
        // n kadar
        while (n > 0)
        {
            // sondan başlayarak kopyalama işlemi yap ki eleman kaybolmasın
            ((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
            n--;
        }
    }
    // eğer değilse
    else
    {
        while (i < n)
        {
            // baştan başlayarak kopyala
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    return (dest);
}

/* yani dst'in asciileri 47 48 49 50 olsun
src'nin asciileri de  85 86 87 88 olsun
else satırına girer ve dst'i sırasıyla 85-88 yapar
sonra da yazdırır ve src ile aynı hale gelir */

/* int	main()
{
    unsigned char	dst[] = "abcdefg";
    unsigned char	src[] = "1234567";
    printf("-----with memmove-------\n");
    printf("old src is: %s\n", src);
    printf("old dest is: %s\n", dst);
    ft_memmove(dst, dst + 2, 7);
    printf("-----Now-----");
    printf("\nnew src is: %s\n", src);
    printf("new dest is: %s\n", dst);
} */

/* // aynı hafıza alanında iş yapılırsa
int	main()
{
    char	a[] = "abcd";
    printf("-----with memmove-------\n");
    printf("old a is: %s\n", a);
    ft_memmove(a, a+2, 4);
    printf("-----Now-----");
    printf("\nnew a is: %s\n", a);
}  // cd verir yani c d \0 \0

// dst > src olsun istiyosan move(a+2, a, x) yazman gerekir yani soldaki */

/* int	main()
{
    char	a[] = "abcd";
    printf("-----with memmove-------\n");
    printf("old a is: %s\n", a);
    ft_memmove(a+2, a, 4);
    printf("-----Now-----");
    printf("\nnew a is: %s\n", a);
}  // ababcd verir yani a b a b c sondaki d fazladan */
