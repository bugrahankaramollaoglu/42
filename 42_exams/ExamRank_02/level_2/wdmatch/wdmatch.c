/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 01:03:32 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/07 00:36:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

// %100 kendi kodum
int main(int ac, char **av)
{ // "BUGRA" "aaaaBaaaaUaaaGRaaaaAaaa"
    if (ac == 3)
    {
        int len_w = 0;
        while (av[1][len_w])
            len_w++;
        int counter = 0;
        int i = 0;
        int k = 0;
        while (av[1][i])
        {
            while (av[2][k])
            {
                if (av[1][i] == av[2][k])
                {
                    counter++;
                    i++;
                }
                k++;
            }
            i++;
        }
        if (counter == len_w)
            printf("%s", av[1]);
        else
        {
            printf("\n");
            return 0;
        }
    }
    printf("\n");
    return 0;
}
