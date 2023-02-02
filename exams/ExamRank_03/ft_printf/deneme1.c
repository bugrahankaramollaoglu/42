/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 05:54:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/02 06:08:56 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int ft_putchar(char c) {
	return (write(1, &c, 1));
}

int ft_putstr(char *str) {
	int i = 0;
	if (!str)
		str = "(null)";
	while (str[i]){
		ft_putchar(str[i]);
		i++;
	}
	return i;
}

int ft_putnbr(unsigned int nb, int base) {
	int i = nb % base;
	char *base_set = "0123456789abcdef";
	int counter = 0;
	if (nb / base > 0)
		counter += ft_putnbr(nb / base, base);
	counter += ft_putchar(base_set[i]);
	return counter;
}


int main() {
	// int a = ft_putchar(5);
	// printf("%d\n", a);
	// int a = ft_putnbr(55, 10);
	//printf("%d\n", ft_putnbr(55, 10));
}
