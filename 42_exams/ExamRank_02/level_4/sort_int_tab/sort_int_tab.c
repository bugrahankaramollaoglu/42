/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 02:52:20 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/11 17:21:00 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// int arr[6] = {5, 1, 6, 6, 10, 40}
// int arr[6] = {1, 5, 6, 6, 10, 40}

void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int tmp;

    // eğer array boş değilse
    if (size > 0)
    {
        // arrayin eleman sayısı -1 kadar
        while (i < size - 1)
        {
            // eğer ilk eleman (şu an için) bir sonraki elemandan büyükse
            if (tab[i] > tab[i + 1])
            {
                // klasik swap işlemini tmp yardımıyla yapıyoruz, yerleri değişiyor
                tmp = tab[i];
                tab[i] = tab[i + 1];
                tab[i + 1] = tmp;
                // i'yi -1 yapıyoruz. nedeni indisi listenin başına atmak. -1. indis olayı kafa karıstırmamalı
                // çünkü bir sonraki döngüde if'e değil i++'ya girecek
                i = 0;
            }
            else
                i++;
            // böylece eğer küçükten büyüğe gidiyosa array (like we want) i++'ya giriyor. değilse if'e giriyor
        }
    }
}

#include <stdio.h>

int main(void)
{
    int a[6] = {9, 7, 6, 4, 5, -10};
    int i = 0;
    int size = 6;

    sort_int_tab(a, size);
    while (i < size)
        printf("[%d]", a[i++]);
    printf("\n");
    return (0);
}
