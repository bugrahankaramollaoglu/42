/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 20:20:00 by bkaramol          #+#    #+#             */
/*   Updated: 2022/08/07 21:37:36 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// 2 stringi uç uca ekler

char    *ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	// s1 için sayaç
	int		i;
	// s2 için sayaç
	int		j;
	// birleştirilmiş halini tutacak string
	char	*s3;

	i = 0;
	j = 0;
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);

	// 2sinden biri boşsa nulla
	if (!s1 || !s2)
		return (NULL);
	
	// s3 için ikisinin uzunlugu + 1 (\0) kadar yer ayır
	s3 = (char *)malloc(sizeof(char) * (s1len + s2len + 1));

	// s1 bitene kadar s1'in her indisini s3'e kopyala
	while (s1[i])
		s3[j++] = s1[i++];
	i = 0;
	// s2 bitene kadar s2'nin her indisini s3'e kopyala
	// j'yi sıfırlamadığımız için kaldığı yerden devam eder
	while (s2[i])
		s3[j++] = s2[i++];
	// s3'ün sonuna bittiğini gösteren null koy
	s3[j] = '\0';
	return (s3);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/* #include <stdio.h>
int main() {
	char a[] = "asdas";
	char b[] = "cemre";
	printf("%s", ft_strjoin(a,b));
} */