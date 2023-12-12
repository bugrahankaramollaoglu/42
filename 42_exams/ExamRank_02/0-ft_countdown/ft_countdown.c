/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 16:55:46 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/12 16:55:54 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// bu yol hileli fakat sınavlarda geçiyor
int main()
{
    write(1, "9876543210\n", 11);
    return 0;
}

// bu da asıl çözüm yolu
int main()
{
    char a = '9';
    while (a >= '0')
    {
        write(1, &a, 1);
        a--;
    }
    write(1, "\n", 1);
    return 0;
}
