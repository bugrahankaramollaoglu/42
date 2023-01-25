#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

// basamak sayısı hesaplayan fonksiyon
int digit(int num)
{
    int i = 0;
    if (num == 0)
        return (1);
    if (num < 0)
        i++;
    while (num)
    {
        num /= 10;
        i++;
    }
    return i;
}

char *ft_itoa(int nb)
{
    // intin çevrilecegi string
    char *my_str;
    // basamak sayısı
    int dig = digit(nb);
    // sayının yedegi
    int nb2 = nb;

    // yer ayırıyoruz basamak sayısı + null kadar
    my_str = (char *)malloc(sizeof(int) * dig + 1);
    if (!my_str)
        return 0;
    // negatifse başına 0 atıyoruz
    if (nb < 0)
    {
        nb2 = -nb2;
        my_str[0] = '-';
    }
    // %10 metodu sadece son basamagı aldıgı icin sondan baslıyoruz eklemeye
    // o yüzden sonuna null koyup nuldan 1 sola kaydırıyoruz
    my_str[dig] = '\0';
    dig--;

    /* sayı negatifligi (1 ya da 0) dig'den kücük olana kadar döngü yaratıyoruz
    bunun sebebi şu: eğer sayı negatifse sayı koydugumuz - işaretine kadar eklensin
    o yüzden 1 <= dig olsun. değilse 0 <= dig olsun.  */
    while ((nb < 0) <= dig)
    {
        my_str[dig] = (nb2 % 10) + 48;
        nb2 /= 10;
        dig--;
    }
    return (my_str);
}

int main()
{
    printf("%s", ft_itoa(-234));
}
