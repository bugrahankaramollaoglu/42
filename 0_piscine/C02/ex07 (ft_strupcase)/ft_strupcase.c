/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:49:21 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 14:46:51 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* küçük harfleri büyüğe çevir
buGRakaRA --> BUGRAKARA
 */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if ((str[a] >= 'a') && (str[a] <= 'z'))
		{
			/* ascii tablosunda küçük harf ile büyük harf arasında 32 fark oldugu icin kücügü büyütmek icin
			32 çıkarıyoruz (97->a && 65->A). aynı şekilde büyük bir harfi küçük harfe çevirmek için de 32 ekleyecektik */
			str[a] -= 32;
		}
		a++;
	}
	return (str);
}
