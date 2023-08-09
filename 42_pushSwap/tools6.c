/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 13:15:58 by bkaramol          #+#    #+#             */
/*   Updated: 2023/01/14 15:45:02 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_word_count(char const *str, char c)
{
	int	index;
	int	word_counter;

	index = 0;
	word_counter = 0;
	while (str[index])
	{
		if (str[index] == c)
			index++;
		else
		{
			word_counter++;
			while (str[index] && str[index] != c)
				index++;
		}
	}
	return (word_counter);
}

static char	*ft_putword(char *word, char const *s, int word_len, int word_len2)
{
	int	j;

	j = 0;
	while (word_len2 > 0)
	{
		word[j] = s[word_len - word_len2];
		j++;
		word_len2--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **new_str,
		int num_words)
{
	int	i;
	int	word;
	int	word_len2;

	i = 0;
	word = 0;
	word_len2 = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len2++;
		}
		new_str[word] = (char *)malloc(sizeof(char) * (word_len2 + 1));
		if (!new_str)
			return (NULL);
		ft_putword(new_str[word], s, i, word_len2);
		word_len2 = 0;
		word++;
	}
	new_str[word] = NULL;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**final_str;
	size_t	num_words;

	if (!s)
		return (NULL);
	num_words = ft_word_count(s, c);
	final_str = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!final_str)
		return (NULL);
	ft_split_words(s, c, final_str, num_words);
	return (final_str);
}

char	*ft_strjoin(char *a, char const *b)
{
	char	*final_str;
	int		i;
	int		i2;

	final_str = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b))
			+ 2);
	if (!final_str)
		return (0);
	i = 0;
	i2 = 0;
	while (a[i])
	{
		final_str[i] = a[i];
		i++;
	}
	final_str[i] = ' ';
	i++;
	while (b[i2])
	{
		final_str[i] = b[i2];
		i++;
		i2++;
	}
	final_str[i] = '\0';
	return (final_str);
}
