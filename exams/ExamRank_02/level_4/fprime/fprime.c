/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 03:18:43 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/25 15:04:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/* 28 --> 2*2*7 sayının asal çarpanlarını yazdırıyoruz */

int main(int ac, char **av)
{
    if (ac == 2)
    {
        // önce atoi ile sayıyı numa atıyoruz
        int num = atoi(av[1]);
        // min asal 2 oldugu icin 2'den baslatıyoruz
        int i = 2;

        // sayı birse 1 yazdırıp cıkıyoruz
        if (num == 1)
        {
            printf("1");
            return 0;
        }

        // sayi bitene kadar (sayi dahil çünkü kendisi de asal olabilir)
        while (i <= num)
        {
            // i sayının çarpanıysa
            if (num % i == 0)
            {
                // i'yi yazdiriyoruz
                printf("%d", i);
                // sayıdan sonra * koymasın diye bunu ekledik
                if (i != num)
                    printf("*");
                num /= i;
                i--;
            }
            i++;
        }
    }
    printf("\n");
    return 0;
}