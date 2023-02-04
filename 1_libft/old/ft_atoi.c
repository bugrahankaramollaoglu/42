/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:57:33 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/13 19:57:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// string olarak verilen bir "142" sayisini int olan 142'ye çevirir

int ft_atoi(const char *str)
{
	// stringi tarayacak sayaç
	int count;

	// nihai işaret
	int sign;

	// inte çevrilmiş haliyle sayımız
	int result;

	count = 0;

	// 0 olursa işaretsiz olur o yüzden 1 diyoruz
	sign = 1;

	result = 0;

	// stringde boşluklara gelirse atlasın
	while (str[count] == ' ' && (str[count] >= 9 && str[count] <= 13))
		count++;

	// + ya da - gördüğünde buna girsin
	if (str[count] == '+' || str[count] == '-')
	{
		// ve eksiyse sign değişkenini -1'le çarpsın
		if (str[count] == '-')
			sign *= -1;
		// -yse de +ysa da indisi 1 arttırsın
		count++;
	}

	// sayı olduğu zaman da buna girsin
	while (str[count] >= '0' && str[count] <= '9')
	{
		// char'ı int'e çevirmek için 48 çıkarıyoruz
		// ve sayıyı basamak basamak yazdırabilmek için de her seferinde
		// 10 ile çarpıyoruz
		result = (str[count] - '0') + (result * 10);
		count++;
	}

	// finalde de ikisini çarpıp p ya da n halini döndürüyoruz
	return (result * sign);
}

/* int main(void)
{
	char a[] = "-3520";
	printf("%d\n", ft_atoi(a));
}
 */