/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:01:56 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/14 13:18:08 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_print_numbers(void)
{
	char num;

	num = '0';
	while (++num <= '9')
		write(1, &num, 1);
}

int main()
{
	ft_print_numbers();
}
