/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:01:10 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 16:01:10 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	exec_redir2(int status, char **redir, int i)
{
	if (ft_strcmp(redir[i], "<"))
	{
		g_data.fd = open(redir[i + 1], O_RDONLY, 0644);
		dup2(g_data.fd, 0);
		if (g_data.fd == -1)
		{
			printf("minishell: %s no such file or directory\n", redir[i + 1]);
			exit(1);
		}
		if (g_data.command && !redir[i + 2])
			exec_shell(status);
		close(g_data.fd);
	}
	else if (ft_strcmp(redir[i], ">>"))
	{
		g_data.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
		dup2(g_data.fd, 1);
		if (g_data.command[0] && !redir[i + 2] && !ft_strcmp(g_data.command[0],
				"echo"))
			exec_shell(status);
		close(g_data.fd);
	}
}

void	exec_redir(int status)
{
	char	**redir;
	int		i;

	redir = g_data.redirection;
	i = 0;
	while (redir[i])
	{
		if (ft_strcmp(redir[i], ">"))
		{
			g_data.fd = open(redir[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			dup2(g_data.fd, 1);
			if (g_data.command && !redir[i + 2] && !ft_strcmp(g_data.command[0],
					"echo"))
				exec_shell(status);
			close(g_data.fd);
		}
		else
			exec_redir2(status, redir, i);
		if (g_data.fd == -1)
		{
			perror("minishell");
			exit(1);
		}
		i += 2;
	}
}
