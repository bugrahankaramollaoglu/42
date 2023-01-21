/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:16:33 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 14:34:10 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* src'den dest stringine kopyalar */

#include <unistd.h>
#include <stdio.h>

char *ft_strcpy(char *dest, char *src)
{
    // sayacımız
    int i;

    i = 0;

    // while src[i] != '\0' yani src bitene kadar
    while (src[i])
    {
        // kopyalama işlemi
        dest[i] = src[i];
        i++;
    }
    // sonuna da null koy
    dest[i] = '\0';

    // finalde de döndür
    return (dest);
}

int main()
{
    char *s = "bugra";
    char *d = "a";
    printf("%s", ft_strcpy(d, s));
}