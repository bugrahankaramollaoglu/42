/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:58:44 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/21 00:36:35 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	i2;

	new = malloc((sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!new)
		return (0);
	i = 0;
	i2 = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[i2])
	{
		new[i] = s2[i2];
		i++;
		i2++;
	}
	new[i] = '\0';
	return (new);
}
