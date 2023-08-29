/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:44:43 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/26 15:42:30 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
	int a;

	a = 0;
	while (str[a] != '\0')
	{
		a++;
	}
	return (a);
}

/* ikinci yol
int ft_strlen(char *str) {
	int i = 0;
	while (*str) {
		str++;
		i++;
	}
	return i;
} */

/*
int	main(void)
{
	int	a;

	a = ft_strlen("bugra");
	printf("%d", a);
}
*/
