/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:08:18 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/25 17:11:13 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int nb = atoi(av[1]);
        int i = 2;
        while (i <= nb)
        {
            if (nb % i == 0)
            {
                printf("%d", i);
                if (nb != i)
                    printf("*");
                nb /= i;
                i--;
            }
            i++;
        }
    }
    printf("\n");
    return 0;
}