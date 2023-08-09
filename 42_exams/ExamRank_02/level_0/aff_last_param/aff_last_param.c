/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_last_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:55:25 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/12 16:55:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        int i = 0;
        // son argümanın indisi ac-1'dir (çünkü 0. argüman her zaman ./a.out)
        while (av[ac - 1][i])
        {
            write(1, &av[ac - 1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}
