/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:28:41 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 11:27:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        // baştaki boşlukları atla
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        // string bitene kadar
        while (av[1][i])
        {
            // eğer harf ise yazdır
            if (av[1][i] != ' ' && av[1][i] != '\t')
                write(1, &av[1][i], 1);
            // eğer boşluksa
            else if (av[1][i] == ' ' || av[1][i] == '\t')
                // eğer bir sonraki harf null değilse ve .,?harf vs. ise boşluk koy
                // null değilse kuralı son kelimeden sonra " " koymamamızı sağlayacak
                // çünkü son harften bir sonraki harf null'dur.
                if (av[1][i + 1] > 32 && av[1][i + 1])
                    write(1, " ", 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}