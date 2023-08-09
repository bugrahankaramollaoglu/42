/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:07 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 16:00:07 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_delenv2(char **new_envp, int flag)
{
	if (!flag)
		g_data.envp = new_envp;
	else
		g_data.ex_path = new_envp;
}

void	ft_delenv(char **envp, int j, int flag)
{
	int		i;
	int		k;
	char	**new_envp;

	k = 0;
	i = 0;
	new_envp = (char **)malloc(sizeof(char *) * (env_counter(envp)));
	while (envp[i])
	{
		if (i == j)
		{
			free(envp[i]);
			i++;
		}
		else
		{
			new_envp[k] = envp[i];
			i++;
			k++;
		}
	}
	new_envp[k] = NULL;
	ft_delenv2(new_envp, flag);
	free(envp);
}
