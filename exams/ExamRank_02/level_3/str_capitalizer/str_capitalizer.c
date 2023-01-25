/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_capitalizer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 00:12:17 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/08 17:19:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void str_capitalizer(char *str)
{
    int i = 0;
    if (str[i] >= 'a' && str[i] <= 'z')
        str[i] -= 32;
    write(1, &str[i], 1);
    while (str[++i])
    {
        if (str[i] >= 'A' && 'Z' >= str[i])
            str[i] += 32;
        if ((str[i] >= 'a' && str[i] <= 'z') && (str[i - 1] == ' ' || str[i - 1] == '\t'))
            str[i] -= 32;
        write(1, &str[i], 1);
    }
}

int main(int argc, char *argv[])
{
    int i = 1;

    if (argc < 2)
        write(1, "\n", 1);
    else
    {
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
}
