/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:12 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/31 01:11:58 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	ft_putstr_fd(path, 1);
	ft_putstr_fd("\n", 1);
	free(path);
}

void	ft_env(void)
{
	int	i;

	i = 0;
	while (g_data.envp[i])
	{
		ft_putstr_fd(g_data.envp[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

char	**create_cpy_env(char **envp)
{
	int		i;
	char	**cpy_env;

	i = 0;
	while (envp[i])
		i++;
	cpy_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		cpy_env[i] = ft_strdup(envp[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}
