/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:18:25 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:40:27 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// n kadar karakteri s1 ve s2'de karşılaştırır, fark varsa ascii farkını döndürür

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    // eğer 0 karakter karşılaştır demişse null döndür
    if (n == 0)
        return (0);
    // 1) s1 bitene kadar
    // 2) s1 ve s2 aynı olduğu sürece
    // 3) i (sayaç) n'ye gelene kadar (-1 bc of the NULL character)
    // bir arttırıyoruz
    while (s1[i] && s1[i] == s2[i] && i < n - 1)
        i++;
    // böyle olmadığı ilk durum farkılaştıkları durumdur orada da farklarını
    // daha doğrusu ascii farklarını döndürüyoruz
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/* int main() {
    char a[] = "bugra";
    char b[] = "bugrz";
    printf("%d\n", ft_strncmp(a, b, 4));
    printf("%d\n", ft_strncmp(a, b, 5));
}
 */

/* bir baska cozum
int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    while (n--)
    {
        if (*s1 != *s2)
            return *(unsigned char *)s1 < *(unsigned char *)s2 ? -1 : 1;
        if (*s1 == '\0')
            return 0;
        s1++;
        s2++;
    }
    return 0;
} */