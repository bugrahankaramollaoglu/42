/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 11:20:54 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/21 00:40:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	ret_val;
	size_t	len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	ret_val = src_len + dest_len;
	len = size - dest_len - 1;
	i = 0;
	if (src && size)
	{
		while (len)
		{
			dest[dest_len++] = src[i++];
			len--;
		}
	}
	return (ret_val);
}
