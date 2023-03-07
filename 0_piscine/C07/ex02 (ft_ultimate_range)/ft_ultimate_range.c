/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 00:17:17 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/06 18:42:53 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *temp;

	if (min >= max)
		return (-1);
	/* böyle de yapabilirsin */
	if ((temp = malloc(sizeof(int) * (max - min))) == '\0')
		return (-1);
	i = 0;
	while (min++ < max)
		temp[i++] = min;
	*range = temp;
	return (i);
}
