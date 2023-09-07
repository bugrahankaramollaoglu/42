/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dollars_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:59:53 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 21:54:24 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_parse_dollars2(char **line, char *src)
{
	int		i;
	char	*temp;

	i = 0;
	while (line[i])
	{
		if (i == 0)
			src = ft_strdup(line[i]);
		else
		{
			temp = src;
			src = ft_strjoin(src, line[i]);
			free(temp);
		}
		free(line[i]);
		i++;
	}
	free(line);
	return (src);
}

int	special_parse(int i, char *prev_arg)
{
	int	a;

	if (i > 0 && !ft_strcmp(prev_arg, "echo") && !ft_strcmp(prev_arg, "export"))
		return (0);
	a = 0;
	while (g_data.list->arg[a] != '$' && g_data.list->arg[a + 1] != '?')
		a++;
	if (g_data.list->arg[a + 1] == '?')
	{
		if (ft_strlen(g_data.list->arg) > 2)
		{
			ft_special_func(i);
			free(g_data.list->arg);
			g_data.dollar_flag = 1;
			g_data.list->arg = ft_strdup("");
		}
		else
		{
			free(g_data.list->arg);
			g_data.list->arg = ft_itoa(g_data.exit_status);
		}
		return (0);
	}
	return (-1);
}

void	ft_parse_dollars(void)
{
	char	*src;
	char	**line;
	int		i;

	i = 0;
	src = g_data.list->arg;
	if (src[0] != '$')
		i++;
	line = ft_split(src, '$');
	if (ft_strlen2(line) == 0)
	{
		free(line);
		return ;
	}
	free(src);
	while (line[i])
	{
		line[i] = ft_find_env(line[i]);
		i++;
	}
	src = ft_parse_dollars2(line, src);
	g_data.list->arg = src;
}

void	dollar_prs(char *str)
{
	int	len;
	int	i;
	int	j;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] == '\'')
			while (str[++i] != '\'' && str[i] != '\0')
				str[j++] = str[i];
		else if (str[i] == '\"')
			while (str[++i] != '\"' && str[i] != '\0')
				str[j++] = str[i];
		else
			str[j++] = str[i];
		i++;
	}
	str[j] = '\0';
}

void	ft_dollars_line(void)
{
	t_arg	*temp_s;
	int		flag;
	int		i;

	i = 0;
	temp_s = g_data.list;
	while (g_data.list)
	{
		if (g_data.list->type == DOLLAR)
		{
			flag = quot_parse(g_data.list->arg);
			dollar_prs(g_data.list->arg);
			g_data.list->type = WORD;
			if (flag != 1)
			{
				if (special_parse(i, temp_s->arg) == -1)
					ft_parse_dollars();
			}
		}
		g_data.list = g_data.list->next;
		i++;
	}
	g_data.list = temp_s;
}
