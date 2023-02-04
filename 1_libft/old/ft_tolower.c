/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugra <bugra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:25:10 by bugra             #+#    #+#             */
/*   Updated: 2022/10/29 17:25:10 by bugra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// büyük ise küçük harfe çeviren fonksiyon

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/* #include <stdio.h>

int main() {
	printf("%c", ft_tolower('S'));
} */