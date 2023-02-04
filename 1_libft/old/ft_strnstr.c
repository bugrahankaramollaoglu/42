/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:41:19 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 09:28:51 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// haystack içinde ilk n karakterde needle arıyor, bulursa needle dahil kalanı döndürüyor
char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int	i;

	// eğer needle boşsa haystack tamamını döndür
	if (!*needle)
		return ((char *)haystack);

	// eğer haystack bitmemişse, n de nao
	// eedle'dan uzunsa
	while (*haystack && n-- >= ft_strlen(needle))
	{
		i = 0;
		// haystack'in i. indisi (ilkin 0) needle'ın i. indisine eşit değilse
		// bu while'a girmez alttaki haystack ile haystack'i 1 arttırır.
		// bu sefer haystack'in 1. indisini kontrol eder böyle böyle
		// eşit oldukları ilk harfe gelince while'a girer
		// ve sonuna da gelmmemişse kalanını döndürür
		while (needle[i] == haystack[i])
		{
			// i'yi bir arttır
			i++;
			// 
			if (!needle[i])
				// haystack + i demiyoruz çünkü haystack'i zaten arttırdık i'lik kadar
				return ((char *)(haystack));
		}
		haystack++;
	}
	return (NULL);
}

/* int main() {
	char a[] = "bugrahan";
	char needle[] = "grahb";

	printf("%s\n", ft_strnstr(a, needle, 6));
} */
