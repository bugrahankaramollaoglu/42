/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:57:20 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:57:20 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_i;
	size_t	val;

	if (size == 0)
		return (ft_strlen(src));
	else if (size < ft_strlen(dest))
		val = ft_strlen(src) + size;
	else
		val = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (dest[i] != '\0')
		i++;
	s_i = 0;
	while (src[s_i] != '\0' && i + 1 < size)
	{
		dest[i] = src[s_i];
		s_i++;
		i++;
	}
	dest[i] = '\0';
	return (val);
}
