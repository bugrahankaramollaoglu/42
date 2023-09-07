#include <unistd.h>

int main(int ac, char **av)
{
    if (ac >= 2)
    {
        int i = 0;
        int y = 0;
        // "    bugra    kara    molla  oglu  " olsun stringimiz. sonuc "kara molla oglu bugra"$ olmalı
        // önce baştaki boşlukları atlıyoruz, ilk kelimenin ilk harfine geldi indis
        while (av[1][i] && (av[1][i] == ' ' || av[1][i] == '\t'))
            i++;
        // daha sonra bu indisi yedekliyoruz ki sadece ilk kelimeyi en son yazdırırken kullanacagız
        y = i;
        // daha sonra bu ilk kelimeyi de atlıyoruz ve bugra_'ya geldik. indis su an _'de
        while (av[1][i] && (av[1][i] != ' ' && av[1][i] != '\t'))
            i++;
        // sonra tüm string bitene kadar
        while (av[1][i])
        {
            // kalan kelimelerin ilk harflerinde buna giriyor (' ' || '\t' değil ve bir önceki indisleri boşluk)
            if ((av[1][i] != ' ' && av[1][i] != '\t') && (av[1][i - 1] == ' ' || av[1][i] == '\t') && av[1][i])
            {
                // o zaman da kelime bitene kadar yazdırıyoruz
                while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
                    write(1, &av[1][i++], 1);
                // ve bir boşluk koyuyoruz
                write(1, " ", 1);
            }
            // kelime aralarındaki boşluklarda if'e girmiyor direkt arttırıyor
            i++;
        }
        // daha sonra yedekledigimiz indisle ilk kelimeyi en son yazdırıyoruz
        while (av[1][y] != ' ' && av[1][y] != '\t')
            write(1, &av[1][y++], 1);
    }
    write(1, "\n", 1);
    return 0;
}