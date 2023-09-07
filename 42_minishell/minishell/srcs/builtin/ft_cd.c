/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:59:40 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:59:40 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_oldpwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "OLDPWD=", 7) == 0)
		{
			free(g_data.envp[i]);
			str = getcwd(NULL, 0);
			g_data.envp[i] = ft_strjoin("OLDPWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_pwd_changer(void)
{
	char	*str;
	int		i;

	i = 0;
	str = getcwd(NULL, 0);
	while (g_data.envp[i])
	{
		if (ft_strncmp(g_data.envp[i], "PWD=", 4) == 0)
		{
			free(g_data.envp[i]);
			g_data.envp[i] = ft_strjoin("PWD=", str);
			free(str);
			break ;
		}
		i++;
	}
}

void	ft_cd(void)
{
	g_data.exit_status = 0;
	ft_oldpwd_changer();
	if (g_data.command[1] && ft_strcmp(g_data.command[1], "~") == 0)
	{
		if (chdir(g_data.command[1]))
		{
			g_data.exit_status = 1;
			perror("minishell ");
		}
	}
	else if (chdir(getenv("HOME")))
	{
		g_data.exit_status = 1;
		perror("minishell ");
	}
	ft_pwd_changer();
}
