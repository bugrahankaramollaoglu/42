/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:38:50 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/21 00:33:32 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			counter;
	char			*sub;

	i = 0;
	counter = 0;
	sub = malloc(len + 1);
	if (!sub)
		return (0);
	if (!s)
		return (0);
	while (i < start)
		i++;
	while (counter < len)
	{
		sub[counter] = s[i];
		i++;
		counter++;
	}
	sub[counter] = '\0';
	return (sub);
}
