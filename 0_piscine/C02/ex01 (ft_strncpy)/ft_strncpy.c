/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:12:09 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/22 15:00:45 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* srcden deste n kadar kopyalar */

#include <unistd.h>
#include <stdio.h>

char *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int a;

	a = 0;

	// en fazla n kadar
	// src'nin sonuna gelene kadar
	while ((a < n) && src[a])
	{
		dest[a] = src[a];
		a++;
	}
	while (a < n)
	{
		dest[a] = '\0';
		a++;
	}
	return dest;
}

int main()
{
	char d[] = "cemre";
	char s[] = "bugra";
	printf("d artık: %s\n", ft_strncpy(d, s, 2));
}
