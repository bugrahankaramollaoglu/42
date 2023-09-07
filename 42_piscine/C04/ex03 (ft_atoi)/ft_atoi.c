/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:00:47 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/26 15:43:14 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* atoi string olarak verilen bir sayıyı mesela "-2323" ya da "1250" int olan -2323
ve 1250 sayılarına çevirmede kullanılıyor.  */
int ft_atoi(char *str)
{
	int count;
	int sign;
	int result;

	/* bu sayacımız. "1250" sayısında 0-4. stringler arasını gezmekte kullanacağız */
	count = 0;
	/* bu işaret sayacımız. 1 ya da -1 olacak (sayı pozitifse/negatifse)
	bunu en son sayıya işaret verirken kullanacağız. */
	sign = 1;
	/* bu int olarak tutulacak sayı yani 1250 */
	result = 0;
	/* önce stringin başındaki boşluklardan kurtuluyoruz "    1250" gibi */
	while ((str[count] >= '\t' && str[count] <= '\r') || str[count] == ' ')
		count++;
	/* sonra stringin başındaki + veya - işaretlerini bakıyoruz */
	while (str[count] == '+' || str[count] == '-')
	{
		/* eğer sayıda tek sayıda - varsa sayı -'dir demektir (---124).
		çift sayıda varsa -'ler götürür + kalır. o yüzden her - gördüğümüzde işareti -1'le çarpacağız.
		indisi de bir arttırıyoruz ki işaretten kurtulup asıl sayıya gelsin. */
		if (str[count] == '-')
			sign *= -1;
		count++;
	}
	/* sonra stringindeki sayıları alıyoruz. */ //
	while (str[count] >= '0' && str[count] <= '9')
	{
		/* result şu an 0. öncelikle str'nin o anki indisinden (mesela 125'de ilk baştaki 1)
		-48 çıkartıyoruz ki char olan bu değer int haline dönüşsün (ki resultta biriktirebilelim).
		mesela "5" ifadesi 5 olsun. daha sonra buna result * 10 ekliyoruz ki result'ın önce 0 sonra 10 sonra 100
		ler basamagına taşınsın böylece 5'i birler basamağına 2'yi onlar 1'i yüzler basamağına koyabilelim. result şu an 0
		oldugundan bir şey eklemez. mesela 1'i inte çevirip resulta ekledi result 1 + (0*10)'dan 1 oldu. daha sonra geldik
		2'ye. 2'yi int'e çevirip resulta ekledi result 2 + (1*10)'den 12 oldu. daha sonra geldik 5'e. 5'i int'e çevirip
		resulta ekledi result 5 + (12*10)'den 125 oldu. */
		result = (str[count] - '0') + (result * 10);
		count++;
	}
	return (result * sign);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi("    ---234"));
}
