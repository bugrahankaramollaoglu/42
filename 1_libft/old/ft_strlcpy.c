/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:18:41 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:37:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies up to dstsize - 1 characters from the string src to dst, NUL-
// terminating the result if dstsize is not 0.
// destSize burada destination'ın alabileceği maksimum uzunluk

size_t ft_strlcpy(char *dest, const char *src, size_t destSize)
{
    size_t index;
    size_t counter;

    index = 0;
    counter = 0;

    // counter'ı src'nin uzunluguna eşitlioyr
    while (src[counter])
        counter++;

    // destSize boş değilse
    if (destSize)
    {
        // burada -1 deme sebebimiz sonuna manuel koyacağımız null için yer ayırmak ki kesin olsun
        // strcpy'den farkı da tam olarak bu
        while (src[index] && index < destSize - 1)
        {
            // kopyalama işlemini yap
            dest[index] = src[index];
            index++;
        }
        dest[index] = '\0';
    }

    // dönüt olarak counter istiyor niye idk
    return (counter);
}

/* int main()
{
    char d[] = "";
    char s[] = "karamol";
    printf("d is: %s\n", d);
    printf("s is: %s\n", s);
    ft_strlcpy(d, s, 10);
    printf("d is %s\n", d);
    printf("s is: %s", s);

    return 0;
}
 */