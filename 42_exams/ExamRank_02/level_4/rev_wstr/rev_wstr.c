#include <unistd.h>
#include <stdio.h>

void rev_wstr(char *str)
{
    int i = 0;
    int j = 0;
    int is_first = 1;

    // len'i aliyoruz
    while (str[i])
        ++i;

    while (i >= 0)
    {
        // kelimeden sonraki boslukları atlıyoruz indisi sola kaydırarak
        while (i >= 0 && (str[i] == '\0' || str[i] == ' ' || str[i] == '\t'))
            i--;

        // kelimenin bittigi indisi yedekliyoruz
        j = i;

        // kelime bitene kadar ikinci yedegi bir azaltıyoruz. böylece daha sonra
        // yazdırırken ilk_yedek - ikinci_yedek bize kelimenin uzunlugunu verecek
        while (j >= 0 && str[j] != ' ' && str[j] != '\t')
            j--;

        // ilk kelimeden önce bosluk olmayacagı icin ilk kelime degilse " " atiyoruz
        if (is_first == 0)
            write(1, " ", 1);

        // daha sonra str (0. indis) + j + 1'den başlayarak i-j yani kelime uzunlugu kadar yaziyoruz
        write(1, str + j + 1, i - j);

        // simdi bunu 0'lıyoruz bundan sonra degistirmiyoruz
        is_first = 0;

        // bir önceki kelimenin sonuna geçmek için j'nin konumunu i'ye atiyoruz
        i = j;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_wstr(argv[1]);
    write(1, "\n", 1);
    return (0);
}