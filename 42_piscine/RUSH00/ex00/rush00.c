/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessam-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 12:00:35 by yessam-s          #+#    #+#             */
/*   Updated: 2022/02/13 14:10:53 by yessam-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	rush(int x, int y)
{
	int	h;
	int	w;

	h = 1;
	while ((h <= y) && x > 0)
	{
		w = 1;
		while (w <= x)
		{
			if ((h == 1 || h == y) && (w == 1 || w == x))
				ft_putchar('o');
			else if ((h == 1 || h == y) && (w != 1 || w != x))
				ft_putchar('-');
			else if ((w == 1 || w == x) && (h != 1 || h != y))
				ft_putchar('|');
			else
				ft_putchar(' ');
			w++;
		}
		h++;
		ft_putchar('\n');
	}
}
