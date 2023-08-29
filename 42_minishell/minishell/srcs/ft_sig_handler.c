/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sig_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 16:00:43 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 22:42:27 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_slash_controller(int sig)
{
	(void)sig;
	if (g_data.sig_handler_flag == 1)
	{
		printf("Quit: 3\n");
		g_data.sig_handler_flag = 0;
	}
}

void	ft_sig_handler(int sig)
{
	(void)sig;
	if ((sig == SIGINT) && g_data.executor_flag == 0)
	{
		g_data.heredoc_flag = 1;
		g_data.exit_status = 1;
		g_data.sig_flag = 1;
		write(1, "\033[A", 3);
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
	}
}
