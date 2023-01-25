/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:22:59 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/08 17:45:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_atoi(char *str)
{
    int n = 0;

    while (*str)
    {
        n *= 10;
        n += *str - '0';
        ++str;
    }
    return (n);
}

void print_hex(int n)
{
    char hex_digits[] = "0123456789abcdef";
    if (n >= 16)
        print_hex(n / 16);
    write(1, &hex_digits[n % 16], 1);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nbr = ft_atoi(av[1]);
        print_hex(nbr);
    }
    write(1, "\n", 1);
}
