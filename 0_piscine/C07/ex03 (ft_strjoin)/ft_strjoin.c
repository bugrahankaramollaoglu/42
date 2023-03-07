/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:14:41 by bkaramol          #+#    #+#             */
/*   Updated: 2023/03/06 22:04:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
	int i = 0;
	int i2 = 0;
	int len = 0;
	while (strs[i])
	{
		while (strs[i][i2])
		{
			len++;
			i2++;
		}
		i++;
		i2 = 0;
	}
	char *ss = malloc(sizeof(char) * len + 1);
	i = 0;
	i2 = 0;
	while (strs[i]) {
		while (strs[i][i2] != ) {
			ss[j]
		}
	}
	if (!ss)
		return 0;

	if (size == 0)
	{
		char *str;
		return str;
	}
}
