/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:26:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/21 00:34:02 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && n-- >= ft_strlen(needle))
	{
		i = 0;
		while (needle[i] == haystack[i])
		{
			i++;
			if (!needle[i])
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}
