/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:42:31 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/20 18:40:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// strmapi ve striteri aynı şeyi yapar. ikisi de s stringini f fonksiyonuna tabi tutar.
// fakat aralarındaki fark strmapi sonucu yeni bir stringe atıp onu döndürürken
// striteri direkt o string üzerinde işlem yapar. 

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    // index sayacı
	unsigned int	i;

    // sonucun atılacağı temp string
	char			*str;

	i = 0;

    // malloc ile char pointer türünde strlen + 1 (null) kadar yer ayır
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	
    // str boşsa null döndür
    if (!str)
		return (NULL);

    // s'nin sonuna gelene kadar
	while (s[i])
	{
        // i. indeksi (0, 1, 2...) f'ye tabi tut
		str[i] = f(i, s[i]);
		i++;
	}

    // sonuna null ekle
	str[i] = '\0';
	return (str);
}

/* // burada deneme bir fonksiyon yazdık. bu (f*) fonksiyonunun yerine gelecek
// kendin de yazabilirsin çekedebilirsin fonksiyonu
char f(){
	xxx;
	yyy;
	return (zzz);
}

// asd fonksiyonunu, s'ye uygula
int main() {
    char    s[] = "melih";
    printf("%s\n", ft_strmapi(s, f));
} */