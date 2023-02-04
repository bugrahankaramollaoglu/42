/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugra <bugra@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:25:12 by bugra             #+#    #+#             */
/*   Updated: 2022/10/29 17:25:12 by bugra            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// verilen girdiyi (a'dan z'ye) büyük harfe çeviren fonksiyon

// neden int tanımladık? çünkü ascii değerini alsın istiyoruz
int	ft_toupper(int c)
{
	// a ile z arasında ise 32 çıkar ki A ve Z olsun
	// 32 de ascii table'dan geliyor.
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/* int main() {
	printf("%c\n", ft_toupper('s'));	
} */