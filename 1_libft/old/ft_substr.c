/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugra <bugra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:25:08 by bugra             #+#    #+#             */
/*   Updated: 2022/10/29 17:25:08 by bugra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// str'nin start. indeksinden itibaren len kadar yazdıran fonksiyon
// ("bugrahan", 3, 4) --> raha
char *ft_substr(char const *s, unsigned int start, size_t len)
{
    // döndürülecek şey (raha)
    char *my_str;
    size_t counter;

    if (!s)
        return (NULL);
    // eğer len yazdırıbilecek maksimum şeyden büyüksa
    // yani 5 harfli bir kelimenin 2. harfinden itibaren 10 harf yazdır
    // gibi bir şey istenirse len'i yazılabilecek maksimum sayıya eşitle
    if (len > ft_strlen(s))
        len = ft_strlen(s);
    // eğer start s'den büyükse
    // mesela 3 harfli bir kelimenin 7. harfinden itibaren yazdır
    // gibi bir şey isteniyorsa "" döndür
    if (start >= ft_strlen(s))
        return (ft_strdup(""));
    my_str = (char *)malloc(sizeof(char) * len + 1);
    if (!my_str)
        return (NULL);
    counter = 0;
    while (len--)
        my_str[counter++] = s[start++];
    my_str[counter] = '\0';
    return (my_str);
}

/* #include <stdio.h>
int main()
{
    char x[] = "bugrahan";
    printf("%s", ft_substr(x, 3, 4));
} */
