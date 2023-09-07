/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:59:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 19:59:17 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	quot_parse(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"' && str[i + 1] != '\"')
			return (2);
		else if (str[i] == '\'' && str[i + 1] != '\'')
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen2(char **a)
{
	int	i;

	i = 0;
	while (a[i])
		i++;
	return (i);
}

void	ft_special_func(int j)
{
	int		i;
	char	*tmp;

	i = 0;
	if (j == 0)
		ft_putstr_fd("minishell: ", 1);
	while (g_data.list->arg[i])
	{
		if (g_data.list->arg[i] == '$')
		{
			if (g_data.list->arg[i + 1] == '?')
			{
				tmp = ft_itoa(g_data.exit_status);
				ft_putstr_fd(tmp, 1);
				free(tmp);
				i += 2;
			}
			else
				ft_putchar_fd(g_data.list->arg[i++], 1);
		}
		else
			ft_putchar_fd(g_data.list->arg[i++], 1);
	}
	if (j == 0)
		ft_putstr_fd(": command not found\n", 1);
}
