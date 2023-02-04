/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:10:27 by bkaramol          #+#    #+#             */
/*   Updated: 2022/07/17 09:28:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char *'ın önüne const sınıfını getirdiğimizde char *
// içerisindeki değerler yalnız okunabilir (read only) olur
size_t	ft_strlen(const char *s)
{
	// uzunluk negatif olamayacagı icin size_t
	size_t	a;

	a = 0;
	
	// s'nin sonuna gelene kadar
	while (s[a])
		a++;
	return (a);
}

/* bunu pointerlarla da yapabilirsin

int ft_strlen(char *s)
{
    int len = 0;
    while (*s)
    {
        len++;
        s++;
    }
    return len;
} */
