/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:11:07 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 16:10:16 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb)
{
    char t;
    if (nb <= 9)
    {
        t = nb - '0';
        write(1, &t, 1);
    }
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

int ft_atoi(char *str)
{
    int result = 0;
    int i = 0;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = (str[i] - '0') + (result * 10);
        i++;
    }
    return result;
}



