/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 23:40:42 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/02 22:22:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, char const *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size && src)
	{
		while (src[i] != '\0' && size > 1)
		{
			dest[i] = src[i];
			size--;
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}
