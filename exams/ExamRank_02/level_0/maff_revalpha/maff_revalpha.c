/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maff_revalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:56:22 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/12 16:57:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main()
{
    char a = 'Z';
    char b = 'y';

    while (b >= 'a')
    {
        write(1, &a, 1);
        write(1, &b, 1);
        // 2şer 2şer arttırıyoruz
        a -= 2;
        b -= 2;
    }
    write(1, "\n", 1);
    return 0;
}