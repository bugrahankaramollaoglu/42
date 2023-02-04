/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:44:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/16 23:24:26 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// c karakterini baştan len byte kadar b'ye kopyalar
// Asıl önemli kısım ise; bu işlemi yaparken doğrudan
// void *b üzerinden değil, *b'nin ram adresini işaretleyen
// ve fonksiyon içerisinde tanımlanan yeni bir char *dizi
// değişkeni üzerinden yapmasıdır.

#include "libft.h"

void *ft_memset(void *b, int c, size_t n)
{
    unsigned int i;

    i = 0;
    // n bitene kadar
    while (n--)
    {
        // b'nin baştan ilk n karakterini c'ye çeviriyoruz
        ((unsigned char *)b)[i] = (unsigned char)c;
        i++;
    }
    return (b);
}

/* int main() {
    char x[] = "bugrahan";
    ft_memset(x, '0', 4);
    printf("%s", x);
} */

