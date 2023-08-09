/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 11:41:42 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/24 14:17:45 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/* str char stringi içerisinde ("bugrahankara") to_find stringini ("rah") arıyor.
bulamazsa 0, bulursa buldugu adresten kalanını gönderiyor (rahankara) */
char *ft_strstr(char *str, char *to_find)
{
	int a;
	int b;

	a = 0;
	b = 0;
	/* eğer aranacak şey nullsa direkt stringin tamamını gönder */
	if (to_find[b] == '\0')
		return (str);
	/* string bitene kadar */
	while (str[a] != '\0')
	{
		/* stringi tararken şu an için ilk karakteriyle (a da b de 0 çünkü) b'nin ilk karakterini karşılaştırıyor
		eğer aynı ise, stringi de aşmadığı müddetçe b'yi 1 arttırıyor. bulunan aynı karakter sayısı to_find'ın uzunluguna eşitse
		to_find (rah) bulunmuş demektir. bunu da sonundaki null'a gelmesinden anlıyoruz. eğer değilse stringi ilerletip b'yi sıfırlıyoruz
		bu ne işe yarıyor? mesela "12342234456789" stringi içerisinde "344" ariyoruz. ilk yarıda 34 var fakat 344 değil, 342.
		dolayısıyla aradığımız string o değil, o yüzden hepsini buldugumuzdan emin olmak için uzunluk kontrolü yapiyoruz. */
		while (str[a + b] == to_find[b] && str[a + b] != '\0')
			b++;
		if (to_find[b] == '\0')
			return (str + a);
		a++;
		b = 0;
	}
	return (0);
}

int main()
{
	char *ss = "bugrahankarahankara";
	char *f = "j";
	printf("%s\n", ft_strstr(ss, f));
}
