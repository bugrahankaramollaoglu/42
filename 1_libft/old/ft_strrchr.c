/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugra <bugra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:23:46 by bugra             #+#    #+#             */
/*   Updated: 2022/10/29 17:23:46 by bugra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strrchr() sondan itibaren s içinde bir karakter arar
// bulursa o karakterden stringin sonuna kadar yazdırır
// mesela aykarakan diye bi isim farz edelim, 'k' verirsen kan yazdırır
// strchr() olsa karakan yazdırırdı çünkü o baştan itibaren bulduğu ilk  
// c'den sonrasını yazdırıyor.

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);

	// kelime bitene kadar sondan başa arıyoruz
	while (i >= 0)
	{
		// eğer aranan karakter ise alttaki kodla sonuna kadar döndürüyoruz
		if (s[i] == (char)c)
			return ((char *)s + i);
		// değilse buna giriyor ve 1 azaltarak en sola kadar gidiyor
		i--;
	}
	return (0);
}

/* int main() {
	char a[] = "cemreBugra";
	printf("%s", ft_strrchr(a, 'e'));
}
 */