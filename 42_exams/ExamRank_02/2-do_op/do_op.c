/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:16:53 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/13 15:39:32 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 4)
    {
        if (*av[2] == '+')
            printf("%d", atoi(av[1]) + atoi(av[3]));
        else if (*av[2] == '-')
            printf("%d", atoi(av[1]) - atoi(av[3]));
        else if (*av[2] == '*')
            printf("%d", atoi(av[1]) * atoi(av[3]));
        else if (*av[2] == '/')
            printf("%d", atoi(av[1]) / atoi(av[3]));
        else if (*av[2] == '%')
            printf("%d", atoi(av[1]) % atoi(av[3]));
    }
    printf("\n");
    return (0);
}
