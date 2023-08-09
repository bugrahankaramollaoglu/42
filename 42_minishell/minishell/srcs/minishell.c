/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:53 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 23:05:33 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_shell(int status)
{
	if (status == 0)
		ft_execve();
	else
	{
		perror("minishell");
	}
}

void	ft_struct_initialize(char **envp, int flag)
{
	if (flag)
	{
		g_data.ex_path = create_cpy_env(envp);
		g_data.envp = create_cpy_env(envp);
	}
	g_data.list = NULL;
	g_data.command = NULL;
	g_data.redirection = NULL;
	g_data.count_type = NULL;
	g_data.heredoc = NULL;
	g_data.line = NULL;
	g_data.sig_flag = 0;
	g_data.dollar_flag = 0;
	g_data.heredoc_flag = 0;
	g_data.error_flag = 0;
	g_data.here_fd = 0;
	g_data.sig_handler_flag = 0;
	g_data.executor_flag = 0;
}

int	start2(t_arg *temp)
{
	if (error_check() == -1)
	{
		temp = NULL;
		return (-1);
	}
	if (g_data.count_type->dollar > 0)
		ft_dollars_line();
	if (g_data.count_type->heredoc > 0)
		ft_heredoc_line();
	if (ft_strcmp(g_data.list->arg, "exit"))
	{
		ft_exit(temp);
		return (-1);
	}
	if (initialize_pipe() == -1)
		execute();
	return (0);
}

void	start(void)
{
	t_arg	*cpy_g_data_list;

	while (1)
	{
		ft_struct_initialize(g_data.envp, 0);
		g_data.line = readline("minishell-$ ");
		if (g_data.sig_flag == 1)
		{
			free(g_data.line);
			continue ;
		}
		if (!g_data.line)
			signal_exit();
		ft_parse();
		cpy_g_data_list = g_data.list;
		add_history(g_data.line);
		free(g_data.line);
		start2(cpy_g_data_list);
		freeliazer(cpy_g_data_list);
	}
}

int	main(int ac, char **av, char **envp)
{
	if (ac > 1)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	av = NULL;
	signal(SIGINT, ft_sig_handler);
	signal(SIGQUIT, ft_slash_controller);
	g_data.exit_status = 0;
	ft_struct_initialize(envp, 1);
	start();
	return (0);
}
