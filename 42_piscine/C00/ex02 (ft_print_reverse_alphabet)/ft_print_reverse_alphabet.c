/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:00:18 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/14 13:15:22 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_reverse_alphabet(void)
{
	char alpha;

	alpha = 123;
	while (--alpha >= 'a')
		/* çünkü write fonksiyonu adres istiyor */
		write(1, &alpha, 1);
}

int main()
{
	ft_print_reverse_alphabet();
}
