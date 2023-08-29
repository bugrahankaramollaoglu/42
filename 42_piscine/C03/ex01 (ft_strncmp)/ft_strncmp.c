/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 11:04:14 by bkaramol          #+#    #+#             */
/*   Updated: 2022/02/26 11:37:08 by bkaramol         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

/* cmp'den farkı sadece ilk n karakteri kaşılaştırmasıdır. */
int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > i + 1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

#include <stdio.h>

int main()
{
	char *s1 = "bugba";
	char s2[] = "bugah";

	printf("%d", ft_strncmp(s1, s2, 5));
}
