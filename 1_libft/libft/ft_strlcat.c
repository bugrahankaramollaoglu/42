/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 23:47:29 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/03 00:03:59 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t destSize)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	while (dst[j] && j < destSize)
		j++;
	while (src[k] && ((j + k + 1) < destSize))
	{
		dst[j + k] = src[k];
		k++;
	}
	if (j != destSize)
		dst[j + k] = '\0';
	return (j + ft_strlen(src));
}
