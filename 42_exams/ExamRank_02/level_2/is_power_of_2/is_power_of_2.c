/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:18:45 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/25 14:50:02 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int is_power_of_2(unsigned int n)
{
    if (n == 0)
        return 0;
    return ((n & ((~n) + 1)) == n ? 1 : 0);
}

int main(void)
{
    unsigned int num[7];
    num[0] = 0;
    num[1] = 200;
    num[2] = 32;
    num[3] = 256;
    num[4] = 13;
    num[5] = 1000;
    num[6] = 1024;
    int i;

    i = 0;
    while (i <= 6)
    {
        if (is_power_of_2(num[i]))
            printf("%s %d\n", "yep", num[i]);
        else
            printf("%s %d\n", "nope", num[i]);
        i++;
    }
}

/*
& operatörü sadece 1-1'de 1 veriyor
~ operatörü 1'leri 0, 0'ları 1 yapıyor
mesela 18 verelim n = 0001 0010
bunun ~'lisi 1110 1101 yapar.
bunun 1 fazlası 1110 1110 yapar.
bunun n ile &'i 0000 0010 yapar
bu da n'e eşit olmadığı için 0 döndürür.
yani 18 2nin üssü degilmis.

fakat aynı seyi 32 icin yapalım
32 yani n = 0010 0000
bunun ~'lisi 1101 1111 yapar.
bunun 1 fazlası 1110 0000 yapar.
bunun n ile &'i 0010 0000 yapar.
bu da n'e eşittir.
sadece 2nin üslerine bu işlemleri uyguladıgımızda
yine aynı sayıya ulaşıyoruz
*/