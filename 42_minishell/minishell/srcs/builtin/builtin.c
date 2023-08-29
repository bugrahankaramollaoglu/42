/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:59:35 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:59:35 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	builtin(void)
{
	if (g_data.command == NULL)
		return (-1);
	if (ft_strcmp(g_data.command[0], "cd"))
		ft_cd();
	else if (ft_strcmp(g_data.command[0], "pwd"))
		ft_pwd();
	else if (ft_strcmp(g_data.command[0], "export") && g_data.command[1])
		ft_export();
	else if (ft_strcmp(g_data.command[0], "unset"))
		ft_unset();
	else if (ft_strcmp(g_data.command[0], "env"))
		ft_env();
	else
		return (-1);
	return (0);
}
