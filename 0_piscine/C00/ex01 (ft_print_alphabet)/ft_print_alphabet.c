/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2022/02/12 17:56:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/14 13:13:28 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char alpha;

	alpha = 96;
	while (++alpha <= 'z')
		write(1, &alpha, 1);
}

/* ek bilgi
	normalde i 0 iken printf(i++) 0 yazdırır,
	a'nın değeri daha sonra arttırılır.
	printf(++i) kullanırsak da önce arttılır sonra
	1 yazdırılır. ama while'da bu metot çalışmıyor.
	sebebi ise ++i de i++ while'ın koşul satırı bittikten
	sonra işleme sokulmasıdır. mesela
		int i = 0;
		while (i++ < 10)
			printf("%d ", i);
	ifadesi 1 2 3 4 5 6 7 8 9 10 yazdırır. mantıken postfix
	oldugu icin 0'dan baslaması gerekir gibi düsünüyoruz ama
	olmuyor. i++ yerine ++i deseydik 1 - 9 arası yazdırırdı.
	sebebi ise i < 10 ifadesi arttırmadan önce kontrol etmesidir. */
