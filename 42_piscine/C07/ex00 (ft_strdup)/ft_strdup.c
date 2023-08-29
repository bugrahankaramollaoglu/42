/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:00:34 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/18 17:03:28 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = ft_strlen(src);
	str = malloc(len + 1);
	if (!str)
		return (0);
	while (src[i])
	{
		str[i++] = src[i];
	}
	str[i] = '\0';
	return (str);
}
#include <stdio.h>
int main() {
	char str[] = "bugrahan";
	printf("%s\n", ft_strdup(str));
}

