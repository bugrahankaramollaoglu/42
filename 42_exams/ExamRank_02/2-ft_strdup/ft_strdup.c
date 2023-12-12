/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:17:08 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 10:51:15 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdlib.h>

/* strdup 3 sey yapar
    1) bir buffer char* yaratıp ona yer ayırır
    2) parametreyi buffera kopyalar, sonuna null koyar
    3) bufferı döndürür
*/

char *ft_strdup(const char *src)
{
    char *new;
    int i;
    while (src[i])
        i++;
    new = (char *)malloc(sizeof(char) * i + 1);
    if (!new)
        return 0;
    i = 0;
    while (src[i])
    {
        new[i] = src[i];
        i++;
    }
    new[i] = '\0';
    return new;
}