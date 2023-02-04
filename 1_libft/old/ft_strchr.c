/
* ************************************************************************** */
 /*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 02:17:21 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:36:59 by bkaramol         ###   ########.fr       */
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

/* #include <stdio.h>

int main() {
	char a[] = "bugrahankaramollaoglu";
	printf("%s", ft_strchr(a, 'm'));
} 
 */

