/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:30:09 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:21:36 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* it reverses the order of a given array */
#include <stdio.h>
#include <unistd.h>

/* temp array kullandigim baska bir algoritmam
#include <stdio.h>

void ft_rev_int_tab(int *arr, int size) {
	int i = 0;
	int a = 0;
	int *new_arr[5];
	int size2 = size;
	size--;
	while (size2) {
		new_arr[a] = arr[size];
		a++;
		size--;
		size2--;
	}

	for (int x = 0; i < a; i++) {
		printf("[%d]", new_arr[i]);
	}
}

int main() {
	int tab[] = {3, 7, 8, 15, 30};
	ft_rev_int_tab(tab, 5);
}
*/

void ft_rev_int_tab(int *tab, int size)
{
	int i;
	int temp;

	i = -1;
	while (++i < size--)
	{
		temp = tab[i];
		tab[i] = tab[size];
		tab[size] = temp;
	}
}

int main()
{
	int tab[] = {1, 2, 3, 4, 5};
	ft_rev_int_tab(tab, 5);
	for (int i = 0; i < 5; i++)
		printf("[%d]", tab[i]);
}
