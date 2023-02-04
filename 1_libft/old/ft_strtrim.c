/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:35:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/26 23:24:03 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// başından ve sonundan *set'in içindeki karakterlere denk gelirse
// sıralama önemli olmaksızın siler. "abc" dersen set'in baş/sondaki 
// bütün abc varyasyonları (bca, cb, c, a, b, cab vs.) siler

// varyasyonları da dahil edebilmek için *set'in karakterlerine
// denk gelirse 1 döndüren bir fonksiyon yazıyoruz.
static int ft_char_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// s1 içinde set'teki karakterleri arayıp silen fonksiyon
char    *ft_strtrim(char const *s1, const char *set)
{
    // trimlenmiş metni buna atacağız
	char    *mystr;

    // başından başlamak için kullandıgımız counter
	size_t	start;

    // sonundan başlamak için kullandığımız counter
	size_t	end;

    // en son mystr'e atarken set[] harici elemanlar için bunu kullanacağız
	size_t	i;

	start = 0;

    // s1'in başından itibaren her bir indis set char dizisinin içinde
    // var mı yok mu diye tarar, varsa start'ı 1 arttırır ki set'telerse atlansınlar
    // ve yazılmasınlar (silinmiş gibi oluyor)
	while (s1[start] && ft_char_in_set(set, s1[start]))
		start++;

    // sondan başlayabilmek için s1'in uzunluğunu buluyoruz
	end = ft_strlen(s1);

    // end>start: baştan itibaren trimlenmiş halin son indeksi start idi
    // en fazla oraya kadar gitsin, ötesine (sola doğru) gitmesin diye bu 
    // koşulu koşuyoruz. 2. koşulumuz da (null'u saymasın diye -1 çıkardık)
    // sondan itibaren eğer ft_char_in_set fonksiyonu bir döndürüyorsa 
    // *s1[indeks]'teki değer set'e dahilse, end-- ile bir sola kaydır indeksi, ki sağ 
    // taraftan trimlenecek şeyler de silinmiş olsun
	while (end > start && ft_char_in_set(set, s1[end - 1]))
		end--;

    // daha sonra hafızada yer ayırıyoruz mystr + '\0' gerektirecek kadar
	mystr = (char*)malloc(sizeof(*s1) * (end - start + 1));

    // eğer mystr boşsa null döndür
	if (!mystr)
		return (NULL);

	i = 0;
	
    // start 5 idi (baştaki xyxyy). end de 13 çünkü ft_strlen(s1) - 3 çünkü sondaki xyz den dolayı 11di.
    // 5 < 10 yani 5 karakter yazılacak o da tam olarak BUGRA'ya yetiyor.
    while (start < end)
		mystr[i++] = s1[start++];

    // finalde de sonuna null atıyoruz
	mystr[i] = '\0';

    // ve döndürüyoruz
	return (mystr);
}

/* int main() {
    char x[] ="xyxyyBUGRAxz";
    printf("%s\n", ft_strtrim(x, "xyz"));
} */