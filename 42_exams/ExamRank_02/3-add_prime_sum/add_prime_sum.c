/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:23:30 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/07 16:08:45 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int is_prime(int nb)
{
    int i = 2;
    if (nb == 0 || nb == 1)
        return 0;
    while (i <= nb/2)
    {
        if (nb % i == 0)
            return 0;
        i++;
    }
    return 1;
}

void ft_putnbr(int nb)
{
    char a;
    if (nb < 10)
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

int ft_atoi(char *s)
{
    int i = 0;
    int result = 0;
    while (s[i] >= '0' && s[i] <= '9')
    {
        result = (s[i] - '0') + (result * 10);
        i++;
    }
    return result;
}

int main(int ac, char **av)
{
    int nb = ft_atoi(av[1]);
    (void)ac;
    int i = 2;
    int sum = 0;
    while (i <= nb)
    {
        if (is_prime(i))
            sum += i;
        i++;
    }
    ft_putnbr(sum);
    write(1, "\n", 1);
    return 0;
}
