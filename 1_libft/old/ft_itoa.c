/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 09:35:12 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/25 11:31:12 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int alan itoa str'ye çevirme işlemi yapar

// digit sayısını ölçüyor
// bir tane long alıyor
// static kullanma sebebimiz de digit'in verisini bir sonraki fonksiyonda tutabilmek
static long digit(long num)
{
    // sayaç olarak i tanımlıyor
    int i;

    i = 0;

    // num 0sa 1 digitlidir
    if (num == 0)
        return (1);

    // num 0dan küçükse sayaçı bir arttırıyoruz ki sağ basamağa geçsin
    // çünkü başındaki - de digit kabul ediliyor string hâlinde
    // yani bu digit() fonksiyonu -124 sayısı verildiğinde 4 döndürür
    if (num < 0)
    {
        i++;
        num = -num;
    }

    // burada da sayıyı bitene kadar 10a bölme formülüyle basamak sayısını öğreniyoruz
    // 123 -> 12 oluyor i=1
    // 12 -> 1 oluyor i=2
    // 1 -> 2 oluyor i = 3
    // sonrasında 10'a bölünemediği için çıkıyor
    while (num)
    {
        num /= 10;
        i++;
    }

    // finalde de digit sayısını döndürüyoruz
    return (i);
}

char *ft_itoa(int n)
{
    // sayının finalde döndüreceğimiz string hali
    char *mystr;
    // parametrenin basamak sayısı
    int a;
    // n ama int-long değişmiş hali
    // aşırı uzun bir int gelirse diye
    long nb;

    nb = n;

    // a basamak sayısını tutuyor
    a = digit(nb);

    // evvela yer ayırıyoruz (+1 for '\0')
    mystr = (char *)malloc(a + 1);

    // ayrılan yer boşsa direkt null döndür
    if (!mystr)
        return (NULL);

    // eğer negatifse artıya çevir ve başına - işareti ekle
    if (n < 0)
    {
        nb *= -1;
        mystr[0] = '-';
    }

    // sonuna null ekle
    mystr[a] = '\0';

    // 1 çıkarıyoruz ki null dahil edilmesin
    // bunu demezsek 343 değil 0343 veriyor başına hep 0 koyuyor
    a--;

    // (n<0) 1 ya da 0 döndürüyor
    // çünkü bu bir ifadedir doğru (1) ya da yanlıştır (0)
    // sayı negatif değilse eğer n < 0 ifadesi 0 döndürecektir
    // o zaman da a bitene kadar (0 olana kadar) işlem sürer
    // _bu arada sayı soldan değil sağdan itibaren yazdırılır_
    // ama eğer sayı negatifse n < 0 ifadesi 1 döndürecektir
    // o zaman da a 0 değil 1 olana kadar yazdırma sürer. bu ek bir karakter
    // de yukarıda yazdıgımız mystr[0] = '-' işaretine gelmeden durmasını sağlar
    // giderek str'ye çevirip (+48) mystr'ye atıyoruz
    // nb /= 10 sebebi bir digit sola kaydırmak
    while ((n < 0) <= a)
    {
        mystr[a] = (nb % 10) + 48;
        nb /= 10;
        a--;
    }
    return (mystr);
}

/* int main(void)
{
    printf("%s", ft_itoa(-234));
} */