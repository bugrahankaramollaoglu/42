/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff_first_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:55:11 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/12 16:55:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    // en az 1 argüman girilmişse
    if (ac >= 2)
    {
        int i = 0;
        // ilk argümanı (av[1]) null görene kadar yazdırıyoruz
        while (av[1][i])
        {
            write(1, &av[1][i], 1);
            i++;
        }
    }
    // argüman sayısı 2 olsa da olmasa da sonuna \n koyuyoruz
    write(1, "\n", 1);
    return 0;
}
