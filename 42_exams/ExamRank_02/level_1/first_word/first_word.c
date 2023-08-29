/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:58:32 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/26 04:04:04 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// argüman "  " olarak verilirse diye içinde kelime (az - AZ) aralığında bir şey yani kelime
// yoksa diye kontrol eden bir ek fonksiyon yazmak zorundasın
int is_word(char *str)
{
    int i = 0;
    while (str[i])
    {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
            return 1;
        i++;
    }
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && is_word(av[1]) == 1)
    {
        int i = 0;

        // baştaki boşlukları atlıyoruz
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        // bir sonraki boşluğa gelene yani kelime bitene kadar yazdırıyoruz
        while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i])
        {
            write(1, &av[1][i], 1);
            i++;
        }
    }
    // sonra \n atıp çıkıyoruz
    write(1, "\n", 1);
    return 0;
}
