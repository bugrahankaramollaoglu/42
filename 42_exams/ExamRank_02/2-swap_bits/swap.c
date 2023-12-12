/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 00:37:23 by bkaramol          #+#    #+#             */
/*   Updated: 2022/10/17 01:14:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// bu fonksiyon 0110 0101 bitini 0101 0110 haline sokuyor

unsigned char swap_bits(unsigned char octet)
{
    // | (pipe) operatörü işlemleri aynı anda yapıyor
    // aynı anda 4 sola 4 sağa kaydırınca böyle oluyor 
    return ((octet >> 4) | (octet << 4));
}