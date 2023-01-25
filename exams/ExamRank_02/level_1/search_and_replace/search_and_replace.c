/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:16:32 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/12 18:16:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
// "abc abc ab" "a" "o" --> obc obc ob
int main(int ac, char **av)
{
    if (ac == 4)
    {
        int i = 0;
        while (av[1][i])
        {
            if (av[1][i] == *av[2])
                av[1][i] = *av[3];
            write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}