/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:04 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 16:00:04 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_addenv(char **envp, int j, int flag)
{
	int		i;
	char	*force;
	char	**new_envp;

	i = 0;
	force = ft_strdup(g_data.command[j]);
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp) + 2));
	while (envp[i])
	{
		new_envp[i] = ft_strdup(envp[i]);
		free(envp[i]);
		i++;
	}
	new_envp[i] = force;
	new_envp[i + 1] = NULL;
	if (!flag)
		g_data.envp = new_envp;
	else
		g_data.ex_path = new_envp;
	free(envp);
}
