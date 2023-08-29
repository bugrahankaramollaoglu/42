/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:04:59 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:22:19 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int innuendo;
	innuendo = *a;
	*a = *b;
	*b = innuendo;
}

void ft_sort_int_tab(int *tab, int size)
{
	int swap;
	int a;

	a = 0;
	while (a < size - 1)
	{
		if (tab[a] > tab[a + 1])
		{
			ft_swap(&tab[a], &tab[a + 1]);
			a = 0;
		}
		else
			a++;
	}
}

int main()
{
	int tab[4] = {2323, 39, 23, 38};
	ft_sort_int_tab(tab, 4);
	for (int i = 0; i < 4; i++)
	{
		printf("[%d]", tab[i]);
	}
}
