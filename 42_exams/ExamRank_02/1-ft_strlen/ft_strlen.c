/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:01:12 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/21 18:23:03 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// bu en klasik hali
/* int ft_strlen(char *str)
{
    int x = 0;
    while (str[x])
        x++;
    return x;
}
 */
// ben şöyle yazdım
int ft_strlen(char *s)
{
    int i;
    for (i = 0; *s; i++, s++)
        ;
    return i;
}

int main()
{
    printf("%d", ft_strlen("asd"));
}
