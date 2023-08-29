/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:35:13 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/09 23:09:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i = 1;
    int j = 0;
    int flag = 0;
    if (ac > 1)
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                if (av[i][j + 1] == ' ' || av[i][j + 1] == '\0' || av[i][j + 1] == '\t')
                    flag = 1;
                if ((av[i][j] >= 'A' && av[i][j] <= 'Z') && flag != 1)
                {
                    av[i][j] += 32;
                    write(1, &av[i][j], 1);
                }
                else if ((av[i][j] >= 'a' && av[i][j] <= 'z') && flag == 1)
                {
                    av[i][j] -= 32;
                    write(1, &av[i][j], 1);
                }
                else
                    write(1, &av[i][j], 1);
                j++;
                flag = 0;
            }
            write(1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
}