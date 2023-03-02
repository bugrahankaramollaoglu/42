/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftr_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:22:55 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/19 16:24:00 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* strlen() is normally a built-in function from string.h library.
it is very easy, it calculates the length of a given string */

#include <unistd.h>

int ft_strlen(char *str)
{
	int c;

	c = 0;
	while (str[c])
		c++;
	return (c);
}

int main()
{
	printf("%d", ft_strlen("asdasdasdasdasd"));
}
