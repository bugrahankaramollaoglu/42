/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:03:56 by bkaramol          #+#    #+#             */
/*   Updated: 2023/08/30 13:15:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_char_in_set(char const *set, char c)
{
	size_t i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, const char *set)
{
	char *mystr;
	size_t start;
	size_t end;
	size_t i;

	start = 0;
	while (s1[start] && ft_char_in_set(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_char_in_set(set, s1[end - 1]))
		end--;
	mystr = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!mystr)
		return (NULL);
	i = 0;
	while (start < end)
		mystr[i++] = s1[start++];
	mystr[i] = '\0';
	return (mystr);
}
