/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:37:01 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/24 14:27:40 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

size_t ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

size_t ft_strlcat(char *dest, char *src, size_t size)
{
	if (size)
	{
		size_t i = 0;
		size_t i2 = 0;
		size_t ret = ft_strlen(dest) + ft_strlen(src);
		while (dest[i])
			i++;
		while (src[i2] && i2 < size - 1)
		{
			dest[i] = src[i2];
			i++;
			i2++;
		}
		dest[i] = 0;
		return ret;
	}
}

#include <stdio.h>
#include <string.h>
int main()
{
	char a[] = "bugra";
	char b[] = "cemre";
	ft_strlcat(a, b, 10);
	printf("%s\n", a);
	printf("%s\n", b);
}
