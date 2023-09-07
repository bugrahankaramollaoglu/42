/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:33 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/30 23:07:50 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

int	tokenizer(t_arg **prompt)
{
	split_by_space(g_data.line, prompt);
	if (g_data.error_flag)
	{
		g_data.list = *prompt;
		return (0);
	}
	split_by_redirection(prompt);
	split_by_pipe(prompt);
	return (1);
}

void	type_counter(t_arg **prompt)
{
	g_data.count_type = ft_calloc(1, sizeof(t_type_counter));
	while (*prompt)
	{
		if ((*prompt)->type == INPUT_RDR || (*prompt)->type == OUTPUT_RDR
			|| (*prompt)->type == DOUBLE_OUTPUT_RDR)
			g_data.count_type->rdr++;
		else if ((*prompt)->type == DOLLAR)
			g_data.count_type->dollar++;
		else if ((*prompt)->type == WORD)
			g_data.count_type->word++;
		else if ((*prompt)->type == DOUBLE_INPUT_RDR)
			g_data.count_type->heredoc++;
		else if ((*prompt)->type == PIPE)
			g_data.count_type->pipe++;
		(*prompt) = (*prompt)->next;
	}
}

int	ft_parse(void)
{
	t_arg	*line;

	line = ft_calloc(1, sizeof(t_arg));
	if (!tokenizer(&line))
		return (-1);
	if (!identify_token(&line))
		return (-1);
	quot_cleaner(&line);
	g_data.list = line;
	type_counter(&line);
	return (1);
}
