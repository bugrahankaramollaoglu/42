/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:50:06 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/08 14:50:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// kendi kodum. %100 calisiyor ama sinavda gecmedi

#include <unistd.h>

void epur(char *str)
{
    int i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t')
            write(1, &str[i], 1);
        else if (str[i + 1] > 32 && str[i + 1] != '\0')
            write(1, " ", 1);
        i++;
    }
}

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
    if (ac >= 2)
    {
        int i = 0;
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i] != ' ' && av[1][i] != '\t')
            i++;
        if (is_word(av[i] + i) == 1)
        {
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            epur(av[1] + i);
            write(1, " ", 1);
            i = 0;
            while (av[1][i] == ' ' || av[1][i] == '\t')
                i++;
            while (av[1][i] != ' ' && av[1][i] != '\t')
            {
                write(1, &av[1][i], 1);
                i++;
            }
        }
        else
        {
            int j = 0;
            while (av[1][j] == ' ' || av[1][j] == '\t')
                j++;
            while (av[1][j] != ' ' && av[1][j] != '\t')
            {
                write(1, &av[1][j], 1);
                j++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}