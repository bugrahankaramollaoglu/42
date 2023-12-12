/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:51:33 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/22 15:32:55 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int max(int *tab, unsigned int len)
{
    int i = 1;
    int greatest = tab[0];
    while (len)
    {
        if (tab[i] > greatest)
            greatest = tab[i];
        len--;
        i++;
    }
    return greatest;
}

int main()
{
    int arr[] = {-100200, 29430, 30, 21, 2, 50, 13};
    printf("%d", max(arr, 7));
}