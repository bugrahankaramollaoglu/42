/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42.istanbul.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:01:54 by bkaramol          #+#    #+#             */
/*   Updated: 2022/11/12 01:01:54 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	// \0 + \n
	my_line = malloc((sizeof(char) * i) + 2);
	if (!my_line)
		return (NULL);
	i = 0;

	// daha sonra satırı my_line'a atıyor
	while (str[i] && str[i] != '\n')
	{
		my_line[i] = str[i];
		i++;
	}

	// eğer str'de satır sonuna gelinmişse my_line'da da \n koyuyoruz
	if (str[i] == '\n')
		my_line[i++] = '\n';

	my_line[i] = '\0';
	return (my_line);
}

// satırdan \ndan sonra aldığı ek kısmı str'ye ekleyen fonksiyon
char *ft_last_str(char *str)
{
	int c;

	int i;
	char *my_line;

	c = 0;

	// satırın uzunlugunu alıp c'ye atıyoruz
	while (str[c] && str[c] != '\n')
		c++;
	if (!str[c])
	{
		free(str);
		return (NULL);
	}

	// mesela beş byte'lık bir satıra 7byte buffer_size verildi. kalan 2 byte'ı
	// bir alt satırdan almak isteyecektir. o 2 byte'ı tutacak olan şey burada my_line'dır
	// ona uygun yer ayırmak için de str uzunluğundan c'yi yani üst satırın uzunlugunu
	// çıkarıyor
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
