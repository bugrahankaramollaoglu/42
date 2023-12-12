/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:23:06 by bkaramol          #+#    #+#             */
/*   Updated: 2022/12/11 20:34:36 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

/* normal splitten farklı olarak sınav spliti otomatik bosluklardan
ayırmamızı istiyor. özel ayraç verilmiyor parametre olarak o yüzden much easier */
char **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char **split;

    // splitted kelimeleri tutacak 2 boyutlu bir string yaratip yer ayirdik
    split = malloc(sizeof(char *) * 256);
    if (!split)
        return 0;

    // ana stringin başındaki boşlukları atladık
    while (str[i] == ' ' || str[i] == '\t')
        i++;

    // string bitene kadar
    while (str[i])
    {
        // j her döngüde sıfırlanacak
        j = 0;

        // her keliemeye özel yer açıyoruz
        split[k] = malloc(sizeof(char) * 4096);
        if (!split[k])
            return 0;

        while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\0')
        {
            split[k][j] = str[i];
            j++;
            i++;
        }

        while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
            i++;

        // her splitted kelimenin sonuna null koyuyoruz
        split[k][j] = '\0';
        k++;
    }
    // ayrılmıs kelimelerin oldugu stringin sonuna da null koyuyoruz
    split[k] = '\0';
    return split;
}
