/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:30:41 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/26 11:22:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int is_word(char *str)
{
    int i = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            return 1;
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if ((ac == 2) && is_word(av[1]) == 1)
    {
        int len = 0;
        int counter = 0;
        while (av[1][len])
            len++;
        len--;
        while (av[1][len] == ' ' || av[1][len] == '\t')
            len--;
        while (av[1][len] != ' ' && av[1][len] != '\t')
        {
            counter++;
            len--;
        }
        len++;
        while (counter)
        {
            write(1, &av[1][len], 1);
            counter--;
            len++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
