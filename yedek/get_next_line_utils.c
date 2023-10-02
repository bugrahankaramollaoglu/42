/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 13:25:38 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/01 13:25:38 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t ft_strlen(char *str)
{
	size_t c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

char *ft_strjoin(char *str, char *buff)
{
	size_t c;
	size_t i;
	char *full_str;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buff)
		return (NULL);
	full_str = malloc(sizeof(char) * ((ft_strlen(str)) + ft_strlen(buff) + 1));
	if (full_str == NULL)
		return (NULL);
	c = -1;
	i = 0;
	while (str[++c])
		full_str[c] = str[c];
	while (buff[i])
		full_str[c++] = buff[i++];
	full_str[ft_strlen(str) + ft_strlen(buff)] = '\0';
	free(str);
	return (full_str);
}

char *ft_strchr(char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}

char *ft_get_line(char *str)
{
	int i;

	char *my_line;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;

	my_line = malloc((sizeof(char) * i) + 2);
	if (!my_line)
		return (NULL);
	i = 0;

	while (str[i] && str[i] != '\n')
	{
		my_line[i] = str[i];
		i++;
	}

	if (str[i] == '\n')
		my_line[i++] = '\n';

	my_line[i] = '\0';
	return (my_line);
}

char *ft_last_str(char *str)
{
	int c;

	int i;
	char *my_line;

	c = 0;

	while (str[c] && str[c] != '\n')
		c++;
	if (!str[c])
	{
		free(str);
		return (NULL);
	}

	my_line = malloc(sizeof(char) * (ft_strlen(str) - c) + 1);
	if (!my_line)
		return (NULL);
	c++;
	i = 0;

	while (str[c])
		my_line[i++] = str[c++];
	my_line[i] = '\0';

	free(str);

	return (my_line);
}
