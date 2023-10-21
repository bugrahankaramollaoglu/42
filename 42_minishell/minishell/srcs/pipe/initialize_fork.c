/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_fork.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:01:06 by bkaramol          #+#    #+#             */
/*   Updated: 2023/10/21 14:40:18 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	set_file_descriptor(int id)
{
	if (id == 0)
	{
		dup2(g_data.all_pipe_fd[id][1], 1);
		close_fd(id);
		check_way();
	}
	else if (id == g_data.pipe_c)
	{
		dup2(g_data.all_pipe_fd[id - 1][0], 0);
		close_fd(id);
		check_way();
	}
	else
	{
		dup2(g_data.all_pipe_fd[id - 1][0], 0);
		dup2(g_data.all_pipe_fd[id][1], 1);
		close_fd(id);
		check_way();
	}
}

void	pipe_free(void)
{
	int	i;

	i = 0;
	while (i < g_data.pipe_c)
	{
		free(g_data.all_pipe_fd[i]);
		i++;
	}
	free(g_data.all_pipe_fd);
}

void	initialize_fork2(void)
{
	int	k;
	int	j;
	int	i;

	k = -1;
	j = -1;
	i = 0;
	while (++k != g_data.pipe_c)
	{
		while (++j != 2)
			close(g_data.all_pipe_fd[k][j]);
		j = -1;
	}
	while (i <= g_data.pipe_c)
	{
		waitpid(g_data.pipe_id[i], &g_data.exit_status, 0);
		i++;
		if (WIFEXITED(g_data.exit_status))
			g_data.exit_status = WEXITSTATUS(g_data.exit_status);
	}
	free(g_data.pipe_id);
}

void	initialize_fork(void)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = -1;
	i = 0;
	g_data.pipe_id = malloc(sizeof(int) * (g_data.pipe_c + 1));
	while (i <= g_data.pipe_c)
	{
		if (i != 0 && g_data.command)
			ft_free_command_redirection();
		ft_command_line();
		g_data.pipe_id[i] = fork();
		if (g_data.pipe_id[i] == 0)
			set_file_descriptor(i);
		else
			i++;
	}
	initialize_fork2();
	pipe_free();
}
