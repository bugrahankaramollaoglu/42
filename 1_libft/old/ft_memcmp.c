/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 04:36:25 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/18 19:37:52 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// s1 ve s2'nin ilk n karakterini karşılaştırıyor
// fark bulursa farkını döndürüyor

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	// 2 tane değişmez pointer tanımlıyoruz (hafızada işlem yaptığımızdan)
	const unsigned char	*s1ptr;
	const unsigned char	*s2ptr;

	// n ile karşılaştırma için sayacımız
	size_t	i;

	i = 0;
	s1ptr = (const unsigned char *) s1;
	s2ptr = (const unsigned char *) s2;
	
	// n kadar karşılaştırma yapacağız için i < n dedik
	while (i < n)
	{
		// indislerin eşit olmadığı ilk anda ascii farklarını döndür
		if (s1ptr[i] != s2ptr[i])
			return (s1ptr[i] - s2ptr[i]);
		// buna girmezse (aynıysa) bir arttırarak bir sonraki harfe geçer
		i++;
	}
	return (0);
}

/* int main() {
	char a[] = "bugra";
	char b[] = "bugrz";	

	printf("%d", ft_memcmp(a, b, 5));
} */

