/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:41:51 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/25 14:22:57 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

/*
bu fonksiyon 1011 0111 şeklinde verilen biti 1110 1101 haline sokuyor
 */

unsigned char reverse_bits(unsigned char octet)
{
    int i = 8;
    unsigned char result = 0;

    while (i)
    {
        result = result * 2 + (octet % 2);
        octet /= 2;
        i--;
    }
    return (result);
}

int main()
{
    printf("%d", reverse_bits('0'));
} // 0011 0000 (48) --> 0000 1100 (12)