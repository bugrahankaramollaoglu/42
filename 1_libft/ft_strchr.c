/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:54:51 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/30 11:37:23 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s'yi c'den itibaren c dahil sonuna kadar yazdıran fonksiyon
char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;

	// s bitene kadar
	while (s[i])
	{
		// c'ye gelirsen c dahil stringin kalanını döndür
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}

	// 1) c boşsa
	// 2) s'nin sonuna gelinmişse
	// kalanını döndür
	if (!c && s[i] == '\0')
		return ((char *)s + i);
	// yoksa null döndür
	return (NULL);
}
