/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 02:28:41 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 11:28:42 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int ac, char **av)
{
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            if (av[1][i] != ' ' && av[1][i] != '\t')
                write(1, &av[1][i], 1);
            else if (av[1][i] == ' ' || av[1][i] == '\t')
                if (av[1][i + 1] > 32 && av[1][i + 1])
                    // epur_str'nin aynısı sadece burada 1 değil 3 bosluk koyuyosun
                    write(1, "   ", 3);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}