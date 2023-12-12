/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:16:49 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/16 20:02:13 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// alpha_mirror'a dahil hatırlaman gereken şey 219 ve 155 sayıları. a-z aralığında 219'dan çıkarıyosun
// indisi, A-Z aralığında da 155'ten. sonra da yazdırıyosun.

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int i = 0;
        while (av[1][i])
        {
            if (av[1][i] >= 'a' && av[1][i] <= 'z')
              w  // comes from av[1][i] = 122 - av[1][i] + 97
                av[1][i] = 219 - av[1][i];
            if (av[1][i] >= 'A' && av[1][i] <= 'Z')
                // comes from av[1][i] = 90 - av[1][i] + 65
                av[1][i] = 155 - av[1][i];
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
