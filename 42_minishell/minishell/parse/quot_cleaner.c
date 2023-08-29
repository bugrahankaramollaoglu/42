/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quot_cleaner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:39 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/29 15:58:39 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

void	quot_cleaner(t_arg **prompt)
{
	t_arg	*iter;
	char	*s;

	iter = *prompt;
	while (iter)
	{
		if (contains_quot(iter->arg))
		{
			if (iter->type != DOLLAR)
			{
				s = iter->arg;
				iter->arg = trim_quot(iter->arg);
				free(s);
			}
		}
		iter = iter->next;
	}
}
