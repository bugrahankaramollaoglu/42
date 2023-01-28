/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 20:48:58 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:23:22 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	res_a;
	int	rem_b;

	if (*b != 0)
	{
		res_a = (*a) / (*b);
		rem_b = (*a) % (*b);
		*a = res_a;
		*b = rem_b;
	}
}
