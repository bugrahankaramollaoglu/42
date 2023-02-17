/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:56:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/14 13:13:28 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_alphabet(void)
{
	char alpha;

	alpha = 96;
	while (++alpha <= 'z')
		write(1, &alpha, 1);
}

int main()
{
	ft_print_alphabet();
}
