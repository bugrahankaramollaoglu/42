/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:54:59 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/31 00:46:32 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parse/parse.h"

int	contains_dollars(char *s)
{
	int	i;

	i = -1;
	if (!s || !*s)
		return (0);
	while (s[++i])
		if (s[i] == '$' && s[i + 1] != '\0' && s[i + 1] != ' ')
			return (1);
	return (0);
}

int	initialize_metacharacter(t_arg *node)
{
	int	len;

	len = ft_strlen(node->arg);
	if (len == 1)
	{
		if (*node->arg == '<')
			node->type = INPUT_RDR;
		else if (*node->arg == '>')
			node->type = OUTPUT_RDR;
		else if (*node->arg == '|')
			node->type = PIPE;
	}
	if (len == 2)
	{
		if (*node->arg == '<' && *(node->arg + 1) == '<')
			node->type = DOUBLE_INPUT_RDR;
		else if (*node->arg == '>' && *(node->arg + 1) == '>')
			node->type = DOUBLE_OUTPUT_RDR;
		else
		{
			g_data.error_flag = -2;
			return (-2);
		}
	}
	return (0);
}

int	identify_token(t_arg **prompt)
{
	t_arg	*iter;

	iter = *prompt;
	while (iter)
	{
		if (contains_dollars(iter->arg))
			iter->type = DOLLAR;
		else if (is_redirection(iter->arg) || is_pipe(iter->arg))
		{
			if (initialize_metacharacter(iter) == -2)
			{
				g_data.list = *prompt;
				return (0);
			}
		}
		else
		{
			iter->type = WORD;
		}
		iter = iter->next;
	}
	return (1);
}
