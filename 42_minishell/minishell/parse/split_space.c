/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:53 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 23:13:27 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	is_quotation(char *s)
{
	if (*s == '\"')
		return (1);
	else if (*s == '\'')
		return (2);
	return (0);
}

int	type_quotation(char s)
{
	if (s == '\'')
		return (1);
	else if (s == '\"')
		return (2);
	else
		return (0);
}

void	split_line2(int start, int len, char *s, t_arg *line)
{
	int	i;

	i = -1;
	while (++i || 1)
	{
		if (is_quotation(&s[i]) == 1 && len++)
			while (!(is_quotation(&s[++i]) == 1) && s[i])
				len++;
		else if (is_quotation(&s[i]) == 2 && len++)
			while (!(is_quotation(&s[++i]) == 2) && s[i])
				len++;
		if (is_space(s[i]) || !s[i])
		{
			if (len != 1)
				p_lstadd_back(&line, p_lstnew(0, ft_substr(s, start, len - 1)));
			start = i + 1;
			len = 0;
		}
		if (!s[i])
			break ;
		len++;
	}
	free(s);
}

int	check_quote(char *line)
{
	int	i;
	int	sign;

	sign = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			if (sign == 0)
				sign = 1;
			else if (sign == 1)
				sign = 0;
		}
		else if (line[i] == '\"')
		{
			if (sign == 0)
				sign = 2;
			else if (sign == 2)
				sign = 0;
		}
		i++;
	}
	return (sign);
}

void	split_by_space(char *s, t_arg **line)
{
	t_arg	*line_tmp;

	if ((check_quote(s)) != 0)
	{
		g_data.error_flag = -1;
		return ;
	}
	s = ft_strtrim(s, " ");
	split_line(s, *line);
	line_tmp = *line;
	*line = (*line)->next;
	free(line_tmp);
}
