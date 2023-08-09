/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:57:17 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:57:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		in;
	int		i2;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (NULL);
	in = 0;
	i2 = 0;
	while (s1[in])
		ptr[i2++] = s1[in++];
	in = 0;
	while (s2[in])
		ptr[i2++] = s2[in++];
	ptr[i2] = '\0';
	return (ptr);
}
