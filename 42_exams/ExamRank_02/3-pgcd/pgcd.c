/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:46:31 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/11 13:19:49 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int ft_atoi(char *v)
{
    int i = 0;
    int result = 0;
    while (v[i])
    {
        if (v[i] >= '0' && v[i] <= '9')
        {
            result = (v[i] - '0') + (result * 10);
            i++;
        }
    }
    return result;
}

void ft_putnbr(int nb)
{
    char a;
    if (nb <= 9)
    {
        a = nb + '0';
        write(1, &a, 1);
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int nb1 = ft_atoi(av[1]);
        int nb2 = ft_atoi(av[2]);
        int greater=0;
        int smaller=0;
        if (nb1 < nb2)
        {
            smaller = nb1;
            greater = nb2;
        }
        else if (nb2 < nb1)
        {
            smaller = nb2;
            greater = nb1;
        }
        int smaller2 = smaller;
        while (smaller2)
        {
            if ((smaller % smaller2 == 0) && (greater % smaller2 == 0))
            {
                ft_putnbr(smaller2);
                write(1, "\n", 1);
                return 0;
            }
            smaller2--;
        }
    }
    write(1, "\n", 1);
    return 0;
}