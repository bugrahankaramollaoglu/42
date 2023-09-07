/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:17:23 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/17 01:05:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char *ft_strrev(char *str)
{
    char tmp;
    int i = 0;
    int len = 0;
    while (str[len])
        len++;
    len--;
    int a = len / 2;
    while (a)
    {
        tmp = str[i];
        str[i] = str[len];
        str[len] = tmp;
        len--;
        i++;
        a--;
    }
    return str;
}

#include <stdio.h>
int main()
{
    char abc[] = "bugrahan";
    printf("%s", ft_strrev(abc));
}
