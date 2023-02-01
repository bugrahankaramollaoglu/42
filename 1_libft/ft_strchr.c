/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:54:51 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/01 15:45:22 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s[0] == '\0')
		return (0);
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	else
	{
		while (*s)
		{
			if (*s == c)
				return ((char *)s);
			s++;
		}
		return (0);
	}
}

