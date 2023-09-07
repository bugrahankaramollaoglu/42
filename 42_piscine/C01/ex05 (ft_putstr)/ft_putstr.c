/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:57:38 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/20 11:59:18 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

// putstr is a very basic version of printf() that can only
// print out strings by using putchar() in a loop

#include <unistd.h>

// klasik ft_putstr
void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* bi tık daha güzeli */
void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
}

// daha güzeli (pointerlarla)
void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

// daha da güzeli
void ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
