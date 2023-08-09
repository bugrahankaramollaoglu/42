/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:29 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 16:00:29 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_way(void)
{
	int	status;

	status = 0;
	if (g_data.count_type->heredoc)
	{
		dup2(g_data.here_fd[0], STDIN_FILENO);
		close(g_data.here_fd[0]);
	}
	if (g_data.redirection != NULL)
		exec_redir(status);
	if (ft_strcmp(g_data.command[0], "export"))
	{
		if (g_data.command[1] == NULL)
			ft_export_path();
		else
			ft_export();
		exit(0);
	}
	else if (ft_strcmp(g_data.command[0], "echo"))
	{
		ft_echo();
		exit(0);
	}
	else if (g_data.command != NULL)
		check_dollar_exit();
}

void	check_dollar_exit(void)
{
	if (g_data.dollar_flag)
		exit(0);
	else
		ft_execve();
}

void	execute(void)
{
	int	status;
	int	i;

	g_data.sig_handler_flag = 1;
	i = 0;
	ft_command_line();
	if (builtin() == -1)
		status = fork();
	else
		return ;
	g_data.executor_flag = 1;
	if (status == 0)
		check_way();
	else
		waitpid(status, &g_data.exit_status, 0);
	g_data.executor_flag = 0;
	if (WIFEXITED(g_data.exit_status) && i == 0)
	{
		g_data.exit_status = WEXITSTATUS(g_data.exit_status);
		i++;
	}
}
