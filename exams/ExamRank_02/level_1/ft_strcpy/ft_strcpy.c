/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:00:55 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/21 17:31:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// strcpy(char *dst, const char *src);
char *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    while (s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

int main()
{
    char s1[] = "bugra";
    // s1'e en az s2 uzunlugunda bir string vermelisin çünkü
    // en az s2 uzunlugunda yer ayrılmış olmalı s1'de
    char s2[] = "1234";
    ft_strcpy(s1, s2);
    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
}