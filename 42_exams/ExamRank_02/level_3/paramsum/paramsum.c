/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paramsum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:37:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 11:29:46 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
    int nb = ac - 1;
    ft_putnbr(nb);
    write(1, "\n", 1);
    return 0;
}