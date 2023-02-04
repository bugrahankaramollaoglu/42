/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 01:40:24 by bkaramol          #+#    #+#             */
/*   Updated: 2023/02/03 01:40:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*ft_putword(char *word, char const *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_split_words(char const *s, char c, char **new_str,
		int num_words)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < num_words)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			word_len++;
			i++;
		}
		new_str[word] = (char *)malloc(sizeof(char) * (word_len + 1));
		if (!new_str)
			return (NULL);
		ft_putword(new_str[word], s, i, word_len);
		word_len = 0;
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
		return (0);
	num_words = ft_word_count(s, c);
	final_str = (char **)malloc(sizeof(char *) * (num_words + 1));
	if (!final_str)
		return (0);
	ft_split_words(s, c, final_str, num_words);
	return (final_str);
}
