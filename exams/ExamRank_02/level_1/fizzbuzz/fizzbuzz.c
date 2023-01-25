/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:59:03 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/17 01:04:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if (n <= 9)
    {
        c = n + '0';
        write(1, &c, 1);
    }
    else
    {
        ft_putnbr(n / 10);
        ft_putnbr(n % 10);
    }
}

int main(void)
{
    int i;

    i = 1;
    while (i <= 100)
    {
        // fizzbuzz'ı (15ile bölünenler) ifelse'e değil if'e yazmak zorundasın
        // yoksa karışıyor (uzun hikaye)
        if (i % 15 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else
            ft_putnbr(i);
        write(1, "\n", 1);
        i++;
    }
}
