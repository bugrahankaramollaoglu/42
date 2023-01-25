/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:01:33 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/28 16:44:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// kaç kere yazdıracağını hesaplamanı sağlayan bir fonksiyon
int howMany(char a)
{
    int num = 0;
    if (a >= 'a' && a <= 'z')
        num = a - 96;
    else if (a >= 'A' && a <= 'Z')
        num = a - 64;
    return num;
} abc --> abbccc

int main(int ac, char **av)
{
    int i = 0;
    int nb;

    if (ac == 2)
    {
        while (av[1][i])
        {
            if ((av[1][i] >= 'a' && av[1][i] <= 'z') || (av[1][i] >= 'A' && av[1][i] <= 'Z'))
            {
                nb = howMany(av[1][i]);
                while (nb)
                {
                    write(1, &av[1][i], 1);
                    nb--;
                }
            }
            else
                write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
