/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:59:05 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/14 01:46:19 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	space;
	int				mal;
	unsigned int	i;

	i = 0;
	if (!s || (start > ft_strlen(s)))
		return (ft_strdup(""));
	if (ft_strlen(s) - start >= len)
		mal = len;
	else
		mal = ft_strlen(s) - start;
	substring = malloc(sizeof(char) * mal + 1);
	if (!substring)
		return (NULL);
	space = start + len;
	while (s[start] && start < space)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
