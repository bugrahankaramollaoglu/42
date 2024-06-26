/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkaramol <bkaramol@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 15:58:49 by bkaramol          #+#    #+#             */
/*   Updated: 2023/07/31 01:12:05 by bkaramol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "parse.h"

t_arg	*create_front(int st, int len, t_arg **prompt, t_arg *tmp)
{
	t_arg	*front;

	front = p_lstnew(0, ft_substr((*prompt)->arg, (st + len),
				(ft_strlen((*prompt)->arg) - (st + len))));
	if (*front->arg)
		front->next = tmp;
	else
	{
		free(front->arg);
		free(front);
		front = tmp;
	}
	return (front);
}

void	*append_list(t_arg **prompt, int st, int len)
{
	char	*back;
	char	*rdr;
	t_arg	*front;
	t_arg	*tmp;

	tmp = (*prompt)->next;
	front = create_front(st, len, prompt, tmp);
	rdr = ft_substr((*prompt)->arg, st, len);
	if (st != 0)
	{
		back = ft_substr((*prompt)->arg, 0, st);
		free((*prompt)->arg);
		(*prompt)->arg = back;
		(*prompt)->next = p_lstnew(0, rdr);
		(*prompt)->next->next = front;
	}
	else
	{
		free((*prompt)->arg);
		(*prompt)->arg = rdr;
		(*prompt)->next = front;
	}
	return (NULL);
}

int	handle_character(t_arg **prompt, int (*checker)(char *))
{
	int		i;
	int		len;
	char	*s;

	s = (*prompt)->arg;
	if (!s)
		return (0);
	i = -1;
	while (s[++i])
	{
		if (is_quotation(&s[i]))
			while (!is_quotation(&s[++i]) && s[i])
				;
		if (checker && checker(&s[i]))
		{
			len = checker(&s[i]);
			append_list(prompt, i, len);
			return (1);
		}
		if (!s[i])
			break ;
	}
	return (0);
}

void	split_by_redirection(t_arg **prompt)
{
	t_arg	*iter;

	iter = *prompt;
	while (iter)
	{
		if (handle_character(&iter, &is_redirection) == 1)
			iter = iter->next;
		else
			iter = iter->next;
		if (!iter)
			break ;
	}
}

int	is_redirection(char *s)
{
	int	len;

	len = 0;
	if (!*s)
		return (0);
	if (*s == '<' || *s == '>')
	{
		len++;
		if (*(s + 1) == '<' || *(s + 1) == '>')
		{
			len++;
			return (len);
		}
	}
	return (len);
}
